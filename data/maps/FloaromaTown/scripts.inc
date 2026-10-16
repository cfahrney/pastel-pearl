FloaromaTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FloaromaTown_OnTransition
	.byte 0

FloaromaTown_EventScript_NPC1::
	msgbox FloaromaTown_Text_NPC1, MSGBOX_NPC
	end

FloaromaTown_Text_NPC1:
	.string "The Berries you pick can be used as\n"
	.string "food for Pokémon.\p"
	.string "You can also exchange them at the\n"
	.string "florist's for Accessories to\p"
	.string "dress up your Pokémon.$"

FloaromaTown_EventScript_NPC2::
	msgbox FloaromaTown_Text_NPC2, MSGBOX_NPC
	end

FloaromaTown_Text_NPC2:
	.string "I simply love it here... The atmosphere\n"
	.string "is so uplifting.\p"
	.string "You came to get emotionally healed too,\n"
	.string "didn't you?$"

FloaromaTown_EventScript_NPC3::
	msgbox FloaromaTown_Text_NPC3, MSGBOX_NPC
	end

FloaromaTown_Text_NPC3:
	.string "I got drawn here by the sweet scent of\n"
	.string "Honey...\p"
	.string "Seriously, what's that? What am I? A\n"
	.string "Pokémon or something? Mmm... Honey.$"

FloaromaTown_EventScript_NPC4::
	@ poe:behavior {"mode":"trade","want":"SPECIES_MEOWTH","give":"SPECIES_MEOWTH_ALOLA","nickname":"Nanu","otName":"Elio","otGender":"MALE","heldItem":"ITEM_NONE"}
	lock
	faceplayer
	goto_if_set FLAG_FLOAROMATOWN_NPC4_TRADED, FloaromaTown_EventScript_NPC4After
	ingame_trade INGAME_TRADE_FLOAROMATOWN_NPC4, FloaromaTown_Text_NPC4, FloaromaTown_EventScript_NPC4Decline, FloaromaTown_EventScript_NPC4Wrong, FloaromaTown_Text_NPC4Received
	setflag FLAG_FLOAROMATOWN_NPC4_TRADED
	release
	end

FloaromaTown_EventScript_NPC4Decline::
	msgbox FloaromaTown_Text_NPC4Decline, MSGBOX_DEFAULT
	release
	end

FloaromaTown_EventScript_NPC4Wrong::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox FloaromaTown_Text_NPC4Wrong, MSGBOX_DEFAULT
	release
	end

FloaromaTown_EventScript_NPC4After::
	msgbox FloaromaTown_Text_NPC4After, MSGBOX_DEFAULT
	release
	end

FloaromaTown_Text_NPC4Decline::
	.string "Dang. Oh well, then.$"

FloaromaTown_Text_NPC4Wrong::
	.string "Uhh, that's not a {STR_VAR_1}. You could\n"
	.string "hav just said no, you know.$"

FloaromaTown_Text_NPC4Received::
	.string "This is so cool!! Thank you so much, I\n"
	.string "think {STR_VAR_1} is just the cutest!$"

FloaromaTown_Text_NPC4After::
	.string "Hi again, trade pal! You know, like a pen\n"
	.string "pal.. or, uh, I don't know. It made sense\l"
	.string "in my head.$"

FloaromaTown_Text_NPC4:
	.string "Hi! Any chance you wouldn't happen to\n"
	.string "have a {STR_VAR_1}, would you? I'd love\l"
	.string "to trade yours for my {STR_VAR_2}, here,\l"
	.string "if you do!$"

FloaromaTown_EventScript_NPC5::
	msgbox FloaromaTown_Text_NPC5, MSGBOX_NPC
	end

FloaromaTown_Text_NPC5:
	.string "Welcome to {COLOR DYNAMIC_COLOR3}Floaroma{COLOR DARK_GRAY}, the town of\n"
	.string "flowers, flowers, and more flowers!\p"
	.string "You should plant some flowers of your\n"
	.string "own, too. Yay for flowers!$"

FloaromaTown_EventScript_NPC6::
	@ poe:behavior {"mode":"tradeMon","trade":"INGAME_TRADE_FLOAROMATOWN_NPC4"}
	lock
	faceplayer
	setvar VAR_0x8005, INGAME_TRADE_FLOAROMATOWN_NPC4
	special BufferTradedMon
	goto_if_ne VAR_RESULT, SPECIES_NONE, FloaromaTown_EventScript_NPC6Traded
	waitse
	playmoncry SPECIES_MEOWTH_ALOLA, CRY_MODE_NORMAL
	setspeaker FloaromaTown_Text_NPC6Speaker
	msgbox FloaromaTown_Text_NPC6, MSGBOX_DEFAULT
	waitmoncry
	release
	end

FloaromaTown_EventScript_NPC6Traded::
	waitse
	playmoncry VAR_RESULT, CRY_MODE_NORMAL
	setspeaker SP_NAME_TRADED_MON
	msgbox FloaromaTown_Text_NPC6Traded, MSGBOX_DEFAULT
	waitmoncry
	release
	end

FloaromaTown_Text_NPC6Traded:
	.string "Mew!!$"

FloaromaTown_Text_NPC6Speaker:
	.string "Meowth$"

FloaromaTown_Text_NPC6:
	.string "Meeeeeowth!$"

FloaromaTown_EventScript_Sign1::
	msgbox FloaromaTown_Text_Sign1, MSGBOX_SIGN
	end

FloaromaTown_Text_Sign1:
	.string "Floaroma Town Vivid & Scented$"

FloaromaTown_EventScript_Sign2::
	msgbox FloaromaTown_Text_Sign2, MSGBOX_SIGN
	end

FloaromaTown_Text_Sign2:
	.string "Pick a Peck of Colors Flower Shop Free\n"
	.string "Berries Available$"

FloaromaTown_EventScript_Sign3::
	msgbox FloaromaTown_Text_Sign3, MSGBOX_SIGN
	end

FloaromaTown_Text_Sign3:
	.string "Floaroma Meadow Ahead Honey Available$"

FloaromaTown_EventScript_NPC7::
	lockall
	applymovement LOCALID_FLOAROMA_TOWN_GALACTIC_GRUNT, FloaromaTown_Movement_GalacticGrunt
	waitmovement 0
	setspeaker FloaromaTown_Text_Grunt1Speaker
	msgbox FloaromaTown_Text_NPC7, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_FLOAROMA_TOWN_GALACTIC_GRUNT_2, FloaromaTown_Movement_GalacticGrunt2
	waitmovement 0
	setspeaker FloaromaTown_Text_Grunt2Speaker
	msgbox FloaromaTown_Text_NPC7_2, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

FloaromaTown_EventScript_NPC8::
	goto FloaromaTown_EventScript_NPC7
	end

FloaromaTown_EventScript_Trigger1::
	lockall
	getplayerxy VAR_0x8004, VAR_0x8005
	goto_if_eq VAR_0x8004, 10, FloaromaTown_EventScript_Trigger1_2
	goto_if_eq VAR_0x8004, 11, FloaromaTown_EventScript_Trigger1_2_2
	goto_if_eq VAR_0x8004, 12, FloaromaTown_EventScript_Trigger1_2_3
	end

FloaromaTown_EventScript_Trigger1_2::
	applymovement LOCALID_FLOAROMA_TOWN_CYRUS, FloaromaTown_Movement_Cyrus
	waitmovement 0
	goto FloaromaTown_EventScript_Trigger1_2_4

FloaromaTown_EventScript_Trigger1_2_2::
	applymovement LOCALID_FLOAROMA_TOWN_CYRUS, FloaromaTown_Movement_Cyrus2
	waitmovement 0
	goto FloaromaTown_EventScript_Trigger1_2_4

FloaromaTown_EventScript_Trigger1_2_3::
	applymovement LOCALID_FLOAROMA_TOWN_CYRUS, FloaromaTown_Movement_Cyrus3
	waitmovement 0
	goto FloaromaTown_EventScript_Trigger1_2_4

FloaromaTown_EventScript_Trigger1_2_4::
	msgbox FloaromaTown_Text_Trigger1, MSGBOX_DEFAULT
	message FloaromaTown_Text_Trigger1_2
	waitmessage
	closemessage
	getplayerxy VAR_0x8004, VAR_0x8005
	goto_if_eq VAR_0x8004, 10, FloaromaTown_EventScript_Trigger1_2_5
	goto_if_eq VAR_0x8004, 11, FloaromaTown_EventScript_Trigger1_2_6
	goto_if_eq VAR_0x8004, 12, FloaromaTown_EventScript_Trigger1_2_7
	end

FloaromaTown_EventScript_Trigger1_2_5::
	applymovement LOCALID_FLOAROMA_TOWN_CYRUS, FloaromaTown_Movement_Cyrus4
	waitmovement 0
	goto FloaromaTown_EventScript_Trigger1_2_8

FloaromaTown_EventScript_Trigger1_2_6::
	applymovement LOCALID_FLOAROMA_TOWN_CYRUS, FloaromaTown_Movement_Cyrus4
	waitmovement 0
	goto FloaromaTown_EventScript_Trigger1_2_8

FloaromaTown_EventScript_Trigger1_2_7::
	applymovement LOCALID_FLOAROMA_TOWN_CYRUS, FloaromaTown_Movement_Cyrus4
	waitmovement 0
	goto FloaromaTown_EventScript_Trigger1_2_8

FloaromaTown_EventScript_Trigger1_2_8::
	removeobject LOCALID_FLOAROMA_TOWN_CYRUS
	setvar VAR_FLOAROMA_TOWN_STATE, 1
	releaseall
	end

FloaromaTown_OnTransition::
	end

FloaromaTown_Movement_GalacticGrunt:
	walk_in_place_right
	step_end

FloaromaTown_Movement_GalacticGrunt2:
	walk_in_place_left
	step_end

FloaromaTown_Movement_Cyrus:
	walk_down
	walk_down
	walk_left
	walk_in_place_down
	step_end

FloaromaTown_Movement_Cyrus2:
	walk_down
	walk_down
	step_end

FloaromaTown_Movement_Cyrus3:
	walk_down
	walk_down
	walk_right
	walk_in_place_down
	step_end

FloaromaTown_Movement_Cyrus4:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

FloaromaTown_Text_NPC7:
	.string "Aren't we Team Galactic? And we're\n"
	.string "assigned here?\p"
	.string "Standing around among flowers... This\n"
	.string "doesn't seem all that cool.$"

FloaromaTown_Text_NPC7_2:
	.string "Hey now! Don't complain. This is a pretty\n"
	.string "decent assignment.\p"
	.string "But Bug- and Grass-type Pokémon so\n"
	.string "creep me out...\p"
	.string "I don't like being here either.$"

FloaromaTown_Text_Trigger1:
	.string "Ah, you have a {COLOR DYNAMIC_COLOR3}Pokédex{COLOR DARK_GRAY}? You will find it\n"
	.string "indispensable.\p"
	.string "Science will become increasingly\n"
	.string "necessary in the world of Pokémon.$"

FloaromaTown_Text_Trigger1_2:
	.string "My name is Cyrus.\p"
	.string "I am but another human seeking to\n"
	.string "become {COLOR DYNAMIC_COLOR3}Sinnoh{COLOR DARK_GRAY}'s greatest Trainer.\p"
	.string "If you're also a Trainer, then do your\n"
	.string "best to gain power.\p"
	.string "Be all that you can become.$"

FloaromaTown_Text_Grunt1Speaker:
	.string "Grunt 1$"

FloaromaTown_Text_Grunt2Speaker:
	.string "Grunt 2$"
