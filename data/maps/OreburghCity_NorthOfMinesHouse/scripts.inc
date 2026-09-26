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
	setspeaker OreburghCity_NorthOfMinesHouse_Text_NPC2Speaker
	msgbox OreburghCity_NorthOfMinesHouse_Text_NPC2, MSGBOX_DEFAULT
	waitmoncry
	release
	end

OreburghCity_NorthOfMinesHouse_Text_NPC1:
	.string "My Geodude much prefers working in the\n"
	.string "mines with me than battling, and I'm\l"
	.string "okay with that!$"

OreburghCity_NorthOfMinesHouse_Text_NPC2:
	.string "Dude! Dude!$"

OreburghCity_NorthOfMinesHouse_Text_NPC2Speaker:
	.string "Geodude$"
