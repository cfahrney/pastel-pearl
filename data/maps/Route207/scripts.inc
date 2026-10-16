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
	.string "Wahaha! Laughter brings good fortune!$"

Route207_Text_Trainer1Defeated:
	.string "Wahahaha! There's nothing that I can do\n"
	.string "but laugh!$"

Route207_Text_Trainer1PostBattle:
	.string "Wahaha! ...Go ahead and laugh at me.$"

Route207_Text_Trainer2Intro:
	.string "I wear shorts the whole year! I've got\n"
	.string "energy to burn!$"

Route207_Text_Trainer2Defeated:
	.string "Having lots of energy isn't good\n"
	.string "enough...$"

Route207_Text_Trainer2PostBattle:
	.string "My Pokémon don't wear anything. I worry\n"
	.string "that they'll be cold.$"

Route207_Text_Trainer3Intro:
	.string "Go for it, my Pokémon! I'll do my best,\n"
	.string "too!$"

Route207_Text_Trainer3Defeated:
	.string "Oh... We lost...$"

Route207_Text_Trainer3PostBattle:
	.string "Did you know? You can dig up Fossils in\n"
	.string "the Underground!\p"
	.string "Those Fossils can be turned back into\n"
	.string "Pokémon at the mining museum!$"

Route207_Text_Trainer4Intro:
	.string "Go do it, my Pokémon! I'll work hard, too!$"

Route207_Text_Trainer4Defeated:
	.string "Oh... We lost...$"

Route207_Text_Trainer4PostBattle:
	.string "I think we'll go visit the TV station in\n"
	.string "{COLOR DYNAMIC_COLOR3}Jubilife City{COLOR DARK_GRAY} next.$"

Route207_Text_Trainer5Intro:
	.string "I just got through Mt. Coronet, but\n"
	.string "we've still got fuel in the tank!$"

Route207_Text_Trainer5Defeated:
	.string "Whoops! Didn't take much to beat us!$"

Route207_Text_Trainer5PostBattle:
	.string "We need to rest up in {COLOR DYNAMIC_COLOR3}Oreburgh City{COLOR DARK_GRAY}\n"
	.string "before heading to Mt. Coronet again.$"

Route207_EventScript_NPC1::
	msgbox Route207_Text_NPC1, MSGBOX_NPC
	end

Route207_Text_NPC1:
	.string "That slope's too slippery. You'll need a\n"
	.string "Bike to get up.\p"
	.string "You don't have a {COLOR DYNAMIC_COLOR3}Bicycle{COLOR DARK_GRAY}? There's a\n"
	.string "Cycle Shop in {COLOR DYNAMIC_COLOR3}Eterna City{COLOR DARK_GRAY}.$"

Route207_EventScript_Trainer6::
	trainerbattle_single TRAINER_ROUTE207_6, Route207_Text_Trainer6Intro, Route207_Text_Trainer6Defeated
	msgbox Route207_Text_Trainer6PostBattle, MSGBOX_AUTOCLOSE
	end

Route207_Text_Trainer6Intro:
	.string "OK, OK! Let's be quick about this!$"

Route207_Text_Trainer6Defeated:
	.string "No way! Give us another battle! ...Oh,\n"
	.string "right. I'm out of Pokémon.$"

Route207_Text_Trainer6PostBattle:
	.string "Yup! I like the way you battle.$"

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
	.string "Route 207\n"
	.string "{DOWN_ARROW} Oreburgh City$"

Route207_Text_Sign2:
	.string "Route 207\n"
	.string "{RIGHT_ARROW} Mt. Coronet$"

Route207_Text_Sign3:
	.string "ROUTE 207 SIGN 3$"
