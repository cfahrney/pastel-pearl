Route207_MapScripts::
	.byte 0

Route207_EventScript_Trainer1::
	trainerbattle_single TRAINER_ROUTE207_1, Route207_Text_Trainer1Intro, Route207_Text_Trainer1Defeated
	msgbox Route207_Text_Trainer1PostBattle, MSGBOX_AUTOCLOSE
	end

Route207_EventScript_Trainer2::
	trainerbattle_single TRAINER_ROUTE207_2, Route207_Text_Trainer2Intro, Route207_Text_Trainer2Defeated
	msgbox Route207_Text_Trainer2PostBattle, MSGBOX_AUTOCLOSE
	end

Route207_EventScript_Trainer3::
	trainerbattle_single TRAINER_ROUTE207_3, Route207_Text_Trainer3Intro, Route207_Text_Trainer3Defeated
	msgbox Route207_Text_Trainer3PostBattle, MSGBOX_AUTOCLOSE
	end

Route207_EventScript_Trainer4::
	trainerbattle_single TRAINER_ROUTE207_4, Route207_Text_Trainer4Intro, Route207_Text_Trainer4Defeated
	msgbox Route207_Text_Trainer4PostBattle, MSGBOX_AUTOCLOSE
	end

Route207_EventScript_Trainer5::
	trainerbattle_single TRAINER_ROUTE207_5, Route207_Text_Trainer5Intro, Route207_Text_Trainer5Defeated
	msgbox Route207_Text_Trainer5PostBattle, MSGBOX_AUTOCLOSE
	end

Route207_Text_Trainer1Intro:
	.string "ROUTE 207 TRAINER 1\n"
	.string "wants to battle!$"

Route207_Text_Trainer1Defeated:
	.string "ROUTE 207 TRAINER 1\n"
	.string "was defeated!$"

Route207_Text_Trainer1PostBattle:
	.string "ROUTE 207 TRAINER 1\n"
	.string "has nothing else to say.$"

Route207_Text_Trainer2Intro:
	.string "ROUTE 207 TRAINER 2\n"
	.string "wants to battle!$"

Route207_Text_Trainer2Defeated:
	.string "ROUTE 207 TRAINER 2\n"
	.string "was defeated!$"

Route207_Text_Trainer2PostBattle:
	.string "ROUTE 207 TRAINER 2\n"
	.string "has nothing else to say.$"

Route207_Text_Trainer3Intro:
	.string "ROUTE 207 TRAINER 3\n"
	.string "wants to battle!$"

Route207_Text_Trainer3Defeated:
	.string "ROUTE 207 TRAINER 3\n"
	.string "was defeated!$"

Route207_Text_Trainer3PostBattle:
	.string "ROUTE 207 TRAINER 3\n"
	.string "has nothing else to say.$"

Route207_Text_Trainer4Intro:
	.string "ROUTE 207 TRAINER 4\n"
	.string "wants to battle!$"

Route207_Text_Trainer4Defeated:
	.string "ROUTE 207 TRAINER 4\n"
	.string "was defeated!$"

Route207_Text_Trainer4PostBattle:
	.string "ROUTE 207 TRAINER 4\n"
	.string "has nothing else to say.$"

Route207_Text_Trainer5Intro:
	.string "ROUTE 207 TRAINER 5\n"
	.string "wants to battle!$"

Route207_Text_Trainer5Defeated:
	.string "ROUTE 207 TRAINER 5\n"
	.string "was defeated!$"

Route207_Text_Trainer5PostBattle:
	.string "ROUTE 207 TRAINER 5\n"
	.string "has nothing else to say.$"

Route207_EventScript_NPC1::
	msgbox Route207_Text_NPC1, MSGBOX_NPC
	end

Route207_Text_NPC1:
	.string "ROUTE 207 NPC 1$"

Route207_EventScript_Trainer6::
	trainerbattle_single TRAINER_ROUTE207_6, Route207_Text_Trainer6Intro, Route207_Text_Trainer6Defeated
	msgbox Route207_Text_Trainer6PostBattle, MSGBOX_AUTOCLOSE
	end

Route207_Text_Trainer6Intro:
	.string "ROUTE 207 TRAINER 6\n"
	.string "wants to battle!$"

Route207_Text_Trainer6Defeated:
	.string "ROUTE 207 TRAINER 6\n"
	.string "was defeated!$"

Route207_Text_Trainer6PostBattle:
	.string "ROUTE 207 TRAINER 6\n"
	.string "has nothing else to say.$"

Route207_EventScript_Sign1::
	msgbox Route207_Text_Sign1, MSGBOX_SIGN
	end

Route207_EventScript_Sign2::
	msgbox Route207_Text_Sign2, MSGBOX_SIGN
	end

Route207_EventScript_Sign3::
	msgbox Route207_Text_Sign3, MSGBOX_SIGN
	end

Route207_Text_Sign1:
	.string "ROUTE 207 SIGN 1$"

Route207_Text_Sign2:
	.string "ROUTE 207 SIGN 2$"

Route207_Text_Sign3:
	.string "ROUTE 207 SIGN 3$"
