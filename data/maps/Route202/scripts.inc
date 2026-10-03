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
	.string "Route 202\n"
	.string "{DOWN_ARROW} Sandgem Town$"

Route202_Text_Sign2:
	.string "Trainer Tips!\p"
	.string "Some Pokemon only appear in the\n"
	.string "morning. Some only come out during the\l"
	.string "day, or at night.\p"
	.string "Be sure to check a route throughout a\n"
	.string "day to see who else could appear!$"

Route202_Text_Sign3:
	.string "Route 202\n"
	.string "{UP_ARROW} Jubilife City$"

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
	.string "You're a Pokemon Trainer!\n"
	.string "I happen to be a Pokemon Trainer!\l"
	.string "Our eyes met, so battle we must!$"

Route202_Text_Trainer1Defeated:
	.string "Wow, you showed me, alright!$"

Route202_Text_Trainer1PostBattle:
	.string "Don't be shy about talking to Trainers\n"
	.string "you'd like to battle. Pokemon grow\l"
	.string "stronger and stronger from battling.$"

Route202_Text_Trainer2Intro:
	.string "Where do you stand on Bug Pokemon?$"

Route202_Text_Trainer2Defeated:
	.string "Ahhh! My bugs!$"

Route202_Text_Trainer2PostBattle:
	.string "My bugs are all tuckered out! I need to\n"
	.string "go to a Pokemon Center!$"

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
	.string "Let's have a Pokemon battle! Humph! But\n"
	.string "I'm gonna win!$"

Route202_Text_Trainer4Defeated:
	.string "You're like, wow!$"

Route202_Text_Trainer4PostBattle:
	.string "It's fun to battle others!\n"
	.string "I'm gonna battle all sorts of people!$"

Route202_EventScript_NPC1::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SHINX, CRY_MODE_NORMAL
	setspeaker Route202_Text_NPC1Speaker
	msgbox Route202_Text_NPC1, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route202_EventScript_NPC2::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_GROWLITHE, CRY_MODE_NORMAL
	setspeaker Route202_Text_NPC2Speaker
	msgbox Route202_Text_NPC2, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route202_Text_NPC1Speaker:
	.string "Shinx$"

Route202_Text_NPC1:
	.string "ROUTE 202 NPC 1$"

Route202_Text_NPC2Speaker:
	.string "Growlithe$"

Route202_Text_NPC2:
	.string "ROUTE 202 NPC 2$"
