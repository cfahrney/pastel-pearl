Route203_MapScripts::
	.byte 0

Route203_EventScript_Sign1::
	msgbox Route203_Text_Sign1, MSGBOX_SIGN
	end

Route203_EventScript_Sign2::
	msgbox Route203_Text_Sign2, MSGBOX_SIGN
	end

Route203_EventScript_Sign3::
	msgbox Route203_Text_Sign3, MSGBOX_SIGN
	end

Route203_EventScript_Sign4::
	msgbox Route203_Text_Sign4, MSGBOX_SIGN
	end

Route203_Text_Sign1:
	.string "ROUTE 203 SIGN 1$"

Route203_Text_Sign2:
	.string "ROUTE 203 SIGN 2$"

Route203_Text_Sign3:
	.string "ROUTE 203 SIGN 3$"

Route203_Text_Sign4:
	.string "ROUTE 203 SIGN 4$"

Route203_EventScript_Trainer1::
	trainerbattle_single TRAINER_ROUTE203_1, Route203_Text_Trainer1Intro, Route203_Text_Trainer1Defeated
	msgbox Route203_Text_Trainer1PostBattle, MSGBOX_AUTOCLOSE
	end

Route203_EventScript_Trainer2::
	trainerbattle_single TRAINER_ROUTE203_2, Route203_Text_Trainer2Intro, Route203_Text_Trainer2Defeated
	msgbox Route203_Text_Trainer2PostBattle, MSGBOX_AUTOCLOSE
	end

Route203_EventScript_Trainer3::
	trainerbattle_single TRAINER_ROUTE203_3, Route203_Text_Trainer3Intro, Route203_Text_Trainer3Defeated
	msgbox Route203_Text_Trainer3PostBattle, MSGBOX_AUTOCLOSE
	end

Route203_EventScript_Trainer4::
	trainerbattle_single TRAINER_ROUTE203_4, Route203_Text_Trainer4Intro, Route203_Text_Trainer4Defeated
	msgbox Route203_Text_Trainer4PostBattle, MSGBOX_AUTOCLOSE
	end

Route203_EventScript_Trainer5::
	trainerbattle_single TRAINER_ROUTE203_5, Route203_Text_Trainer5Intro, Route203_Text_Trainer5Defeated
	msgbox Route203_Text_Trainer5PostBattle, MSGBOX_AUTOCLOSE
	end

Route203_EventScript_Trainer6::
	trainerbattle_single TRAINER_ROUTE203_6, Route203_Text_Trainer6Intro, Route203_Text_Trainer6Defeated
	msgbox Route203_Text_Trainer6PostBattle, MSGBOX_AUTOCLOSE
	end

Route203_Text_Trainer1Intro:
	.string "ROUTE 203 TRAINER 1\n"
	.string "wants to battle!$"

Route203_Text_Trainer1Defeated:
	.string "ROUTE 203 TRAINER 1\n"
	.string "was defeated!$"

Route203_Text_Trainer1PostBattle:
	.string "ROUTE 203 TRAINER 1\n"
	.string "has nothing else to say.$"

Route203_Text_Trainer2Intro:
	.string "ROUTE 203 TRAINER 2\n"
	.string "wants to battle!$"

Route203_Text_Trainer2Defeated:
	.string "ROUTE 203 TRAINER 2\n"
	.string "was defeated!$"

Route203_Text_Trainer2PostBattle:
	.string "ROUTE 203 TRAINER 2\n"
	.string "has nothing else to say.$"

Route203_Text_Trainer3Intro:
	.string "ROUTE 203 TRAINER 3\n"
	.string "wants to battle!$"

Route203_Text_Trainer3Defeated:
	.string "ROUTE 203 TRAINER 3\n"
	.string "was defeated!$"

Route203_Text_Trainer3PostBattle:
	.string "ROUTE 203 TRAINER 3\n"
	.string "has nothing else to say.$"

Route203_Text_Trainer4Intro:
	.string "ROUTE 203 TRAINER 4\n"
	.string "wants to battle!$"

Route203_Text_Trainer4Defeated:
	.string "ROUTE 203 TRAINER 4\n"
	.string "was defeated!$"

Route203_Text_Trainer4PostBattle:
	.string "ROUTE 203 TRAINER 4\n"
	.string "has nothing else to say.$"

Route203_Text_Trainer5Intro:
	.string "ROUTE 203 TRAINER 5\n"
	.string "wants to battle!$"

Route203_Text_Trainer5Defeated:
	.string "ROUTE 203 TRAINER 5\n"
	.string "was defeated!$"

Route203_Text_Trainer5PostBattle:
	.string "ROUTE 203 TRAINER 5\n"
	.string "has nothing else to say.$"

Route203_Text_Trainer6Intro:
	.string "ROUTE 203 TRAINER 6\n"
	.string "wants to battle!$"

Route203_Text_Trainer6Defeated:
	.string "ROUTE 203 TRAINER 6\n"
	.string "was defeated!$"

Route203_Text_Trainer6PostBattle:
	.string "ROUTE 203 TRAINER 6\n"
	.string "has nothing else to say.$"
