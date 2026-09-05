TwinleafTown_PlayerHouse_2F_MapScripts::
	.byte 0

@ Same PC boot-up sequence as LittlerootTown_BrendansHouse_2F_EventScript_PC,
@ minus the gender/rival's-PC branch — Twinleaf has one shared player house,
@ so this is always the player's own PC.
TwinleafTown_PlayerHouse_2F_EventScript_PC::
	lockall
	setvar VAR_0x8004, PC_LOCATION_OTHER
	special DoPCTurnOnEffect
	playse SE_PC_ON
	msgbox gText_PlayerHouseBootPC, MSGBOX_DEFAULT
	special BedroomPC
	releaseall
	end

@ Same wall clock flow as PlayersHouse_2F_EventScript_WallClock in
@ data/scripts/players_house.inc, minus the gender-specific MOM greeting
@ (already handled by her running-shoes scene downstairs).
TwinleafTown_PlayerHouse_2F_EventScript_Clock::
	lockall
	goto_if_set FLAG_SET_WALL_CLOCK, TwinleafTown_PlayerHouse_2F_EventScript_ViewClock
	msgbox TwinleafTown_PlayerHouse_2F_Text_ClockIsStopped, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	special StartWallClock
	delay 30
	setflag FLAG_SET_WALL_CLOCK
	releaseall
	end

TwinleafTown_PlayerHouse_2F_EventScript_ViewClock::
	incrementgamestat GAME_STAT_CHECKED_CLOCK
	fadescreen FADE_TO_BLACK
	special Special_ViewWallClock
	releaseall
	end

TwinleafTown_PlayerHouse_2F_Text_ClockIsStopped:
	.string "The clock is stopped…\p"
	.string "Better set it and start it!$"

@ Gated on FLAG_SET_WALL_CLOCK both at the coord_event (map.json) and
@ here, so this keeps firing every time the player heads for the stairs
@ until they've actually set the clock.
TwinleafTown_PlayerHouse_2F_EventScript_SetTheClock::
	goto_if_set FLAG_SET_WALL_CLOCK, TwinleafTown_PlayerHouse_2F_EventScript_SetTheClockDone
	lockall
	msgbox TwinleafTown_PlayerHouse_2F_Text_BeforeIGoSetClock, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, TwinleafTown_PlayerHouse_2F_Movement_StepBackFromStairs
	waitmovement 0
	releaseall
TwinleafTown_PlayerHouse_2F_EventScript_SetTheClockDone:
	end

TwinleafTown_PlayerHouse_2F_Movement_StepBackFromStairs:
	walk_left
	walk_left
	face_up
	step_end

TwinleafTown_PlayerHouse_2F_Text_BeforeIGoSetClock:
	.string "Before I go, I should set the\n"
	.string "clock.$"
