ValleyWindworks_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, ValleyWindworks_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, ValleyWindworks_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, ValleyWindworks_OnResume
	.byte 0

ValleyWindworks_EventScript_NPC1::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_DRIFLOON, CRY_MODE_NORMAL
	setspeaker ValleyWindworks_Text_NPC1Speaker
	msgbox ValleyWindworks_Text_NPC1, MSGBOX_DEFAULT
	waitmoncry
	release
	end

ValleyWindworks_Text_NPC1:
	.string "Floooooon!$"

ValleyWindworks_Text_NPC1Speaker:
	.string "Drifloon$"

ValleyWindworks_EventScript_Sign1::
	msgbox ValleyWindworks_Text_Sign1, MSGBOX_SIGN
	end

ValleyWindworks_Text_Sign1:
	.string "Valley Windworks Ecological,\n"
	.string "Wind-Driven Energy$"

ValleyWindworks_EventScript_NPC2::
	lockall
	faceplayer
	msgbox ValleyWindworks_Text_NPC2, MSGBOX_DEFAULT
	closemessage
	@ TODO(DP): Scripted battle against DP trainer #843 (Galactic Grunt)
	goto_if_eq VAR_RESULT, 0, ValleyWindworks_EventScript_NPC2_2
	msgbox ValleyWindworks_Text_NPC2_2, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_VALLEY_WINDWORKS_GALACTIC_GRUNT, ValleyWindworks_Movement_GalacticGrunt
	waitmovement 0
	opendoor 19, 11
	waitdooranim
	applymovement LOCALID_VALLEY_WINDWORKS_GALACTIC_GRUNT, ValleyWindworks_Movement_GalacticGrunt2
	waitmovement 0
	closedoor 19, 11
	waitdooranim
	msgbox ValleyWindworks_Text_NPC2_3, MSGBOX_DEFAULT
	removeobject LOCALID_VALLEY_WINDWORKS_GALACTIC_GRUNT
	closemessage
	releaseall
	end

ValleyWindworks_EventScript_NPC2_2::
	releaseall
	end

ValleyWindworks_EventScript_Sign2::
	lockall
	goto_if_set FLAG_FLOAROMA_MEADOW_TRIGGER_2, ValleyWindworks_EventScript_Sign2_2
	msgbox ValleyWindworks_Text_Sign2, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

ValleyWindworks_EventScript_Sign2_2::
	bufferitemname STR_VAR_1, ITEM_WORKS_KEY
	msgbox ValleyWindworks_Text_Sign2_2, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, ValleyWindworks_EventScript_Sign2_2_2
	setflag FLAG_VALLEY_WINDWORKS_SIGN_1
	call ValleyWindworks_EventScript_Sign2_2_3
	@ TODO(DP): SetWarpPosition 0, 243, 654
	msgbox ValleyWindworks_Text_Sign2_3, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

ValleyWindworks_EventScript_Sign2_2_2::
	closemessage
	releaseall
	end

ValleyWindworks_EventScript_Sign2_2_3::
	@ TODO(DP): SetBgEventPosition 1, 243, 650
	return

ValleyWindworks_OnLoad::
	call_if_set FLAG_VALLEY_WINDWORKS_SIGN_1, ValleyWindworks_EventScript_Sign2_2_3
	call_if_unset FLAG_VALLEY_WINDWORKS_SIGN_1, ValleyWindworks_OnLoad_2
	goto_if_set FLAG_VALLEY_WINDWORKS_EVENT_1, ValleyWindworks_OnLoad_2_2
	end

ValleyWindworks_OnLoad_2::
	@ TODO(DP): SetWarpPosition 0, 243, 650
	return

ValleyWindworks_OnLoad_2_2::
	setflag FLAG_HIDE_VALLEY_WINDWORKS_NPC
	removeobject LOCALID_VALLEY_WINDWORKS_NPC
	clearflag FLAG_VALLEY_WINDWORKS_EVENT_1
	end

ValleyWindworks_OnTransition::
	call_if_eq VAR_VALLEY_WINDWORKS_STATE, 2, ValleyWindworks_OnTransition_2
	call_if_set FLAG_VALLEY_WINDWORKS_SIGN_1, ValleyWindworks_EventScript_Sign2_2_3
	call_if_unset FLAG_VALLEY_WINDWORKS_SIGN_1, ValleyWindworks_OnLoad_2
	goto_if_lt VAR_ROUTE205_STATE, 2, ValleyWindworks_OnTransition_2_2
	@ TODO(DP): goto if DP system flag 2728 is set
	@ TODO(DP): GetDayOfWeek 16384
	goto_if_ne VAR_TEMP_0, 5, ValleyWindworks_OnTransition_2_2
	goto ValleyWindworks_OnTransition_2_3

ValleyWindworks_OnTransition_2::
	setvar VAR_VALLEY_WINDWORKS_STATE, 3
	return

ValleyWindworks_OnTransition_2_2::
	setflag FLAG_HIDE_VALLEY_WINDWORKS_NPC
	end

ValleyWindworks_OnTransition_2_3::
	clearflag FLAG_HIDE_VALLEY_WINDWORKS_NPC
	end

ValleyWindworks_OnResume::
	end

ValleyWindworks_Movement_GalacticGrunt:
	walk_in_place_up
	step_end

ValleyWindworks_Movement_GalacticGrunt2:
	walk_up
	set_invisible
	step_end

ValleyWindworks_Text_NPC2:
	.string "Don't you dare go into the Valley\n"
	.string "Windworks.\p"
	.string "I got ordered to keep everyone out if\n"
	.string "they're not part of Team Galactic.\p"
	.string "You're giving me a look that makes me\n"
	.string "think you're gonna try to get in.\p"
	.string "OK, then. You'll have to battle me for it!$"

ValleyWindworks_Text_NPC2_2:
	.string "Isn't that just great. Getting owned by\n"
	.string "some kid.\p"
	.string "But you can't do a thing if I lock myself\n"
	.string "in with my Works Key!\p"
	.string "That's right, the other Works Key's not\n"
	.string "here!\p"
	.string "My cohorts in the flower patch have the\n"
	.string "only other one!\p"
	.string "Hahaha! In that sense, I'm no longer the\n"
	.string "loser!$"

ValleyWindworks_Text_NPC2_3:
	.string "Ker-chunk!$"

ValleyWindworks_Text_Sign2:
	.string "It's locked from inside!$"

ValleyWindworks_Text_Sign2_2:
	.string "It's locked from inside!\p"
	.string "Use the Works Key?$"

ValleyWindworks_Text_Sign2_3:
	.string "Ker-chunk!\p"
	.string "The door to Valley Windworks opened!$"
