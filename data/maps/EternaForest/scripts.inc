EternaForest_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, EternaForest_OnTransition
	.byte 0

EternaForest_EventScript_Trainer1::
	trainerbattle_single TRAINER_ETERNA_FOREST_1, EternaForest_Text_Trainer1Intro, EternaForest_Text_Trainer1Defeated
	msgbox EternaForest_Text_Trainer1PostBattle, MSGBOX_AUTOCLOSE
	end

EternaForest_Text_Trainer1Intro:
	.string "Here comes the swarm!$"

EternaForest_Text_Trainer1Defeated:
	.string "Whoooh...$"

EternaForest_Text_Trainer1PostBattle:
	.string "Did you know? “Swarm” is the name of a\n"
	.string "Pokémon ability.$"

EternaForest_EventScript_Trainer2::
	trainerbattle_single TRAINER_ETERNA_FOREST_2, EternaForest_Text_Trainer2Intro, EternaForest_Text_Trainer2Defeated
	msgbox EternaForest_Text_Trainer2PostBattle, MSGBOX_AUTOCLOSE
	end

EternaForest_Text_Trainer2Intro:
	.string "My senses tingle... I've spotted a rare\n"
	.string "Pokémon!$"

EternaForest_Text_Trainer2Defeated:
	.string "Awawawawah...$"

EternaForest_Text_Trainer2PostBattle:
	.string "I thought it was a rare Pokémon, but it\n"
	.string "turned out to be just a Trainer!$"

EternaForest_EventScript_Trainer3::
	trainerbattle_single TRAINER_ETERNA_FOREST_3, EternaForest_Text_Trainer3Intro, EternaForest_Text_Trainer3Defeated
	msgbox EternaForest_Text_Trainer3PostBattle, MSGBOX_AUTOCLOSE
	end

EternaForest_Text_Trainer3Intro:
	.string "A strange presence has been felt... It\n"
	.string "is emanating from...you!$"

EternaForest_Text_Trainer3Defeated:
	.string "Oh! Be one with me, my Meditite!$"

EternaForest_Text_Trainer3PostBattle:
	.string "The Old Chateau... I sense... a\n"
	.string "particularly strong presence there.$"

EternaForest_EventScript_Trainer4::
	trainerbattle_single TRAINER_ETERNA_FOREST_4, EternaForest_Text_Trainer4Intro, EternaForest_Text_Trainer4Defeated
	msgbox EternaForest_Text_Trainer4PostBattle, MSGBOX_AUTOCLOSE
	end

EternaForest_Text_Trainer4Intro:
	.string "This forest is strange, you know... It\n"
	.string "seems to fill me with energy...$"

EternaForest_Text_Trainer4Defeated:
	.string "Your victory... There is nothing strange\n"
	.string "about it.$"

EternaForest_Text_Trainer4PostBattle:
	.string "Forests are mystifying... They seem to\n"
	.string "gather such unexplainable energy.$"

EternaForest_EventScript_Trainer5::
	trainerbattle_single TRAINER_ETERNA_FOREST_5, EternaForest_Text_Trainer5Intro, EternaForest_Text_Trainer5Defeated
	msgbox EternaForest_Text_Trainer5PostBattle, MSGBOX_AUTOCLOSE
	end

EternaForest_Text_Trainer5Intro:
	.string "What's cool, you might ask? No? I'll tell\n"
	.string "you anyway: bug Pokémon!$"

EternaForest_Text_Trainer5Defeated:
	.string "It bugs me when people ignore the\n"
	.string "awesome coolness of bug Pokémon!$"

EternaForest_Text_Trainer5PostBattle:
	.string "It would seem that coolness alone\n"
	.string "doesn't add up to any wins...$"

EternaForest_EventScript_Trainer6::
	trainerbattle_single TRAINER_ETERNA_FOREST_6, EternaForest_Text_Trainer6Intro, EternaForest_Text_Trainer6Defeated
	msgbox EternaForest_Text_Trainer6PostBattle, MSGBOX_AUTOCLOSE
	end

EternaForest_Text_Trainer6Intro:
	.string "We're just out on a power walk!$"

EternaForest_Text_Trainer6Defeated:
	.string "Oh, you!$"

EternaForest_Text_Trainer6PostBattle:
	.string "Eewww, nasty! There are only bug\n"
	.string "Pokémon in the forest...\p"
	.string "I also forgot to buy some Antidotes.\n"
	.string "It's just the worst thing ever!$"

EternaForest_EventScript_Trainer7::
	trainerbattle_single TRAINER_ETERNA_FOREST_7, EternaForest_Text_Trainer7Intro, EternaForest_Text_Trainer7Defeated
	msgbox EternaForest_Text_Trainer7PostBattle, MSGBOX_AUTOCLOSE
	end

EternaForest_Text_Trainer7Intro:
	.string "I'm mostly here to catch some Pokémon,\n"
	.string "but I could use a battle!$"

EternaForest_Text_Trainer7Defeated:
	.string "This was supposed to be my warmup...$"

EternaForest_Text_Trainer7PostBattle:
	.string "I had to use all my Revives 'cuz of you!$"

EternaForest_EventScript_Trainer8::
	trainerbattle_single TRAINER_ETERNA_FOREST_8, EternaForest_Text_Trainer8Intro, EternaForest_Text_Trainer8Defeated
	msgbox EternaForest_Text_Trainer8PostBattle, MSGBOX_AUTOCLOSE
	end

EternaForest_Text_Trainer8Intro:
	.string "Buzzzzzzzz!!$"

EternaForest_Text_Trainer8Defeated:
	.string "Well alright then!$"

EternaForest_Text_Trainer8PostBattle:
	.string "I love how many Bug Pokémon you can\n"
	.string "hear in the trees.$"

EternaForest_EventScript_Trainer9::
	trainerbattle_single TRAINER_ETERNA_FOREST_9, EternaForest_Text_Trainer9Intro, EternaForest_Text_Trainer9Defeated
	msgbox EternaForest_Text_Trainer9PostBattle, MSGBOX_AUTOCLOSE
	end

EternaForest_Text_Trainer9Intro:
	.string "When a Trainer and a Pokémon bond as\n"
	.string "one, a wondrous power is born...$"

EternaForest_Text_Trainer9Defeated:
	.string "Hmm...$"

EternaForest_Text_Trainer9PostBattle:
	.string "There still remain many mysteries yet\n"
	.string "to be solved in this strange world...$"

EternaForest_EventScript_Trainer10::
	trainerbattle_single TRAINER_ETERNA_FOREST_10, EternaForest_Text_Trainer10Intro, EternaForest_Text_Trainer10Defeated
	msgbox EternaForest_Text_Trainer10PostBattle, MSGBOX_AUTOCLOSE
	end

EternaForest_Text_Trainer10Intro:
	.string "I see it... I see it...\p"
	.string "I see you going down in defeat...$"

EternaForest_Text_Trainer10Defeated:
	.string "It is I that has gone down in defeat.$"

EternaForest_Text_Trainer10PostBattle:
	.string "The Old Chateau...lies abandoned, with\n"
	.string "none living in its walls...\p"
	.string "And yet, and yet, there permeates a\n"
	.string "presence...$"

EternaForest_EventScript_NPC1::
	msgbox EternaForest_Text_NPC1, MSGBOX_NPC
	end

EternaForest_Text_NPC1:
	.string "My Pokémon got poisoned, and now it\n"
	.string "can't battle.\p"
	.string "I knew I should've loaded up on\n"
	.string "Antidotes at the Poké Mart!$"

EternaForest_EventScript_NPC2::
	msgbox EternaForest_Text_NPC2, MSGBOX_NPC
	end

EternaForest_Text_NPC2:
	.string "The rock is covered in moss. It feels\n"
	.string "pleasantly cool.$"

EternaForest_EventScript_Sign1::
	msgbox EternaForest_Text_Sign1, MSGBOX_SIGN
	end

EternaForest_Text_Sign1:
	.string "Eterna Forest Where Time Stands Still$"

EternaForest_EventScript_Tree1::
	lockall
	checkfieldmove FIELD_MOVE_CUT, TRUE
	goto_if_eq VAR_RESULT, PARTY_SIZE, EventScript_CheckTreeCantCut
	setfieldeffectargument 0, VAR_RESULT
	bufferpartymonnick STR_VAR_1, VAR_RESULT
	buffermovename STR_VAR_2, MOVE_CUT
	msgbox Text_WantToCut, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_CancelCut
	msgbox Text_MonUsedFieldMove, MSGBOX_DEFAULT
	closemessage
	isfollowerfieldmoveuser VAR_0x8004
	setfieldeffectargument 3, VAR_0x8004
	dofieldeffect FLDEFF_USE_CUT_ON_TREE
	waitstate
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	call_if_eq VAR_0x8004, TRUE, EventScript_FollowerFieldMove
	applymovement VAR_LAST_TALKED, Movement_CutTreeDown
	waitmovement 0
	removeobject VAR_LAST_TALKED
	setflag FLAG_HIDE_ETERNA_FOREST_TREE1
	releaseall
	end

EternaForest_EventScript_Tree2::
	lockall
	checkfieldmove FIELD_MOVE_CUT, TRUE
	goto_if_eq VAR_RESULT, PARTY_SIZE, EventScript_CheckTreeCantCut
	setfieldeffectargument 0, VAR_RESULT
	bufferpartymonnick STR_VAR_1, VAR_RESULT
	buffermovename STR_VAR_2, MOVE_CUT
	msgbox Text_WantToCut, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_CancelCut
	msgbox Text_MonUsedFieldMove, MSGBOX_DEFAULT
	closemessage
	isfollowerfieldmoveuser VAR_0x8004
	setfieldeffectargument 3, VAR_0x8004
	dofieldeffect FLDEFF_USE_CUT_ON_TREE
	waitstate
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	call_if_eq VAR_0x8004, TRUE, EventScript_FollowerFieldMove
	applymovement VAR_LAST_TALKED, Movement_CutTreeDown
	waitmovement 0
	removeobject VAR_LAST_TALKED
	setflag FLAG_HIDE_ETERNA_FOREST_TREE2
	releaseall
	end

EternaForest_EventScript_Tree3::
	lockall
	checkfieldmove FIELD_MOVE_CUT, TRUE
	goto_if_eq VAR_RESULT, PARTY_SIZE, EventScript_CheckTreeCantCut
	setfieldeffectargument 0, VAR_RESULT
	bufferpartymonnick STR_VAR_1, VAR_RESULT
	buffermovename STR_VAR_2, MOVE_CUT
	msgbox Text_WantToCut, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_CancelCut
	msgbox Text_MonUsedFieldMove, MSGBOX_DEFAULT
	closemessage
	isfollowerfieldmoveuser VAR_0x8004
	setfieldeffectargument 3, VAR_0x8004
	dofieldeffect FLDEFF_USE_CUT_ON_TREE
	waitstate
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	call_if_eq VAR_0x8004, TRUE, EventScript_FollowerFieldMove
	applymovement VAR_LAST_TALKED, Movement_CutTreeDown
	waitmovement 0
	removeobject VAR_LAST_TALKED
	setflag FLAG_HIDE_ETERNA_FOREST_TREE3
	releaseall
	end

EternaForest_EventScript_Sign2::
	msgbox EternaForest_Text_Sign2, MSGBOX_SIGN
	end

EternaForest_EventScript_NPC3::
	lockall
	faceplayer
	setspeaker SP_NAME_GARDENIA
	msgbox EternaForest_Text_NPC3, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ETERNA_FOREST_GARDENIA, EternaForest_Movement_Gardenia
	waitmovement 0
	msgbox EternaForest_Text_NPC3_2, MSGBOX_DEFAULT
	faceplayer
	msgbox EternaForest_Text_NPC3_3, MSGBOX_DEFAULT
	closemessage
	copyvar VAR_RESULT, VAR_FACING
	goto_if_eq VAR_RESULT, DIR_NORTH, EternaForest_EventScript_NPC3_2
	goto_if_eq VAR_RESULT, DIR_SOUTH, EternaForest_EventScript_NPC3_2_2
	goto_if_eq VAR_RESULT, DIR_WEST, EternaForest_EventScript_NPC3_2_3
	goto_if_eq VAR_RESULT, DIR_EAST, EternaForest_EventScript_NPC3_2_4
	end

EternaForest_EventScript_NPC3_2::
	applymovement LOCALID_ETERNA_FOREST_GARDENIA, EternaForest_Movement_Gardenia2
	waitmovement 0
	goto EternaForest_EventScript_NPC3_2_5

EternaForest_EventScript_NPC3_2_2::
	applymovement LOCALID_ETERNA_FOREST_GARDENIA, EternaForest_Movement_Gardenia3
	waitmovement 0
	goto EternaForest_EventScript_NPC3_2_5

EternaForest_EventScript_NPC3_2_3::
	applymovement LOCALID_ETERNA_FOREST_GARDENIA, EternaForest_Movement_Gardenia3
	waitmovement 0
	goto EternaForest_EventScript_NPC3_2_5

EternaForest_EventScript_NPC3_2_4::
	applymovement LOCALID_ETERNA_FOREST_GARDENIA, EternaForest_Movement_Gardenia3
	waitmovement 0
	goto EternaForest_EventScript_NPC3_2_5

EternaForest_EventScript_NPC3_2_5::
	removeobject LOCALID_ETERNA_FOREST_GARDENIA
	releaseall
	end

EternaForest_EventScript_Trigger1::
	lockall
	@ TODO(DP): RideBike 0
	getplayerxy VAR_0x8004, VAR_0x8005
	goto_if_eq VAR_0x8004, 28, EternaForest_EventScript_Trigger1_2
	goto_if_eq VAR_0x8004, 29, EternaForest_EventScript_Trigger1_2_2
	end

EternaForest_EventScript_Trigger1_2::
	playse SE_PIN
	applymovement LOCALID_ETERNA_FOREST_NPC, EternaForest_Movement_Npc
	waitmovement 0
	goto EternaForest_EventScript_Trigger1_2_3

EternaForest_EventScript_Trigger1_2_2::
	playse SE_PIN
	applymovement LOCALID_ETERNA_FOREST_NPC, EternaForest_Movement_Npc2
	waitmovement 0
	goto EternaForest_EventScript_Trigger1_2_3

EternaForest_EventScript_Trigger1_2_3::
	call_if_unset FLAG_ETERNA_FOREST_TRIGGER_1, EternaForest_EventScript_Trigger1_2_4
	call_if_set FLAG_ETERNA_FOREST_TRIGGER_1, EternaForest_EventScript_Trigger1_2_5
	@ TODO(DP): fanfare SEQ_GONIN
	message EternaForest_Text_Trigger1
	waitmessage
	waitfanfare
	setflag FLAG_ETERNA_FOREST_TRIGGER_1
	setvar VAR_ETERNA_FOREST_STATE, 1
	setspeaker EternaForest_Text_CherylSpeaker
	msgbox EternaForest_Text_Trigger1_2, MSGBOX_DEFAULT
	closemessage
	setvar VAR_ETERNA_FOREST_STATE_2, 608
	@ TODO(DP): StartFollow
	@ TODO(DP): SetEventMovement 0, 48
	@ TODO(DP): KeepEvent 0, 1
	releaseall
	end

EternaForest_EventScript_Trigger1_2_4::
	msgbox EternaForest_Text_Trigger1_3, MSGBOX_DEFAULT
	return

EternaForest_EventScript_Trigger1_2_5::
	setspeaker EternaForest_Text_CherylSpeaker
	msgbox EternaForest_Text_Trigger1_4, MSGBOX_DEFAULT
	return

EternaForest_EventScript_Trigger2::
	lockall
	@ TODO(DP): StopFollow
	@ TODO(DP): SetEventMovement 0, 15
	@ TODO(DP): KeepEvent 0, 0
	applymovement LOCALID_ETERNA_FOREST_NPC, EternaForest_Movement_Npc3
	waitmovement 0
	setspeaker EternaForest_Text_CherylSpeaker
	msgbox EternaForest_Text_Trigger2, MSGBOX_DEFAULT
	closemessage
	getplayerxy VAR_0x8004, VAR_0x8005
	goto_if_eq VAR_0x8004, 28, EternaForest_EventScript_Trigger2_2
	goto_if_eq VAR_0x8004, 29, EternaForest_EventScript_Trigger2_2_2
	end

EternaForest_EventScript_Trigger2_2::
	applymovement LOCALID_ETERNA_FOREST_NPC, EternaForest_Movement_Npc4
	waitmovement 0
	goto EternaForest_EventScript_Trigger2_2_3

EternaForest_EventScript_Trigger2_2_2::
	applymovement LOCALID_ETERNA_FOREST_NPC, EternaForest_Movement_Npc5
	waitmovement 0
	goto EternaForest_EventScript_Trigger2_2_3

EternaForest_EventScript_Trigger2_2_3::
	setvar VAR_ETERNA_FOREST_STATE, 0
	releaseall
	end

EternaForest_EventScript_Trigger3::
	lockall
	playse SE_PIN
	applymovement LOCALID_ETERNA_FOREST_NPC, EternaForest_Movement_Npc6
	applymovement LOCALID_PLAYER, EternaForest_Movement_Player
	waitmovement 0
	setspeaker EternaForest_Text_CherylSpeaker
	msgbox EternaForest_Text_Trigger3, MSGBOX_DEFAULT
	closemessage
	getplayerxy VAR_0x8004, VAR_0x8005
	goto_if_eq VAR_0x8005, 34, EternaForest_EventScript_Trigger3_2
	goto_if_eq VAR_0x8005, 35, EternaForest_EventScript_Trigger3_2_2
	goto_if_eq VAR_0x8005, 36, EternaForest_EventScript_Trigger3_2_3
	goto_if_eq VAR_0x8005, 37, EternaForest_EventScript_Trigger3_2_4
	goto_if_eq VAR_0x8005, 38, EternaForest_EventScript_Trigger3_2_5
	goto EternaForest_EventScript_Trigger3_2_6

EternaForest_EventScript_Trigger3_2::
	applymovement LOCALID_ETERNA_FOREST_NPC, EternaForest_Movement_Npc7
	applymovement LOCALID_PLAYER, EternaForest_Movement_Player2
	waitmovement 0
	goto EternaForest_EventScript_Trigger3_2_7

EternaForest_EventScript_Trigger3_2_2::
	applymovement LOCALID_ETERNA_FOREST_NPC, EternaForest_Movement_Npc8
	applymovement LOCALID_PLAYER, EternaForest_Movement_Player3
	waitmovement 0
	goto EternaForest_EventScript_Trigger3_2_7

EternaForest_EventScript_Trigger3_2_3::
	applymovement LOCALID_ETERNA_FOREST_NPC, EternaForest_Movement_Npc8
	applymovement LOCALID_PLAYER, EternaForest_Movement_Player3
	waitmovement 0
	goto EternaForest_EventScript_Trigger3_2_7

EternaForest_EventScript_Trigger3_2_4::
	applymovement LOCALID_ETERNA_FOREST_NPC, EternaForest_Movement_Npc9
	applymovement LOCALID_PLAYER, EternaForest_Movement_Player4
	waitmovement 0
	goto EternaForest_EventScript_Trigger3_2_7

EternaForest_EventScript_Trigger3_2_5::
	applymovement LOCALID_ETERNA_FOREST_NPC, EternaForest_Movement_Npc9
	applymovement LOCALID_PLAYER, EternaForest_Movement_Player4
	waitmovement 0
	goto EternaForest_EventScript_Trigger3_2_7

EternaForest_EventScript_Trigger3_2_6::
	applymovement LOCALID_ETERNA_FOREST_NPC, EternaForest_Movement_Npc10
	applymovement LOCALID_PLAYER, EternaForest_Movement_Player5
	waitmovement 0
	goto EternaForest_EventScript_Trigger3_2_7

EternaForest_EventScript_Trigger3_2_7::
	playse SE_EXIT
	@ TODO(DP): StopFollow
	removeobject LOCALID_ETERNA_FOREST_NPC
	waitse
	setflag FLAG_ETERNA_FOREST_TRIGGER_2
	setvar VAR_ETERNA_FOREST_STATE, 2
	releaseall
	end

EternaForest_OnTransition::
	goto_if_unset FLAG_ETERNA_FOREST_TRIGGER_2, EternaForest_OnTransition_2
	end

EternaForest_OnTransition_2::
	setvar VAR_ETERNA_FOREST_STATE, 0
	end

EternaForest_Movement_Gardenia:
	walk_in_place_up
	step_end

EternaForest_Movement_Gardenia2:
	walk_left
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

EternaForest_Movement_Gardenia3:
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

EternaForest_Movement_Npc:
	emote_exclamation_mark
	walk_down
	step_end

EternaForest_Movement_Npc2:
	emote_exclamation_mark
	walk_down
	walk_right
	walk_in_place_down
	step_end

EternaForest_Movement_Npc3:
	walk_in_place_down
	step_end

EternaForest_Movement_Npc4:
	walk_up
	walk_up
	walk_in_place_down
	step_end

EternaForest_Movement_Npc5:
	walk_up
	walk_up
	walk_left
	walk_in_place_down
	step_end

EternaForest_Movement_Npc6:
	walk_in_place_right
	emote_exclamation_mark
	step_end

EternaForest_Movement_Player:
	delay_16
	delay_16
	delay_16
	walk_in_place_left
	step_end

EternaForest_Movement_Npc7:
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_right
	step_end

EternaForest_Movement_Player2:
	delay_16
	delay_16
	walk_in_place_down
	delay_16
	walk_in_place_right
	step_end

EternaForest_Movement_Npc8:
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_right
	step_end

EternaForest_Movement_Player3:
	delay_16
	walk_in_place_down
	delay_16
	walk_in_place_right
	step_end

EternaForest_Movement_Npc9:
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_right
	step_end

EternaForest_Movement_Player4:
	delay_16
	walk_in_place_up
	delay_16
	walk_in_place_right
	step_end

EternaForest_Movement_Npc10:
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_right
	step_end

EternaForest_Movement_Player5:
	delay_16
	delay_16
	walk_in_place_up
	delay_16
	walk_in_place_right
	step_end

EternaForest_Text_Sign2:
	.string "Trainer Tips!\p"
	.string "In forests and caves, there are many\n"
	.string "items on the ground that cannot be\l"
	.string "seen in the murky darkness.\p"
	.string "Take the time to search carefully!$"

EternaForest_Text_NPC3:
	.string "Hiya! Were you intrigued by the rumors\n"
	.string "going around, too?$"

EternaForest_Text_NPC3_2:
	.string "You know, people've been talking about\n"
	.string "the ghost Pokémon of the Old Chateau.\p"
	.string "I've been hearing rumors about sinister\n"
	.string "shadows, too.$"

EternaForest_Text_NPC3_3:
	.string "I should check it out myself, but going\n"
	.string "in there is...\p"
	.string "...Well, you know, being that I'm a Gym\n"
	.string "Leader, I'm always busy.\p"
	.string "So, since I'm so busy, I can't go in. It's\n"
	.string "not because I'm s-scared!\p"
	.string "S-so, good luck with your\n"
	.string "investigation!$"

EternaForest_Text_Trigger1:
	.string "{PLAYER} decided to go with Cheryl!$"

EternaForest_Text_Trigger1_2:
	.string "I'll keep your Pokémon in perfect\n"
	.string "health.$"

EternaForest_Text_Trigger1_3:
	.string "Hello, my name's Cheryl. And you are...?\p"
	.string "OK, so your name is {PLAYER}. I'm\n"
	.string "sincerely glad to meet you.\p"
	.string "{PLAYER}, may I ask a big favor of you?\p"
	.string "I want to get through this forest, but\n"
	.string "I'm afraid of doing it alone.\p"
	.string "I've heard that there is a sinister\n"
	.string "group of people called Team Galactic\l"
	.string "about.\p"
	.string "I think there'd be safety in numbers.\n"
	.string "Please, may I go through with you?$"

EternaForest_Text_Trigger1_4:
	.string "Oh, hi, {PLAYER}! I've been waiting like I\n"
	.string "said.\p"
	.string "Let's get through this forest together.$"

EternaForest_Text_Trigger2:
	.string "Oh? Are you going back? I'll wait here\n"
	.string "for you, then.$"

EternaForest_Text_Trigger3:
	.string "Oh! There's the exit! I'm so relieved...\n"
	.string "We finally got here.\p"
	.string "I would've never been able to get\n"
	.string "through this by myself.\p"
	.string "Thank you so much, {PLAYER}!$"

EternaForest_Text_CherylSpeaker:
	.string "Cheryl$"
