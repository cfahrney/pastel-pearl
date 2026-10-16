CanalaveCity_SouthOfMartHouse_MapScripts::
	.byte 0

CanalaveCity_SouthOfMartHouse_EventScript_NPC1::
	msgbox CanalaveCity_SouthOfMartHouse_Text_NPC1_2, MSGBOX_NPC
	end

CanalaveCity_SouthOfMartHouse_EventScript_NPC2::
	lock
	faceplayer
	goto_if_set FLAG_CANALAVE_CITY_SOUTH_OF_MART_HOUSE_WOMAN_1, CanalaveCity_SouthOfMartHouse_EventScript_NPC2_2
	msgbox CanalaveCity_SouthOfMartHouse_Text_NPC2_2, MSGBOX_DEFAULT
	setvar VAR_0x8004, ITEM_TM_SKILL_SWAP
	setvar VAR_0x8005, 1
	checkitemspace VAR_0x8004, VAR_0x8005
	goto_if_eq VAR_RESULT, FALSE, CanalaveCity_SouthOfMartHouse_EventScript_NPC2_2_2
	giveitem VAR_0x8004, VAR_0x8005
	setflag FLAG_CANALAVE_CITY_SOUTH_OF_MART_HOUSE_WOMAN_1
	goto CanalaveCity_SouthOfMartHouse_EventScript_NPC2_2

CanalaveCity_SouthOfMartHouse_EventScript_NPC2_2::
	msgbox CanalaveCity_SouthOfMartHouse_Text_NPC2_3, MSGBOX_DEFAULT
	closemessage
	release
	end

CanalaveCity_SouthOfMartHouse_EventScript_NPC2_2_2::
	msgbox gText_TooBadBagIsFull, MSGBOX_DEFAULT
	closemessage
	release
	end

CanalaveCity_SouthOfMartHouse_Text_NPC1_2:
	.string "Somewhere beyond the sea...\p"
	.string "There are other lands populated by\n"
	.string "Pokémon and Trainers.$"

CanalaveCity_SouthOfMartHouse_Text_NPC2_2:
	.string "Hello, Trainer! This is something I\n"
	.string "found.\p"
	.string "It was mixed in with a load of cargo\n"
	.string "from another country.\p"
	.string "It's not anything that I can use, so I\n"
	.string "think you should take it.$"

CanalaveCity_SouthOfMartHouse_Text_NPC2_3:
	.string "You know how Pokémon have their own\n"
	.string "abilities?\p"
	.string "Well, the move Skill Swap exchanges the\n"
	.string "user's ability with that of its target\l"
	.string "Pokémon.\p"
	.string "How you use Skill Swap is a measure of\n"
	.string "your expertise as a Trainer.$"
