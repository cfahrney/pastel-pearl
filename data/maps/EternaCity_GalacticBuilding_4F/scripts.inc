EternaCity_GalacticBuilding_4F_MapScripts::
	.byte 0

EternaCity_GalacticBuilding_4F_EventScript_NPC1::
	lockall
	faceplayer
	applymovement LOCALID_ETERNA_CITY_GALACTIC_BUILDING_4_F_MIDDLE_AGED_MAN, EternaCity_GalacticBuilding_4F_Movement_MiddleAgedMan
	waitmovement 0
	msgbox EternaCity_GalacticBuilding_4F_Text_NPC1, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_ETERNA_CITY_GALACTIC_BUILDING_4F_2, EternaCity_GalacticBuilding_4F_Text_NPC1Defeated
	msgbox EternaCity_GalacticBuilding_4F_Text_NPC1_2, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_ETERNA_CITY_GALACTIC_BUILDING_4_F_JUPITER
	fadescreen FADE_FROM_BLACK
	delay 30
	copyvar VAR_0x8004, VAR_FACING
	goto_if_eq VAR_0x8004, DIR_NORTH, EternaCity_GalacticBuilding_4F_EventScript_NPC1_2_2
	goto_if_eq VAR_0x8004, DIR_SOUTH, EternaCity_GalacticBuilding_4F_EventScript_NPC1_2_3
	goto_if_eq VAR_0x8004, DIR_WEST, EternaCity_GalacticBuilding_4F_EventScript_NPC1_2_4
	goto_if_eq VAR_0x8004, DIR_EAST, EternaCity_GalacticBuilding_4F_EventScript_NPC1_2_5
	end

EternaCity_GalacticBuilding_4F_EventScript_NPC1_2::
	releaseall
	end

EternaCity_GalacticBuilding_4F_EventScript_NPC1_2_2::
	applymovement LOCALID_ETERNA_CITY_GALACTIC_BUILDING_4_F_MIDDLE_AGED_MAN, EternaCity_GalacticBuilding_4F_Movement_MiddleAgedMan2
	applymovement LOCALID_PLAYER, EternaCity_GalacticBuilding_4F_Movement_Player
	waitmovement 0
	goto EternaCity_GalacticBuilding_4F_EventScript_NPC1_2_6

EternaCity_GalacticBuilding_4F_EventScript_NPC1_2_3::
	applymovement LOCALID_ETERNA_CITY_GALACTIC_BUILDING_4_F_MIDDLE_AGED_MAN, EternaCity_GalacticBuilding_4F_Movement_MiddleAgedMan3
	applymovement LOCALID_PLAYER, EternaCity_GalacticBuilding_4F_Movement_Player2
	waitmovement 0
	goto EternaCity_GalacticBuilding_4F_EventScript_NPC1_2_6

EternaCity_GalacticBuilding_4F_EventScript_NPC1_2_4::
	applymovement LOCALID_ETERNA_CITY_GALACTIC_BUILDING_4_F_MIDDLE_AGED_MAN, EternaCity_GalacticBuilding_4F_Movement_MiddleAgedMan4
	waitmovement 0
	goto EternaCity_GalacticBuilding_4F_EventScript_NPC1_2_6

EternaCity_GalacticBuilding_4F_EventScript_NPC1_2_5::
	applymovement LOCALID_ETERNA_CITY_GALACTIC_BUILDING_4_F_MIDDLE_AGED_MAN, EternaCity_GalacticBuilding_4F_Movement_MiddleAgedMan5
	applymovement LOCALID_PLAYER, EternaCity_GalacticBuilding_4F_Movement_Player3
	waitmovement 0
	goto EternaCity_GalacticBuilding_4F_EventScript_NPC1_2_6

EternaCity_GalacticBuilding_4F_EventScript_NPC1_2_6::
	msgbox EternaCity_GalacticBuilding_4F_Text_NPC1_3, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	setflag FLAG_HIDE_ETERNA_CITY_GALACTIC_GRUNT
	setflag FLAG_ETERNA_CITY_BIKE_SHOP_YOUNGSTER_1
	clearflag FLAG_HIDE_ETERNA_CITY_BIKE_SHOP_MIDDLE_AGED_MAN
	clearflag FLAG_HIDE_ETERNA_CITY_BIKE_SHOP_CLEFAIRY
	clearflag FLAG_ETERNA_CITY_GALACTIC_BUILDING_4F_JUPITER_1
	removeobject LOCALID_ETERNA_CITY_GALACTIC_BUILDING_4_F_MIDDLE_AGED_MAN
	removeobject LOCALID_ETERNA_CITY_GALACTIC_BUILDING_4_F_CLEFAIRY
	removeobject LOCALID_ETERNA_CITY_GALACTIC_BUILDING_4_F_BUNEARY
	fadescreen FADE_FROM_BLACK
	@ TODO(DP): Set DP system flag 2439
	releaseall
	end

EternaCity_GalacticBuilding_4F_EventScript_NPC2::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_CLEFAIRY, CRY_MODE_NORMAL
	message EternaCity_GalacticBuilding_4F_Text_NPC2
	waitmessage
	waitmoncry
	waitbuttonpress
	closemessage
	release
	end

EternaCity_GalacticBuilding_4F_EventScript_NPC3::
	lock
	faceplayer
	goto_if_set FLAG_ETERNA_CITY_BIKE_SHOP_YOUNGSTER_1, EternaCity_GalacticBuilding_4F_EventScript_NPC3_2
	msgbox EternaCity_GalacticBuilding_4F_Text_NPC3, MSGBOX_DEFAULT
	closemessage
	release
	end

EternaCity_GalacticBuilding_4F_EventScript_NPC3_2::
	msgbox EternaCity_GalacticBuilding_4F_Text_NPC1_3, MSGBOX_DEFAULT
	waitbuttonpress
	closemessage
	release
	end

EternaCity_GalacticBuilding_4F_EventScript_NPC4::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_BUNEARY, CRY_MODE_NORMAL
	message EternaCity_GalacticBuilding_4F_Text_NPC4
	waitmessage
	waitmoncry
	waitbuttonpress
	closemessage
	release
	end

EternaCity_GalacticBuilding_4F_Movement_MiddleAgedMan:
	walk_in_place_right
	step_end

EternaCity_GalacticBuilding_4F_Movement_MiddleAgedMan2:
	delay_16
	walk_right
	walk_right
	walk_in_place_down
	step_end

EternaCity_GalacticBuilding_4F_Movement_Player:
	walk_in_place_left
	delay_8
	walk_in_place_up
	step_end

EternaCity_GalacticBuilding_4F_Movement_MiddleAgedMan3:
	delay_16
	walk_right
	walk_right
	walk_in_place_up
	step_end

EternaCity_GalacticBuilding_4F_Movement_Player2:
	walk_in_place_left
	delay_8
	walk_in_place_down
	step_end

EternaCity_GalacticBuilding_4F_Movement_MiddleAgedMan4:
	delay_16
	walk_right
	walk_right
	step_end

EternaCity_GalacticBuilding_4F_Movement_MiddleAgedMan5:
	delay_16
	walk_in_place_right
	step_end

EternaCity_GalacticBuilding_4F_Movement_Player3:
	walk_in_place_left
	step_end

EternaCity_GalacticBuilding_4F_Text_NPC1:
	.string "Eh? Did you want something?\p"
	.string "How silly of me to even ask. You want to\n"
	.string "free the Pokémon.\p"
	.string "Yeah, that's gonna happen!$"

EternaCity_GalacticBuilding_4F_Text_NPC1Defeated:
	.string "Losing to some child... Being careless\n"
	.string "cost me too much.$"

EternaCity_GalacticBuilding_4F_Text_NPC1_2:
	.string "Well, aren't you tough...?\p"
	.string "It's OK, though. Our official Pokémon-\n"
	.string "statue investigation is finished.\p"
	.string "Mars has collected energy from the\n"
	.string "Valley Windworks.\p"
	.string "We're pretty much finished here. I'll let\n"
	.string "you in on one little thing.\p"
	.string "Our boss is researching the myths of\n"
	.string "ancient Pokémon.\p"
	.string "With the power of mythical Pokémon, he\n"
	.string "will become the ruler of {COLOR DYNAMIC_COLOR3}Sinnoh{COLOR DARK_GRAY}...\p"
	.string "I suggest you keep out of Team\n"
	.string "Galactic's affairs from now on.\p"
	.string "This is your last warning!$"

EternaCity_GalacticBuilding_4F_Text_NPC1_3:
	.string "I got my Clefairy back, and it's all\n"
	.string "thanks to you!\p"
	.string "But that Team Galactic...\p"
	.string "They said, “Clefairy came from space.\n"
	.string "Hand it over!” Their logic baffles me\l"
	.string "still. It's like they are from space!\p"
	.string "Anyway, they're gone now. Thank you\n"
	.string "very much!\p"
	.string "I can't thank you enough right now, but\n"
	.string "cruise by my Cycle Shop, OK?$"

EternaCity_GalacticBuilding_4F_Text_NPC2:
	.string "{SPEAKER NAME_CLEFAIRY}Pi...$"

EternaCity_GalacticBuilding_4F_Text_NPC3:
	.string "What is it with this Team Galactic?\p"
	.string "Why did they take our Pokémon? What\n"
	.string "are they trying to accomplish?$"

EternaCity_GalacticBuilding_4F_Text_NPC4:
	.string "{SPEAKER NAME_BUNEARY}Myun...$"
