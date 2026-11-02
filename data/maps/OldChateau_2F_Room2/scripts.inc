OldChateau_2F_Room2_MapScripts::
	.byte 0

OldChateau_2F_Room2_EventScript_Sign1::
	lockall
	goto_if_set FLAG_OLD_CHATEAU_2F_ROOM2_SIGN_1, OldChateau_2F_Room2_EventScript_Sign1_2
	@ TODO(DP): goto if DP system flag 2736 is set
	goto_if_unset FLAG_SYS_GAME_CLEAR, OldChateau_2F_Room2_EventScript_Sign1_2
	@ TODO(DP): NationalDex 2, 32780
	goto_if_unset FLAG_SYS_GAME_CLEAR, OldChateau_2F_Room2_EventScript_Sign1_2
	gettimeofday
	goto_if_lt VAR_RESULT, TIME_NIGHT, OldChateau_2F_Room2_EventScript_Sign1_2
	msgbox OldChateau_2F_Room2_Text_Sign1, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, OldChateau_2F_Room2_EventScript_Sign1_2_2
	msgbox OldChateau_2F_Room2_Text_Sign1_2, MSGBOX_DEFAULT
	closemessage
	playmoncry SPECIES_ROTOM, CRY_MODE_NORMAL
	waitmoncry
	@ TODO(DP): Set DP system flag 2736
	setwildbattle SPECIES_ROTOM, 15
	dowildbattle
	@ TODO(DP): CheckWildBattle2 32780
	goto OldChateau_2F_Room2_EventScript_Sign1_2_4
	setflag FLAG_OLD_CHATEAU_2F_ROOM2_SIGN_1
	releaseall
	end

OldChateau_2F_Room2_EventScript_Sign1_2::
	msgbox OldChateau_2F_Room2_Text_Sign1_3, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

OldChateau_2F_Room2_EventScript_Sign1_2_2::
	closemessage
	releaseall
	end

OldChateau_2F_Room2_EventScript_Sign1_2_3::
	releaseall
	end

OldChateau_2F_Room2_EventScript_Sign1_2_4::
	msgbox OldChateau_2F_Room2_Text_Sign1_4, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

OldChateau_2F_Room2_EventScript_Sign2::
	goto OldChateau_2F_Room2_EventScript_Sign1
	end

OldChateau_2F_Room2_Text_Sign1:
	.string "Inside the TV... There appears to be a\n"
	.string "Pokémon?...\p"
	.string "The Pokémon appears as if it will come\n"
	.string "out. Want to thump the TV?$"

OldChateau_2F_Room2_Text_Sign1_2:
	.string "{PLAYER} thumped the TV set!$"

OldChateau_2F_Room2_Text_Sign1_3:
	.string "The TV has an oddly malevolent feel...\n"
	.string "It's as if it is staring...$"

OldChateau_2F_Room2_Text_Sign1_4:
	.string "Rotom disappeared into the TV set...$"
