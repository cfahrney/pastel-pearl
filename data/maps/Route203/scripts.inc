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
	.string "Route 203\n"
	.string "{LEFT_ARROW} Jubilife City$"

Route203_Text_Sign2:
	.string "Trainer Tips!\p"
	.string "Pokemon moves use energy called Power\n"
	.string "Points, or PP for short.\p"
	.string "If the PP of moves runs low, head for\n"
	.string "any Pokemon Center.$"

Route203_Text_Sign3:
	.string "Trainer tips!\p"
	.string "If a Pokemon is about to evolve, it can\n"
	.string "be instantly stopped.\p"
	.string "Press the B Button during evolution to\n"
	.string "startle the Pokemon into stopping.\p"
	.string "This is how evolution can be canceled.$"

Route203_Text_Sign4:
	.string "Route 203\n"
	.string "{RIGHT_ARROW} Oreburgh City$"

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
	.string "I got a nifty-keen Gym Badge from the\n"
	.string "Gym Leader in Oreburgh City!$"

Route203_Text_Trainer1Defeated:
	.string "Oh, I lost! Lalala!$"

Route203_Text_Trainer1PostBattle:
	.string "I'm going to collect lots of Gym Badges!\n"
	.string "I'll work with my Pokemon!$"

Route203_Text_Trainer2Intro:
	.string "Gimme a battle so I can see if I'm ready\n"
	.string "for the Pokemon Gym Challenge!$"

Route203_Text_Trainer2Defeated:
	.string "I guess it means I'm not ready for the\n"
	.string "Gym challenge yet...$"

Route203_Text_Trainer2PostBattle:
	.string "I guess if you don't have a single Gym\n"
	.string "Badge, you're a total nobody...$"

Route203_Text_Trainer3Intro:
	.string "I found a Trainer while looking for some\n"
	.string "Pokemon!$"

Route203_Text_Trainer3Defeated:
	.string "Huh? Finished so soon?$"

Route203_Text_Trainer3PostBattle:
	.string "I walk through tall grass until I find\n"
	.string "the Pokemon I want.$"

Route203_Text_Trainer4Intro:
	.string "We're always together. I'll show you how\n"
	.string "we've bonded!$"

Route203_Text_Trainer4Defeated:
	.string "Wow, that's an amazing bond you have\n"
	.string "with your Pokemon.$"

Route203_Text_Trainer4PostBattle:
	.string "I don't bear grudges over losing. But I\n"
	.string "promise I'll get tougher!$"

Route203_Text_Trainer5Intro:
	.string "I'm full of energy because I get power\n"
	.string "from my Pokemon!$"

Route203_Text_Trainer5Defeated:
	.string "Oh! My poor Magby and Zubat!$"

Route203_Text_Trainer5PostBattle:
	.string "Avoid tall grass... Or avoid Trainers...\p"
	.string "Do you have trouble deciding?$"

Route203_Text_Trainer6Intro:
	.string "Check out this cutie I caught earlier!$"

Route203_Text_Trainer6Defeated:
	.string "Oh...maybe they weren't ready for a\n"
	.string "battle yet...$"

Route203_Text_Trainer6PostBattle:
	.string "My Bidoof and I are still proud of\n"
	.string "Togepi!$"
