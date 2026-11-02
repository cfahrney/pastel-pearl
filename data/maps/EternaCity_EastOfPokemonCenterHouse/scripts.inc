EternaCity_EastOfPokemonCenterHouse_MapScripts::
	.byte 0

EternaCity_EastOfPokemonCenterHouse_EventScript_NPC2::
	msgbox EternaCity_EastOfPokemonCenterHouse_Text_NPC2_2, MSGBOX_NPC
	end

EternaCity_EastOfPokemonCenterHouse_EventScript_NPC3::
	lock
	faceplayer
	goto_if_set FLAG_ETERNA_CITY_EAST_OF_POKEMON_CENTER_HOUSE_ASSISTANT_1, EternaCity_EastOfPokemonCenterHouse_EventScript_NPC3_2
	setflag FLAG_ETERNA_CITY_EAST_OF_POKEMON_CENTER_HOUSE_ASSISTANT_1
	msgbox EternaCity_EastOfPokemonCenterHouse_Text_NPC3, MSGBOX_DEFAULT
	closemessage
	release
	end

EternaCity_EastOfPokemonCenterHouse_EventScript_NPC3_2::
	msgbox EternaCity_EastOfPokemonCenterHouse_Text_NPC3_2, MSGBOX_DEFAULT
	closemessage
	release
	end

EternaCity_EastOfPokemonCenterHouse_EventScript_NPC1::
	lockall
	faceplayer
	goto_if_ge VAR_ETERNA_CITY_EAST_OF_POKEMON_CENTER_HOUSE_STATE, 9, EternaCity_EastOfPokemonCenterHouse_EventScript_NPC1_2
	goto_if_set FLAG_ETERNA_CITY_EAST_OF_POKEMON_CENTER_HOUSE_OLD_MAN_1, EternaCity_EastOfPokemonCenterHouse_EventScript_NPC1_2_2
	goto_if_set FLAG_ETERNA_CITY_EAST_OF_POKEMON_CENTER_HOUSE_OLD_MAN_2, EternaCity_EastOfPokemonCenterHouse_EventScript_NPC1_2_3
	msgbox EternaCity_EastOfPokemonCenterHouse_Text_NPC1_2, MSGBOX_DEFAULT
	setvar VAR_0x8004, ITEM_NONE @ TODO(DP): ITEM_EXPLORER_KIT
	setvar VAR_0x8005, 1
	giveitem VAR_0x8004, VAR_0x8005
	setflag FLAG_ETERNA_CITY_EAST_OF_POKEMON_CENTER_HOUSE_OLD_MAN_2
	clearflag FLAG_ETERNA_CITY_EAST_OF_POKEMON_CENTER_HOUSE_OLD_MAN_3
	msgbox EternaCity_EastOfPokemonCenterHouse_Text_NPC1_3, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EternaCity_EastOfPokemonCenterHouse_EventScript_NPC1_2_4
	setflag FLAG_ETERNA_CITY_EAST_OF_POKEMON_CENTER_HOUSE_OLD_MAN_1
	goto EternaCity_EastOfPokemonCenterHouse_EventScript_NPC1_2_2

EternaCity_EastOfPokemonCenterHouse_EventScript_NPC1_2::
	msgbox EternaCity_EastOfPokemonCenterHouse_Text_NPC1_4, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

EternaCity_EastOfPokemonCenterHouse_EventScript_NPC1_2_2::
	goto_if_eq VAR_ETERNA_CITY_EAST_OF_POKEMON_CENTER_HOUSE_STATE, 0, EternaCity_EastOfPokemonCenterHouse_EventScript_NPC1_2_5
	goto_if_eq VAR_ETERNA_CITY_EAST_OF_POKEMON_CENTER_HOUSE_STATE, 1, EternaCity_EastOfPokemonCenterHouse_EventScript_NPC1_2_6
	goto_if_eq VAR_ETERNA_CITY_EAST_OF_POKEMON_CENTER_HOUSE_STATE, 2, EternaCity_EastOfPokemonCenterHouse_EventScript_NPC1_2_7
	goto_if_eq VAR_ETERNA_CITY_EAST_OF_POKEMON_CENTER_HOUSE_STATE, 3, EternaCity_EastOfPokemonCenterHouse_EventScript_NPC1_2_8
	goto_if_eq VAR_ETERNA_CITY_EAST_OF_POKEMON_CENTER_HOUSE_STATE, 4, EternaCity_EastOfPokemonCenterHouse_EventScript_NPC1_2_9
	goto_if_eq VAR_ETERNA_CITY_EAST_OF_POKEMON_CENTER_HOUSE_STATE, 5, EternaCity_EastOfPokemonCenterHouse_EventScript_NPC1_2_10
	goto_if_eq VAR_ETERNA_CITY_EAST_OF_POKEMON_CENTER_HOUSE_STATE, 6, EternaCity_EastOfPokemonCenterHouse_EventScript_NPC1_2_11
	goto_if_eq VAR_ETERNA_CITY_EAST_OF_POKEMON_CENTER_HOUSE_STATE, 7, EternaCity_EastOfPokemonCenterHouse_EventScript_NPC1_2_12
	goto_if_eq VAR_ETERNA_CITY_EAST_OF_POKEMON_CENTER_HOUSE_STATE, 8, EternaCity_EastOfPokemonCenterHouse_EventScript_NPC1_2_13
	goto EternaCity_EastOfPokemonCenterHouse_EventScript_NPC1_2

EternaCity_EastOfPokemonCenterHouse_EventScript_NPC1_2_3::
	msgbox EternaCity_EastOfPokemonCenterHouse_Text_NPC1_5, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EternaCity_EastOfPokemonCenterHouse_EventScript_NPC1_2_4
	setflag FLAG_ETERNA_CITY_EAST_OF_POKEMON_CENTER_HOUSE_OLD_MAN_1
	goto EternaCity_EastOfPokemonCenterHouse_EventScript_NPC1_2_2

EternaCity_EastOfPokemonCenterHouse_EventScript_NPC1_2_4::
	msgbox EternaCity_EastOfPokemonCenterHouse_Text_NPC1_6, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

EternaCity_EastOfPokemonCenterHouse_EventScript_NPC1_2_5::
	goto_if_unset FLAG_ETERNA_CITY_EAST_OF_POKEMON_CENTER_HOUSE_OLD_MAN_3, EternaCity_EastOfPokemonCenterHouse_EventScript_NPC1_2_14
	@ TODO(DP): goto if DP system flag 2414 is clear
	setvar VAR_ETERNA_CITY_EAST_OF_POKEMON_CENTER_HOUSE_STATE, 1
	clearflag FLAG_ETERNA_CITY_EAST_OF_POKEMON_CENTER_HOUSE_OLD_MAN_3
	msgbox EternaCity_EastOfPokemonCenterHouse_Text_NPC1_7, MSGBOX_DEFAULT
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 1
	@ TODO(DP): Common DP script 2013
	setvar VAR_0x8004, 23
	setvar VAR_0x8005, 1
	@ TODO(DP): Common DP script 2013
	setvar VAR_0x8004, 28
	setvar VAR_0x8005, 1
	@ TODO(DP): Common DP script 2013
	msgbox EternaCity_EastOfPokemonCenterHouse_Text_NPC1_8, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

EternaCity_EastOfPokemonCenterHouse_EventScript_NPC1_2_6::
	goto_if_unset FLAG_ETERNA_CITY_EAST_OF_POKEMON_CENTER_HOUSE_OLD_MAN_3, EternaCity_EastOfPokemonCenterHouse_EventScript_NPC1_2_16
	@ TODO(DP): goto if DP system flag 2415 is clear
	setvar VAR_ETERNA_CITY_EAST_OF_POKEMON_CENTER_HOUSE_STATE, 2
	clearflag FLAG_ETERNA_CITY_EAST_OF_POKEMON_CENTER_HOUSE_OLD_MAN_3
	msgbox EternaCity_EastOfPokemonCenterHouse_Text_NPC1_9, MSGBOX_DEFAULT
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 1
	@ TODO(DP): Common DP script 2014
	setvar VAR_0x8004, 3
	setvar VAR_0x8005, 1
	@ TODO(DP): Common DP script 2014
	setvar VAR_0x8004, 4
	setvar VAR_0x8005, 1
	@ TODO(DP): Common DP script 2014
	msgbox EternaCity_EastOfPokemonCenterHouse_Text_NPC1_10, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

EternaCity_EastOfPokemonCenterHouse_EventScript_NPC1_2_7::
	goto_if_unset FLAG_ETERNA_CITY_EAST_OF_POKEMON_CENTER_HOUSE_OLD_MAN_3, EternaCity_EastOfPokemonCenterHouse_EventScript_NPC1_2_18
	@ TODO(DP): goto if DP system flag 2416 is clear
	setvar VAR_ETERNA_CITY_EAST_OF_POKEMON_CENTER_HOUSE_STATE, 3
	clearflag FLAG_ETERNA_CITY_EAST_OF_POKEMON_CENTER_HOUSE_OLD_MAN_3
	msgbox EternaCity_EastOfPokemonCenterHouse_Text_NPC1_11, MSGBOX_DEFAULT
	setvar VAR_0x8004, 33
	setvar VAR_0x8005, 1
	@ TODO(DP): Common DP script 2013
	msgbox EternaCity_EastOfPokemonCenterHouse_Text_NPC1_12, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

EternaCity_EastOfPokemonCenterHouse_EventScript_NPC1_2_8::
	goto_if_unset FLAG_ETERNA_CITY_EAST_OF_POKEMON_CENTER_HOUSE_OLD_MAN_3, EternaCity_EastOfPokemonCenterHouse_EventScript_NPC1_2_20
	@ TODO(DP): goto if DP system flag 2417 is clear
	setvar VAR_ETERNA_CITY_EAST_OF_POKEMON_CENTER_HOUSE_STATE, 4
	clearflag FLAG_ETERNA_CITY_EAST_OF_POKEMON_CENTER_HOUSE_OLD_MAN_3
	msgbox EternaCity_EastOfPokemonCenterHouse_Text_NPC1_13, MSGBOX_DEFAULT
	setvar VAR_0x8004, 11
	setvar VAR_0x8005, 1
	@ TODO(DP): Common DP script 2046
	setvar VAR_0x8004, 9
	setvar VAR_0x8005, 1
	@ TODO(DP): Common DP script 2046
	setvar VAR_0x8004, 17
	setvar VAR_0x8005, 1
	@ TODO(DP): Common DP script 2046
	setvar VAR_0x8004, 113
	setvar VAR_0x8005, 1
	@ TODO(DP): Common DP script 2046
	msgbox EternaCity_EastOfPokemonCenterHouse_Text_NPC1_14, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

EternaCity_EastOfPokemonCenterHouse_EventScript_NPC1_2_9::
	goto_if_unset FLAG_ETERNA_CITY_EAST_OF_POKEMON_CENTER_HOUSE_OLD_MAN_3, EternaCity_EastOfPokemonCenterHouse_EventScript_NPC1_2_22
	@ TODO(DP): goto if DP system flag 2418 is clear
	setvar VAR_ETERNA_CITY_EAST_OF_POKEMON_CENTER_HOUSE_STATE, 5
	clearflag FLAG_ETERNA_CITY_EAST_OF_POKEMON_CENTER_HOUSE_OLD_MAN_3
	clearflag FLAG_ETERNA_CITY_EAST_OF_POKEMON_CENTER_HOUSE_OLD_MAN_4
	msgbox EternaCity_EastOfPokemonCenterHouse_Text_NPC1_15, MSGBOX_DEFAULT
	call EternaCity_EastOfPokemonCenterHouse_EventScript_NPC1_2_24
	msgbox EternaCity_EastOfPokemonCenterHouse_Text_NPC1_16, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

EternaCity_EastOfPokemonCenterHouse_EventScript_NPC1_2_10::
	goto_if_unset FLAG_ETERNA_CITY_EAST_OF_POKEMON_CENTER_HOUSE_OLD_MAN_3, EternaCity_EastOfPokemonCenterHouse_EventScript_NPC1_2_25
	@ TODO(DP): goto if DP system flag 2419 is clear
	call_if_set FLAG_ETERNA_CITY_EAST_OF_POKEMON_CENTER_HOUSE_OLD_MAN_4, EternaCity_EastOfPokemonCenterHouse_EventScript_NPC1_2_27
	call_if_unset FLAG_ETERNA_CITY_EAST_OF_POKEMON_CENTER_HOUSE_OLD_MAN_4, EternaCity_EastOfPokemonCenterHouse_EventScript_NPC1_2_28
	setvar VAR_0x8004, 81
	setvar VAR_0x8005, 1
	@ TODO(DP): HasSpaceForDecoration 32772, 32773, 32780
	goto_if_eq VAR_RESULT, YES, EternaCity_EastOfPokemonCenterHouse_EventScript_NPC1_2_29
	@ TODO(DP): Common DP script 2046
	setvar VAR_ETERNA_CITY_EAST_OF_POKEMON_CENTER_HOUSE_STATE, 6
	clearflag FLAG_ETERNA_CITY_EAST_OF_POKEMON_CENTER_HOUSE_OLD_MAN_3
	clearflag FLAG_ETERNA_CITY_EAST_OF_POKEMON_CENTER_HOUSE_OLD_MAN_4
	msgbox EternaCity_EastOfPokemonCenterHouse_Text_NPC1_17, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

EternaCity_EastOfPokemonCenterHouse_EventScript_NPC1_2_11::
	@ TODO(DP): StoreUndTime 32780
	goto_if_lt VAR_RESULT, NO, EternaCity_EastOfPokemonCenterHouse_EventScript_NPC1_2_30
	call_if_set FLAG_ETERNA_CITY_EAST_OF_POKEMON_CENTER_HOUSE_OLD_MAN_4, EternaCity_EastOfPokemonCenterHouse_EventScript_NPC1_2_27
	call_if_unset FLAG_ETERNA_CITY_EAST_OF_POKEMON_CENTER_HOUSE_OLD_MAN_4, EternaCity_EastOfPokemonCenterHouse_EventScript_NPC1_2_31
	setvar VAR_0x8004, 82
	setvar VAR_0x8005, 1
	@ TODO(DP): HasSpaceForDecoration 32772, 32773, 32780
	goto_if_eq VAR_RESULT, YES, EternaCity_EastOfPokemonCenterHouse_EventScript_NPC1_2_29
	@ TODO(DP): Common DP script 2012
	setvar VAR_ETERNA_CITY_EAST_OF_POKEMON_CENTER_HOUSE_STATE, 7
	clearflag FLAG_ETERNA_CITY_EAST_OF_POKEMON_CENTER_HOUSE_OLD_MAN_4
	closemessage
	releaseall
	end

EternaCity_EastOfPokemonCenterHouse_EventScript_NPC1_2_12::
	@ TODO(DP): StoreUndTime 32780
	goto_if_lt VAR_RESULT, NO, EternaCity_EastOfPokemonCenterHouse_EventScript_NPC1_2_30
	call_if_set FLAG_ETERNA_CITY_EAST_OF_POKEMON_CENTER_HOUSE_OLD_MAN_4, EternaCity_EastOfPokemonCenterHouse_EventScript_NPC1_2_27
	call_if_unset FLAG_ETERNA_CITY_EAST_OF_POKEMON_CENTER_HOUSE_OLD_MAN_4, EternaCity_EastOfPokemonCenterHouse_EventScript_NPC1_2_32
	setvar VAR_0x8004, 83
	setvar VAR_0x8005, 1
	@ TODO(DP): HasSpaceForDecoration 32772, 32773, 32780
	goto_if_eq VAR_RESULT, YES, EternaCity_EastOfPokemonCenterHouse_EventScript_NPC1_2_29
	@ TODO(DP): Common DP script 2012
	setvar VAR_ETERNA_CITY_EAST_OF_POKEMON_CENTER_HOUSE_STATE, 8
	clearflag FLAG_ETERNA_CITY_EAST_OF_POKEMON_CENTER_HOUSE_OLD_MAN_4
	closemessage
	releaseall
	end

EternaCity_EastOfPokemonCenterHouse_EventScript_NPC1_2_13::
	@ TODO(DP): StoreUndTime 32780
	goto_if_lt VAR_RESULT, NO, EternaCity_EastOfPokemonCenterHouse_EventScript_NPC1_2_30
	call_if_set FLAG_ETERNA_CITY_EAST_OF_POKEMON_CENTER_HOUSE_OLD_MAN_4, EternaCity_EastOfPokemonCenterHouse_EventScript_NPC1_2_27
	call_if_unset FLAG_ETERNA_CITY_EAST_OF_POKEMON_CENTER_HOUSE_OLD_MAN_4, EternaCity_EastOfPokemonCenterHouse_EventScript_NPC1_2_33
	setvar VAR_0x8004, 84
	setvar VAR_0x8005, 1
	@ TODO(DP): HasSpaceForDecoration 32772, 32773, 32780
	goto_if_eq VAR_RESULT, YES, EternaCity_EastOfPokemonCenterHouse_EventScript_NPC1_2_29
	@ TODO(DP): Common DP script 2012
	setvar VAR_ETERNA_CITY_EAST_OF_POKEMON_CENTER_HOUSE_STATE, 9
	clearflag FLAG_ETERNA_CITY_EAST_OF_POKEMON_CENTER_HOUSE_OLD_MAN_4
	closemessage
	releaseall
	end

EternaCity_EastOfPokemonCenterHouse_EventScript_NPC1_2_14::
	setflag FLAG_ETERNA_CITY_EAST_OF_POKEMON_CENTER_HOUSE_OLD_MAN_3
	msgbox EternaCity_EastOfPokemonCenterHouse_Text_NPC1_18, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

EternaCity_EastOfPokemonCenterHouse_EventScript_NPC1_2_15::
	msgbox EternaCity_EastOfPokemonCenterHouse_Text_NPC1_19, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

EternaCity_EastOfPokemonCenterHouse_EventScript_NPC1_2_16::
	setflag FLAG_ETERNA_CITY_EAST_OF_POKEMON_CENTER_HOUSE_OLD_MAN_3
	msgbox EternaCity_EastOfPokemonCenterHouse_Text_NPC1_20, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

EternaCity_EastOfPokemonCenterHouse_EventScript_NPC1_2_17::
	msgbox EternaCity_EastOfPokemonCenterHouse_Text_NPC1_21, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

EternaCity_EastOfPokemonCenterHouse_EventScript_NPC1_2_18::
	setflag FLAG_ETERNA_CITY_EAST_OF_POKEMON_CENTER_HOUSE_OLD_MAN_3
	msgbox EternaCity_EastOfPokemonCenterHouse_Text_NPC1_22, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

EternaCity_EastOfPokemonCenterHouse_EventScript_NPC1_2_19::
	msgbox EternaCity_EastOfPokemonCenterHouse_Text_NPC1_23, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

EternaCity_EastOfPokemonCenterHouse_EventScript_NPC1_2_20::
	setflag FLAG_ETERNA_CITY_EAST_OF_POKEMON_CENTER_HOUSE_OLD_MAN_3
	msgbox EternaCity_EastOfPokemonCenterHouse_Text_NPC1_24, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

EternaCity_EastOfPokemonCenterHouse_EventScript_NPC1_2_21::
	msgbox EternaCity_EastOfPokemonCenterHouse_Text_NPC1_25, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

EternaCity_EastOfPokemonCenterHouse_EventScript_NPC1_2_22::
	setflag FLAG_ETERNA_CITY_EAST_OF_POKEMON_CENTER_HOUSE_OLD_MAN_3
	msgbox EternaCity_EastOfPokemonCenterHouse_Text_NPC1_26, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

EternaCity_EastOfPokemonCenterHouse_EventScript_NPC1_2_23::
	msgbox EternaCity_EastOfPokemonCenterHouse_Text_NPC1_27, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

EternaCity_EastOfPokemonCenterHouse_EventScript_NPC1_2_24::
	copyvar VAR_RESULT, VAR_STARTER_MON
	goto_if_eq VAR_STARTER_MON, STARTER_CHIMCHAR, EternaCity_EastOfPokemonCenterHouse_EventScript_NPC1_2_34
	goto_if_eq VAR_STARTER_MON, STARTER_TURTWIG, EternaCity_EastOfPokemonCenterHouse_EventScript_NPC1_2_35
	goto EternaCity_EastOfPokemonCenterHouse_EventScript_NPC1_2_36

EternaCity_EastOfPokemonCenterHouse_EventScript_NPC1_2_25::
	setflag FLAG_ETERNA_CITY_EAST_OF_POKEMON_CENTER_HOUSE_OLD_MAN_3
	msgbox EternaCity_EastOfPokemonCenterHouse_Text_NPC1_28, MSGBOX_DEFAULT
	call EternaCity_EastOfPokemonCenterHouse_EventScript_NPC1_2_37
	msgbox EternaCity_EastOfPokemonCenterHouse_Text_NPC1_29, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

EternaCity_EastOfPokemonCenterHouse_EventScript_NPC1_2_26::
	msgbox EternaCity_EastOfPokemonCenterHouse_Text_NPC1_30, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

EternaCity_EastOfPokemonCenterHouse_EventScript_NPC1_2_27::
	msgbox EternaCity_EastOfPokemonCenterHouse_Text_NPC1_31, MSGBOX_DEFAULT
	return

EternaCity_EastOfPokemonCenterHouse_EventScript_NPC1_2_28::
	msgbox EternaCity_EastOfPokemonCenterHouse_Text_NPC1_32, MSGBOX_DEFAULT
	return

EternaCity_EastOfPokemonCenterHouse_EventScript_NPC1_2_29::
	setflag FLAG_ETERNA_CITY_EAST_OF_POKEMON_CENTER_HOUSE_OLD_MAN_4
	msgbox EternaCity_EastOfPokemonCenterHouse_Text_NPC1_33, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

EternaCity_EastOfPokemonCenterHouse_EventScript_NPC1_2_30::
	msgbox EternaCity_EastOfPokemonCenterHouse_Text_NPC1_34, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

EternaCity_EastOfPokemonCenterHouse_EventScript_NPC1_2_31::
	msgbox EternaCity_EastOfPokemonCenterHouse_Text_NPC1_35, MSGBOX_DEFAULT
	return

EternaCity_EastOfPokemonCenterHouse_EventScript_NPC1_2_32::
	msgbox EternaCity_EastOfPokemonCenterHouse_Text_NPC1_36, MSGBOX_DEFAULT
	return

EternaCity_EastOfPokemonCenterHouse_EventScript_NPC1_2_33::
	msgbox EternaCity_EastOfPokemonCenterHouse_Text_NPC1_37, MSGBOX_DEFAULT
	return

EternaCity_EastOfPokemonCenterHouse_EventScript_NPC1_2_34::
	setvar VAR_0x8004, 101
	setvar VAR_0x8005, 1
	@ TODO(DP): Common DP script 2046
	return

EternaCity_EastOfPokemonCenterHouse_EventScript_NPC1_2_35::
	setvar VAR_0x8004, 102
	setvar VAR_0x8005, 1
	@ TODO(DP): Common DP script 2046
	return

EternaCity_EastOfPokemonCenterHouse_EventScript_NPC1_2_36::
	setvar VAR_0x8004, 103
	setvar VAR_0x8005, 1
	@ TODO(DP): Common DP script 2046
	return

EternaCity_EastOfPokemonCenterHouse_EventScript_NPC1_2_37::
	getplayerxy VAR_0x8004, VAR_0x8005
	goto_if_eq VAR_0x8004, 5, EternaCity_EastOfPokemonCenterHouse_EventScript_NPC1_2_38
	goto_if_eq VAR_0x8004, 7, EternaCity_EastOfPokemonCenterHouse_EventScript_NPC1_2_39
	goto_if_eq VAR_0x8005, 4, EternaCity_EastOfPokemonCenterHouse_EventScript_NPC1_2_40
	goto EternaCity_EastOfPokemonCenterHouse_EventScript_NPC1_2_41

EternaCity_EastOfPokemonCenterHouse_EventScript_NPC1_2_38::
	applymovement LOCALID_ETERNA_CITY_EAST_OF_POKEMON_CENTER_HOUSE_OLD_MAN, EternaCity_EastOfPokemonCenterHouse_Movement_OldMan
	waitmovement 0
	return

EternaCity_EastOfPokemonCenterHouse_EventScript_NPC1_2_39::
	applymovement LOCALID_ETERNA_CITY_EAST_OF_POKEMON_CENTER_HOUSE_OLD_MAN, EternaCity_EastOfPokemonCenterHouse_Movement_OldMan2
	waitmovement 0
	return

EternaCity_EastOfPokemonCenterHouse_EventScript_NPC1_2_40::
	applymovement LOCALID_ETERNA_CITY_EAST_OF_POKEMON_CENTER_HOUSE_OLD_MAN, EternaCity_EastOfPokemonCenterHouse_Movement_OldMan3
	waitmovement 0
	return

EternaCity_EastOfPokemonCenterHouse_EventScript_NPC1_2_41::
	applymovement LOCALID_ETERNA_CITY_EAST_OF_POKEMON_CENTER_HOUSE_OLD_MAN, EternaCity_EastOfPokemonCenterHouse_Movement_OldMan4
	waitmovement 0
	return

EternaCity_EastOfPokemonCenterHouse_EventScript_Sign1::
	lockall
	msgbox EternaCity_EastOfPokemonCenterHouse_Text_Sign1, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

EternaCity_EastOfPokemonCenterHouse_Movement_OldMan:
	walk_slow_up
	walk_slow_down
	walk_slow_down
	walk_slow_up
	walk_in_place_fast_left
	step_end

EternaCity_EastOfPokemonCenterHouse_Movement_OldMan2:
	walk_slow_up
	walk_slow_down
	walk_slow_down
	walk_slow_up
	walk_in_place_fast_right
	step_end

EternaCity_EastOfPokemonCenterHouse_Movement_OldMan3:
	walk_slow_left
	walk_slow_right
	walk_slow_right
	walk_slow_left
	walk_in_place_fast_up
	step_end

EternaCity_EastOfPokemonCenterHouse_Movement_OldMan4:
	walk_slow_left
	walk_slow_right
	walk_slow_right
	walk_slow_left
	walk_in_place_fast_down
	step_end

EternaCity_EastOfPokemonCenterHouse_Text_NPC2_2:
	.string "The underground tunnels go everywhere!\p"
	.string "Grab your friends and let's play\n"
	.string "together using DS Wireless\l"
	.string "Communications!$"

EternaCity_EastOfPokemonCenterHouse_Text_NPC3:
	.string "Let's dig up some Treasure!\p"
	.string "I'm from {COLOR DYNAMIC_COLOR3}Oreburgh{COLOR DARK_GRAY}. I work at the mining\n"
	.string "museum there.\p"
	.string "I got advice from the Underground Man\n"
	.string "on digging up Treasure and Spheres.\p"
	.string "Before I get digging, let me share his\n"
	.string "advice with you.\p"
	.string "While you're digging, you may uncover\n"
	.string "dark rocks.\p"
	.string "They are very hard! If you keep hitting\n"
	.string "them, the wall will collapse.\p"
	.string "Don't forget that, and you'll be digging\n"
	.string "up Treasure in no time!$"

EternaCity_EastOfPokemonCenterHouse_Text_NPC3_2:
	.string "Oh, you'd like more advice on digging up\n"
	.string "Treasure and Spheres?\p"
	.string "Well, your Explorer Kit contains a\n"
	.string "sledgehammer and a pickax.\p"
	.string "Choose either of these tools and touch\n"
	.string "the lower screen to dig.\p"
	.string "You get to keep the stuff you fully\n"
	.string "uncover before the wall collapses.\p"
	.string "Don't forget, the dark rocks are\n"
	.string "impossible to break.\p"
	.string "If you hit them too often, the wall will\n"
	.string "collapse.\p"
	.string "Don't forget that, and you'll be digging\n"
	.string "up Treasure in no time!$"

EternaCity_EastOfPokemonCenterHouse_Text_NPC1_2:
	.string "I am! I am the first to have gone\n"
	.string "underground and dug some tunnels.\p"
	.string "You can call me the Underground Man.\n"
	.string "Everyone else does.\p"
	.string "I'll make a gift of this to you. You hold\n"
	.string "up your end of the deal and put it to\l"
	.string "good use!$"

EternaCity_EastOfPokemonCenterHouse_Text_NPC1_3:
	.string "My gift to you, the Explorer Kit, will\n"
	.string "instantly take you underground!\p"
	.string "You need only to use it, and you will be\n"
	.string "down in the tunnels!\p"
	.string "The Underground is a different world\n"
	.string "where you can do this, that, and the\l"
	.string "other thing, too!\p"
	.string "Let me mentor you into becoming a\n"
	.string "full-fledged spelunker!\p"
	.string "Will you take on that challenge?$"

EternaCity_EastOfPokemonCenterHouse_Text_NPC1_4:
	.string "You have been outstanding! There\n"
	.string "really is nothing left to teach you.\p"
	.string "From now on, you are the spelunking\n"
	.string "master!$"

EternaCity_EastOfPokemonCenterHouse_Text_NPC1_5:
	.string "Let me mentor you as you become a\n"
	.string "full-fledged spelunker!\p"
	.string "Will you take on that challenge?$"

EternaCity_EastOfPokemonCenterHouse_Text_NPC1_6:
	.string "I had hoped to teach a youngster like\n"
	.string "you about the many charms of the\l"
	.string "underground tunnels...\p"
	.string "But I can't force you to accept my\n"
	.string "proposal if you're not inclined.\p"
	.string "Sigh... I get so lonely sometimes...$"

EternaCity_EastOfPokemonCenterHouse_Text_NPC1_7:
	.string "Hm! I see that you've gone down to the\n"
	.string "underground tunnels!\p"
	.string "Well done! Take these as rewards!$"

EternaCity_EastOfPokemonCenterHouse_Text_NPC1_8:
	.string "Those are called Traps. They're\n"
	.string "triggered when stepped on.\p"
	.string "The Underground is a place where you\n"
	.string "can go with your friends.\p"
	.string "You might try setting those Traps when\n"
	.string "you're down there with others.\p"
	.string "Now, what should I assign you next...$"

EternaCity_EastOfPokemonCenterHouse_Text_NPC1_9:
	.string "Ah! You dug up what I was looking for!\n"
	.string "Good job on finding it!\p"
	.string "Well done, indeed! Take these as your\n"
	.string "reward!$"

EternaCity_EastOfPokemonCenterHouse_Text_NPC1_10:
	.string "Dig in the walls of the underground\n"
	.string "tunnels to unearth hidden stuff.\p"
	.string "Fossils and Stones can be dug up and\n"
	.string "brought out from down under.\p"
	.string "Spheres, which are gems, cannot be\n"
	.string "brought out, but they can be exchanged\l"
	.string "for goods down there.\p"
	.string "Now, what should I assign you next...?$"

EternaCity_EastOfPokemonCenterHouse_Text_NPC1_11:
	.string "Good, good! You've buried your Spheres!\p"
	.string "The next time you go underground, they\n"
	.string "should have grown bigger!\p"
	.string "Just don't forget where you've buried\n"
	.string "your Spheres!\p"
	.string "Anyway, well done! This is your reward!$"

EternaCity_EastOfPokemonCenterHouse_Text_NPC1_12:
	.string "You may have seen them already, but\n"
	.string "there are Sphere collectors.\p"
	.string "They wander about in the underground\n"
	.string "tunnels seeking Spheres.\p"
	.string "They'll happily trade you items for big\n"
	.string "Spheres.\p"
	.string "Now, what shall I assign you next...?$"

EternaCity_EastOfPokemonCenterHouse_Text_NPC1_13:
	.string "Ah, you've made your Secret Base!\n"
	.string "Excellent!\p"
	.string "I thought I might have been asking too\n"
	.string "much of you, but you did it!\p"
	.string "Well done! Take these as your reward!$"

EternaCity_EastOfPokemonCenterHouse_Text_NPC1_14:
	.string "Incidentally, a Digger Drill can be used\n"
	.string "only once.\p"
	.string "If you wish to move your Secret Base,\n"
	.string "you will need to obtain another Digger\l"
	.string "Drill.\p"
	.string "You can trade a Sphere for one\n"
	.string "underground.\p"
	.string "What should I make you do next...$"

EternaCity_EastOfPokemonCenterHouse_Text_NPC1_15:
	.string "Ah! You've even managed to decorate\n"
	.string "your Secret Base!\p"
	.string "I knew I recognized a spelunker in you!\p"
	.string "Don't forget to close the door when\n"
	.string "you're decorating!\p"
	.string "We don't want any visitors getting hurt\n"
	.string "by walking in on you!\p"
	.string "Also, if you want to place goods you've\n"
	.string "received, store them in the PC first.\p"
	.string "Anyways, well done! This is your reward!$"

EternaCity_EastOfPokemonCenterHouse_Text_NPC1_16:
	.string "There are ways of collecting more\n"
	.string "decoration goods.\p"
	.string "You can grow Spheres you've found and\n"
	.string "trade them for goods.\p"
	.string "It's also possible to obtain goods from\n"
	.string "friends.$"

EternaCity_EastOfPokemonCenterHouse_Text_NPC1_17:
	.string "There really is nothing else that I can\n"
	.string "teach you.\p"
	.string "If you wish to put away more Big\n"
	.string "Boulders or put out more goods, keep\l"
	.string "capturing more Flags.\p"
	.string "Become the spelunking master for me!$"

EternaCity_EastOfPokemonCenterHouse_Text_NPC1_18:
	.string "Hm! Well said, my young friend!\p"
	.string "I will teach you by assigning missions.\n"
	.string "First, go underground!\p"
	.string "Going underground is quite easy. Simply\n"
	.string "use your Explorer Kit.\p"
	.string "If you accomplish that, I will give you\n"
	.string "your next test.$"

EternaCity_EastOfPokemonCenterHouse_Text_NPC1_19:
	.string "You've not gone underground yet?\p"
	.string "To get down to the underground\n"
	.string "tunnels, you need only to use your\l"
	.string "Explorer Kit.\p"
	.string "But you need to be outside. It can't be\n"
	.string "used indoors or in a cave.\p"
	.string "Now, off you go!$"

EternaCity_EastOfPokemonCenterHouse_Text_NPC1_20:
	.string "How was it in the underground tunnels?\p"
	.string "Big and empty, I would think.\p"
	.string "But that's only because you are a\n"
	.string "novice spelunker!\p"
	.string "There are many hidden things down\n"
	.string "there that are not visible to the eye.\p"
	.string "For my next test, I want you to dig up\n"
	.string "some Treasure or Spheres for me.\p"
	.string "While underground, check the Radar for\n"
	.string "yellow spots.\p"
	.string "Go to such a location and search for\n"
	.string "Treasure using the Touch Screen.$"

EternaCity_EastOfPokemonCenterHouse_Text_NPC1_21:
	.string "You've not located any Treasure or\n"
	.string "Spheres yet?\p"
	.string "Listen. Check the Radar and go to any\n"
	.string "yellow spot that's shown.\p"
	.string "Next, use the Touch Screen to identify\n"
	.string "places to dig.\p"
	.string "Try to get right on top of a yellow spot\n"
	.string "on the Radar, OK?\p"
	.string "Once you are right in front of it, press\n"
	.string "the A Button!\p"
	.string "Now, off you go on your search!$"

EternaCity_EastOfPokemonCenterHouse_Text_NPC1_22:
	.string "My tests aren't over yet! Next, let's\n"
	.string "use some Spheres!\p"
	.string "The Spheres one can find underground\n"
	.string "are very peculiar.\p"
	.string "When buried in the ground, they grow\n"
	.string "daily, a little bit at a time.\p"
	.string "I want you to go bury these strange\n"
	.string "Spheres in the underground tunnels.\p"
	.string "That is my latest test!$"

EternaCity_EastOfPokemonCenterHouse_Text_NPC1_23:
	.string "You've not buried the Spheres yet?\n"
	.string "You're afraid of losing them?\p"
	.string "Have no fear! Spheres are easily buried\n"
	.string "and just as easily dug up.\p"
	.string "Don't be afraid. Go bury those Spheres\n"
	.string "like I've said.\p"
	.string "Just don't forget where you've buried\n"
	.string "them--the Underground is huge!$"

EternaCity_EastOfPokemonCenterHouse_Text_NPC1_24:
	.string "Have you grown weary of repeatedly\n"
	.string "going back to the Underground?\p"
	.string "Well, it's not over yet! Next up is your\n"
	.string "Secret Base!\p"
	.string "That's right, I will teach you how to\n"
	.string "make your own Secret Base!\p"
	.string "All you need is the Digger Drill I gave\n"
	.string "you earlier.\p"
	.string "Simply go underground and use the\n"
	.string "Digger Drill wherever you like.\p"
	.string "That will instantly make you your very\n"
	.string "own Secret Base!\p"
	.string "So, your next assignment is: go make\n"
	.string "your own Secret Base!$"

EternaCity_EastOfPokemonCenterHouse_Text_NPC1_25:
	.string "Hm? You don't know how to use the\n"
	.string "Digger Drill?\p"
	.string "OK, I'll admit this test may have been a\n"
	.string "little tricky for you.\p"
	.string "All you need to do is find the Digger\n"
	.string "Drill among your Traps.\p"
	.string "Then, face a wall and use the Digger\n"
	.string "Drill. That's all it takes.\p"
	.string "Do that and you'll have your Secret\n"
	.string "Base before you can say...\p"
	.string "Boo!\p"
	.string "No, seriously though!$"

EternaCity_EastOfPokemonCenterHouse_Text_NPC1_26:
	.string "Hm! You've stuck it out to the end! This\n"
	.string "is my final test.\p"
	.string "You've made yourself a Secret Base, but\n"
	.string "it's totally empty, is it not?\p"
	.string "Not to worry! You can decorate your own\n"
	.string "Secret Base as you see fit!\p"
	.string "So! For my final test, I want you to\n"
	.string "decorate your Secret Base.\p"
	.string "Use furniture and interior goods to\n"
	.string "give your Secret Base character!$"

EternaCity_EastOfPokemonCenterHouse_Text_NPC1_27:
	.string "Ah, have I finally managed to stump\n"
	.string "you?\p"
	.string "Perhaps you've left your Secret Base's\n"
	.string "door open?\p"
	.string "You see, the underground tunnels are\n"
	.string "visited by many Trainers.\p"
	.string "It wouldn't do to have someone barge in\n"
	.string "on you while you're working on your\l"
	.string "Secret Base.\p"
	.string "Don't forget to close the door while\n"
	.string "you're redecorating!$"

EternaCity_EastOfPokemonCenterHouse_Text_NPC1_28:
	.string "I've taught you all I know, but if you\n"
	.string "insist, there is one more thing I should\l"
	.string "tell you.\p"
	.string "The Secret Base you've made has Big\n"
	.string "Boulders that get in the way, yes?\p"
	.string "There is actually a way of moving those\n"
	.string "boulders aside...\p"
	.string "However, the task may be dangerous for\n"
	.string "you now.\p"
	.string "I suppose I could tell you how when you\n"
	.string "get better as a spelunker...$"

EternaCity_EastOfPokemonCenterHouse_Text_NPC1_29:
	.string "...Hm! However, you are someone I'd\n"
	.string "recognized as a born spelunker...\p"
	.string "Fine! I will tell you, but only because\n"
	.string "you're exceptional!\p"
	.string "You know that you may go underground\n"
	.string "with your friends, correct?\p"
	.string "That means your friends are certain to\n"
	.string "have Secret Bases of their own.\p"
	.string "Now, this is what you must do: First,\n"
	.string "find a friend's Secret Base.\p"
	.string "Next, go to the PC and steal your\n"
	.string "friend's Flag.\p"
	.string "Then, run back to your Secret Base and\n"
	.string "take the Flag to your PC!\p"
	.string "If you can do that, I will permit you to\n"
	.string "move boulders.$"

EternaCity_EastOfPokemonCenterHouse_Text_NPC1_30:
	.string "Ah! My spelunker! Are you spelunking\n"
	.string "with your friends?\p"
	.string "It's a hundred times more fun to play\n"
	.string "with friends underground!\p"
	.string "If you manage to steal a Flag from a\n"
	.string "friend's Secret Base, you be sure to\l"
	.string "come show me!$"

EternaCity_EastOfPokemonCenterHouse_Text_NPC1_31:
	.string "Hm! This belongs to you!$"

EternaCity_EastOfPokemonCenterHouse_Text_NPC1_32:
	.string "Wait! Don't tell me! You've captured a\n"
	.string "Flag?\p"
	.string "Excellent! You should already be\n"
	.string "capable of moving Big Boulders inside\l"
	.string "your Secret Base!\p"
	.string "You can shunt aside a boulder by\n"
	.string "storing it like furniture.\p"
	.string "Anyways, well done! This is your reward!$"

EternaCity_EastOfPokemonCenterHouse_Text_NPC1_33:
	.string "Oh? Your underground PC appears to be\n"
	.string "full.\p"
	.string "Discard a decorative item or two, then\n"
	.string "come see me again.$"

EternaCity_EastOfPokemonCenterHouse_Text_NPC1_34:
	.string "So, my spelunker, are you going\n"
	.string "underground with your friends?\p"
	.string "The underground tunnels are vast. They\n"
	.string "can be a place where you meet many\l"
	.string "others like you.$"

EternaCity_EastOfPokemonCenterHouse_Text_NPC1_35:
	.string "Ah, you've captured three Flags!\p"
	.string "Well done! Take this as your reward!$"

EternaCity_EastOfPokemonCenterHouse_Text_NPC1_36:
	.string "Ah, you've captured ten Flags!\p"
	.string "Well done! Take this as your reward!$"

EternaCity_EastOfPokemonCenterHouse_Text_NPC1_37:
	.string "Oh! Oh! My goodness! You've captured\n"
	.string "fifty Flags!\p"
	.string "Fantastic! Take this as your reward!$"

EternaCity_EastOfPokemonCenterHouse_Text_Sign1:
	.string "New and on sale! Underground Radar!\p"
	.string "The upper radar screen indicates\n"
	.string "possible Treasure locations.\p"
	.string "The lower Touch Radar indicates precise\n"
	.string "locations!$"
