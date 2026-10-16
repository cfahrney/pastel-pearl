CanalaveCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CanalaveCity_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, CanalaveCity_OnLoad
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CanalaveCity_OnFrame
	.byte 0

CanalaveCity_EventScript_NPC5::
	lock
	faceplayer
	goto_if_set FLAG_CANALAVE_CITY_FAT_MAN_1, CanalaveCity_EventScript_NPC5_2
	message CanalaveCity_Text_NPC5_2
	waitmessage
	goto CanalaveCity_EventScript_NPC5_2_2

CanalaveCity_EventScript_NPC5_2::
	message CanalaveCity_Text_NPC5_3
	waitmessage
	goto CanalaveCity_EventScript_NPC5_2_2

CanalaveCity_EventScript_NPC5_2_2::
	waitbuttonpress
	closemessage
	release
	end

CanalaveCity_EventScript_NPC2::
	lock
	faceplayer
	goto_if_set FLAG_CANALAVE_CITY_FAT_MAN_1, CanalaveCity_EventScript_NPC2_2
	message CanalaveCity_Text_NPC2_2
	waitmessage
	goto CanalaveCity_EventScript_NPC5_2_2

CanalaveCity_EventScript_NPC2_2::
	message CanalaveCity_Text_NPC2_3
	waitmessage
	goto CanalaveCity_EventScript_NPC5_2_2

CanalaveCity_EventScript_NPC4::
	lock
	faceplayer
	goto_if_set FLAG_CANALAVE_CITY_FAT_MAN_1, CanalaveCity_EventScript_NPC4_2
	message CanalaveCity_Text_NPC4_2
	waitmessage
	goto CanalaveCity_EventScript_NPC5_2_2

CanalaveCity_EventScript_NPC4_2::
	message CanalaveCity_Text_NPC4_3
	waitmessage
	goto CanalaveCity_EventScript_NPC5_2_2

CanalaveCity_EventScript_NPC7::
	lock
	faceplayer
	goto_if_set FLAG_CANALAVE_CITY_FAT_MAN_1, CanalaveCity_EventScript_NPC7_2
	message CanalaveCity_Text_NPC7
	waitmessage
	goto CanalaveCity_EventScript_NPC5_2_2

CanalaveCity_EventScript_NPC7_2::
	message CanalaveCity_Text_NPC7_2
	waitmessage
	goto CanalaveCity_EventScript_NPC5_2_2

CanalaveCity_EventScript_Sign4::
	msgbox CanalaveCity_Text_Sign4, MSGBOX_SIGN
	end

CanalaveCity_EventScript_Sign5::
	msgbox CanalaveCity_Text_Sign5, MSGBOX_SIGN
	end

CanalaveCity_EventScript_Sign2::
	msgbox CanalaveCity_Text_Sign2_2, MSGBOX_SIGN
	end

CanalaveCity_EventScript_Sign3::
	msgbox CanalaveCity_Text_Sign3_2, MSGBOX_SIGN
	end

CanalaveCity_EventScript_Sign6::
	msgbox CanalaveCity_Text_Sign6, MSGBOX_SIGN
	end

CanalaveCity_EventScript_NPC1::
	lock
	faceplayer
	goto_if_set FLAG_CANALAVE_CITY_FAT_MAN_1, CanalaveCity_EventScript_NPC1_2
	playmoncry SPECIES_PSYDUCK, CRY_MODE_NORMAL
	setspeaker CanalaveCity_Text_PsyduckSpeaker
	message CanalaveCity_Text_NPC1_2
	waitmessage
	goto CanalaveCity_EventScript_NPC5_2_2

CanalaveCity_EventScript_NPC1_2::
	playmoncry SPECIES_PSYDUCK, CRY_MODE_NORMAL
	setspeaker CanalaveCity_Text_PsyduckSpeaker
	message CanalaveCity_Text_NPC1_3
	waitmessage
	goto CanalaveCity_EventScript_NPC5_2_2

CanalaveCity_EventScript_NPC3::
	lock
	faceplayer
	goto_if_set FLAG_CANALAVE_CITY_FAT_MAN_1, CanalaveCity_EventScript_NPC3_2
	message CanalaveCity_Text_NPC3_2
	waitmessage
	goto CanalaveCity_EventScript_NPC5_2_2

CanalaveCity_EventScript_NPC3_2::
	message CanalaveCity_Text_NPC3_3
	waitmessage
	goto CanalaveCity_EventScript_NPC5_2_2

CanalaveCity_EventScript_NPC8::
	lock
	faceplayer
	msgbox CanalaveCity_Text_NPC8, MSGBOX_DEFAULT
	waitbuttonpress
	closemessage
	release
	end

CanalaveCity_EventScript_NPC9::
	lock
	faceplayer
	checkplayergender
	goto_if_eq VAR_RESULT, 0, CanalaveCity_EventScript_NPC9_2
	goto CanalaveCity_EventScript_NPC9_2_2

CanalaveCity_EventScript_NPC9_2::
	setspeaker SP_NAME_ASSISTANT
	message CanalaveCity_Text_NPC9
	waitmessage
	goto CanalaveCity_EventScript_NPC9_2_3

CanalaveCity_EventScript_NPC9_2_2::
	setspeaker SP_NAME_ASSISTANT
	message CanalaveCity_Text_NPC9_2
	waitmessage
	goto CanalaveCity_EventScript_NPC9_2_3

CanalaveCity_EventScript_NPC9_2_3::
	waitbuttonpress
	closemessage
	release
	end

CanalaveCity_EventScript_NPC10::
	lock
	faceplayer
	setspeaker SP_NAME_ROWAN
	msgbox CanalaveCity_Text_NPC10, MSGBOX_DEFAULT
	closemessage
	release
	end

CanalaveCity_EventScript_NPC6::
	lockall
	faceplayer
	copyvar VAR_0x8004, VAR_FACING
	faceplayer
	goto_if_eq VAR_CANALAVE_CITY_STATE, 2, CanalaveCity_EventScript_NPC6_2
	message CanalaveCity_Text_NPC6_2
	waitmessage
	@ TODO(DP): Multi 1, 1, 0, 1, 32780
	@ TODO(DP): Unk0042 213, 0
	call_if_set FLAG_CANALAVE_CITY_SAILOR_1, CanalaveCity_EventScript_NPC6_2_2
	call_if_set FLAG_CANALAVE_CITY_SAILOR_2, CanalaveCity_EventScript_NPC6_2_3
	@ TODO(DP): Unk0042 218, 4
	@ TODO(DP): CloseMulti
	goto_if_eq VAR_RESULT, 0, CanalaveCity_EventScript_NPC6_2_4
	goto_if_eq VAR_RESULT, 1, CanalaveCity_EventScript_NPC6_2_5
	goto_if_eq VAR_RESULT, 2, CanalaveCity_EventScript_NPC6_2_6
	goto_if_eq VAR_RESULT, 3, CanalaveCity_EventScript_NPC6_2_7
	goto CanalaveCity_EventScript_NPC6_2_7

CanalaveCity_EventScript_NPC6_2::
	checkitem ITEM_NONE @ TODO(DP): ITEM_LUNAR_WING, 1
	goto_if_eq VAR_RESULT, TRUE, CanalaveCity_EventScript_NPC6_2_8
	msgbox CanalaveCity_Text_NPC6_3, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, CanalaveCity_EventScript_NPC6_2_9
	goto_if_eq VAR_RESULT, NO, CanalaveCity_EventScript_NPC6_2_10
	end

CanalaveCity_EventScript_NPC6_2_2::
	@ TODO(DP): Unk0042 214, 1
	return

CanalaveCity_EventScript_NPC6_2_3::
	@ TODO(DP): Unk0042 215, 2
	return

CanalaveCity_EventScript_NPC6_2_4::
	call CanalaveCity_EventScript_NPC6_2_11
	call_if_eq VAR_0x8004, DIR_SOUTH, CanalaveCity_EventScript_NPC6_2_12
	call_if_eq VAR_0x8004, DIR_EAST, CanalaveCity_EventScript_NPC6_2_13
	call_if_eq VAR_0x8004, DIR_NORTH, CanalaveCity_EventScript_NPC6_2_14
	@ TODO(DP): ShipAnimation 3, 3, 288, 100, 502
	releaseall
	end

CanalaveCity_EventScript_NPC6_2_5::
	call CanalaveCity_EventScript_NPC6_2_11
	call_if_eq VAR_0x8004, DIR_SOUTH, CanalaveCity_EventScript_NPC6_2_12
	call_if_eq VAR_0x8004, DIR_EAST, CanalaveCity_EventScript_NPC6_2_13
	call_if_eq VAR_0x8004, DIR_NORTH, CanalaveCity_EventScript_NPC6_2_14
	@ TODO(DP): ShipAnimation 3, 2, 260, 39, 277
	releaseall
	end

CanalaveCity_EventScript_NPC6_2_6::
	call CanalaveCity_EventScript_NPC6_2_11
	call_if_eq VAR_0x8004, DIR_SOUTH, CanalaveCity_EventScript_NPC6_2_12
	call_if_eq VAR_0x8004, DIR_EAST, CanalaveCity_EventScript_NPC6_2_13
	call_if_eq VAR_0x8004, DIR_NORTH, CanalaveCity_EventScript_NPC6_2_14
	@ TODO(DP): ShipAnimation 3, 3, 320, 152, 277
	releaseall
	end

CanalaveCity_EventScript_NPC6_2_7::
	msgbox CanalaveCity_Text_NPC6_4, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

CanalaveCity_EventScript_NPC6_2_8::
	msgbox CanalaveCity_Text_NPC6_5, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

CanalaveCity_EventScript_NPC6_2_9::
	msgbox CanalaveCity_Text_NPC6_6, MSGBOX_DEFAULT
	closemessage
	goto CanalaveCity_EventScript_NPC6_2_5

CanalaveCity_EventScript_NPC6_2_10::
	msgbox CanalaveCity_Text_NPC6_7, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

CanalaveCity_EventScript_NPC6_2_11::
	msgbox CanalaveCity_Text_NPC6_8, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CANALAVE_CITY_SAILOR_2, CanalaveCity_Movement_Sailor2
	waitmovement 0
	playse SE_EXIT
	applymovement LOCALID_CANALAVE_CITY_SAILOR_2, CanalaveCity_Movement_Sailor22
	waitmovement 0
	return

CanalaveCity_EventScript_NPC6_2_12::
	applymovement LOCALID_PLAYER, CanalaveCity_Movement_Player
	waitmovement 0
	playse SE_EXIT
	applymovement LOCALID_PLAYER, CanalaveCity_Movement_Player2
	waitmovement 0
	return

CanalaveCity_EventScript_NPC6_2_13::
	applymovement LOCALID_PLAYER, CanalaveCity_Movement_Player3
	waitmovement 0
	playse SE_EXIT
	applymovement LOCALID_PLAYER, CanalaveCity_Movement_Player2
	waitmovement 0
	return

CanalaveCity_EventScript_NPC6_2_14::
	applymovement LOCALID_PLAYER, CanalaveCity_Movement_Player4
	waitmovement 0
	playse SE_EXIT
	applymovement LOCALID_PLAYER, CanalaveCity_Movement_Player2
	waitmovement 0
	return

CanalaveCity_EventScript_Sign1::
	call CanalaveCity_EventScript_Sign1_2
	goto_if_eq VAR_TEMP_0, 0, CanalaveCity_EventScript_Sign1_2_2
	msgbox CanalaveCity_Text_Sign1_2, MSGBOX_SIGN
	end

CanalaveCity_EventScript_Sign1_2::
	goto_if_set FLAG_CANALAVE_CITY_SIGN_1, CanalaveCity_EventScript_Sign1_2_3
	@ TODO(DP): goto if DP system flag 2404 is clear
	@ TODO(DP): NationalDex 2, 16384
	goto_if_eq VAR_TEMP_0, 0, CanalaveCity_EventScript_Sign1_2_3
	checkitem ITEM_NONE @ TODO(DP): ITEM_MEMBER_CARD, 1
	copyvar VAR_TEMP_0, VAR_RESULT
	goto_if_eq VAR_TEMP_0, FALSE, CanalaveCity_EventScript_Sign1_2_3
	@ TODO(DP): CheckEventValidity 0, 16384
	goto_if_eq VAR_TEMP_0, FALSE, CanalaveCity_EventScript_Sign1_2_3
	goto_if_unset FLAG_CANALAVE_CITY_SIGN_2, CanalaveCity_EventScript_Sign1_2_3
	setvar VAR_TEMP_0, 1
	return

CanalaveCity_EventScript_Sign1_2_2::
	msgbox CanalaveCity_Text_Sign1_3, MSGBOX_SIGN
	end

CanalaveCity_EventScript_Sign1_2_3::
	setvar VAR_TEMP_0, 0
	return

CanalaveCity_EventScript_Sign7::
	lockall
	msgbox CanalaveCity_Text_Sign7, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

CanalaveCity_EventScript_Trigger1::
	lockall
	getplayerxy VAR_0x8004, VAR_0x8005
	goto_if_eq VAR_0x8005, 12, CanalaveCity_EventScript_Trigger1_2
	goto_if_eq VAR_0x8005, 13, CanalaveCity_EventScript_Trigger1_2_2
	goto_if_eq VAR_0x8005, 14, CanalaveCity_EventScript_Trigger1_2_3
	goto_if_eq VAR_0x8005, 15, CanalaveCity_EventScript_Trigger1_2_4
	goto_if_eq VAR_0x8005, 16, CanalaveCity_EventScript_Trigger1_2_5
	end

CanalaveCity_EventScript_Trigger1_2::
	setobjectxyperm LOCALID_CANALAVE_CITY_BARRY, 6, 12
	goto CanalaveCity_EventScript_Trigger1_2_6

CanalaveCity_EventScript_Trigger1_2_2::
	setobjectxyperm LOCALID_CANALAVE_CITY_BARRY, 6, 13
	goto CanalaveCity_EventScript_Trigger1_2_6

CanalaveCity_EventScript_Trigger1_2_3::
	setobjectxyperm LOCALID_CANALAVE_CITY_BARRY, 6, 14
	goto CanalaveCity_EventScript_Trigger1_2_6

CanalaveCity_EventScript_Trigger1_2_4::
	setobjectxyperm LOCALID_CANALAVE_CITY_BARRY, 6, 15
	goto CanalaveCity_EventScript_Trigger1_2_6

CanalaveCity_EventScript_Trigger1_2_5::
	setobjectxyperm LOCALID_CANALAVE_CITY_BARRY, 6, 16
	goto CanalaveCity_EventScript_Trigger1_2_6

CanalaveCity_EventScript_Trigger1_2_6::
	setobjectmovementtype LOCALID_CANALAVE_CITY_BARRY, MOVEMENT_TYPE_FACE_RIGHT
	clearflag FLAG_HIDE_CANALAVE_CITY_BARRY
	clearflag FLAG_HIDE_CANALAVE_CITY_BARRY
	addobject LOCALID_CANALAVE_CITY_BARRY
	playbgm MUS_RIVAL_THEME, FALSE
	applymovement LOCALID_CANALAVE_CITY_BARRY, CanalaveCity_Movement_Barry
	waitmovement 0
	setspeaker SP_NAME_RIVAL
	msgbox CanalaveCity_Text_Trigger1, MSGBOX_DEFAULT
	closemessage
	copyvar VAR_RESULT, VAR_STARTER_MON
	goto_if_eq VAR_STARTER_MON, STARTER_TURTWIG, CanalaveCity_EventScript_Trigger1_2_7
	goto_if_eq VAR_STARTER_MON, STARTER_CHIMCHAR, CanalaveCity_EventScript_Trigger1_2_8
	goto CanalaveCity_EventScript_Trigger1_2_9

CanalaveCity_EventScript_Trigger1_2_7::
	@ TODO(DP): Scripted battle against DP trainer #477 (Pokémon Trainer Barry Cedric)
	goto CanalaveCity_EventScript_Trigger1_2_10

CanalaveCity_EventScript_Trigger1_2_8::
	@ TODO(DP): Scripted battle against DP trainer #478 (Pokémon Trainer Barry Cedric)
	goto CanalaveCity_EventScript_Trigger1_2_10

CanalaveCity_EventScript_Trigger1_2_9::
	@ TODO(DP): Scripted battle against DP trainer #476 (Pokémon Trainer Barry Cedric)
	goto CanalaveCity_EventScript_Trigger1_2_10

CanalaveCity_EventScript_Trigger1_2_10::
	setspeaker SP_NAME_RIVAL
	msgbox CanalaveCity_Text_Trigger1_2, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CANALAVE_CITY_BARRY, CanalaveCity_Movement_Barry2
	waitmovement 0
	removeobject LOCALID_CANALAVE_CITY_BARRY
	setvar VAR_CANALAVE_CITY_STATE_2, 1
	releaseall
	end

CanalaveCity_EventScript_Trigger1_2_11::
	setflag FLAG_HIDE_CANALAVE_CITY_BARRY
	releaseall
	end

CanalaveCity_OnTransition::
	call Common_EventScript_SetupLucasDawnAssistantGfxId
	call_if_eq VAR_CANALAVE_CITY_STATE_3, 2, CanalaveCity_OnTransition_2
	call_if_eq VAR_CANALAVE_CITY_STATE_3, 3, CanalaveCity_OnTransition_2_2
	call CanalaveCity_EventScript_Sign1_2
	call_if_eq VAR_TEMP_0, 0, CanalaveCity_OnTransition_2_3
	call_if_eq VAR_TEMP_0, 1, CanalaveCity_OnTransition_2_4
	call_if_eq VAR_CANALAVE_CITY_STATE_2, 1, CanalaveCity_OnTransition_2_5
	call_if_eq VAR_CANALAVE_CITY_STATE_2, 2, CanalaveCity_OnTransition_2_5
	call_if_eq VAR_CANALAVE_CITY_STATE_2, 4, CanalaveCity_OnTransition_2_6
	call_if_eq VAR_CANALAVE_CITY_STATE_2, 5, CanalaveCity_OnTransition_2_7
	checkplayergender
	copyvar VAR_TEMP_0, VAR_RESULT
	goto_if_eq VAR_TEMP_0, 0, CanalaveCity_OnTransition_2_8
	goto_if_eq VAR_TEMP_0, 1, CanalaveCity_OnTransition_2_9
	end

CanalaveCity_OnTransition_2::
	setvar VAR_CANALAVE_CITY_STATE_3, 0
	return

CanalaveCity_OnTransition_2_2::
	setobjectxyperm LOCALID_CANALAVE_CITY_SAILOR_2, 23, 5
	setobjectmovementtype LOCALID_CANALAVE_CITY_SAILOR_2, MOVEMENT_TYPE_FACE_RIGHT
	setobjectmovementtype LOCALID_CANALAVE_CITY_SAILOR_2, MOVEMENT_TYPE_FACE_RIGHT
	return

CanalaveCity_OnTransition_2_3::
	@ TODO(DP): SetBgEventPosition 0, 58, 713
	@ TODO(DP): SetWarpPosition 5, 59, 712
	return

CanalaveCity_OnTransition_2_4::
	clearflag FLAG_CANALAVE_CITY_EVENT_1
	return

CanalaveCity_OnTransition_2_5::
	setobjectxyperm LOCALID_CANALAVE_CITY_BARRY, 7, 22
	setobjectmovementtype LOCALID_CANALAVE_CITY_BARRY, MOVEMENT_TYPE_FACE_UP
	setobjectmovementtype LOCALID_CANALAVE_CITY_BARRY, MOVEMENT_TYPE_FACE_UP
	return

CanalaveCity_OnTransition_2_6::
	setobjectxyperm LOCALID_CANALAVE_CITY_BARRY, 5, 10
	setobjectmovementtype LOCALID_CANALAVE_CITY_BARRY, MOVEMENT_TYPE_FACE_DOWN
	setobjectmovementtype LOCALID_CANALAVE_CITY_BARRY, MOVEMENT_TYPE_FACE_DOWN
	return

CanalaveCity_OnTransition_2_7::
	setflag FLAG_HIDE_CANALAVE_CITY_PROF_ROWAN
	setflag FLAG_HIDE_CANALAVE_CITY_NPC
	setvar VAR_CANALAVE_CITY_STATE_2, 6
	return

CanalaveCity_OnTransition_2_8::
	setvar VAR_CANALAVE_CITY_STATE_4, 97
	end

CanalaveCity_OnTransition_2_9::
	setvar VAR_CANALAVE_CITY_STATE_4, 0
	end

CanalaveCity_OnLoad::
	call CanalaveCity_EventScript_Sign1_2
	call_if_eq VAR_TEMP_0, 0, CanalaveCity_OnTransition_2_3
	end

CanalaveCity_EventScript_OnFrame1::
	lockall
	setspeaker SP_NAME_RIVAL
	msgbox CanalaveCity_Text_OnFrame1, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CANALAVE_CITY_BARRY, CanalaveCity_Movement_Barry3
	applymovement LOCALID_PLAYER, CanalaveCity_Movement_Player5
	waitmovement 0
	removeobject LOCALID_CANALAVE_CITY_BARRY
	setvar VAR_CANALAVE_CITY_STATE_2, 3
	setvar VAR_CANALAVE_CITY_STATE_5, 1
	releaseall
	end

CanalaveCity_EventScript_OnFrame2::
	lockall
	applymovement LOCALID_CANALAVE_CITY_PROF_ROWAN, CanalaveCity_Movement_ProfRowan
	waitmovement 0
	setspeaker SP_NAME_ROWAN
	msgbox CanalaveCity_Text_OnFrame2, MSGBOX_DEFAULT
	closemessage
	clearflag FLAG_HIDE_CANALAVE_CITY_SAILOR
	clearflag FLAG_HIDE_CANALAVE_CITY_SAILOR
	addobject LOCALID_CANALAVE_CITY_SAILOR
	lock
	applymovement LOCALID_CANALAVE_CITY_SAILOR, CanalaveCity_Movement_Sailor
	waitmovement 0
	msgbox CanalaveCity_Text_OnFrame2_2, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CANALAVE_CITY_SAILOR, CanalaveCity_Movement_Sailor3
	waitmovement 0
	removeobject LOCALID_CANALAVE_CITY_SAILOR
	applymovement LOCALID_CANALAVE_CITY_BARRY, CanalaveCity_Movement_Barry4
	waitmovement 0
	setspeaker SP_NAME_RIVAL
	msgbox CanalaveCity_Text_OnFrame2_3, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CANALAVE_CITY_BARRY, CanalaveCity_Movement_Barry5
	waitmovement 0
	removeobject LOCALID_CANALAVE_CITY_BARRY
	applymovement LOCALID_CANALAVE_CITY_PROF_ROWAN, CanalaveCity_Movement_ProfRowan2
	waitmovement 0
	setspeaker SP_NAME_ROWAN
	msgbox CanalaveCity_Text_OnFrame2_4, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CANALAVE_CITY_NPC, CanalaveCity_Movement_Npc
	waitmovement 0
	delay 30
	checkplayergender
	goto_if_eq VAR_RESULT, 0, CanalaveCity_EventScript_OnFrame2_2
	goto CanalaveCity_EventScript_OnFrame2_2_2

CanalaveCity_EventScript_OnFrame2_2::
	setspeaker SP_NAME_ASSISTANT
	message CanalaveCity_Text_OnFrame2_5
	waitmessage
	goto CanalaveCity_EventScript_OnFrame2_2_3

CanalaveCity_EventScript_OnFrame2_2_2::
	setspeaker SP_NAME_ASSISTANT
	message CanalaveCity_Text_OnFrame2_6
	waitmessage
	goto CanalaveCity_EventScript_OnFrame2_2_3

CanalaveCity_EventScript_OnFrame2_2_3::
	waitbuttonpress
	closemessage
	setvar VAR_CANALAVE_CITY_STATE_2, 5
	clearflag FLAG_CANALAVE_CITY_EVENT_2
	clearflag FLAG_CANALAVE_CITY_EVENT_3
	clearflag FLAG_CANALAVE_CITY_EVENT_4
	releaseall
	end

CanalaveCity_EventScript_OnFrame3::
	lockall
	playse SE_PIN
	applymovement LOCALID_CANALAVE_CITY_SAILOR_2, CanalaveCity_Movement_Sailor23
	waitmovement 0
	msgbox CanalaveCity_Text_OnFrame3, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CANALAVE_CITY_SAILOR_2, CanalaveCity_Movement_Sailor24
	waitmovement 0
	removeobject LOCALID_CANALAVE_CITY_SAILOR_2
	setobjectxyperm LOCALID_CANALAVE_CITY_SAILOR_2, 13, 39
	setobjectmovementtype LOCALID_CANALAVE_CITY_SAILOR_2, MOVEMENT_TYPE_FACE_LEFT
	setobjectmovementtype LOCALID_CANALAVE_CITY_SAILOR_2, MOVEMENT_TYPE_FACE_LEFT
	addobject LOCALID_CANALAVE_CITY_SAILOR_2
	setvar VAR_CANALAVE_CITY_STATE_3, 4
	releaseall
	end

CanalaveCity_OnFrame:
	map_script_2 VAR_CANALAVE_CITY_STATE_2, 2, CanalaveCity_EventScript_OnFrame1
	map_script_2 VAR_CANALAVE_CITY_STATE_2, 4, CanalaveCity_EventScript_OnFrame2
	map_script_2 VAR_CANALAVE_CITY_STATE_3, 3, CanalaveCity_EventScript_OnFrame3
	.2byte 0

CanalaveCity_Movement_Sailor2:
	face_right
	delay_16
	delay_16
	step_end

CanalaveCity_Movement_Sailor22:
	set_invisible
	step_end

CanalaveCity_Movement_Player:
	walk_down
	face_right
	delay_16
	delay_16
	step_end

CanalaveCity_Movement_Player2:
	set_invisible
	step_end

CanalaveCity_Movement_Player3:
	walk_right
	delay_16
	delay_16
	step_end

CanalaveCity_Movement_Player4:
	walk_up
	face_right
	delay_16
	delay_16
	step_end

CanalaveCity_Movement_Barry:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

CanalaveCity_Movement_Barry2:
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

CanalaveCity_Movement_Barry3:
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

CanalaveCity_Movement_Player5:
	delay_16
	walk_in_place_left
	step_end

CanalaveCity_Movement_ProfRowan:
	walk_in_place_down
	step_end

CanalaveCity_Movement_Sailor:
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_up
	walk_fast_up
	step_end

CanalaveCity_Movement_Sailor3:
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

CanalaveCity_Movement_Barry4:
	walk_in_place_up
	step_end

CanalaveCity_Movement_Barry5:
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

CanalaveCity_Movement_ProfRowan2:
	delay_16
	delay_16
	walk_in_place_up
	step_end

CanalaveCity_Movement_Npc:
	walk_in_place_left
	step_end

CanalaveCity_Movement_Sailor23:
	emote_exclamation_mark
	walk_right
	walk_right
	walk_right
	walk_up
	step_end

CanalaveCity_Movement_Sailor24:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

CanalaveCity_Text_NPC5_2:
	.string "What's up? Your clothes look damp.\p"
	.string "Were you swimming at the beach right by\n"
	.string "{COLOR DYNAMIC_COLOR3}Sandgem Town{COLOR DARK_GRAY}?$"

CanalaveCity_Text_NPC5_3:
	.string "The tremor earlier... It didn't feel like\n"
	.string "an earthquake.\p"
	.string "It felt more like an explosion.$"

CanalaveCity_Text_NPC2_2:
	.string "My Psyduck is very close to me. It can\n"
	.string "use the move Return!$"

CanalaveCity_Text_NPC2_3:
	.string "E-even Ps-Psyduck's Future Sight\n"
	.string "couldn't foretell that tremor!$"

CanalaveCity_Text_NPC4_2:
	.string "Welcome to Canalave City, the Canal\n"
	.string "City!\p"
	.string "In the old days, this port used to be a\n"
	.string "hub of cargo transportation.$"

CanalaveCity_Text_NPC4_3:
	.string "What was that tremor? I thought Mt.\n"
	.string "Coronet erupted!$"

CanalaveCity_Text_NPC7:
	.string "I'm going to study at the library. I love\n"
	.string "reading.\p"
	.string "I love how reading takes me to places\n"
	.string "far away in time and space.$"

CanalaveCity_Text_NPC7_2:
	.string "An explosion at Lake Valor? But there\n"
	.string "isn't anything there?$"

CanalaveCity_Text_Sign4:
	.string "Canalave Library$"

CanalaveCity_Text_Sign5:
	.string "Canalave City Pokémon Gym Leader:\n"
	.string "Byron The Man with the Steel Body!$"

CanalaveCity_Text_Sign2_2:
	.string "Canalave Dock$"

CanalaveCity_Text_Sign3_2:
	.string "Canalave City\n"
	.string "Cargo Port$"

CanalaveCity_Text_Sign6:
	.string "Sailor Eldritch's House$"

CanalaveCity_Text_NPC1_2:
	.string "Gua?$"

CanalaveCity_Text_NPC1_3:
	.string "Gua! Gua! Gwa? Guaa! Guuagwa?!$"

CanalaveCity_Text_NPC3_2:
	.string "The Gym Leader and Trainers of this Gym\n"
	.string "often go out to Iron Island.\p"
	.string "They not only train their Pokémon, but\n"
	.string "they work out as well.$"

CanalaveCity_Text_NPC3_3:
	.string "I'm flabbergasted!$"

CanalaveCity_Text_NPC8:
	.string "{STR_VAR_1}: Yeah, yeah, you're just a\n"
	.string "bit better than me, as usual.\p"
	.string "But listen up!\p"
	.string "Let me tell you who's going to take on\n"
	.string "the Pokémon League and become the\l"
	.string "Champion.\p"
	.string "You guessed right! It's going to be me!\p"
	.string "Anyways, you should be able to take the\n"
	.string "Gym Leader here.\p"
	.string "Hurry up and go make the challenge!$"

CanalaveCity_Text_NPC9:
	.string "We're going off to {COLOR DYNAMIC_COLOR3}Lake Verity{COLOR DARK_GRAY} first...\p"
	.string "Don't do anything rash if something\n"
	.string "does happen.$"

CanalaveCity_Text_NPC9_2:
	.string "We're going to investigate {COLOR DYNAMIC_COLOR3}Lake Verity{COLOR DARK_GRAY}\n"
	.string "before we join you.\p"
	.string "Don't try to be a hero if anything crazy\n"
	.string "happens.$"

CanalaveCity_Text_NPC10:
	.string "Hmm...\p"
	.string "What is taking place at Lake Valor... You\n"
	.string "must find out!\p"
	.string "But before you go, let me stress: don't\n"
	.string "get in over your head.\p"
	.string "We will try to join you as soon as we\n"
	.string "inspect {COLOR DYNAMIC_COLOR3}Lake Verity{COLOR DARK_GRAY}.$"

CanalaveCity_Text_NPC6_2:
	.string "Do you wanna set sail?$"

CanalaveCity_Text_NPC6_3:
	.string "I've lost my love of sailing since my son\n"
	.string "fell into that horrid nightmare...\p"
	.string "I need the Lunar Wing from Fullmoon\n"
	.string "Island to awaken him!\p"
	.string "Would you go to Fullmoon Island for me?\n"
	.string "If not for me, then for my son?$"

CanalaveCity_Text_NPC6_4:
	.string "You just tell me whenever you need to\n"
	.string "set sail!$"

CanalaveCity_Text_NPC6_5:
	.string "That Lunar Wing... Please! Take it to my\n"
	.string "son...$"

CanalaveCity_Text_NPC6_6:
	.string "We're both counting on you!\p"
	.string "Only you can awaken my son from his\n"
	.string "awful nightmare...\p"
	.string "Please, I need the Lunar Wing from\n"
	.string "Fullmoon Island to awaken him!$"

CanalaveCity_Text_NPC6_7:
	.string "Do you need to get ready?\p"
	.string "I'll be waiting here. We're desperate for\n"
	.string "your help.$"

CanalaveCity_Text_NPC6_8:
	.string "Anchors aweigh!$"

CanalaveCity_Text_Sign1_2:
	.string "Harbor Inn A Roost for Restless Sailors\n"
	.string "“Enjoy sweet dreams in our sumptuous\l"
	.string "beds!”$"

CanalaveCity_Text_Sign1_3:
	.string "Harbor Inn...\n"
	.string "The text is too faded to read.$"

CanalaveCity_Text_Sign7:
	.string "The door is tightly shut. It appears\n"
	.string "impossible to open.$"

CanalaveCity_Text_Trigger1:
	.string "Whoops! Hey, {PLAYER}!\p"
	.string "You're going to challenge the Gym\n"
	.string "Leader up past here, eh?\p"
	.string "Someone should check to see if you're\n"
	.string "ready for this challenge!\p"
	.string "That someone is me! With my brand-new\n"
	.string "Gym Badge!$"

CanalaveCity_Text_Trigger1_2:
	.string "Yeah, yeah, you're just a bit better\n"
	.string "than me, as usual.\p"
	.string "But listen up!\p"
	.string "Let me tell you who's going to take on\n"
	.string "the Pokémon League and become the\l"
	.string "Champion.\p"
	.string "You guessed right! It's going to be me!\p"
	.string "Anyways, you should be able to take the\n"
	.string "Gym Leader here.\p"
	.string "Hurry up and go make the challenge!$"

CanalaveCity_Text_OnFrame1:
	.string "Hey! That's the Mine Badge! Good going!\p"
	.string "You're tough enough to consider\n"
	.string "becoming the Pokémon Champ.\p"
	.string "Of course, I'm tougher, so it's not going\n"
	.string "to actually happen.\p"
	.string "Anyways, {PLAYER}, come with me to the\n"
	.string "library.$"

CanalaveCity_Text_OnFrame2:
	.string "!\p"
	.string "...That tremor... That wasn't a natural\n"
	.string "occurrence.$"

CanalaveCity_Text_OnFrame2_2:
	.string "Hey, hey! Old dude and kids! Something\n"
	.string "big just happened!\p"
	.string "They're saying there was a huge\n"
	.string "explosion at Lake Valor!\p"
	.string "Ka-boom!!\p"
	.string "Like that!$"

CanalaveCity_Text_OnFrame2_3:
	.string "Gramps!\p"
	.string "I'm going to the lake! I have a bad\n"
	.string "feeling about this!$"

CanalaveCity_Text_OnFrame2_4:
	.string "!\p"
	.string "...That {RIVAL}... Can't sit still...\p"
	.string "{PLAYER}, I'm worried about Lake Valor.\p"
	.string "But I have no idea what is taking place.\n"
	.string "You must find out!\p"
	.string "But before you go, let me stress: don't\n"
	.string "get in over your head.\p"
	.string "We will try to join you as soon as we\n"
	.string "inspect {COLOR DYNAMIC_COLOR3}Lake Verity{COLOR DARK_GRAY}.$"

CanalaveCity_Text_OnFrame2_5:
	.string "...{PLAYER}, you'll be OK, won't you?$"

CanalaveCity_Text_OnFrame2_6:
	.string "Lake Valor... I wonder what happened?$"

CanalaveCity_Text_OnFrame3:
	.string "You've been asleep for a long, long\n"
	.string "time... What happened to you?\p"
	.string "And what were you doing here? No one's\n"
	.string "lived here for fifty years.$"

CanalaveCity_Text_PsyduckSpeaker:
	.string "Psyduck$"
