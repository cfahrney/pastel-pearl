OldChateau_Entrance_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, OldChateau_Entrance_OnTransition
	.byte 0

OldChateau_Entrance_EventScript_Sign1::
	lockall
	msgbox OldChateau_Entrance_Text_Sign1, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

OldChateau_Entrance_OnTransition::
	@ DP: set system flag 2524 (not needed here)
	end

OldChateau_Entrance_Text_Sign1:
	.string "...It appears as if it is glaring...$"
