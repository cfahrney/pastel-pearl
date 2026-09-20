OreburghCity_NorthOfMinesHouse_MapScripts::
	.byte 0

OreburghCity_NorthOfMinesHouse_EventScript_NPC1::
	msgbox OreburghCity_NorthOfMinesHouse_Text_NPC1, MSGBOX_NPC
	end

OreburghCity_NorthOfMinesHouse_EventScript_NPC2::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_GEODUDE, CRY_MODE_NORMAL
	msgbox OreburghCity_NorthOfMinesHouse_Text_NPC2, MSGBOX_DEFAULT
	waitmoncry
	release
	end

OreburghCity_NorthOfMinesHouse_Text_NPC1:
	.string "NORTH OF MINES HOUSE\nNPC 1$"

OreburghCity_NorthOfMinesHouse_Text_NPC2:
	.string "NORTH OF MINES HOUSE\nNPC 2$"
