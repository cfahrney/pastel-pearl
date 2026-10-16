Route204_North_MapScripts::
	.byte 0

Route204_North_EventScript_NPC1::
	msgbox Route204_North_Text_NPC1, MSGBOX_NPC
	end

Route204_North_Text_NPC1:
	.string "Are you raising different kinds of\n"
	.string "Pokémon? If you only have the same\l"
	.string "type of Pokémon, you'll have a hard time\l"
	.string "against types it's weak to.$"

Route204_North_EventScript_Sign1::
	msgbox Route204_North_Text_Sign1, MSGBOX_SIGN
	end

Route204_North_EventScript_Trainer1::
	trainerbattle_single TRAINER_ROUTE204_3, Route204_North_Text_Trainer1Intro, Route204_North_Text_Trainer1Defeated
	msgbox Route204_North_Text_Trainer1PostBattle, MSGBOX_AUTOCLOSE
	end

Route204_North_Text_Sign1:
	.string "Rt. 204 Floaroma Town$"

Route204_North_Text_Trainer1Intro:
	.string "Let's have a battle while smelling the\n"
	.string "aroma of flowers!$"

Route204_North_Text_Trainer1Defeated:
	.string "Even though I lost, I'm not angry\n"
	.string "because it smells so nice.$"

Route204_North_Text_Trainer1PostBattle:
	.string "Maybe I'll put some Accessories on my\n"
	.string "Pokémon at the TV station in\p"
	.string "{COLOR DYNAMIC_COLOR3}Jubilife City{COLOR DARK_GRAY}.$"

Route204_North_EventScript_Trainer2::
	trainerbattle_single TRAINER_ROUTE204_NORTH_2, Route204_North_Text_Trainer2Intro, Route204_North_Text_Trainer2Defeated
	msgbox Route204_North_Text_Trainer2PostBattle, MSGBOX_AUTOCLOSE
	end

Route204_North_Text_Trainer2Intro:
	.string "Say, listen. What's your opinion on bug\n"
	.string "Pokémon?$"

Route204_North_Text_Trainer2Defeated:
	.string "I'm not going to be able to explain the\n"
	.string "charms of bug Pokémon this way!$"

Route204_North_Text_Trainer2PostBattle:
	.string "Bug Pokémon grow quickly, and they do\n"
	.string "stuff like poison and paralyze, and\p"
	.string "they're cute and yet cool.\p"
	.string "You gotta believe me. They're good!$"

Route204_North_EventScript_Trainer3::
	trainerbattle_single TRAINER_ROUTE204_NORTH_3, Route204_North_Text_Trainer3Intro, Route204_North_Text_Trainer3Defeated
	msgbox Route204_North_Text_Trainer3PostBattle, MSGBOX_AUTOCLOSE
	end

Route204_North_Text_Trainer3Intro:
	.string "Let's have a battle while smelling the\n"
	.string "aroma of flowers!$"

Route204_North_Text_Trainer3Defeated:
	.string "Even though I lost, I'm not angry\n"
	.string "because it smells so nice.$"

Route204_North_Text_Trainer3PostBattle:
	.string "Maybe I'll put some Accessories on my\n"
	.string "Pokémon at the TV station in\p"
	.string "{COLOR DYNAMIC_COLOR3}Jubilife City{COLOR DARK_GRAY}.$"

Route204_North_EventScript_Trainer4::
	trainerbattle_double TRAINER_ROUTE204_NORTH_4, Route204_North_Text_Trainer4Intro, Route204_North_Text_Trainer4Defeated, Route204_North_Text_Trainer4NotEnoughMons
	msgbox Route204_North_Text_Trainer4PostBattle, MSGBOX_AUTOCLOSE
	end

Route204_North_Text_Trainer4Intro:
	.string "ROUTE 204 NORTH TRAINER 4\nwants to battle!$"

Route204_North_Text_Trainer4Defeated:
	.string "ROUTE 204 NORTH TRAINER 4\nwas defeated!$"

Route204_North_Text_Trainer4PostBattle:
	.string "ROUTE 204 NORTH TRAINER 4\nhas nothing else to say.$"

Route204_North_Text_Trainer4NotEnoughMons:
	.string "ROUTE 204 NORTH TRAINER 4\nwants a double battle!$"
