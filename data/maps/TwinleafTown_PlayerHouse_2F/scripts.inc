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

@ The clock runs from new game (new_game.c), so it only shows the time.
TwinleafTown_PlayerHouse_2F_EventScript_Clock::
	lockall
	incrementgamestat GAME_STAT_CHECKED_CLOCK
	fadescreen FADE_TO_BLACK
	special Special_ViewWallClock
	releaseall
	end
