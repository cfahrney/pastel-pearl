Route205_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route205_OnTransition
	.byte 0

Route205_EventScript_Trainer1::
	trainerbattle_single TRAINER_ROUTE205_1, Route205_Text_Trainer1Intro, Route205_Text_Trainer1Defeated
	msgbox Route205_Text_Trainer1PostBattle, MSGBOX_AUTOCLOSE
	end

Route205_Text_Trainer1Intro:
	.string "It's a long way between {COLOR DYNAMIC_COLOR3}Floaroma{COLOR DARK_GRAY} and\n"
	.string "Eterna City. So, let's battle!$"

Route205_Text_Trainer1Defeated:
	.string "Wawawaah! I'm out of Pokémon that can\n"
	.string "go!$"

Route205_Text_Trainer1PostBattle:
	.string "With my Pokémon by my side, I'm sure any\n"
	.string "camping will be a blast!$"

Route205_EventScript_Trainer2::
	trainerbattle_single TRAINER_ROUTE205_2, Route205_Text_Trainer2Intro, Route205_Text_Trainer2Defeated
	msgbox Route205_Text_Trainer2PostBattle, MSGBOX_AUTOCLOSE
	end

Route205_Text_Trainer2Intro:
	.string "What kinds of Pokémon live around here,\n"
	.string "I wonder?$"

Route205_Text_Trainer2Defeated:
	.string "I'm shocked! How did I lose?$"

Route205_Text_Trainer2PostBattle:
	.string "What can I tell you about Pokémon?\p"
	.string "Well, there are males and females. And\n"
	.string "some that you can't tell!$"

Route205_EventScript_Trainer3::
	trainerbattle_single TRAINER_ROUTE205_3, Route205_Text_Trainer3Intro, Route205_Text_Trainer3Defeated
	msgbox Route205_Text_Trainer3PostBattle, MSGBOX_AUTOCLOSE
	end

Route205_Text_Trainer3Intro:
	.string "There's no mountain here, but I'm\n"
	.string "dressed to hike! Gahaha! Here goes!$"

Route205_Text_Trainer3Defeated:
	.string "Oh, yeah! A refreshing battle that was!$"

Route205_Text_Trainer3PostBattle:
	.string "You can find the same kinds of Pokémon\n"
	.string "in all sorts of places.\p"
	.string "There's no law saying a Hiker can't go\n"
	.string "searching off in the mountains!$"

Route205_EventScript_Trainer4::
	trainerbattle_single TRAINER_ROUTE205_4, Route205_Text_Trainer4Intro, Route205_Text_Trainer4Defeated
	msgbox Route205_Text_Trainer4PostBattle, MSGBOX_AUTOCLOSE
	end

Route205_Text_Trainer4Intro:
	.string "How about a quick battle before I leave\n"
	.string "for Eterna Forest?$"

Route205_Text_Trainer4Defeated:
	.string "That really dampened my spirits.$"

Route205_Text_Trainer4PostBattle:
	.string "They say there are rough Pokémon in\n"
	.string "Eterna Forest.\p"
	.string "I'd better be more prepared than this.$"

Route205_EventScript_Trainer7::
	trainerbattle_single TRAINER_ROUTE205_7, Route205_Text_Trainer7Intro, Route205_Text_Trainer7Defeated
	msgbox Route205_Text_Trainer7PostBattle, MSGBOX_AUTOCLOSE
	end

Route205_Text_Trainer7Intro:
	.string "Of all places possible, I've lost my way\n"
	.string "here...$"

Route205_Text_Trainer7Defeated:
	.string "Having lost his way, the Trainer lost\n"
	.string "the battle too...$"

Route205_Text_Trainer7PostBattle:
	.string "From being lost in the mountains so\n"
	.string "long, I became a Hiker...$"

Route205_EventScript_Trainer8::
	trainerbattle_single TRAINER_ROUTE205_8, Route205_Text_Trainer8Intro, Route205_Text_Trainer8Defeated
	msgbox Route205_Text_Trainer8PostBattle, MSGBOX_AUTOCLOSE
	end

Route205_Text_Trainer8Intro:
	.string "Oh, I don't know. Should I play a little?$"

Route205_Text_Trainer8Defeated:
	.string "Oh, boo! How insulting!$"

Route205_Text_Trainer8PostBattle:
	.string "Listen very closely... Can you hear the\n"
	.string "cries of Pokémon?$"

Route205_EventScript_Trainer9::
	trainerbattle_single TRAINER_ROUTE205_9, Route205_Text_Trainer9Intro, Route205_Text_Trainer9Defeated
	msgbox Route205_Text_Trainer9PostBattle, MSGBOX_AUTOCLOSE
	end

Route205_Text_Trainer9Intro:
	.string "Osu! I'm not trained to hold back!$"

Route205_Text_Trainer9Defeated:
	.string "I... I concede! You're in a different\n"
	.string "class...$"

Route205_Text_Trainer9PostBattle:
	.string "You taught me how I measure up! Thank\n"
	.string "you!$"

Route205_EventScript_Trainer10::
	trainerbattle_single TRAINER_ROUTE205_10, Route205_Text_Trainer10Intro, Route205_Text_Trainer10Defeated
	msgbox Route205_Text_Trainer10PostBattle, MSGBOX_AUTOCLOSE
	end

Route205_Text_Trainer10Intro:
	.string "Check out these Pokémon I caught in\n"
	.string "{COLOR DYNAMIC_COLOR3}Eterna Forest{COLOR DARK_GRAY}!$"

Route205_Text_Trainer10Defeated:
	.string "Aww.. maybe I should go catch some more\n"
	.string "Pokémon...$"

Route205_Text_Trainer10PostBattle:
	.string "Have you caught any Pokémon from\n"
	.string "{COLOR DYNAMIC_COLOR3}Eterna Forest{COLOR DARK_GRAY} yet?$"

Route205_EventScript_Trainer12::
	trainerbattle_single TRAINER_ROUTE205_12, Route205_Text_Trainer12Intro, Route205_Text_Trainer12Defeated
	msgbox Route205_Text_Trainer12PostBattle, MSGBOX_AUTOCLOSE
	end

Route205_Text_Trainer12Intro:
	.string "I love Pokémon that smell sweet. Like\n"
	.string "this one--get a whiff of this!$"

Route205_Text_Trainer12Defeated:
	.string "Did you understand what I meant? Didn't\n"
	.string "my Pokémon smell nice?$"

Route205_Text_Trainer12PostBattle:
	.string "If you plant lots of Berries, you can be\n"
	.string "surrounded by sweet scents.$"

Route205_EventScript_Sign1::
	msgbox Route205_Text_Sign1, MSGBOX_SIGN
	end

Route205_Text_Sign1:
	.string "ROUTE 205 SIGN 1$"

Route205_EventScript_Sign2::
	msgbox Route205_Text_Sign2, MSGBOX_SIGN
	end

Route205_Text_Sign2:
	.string "Route 205\n"
	.string "{LEFT_ARROW} Floaroma Town$"

Route205_EventScript_Sign3::
	msgbox Route205_Text_Sign3, MSGBOX_SIGN
	end

Route205_Text_Sign3:
	.string "Route 205\n"
	.string "{UP_ARROW} Eterna Forest$"

Route205_EventScript_Sign4::
	msgbox Route205_Text_Sign4, MSGBOX_SIGN
	end

Route205_EventScript_NPC1::
	lockall
	faceplayer
	applymovement LOCALID_ROUTE205_GALACTIC_GRUNT_2, Route205_Movement_GalacticGrunt2
	waitmovement 0
	msgbox Route205_Text_NPC1, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ROUTE205_GALACTIC_GRUNT, Route205_Movement_GalacticGrunt
	waitmovement 0
	call Route205_EventScript_NPC1_2
	msgbox Route205_Text_NPC1_2, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

Route205_EventScript_NPC1_2::
	setflag FLAG_ROUTE205_GALACTIC_GRUNT_1
	return

Route205_EventScript_NPC2::
	goto Route205_EventScript_NPC1
	end

Route205_EventScript_NPC3::
	lock
	faceplayer
	goto_if_set FLAG_ROUTE205_LITTLE_GIRL_1, Route205_EventScript_NPC3_2
	call Route205_EventScript_NPC3_2_2
	msgbox Route205_Text_NPC3, MSGBOX_DEFAULT
	closemessage
	release
	end

Route205_EventScript_NPC3_2::
	msgbox Route205_Text_NPC3_2, MSGBOX_DEFAULT
	closemessage
	release
	end

Route205_EventScript_NPC3_2_2::
	setflag FLAG_ROUTE205_LITTLE_GIRL_2
	setflag FLAG_ROUTE205_LITTLE_GIRL_1
	setvar VAR_ROUTE205_STATE, 1
	return

Route205_EventScript_NPC4::
	lock
	faceplayer
	setflag FLAG_ROUTE205_YOUNGSTER_1
	msgbox Route205_Text_NPC4, MSGBOX_DEFAULT
	closemessage
	release
	end

Route205_EventScript_Trigger1::
	lockall
	getplayerxy VAR_0x8004, VAR_0x8005
	goto_if_eq VAR_0x8005, 83, Route205_EventScript_Trigger1_2
	goto_if_eq VAR_0x8005, 84, Route205_EventScript_Trigger1_2_2
	goto_if_eq VAR_0x8005, 85, Route205_EventScript_Trigger1_2_3
	goto_if_eq VAR_0x8005, 86, Route205_EventScript_Trigger1_2_4
	goto_if_eq VAR_0x8005, 87, Route205_EventScript_Trigger1_2_5
	end

Route205_EventScript_Trigger1_2::
	playse SE_PIN
	applymovement LOCALID_ROUTE205_LITTLE_GIRL, Route205_Movement_LittleGirl
	waitmovement 0
	applymovement LOCALID_PLAYER, Route205_Movement_Player
	waitmovement 0
	goto Route205_EventScript_Trigger1_2_6

Route205_EventScript_Trigger1_2_2::
	playse SE_PIN
	applymovement LOCALID_ROUTE205_LITTLE_GIRL, Route205_Movement_LittleGirl2
	waitmovement 0
	applymovement LOCALID_PLAYER, Route205_Movement_Player
	waitmovement 0
	goto Route205_EventScript_Trigger1_2_6

Route205_EventScript_Trigger1_2_3::
	goto Route205_EventScript_Trigger1_2_6

Route205_EventScript_Trigger1_2_4::
	playse SE_PIN
	applymovement LOCALID_ROUTE205_LITTLE_GIRL, Route205_Movement_LittleGirl3
	waitmovement 0
	applymovement LOCALID_PLAYER, Route205_Movement_Player2
	waitmovement 0
	goto Route205_EventScript_Trigger1_2_6

Route205_EventScript_Trigger1_2_5::
	playse SE_PIN
	applymovement LOCALID_ROUTE205_LITTLE_GIRL, Route205_Movement_LittleGirl4
	waitmovement 0
	applymovement LOCALID_PLAYER, Route205_Movement_Player2
	waitmovement 0
	goto Route205_EventScript_Trigger1_2_6

Route205_EventScript_Trigger1_2_6::
	call Route205_EventScript_NPC3_2_2
	msgbox Route205_Text_NPC3, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

Route205_EventScript_Trigger2::
	lockall
	applymovement LOCALID_ROUTE205_GALACTIC_GRUNT_2, Route205_Movement_GalacticGrunt22
	waitmovement 0
	msgbox Route205_Text_NPC1, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ROUTE205_GALACTIC_GRUNT, Route205_Movement_GalacticGrunt3
	waitmovement 0
	msgbox Route205_Text_Trigger2, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ROUTE205_GALACTIC_GRUNT_2, Route205_Movement_GalacticGrunt23
	applymovement LOCALID_PLAYER, Route205_Movement_Player3
	waitmovement 0
	applymovement LOCALID_ROUTE205_GALACTIC_GRUNT, Route205_Movement_GalacticGrunt
	waitmovement 0
	call Route205_EventScript_NPC1_2
	releaseall
	end

Route205_OnTransition::
	goto_if_set FLAG_ROUTE205_YOUNGSTER_1, Route205_OnTransition_2
	end

Route205_OnTransition_2::
	setobjectxyperm LOCALID_ROUTE205_YOUNGSTER, 18, 77
	end

Route205_Movement_GalacticGrunt2:
	walk_in_place_down
	step_end

Route205_Movement_GalacticGrunt:
	walk_in_place_down
	step_end

Route205_Movement_LittleGirl:
	walk_in_place_up
	emote_exclamation_mark
	delay_16
	walk_up
	step_end

Route205_Movement_Player:
	walk_in_place_down
	step_end

Route205_Movement_LittleGirl2:
	walk_in_place_up
	emote_exclamation_mark
	delay_16
	step_end

Route205_Movement_LittleGirl3:
	walk_in_place_down
	emote_exclamation_mark
	delay_16
	step_end

Route205_Movement_Player2:
	walk_in_place_up
	step_end

Route205_Movement_LittleGirl4:
	walk_in_place_down
	emote_exclamation_mark
	delay_16
	walk_down
	step_end

Route205_Movement_GalacticGrunt22:
	walk_in_place_right
	step_end

Route205_Movement_GalacticGrunt3:
	walk_in_place_left
	step_end

Route205_Movement_GalacticGrunt23:
	walk_fast_right
	walk_in_place_fast_down
	delay_16
	delay_16
	walk_left
	walk_in_place_down
	step_end

Route205_Movement_Player3:
	walk_down
	walk_in_place_fast_up
	step_end

Route205_Text_Sign4:
	.string "Trainer Tips!\p"
	.string "The items placed in your Bag are\n"
	.string "automatically sorted to the\l"
	.string "appropriate pockets.\p"
	.string "It's very convenient! It's a Trainer's\n"
	.string "best friend!$"

Route205_Text_NPC1:
	.string "We, Team Galactic, are conducting\n"
	.string "research in the Eterna Forest!\p"
	.string "This is as far as you will go!$"

Route205_Text_NPC1_2:
	.string "Our research involves catching Pokémon\n"
	.string "in the flowery meadows of {COLOR DYNAMIC_COLOR3}Floaroma\l"
	.string "Town{COLOR DARK_GRAY}.\p"
	.string "We are also using the energy of the\n"
	.string "Valley Windworks for something.\p"
	.string "But that is of no concern to you!$"

Route205_Text_NPC3:
	.string "Help, help, Trainer!\p"
	.string "Please, can you get my papa for me? He\n"
	.string "works at the Valley Windworks.\p"
	.string "But the people dressed like spacemen\n"
	.string "are mean and won't let me in...$"

Route205_Text_NPC3_2:
	.string "Please, Trainer! Get my papa from the\n"
	.string "Valley Windworks!$"

Route205_Text_NPC4:
	.string "If you slather sweet Honey on a\n"
	.string "sweet-smelling tree...\p"
	.string "Pokémon may be attracted by that\n"
	.string "sweet scent.$"

Route205_Text_Trigger2:
	.string "Our research involves catching Pokémon\n"
	.string "in the flowery meadows of {COLOR DYNAMIC_COLOR3}Floaroma\l"
	.string "Town{COLOR DARK_GRAY}.\p"
	.string "We are also using the energy of the\n"
	.string "Valley Windworks for something.\p"
	.string "But that is of no concern to you!$"
