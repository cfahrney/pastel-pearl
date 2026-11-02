Route219_MapScripts::
	.byte 0

Route219_EventScript_Trainer1::
	trainerbattle_single TRAINER_ROUTE219_1, Route219_Text_Trainer1Intro, Route219_Text_Trainer1Defeated
	msgbox Route219_Text_Trainer1PostBattle, MSGBOX_AUTOCLOSE
	end

Route219_Text_Trainer1Intro:
	.string "I love my inner tube. So I admire\n"
	.string "jellyfish Pokémon!$"

Route219_Text_Trainer1Defeated:
	.string "I'm drifting away...$"

Route219_Text_Trainer1PostBattle:
	.string "I wish Professor Rowan would give me a\n"
	.string "{COLOR DYNAMIC_COLOR3}Pokédex{COLOR DARK_GRAY}.\p"
	.string "But that old guy looks kind of scary.$"

Route219_EventScript_Trainer2::
	trainerbattle_single TRAINER_ROUTE219_2, Route219_Text_Trainer2Intro, Route219_Text_Trainer2Defeated
	msgbox Route219_Text_Trainer2PostBattle, MSGBOX_AUTOCLOSE
	end

Route219_Text_Trainer2Intro:
	.string "I can't swim without my floaty. But my\n"
	.string "Pokémon sure can!$"

Route219_Text_Trainer2Defeated:
	.string "They weren't tough, my Pokémon...$"

Route219_Text_Trainer2PostBattle:
	.string "My mommy said that Professor Rowan is\n"
	.string "really kindhearted.$"
