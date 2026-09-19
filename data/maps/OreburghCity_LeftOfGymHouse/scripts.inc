OreburghCity_LeftOfGymHouse_MapScripts::
	.byte 0

OreburghCity_LeftOfGymHouse_EventScript_NPC1::
	msgbox OreburghCity_LeftOfGymHouse_Text_NPC1, MSGBOX_NPC
	end

OreburghCity_LeftOfGymHouse_EventScript_NPC2::
	msgbox OreburghCity_LeftOfGymHouse_Text_NPC2, MSGBOX_NPC
	end

OreburghCity_LeftOfGymHouse_EventScript_NPC3::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_PIKACHU, CRY_MODE_NORMAL
	msgbox OreburghCity_LeftOfGymHouse_Text_NPC3, MSGBOX_DEFAULT
	waitmoncry
	release
	end

OreburghCity_LeftOfGymHouse_Text_NPC1:
	.string "OREBURGH CITY LEFT OF GYM HOUSE\n"
	.string "NPC 1$"

OreburghCity_LeftOfGymHouse_Text_NPC2:
	.string "OREBURGH CITY LEFT OF GYM HOUSE\n"
	.string "NPC 2$"

OreburghCity_LeftOfGymHouse_Text_NPC3:
	.string "OREBURGH CITY LEFT OF GYM HOUSE\n"
	.string "NPC 3$"
