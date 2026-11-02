EternaCity_WestOfGymEntranceHouse_MapScripts::
	.byte 0

EternaCity_WestOfGymEntranceHouse_EventScript_NPC1::
	lockall
	faceplayer
	goto_if_set FLAG_ETERNA_CITY_WEST_OF_GYM_ENTRANCE_HOUSE_PROF_OAK_1, EternaCity_WestOfGymEntranceHouse_EventScript_NPC1_2
	setspeaker EternaCity_WestOfGymEntranceHouse_Text_OakSpeaker
	msgbox EternaCity_WestOfGymEntranceHouse_Text_NPC1_2, MSGBOX_DEFAULT
	closemessage
	playse SE_PIN
	applymovement LOCALID_ETERNA_CITY_WEST_OF_GYM_ENTRANCE_HOUSE_PROF_OAK, EternaCity_WestOfGymEntranceHouse_Movement_ProfOak
	waitmovement 0
	setspeaker EternaCity_WestOfGymEntranceHouse_Text_OakSpeaker
	msgbox EternaCity_WestOfGymEntranceHouse_Text_NPC1_3, MSGBOX_DEFAULT
	setvar VAR_0x8004, ITEM_UPGRADE
	setvar VAR_0x8005, 1
	checkitemspace VAR_0x8004, VAR_0x8005
	goto_if_eq VAR_RESULT, FALSE, EternaCity_WestOfGymEntranceHouse_EventScript_NPC1_2_2
	giveitem VAR_0x8004, VAR_0x8005
	setflag FLAG_ETERNA_CITY_WEST_OF_GYM_ENTRANCE_HOUSE_PROF_OAK_1
	msgbox EternaCity_WestOfGymEntranceHouse_Text_NPC1_4, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

EternaCity_WestOfGymEntranceHouse_EventScript_NPC1_2::
	@ TODO(DP): Common DP script 9952
	end

EternaCity_WestOfGymEntranceHouse_EventScript_NPC1_2_2::
	msgbox gText_TooBadBagIsFull, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

EternaCity_WestOfGymEntranceHouse_Movement_ProfOak:
	emote_exclamation_mark
	step_end

EternaCity_WestOfGymEntranceHouse_Text_OakSpeaker:
	.string "Oak$"

EternaCity_WestOfGymEntranceHouse_Text_NPC1_2:
	.string "Ah, it's you! Good to see you! How is\n"
	.string "your {COLOR DYNAMIC_COLOR3}Pokédex{COLOR DARK_GRAY} coming along?\p"
	.string "Capturing every kind of Pokémon is no\n"
	.string "easy feat, I'll grant you that.\p"
	.string "But I'm sure you can accomplish it!$"

EternaCity_WestOfGymEntranceHouse_Text_NPC1_3:
	.string "Ah, yes!\p"
	.string "An acquaintance from {COLOR DYNAMIC_COLOR3}Kanto{COLOR DARK_GRAY} has sent me\n"
	.string "something quite interesting.\p"
	.string "I think you'd make better use of it than\n"
	.string "I ever could.$"

EternaCity_WestOfGymEntranceHouse_Text_NPC1_4:
	.string "I understand there is a Pokémon that\n"
	.string "evolves when it is traded while holding\l"
	.string "that Up-Grade.$"
