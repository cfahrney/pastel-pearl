EternaCity_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, EternaCity_Gym_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, EternaCity_Gym_OnLoad
	.byte 0

EternaCity_Gym_EventScript_NPC1::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ROSERADE, CRY_MODE_NORMAL
	setspeaker EternaCity_Gym_Text_NPC1Speaker
	msgbox EternaCity_Gym_Text_NPC1, MSGBOX_DEFAULT
	waitmoncry
	release
	end

EternaCity_Gym_Text_NPC1Speaker:
	.string "Roserade$"

EternaCity_Gym_Text_NPC1:
	.string "GYM NPC 1$"

EternaCity_Gym_EventScript_Trainer6::
	trainerbattle_single TRAINER_ETERNA_CITY_GYM_6, EternaCity_Gym_Text_Trainer6Intro, EternaCity_Gym_Text_Trainer6Defeated
	msgbox EternaCity_Gym_Text_Trainer6PostBattle, MSGBOX_AUTOCLOSE
	end

EternaCity_Gym_Text_Trainer6Intro:
	.string "GYM TRAINER 6$"

EternaCity_Gym_Text_Trainer6Defeated:
	.string "GYM TRAINER 6$"

EternaCity_Gym_Text_Trainer6PostBattle:
	.string "GYM TRAINER 6$"

EternaCity_Gym_EventScript_NPC2::
	lock
	faceplayer
	goto_if_set FLAG_BADGE02_GET, EternaCity_Gym_EventScript_NPC2_2
	@ TODO(DP): DeActivateLeader 9, 68, 0, 0, 0
	msgbox EternaCity_Gym_Text_NPC2, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_ETERNA_CITY_GYM_5, EternaCity_Gym_Text_NPC2Defeated
	msgbox EternaCity_Gym_Text_NPC2_2, MSGBOX_DEFAULT
	message EternaCity_Gym_Text_NPC2_3
	waitmessage
	playfanfare MUS_OBTAIN_BADGE
	waitfanfare
	setflag FLAG_BADGE02_GET
	@ TODO(DP): AddSpecialGameStat 23
	settrainerflag TRAINER_ETERNA_CITY_GYM_4
	settrainerflag TRAINER_ETERNA_CITY_GYM_1
	settrainerflag TRAINER_ETERNA_CITY_GYM_3
	settrainerflag TRAINER_ETERNA_CITY_GYM_2
	@ TODO(DP): DeActivateLeader 10, 68, 315, 0, 0
	clearflag FLAG_ETERNA_CITY_GYM_GARDENIA_1
	msgbox EternaCity_Gym_Text_NPC2_4, MSGBOX_DEFAULT
	goto EternaCity_Gym_EventScript_NPC2_2_3

EternaCity_Gym_EventScript_NPC2_2::
	goto_if_unset FLAG_ETERNA_CITY_GYM_GARDENIA_2, EternaCity_Gym_EventScript_NPC2_2_3
	msgbox EternaCity_Gym_Text_NPC2_5, MSGBOX_DEFAULT
	closemessage
	release
	end

EternaCity_Gym_EventScript_NPC2_2_2::
	release
	end

EternaCity_Gym_EventScript_NPC2_2_3::
	setvar VAR_0x8004, ITEM_TM_GRASS_KNOT
	setvar VAR_0x8005, 1
	checkitemspace VAR_0x8004, VAR_0x8005
	goto_if_eq VAR_RESULT, FALSE, EternaCity_Gym_EventScript_NPC2_2_4
	giveitem VAR_0x8004, VAR_0x8005
	setflag FLAG_ETERNA_CITY_GYM_GARDENIA_2
	bufferitemname STR_VAR_1, VAR_0x8004
	@ TODO(DP): move name into STR_VAR_2
	msgbox EternaCity_Gym_Text_NPC2_6, MSGBOX_DEFAULT
	closemessage
	release
	end

EternaCity_Gym_EventScript_NPC2_2_4::
	msgbox gText_TooBadBagIsFull, MSGBOX_DEFAULT
	closemessage
	release
	end

EternaCity_Gym_EventScript_NPC3::
	lock
	faceplayer
	goto_if_ge VAR_ETERNA_CITY_GYM_STATE, 2, EternaCity_Gym_EventScript_NPC3_2
	setvar VAR_0x8007, 1
	call EternaCity_Gym_EventScript_NPC3_2_2
	msgbox EternaCity_Gym_Text_NPC3, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_ETERNA_CITY_GYM_4, EternaCity_Gym_Text_NPC3Defeated
	clearflag FLAG_HIDE_ETERNA_CITY_GYM_WOMAN_2
	clearflag FLAG_HIDE_ETERNA_CITY_GYM_WOMAN_2
	addobject LOCALID_ETERNA_CITY_GYM_WOMAN_2
	msgbox EternaCity_Gym_Text_NPC3_2, MSGBOX_DEFAULT
	setvar VAR_ETERNA_CITY_GYM_STATE, 2
	closemessage
	release
	end

EternaCity_Gym_EventScript_NPC3_2::
	msgbox EternaCity_Gym_Text_NPC3_2, MSGBOX_DEFAULT
	closemessage
	release
	end

EternaCity_Gym_EventScript_NPC3_2_2::
	copyvar VAR_RESULT, VAR_FACING
	call_if_eq VAR_RESULT, DIR_NORTH, EternaCity_Gym_EventScript_NPC3_2_3
	call_if_eq VAR_RESULT, DIR_SOUTH, EternaCity_Gym_EventScript_NPC3_2_4
	call_if_eq VAR_RESULT, DIR_WEST, EternaCity_Gym_EventScript_NPC3_2_5
	call_if_eq VAR_RESULT, DIR_EAST, EternaCity_Gym_EventScript_NPC3_2_6
	return

EternaCity_Gym_EventScript_NPC3_2_3::
	@ TODO(DP): turn DP object 32775
	@ TODO(DP): turn DP object 32775
	return

EternaCity_Gym_EventScript_NPC3_2_4::
	@ TODO(DP): turn DP object 32775
	@ TODO(DP): turn DP object 32775
	return

EternaCity_Gym_EventScript_NPC3_2_5::
	@ TODO(DP): turn DP object 32775
	@ TODO(DP): turn DP object 32775
	return

EternaCity_Gym_EventScript_NPC3_2_6::
	@ TODO(DP): turn DP object 32775
	@ TODO(DP): turn DP object 32775
	return

EternaCity_Gym_EventScript_NPC4::
	lock
	faceplayer
	goto_if_ge VAR_ETERNA_CITY_GYM_STATE, 3, EternaCity_Gym_EventScript_NPC4_2
	setvar VAR_0x8007, 2
	call EternaCity_Gym_EventScript_NPC3_2_2
	msgbox EternaCity_Gym_Text_NPC4, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_ETERNA_CITY_GYM_1, EternaCity_Gym_Text_NPC4Defeated
	clearflag FLAG_HIDE_ETERNA_CITY_GYM_WOMAN_3
	clearflag FLAG_HIDE_ETERNA_CITY_GYM_WOMAN_3
	addobject LOCALID_ETERNA_CITY_GYM_WOMAN_3
	msgbox EternaCity_Gym_Text_NPC4_2, MSGBOX_DEFAULT
	setvar VAR_ETERNA_CITY_GYM_STATE, 3
	closemessage
	release
	end

EternaCity_Gym_EventScript_NPC4_2::
	msgbox EternaCity_Gym_Text_NPC4_2, MSGBOX_DEFAULT
	closemessage
	release
	end

EternaCity_Gym_EventScript_NPC5::
	lock
	faceplayer
	goto_if_ge VAR_ETERNA_CITY_GYM_STATE, 4, EternaCity_Gym_EventScript_NPC5_2
	setvar VAR_0x8007, 3
	call EternaCity_Gym_EventScript_NPC3_2_2
	msgbox EternaCity_Gym_Text_NPC5, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_VALLEY_WINDWORKS_EVENT_1
	trainerbattle_no_intro TRAINER_ETERNA_CITY_GYM_2, EternaCity_Gym_Text_NPC5Defeated
	clearflag FLAG_VALLEY_WINDWORKS_EVENT_1
	msgbox EternaCity_Gym_Text_NPC5_2, MSGBOX_DEFAULT
	setvar VAR_ETERNA_CITY_GYM_STATE, 4
	closemessage
	release
	end

EternaCity_Gym_EventScript_NPC5_2::
	msgbox EternaCity_Gym_Text_NPC5_2, MSGBOX_DEFAULT
	closemessage
	release
	end

EternaCity_Gym_EventScript_NPC6::
	lock
	faceplayer
	goto_if_ge VAR_ETERNA_CITY_GYM_STATE, 1, EternaCity_Gym_EventScript_NPC6_2
	msgbox EternaCity_Gym_Text_NPC6, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_ETERNA_CITY_GYM_3, EternaCity_Gym_Text_NPC6Defeated
	msgbox EternaCity_Gym_Text_NPC6_2, MSGBOX_DEFAULT
	setvar VAR_ETERNA_CITY_GYM_STATE, 1
	clearflag FLAG_HIDE_ETERNA_CITY_GYM_WOMAN
	clearflag FLAG_HIDE_ETERNA_CITY_GYM_WOMAN
	addobject LOCALID_ETERNA_CITY_GYM_WOMAN
	closemessage
	release
	end

EternaCity_Gym_EventScript_NPC6_2::
	msgbox EternaCity_Gym_Text_NPC6_2, MSGBOX_DEFAULT
	closemessage
	release
	end

EternaCity_Gym_OnTransition::
	goto_if_eq VAR_ETERNA_CITY_GYM_STATE, 3, EternaCity_Gym_OnTransition_2
	goto_if_eq VAR_ETERNA_CITY_GYM_STATE, 2, EternaCity_Gym_OnTransition_2_2
	goto_if_eq VAR_ETERNA_CITY_GYM_STATE, 1, EternaCity_Gym_OnTransition_2_3
	goto_if_eq VAR_ETERNA_CITY_GYM_STATE, 0, EternaCity_Gym_OnTransition_2_4
	end

EternaCity_Gym_OnTransition_2::
	setflag FLAG_HIDE_ETERNA_CITY_GYM_GARDENIA
	end

EternaCity_Gym_OnTransition_2_2::
	setflag FLAG_HIDE_ETERNA_CITY_GYM_WOMAN_3
	setflag FLAG_HIDE_ETERNA_CITY_GYM_GARDENIA
	end

EternaCity_Gym_OnTransition_2_3::
	setflag FLAG_HIDE_ETERNA_CITY_GYM_WOMAN_2
	setflag FLAG_HIDE_ETERNA_CITY_GYM_WOMAN_3
	setflag FLAG_HIDE_ETERNA_CITY_GYM_GARDENIA
	end

EternaCity_Gym_OnTransition_2_4::
	setflag FLAG_HIDE_ETERNA_CITY_GYM_WOMAN
	setflag FLAG_HIDE_ETERNA_CITY_GYM_WOMAN_2
	setflag FLAG_HIDE_ETERNA_CITY_GYM_WOMAN_3
	setflag FLAG_HIDE_ETERNA_CITY_GYM_GARDENIA
	end

EternaCity_Gym_OnLoad::
	goto_if_set FLAG_VALLEY_WINDWORKS_EVENT_1, EternaCity_Gym_OnLoad_2
	end

EternaCity_Gym_OnLoad_2::
	clearflag FLAG_HIDE_ETERNA_CITY_GYM_GARDENIA
	clearflag FLAG_HIDE_ETERNA_CITY_GYM_GARDENIA
	addobject LOCALID_ETERNA_CITY_GYM_GARDENIA
	clearflag FLAG_VALLEY_WINDWORKS_EVENT_1
	end

EternaCity_Gym_Text_NPC2:
	.string "You kept me waiting!\p"
	.string "I'm Eterna's Gym Leader, Gardenia, the\n"
	.string "Grass-type master!\p"
	.string "When I first saw you, I was convinced\n"
	.string "you'd find your way to me.\p"
	.string "My hunch was right on the money. You\n"
	.string "have a winning aura about you.\p"
	.string "So, anyway, this will be fun. Let's have\n"
	.string "our battle!$"

EternaCity_Gym_Text_NPC2Defeated:
	.string "Amazing! You're very good, aren't you?$"

EternaCity_Gym_Text_NPC2_2:
	.string "I might've said it before, but you're\n"
	.string "really tough!\p"
	.string "Wasn't it hard for you to raise your\n"
	.string "Pokémon to be so good?\p"
	.string "I guess that's a measure of how much\n"
	.string "you love your Pokémon.\p"
	.string "In recognition of that, I proudly grant\n"
	.string "you this!$"

EternaCity_Gym_Text_NPC2_3:
	.string "{PLAYER} received the Forest Badge from\n"
	.string "Gardenia!$"

EternaCity_Gym_Text_NPC2_4:
	.string "With the Forest Badge, your Pokémon\n"
	.string "can use the hidden move Cut outside of\l"
	.string "battle.\p"
	.string "Now that you have two Gym Badges, all\n"
	.string "Pokémon you received in trades will\l"
	.string "obey you up to Lv. 30.\p"
	.string "I've also got something else. It's a gift\n"
	.string "from me!$"

EternaCity_Gym_Text_NPC2_5:
	.string "Yup! If there's one thing I can tell\n"
	.string "about you, it's this!\p"
	.string "You and your Pokémon are gonna get\n"
	.string "even tougher, and I mean seriously!$"

EternaCity_Gym_Text_NPC2_6:
	.string "That {STR_VAR_1} contains the move\n"
	.string "{STR_VAR_2}.\p"
	.string "It's one of my favorite moves.\p"
	.string "The heavier the foe, the more damage\n"
	.string "this move will cause.$"

EternaCity_Gym_Text_NPC3:
	.string "My Grass-type Pokémon can dole out\n"
	.string "some serious special attacks...\p"
	.string "I won't let you win...easily!$"

EternaCity_Gym_Text_NPC3Defeated:
	.string "The more beautiful a flower, the faster\n"
	.string "it withers...$"

EternaCity_Gym_Text_NPC3_2:
	.string "Oh, that's right... A hint about the next\n"
	.string "Trainer...\p"
	.string "In the middle of three trees. That's it\n"
	.string "for my hint. Good luck.$"

EternaCity_Gym_Text_NPC4:
	.string "Even when you try to conceal it, you\n"
	.string "can't hide the aroma of flowers.$"

EternaCity_Gym_Text_NPC4Defeated:
	.string "Just like your inability to conceal your\n"
	.string "abundant skill.$"

EternaCity_Gym_Text_NPC4_2:
	.string "Your next opponent is beside four\n"
	.string "flowers.$"

EternaCity_Gym_Text_NPC5:
	.string "Giggle! You found me! Of course I'll\n"
	.string "battle you!$"

EternaCity_Gym_Text_NPC5Defeated:
	.string "Aww, boo! Look, you've beaten me!$"

EternaCity_Gym_Text_NPC5_2:
	.string "Giggle! There's only our Gym Leader\n"
	.string "left. Go on, don't be afraid!$"

EternaCity_Gym_Text_NPC6:
	.string "How did you know where to find me? Let's\n"
	.string "have our battle!$"

EternaCity_Gym_Text_NPC6Defeated:
	.string "I was going to beat you while you were\n"
	.string "still in a state of shock...$"

EternaCity_Gym_Text_NPC6_2:
	.string "OK, the next Trainer is at the end, past\n"
	.string "the two boulders...I think.$"
