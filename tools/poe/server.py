#!/usr/bin/env python3
"""Poe (Porymap Object Editor): click objects on a rendered map, edit their text/teams/items.

Usage: python3 tools/poe/server.py [MapName] [--port N] [--no-browser]
"""
import io
import json
import re
import subprocess
import sys
import tempfile
import threading
import webbrowser
from http.server import BaseHTTPRequestHandler, ThreadingHTTPServer
from pathlib import Path
from urllib.parse import parse_qs, urlparse

from PIL import Image

ROOT = Path(__file__).resolve().parents[2]
HERE = Path(__file__).resolve().parent
PARTY_FILE = ROOT / "src/data/trainers.party"
FLAGS_FILE = ROOT / "include/constants/flags.h"
MAX_TEXT_WIDTH = 208
TRAINER_NAME_LENGTH = 10
POKEMON_NAME_LENGTH = 12
WRITE_LOCK = threading.Lock()

# (tiles, metatiles, palettes) in the primary tileset, per layout_version
PRIMARY_SIZES = {"emerald": (512, 512, 6), "frlg": (640, 640, 7)}

# Widths for runtime-substituted placeholders (assumed worst-ish case)
PLACEHOLDER_WIDTHS = {"PLAYER": 42, "RIVAL": 42, "STR_VAR_1": 60, "STR_VAR_2": 60, "STR_VAR_3": 60}

PLACEHOLDER_TEXT_RE = re.compile(r"\b(SIGN|TRAINER|NPC|TRIGGER)\s+\d+\b")
PLACEHOLDER_PARTY_RE = re.compile(r"^\s*Bidoof\s*\nLevel:\s*2\s*\nIVs: 0 HP / 0 Atk / 0 Def / 0 SpA / 0 SpD / 0 Spe\s*$")


def read(path):
    return Path(path).read_text(encoding="utf-8")


def write(path, text):
    Path(path).write_text(text, encoding="utf-8")


# ---------------------------------------------------------------- maps / layouts

def map_names():
    groups = json.loads(read(ROOT / "data/maps/map_groups.json"))
    return [m for g in groups["group_order"] for m in groups[g]]


def load_map(name):
    return json.loads(read(ROOT / "data/maps" / name / "map.json"))


_map_ids = {}


def map_folder(map_id):
    """MAP_ROUTE201 -> Route201 (folder name); rebuilds the index when a lookup misses."""
    if map_id not in _map_ids:
        for name in map_names():
            try:
                _map_ids[load_map(name)["id"]] = name
            except (OSError, KeyError, ValueError):
                pass
    return _map_ids.get(map_id)


def pretty_map_name(folder):
    s = re.sub(r"_(Frlg)$", r" (\1)", folder or "")
    s = re.sub(r"(?<=[a-z])(?=[A-Z0-9])|(?<=[0-9])(?=[A-Z][a-z])", " ", s)
    return s.replace("_", " · ")


def load_layout(layout_id):
    for layout in json.loads(read(ROOT / "data/layouts/layouts.json"))["layouts"]:
        if layout.get("id") == layout_id:
            return layout
    raise KeyError(layout_id)


def tileset_dirs():
    """gTileset_X -> data/tilesets/... folder, via the gMetatiles_X INCBIN path."""
    headers = read(ROOT / "src/data/tilesets/headers.h")
    metatiles = read(ROOT / "src/data/tilesets/metatiles.h")
    meta_paths = dict(re.findall(r"(gMetatiles_\w+)\[\]\s*=\s*INCBIN_U16\(\"([^\"]+)/metatiles\.bin\"", metatiles))
    out = {}
    for name, body in re.findall(r"const struct Tileset (gTileset_\w+)\s*=\s*\{(.*?)\};", headers, re.S):
        m = re.search(r"\.metatiles\s*=\s*(gMetatiles_\w+)", body)
        if m and m.group(1) in meta_paths:
            out[name] = ROOT / meta_paths[m.group(1)]
    return out


def read_pal(path):
    try:
        lines = read(path).split()
    except FileNotFoundError:
        return [(255, 0, 255)] * 16
    nums = [int(x) for x in lines[3:3 + 48]]
    cols = [tuple(nums[i:i + 3]) for i in range(0, len(nums), 3)]
    return (cols + [(0, 0, 0)] * 16)[:16]


class Tileset:
    def __init__(self, folder):
        img = Image.open(folder / "tiles.png")
        if img.mode != "P":
            img = img.convert("P")
        self.tiles_w = img.width // 8
        self.num_tiles = self.tiles_w * (img.height // 8)
        self.pixels = img.tobytes()
        self.img_w = img.width
        self.pals = [read_pal(folder / "palettes" / f"{i:02d}.pal") for i in range(16)]
        raw = (folder / "metatiles.bin").read_bytes()
        self.metatiles = [int.from_bytes(raw[i:i + 2], "little") for i in range(0, len(raw), 2)]

    def tile_rgba(self, idx, pal, hflip, vflip, opaque):
        out = bytearray(8 * 8 * 4)
        if idx >= self.num_tiles:
            return bytes(out)
        tx, ty = (idx % self.tiles_w) * 8, (idx // self.tiles_w) * 8
        for y in range(8):
            sy = 7 - y if vflip else y
            row = (ty + sy) * self.img_w + tx
            for x in range(8):
                sx = 7 - x if hflip else x
                c = self.pixels[row + sx] & 0xF
                o = (y * 8 + x) * 4
                if c == 0 and not opaque:
                    continue
                r, g, b = pal[c]
                out[o:o + 4] = bytes((r, g, b, 255))
        return bytes(out)


_PICS = "graphics/object_events/pics/misc/"
# icon name -> (sprite sheet, crop box of the resting frame)
ICONS = {
    "sign": (_PICS + "sign.png", (0, 0, 16, 16)),
    "item_ball": (_PICS + "ball_poke.png", (0, 16, 16, 32)),
    "cut_tree": (_PICS + "cuttable_tree.png", (0, 0, 16, 16)),
    "cut_tree_frlg": (_PICS + "cuttable_tree_frlg.png", (0, 0, 16, 16)),
    "rock": (_PICS + "breakable_rock.png", (0, 0, 16, 16)),
    "rock_frlg": (_PICS + "breakable_rock_frlg.png", (0, 0, 16, 16)),
    "boulder": (_PICS + "pushable_boulder.png", (0, 0, 16, 16)),
    "boulder_frlg": (_PICS + "pushable_boulder_frlg.png", (0, 0, 16, 16)),
}
GFX_ICONS = {"OBJ_EVENT_GFX_ITEM_BALL": "item_ball",
             "OBJ_EVENT_GFX_CUTTABLE_TREE": "cut_tree", "OBJ_EVENT_GFX_CUTTABLE_TREE_FRLG": "cut_tree_frlg",
             "OBJ_EVENT_GFX_BREAKABLE_ROCK": "rock", "OBJ_EVENT_GFX_BREAKABLE_ROCK_FRLG": "rock_frlg",
             "OBJ_EVENT_GFX_PUSHABLE_BOULDER": "boulder", "OBJ_EVENT_GFX_PUSHABLE_BOULDER_FRLG": "boulder_frlg"}


def render_icon(name):
    path, box = ICONS[name]
    img = Image.open(ROOT / path).crop(box)
    out = img.convert("RGBA")
    if img.mode == "P":
        idx = img.tobytes()
        rgba = out.tobytes()
        out.putdata([(0, 0, 0, 0) if i == 0 else tuple(rgba[n * 4:n * 4 + 4]) for n, i in enumerate(idx)])
    buf = io.BytesIO()
    out.save(buf, "PNG")
    return buf.getvalue()


OBJ_DIR = ROOT / "src/data/object_events"
SPRITE_SOURCES = [OBJ_DIR / "object_event_graphics_info_pointers.h", OBJ_DIR / "object_event_graphics_info.h",
                  OBJ_DIR / "object_event_pic_tables.h", OBJ_DIR / "object_event_graphics.h",
                  ROOT / "src/event_object_movement.c", ROOT / "include/constants/event_objects.h"]
DIR_NAMES = {"DIR_SOUTH": "south", "DIR_NORTH": "north", "DIR_WEST": "west", "DIR_EAST": "east"}
_sprite_db, _sprite_db_key, _sprite_cache = None, None, {}


def sprite_db():
    """Parse the object-event tables: gfx constant -> graphics info -> frames -> PNG + palette."""
    global _sprite_db, _sprite_db_key
    key = tuple(p.stat().st_mtime for p in SPRITE_SOURCES)
    if _sprite_db_key == key:
        return _sprite_db
    ptrs, info_src, pics_src, gfx_src, move_src, consts = (read(p) for p in SPRITE_SOURCES)
    db = {"gfx": dict(re.findall(r"\[(OBJ_EVENT_GFX_\w+)\]\s*=\s*&(gObjectEventGraphicsInfo_\w+)", ptrs)),
          "alias": dict(re.findall(r"#define\s+(OBJ_EVENT_GFX_\w+)\s+(OBJ_EVENT_GFX_\w+)", consts)),
          "info": {}, "tables": {}, "paths": {}, "pal_tags": {}, "facing": {}}
    for name, body in re.findall(r"const struct ObjectEventGraphicsInfo (gObjectEventGraphicsInfo_\w+)\s*=\s*\{(.*?)\};", info_src, re.S):
        f = dict(re.findall(r"\.(\w+)\s*=\s*&?([\w]+)", body))
        db["info"][name] = {"pal": f.get("paletteTag"), "w": int(f.get("width", 16)), "h": int(f.get("height", 32)),
                            "images": f.get("images"), "anims": f.get("anims", "")}
    for name, body in re.findall(r"SpriteFrameImage (sPicTable_\w+)\[\]\s*=\s*\{(.*?)\};", pics_src, re.S):
        frames = []
        for macro, args in re.findall(r"(overworld_frame|overworld_ascending_frames|obj_frame_tiles)\(([^)]*)\)", body):
            a = [x.strip() for x in args.split(",")]
            if macro == "overworld_frame":
                frames.append((a[0], int(a[3])))
            elif macro == "overworld_ascending_frames":
                frames.extend((a[0], i) for i in range(9))
            else:
                frames.append((a[0], 0))
        db["tables"][name] = frames
    for src in (gfx_src, move_src):
        db["paths"].update(re.findall(r"(gObjectEvent(?:Pic|Pal)_\w+)\[\]\s*=\s*INC\w+\(\"([^\"]+)\"", src))
    db["pal_tags"] = {tag: pal for pal, tag in re.findall(r"\{\s*(gObjectEventPal_\w+)\s*,\s*(OBJ_EVENT_PAL_TAG_\w+)\s*\}", move_src)}
    m = re.search(r"gInitialMovementTypeFacingDirections\[[^\]]*\]\s*=\s*\{(.*?)\};", move_src, re.S)
    if m:
        db["facing"] = {mt: DIR_NAMES.get(d, "south") for mt, d in re.findall(r"\[(MOVEMENT_TYPE_\w+)\]\s*=\s*(DIR_\w+)", m.group(1))}
    _sprite_db, _sprite_db_key = db, key
    _sprite_cache.clear()
    return db


MON_GFX_RE = re.compile(r"^OBJ_EVENT_GFX_SPECIES(_SHINY)?(_FEMALE)?\((\w+)\)$")
_mon_ow = None


def mon_overworld_db():
    """SPECIES_X -> overworld sheet/palettes from its OVERWORLD(...) / OVERWORLD_FEMALE(...) entry."""
    global _mon_ow
    if _mon_ow is not None:
        return _mon_ow
    tables = {}
    for f in (OBJ_DIR / "object_event_pic_tables.h", OBJ_DIR / "object_event_pic_tables_followers.h"):  # followers win on name clashes
        tables.update(re.findall(r"SpriteFrameImage (sPicTable_\w+)\[\]\s*=\s*\{\s*\w+\((gObjectEventPic_\w+)", read(f)))
    paths = dict(re.findall(r"(gObjectEventPic_\w+|g\w*OverworldPalette\w*)\[\]\s*=\s*INCGFX_\w+\(\"([^\"]+)\"",
                            read(ROOT / "src/data/graphics/pokemon.h")))
    ow = r"\(\s*(\w+)\s*,\s*SIZE_(\d+)x(\d+)\s*,\s*\w+\s*,\s*\w+\s*,\s*(\w+)\s*(?:,\s*(\w+)\s*,\s*(\w+)\s*)?\)"
    _mon_ow = {}
    for f in sorted((ROOT / "src/data/pokemon/species_info").glob("gen_*_families.h")):
        chunks = re.split(r"\n\s*\[(SPECIES_\w+)\]\s*=", read(f))
        for const, body in zip(chunks[1::2], chunks[2::2]):
            m = re.search(r"OVERWORLD" + ow, body)
            if not m or const in _mon_ow or tables.get(m.group(1)) not in paths:
                continue
            entry = {"w": int(m.group(2)), "h": int(m.group(3)), "asym": m.group(4).endswith("_Asym"),
                     "pic": paths[tables[m.group(1)]], "pal": paths.get(m.group(5)), "shiny": paths.get(m.group(6))}
            fm = re.search(r"OVERWORLD_FEMALE" + ow, body)
            if fm and tables.get(fm.group(1)) in paths:
                entry["f_pic"] = paths[tables[fm.group(1)]]
                entry["f_pal"], entry["f_shiny"] = paths.get(fm.group(5)), paths.get(fm.group(6))
            _mon_ow[const] = entry
    return _mon_ow


def sprite_info(gfx):
    mm = MON_GFX_RE.match(gfx or "")
    if mm:
        d = mon_overworld_db().get("SPECIES_" + mm.group(3))
        return d and {"w": d["w"], "h": d["h"], "mon": ("SPECIES_" + mm.group(3), bool(mm.group(1)), bool(mm.group(2)))}
    db = sprite_db()
    for _ in range(4):
        if gfx in db["gfx"] or gfx not in db["alias"]:
            break
        gfx = db["alias"][gfx]
    info = db["info"].get(db["gfx"].get(gfx))
    if not info or not db["tables"].get(info["images"]):
        return None
    return info


def movement_types():
    t = read(ROOT / "include/constants/event_object_movement.h")
    return [c for c in re.findall(r"#define\s+(MOVEMENT_TYPE_\w+)\s+0x[0-9A-Fa-f]+", t)]


MAX_MOVEMENT_RANGE = 15  # movementRangeX/Y are 4-bit fields
MAX_SIGHT = 15


def set_movement(map_name, index, expected, mtype, rx, ry, sight=None):
    if mtype not in movement_types():
        raise ValueError(f"Unknown movement type {mtype}")
    if not all(isinstance(v, int) and 0 <= v <= MAX_MOVEMENT_RANGE for v in (rx, ry)):
        raise ValueError(f"Ranges must be 0–{MAX_MOVEMENT_RANGE}")
    if sight is not None and not (isinstance(sight, int) and 0 <= sight <= MAX_SIGHT):
        raise ValueError(f"Sight must be 0–{MAX_SIGHT}")
    with WRITE_LOCK:
        path = ROOT / "data/maps" / map_name / "map.json"
        m = json.loads(read(path))
        ev = m["object_events"][index]
        current = [ev.get("movement_type"), ev.get("movement_range_x"), ev.get("movement_range_y"),
                   ev.get("trainer_sight_or_berry_tree_id")]
        if current != expected:
            raise ConflictError("This object's movement changed on disk since it was loaded — reload and try again.")
        ev["movement_type"], ev["movement_range_x"], ev["movement_range_y"] = mtype, rx, ry
        if sight is not None:
            ev["trainer_sight_or_berry_tree_id"] = str(sight)
        write(path, json.dumps(m, indent=2) + "\n")


def facing_for(movement_type):
    return sprite_db()["facing"].get(movement_type, "south")


def render_sprite(gfx, direction):
    key = (gfx, direction)
    if key in _sprite_cache:
        return _sprite_cache[key]
    db, info = sprite_db(), sprite_info(gfx)
    if not info:
        raise KeyError(gfx)
    if "mon" in info:
        _sprite_cache[key] = render_mon_overworld(*info["mon"], direction)
        return _sprite_cache[key]
    frames = db["tables"][info["images"]]
    standard = len(frames) >= 3 and "Inanimate" not in info["anims"]
    idx = {"south": 0, "north": 1, "west": 2, "east": 2}[direction] if standard else 0
    pic, frame = frames[min(idx, len(frames) - 1)]
    path = ROOT / db["paths"][pic]
    if path.suffix != ".png" and path.with_suffix(".png").exists():
        path = path.with_suffix(".png")  # some pics INCBIN the built .4bpp; the source PNG sits beside it
    sheet = Image.open(path)
    w, h = info["w"], info["h"]
    per_row = max(1, sheet.width // w)
    box = ((frame % per_row) * w, (frame // per_row) * h)
    img = sheet.crop((box[0], box[1], box[0] + w, box[1] + h))
    pal_path = db["paths"].get(db["pal_tags"].get(info["pal"], ""))
    if img.mode == "P":
        colors = read_pal(ROOT / pal_path) if pal_path else None
        if not colors:
            flat = img.getpalette() or []
            colors = [tuple(flat[i:i + 3]) for i in range(0, 48, 3)]
        idxs = img.tobytes()
        out = Image.new("RGBA", (w, h))
        out.putdata([(0, 0, 0, 0) if (i & 0xF) == 0 else colors[i & 0xF] + (255,) for i in idxs])
    else:
        out = img.convert("RGBA")
    if standard and direction == "east":
        out = out.transpose(Image.FLIP_LEFT_RIGHT)
    buf = io.BytesIO()
    out.save(buf, "PNG")
    _sprite_cache[key] = buf.getvalue()
    return _sprite_cache[key]


def render_mon_overworld(species, shiny, female, direction):
    d = mon_overworld_db()[species]
    pic, pal, shiny_pal = d["pic"], d["pal"], d["shiny"]
    if female and d.get("f_pic"):
        pic, pal, shiny_pal = d["f_pic"], d.get("f_pal") or pal, d.get("f_shiny") or shiny_pal
    if shiny and shiny_pal:
        pal = shiny_pal
    # sAnimTable_Following: S=0, N=2, W=4, E=4 mirrored; _Asym has its own east frame 6.
    frame = {"south": 0, "north": 2, "west": 4, "east": 6 if d["asym"] else 4}[direction]
    sheet = Image.open(ROOT / pic)
    w, h = d["w"], d["h"]
    if (frame + 1) * w > sheet.width:
        frame = 0
    img = sheet.crop((frame * w, 0, frame * w + w, h))
    colors = read_pal(ROOT / pal) if pal else None
    if img.mode == "P":
        if not colors:
            flat = img.getpalette() or []
            colors = [tuple(flat[i:i + 3]) for i in range(0, 48, 3)]
        out = Image.new("RGBA", (w, h))
        out.putdata([(0, 0, 0, 0) if (i & 0xF) == 0 else colors[i & 0xF] + (255,) for i in img.tobytes()])
    else:
        out = img.convert("RGBA")
    if direction == "east" and not d["asym"]:
        out = out.transpose(Image.FLIP_LEFT_RIGHT)
    buf = io.BytesIO()
    out.save(buf, "PNG")
    return buf.getvalue()


def render_map(name):
    m = load_map(name)
    layout = load_layout(m["layout"])
    version = layout.get("layout_version", "emerald")
    n_tiles, n_metas, n_pals = PRIMARY_SIZES.get(version, PRIMARY_SIZES["emerald"])
    dirs = tileset_dirs()
    prim = Tileset(dirs[layout["primary_tileset"]])
    sec = Tileset(dirs[layout["secondary_tileset"]])
    pals = prim.pals[:n_pals] + sec.pals[n_pals:]
    w, h = layout["width"], layout["height"]
    raw = (ROOT / layout["blockdata_filepath"]).read_bytes()
    blocks = [int.from_bytes(raw[i:i + 2], "little") & 0x3FF for i in range(0, len(raw), 2)]

    tile_cache, meta_cache = {}, {}

    def tile(entry, opaque):
        key = (entry, opaque)
        if key not in tile_cache:
            idx, hf, vf, pal = entry & 0x3FF, entry >> 10 & 1, entry >> 11 & 1, entry >> 12 & 0xF
            src, local = (prim, idx) if idx < n_tiles else (sec, idx - n_tiles)
            data = src.tile_rgba(local, pals[pal] if pal < len(pals) else pals[0], hf, vf, opaque)
            tile_cache[key] = Image.frombytes("RGBA", (8, 8), data)
        return tile_cache[key]

    def metatile(mid):
        if mid not in meta_cache:
            src, local = (prim, mid) if mid < n_metas else (sec, mid - n_metas)
            entries = src.metatiles[local * 8:local * 8 + 8]
            img = Image.new("RGBA", (16, 16), pals[0][0] + (255,))
            if len(entries) < 8:
                img.paste((255, 0, 255, 255), (0, 0, 16, 16))
            else:
                for layer in range(2):
                    for i in range(4):
                        t = tile(entries[layer * 4 + i], False)
                        img.alpha_composite(t, ((i % 2) * 8, (i // 2) * 8))
            meta_cache[mid] = img
        return meta_cache[mid]

    out = Image.new("RGBA", (w * 16, h * 16))
    for i, mid in enumerate(blocks[:w * h]):
        out.paste(metatile(mid), ((i % w) * 16, (i // w) * 16))
    buf = io.BytesIO()
    out.save(buf, "PNG")
    return buf.getvalue()


# ---------------------------------------------------------------- story-state registry

VARS_FILE = ROOT / "include/constants/vars.h"
STATE_HEAD_RE = re.compile(r"^\s*//\s*@states\b\s*(.*)$")
STATE_ROW_RE = re.compile(r"^\s*//\s+(\d+)\s\s*(\S.*?)\s*$")
_story_states = None


def story_states():
    """VAR_X -> its documented state values, from the `// @states` block under its #define.

    Lives next to the #define (rather than in its own file) so the names can't drift from
    the var they describe; a var with no block simply isn't story state as far as Poe cares.
    """
    global _story_states
    if _story_states is not None:
        return _story_states
    out, lines = {}, read(VARS_FILE).splitlines()
    for i, line in enumerate(lines):
        m = re.match(r"^\s*#define\s+(VAR_\w+)\s+0x[0-9A-Fa-f]+", line)
        if not m or i + 1 >= len(lines):
            continue
        head = STATE_HEAD_RE.match(lines[i + 1])
        if not head:
            continue
        states = []
        for row in lines[i + 2:]:
            r = STATE_ROW_RE.match(row)
            if not r:
                break
            states.append({"value": int(r.group(1)), "label": r.group(2)})
        out[m.group(1)] = {"var": m.group(1), "note": head.group(1), "states": states}
    _story_states = out
    return out


def story_state_audit():
    """Values a map script uses for a registered var that the registry doesn't document."""
    reg = story_states()
    if not reg:
        return {}
    used = {v: set() for v in reg}
    pattern = re.compile(r"\b(?:setvar|compare|map_script_2|(?:goto|call)_if_\w+)\s+(%s)\s*,\s*(\d+)"
                         % "|".join(map(re.escape, reg)))
    for p in (ROOT / "data/maps").glob("*/scripts.inc"):
        for var, val in pattern.findall(read(p)):
            used[var].add(int(val))
    out = {}
    for var, info in reg.items():
        known = {s["value"] for s in info["states"]}
        missing = sorted(used[var] - known)
        unused = sorted(known - used[var] - {0})  # 0 is every var's starting value, never set explicitly
        if missing or unused:
            out[var] = {"undocumented": missing, "documented_but_unused": unused}
    return out


# ---------------------------------------------------------------- scripts.inc text

LABEL_RE = re.compile(r"^([A-Za-z_]\w*)::?\s*(@.*)?$")
STRING_RE = re.compile(r'^\s*\.string\s+"(.*)"\s*$')


def scripts_path(map_name):
    return ROOT / "data/maps" / map_name / "scripts.inc"


def parse_labels(lines):
    """label -> (line index of label, kind) where kind is 'text' or 'script'."""
    out = {}
    for i, line in enumerate(lines):
        m = LABEL_RE.match(line)
        if m:
            nxt = next((l for l in lines[i + 1:] if l.strip()), "")
            out[m.group(1)] = (i, "text" if STRING_RE.match(nxt) else "script")
    return out


def text_block(lines, label_line):
    strings = []
    for line in lines[label_line + 1:]:
        m = STRING_RE.match(line)
        if not m:
            break
        strings.append(m.group(1))
    return strings


def script_body(lines, label_line):
    body = [lines[label_line]]
    for line in lines[label_line + 1:]:
        if LABEL_RE.match(line):
            break
        body.append(line)
    while body and not body[-1].strip():
        body.pop()
    return body


CMP_NEG = {"eq": "ne", "ne": "eq", "lt": "ge", "ge": "lt", "gt": "le", "le": "gt",
           "set": "unset", "unset": "set", "defeated": "not_defeated", "not_defeated": "defeated"}
INT_OPS = ("eq", "ne", "lt", "le", "gt", "ge")
JUMP_RE = re.compile(r"^\s*(goto|call)_if_(eq|ne|lt|le|gt|ge|set|unset|not_defeated|defeated)\s+(.+?)\s*$")
GOTO_RE = re.compile(r"^\s*goto\s+(\w+)\s*$")
SWITCH_RE = re.compile(r"^\s*switch\s+(\w+)\s*$")
CASE_RE = re.compile(r"^\s*case\s+([^,]+?)\s*,\s*(\w+)\s*$")
COMPARE_RE = re.compile(r"^\s*compare\s+(\w+)\s*,\s*(\S+)\s*$")
VAR_WRITE_RE = re.compile(r"^\s*(?:setvar|copyvar|addvar|subvar|specialvar)\s+(\w+)")
FLAG_WRITE_RE = re.compile(r"^\s*(?:setflag|clearflag)\s+(\w+)")
MAX_BLOCKS = 24


def trackable(c, registered):
    """Only conditions on state that persists can be carried down a branch.

    Scratch vars (VAR_RESULT, VAR_0x800x) are rewritten constantly — by multichoice, YESNO
    boxes, specialvar — so a condition on one is stale the moment anything reassigns it, and
    carrying it produces nonsense guards. A var counts as real state exactly when the registry
    documents it, which is also what keeps Yes/No handlers from looking like dialogue variants.
    """
    if c["op"] in ("set", "unset"):
        return c["left"].startswith("FLAG_")
    if c["op"] in ("defeated", "not_defeated"):
        return True
    return c["left"] in registered


def negate(c):
    return {"left": c["left"], "op": CMP_NEG[c["op"]], "right": c["right"]}


def parse_jump(op, args):
    """(condition, destination) for one goto_if_/call_if_ line; condition None if not readable."""
    if op in ("set", "unset", "defeated", "not_defeated"):
        return ({"left": args[0], "op": op, "right": None}, args[1]) if len(args) == 2 else (None, args[-1])
    if len(args) == 3:
        return {"left": args[0], "op": op, "right": args[1]}, args[2]
    return None, args[-1] if args else None


def guard_impossible(guard):
    """True when no value could satisfy the whole guard — i.e. an earlier branch shadows this one."""
    by_var, flags = {}, {}
    for c in guard:
        if c["op"] in ("set", "unset"):
            if flags.setdefault(c["left"], c["op"]) != c["op"]:
                return True
        elif c["op"] in INT_OPS and str(c["right"]).isdigit():
            by_var.setdefault(c["left"], []).append((c["op"], int(c["right"])))
    for conds in by_var.values():
        lo, hi, excluded = 0, 0xFFFF, set()
        for op, v in conds:
            if op == "eq":
                lo, hi = max(lo, v), min(hi, v)
            elif op == "ne":
                excluded.add(v)
            elif op == "lt":
                hi = min(hi, v - 1)
            elif op == "le":
                hi = min(hi, v)
            elif op == "gt":
                lo = max(lo, v + 1)
            elif op == "ge":
                lo = max(lo, v)
        if lo > hi or (lo == hi and lo in excluded):
            return True
    return False


def walk_block(body, labels, guard, queue, texts, order, registered):
    """Step through one script block, carrying the conditions that must hold to reach each line."""
    cur, switch_var, pending = list(guard), None, None
    keep = lambda c: [x for x in cur if x["left"] != c]  # a write makes earlier tests on it stale
    for line in body:
        line = re.sub(r"\s+@.*$", "", line)  # a trailing @ comment would end up inside the jump target
        m = VAR_WRITE_RE.match(line) or FLAG_WRITE_RE.match(line)
        if m:
            cur = keep(m.group(1))
            continue
        m = SWITCH_RE.match(line)
        if m:
            switch_var, pending = m.group(1), None
            continue
        m = COMPARE_RE.match(line)
        if m:
            pending = (m.group(1), m.group(2))
            continue
        m = CASE_RE.match(line)
        if m and switch_var:
            c = {"left": switch_var, "op": "eq", "right": m.group(1)}
            use = [c] if trackable(c, registered) else []
            queue.append((m.group(2), cur + use))
            cur = cur + [negate(c) for c in use]
            continue
        m = GOTO_RE.match(line)
        if m:
            queue.append((m.group(1), list(cur)))
            return  # whatever follows an unconditional goto can't be reached
        m = JUMP_RE.match(line)
        if m:
            kind, op, rest = m.groups()
            args = [a.strip() for a in rest.split(",")]
            c, dest = parse_jump(op, args)
            if c is None and len(args) == 1 and pending:
                c = {"left": pending[0], "op": op, "right": pending[1]}
            use = [c] if c and trackable(c, registered) else []
            if dest:
                queue.append((dest, cur + use))
                if kind == "goto":  # a call comes back, so it doesn't constrain what follows
                    cur = cur + [negate(x) for x in use]
            pending = None
            continue
        for tok in re.findall(r"\b[A-Za-z_]\w*\b", line):
            if tok not in labels:
                continue
            if labels[tok][1] == "text":
                if tok not in texts:
                    texts[tok], _ = [], order.append(tok)
                texts[tok].append(list(cur))
            else:
                queue.append((tok, list(cur)))


def collect_script(map_name, script):
    """Follow a script and its same-file sub-scripts; return the bodies plus each text and its guards."""
    path = scripts_path(map_name)
    if not path.exists():
        return None
    lines = read(path).splitlines()
    labels = parse_labels(lines)
    if script not in labels:
        return None
    seen, queue, bodies, blocks = set(), [(script, [])], [], []
    texts, order, registered = {}, [], set(story_states())
    while queue and len(seen) < MAX_BLOCKS:
        label, guard = queue.pop(0)
        if label in seen or label not in labels or labels[label][1] != "script":
            continue
        seen.add(label)
        body = script_body(lines, labels[label][0])
        bodies.append("\n".join(body))
        blocks.append({"label": label, "body": "\n".join(body)})
        walk_block(body[1:], labels, guard, queue, texts, order, registered)
    return {"body": "\n\n".join(bodies), "blocks": blocks,
            "texts": [{"label": t, "strings": text_block(lines, labels[t][0]), "paths": texts[t],
                       "unreachable": all(guard_impossible(p) for p in texts[t])} for t in order]}


def replace_text(map_name, label, expected, new_strings):
    path = scripts_path(map_name)
    lines = read(path).split("\n")
    labels = parse_labels(lines)
    if label not in labels or labels[label][1] != "text":
        raise ValueError(f"{label} not found as a text label in {path.name}")
    start = labels[label][0]
    current = text_block(lines, start)
    if current != expected:
        raise ConflictError(f"{label} changed on disk since it was loaded — reload and try again.")
    new_lines = ['\t.string "%s"' % s for s in new_strings]
    lines[start + 1:start + 1 + len(current)] = new_lines
    write(path, "\n".join(lines))


def replace_script(map_name, label, expected, new_body):
    """Replace one script block (label line through the line before the next label)."""
    path = scripts_path(map_name)
    lines = read(path).split("\n")
    labels = parse_labels(lines)
    if label not in labels or labels[label][1] != "script":
        raise ValueError(f"{label} not found as a script label in {path.name}")
    start = labels[label][0]
    current = script_body(lines, start)
    if "\n".join(current) != expected:
        raise ConflictError(f"{label} changed on disk since it was loaded — reload and try again.")
    new_lines = new_body.replace("\r", "").rstrip("\n").split("\n")
    if new_lines[0].strip() != current[0].strip():
        raise ValueError(f"The first line must stay `{current[0].strip()}` — map.json points at that label.")
    lines[start:start + len(current)] = new_lines
    write(path, "\n".join(lines))


class ConflictError(Exception):
    pass


# ---------------------------------------------------------------- trainers.party

def party_blocks(text):
    """TRAINER_X -> (start, end) char offsets of the block body (after the === line)."""
    out = {}
    heads = list(re.finditer(r"^=== (TRAINER_\w+) ===[ \t]*\n", text, re.M))
    for i, h in enumerate(heads):
        end = heads[i + 1].start() if i + 1 < len(heads) else len(text)
        out[h.group(1)] = (h.end(), end)
    return out


def get_party(trainer):
    text = read(PARTY_FILE)
    blocks = party_blocks(text)
    if trainer not in blocks:
        return None
    s, e = blocks[trainer]
    return text[s:e].rstrip("\n")


_constants = None


def known_constants():
    global _constants
    if _constants is None:
        names = set()
        for p in (ROOT / "include/constants").rglob("*.h"):
            t = read(p)
            names.update(re.findall(r"^\s*#define\s+([A-Z_][A-Z0-9_]*)", t, re.M))
            names.update(re.findall(r"^\s*([A-Z_][A-Z0-9_]*)\s*(?:=[^=]|,|$)", t, re.M))
        _constants = names
    return _constants


CHECKED_PREFIXES = ("SPECIES_", "MOVE_", "ITEM_", "ABILITY_", "NATURE_", "BALL_", "TRAINER_CLASS_", "TRAINER_PIC_")


def validate_party_file(text, trainer):
    """Run the real trainerproc pipeline on a candidate file; return list of error strings."""
    with tempfile.TemporaryDirectory() as tmp:
        src, out = Path(tmp) / "t.party", Path(tmp) / "t.h"
        write(src, text)
        cpp = subprocess.run(
            ["arm-none-eabi-cpp", "-iquote", str(ROOT / "include"), "-Wno-trigraphs", "-DMODERN=1",
             "-DTESTING=0", "-DEMERALD", "-std=gnu17", "-traditional-cpp", "-"],
            input=text, capture_output=True, text=True, cwd=ROOT)
        if cpp.returncode:
            return ["preprocessor: " + cpp.stderr.strip()]
        proc = subprocess.run([str(ROOT / "tools/trainerproc/trainerproc"), "-o", str(out), "-i", str(src), "-"],
                              input=cpp.stdout, capture_output=True, text=True, cwd=ROOT)
        if proc.returncode:
            return [proc.stderr.strip() or "trainerproc failed"]
        gen = read(out)
    m = re.search(r"\[DIFFICULTY_NORMAL\]\[%s\] =(.*?)(?=\[DIFFICULTY_|\Z)" % re.escape(trainer), gen, re.S)
    if not m:
        return [f"{trainer} missing from generated output"]
    errors = []
    name = re.search(r'\.trainerName = _\("(.*?)"\)', m.group(1))
    if name and len(name.group(1)) > TRAINER_NAME_LENGTH:
        errors.append(f'Name "{name.group(1)}" is {len(name.group(1))} chars; max is {TRAINER_NAME_LENGTH}.')
    consts = known_constants()
    for tok in sorted(set(re.findall(r"\b[A-Z][A-Z0-9_]+\b", m.group(1)))):
        if tok.startswith(CHECKED_PREFIXES) and tok not in consts:
            errors.append(f"Unknown constant {tok} (check spelling of the species/move/item/etc.).")
    return errors


def replace_party(trainer, expected, new_body):
    with WRITE_LOCK:
        text = read(PARTY_FILE)
        blocks = party_blocks(text)
        if trainer not in blocks:
            raise ValueError(f"{trainer} not in trainers.party")
        s, e = blocks[trainer]
        if text[s:e].rstrip("\n") != expected:
            raise ConflictError(f"{trainer} changed on disk since it was loaded — reload and try again.")
        body = "\n".join(l.rstrip() for l in new_body.strip("\n").split("\n"))
        new_text = text[:s] + body + "\n\n" + text[e:].lstrip("\n") if e < len(text) else text[:s] + body + "\n"
        errors = validate_party_file(new_text, trainer)
        if errors:
            return errors
        write(PARTY_FILE, new_text)
        return []


# ---------------------------------------------------------------- trainer editor data

def party_token(s):
    """What trainerproc turns a name into: uppercase, non-alnum -> '_', apostrophes dropped."""
    return "".join(c.upper() if c.isascii() and c.isalnum() else "" if c == "'" else "_" for c in s)


def title_from_const(suffix):
    return " ".join(w.capitalize() for w in suffix.split("_"))


_trainer_data = None
_mon_pics = {}


def trainer_data():
    global _trainer_data
    if _trainer_data is not None:
        return _trainer_data
    consts = read(ROOT / "include/constants/trainers.h")
    battle_main = read(ROOT / "src/battle_main.c")
    table = re.search(r"gTrainerClasses\[[^\]]*\]\s*=\s*\{(.*?)\n\};", battle_main, re.S).group(1)
    classes = [{"const": c, "party": title_from_const(c[len("TRAINER_CLASS_"):]), "name": n}
               for c, n in re.findall(r"\[(TRAINER_CLASS_\w+)\]\s*=\s*\{\s*_\(\"([^\"]*)\"\)", table)]
    pics = [c for c in re.findall(r"^\s*(TRAINER_PIC_\w+)\s*[,=]", consts, re.M)
            if c not in ("TRAINER_PIC_NONE",) and not c.endswith("_COUNT")]
    music = [c for c in re.findall(r"#define\s+(TRAINER_ENCOUNTER_MUSIC_\w+)", consts)]

    order = {c: int(n) for c, n in re.findall(r"^\s*(SPECIES_\w+)\s*=\s*(\d+)", read(ROOT / "include/constants/species.h"), re.M)}
    abilities = named_table(ROOT / "src/data/abilities.h", "ABILITY_")
    known_abilities = {a["const"] for a in abilities}
    gfx = dict(re.findall(r"(gMon(?:FrontPic|Palette|ShinyPalette)_\w+)\[\]\s*=\s*INCGFX_U\d+\(\"([^\"]+)\"", read(ROOT / "src/data/graphics/pokemon.h")))
    species = {}
    for f in sorted((ROOT / "src/data/pokemon/species_info").glob("gen_*_families.h")):
        chunks = re.split(r"\n\s*\[(SPECIES_\w+)\]\s*=", read(f))
        for const, body in zip(chunks[1::2], chunks[2::2]):
            name = re.search(r"\.speciesName\s*=\s*_\(\"([^\"]*)\"\)", body)
            pic = re.search(r"\.frontPic\s*=\s*(gMonFrontPic_\w+)", body)
            pal = re.search(r"\.palette\s*=\s*(gMonPalette_\w+)", body)
            shiny = re.search(r"\.shinyPalette\s*=\s*(gMonShinyPalette_\w+)", body)
            if not name or const in species or const not in order:
                continue
            base = const[len("SPECIES_"):]
            label = name.group(1)
            if party_token(label) == base:
                party = label
            else:
                party = title_from_const(base)
                norm = party_token(label)
                form = base[len(norm) + 1:] if base.startswith(norm + "_") else ""
                label = f"{label} ({title_from_const(form)})" if form else label
            species[const] = {"const": const, "label": label, "party": party, "n": order[const]}
            species[const].update(species_abilities(body, known_abilities))
            if pic and pal and pic.group(1) in gfx and pal.group(1) in gfx:
                _mon_pics[const] = (gfx[pic.group(1)], gfx[pal.group(1)],
                                    gfx.get(shiny.group(1)) if shiny else None)
    species_list = sorted(species.values(), key=lambda s: s["n"])
    natures = [{"const": c, "label": f"{title_from_const(c[7:])} ({hint})" if hint != "Neutral" else f"{title_from_const(c[7:])} (neutral)",
                "party": title_from_const(c[7:])}
               for c, hint in re.findall(r"#define\s+(NATURE_\w+)\s+\d+\s*//\s*(.+)", read(ROOT / "include/constants/pokemon.h"))]
    _trainer_data = {"classes": classes, "pics": [{"const": c, "party": title_from_const(c[len("TRAINER_PIC_"):])} for c in pics],
                     "music": [{"const": c, "party": title_from_const(c[len("TRAINER_ENCOUNTER_MUSIC_"):])} for c in music],
                     "species": species_list, "nameLength": TRAINER_NAME_LENGTH,
                     "monNameLength": POKEMON_NAME_LENGTH,
                     "items": named_table(ROOT / "src/data/items.h", "ITEM_"),
                     "moves": named_table(ROOT / "src/data/moves_info.h", "MOVE_"),
                     "natures": natures, "abilities": abilities, "balls": ball_list()}
    return _trainer_data


def species_abilities(body, known):
    """The 3 ability slots of one species -> {abilities: [...], ha: <hidden>} for the Ability dropdown.

    The engine asserts a trainer mon's ability is one of its species' three slots
    (battle_main.c CreateNPCTrainerPartyFromTrainer), so the dropdown has to match this list.
    """
    m = re.search(r"\.abilities\s*=\s*\{([^}]*)\}", body)
    if not m:
        return {}
    slots = [a for a in re.findall(r"ABILITY_\w+", m.group(1))][:3]
    usable = [a for a in dict.fromkeys(slots) if a != "ABILITY_NONE" and a in known]
    out = {"abilities": usable} if usable else {}
    if len(slots) > 2 and slots[2] in usable and slots[2] not in slots[:2]:
        out["ha"] = slots[2]
    return out


def ball_list():
    """BALL_X -> the bare word trainerproc wants after `Ball:`, labelled with the ball item's name."""
    consts = re.findall(r"^\s*(BALL_\w+)\s*=", read(ROOT / "include/constants/pokeball.h"), re.M)
    names = dict(re.findall(r"\[(ITEM_\w+)\]\s*=\s*\{\s*\.name\s*=\s*\w*\(\"([^\"]*)\"\)", read(ROOT / "src/data/items.h")))
    out = []
    for const in consts:
        suffix, party = const[len("BALL_"):], title_from_const(const[len("BALL_"):])
        item = f"ITEM_{suffix}_BALL"
        out.append({"const": const, "party": party, "label": names.get(item, party + " Ball"),
                    "item": item if item in names else ""})
    return out


_item_icons, _item_icon_cache = None, {}


def item_icons():
    """ITEM_X -> (icon png, palette): .iconPic/.iconPalette, TM/HM discs colored by move type, plus aliases."""
    global _item_icons
    if _item_icons is None:
        gfx = dict(re.findall(r"(gItemIcon(?:Palette)?_\w+)\[\]\s*=\s*INCGFX_U\d+\(\"([^\"]+)\"",
                              read(ROOT / "src/data/graphics/items.h")))
        split = lambda text, prefix: zip(*[iter(re.split(r"\n\s*\[(%s\w+)\]\s*=" % prefix, text)[1:])] * 2)
        type_pal = {t: m.group(1) for t, body in split(read(ROOT / "src/data/types_info.h"), "TYPE_")
                    if (m := re.search(r"\.paletteTMHM\s*=\s*(\w+)", body))}
        move_type = {mv: m.group(1) for mv, body in split(read(ROOT / "src/data/moves_info.h"), "MOVE_")
                     if (m := re.search(r"\.type\s*=\s*(TYPE_\w+)", body))}
        _item_icons, by_name = {}, {}
        for const, body in split(read(ROOT / "src/data/items.h"), "ITEM_"):
            pic = re.search(r"\.iconPic\s*=\s*(\w+)", body)
            pal = re.search(r"\.iconPalette\s*=\s*(\w+)", body)
            name = re.search(r"\.name\s*=\s*\w*\(\"([^\"]*)\"\)", body)
            tm = re.match(r"ITEM_(TM|HM)_(\w+)$", const)
            if "POCKET_TM_HM" in body and tm:
                pic_sym = "gItemIcon_HM" if tm.group(1) == "HM" else "gItemIcon_TM"
                pal_sym = type_pal.get(move_type.get("MOVE_" + tm.group(2), ""))
            else:
                pic_sym, pal_sym = pic and pic.group(1), pal and pal.group(1)
            if pic_sym in gfx and pal_sym in gfx:
                _item_icons[const] = (gfx[pic_sym], gfx[pal_sym])
                if name:
                    by_name["ITEM_" + party_token(name.group(1))] = const
        aliases = dict(re.findall(r"^\s*(ITEM_\w+)\s*=\s*(ITEM_\w+)\s*,", read(ROOT / "include/constants/items.h"), re.M))
        for alias, target in list(aliases.items()) + list(by_name.items()):
            if alias not in _item_icons and target in _item_icons:
                _item_icons[alias] = _item_icons[target]
    return _item_icons


def render_item_icon(const):
    if const not in _item_icon_cache:
        pic, pal = item_icons()[const]
        img = Image.open(ROOT / pic)
        colors = read_pal(ROOT / pal)
        out = Image.new("RGBA", img.size)
        if img.mode == "P":
            out.putdata([(0, 0, 0, 0) if (i & 0xF) == 0 else colors[i & 0xF] + (255,) for i in img.tobytes()])
        else:
            out = img.convert("RGBA")
        buf = io.BytesIO()
        out.save(buf, "PNG")
        _item_icon_cache[const] = buf.getvalue()
    return _item_icon_cache[const]


def named_table(path, prefix):
    """[PREFIX_X] = { .name = ...("Display") } entries -> dropdown rows with a trainerproc-safe party name."""
    rows, seen = [], set()
    for const, name in re.findall(r"\[(%s\w+)\]\s*=\s*\{\s*\.name\s*=\s*\w*\(\"([^\"]*)\"\)" % prefix, read(path)):
        suffix = const[len(prefix):]
        if const in seen or suffix == "NONE" or not name.strip("?- "):
            continue
        seen.add(const)
        party = name if party_token(name) == suffix else title_from_const(suffix)
        rows.append({"const": const, "label": name, "party": party})
    counts = {}
    for r in rows:
        counts[r["label"]] = counts.get(r["label"], 0) + 1
    for r in rows:
        if counts[r["label"]] > 1:
            r["label"] = f"{r['label']} ({title_from_const(r['const'][len(prefix):])})"
    return rows


_encounters = None
ENC_LABELS = {"land_mons": "Grass / cave", "water_mons": "Surfing", "rock_smash_mons": "Rock Smash",
              "fishing_mons": "Fishing", "hidden_mons": "Hidden"}


def encounter_db():
    """MAP_X -> encounter sections, slots merged per species, with real per-slot chances."""
    global _encounters
    if _encounters is not None:
        return _encounters
    data = json.loads(read(ROOT / "src/data/wild_encounters.json"))
    names = {sp["const"]: sp["label"] for sp in trainer_data()["species"]}
    _encounters = {}
    for group in data["wild_encounter_groups"]:
        if not group.get("for_maps"):
            continue
        fields = {f["type"]: f for f in group["fields"]}
        for enc in group["encounters"]:
            sections = []
            for ftype, field in fields.items():
                table = enc.get(ftype)
                if not table:
                    continue
                rates = field.get("encounter_rates") or []
                # Fishing splits into rods; everything else is one list.
                parts = field.get("groups") or {"": list(range(len(table["mons"])))}
                for part, idxs in parts.items():
                    total = sum(rates[i] for i in idxs if i < len(rates)) or 1
                    merged = {}
                    for i in idxs:
                        if i >= len(table["mons"]):
                            continue
                        mon = table["mons"][i]
                        cur = merged.setdefault(mon["species"], {"species": mon["species"],
                                                                "label": names.get(mon["species"], mon["species"]),
                                                                "min": mon["min_level"], "max": mon["max_level"], "chance": 0})
                        cur["min"] = min(cur["min"], mon["min_level"])
                        cur["max"] = max(cur["max"], mon["max_level"])
                        cur["chance"] += 100 * (rates[i] if i < len(rates) else 0) / total
                    if merged:
                        sections.append({"type": ftype,
                                         "label": ENC_LABELS.get(ftype, ftype) + (f" · {title_from_const(part.upper())}" if part else ""),
                                         "rate": table.get("encounter_rate"),
                                         "mons": sorted(merged.values(), key=lambda m: -m["chance"])})
            if sections:
                _encounters.setdefault(enc["map"], []).extend(sections)
    return _encounters


def render_mon(const, shiny=False):
    trainer_data()
    pic, pal, shiny_pal = _mon_pics[const]
    if shiny and shiny_pal:
        pal = shiny_pal
    img = Image.open(ROOT / pic)
    frame = img.crop((0, 0, 64, 64))
    colors = read_pal(ROOT / pal)
    out = Image.new("RGBA", (64, 64))
    if frame.mode == "P":
        out.putdata([(0, 0, 0, 0) if (i & 0xF) == 0 else colors[i & 0xF] + (255,) for i in frame.tobytes()])
    else:
        out = frame.convert("RGBA")
    buf = io.BytesIO()
    out.save(buf, "PNG")
    return buf.getvalue()


# ---------------------------------------------------------------- items

def item_list():
    t = read(ROOT / "include/constants/items.h")
    return [n for n in re.findall(r"^\s*(ITEM_[A-Z0-9_]+)\s*=", t, re.M)
            if n not in ("ITEM_NONE",) and not n.startswith("ITEM_USE_")]


def flag_used_elsewhere(flag, map_name):
    hits = subprocess.run(["git", "grep", "-lw", flag, "--", "data", "src", "include"],
                          capture_output=True, text=True, cwd=ROOT).stdout.split()
    allowed = {f"data/maps/{map_name}/map.json", "include/constants/flags.h"}
    return [h for h in hits if h not in allowed]


def set_item(map_name, kind, index, item):
    with WRITE_LOCK:
        path = ROOT / "data/maps" / map_name / "map.json"
        m = json.loads(read(path))
        if kind == "object":
            ev = m["object_events"][index]
            item_key = "trainer_sight_or_berry_tree_id"
        else:
            ev = m["bg_events"][index]
            item_key = "item"
        old_item, old_flag = ev[item_key], ev["flag"]
        if item not in item_list():
            raise ValueError(f"Unknown item {item}")
        ev[item_key] = item
        note = ""
        suffix_old = old_item[len("ITEM_"):] if old_item.startswith("ITEM_") else "\x00"
        fm = (re.match(r"^(FLAG_\w+?)_(%s)(_\d+)?$" % re.escape(suffix_old), old_flag)
              or re.match(r"^(FLAG_\w+)_(\d+)$", old_flag))
        if fm:
            flags_text = read(FLAGS_FILE)
            base = f"{fm.group(1)}_{item[len('ITEM_'):]}"
            new_flag, n = base, 2
            while re.search(r"#define\s+%s\b" % new_flag, flags_text) and new_flag != old_flag:
                new_flag, n = f"{base}_{n}", n + 1
            elsewhere = flag_used_elsewhere(old_flag, map_name)
            if new_flag != old_flag and not elsewhere:
                def repl(mm):
                    pad = max(1, len(mm.group(0)) - len("#define ") - len(new_flag) - len(mm.group(2)))
                    return f"#define {new_flag}{' ' * pad}{mm.group(2)}"
                flags_text, count = re.subn(r"#define\s+%s(\s+)(\S+)" % re.escape(old_flag),
                                            lambda mm: repl(mm), flags_text, count=1)
                if count:
                    write(FLAGS_FILE, flags_text)
                    ev["flag"] = new_flag
                    note = f"Flag renamed {old_flag} → {new_flag}."
            elif elsewhere:
                note = f"Kept flag {old_flag} (also used in {', '.join(elsewhere)})."
        write(path, json.dumps(m, indent=2) + "\n")
        return note


# ---------------------------------------------------------------- per-object settings

# Lives on the event itself in map.json: mapjson only reads keys it knows, and Porymap keeps
# unrecognized keys and shows them under Custom Attributes, so the setting survives both tools.
MUTED_KEY = "poe_muted"
FALSY = ("", "false", "0", "no")


def is_muted(ev):
    """Muted events are never reported as to-dos. Tolerates a hand-typed string from Porymap."""
    v = ev.get(MUTED_KEY)
    if isinstance(v, str):
        return v.strip().lower() not in FALSY
    return bool(v)


def set_muted(map_name, src, index, muted):
    with WRITE_LOCK:
        path = ROOT / "data/maps" / map_name / "map.json"
        m = json.loads(read(path))
        ev = m[EVENT_KEYS[src]][index]
        if muted:
            ev[MUTED_KEY] = True
        else:
            ev.pop(MUTED_KEY, None)
        write(path, json.dumps(m, indent=2) + "\n")


# ---------------------------------------------------------------- map objects

EVENT_KEYS = {"object": "object_events", "bg": "bg_events", "coord": "coord_events", "warp": "warp_events"}

def classify(ev, map_name):
    script = ev.get("script", "")
    num = re.search(r"(\d+)$", script)
    n = num.group(1) if num else ""
    if ev.get("graphics_id") == "OBJ_EVENT_GFX_ITEM_BALL" or script == "Common_EventScript_FindItem":
        return "item", "I"
    if "trainer_type" in ev and ev["trainer_type"] not in ("TRAINER_TYPE_NONE", "0"):
        return "trainer", "T" + n
    if "_EventScript_Trainer" in script:
        return "trainer", "T" + n
    if re.search(r"_EventScript_Tree\d+$", script) or "CUTTABLE_TREE" in ev.get("graphics_id", ""):
        return "fieldobj", "C"
    if re.search(r"_EventScript_Rock\d+$", script) or "BREAKABLE_ROCK" in ev.get("graphics_id", "") or "BOULDER" in ev.get("graphics_id", ""):
        return "fieldobj", "R"
    return "npc", "N" + n


def map_objects(map_name):
    m = load_map(map_name)
    objs = []
    for i, ev in enumerate(m.get("object_events", [])):
        kind, tag = classify(ev, map_name)
        icon = GFX_ICONS.get(ev.get("graphics_id", ""), "item_ball" if kind == "item" else None)
        obj = {"kind": kind, "tag": tag, "src": "object", "index": i, "x": ev["x"], "y": ev["y"],
               "script": ev.get("script", ""), "gfx": ev.get("graphics_id", ""), "icon": icon}
        if kind == "item":
            obj["item"] = ev.get("trainer_sight_or_berry_tree_id", "")
        if kind in ("trainer", "npc"):
            info = sprite_info(obj["gfx"])
            if info:
                obj["sprite"] = {"w": info["w"], "h": info["h"], "dir": facing_for(ev.get("movement_type", ""))}
        objs.append(obj)
    for i, ev in enumerate(m.get("bg_events", [])):
        if ev["type"] == "hidden_item":
            objs.append({"kind": "hidden", "tag": "H", "src": "bg", "index": i, "x": ev["x"], "y": ev["y"], "script": "",
                         "item": ev.get("item", "")})
        else:
            n = re.search(r"(\d+)$", ev.get("script", ""))
            objs.append({"kind": "sign", "tag": "S" + (n.group(1) if n else ""), "src": "bg", "index": i,
                         "x": ev["x"], "y": ev["y"], "script": ev.get("script", ""), "icon": "sign"})
    for i, ev in enumerate(m.get("coord_events", [])):
        if ev.get("type") != "trigger":
            continue
        n = re.search(r"(\d+)$", ev.get("script", ""))
        objs.append({"kind": "trigger", "tag": "E" + (n.group(1) if n else ""), "src": "coord", "index": i,
                     "x": ev["x"], "y": ev["y"], "script": ev.get("script", "")})
    for i, ev in enumerate(m.get("warp_events", [])):
        folder = map_folder(ev.get("dest_map", ""))
        objs.append({"kind": "warp", "tag": "W", "src": "warp", "index": i, "x": ev["x"], "y": ev["y"],
                     "script": "", "dest": ev.get("dest_map", ""), "destFolder": folder,
                     "destLabel": pretty_map_name(folder) if folder else ev.get("dest_map", "")})
    icons = item_icons()
    for o in objs:
        o["muted"] = is_muted(m[EVENT_KEYS[o["src"]]][o["index"]])
        o["placeholder"] = not o["muted"] and is_placeholder(map_name, o)
        if o.get("item") in icons:
            o["itemIcon"] = o["item"]
    conns = []
    for c in m.get("connections") or []:
        folder = map_folder(c.get("map", ""))
        conns.append({"direction": c.get("direction"), "map": c.get("map"), "folder": folder,
                      "label": pretty_map_name(folder) if folder else c.get("map")})
    layout = load_layout(m["layout"])
    raw = (ROOT / layout["blockdata_filepath"]).read_bytes()
    collision = [1 if int.from_bytes(raw[i:i + 2], "little") & 0xC00 else 0 for i in range(0, len(raw), 2)]
    return {"name": map_name, "id": m.get("id"), "hasEncounters": bool(encounter_db().get(m.get("id"))),
            "label": pretty_map_name(map_name), "width": layout["width"],
            "height": layout["height"], "objects": objs, "connections": conns,
            "collision": collision[:layout["width"] * layout["height"]]}


def is_placeholder(map_name, o):
    if o["kind"] in ("warp", "fieldobj", "hidden"):
        return False
    if o["kind"] == "item":
        return bool(re.search(r"_\d+$", load_map(map_name)["object_events"][o["index"]].get("flag", "")))
    if not o["script"] or o["script"] == "NULL":
        return True
    info = collect_script(map_name, o["script"])
    if not info:
        return False
    if any(PLACEHOLDER_TEXT_RE.search(re.sub(r"\\[nlp]", " ", "".join(t["strings"]))) for t in info["texts"]):
        return True
    tm = re.search(r"trainerbattle_\w+\s+(TRAINER_\w+)", info["body"])
    if tm:
        party = get_party(tm.group(1))
        body = party.split("\n\n", 1)[1] if party and "\n\n" in party else ""
        return bool(PLACEHOLDER_PARTY_RE.match(body))
    return False


def object_detail(map_name, src, index):
    m = load_map(map_name)
    ev = m[EVENT_KEYS[src]][index]
    out = {"event": ev, "muted": is_muted(ev)}
    if src == "warp":
        out["dest_folder"] = map_folder(ev.get("dest_map", ""))
        out["dest_label"] = pretty_map_name(out["dest_folder"]) if out["dest_folder"] else ev.get("dest_map", "")
        return out
    script = ev.get("script", "")
    if src == "object" and (ev.get("graphics_id") == "OBJ_EVENT_GFX_ITEM_BALL" or script == "Common_EventScript_FindItem"):
        out["item"] = {"kind": "object", "item": ev["trainer_sight_or_berry_tree_id"], "flag": ev["flag"]}
        return out
    if src == "bg" and ev.get("type") == "hidden_item":
        out["item"] = {"kind": "bg", "item": ev["item"], "flag": ev["flag"]}
        return out
    if script and script != "NULL":
        info = collect_script(map_name, script)
        if info:
            out["script"] = info
            tm = re.search(r"trainerbattle_\w+\s+(TRAINER_\w+)", info["body"])
            if tm:
                out["trainer"] = {"id": tm.group(1), "party": get_party(tm.group(1))}
        else:
            out["script_elsewhere"] = script
    return out


# ---------------------------------------------------------------- text metrics

def text_metrics():
    fonts = read(ROOT / "src/fonts.c")
    arr = re.search(r"gFontNormalLatinGlyphWidths\[\]\s*=\s*\{(.*?)\};", fonts, re.S).group(1)
    widths = [int(x) for x in re.findall(r"\d+", arr)]
    chars, named = {}, dict(PLACEHOLDER_WIDTHS)
    for line in read(ROOT / "charmap.txt").splitlines():
        line = line.split("@")[0].rstrip()
        m = re.match(r"^'((?:\\.|[^'\\])+)'\s*=\s*([0-9A-Fa-f ]+)$", line)
        if m:
            ch = m.group(1).replace("\\'", "'").replace('\\"', '"')
            if ch.startswith("\\"):
                continue
            bs = [int(b, 16) for b in m.group(2).split()]
            if len(ch) == 1 and ch not in chars:
                chars[ch] = sum(widths[b] if b < len(widths) else 0 for b in bs)
            continue
        m = re.match(r"^([A-Z_][A-Z0-9_]*)\s*=\s*([0-9A-Fa-f ]+)$", line)
        if m and m.group(1) not in named:
            bs = [int(b, 16) for b in m.group(2).split()]
            named[m.group(1)] = 0 if bs[0] >= 0xF7 else sum(widths[b] for b in bs if b < len(widths))
    return {"chars": chars, "named": named, "maxWidth": MAX_TEXT_WIDTH}


# ---------------------------------------------------------------- http

class Handler(BaseHTTPRequestHandler):
    def log_message(self, fmt, *args):
        pass

    def send(self, code, body, ctype="application/json"):
        if not isinstance(body, bytes):
            body = json.dumps(body).encode()
        self.send_response(code)
        self.send_header("Content-Type", ctype)
        self.send_header("Cache-Control", "no-store")
        self.send_header("Content-Length", str(len(body)))
        self.end_headers()
        self.wfile.write(body)

    def do_GET(self):
        u = urlparse(self.path)
        q = {k: v[0] for k, v in parse_qs(u.query).items()}
        try:
            if u.path == "/":
                self.send(200, (HERE / "index.html").read_bytes(), "text/html; charset=utf-8")
            elif u.path == "/poe-icon.png":
                self.send(200, (HERE / "poe-icon.png").read_bytes(), "image/png")
            elif u.path == "/api/init":
                self.send(200, {"maps": map_names(), "defaultMap": self.server.default_map,
                                "metrics": text_metrics(), "items": item_list(),
                                "movementTypes": movement_types(), "facing": sprite_db()["facing"],
                                "maxRange": MAX_MOVEMENT_RANGE, "maxSight": MAX_SIGHT,
                                "itemIcons": sorted(item_icons()),
                                "storyStates": story_states(), "storyAudit": story_state_audit()})
            elif u.path == "/api/map":
                self.send(200, map_objects(q["name"]))
            elif u.path == "/api/encounters":
                self.send(200, {"sections": encounter_db().get(q["map"], [])})
            elif u.path == "/api/map.png":
                self.send(200, render_map(q["name"]), "image/png")
            elif u.path == "/api/trainerdata":
                self.send(200, trainer_data())
            elif u.path == "/api/mon.png":
                self.send(200, render_mon(q["species"], q.get("shiny") == "1"), "image/png")
            elif u.path == "/api/itemicon.png":
                self.send(200, render_item_icon(q["item"]), "image/png")
            elif u.path == "/api/sprite.png":
                self.send(200, render_sprite(q["gfx"], q.get("dir", "south")), "image/png")
            elif u.path == "/api/icon.png":
                self.send(200, render_icon(q["name"]), "image/png")
            elif u.path == "/api/object":
                self.send(200, object_detail(q["map"], q["src"], int(q["index"])))
            else:
                self.send(404, {"error": "not found"})
        except Exception as e:
            self.send(500, {"error": f"{type(e).__name__}: {e}"})

    def do_POST(self):
        u = urlparse(self.path)
        try:
            data = json.loads(self.rfile.read(int(self.headers.get("Content-Length", 0))))
            if u.path == "/api/text":
                with WRITE_LOCK:
                    replace_text(data["map"], data["label"], data["expected"], data["strings"])
                self.send(200, {"ok": True})
            elif u.path == "/api/script":
                with WRITE_LOCK:
                    replace_script(data["map"], data["label"], data["expected"], data["body"])
                self.send(200, {"ok": True})
            elif u.path == "/api/party":
                errors = replace_party(data["trainer"], data["expected"], data["party"])
                self.send(200 if not errors else 422, {"ok": not errors, "errors": errors})
            elif u.path == "/api/movement":
                set_movement(data["map"], int(data["index"]), data["expected"], data["type"],
                             data["rx"], data["ry"], data.get("sight"))
                self.send(200, {"ok": True})
            elif u.path == "/api/item":
                note = set_item(data["map"], data["kind"], int(data["index"]), data["item"])
                self.send(200, {"ok": True, "note": note})
            elif u.path == "/api/mute":
                set_muted(data["map"], data["src"], int(data["index"]), bool(data["muted"]))
                self.send(200, {"ok": True})
            else:
                self.send(404, {"error": "not found"})
        except ConflictError as e:
            self.send(409, {"error": str(e)})
        except Exception as e:
            self.send(500, {"error": f"{type(e).__name__}: {e}"})


def main():
    args = sys.argv[1:]
    port = int(args[args.index("--port") + 1]) if "--port" in args else 8765
    positional = [a for i, a in enumerate(args) if not a.startswith("--") and (i == 0 or args[i - 1] != "--port")]
    default_map = positional[0] if positional else ""
    if default_map and default_map not in map_names():
        sys.exit(f"Unknown map {default_map!r} (use the folder name under data/maps/)")
    for p in range(port, port + 20):
        try:
            server = ThreadingHTTPServer(("127.0.0.1", p), Handler)
            break
        except OSError:
            continue
    else:
        sys.exit("No free port")
    server.default_map = default_map
    url = f"http://127.0.0.1:{server.server_address[1]}/" + (f"#{default_map}" if default_map else "")
    print(f"Poe running at {url}  (Ctrl+C to stop)", flush=True)
    if "--no-browser" not in args:
        webbrowser.open(url)
    try:
        server.serve_forever()
    except KeyboardInterrupt:
        pass


if __name__ == "__main__":
    main()
