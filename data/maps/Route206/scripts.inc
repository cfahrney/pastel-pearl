Route206_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, Route206_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, Route206_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route206_OnFrame
	.byte 0

Route206_EventScript_Trainer1::
	trainerbattle_single TRAINER_ROUTE206_1, Route206_Text_Trainer1Intro, Route206_Text_Trainer1Defeated
	msgbox Route206_Text_Trainer1PostBattle, MSGBOX_AUTOCLOSE
	end

Route206_EventScript_Trainer2::
	trainerbattle_single TRAINER_ROUTE206_2, Route206_Text_Trainer2Intro, Route206_Text_Trainer2Defeated
	msgbox Route206_Text_Trainer2PostBattle, MSGBOX_AUTOCLOSE
	end

Route206_EventScript_Trainer3::
	trainerbattle_single TRAINER_ROUTE206_3, Route206_Text_Trainer3Intro, Route206_Text_Trainer3Defeated
	msgbox Route206_Text_Trainer3PostBattle, MSGBOX_AUTOCLOSE
	end

Route206_EventScript_Trainer4::
	trainerbattle_single TRAINER_ROUTE206_4, Route206_Text_Trainer4Intro, Route206_Text_Trainer4Defeated
	msgbox Route206_Text_Trainer4PostBattle, MSGBOX_AUTOCLOSE
	end

Route206_EventScript_Trainer5::
	trainerbattle_single TRAINER_ROUTE206_5, Route206_Text_Trainer5Intro, Route206_Text_Trainer5Defeated
	msgbox Route206_Text_Trainer5PostBattle, MSGBOX_AUTOCLOSE
	end

Route206_EventScript_Trainer6::
	trainerbattle_single TRAINER_ROUTE206_6, Route206_Text_Trainer6Intro, Route206_Text_Trainer6Defeated
	msgbox Route206_Text_Trainer6PostBattle, MSGBOX_AUTOCLOSE
	end

Route206_EventScript_Trainer7::
	trainerbattle_single TRAINER_ROUTE206_7, Route206_Text_Trainer7Intro, Route206_Text_Trainer7Defeated
	msgbox Route206_Text_Trainer7PostBattle, MSGBOX_AUTOCLOSE
	end

Route206_EventScript_Trainer8::
	trainerbattle_single TRAINER_ROUTE206_8, Route206_Text_Trainer8Intro, Route206_Text_Trainer8Defeated
	msgbox Route206_Text_Trainer8PostBattle, MSGBOX_AUTOCLOSE
	end

Route206_EventScript_Sign1::
	msgbox Route206_Text_Sign1, MSGBOX_SIGN
	end

Route206_Text_Trainer1Intro:
	.string "I love my Bike!\p"
	.string "But I'm not very good at fixing flat\n"
	.string "tires...$"

Route206_Text_Trainer1Defeated:
	.string "Kerrrash!$"

Route206_Text_Trainer1PostBattle:
	.string "I admire people who understand\n"
	.string "gadgets.\p"
	.string "I'm clueless about how my Pokétch\n"
	.string "works.$"

Route206_Text_Trainer2Intro:
	.string "Some people compete over speed, and\n"
	.string "some compete over technique.\p"
	.string "Which kind are you?$"

Route206_Text_Trainer2Defeated:
	.string "You're a speedy technician!$"

Route206_Text_Trainer2PostBattle:
	.string "I enjoy the scenery.\p"
	.string "Don't you think the area below Cycling\n"
	.string "Road looks nice?$"

Route206_Text_Trainer3Intro:
	.string "A {COLOR DYNAMIC_COLOR3}Bicycle{COLOR DARK_GRAY} can only take you as far as\n"
	.string "your energy will allow.$"

Route206_Text_Trainer3Defeated:
	.string "Gasp... Gasp... Gasp...$"

Route206_Text_Trainer3PostBattle:
	.string "My Pokémon are out of gas. So am I.\p"
	.string "I'm going to head home soon...$"

Route206_Text_Trainer4Intro:
	.string "Your Bike is the type that can shift\n"
	.string "gears, huh?\p"
	.string "Let me see if you know how to ride it\n"
	.string "properly.$"

Route206_Text_Trainer4Defeated:
	.string "Crash! Tinkle...$"

Route206_Text_Trainer4PostBattle:
	.string "Huh? I was supposed to be checking if\n"
	.string "you know how to shift gears.\p"
	.string "Why am I checking out your Pokémon?$"

Route206_Text_Trainer5Intro:
	.string "You and I, we're both riding Bikes.\p"
	.string "And you've got Pokémon. I don't want to\n"
	.string "lose to you!$"

Route206_Text_Trainer5Defeated:
	.string "Oh, geez... I seem to have fallen off my\n"
	.string "Bike.$"

Route206_Text_Trainer5PostBattle:
	.string "Instead of a battle, I should've\n"
	.string "challenged you to a Bike race!$"

Route206_Text_Trainer6Intro:
	.string "Hey! Watch where you're going! Or did\n"
	.string "you want to challenge me?$"

Route206_Text_Trainer6Defeated:
	.string "My efforts were meaningless...$"

Route206_Text_Trainer6PostBattle:
	.string "I might try racing through Cycling Road\n"
	.string "in one long shot.$"

Route206_Text_Trainer7Intro:
	.string "Yo! Having a good time cycling?$"

Route206_Text_Trainer7Defeated:
	.string "Hey, not bad, you!$"

Route206_Text_Trainer7PostBattle:
	.string "Cycling Road's teeming with Pokémon\n"
	.string "Trainers, too!$"

Route206_Text_Trainer8Intro:
	.string "Whoa! You startled me! Well, we may as\n"
	.string "well battle!$"

Route206_Text_Trainer8Defeated:
	.string "Your power startles me!$"

Route206_Text_Trainer8PostBattle:
	.string "We Hikers are bighearted guys! Losing\n"
	.string "doesn't bother us!$"

Route206_Text_Sign1:
	.string "Rt. 206 Oreburgh City$"

Route206_EventScript_Sign2::
	msgbox Route206_Text_Sign2, MSGBOX_SIGN
	end

Route206_OnResume::
	@ TODO(DP): call if DP system flag 2452 is set
	@ TODO(DP): GetPreviousMapID 16384
	goto_if_eq VAR_TEMP_0, 80, Route206_OnResume_2_2
	goto_if_eq VAR_TEMP_0, 351, Route206_OnResume_2_2
	end

Route206_OnResume_2::
	@ TODO(DP): CyclingRoad 1
	return

Route206_OnResume_2_2::
	goto_if_set FLAG_ROUTE206_EVENT_1, Route206_OnResume_2_3
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	goto_if_lt VAR_TEMP_0, 11, Route206_OnResume_2_3
	goto_if_gt VAR_TEMP_0, 18, Route206_OnResume_2_3
	goto_if_eq VAR_TEMP_1, 0, Route206_OnResume_2_4
	goto_if_eq VAR_TEMP_1, 105, Route206_OnResume_2_4
	end

Route206_OnResume_2_3::
	end

Route206_OnResume_2_4::
	setflag FLAG_ROUTE206_EVENT_1
	@ DP: set system flag 2452 (not needed here)
	setvar VAR_ROUTE206_STATE, 1
	@ TODO(DP): CyclingRoad 1
	end

Route206_OnTransition::
	@ DP: set system flag 2534 (not needed here)
	end

Route206_EventScript_OnFrame::
	@ TODO(DP): RideBike 1
	setvar VAR_ROUTE206_STATE, 0
	end

Route206_OnFrame:
	map_script_2 VAR_ROUTE206_STATE, 1, Route206_EventScript_OnFrame
	.2byte 0

Route206_Text_Sign2:
	.string "Rt. 206\n"
	.string "Eterna City$"

Route206_EventScript_Trainer9::
	trainerbattle_single TRAINER_ROUTE206_9, Route206_Text_Trainer9Intro, Route206_Text_Trainer9Defeated
	msgbox Route206_Text_Trainer9PostBattle, MSGBOX_AUTOCLOSE
	end

Route206_Text_Trainer9Intro:
	.string "I worked up a good sweat riding! I'm\n"
	.string "feeling great! Let's battle!$"

Route206_Text_Trainer9Defeated:
	.string "Whew! You worked us over.$"

Route206_Text_Trainer9PostBattle:
	.string "Do you find yourself pedaling backward\n"
	.string "going downhill?$"
