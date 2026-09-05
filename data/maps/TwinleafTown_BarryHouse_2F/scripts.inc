TwinleafTown_BarryHouse_2F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, TwinleafTown_BarryHouse_2F_OnFrame
	.byte 0

@ VAR_TWINLEAF_TOWN_STATE == 1: fires automatically the moment the player
@ walks in (no trigger tile needed) since Barry is already in the room.
TwinleafTown_BarryHouse_2F_OnFrame:
	map_script_2 VAR_TWINLEAF_TOWN_STATE, 1, TwinleafTown_BarryHouse_2F_EventScript_BarryNoticesPlayer
	.2byte 0

TwinleafTown_BarryHouse_2F_EventScript_BarryNoticesPlayer::
	lockall
	applymovement LOCALID_PLAYER, Common_Movement_FaceRight
	waitmovement 0
	msgbox TwinleafTown_BarryHouse_2F_Text_BagAndJournal, MSGBOX_DEFAULT
	closemessage
	playse SE_PIN
	applymovement LOCALID_TWINLEAF_BARRYHOUSE_BARRY, TwinleafTown_BarryHouse_2F_Movement_BarryNotices
	waitmovement 0
	applymovement LOCALID_TWINLEAF_BARRYHOUSE_BARRY, Common_Movement_Delay48
	waitmovement 0
	playbgm MUS_RIVAL_THEME, TRUE
	msgbox TwinleafTown_BarryHouse_2F_Text_GoingToTheLake, MSGBOX_DEFAULT
	closemessage
	@ Player steps out of Barry's path before he starts running, so his
	@ forced movement never has to cross through the tile the player is on.
	applymovement LOCALID_PLAYER, TwinleafTown_BarryHouse_2F_Movement_PlayerStepAside
	waitmovement 0
	applymovement LOCALID_TWINLEAF_BARRYHOUSE_BARRY, TwinleafTown_BarryHouse_2F_Movement_BarryLeaveDownStairs
	waitmovement 0
	removeobject LOCALID_TWINLEAF_BARRYHOUSE_BARRY
	savebgm MUS_DUMMY
	fadedefaultbgm
	setflag FLAG_HIDE_TWINLEAF_TOWN_BARRYHOUSE_BARRY
	setvar VAR_TWINLEAF_TOWN_STATE, 2
	releaseall
	end

TwinleafTown_BarryHouse_2F_Text_BagAndJournal:
	.string "I'd better take my Bag and\n"
	.string "Journal, too…$"

TwinleafTown_BarryHouse_2F_Text_GoingToTheLake:
	.string "Oh, hey, {PLAYER}!\p"
	.string "We're going to the lake! I'll be\n"
	.string "waiting on the road! It's 10 million\l"
	.string "bucks if you're late!$"

TwinleafTown_BarryHouse_2F_Movement_BarryNotices:
	face_left
	emote_exclamation_mark
	step_end

TwinleafTown_BarryHouse_2F_Movement_PlayerStepAside:
	walk_left
	face_right
	step_end

TwinleafTown_BarryHouse_2F_Movement_BarryLeaveDownStairs:
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_up
	step_end
