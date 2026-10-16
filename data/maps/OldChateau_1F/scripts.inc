OldChateau_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, OldChateau_1F_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, OldChateau_1F_OnFrame
	.byte 0

OldChateau_1F_OnTransition::
	@ TODO(DP): Unk0292 10, 16384
	goto_if_eq VAR_TEMP_0, 1, OldChateau_1F_OnTransition_2
	setflag FLAG_HIDE_OLD_CHATEAU_1F_OLD_MAN
	end

OldChateau_1F_OnTransition_2::
	clearflag FLAG_HIDE_OLD_CHATEAU_1F_OLD_MAN
	setvar VAR_OLD_CHATEAU_1F_STATE, 1
	end

OldChateau_1F_EventScript_OnFrame::
	lockall
	applymovement LOCALID_PLAYER, OldChateau_1F_Movement_Player
	applymovement LOCALID_OLD_CHATEAU_1_F_OLD_MAN, OldChateau_1F_Movement_OldMan
	waitmovement 0
	setflag FLAG_HIDE_OLD_CHATEAU_1F_OLD_MAN
	removeobject LOCALID_OLD_CHATEAU_1_F_OLD_MAN
	setvar VAR_OLD_CHATEAU_1F_STATE, 0
	releaseall
	end

OldChateau_1F_OnFrame:
	map_script_2 VAR_OLD_CHATEAU_1F_STATE, 1, OldChateau_1F_EventScript_OnFrame
	.2byte 0

OldChateau_1F_Movement_Player:
	walk_up
	delay_16
	delay_16
	delay_16
	delay_16
	face_left
	step_end

OldChateau_1F_Movement_OldMan:
	delay_16
	face_left
	delay_16
	delay_16
	disable_anim
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	restore_anim
	set_invisible
	step_end
