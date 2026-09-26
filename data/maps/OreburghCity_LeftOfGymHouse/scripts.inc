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
	setspeaker OreburghCity_LeftOfGymHouse_Text_NPC3Speaker
	msgbox OreburghCity_LeftOfGymHouse_Text_NPC3, MSGBOX_DEFAULT
	waitmoncry
	release
	end

OreburghCity_LeftOfGymHouse_Text_NPC1:
	.string "You know how Pokemon have different\n"
	.string "natures like we have personalities?\p"
	.string "I don't think it's surprising to see\n"
	.string "Pokemon in different colors.$"

OreburghCity_LeftOfGymHouse_Text_NPC2:
	.string "Have you ever seen or heard about\n"
	.string "differently colored Pokemon?\p"
	.string "For instance, a regular Pikachu has a\n"
	.string "yellow body, correct?\p"
	.string "Well, the different-colored Pikachu has\n"
	.string "a sort of orange body.$"

OreburghCity_LeftOfGymHouse_Text_NPC3:
	.string "Pikaaah!$"

OreburghCity_LeftOfGymHouse_Text_NPC3Speaker:
	.string "Pikachu$"
