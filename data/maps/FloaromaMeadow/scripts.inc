FloaromaMeadow_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FloaromaMeadow_OnTransition
	.byte 0

FloaromaMeadow_EventScript_NPC4::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_COMBEE, CRY_MODE_NORMAL
	setspeaker FloaromaMeadow_Text_NPC4Speaker
	msgbox FloaromaMeadow_Text_NPC4, MSGBOX_DEFAULT
	waitmoncry
	release
	end

FloaromaMeadow_Text_NPC4Speaker:
	.string "Combee$"

FloaromaMeadow_Text_NPC4:
	.string "FLOAROMA MEADOW NPC 4$"

FloaromaMeadow_EventScript_NPC5::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_COMBEE, CRY_MODE_NORMAL
	setspeaker FloaromaMeadow_Text_NPC5Speaker
	msgbox FloaromaMeadow_Text_NPC5, MSGBOX_DEFAULT
	waitmoncry
	release
	end

FloaromaMeadow_Text_NPC5Speaker:
	.string "Combee$"

FloaromaMeadow_Text_NPC5:
	.string "FLOAROMA MEADOW NPC 5$"

FloaromaMeadow_EventScript_NPC6::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_VESPIQUEN, CRY_MODE_NORMAL
	setspeaker FloaromaMeadow_Text_NPC6Speaker
	msgbox FloaromaMeadow_Text_NPC6, MSGBOX_DEFAULT
	waitmoncry
	release
	end

FloaromaMeadow_Text_NPC6Speaker:
	.string "Vespiquen$"

FloaromaMeadow_Text_NPC6:
	.string "FLOAROMA MEADOW NPC 6$"

FloaromaMeadow_EventScript_NPC7::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_COMBEE, CRY_MODE_NORMAL
	setspeaker FloaromaMeadow_Text_NPC7Speaker
	msgbox FloaromaMeadow_Text_NPC7, MSGBOX_DEFAULT
	waitmoncry
	release
	end

FloaromaMeadow_Text_NPC7Speaker:
	.string "Combee$"

FloaromaMeadow_Text_NPC7:
	.string "FLOAROMA MEADOW NPC 7$"

FloaromaMeadow_EventScript_NPC8::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_CUTIEFLY, CRY_MODE_NORMAL
	setspeaker FloaromaMeadow_Text_NPC8Speaker
	msgbox FloaromaMeadow_Text_NPC8, MSGBOX_DEFAULT
	waitmoncry
	release
	end

FloaromaMeadow_Text_NPC8Speaker:
	.string "Cutiefly$"

FloaromaMeadow_Text_NPC8:
	.string "FLOAROMA MEADOW NPC 8$"

FloaromaMeadow_EventScript_NPC1::
	end

FloaromaMeadow_EventScript_NPC2::
	goto FloaromaMeadow_EventScript_NPC1
	end

FloaromaMeadow_EventScript_NPC3::
	lock
	faceplayer
	message FloaromaMeadow_Text_NPC3_2
	waitmessage
	showmoneybox 0, 0
	@ TODO(DP): Yes/No without a message before it
	goto_if_eq VAR_RESULT, NO, FloaromaMeadow_EventScript_NPC3_2
	checkmoney 100
	goto_if_eq VAR_RESULT, FALSE, FloaromaMeadow_EventScript_NPC3_2_2
	setvar VAR_0x8004, ITEM_HONEY
	setvar VAR_0x8005, 1
	checkitemspace VAR_0x8004, VAR_0x8005
	goto_if_eq VAR_RESULT, FALSE, FloaromaMeadow_EventScript_NPC3_2_3
	removemoney 100
	updatemoneybox
	giveitem VAR_0x8004, VAR_0x8005
	hidemoneybox
	closemessage
	release
	end

FloaromaMeadow_EventScript_NPC3_2::
	msgbox FloaromaMeadow_Text_NPC3_3, MSGBOX_DEFAULT
	hidemoneybox
	closemessage
	release
	end

FloaromaMeadow_EventScript_NPC3_2_2::
	msgbox FloaromaMeadow_Text_NPC3_4, MSGBOX_DEFAULT
	hidemoneybox
	closemessage
	release
	end

FloaromaMeadow_EventScript_NPC3_2_3::
	msgbox FloaromaMeadow_Text_NPC3_5, MSGBOX_DEFAULT
	hidemoneybox
	closemessage
	release
	end

FloaromaMeadow_EventScript_Trigger1::
	lockall
	call FloaromaMeadow_EventScript_Trigger1_2
	@ TODO(DP): Scripted battle against DP trainer #296 (Galactic Grunt)
	goto_if_eq VAR_RESULT, 0, FloaromaMeadow_EventScript_Trigger1_2_2
	call FloaromaMeadow_EventScript_Trigger1_2_3
	@ TODO(DP): Scripted battle against DP trainer #297 (Galactic Grunt)
	goto_if_eq VAR_RESULT, 0, FloaromaMeadow_EventScript_Trigger1_2_2
	call FloaromaMeadow_EventScript_Trigger1_2_4
	@ TODO(DP): Set DP system flag 2441
	releaseall
	end

FloaromaMeadow_EventScript_Trigger1_2::
	setspeaker FloaromaMeadow_Text_Grunt1Speaker
	msgbox FloaromaMeadow_Text_Trigger1, MSGBOX_DEFAULT
	setspeaker FloaromaMeadow_Text_Grunt2Speaker
	msgbox FloaromaMeadow_Text_Trigger1_2, MSGBOX_DEFAULT
	playse SE_PIN
	applymovement LOCALID_FLOAROMA_MEADOW_GALACTIC_GRUNT, FloaromaMeadow_Movement_GalacticGrunt
	playse SE_PIN
	applymovement LOCALID_FLOAROMA_MEADOW_GALACTIC_GRUNT_2, FloaromaMeadow_Movement_GalacticGrunt2
	waitmovement 0
	setspeaker FloaromaMeadow_Text_Grunt1Speaker
	msgbox FloaromaMeadow_Text_Trigger1_3, MSGBOX_DEFAULT
	setspeaker FloaromaMeadow_Text_Grunt2Speaker
	msgbox FloaromaMeadow_Text_Trigger1_4, MSGBOX_DEFAULT
	closemessage
	return

FloaromaMeadow_EventScript_Trigger1_2_2::
	releaseall
	end

FloaromaMeadow_EventScript_Trigger1_2_3::
	applymovement LOCALID_FLOAROMA_MEADOW_GALACTIC_GRUNT, FloaromaMeadow_Movement_GalacticGrunt3
	waitmovement 0
	setspeaker FloaromaMeadow_Text_Grunt1Speaker
	msgbox FloaromaMeadow_Text_Trigger1_5, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_FLOAROMA_MEADOW_GALACTIC_GRUNT, FloaromaMeadow_Movement_GalacticGrunt4
	waitmovement 0
	setspeaker FloaromaMeadow_Text_Grunt2Speaker
	msgbox FloaromaMeadow_Text_Trigger1_6, MSGBOX_DEFAULT
	closemessage
	return

FloaromaMeadow_EventScript_Trigger1_2_4::
	setspeaker FloaromaMeadow_Text_Grunt1Speaker
	msgbox FloaromaMeadow_Text_Trigger1_7, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_FLOAROMA_MEADOW_GALACTIC_GRUNT
	removeobject LOCALID_FLOAROMA_MEADOW_GALACTIC_GRUNT_2
	setvar VAR_FLOAROMA_MEADOW_STATE, 1
	fadescreen FADE_FROM_BLACK
	clearflag FLAG_FLOAROMA_MEADOW_TRIGGER_1
	@ TODO(DP): show DP object 3
	applymovement LOCALID_FLOAROMA_MEADOW_MIDDLE_AGED_MAN, FloaromaMeadow_Movement_MiddleAgedMan
	waitmovement 0
	@ TODO(DP): hide DP object 3
	msgbox FloaromaMeadow_Text_Trigger1_8, MSGBOX_DEFAULT
	setvar VAR_0x8004, 438
	setvar VAR_0x8005, 1
	giveitem VAR_0x8004, VAR_0x8005
	setflag FLAG_FLOAROMA_MEADOW_TRIGGER_2
	msgbox FloaromaMeadow_Text_Trigger1_9, MSGBOX_DEFAULT
	setvar VAR_0x8004, ITEM_HONEY
	setvar VAR_0x8005, 1
	checkitemspace VAR_0x8004, VAR_0x8005
	goto_if_eq VAR_RESULT, FALSE, FloaromaMeadow_EventScript_Trigger1_2_5
	giveitem VAR_0x8004, VAR_0x8005
	message FloaromaMeadow_Text_Trigger1_10
	waitmessage
	goto FloaromaMeadow_EventScript_Trigger1_2_6

FloaromaMeadow_EventScript_Trigger1_2_5::
	msgbox gText_TooBadBagIsFull, MSGBOX_DEFAULT
	message FloaromaMeadow_Text_NPC3_5
	waitmessage
	goto FloaromaMeadow_EventScript_Trigger1_2_6

FloaromaMeadow_EventScript_Trigger1_2_6::
	setflag FLAG_FLOAROMA_MEADOW_TRIGGER_3
	waitbuttonpress
	closemessage
	return

FloaromaMeadow_OnTransition::
	@ DP: set system flag 2510 (not needed here)
	end

FloaromaMeadow_Movement_GalacticGrunt:
	walk_in_place_down
	emote_exclamation_mark
	step_end

FloaromaMeadow_Movement_GalacticGrunt2:
	walk_in_place_down
	emote_exclamation_mark
	step_end

FloaromaMeadow_Movement_GalacticGrunt3:
	walk_in_place_right
	step_end

FloaromaMeadow_Movement_GalacticGrunt4:
	walk_in_place_down
	step_end

FloaromaMeadow_Movement_MiddleAgedMan:
	walk_down
	walk_in_place_right
	delay_16
	delay_16
	delay_16
	walk_in_place_down
	step_end

FloaromaMeadow_Text_NPC3_2:
	.string "Honey can attract Pokémon if it's\n"
	.string "slathered on a tree and left a while.\p"
	.string "Would you like to buy some Honey for a\n"
	.string "mere ¥100?$"

FloaromaMeadow_Text_NPC3_3:
	.string "Oopsy! Well, come again.$"

FloaromaMeadow_Text_NPC3_4:
	.string "Oopsy! You don't have enough money.$"

FloaromaMeadow_Text_NPC3_5:
	.string "Oopsy! You can't hold any more.$"

FloaromaMeadow_Text_Trigger1:
	.string "Enough arguing! Hand over that sweet\n"
	.string "Honey!$"

FloaromaMeadow_Text_Trigger1_2:
	.string "Do as we say! Team Galactic will have\n"
	.string "that Honey!\p"
	.string "We must have it to attract Pokémon in\n"
	.string "great numbers!$"

FloaromaMeadow_Text_Trigger1_3:
	.string "Hey! This kid is a witness! What'll we\n"
	.string "do?$"

FloaromaMeadow_Text_Trigger1_4:
	.string "We don't need the brat running off to\n"
	.string "get help...\p"
	.string "The solution's simple! We ensure the\n"
	.string "brat stays quiet!$"

FloaromaMeadow_Text_Trigger1_5:
	.string "This is so lame... They're going to dock\n"
	.string "my pay!$"

FloaromaMeadow_Text_Trigger1_6:
	.string "I'm up next! Heheheh...\p"
	.string "Battling you right after my cohort\n"
	.string "weakened you gives me the edge!$"

FloaromaMeadow_Text_Trigger1_7:
	.string "This brat's tough! Like, really, really\n"
	.string "tough!\p"
	.string "Tougher than I can put into words, and\n"
	.string "I know a lot of words!\p"
	.string "We're done for here... Let's get back to\n"
	.string "the Valley Windworks.$"

FloaromaMeadow_Text_Trigger1_8:
	.string "Oh, what's this thing? They seem to\n"
	.string "have forgotten it...\p"
	.string "It's a Works Key... It must be for the\n"
	.string "Valley Windworks!\p"
	.string "It's of no use to me. You may as well\n"
	.string "have it.$"

FloaromaMeadow_Text_Trigger1_9:
	.string "Thank you! You surely saved me.\p"
	.string "Those goons were trying to rob me of my\n"
	.string "sweet, sweet Honey.\p"
	.string "They sure were weird, though. You saw\n"
	.string "how they were dressed.\p"
	.string "What they were saying didn't make a\n"
	.string "whole lot of sense, either.\p"
	.string "Oh! I need to thank you! Will you take\n"
	.string "this as my thanks?$"

FloaromaMeadow_Text_Trigger1_10:
	.string "If you slather that Honey on a\n"
	.string "sweet-smelling tree, it might attract\l"
	.string "Pokémon.$"

FloaromaMeadow_EventScript_NPC9::
	lock
	faceplayer
	setvar VAR_0x8004, ITEM_WORKS_KEY
	setvar VAR_0x8005, 1
	giveitem VAR_0x8004, VAR_0x8005
	closemessage
	setflag FLAG_FLOAROMA_MEADOW_TRIGGER_2
	removeobject LOCALID_FLOAROMA_MEADOW_POKE_BALL
	release
	end

FloaromaMeadow_Text_Grunt1Speaker:
	.string "Grunt 1$"

FloaromaMeadow_Text_Grunt2Speaker:
	.string "Grunt 2$"
