Route202_MapScripts::
	.byte 0

Route202_EventScript_Sign1::
	msgbox Route202_Text_Sign1, MSGBOX_SIGN
	end

Route202_EventScript_Sign2::
	msgbox Route202_Text_Sign2, MSGBOX_SIGN
	end

Route202_EventScript_Sign3::
	msgbox Route202_Text_Sign3, MSGBOX_SIGN
	end

Route202_Text_Sign1:
	.string "ROUTE 202 SIGN 1$"

Route202_Text_Sign2:
	.string "ROUTE 202 SIGN 2$"

Route202_Text_Sign3:
	.string "ROUTE 202 SIGN 3$"

Route202_EventScript_Trainer1::
	trainerbattle_single TRAINER_ROUTE202_1, Route202_Text_Trainer1Intro, Route202_Text_Trainer1Defeated
	msgbox Route202_Text_Trainer1PostBattle, MSGBOX_AUTOCLOSE
	end

Route202_EventScript_Trainer2::
	trainerbattle_single TRAINER_ROUTE202_2, Route202_Text_Trainer2Intro, Route202_Text_Trainer2Defeated
	msgbox Route202_Text_Trainer2PostBattle, MSGBOX_AUTOCLOSE
	end

Route202_EventScript_Trainer3::
	trainerbattle_single TRAINER_ROUTE202_3, Route202_Text_Trainer3Intro, Route202_Text_Trainer3Defeated
	msgbox Route202_Text_Trainer3PostBattle, MSGBOX_AUTOCLOSE
	end

Route202_EventScript_Trainer4::
	trainerbattle_single TRAINER_ROUTE202_4, Route202_Text_Trainer4Intro, Route202_Text_Trainer4Defeated
	msgbox Route202_Text_Trainer4PostBattle, MSGBOX_AUTOCLOSE
	end

Route202_Text_Trainer1Intro:
	.string "ROUTE 202 TRAINER 1\n"
	.string "wants to battle!$"

Route202_Text_Trainer1Defeated:
	.string "ROUTE 202 TRAINER 1\n"
	.string "was defeated!$"

Route202_Text_Trainer1PostBattle:
	.string "ROUTE 202 TRAINER 1\n"
	.string "has nothing else to say.$"

Route202_Text_Trainer2Intro:
	.string "ROUTE 202 TRAINER 2\n"
	.string "wants to battle!$"

Route202_Text_Trainer2Defeated:
	.string "ROUTE 202 TRAINER 2\n"
	.string "was defeated!$"

Route202_Text_Trainer2PostBattle:
	.string "ROUTE 202 TRAINER 2\n"
	.string "has nothing else to say.$"

Route202_Text_Trainer3Intro:
	.string "ROUTE 202 TRAINER 3\n"
	.string "wants to battle!$"

Route202_Text_Trainer3Defeated:
	.string "ROUTE 202 TRAINER 3\n"
	.string "was defeated!$"

Route202_Text_Trainer3PostBattle:
	.string "ROUTE 202 TRAINER 3\n"
	.string "has nothing else to say.$"

Route202_Text_Trainer4Intro:
	.string "ROUTE 202 TRAINER 4\n"
	.string "wants to battle!$"

Route202_Text_Trainer4Defeated:
	.string "ROUTE 202 TRAINER 4\n"
	.string "was defeated!$"

Route202_Text_Trainer4PostBattle:
	.string "ROUTE 202 TRAINER 4\n"
	.string "has nothing else to say.$"
