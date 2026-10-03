SandgemTown_BottomRightHouse_1F_MapScripts::
	.byte 0

SandgemTown_BottomRightHouse_1F_EventScript_NPC1::
	msgbox SandgemTown_BottomRightHouse_1F_Text_NPC1, MSGBOX_NPC
	end

SandgemTown_BottomRightHouse_1F_EventScript_NPC2::
	msgbox SandgemTown_BottomRightHouse_1F_Text_NPC2, MSGBOX_NPC
	end

SandgemTown_BottomRightHouse_1F_EventScript_NPC3::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_BIDOOF, CRY_MODE_NORMAL
	setspeaker SandgemTown_BottomRightHouse_1F_Text_NPC3Speaker
	msgbox SandgemTown_BottomRightHouse_1F_Text_NPC3, MSGBOX_DEFAULT
	waitmoncry
	release
	end

SandgemTown_BottomRightHouse_1F_Text_NPC1:
	.string "Ah, so that Rowan fellow is back? He's\n"
	.string "quite the remarkable man.\p"
	.string "He's been studying Pokémon since way,\n"
	.string "way back.\p"
	.string "My son and grandchild help Rowan with\n"
	.string "his studies now.$"

SandgemTown_BottomRightHouse_1F_Text_NPC2:
	.string "Who are you?\p"
	.string "...\p"
	.string "Oh, I see! You're doing that {COLOR DYNAMIC_COLOR3}Pokédex{COLOR DARK_GRAY}\n"
	.string "thing for the professor!\p"
	.string "Wow! That's the same as my big sibling!\n"
	.string "Go for it!$"

SandgemTown_BottomRightHouse_1F_Text_NPC3:
	.string "Doooof?$"

SandgemTown_BottomRightHouse_1F_Text_NPC3Speaker:
	.string "Bidoof$"
