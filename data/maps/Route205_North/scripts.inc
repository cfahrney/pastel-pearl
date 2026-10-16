Route205_North_MapScripts::
	.byte 0

Route205_North_EventScript_NPC1::
	msgbox Route205_North_Text_NPC1, MSGBOX_NPC
	end

Route205_North_Text_NPC1:
	.string "To sit back and fish casually... It's a\n"
	.string "grown-up's hobby.$"

Route205_North_EventScript_Trainer1::
	trainerbattle_single TRAINER_ROUTE205_NORTH_1, Route205_North_Text_Trainer1Intro, Route205_North_Text_Trainer1Defeated
	msgbox Route205_North_Text_Trainer1PostBattle, MSGBOX_AUTOCLOSE
	end

Route205_North_Text_Trainer1Intro:
	.string "I landed myself a feisty Trainer! Let's\n"
	.string "go!$"

Route205_North_Text_Trainer1Defeated:
	.string "I let a big win slip away...$"

Route205_North_Text_Trainer1PostBattle:
	.string "Do you have a fishing rod? Catch some\n"
	.string "big ones!$"

Route205_North_EventScript_Trainer2::
	trainerbattle_single TRAINER_ROUTE205_NORTH_2, Route205_North_Text_Trainer2Intro, Route205_North_Text_Trainer2Defeated
	msgbox Route205_North_Text_Trainer2PostBattle, MSGBOX_AUTOCLOSE
	end

Route205_North_Text_Trainer2Intro:
	.string "I fished up some tough Pokémon! Let's\n"
	.string "have ourselves a battle!$"

Route205_North_Text_Trainer2Defeated:
	.string "Losing has my emotions all knotted up!$"

Route205_North_Text_Trainer2PostBattle:
	.string "My feet are tangled, too! Ouch! Ouch!$"

Route205_North_EventScript_Trainer3::
	trainerbattle_single TRAINER_ROUTE205_NORTH_3, Route205_North_Text_Trainer3Intro, Route205_North_Text_Trainer3Defeated
	msgbox Route205_North_Text_Trainer3PostBattle, MSGBOX_AUTOCLOSE
	end

Route205_North_Text_Trainer3Intro:
	.string "Nothing's biting... I could use a break, I\n"
	.string "suppose.$"

Route205_North_Text_Trainer3Defeated:
	.string "Oh, well. I should've been a little more\n"
	.string "serious about this.$"

Route205_North_Text_Trainer3PostBattle:
	.string "!\p"
	.string "Yank your fishing rod when that\n"
	.string "appears. That's how you fish.$"

Route205_North_EventScript_Sign1::
	msgbox Route205_North_Text_Sign1, MSGBOX_SIGN
	end

Route205_North_Text_Sign1:
	.string "Route 205\n"
	.string "{LEFT_ARROW} Eterna Forest$"

Route205_North_EventScript_Sign2::
	msgbox Route205_North_Text_Sign2, MSGBOX_SIGN
	end

Route205_North_Text_Sign2:
	.string "Route 205\n"
	.string "{RIGHT_ARROW} Eterna City$"
