Route203_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route203_OnTransition
	.byte 0

Route203_OnTransition:
	@ Barry only waits here once the player has the DexNav.
	setflag FLAG_HIDE_ROUTE203_BARRY
	call_if_eq VAR_JUBILIFE_CITY_STATE, 3, Route203_EventScript_ShowBarry
	end

Route203_EventScript_ShowBarry:
	clearflag FLAG_HIDE_ROUTE203_BARRY
	return

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
	.string "Gym Leader in {COLOR DYNAMIC_COLOR3}Oreburgh City{COLOR DARK_GRAY}!$"

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

Route203_EventScript_BarryNoticesPlayerAtY17::
	lockall
	call Route203_EventScript_BarryNoticesPlayer
	applymovement LOCALID_ROUTE203_BARRY, Route203_Movement_BarryApproachY17
	waitmovement LOCALID_ROUTE203_BARRY
	goto Route203_EventScript_BarryRivalFight1

Route203_EventScript_BarryNoticesPlayerAtY18::
	lockall
	call Route203_EventScript_BarryNoticesPlayer
	applymovement LOCALID_ROUTE203_BARRY, Route203_Movement_BarryApproachY18
	waitmovement LOCALID_ROUTE203_BARRY
	goto Route203_EventScript_BarryRivalFight1

Route203_EventScript_BarryNoticesPlayerAtY19::
	lockall
	call Route203_EventScript_BarryNoticesPlayer
	applymovement LOCALID_ROUTE203_BARRY, Route203_Movement_BarryApproachY19
	waitmovement LOCALID_ROUTE203_BARRY
	goto Route203_EventScript_BarryRivalFight1

Route203_EventScript_BarryNoticesPlayerAtY20::
	lockall
	call Route203_EventScript_BarryNoticesPlayer
	applymovement LOCALID_ROUTE203_BARRY, Route203_Movement_BarryApproachY20
	waitmovement LOCALID_ROUTE203_BARRY
	goto Route203_EventScript_BarryRivalFight1

Route203_EventScript_BarryNoticesPlayerAtY21::
	lockall
	call Route203_EventScript_BarryNoticesPlayer
	applymovement LOCALID_ROUTE203_BARRY, Route203_Movement_BarryApproachY21
	waitmovement LOCALID_ROUTE203_BARRY
	goto Route203_EventScript_BarryRivalFight1

Route203_EventScript_BarryNoticesPlayer::
	playse SE_PIN
	playbgm MUS_RIVAL_THEME, TRUE
	applymovement LOCALID_ROUTE203_BARRY, Common_Movement_ExclamationMark
	waitmovement LOCALID_ROUTE203_BARRY
	applymovement LOCALID_ROUTE203_BARRY, Common_Movement_FaceLeft
	waitmovement LOCALID_ROUTE203_BARRY
	delay 45
	return

Route203_EventScript_BarryRivalFight1::
	applymovement LOCALID_PLAYER, Common_Movement_FaceRight
	waitmovement LOCALID_PLAYER
	setspeaker SP_NAME_RIVAL
	msgbox Route203_Text_BarryGotTougher, MSGBOX_DEFAULT
	closemessage
	goto_if_eq VAR_STARTER_MON, STARTER_TURTWIG, Route203_EventScript_BarryBattleTurtwig
	goto_if_eq VAR_STARTER_MON, STARTER_CHIMCHAR, Route203_EventScript_BarryBattleChimchar
	goto Route203_EventScript_BarryBattlePiplup

Route203_EventScript_BarryBattleTurtwig::
	trainerbattle_no_intro TRAINER_ROUTE203_BARRY_PLAYER_CHOSE_TURTWIG, Route203_Text_BarryDefeated
	goto Route203_EventScript_BarryAfterBattle

Route203_EventScript_BarryBattleChimchar::
	trainerbattle_no_intro TRAINER_ROUTE203_BARRY_PLAYER_CHOSE_CHIMCHAR, Route203_Text_BarryDefeated
	goto Route203_EventScript_BarryAfterBattle

Route203_EventScript_BarryBattlePiplup::
	trainerbattle_no_intro TRAINER_ROUTE203_BARRY_PLAYER_CHOSE_PIPLUP, Route203_Text_BarryDefeated
	goto Route203_EventScript_BarryAfterBattle

Route203_EventScript_BarryAfterBattle::
	savebgm MUS_DUMMY
	fadedefaultbgm
	setspeaker SP_NAME_RIVAL
	msgbox Route203_Text_BarryVowsToBeToughest, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ROUTE203_BARRY, Route203_Movement_BarryJogsOff
	waitmovement LOCALID_ROUTE203_BARRY
	removeobject LOCALID_ROUTE203_BARRY
	setflag FLAG_HIDE_ROUTE203_BARRY
	setvar VAR_JUBILIFE_CITY_STATE, 4
	releaseall
	end

Route203_Movement_BarryApproachY17:
	walk_left
	walk_left
	walk_left
	walk_up
	face_left
	step_end

Route203_Movement_BarryApproachY18:
	walk_left
	walk_left
	walk_left
	face_left
	step_end

Route203_Movement_BarryApproachY19:
	walk_left
	walk_left
	walk_left
	walk_down
	face_left
	step_end

Route203_Movement_BarryApproachY20:
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	face_left
	step_end

Route203_Movement_BarryApproachY21:
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	face_left
	step_end

Route203_Movement_BarryJogsOff:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

Route203_Text_BarryGotTougher:
	.string "Hey! {PLAYER}!\n"
	.string "Tell me you got a little tougher!\p"
	.string "Me? Do you even need to ask?\n"
	.string "Of course I got tougher!\p"
	.string "Come on!\n"
	.string "Let's battle it out!$"

Route203_Text_BarryDefeated:
	.string "What just happened?\n"
	.string "I lost?!$"

Route203_Text_BarryVowsToBeToughest:
	.string "Waah!\n"
	.string "What do you mean I lost?!\p"
	.string "Well, that's it!\n"
	.string "That's the last time I'll ever lose!\p"
	.string "I'm going to be the world's\n"
	.string "toughest Trainer, and you know it!\p"
	.string "The first thing to do is take on\n"
	.string "the {COLOR DYNAMIC_COLOR3}Oreburgh City{COLOR DARK_GRAY} Pokémon Gym!\p"
	.string "I'm gonna toughen up for that,\n"
	.string "totally!$"
