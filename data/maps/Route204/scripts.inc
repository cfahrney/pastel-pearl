Route204_MapScripts::
	.byte 0

Route204_EventScript_Trainer1::
	trainerbattle_single TRAINER_ROUTE204_1, Route204_Text_Trainer1Intro, Route204_Text_Trainer1Defeated
	msgbox Route204_Text_Trainer1PostBattle, MSGBOX_AUTOCLOSE
	end

Route204_EventScript_Trainer2::
	trainerbattle_single TRAINER_ROUTE204_2, Route204_Text_Trainer2Intro, Route204_Text_Trainer2Defeated
	msgbox Route204_Text_Trainer2PostBattle, MSGBOX_AUTOCLOSE
	end

Route204_Text_Trainer1Intro:
	.string "ROUTE 204 TRAINER 1\n"
	.string "wants to battle!$"

Route204_Text_Trainer1Defeated:
	.string "ROUTE 204 TRAINER 1\n"
	.string "was defeated!$"

Route204_Text_Trainer1PostBattle:
	.string "ROUTE 204 TRAINER 1\n"
	.string "has nothing else to say.$"

Route204_Text_Trainer2Intro:
	.string "ROUTE 204 TRAINER 2\n"
	.string "wants to battle!$"

Route204_Text_Trainer2Defeated:
	.string "ROUTE 204 TRAINER 2\n"
	.string "was defeated!$"

Route204_Text_Trainer2PostBattle:
	.string "ROUTE 204 TRAINER 2\n"
	.string "has nothing else to say.$"

Route204_EventScript_Tree1::
	lockall
	checkfieldmove FIELD_MOVE_CUT, TRUE
	goto_if_eq VAR_RESULT, PARTY_SIZE, EventScript_CheckTreeCantCut
	setfieldeffectargument 0, VAR_RESULT
	bufferpartymonnick STR_VAR_1, VAR_RESULT
	buffermovename STR_VAR_2, MOVE_CUT
	msgbox Text_WantToCut, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_CancelCut
	msgbox Text_MonUsedFieldMove, MSGBOX_DEFAULT
	closemessage
	isfollowerfieldmoveuser VAR_0x8004
	setfieldeffectargument 3, VAR_0x8004
	dofieldeffect FLDEFF_USE_CUT_ON_TREE
	waitstate
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	call_if_eq VAR_0x8004, TRUE, EventScript_FollowerFieldMove
	applymovement VAR_LAST_TALKED, Movement_CutTreeDown
	waitmovement 0
	removeobject VAR_LAST_TALKED
	setflag FLAG_HIDE_ROUTE204_TREE1
	releaseall
	end

Route204_EventScript_Trainer3::
	trainerbattle_single TRAINER_ROUTE204_3, Route204_Text_Trainer3Intro, Route204_Text_Trainer3Defeated
	msgbox Route204_Text_Trainer3PostBattle, MSGBOX_AUTOCLOSE
	end

Route204_EventScript_Trainer4::
	trainerbattle_single TRAINER_ROUTE204_4, Route204_Text_Trainer4Intro, Route204_Text_Trainer4Defeated
	msgbox Route204_Text_Trainer4PostBattle, MSGBOX_AUTOCLOSE
	end

Route204_EventScript_Trainer5::
	trainerbattle_single TRAINER_ROUTE204_5, Route204_Text_Trainer5Intro, Route204_Text_Trainer5Defeated
	msgbox Route204_Text_Trainer5PostBattle, MSGBOX_AUTOCLOSE
	end

Route204_Text_Trainer3Intro:
	.string "ROUTE 204 TRAINER 3\n"
	.string "wants to battle!$"

Route204_Text_Trainer3Defeated:
	.string "ROUTE 204 TRAINER 3\n"
	.string "was defeated!$"

Route204_Text_Trainer3PostBattle:
	.string "ROUTE 204 TRAINER 3\n"
	.string "has nothing else to say.$"

Route204_Text_Trainer4Intro:
	.string "ROUTE 204 TRAINER 4\n"
	.string "wants to battle!$"

Route204_Text_Trainer4Defeated:
	.string "ROUTE 204 TRAINER 4\n"
	.string "was defeated!$"

Route204_Text_Trainer4PostBattle:
	.string "ROUTE 204 TRAINER 4\n"
	.string "has nothing else to say.$"

Route204_Text_Trainer5Intro:
	.string "ROUTE 204 TRAINER 5\n"
	.string "wants to battle!$"

Route204_Text_Trainer5Defeated:
	.string "ROUTE 204 TRAINER 5\n"
	.string "was defeated!$"

Route204_Text_Trainer5PostBattle:
	.string "ROUTE 204 TRAINER 5\n"
	.string "has nothing else to say.$"
