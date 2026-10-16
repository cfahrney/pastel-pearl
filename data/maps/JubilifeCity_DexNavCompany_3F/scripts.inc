JubilifeCity_DexNavCompany_3F_MapScripts::
	.byte 0

JubilifeCity_DexNavCompany_3F_EventScript_NPC1::
	msgbox JubilifeCity_DexNavCompany_3F_Text_NPC1, MSGBOX_NPC
	end

JubilifeCity_DexNavCompany_3F_Text_NPC1:
	.string "DEX NAV COMPANY 3F NPC 1$"

JubilifeCity_DexNavCompany_3F_EventScript_NPC2::
	msgbox JubilifeCity_DexNavCompany_3F_Text_NPC2_2, MSGBOX_NPC
	end

JubilifeCity_DexNavCompany_3F_EventScript_NPC3::
	msgbox JubilifeCity_DexNavCompany_3F_Text_NPC3_2, MSGBOX_NPC
	end

JubilifeCity_DexNavCompany_3F_EventScript_Sign2_2::
	message JubilifeCity_DexNavCompany_3F_Text_Sign2_3
	waitmessage
	@ TODO(DP): Multi 1, 1, 0, 1, 32772
	@ TODO(DP): CheckPoketch 32780
	goto_if_eq VAR_RESULT, 0, JubilifeCity_DexNavCompany_3F_EventScript_Sign2_2_2
	call JubilifeCity_DexNavCompany_3F_EventScript_Sign2_2_2_2
	call JubilifeCity_DexNavCompany_3F_EventScript_Sign2_2_2_3
	call JubilifeCity_DexNavCompany_3F_EventScript_Sign2_2_2_4
	call JubilifeCity_DexNavCompany_3F_EventScript_Sign2_2_2_5
	call JubilifeCity_DexNavCompany_3F_EventScript_Sign2_2_2_6
	call JubilifeCity_DexNavCompany_3F_EventScript_Sign2_2_2_7
	goto JubilifeCity_DexNavCompany_3F_EventScript_Sign2_2_2

JubilifeCity_DexNavCompany_3F_EventScript_Sign2_2_2::
	@ TODO(DP): ChoiceMulti 258, 0
	@ TODO(DP): CloseMulti
	goto_if_eq VAR_0x8004, 1, JubilifeCity_DexNavCompany_3F_EventScript_Sign2_2_2_8
	goto_if_eq VAR_0x8004, 2, JubilifeCity_DexNavCompany_3F_EventScript_Sign2_2_2_9
	goto_if_eq VAR_0x8004, 3, JubilifeCity_DexNavCompany_3F_EventScript_Sign2_2_2_10
	goto_if_eq VAR_0x8004, 4, JubilifeCity_DexNavCompany_3F_EventScript_Sign2_2_2_11
	goto_if_eq VAR_0x8004, 5, JubilifeCity_DexNavCompany_3F_EventScript_Sign2_2_2_12
	goto_if_eq VAR_0x8004, 6, JubilifeCity_DexNavCompany_3F_EventScript_Sign2_2_2_13
	closemessage
	releaseall
	end

JubilifeCity_DexNavCompany_3F_EventScript_Sign2_2_2_2::
	@ TODO(DP): CheckPoketchApp 0, 32780
	goto_if_eq VAR_RESULT, 0, JubilifeCity_DexNavCompany_3F_EventScript_Sign2_2_2_14
	@ TODO(DP): ChoiceMulti 233, 1
	return

JubilifeCity_DexNavCompany_3F_EventScript_Sign2_2_2_3::
	@ TODO(DP): CheckPoketchApp 11, 32780
	goto_if_eq VAR_RESULT, 0, JubilifeCity_DexNavCompany_3F_EventScript_Sign2_2_2_14
	@ TODO(DP): ChoiceMulti 237, 2
	return

JubilifeCity_DexNavCompany_3F_EventScript_Sign2_2_2_4::
	@ TODO(DP): CheckPoketchApp 23, 32780
	goto_if_eq VAR_RESULT, 0, JubilifeCity_DexNavCompany_3F_EventScript_Sign2_2_2_14
	@ TODO(DP): ChoiceMulti 234, 3
	return

JubilifeCity_DexNavCompany_3F_EventScript_Sign2_2_2_5::
	@ TODO(DP): CheckPoketchApp 20, 32780
	goto_if_eq VAR_RESULT, 0, JubilifeCity_DexNavCompany_3F_EventScript_Sign2_2_2_14
	@ TODO(DP): ChoiceMulti 250, 4
	return

JubilifeCity_DexNavCompany_3F_EventScript_Sign2_2_2_6::
	@ TODO(DP): CheckPoketchApp 24, 32780
	goto_if_eq VAR_RESULT, 0, JubilifeCity_DexNavCompany_3F_EventScript_Sign2_2_2_14
	@ TODO(DP): ChoiceMulti 249, 5
	return

JubilifeCity_DexNavCompany_3F_EventScript_Sign2_2_2_7::
	@ TODO(DP): CheckPoketchApp 16, 32780
	goto_if_eq VAR_RESULT, 0, JubilifeCity_DexNavCompany_3F_EventScript_Sign2_2_2_14
	@ TODO(DP): ChoiceMulti 254, 6
	return

JubilifeCity_DexNavCompany_3F_EventScript_Sign2_2_2_8::
	msgbox JubilifeCity_DexNavCompany_3F_Text_Sign2_4, MSGBOX_DEFAULT
	goto JubilifeCity_DexNavCompany_3F_EventScript_Sign2_2

JubilifeCity_DexNavCompany_3F_EventScript_Sign2_2_2_9::
	msgbox JubilifeCity_DexNavCompany_3F_Text_Sign2_5, MSGBOX_DEFAULT
	goto JubilifeCity_DexNavCompany_3F_EventScript_Sign2_2

JubilifeCity_DexNavCompany_3F_EventScript_Sign2_2_2_10::
	msgbox JubilifeCity_DexNavCompany_3F_Text_Sign2_6, MSGBOX_DEFAULT
	goto JubilifeCity_DexNavCompany_3F_EventScript_Sign2_2

JubilifeCity_DexNavCompany_3F_EventScript_Sign2_2_2_11::
	msgbox JubilifeCity_DexNavCompany_3F_Text_Sign2_7, MSGBOX_DEFAULT
	goto JubilifeCity_DexNavCompany_3F_EventScript_Sign2_2

JubilifeCity_DexNavCompany_3F_EventScript_Sign2_2_2_12::
	msgbox JubilifeCity_DexNavCompany_3F_Text_Sign2_8, MSGBOX_DEFAULT
	goto JubilifeCity_DexNavCompany_3F_EventScript_Sign2_2

JubilifeCity_DexNavCompany_3F_EventScript_Sign2_2_2_13::
	msgbox JubilifeCity_DexNavCompany_3F_Text_Sign2_9, MSGBOX_DEFAULT
	goto JubilifeCity_DexNavCompany_3F_EventScript_Sign2_2

JubilifeCity_DexNavCompany_3F_EventScript_Sign2_2_2_14::
	return

JubilifeCity_DexNavCompany_3F_EventScript_Sign2::
	lockall
	faceplayer
	msgbox JubilifeCity_DexNavCompany_3F_Text_Sign2_2, MSGBOX_DEFAULT
	goto JubilifeCity_DexNavCompany_3F_EventScript_Sign2_2

JubilifeCity_DexNavCompany_3F_EventScript_Sign1_2::
	message JubilifeCity_DexNavCompany_3F_Text_Sign1_3
	waitmessage
	@ TODO(DP): Multi 1, 1, 0, 1, 32772
	@ TODO(DP): CheckPoketch 32780
	goto_if_eq VAR_RESULT, 0, JubilifeCity_DexNavCompany_3F_EventScript_Sign1_2_2
	call JubilifeCity_DexNavCompany_3F_EventScript_Sign1_2_2_2
	call JubilifeCity_DexNavCompany_3F_EventScript_Sign1_2_2_3
	call JubilifeCity_DexNavCompany_3F_EventScript_Sign1_2_2_4
	call JubilifeCity_DexNavCompany_3F_EventScript_Sign1_2_2_5
	call JubilifeCity_DexNavCompany_3F_EventScript_Sign1_2_2_6
	call JubilifeCity_DexNavCompany_3F_EventScript_Sign1_2_2_7
	call JubilifeCity_DexNavCompany_3F_EventScript_Sign1_2_2_8
	goto JubilifeCity_DexNavCompany_3F_EventScript_Sign1_2_2

JubilifeCity_DexNavCompany_3F_EventScript_Sign1_2_2::
	@ TODO(DP): ChoiceMulti 258, 0
	@ TODO(DP): CloseMulti
	goto_if_eq VAR_0x8004, 1, JubilifeCity_DexNavCompany_3F_EventScript_Sign1_2_2_9
	goto_if_eq VAR_0x8004, 2, JubilifeCity_DexNavCompany_3F_EventScript_Sign1_2_2_10
	goto_if_eq VAR_0x8004, 3, JubilifeCity_DexNavCompany_3F_EventScript_Sign1_2_2_11
	goto_if_eq VAR_0x8004, 4, JubilifeCity_DexNavCompany_3F_EventScript_Sign1_2_2_12
	goto_if_eq VAR_0x8004, 5, JubilifeCity_DexNavCompany_3F_EventScript_Sign1_2_2_13
	goto_if_eq VAR_0x8004, 6, JubilifeCity_DexNavCompany_3F_EventScript_Sign1_2_2_14
	goto_if_eq VAR_0x8004, 7, JubilifeCity_DexNavCompany_3F_EventScript_Sign1_2_2_15
	closemessage
	releaseall
	end

JubilifeCity_DexNavCompany_3F_EventScript_Sign1_2_2_2::
	@ TODO(DP): CheckPoketchApp 1, 32780
	goto_if_eq VAR_RESULT, 0, JubilifeCity_DexNavCompany_3F_EventScript_Sign1_2_2_16
	@ TODO(DP): ChoiceMulti 235, 1
	return

JubilifeCity_DexNavCompany_3F_EventScript_Sign1_2_2_3::
	@ TODO(DP): CheckPoketchApp 2, 32780
	goto_if_eq VAR_RESULT, 0, JubilifeCity_DexNavCompany_3F_EventScript_Sign1_2_2_16
	@ TODO(DP): ChoiceMulti 236, 2
	return

JubilifeCity_DexNavCompany_3F_EventScript_Sign1_2_2_4::
	@ TODO(DP): CheckPoketchApp 5, 32780
	goto_if_eq VAR_RESULT, 0, JubilifeCity_DexNavCompany_3F_EventScript_Sign1_2_2_16
	@ TODO(DP): ChoiceMulti 240, 3
	return

JubilifeCity_DexNavCompany_3F_EventScript_Sign1_2_2_5::
	@ TODO(DP): CheckPoketchApp 8, 32780
	goto_if_eq VAR_RESULT, 0, JubilifeCity_DexNavCompany_3F_EventScript_Sign1_2_2_16
	@ TODO(DP): ChoiceMulti 244, 4
	return

JubilifeCity_DexNavCompany_3F_EventScript_Sign1_2_2_6::
	@ TODO(DP): CheckPoketchApp 22, 32780
	goto_if_eq VAR_RESULT, 0, JubilifeCity_DexNavCompany_3F_EventScript_Sign1_2_2_16
	@ TODO(DP): ChoiceMulti 248, 5
	return

JubilifeCity_DexNavCompany_3F_EventScript_Sign1_2_2_7::
	@ TODO(DP): CheckPoketchApp 9, 32780
	goto_if_eq VAR_RESULT, 0, JubilifeCity_DexNavCompany_3F_EventScript_Sign1_2_2_16
	@ TODO(DP): ChoiceMulti 257, 6
	return

JubilifeCity_DexNavCompany_3F_EventScript_Sign1_2_2_8::
	@ TODO(DP): CheckPoketchApp 7, 32780
	goto_if_eq VAR_RESULT, 0, JubilifeCity_DexNavCompany_3F_EventScript_Sign1_2_2_16
	@ TODO(DP): ChoiceMulti 252, 7
	return

JubilifeCity_DexNavCompany_3F_EventScript_Sign1_2_2_9::
	msgbox JubilifeCity_DexNavCompany_3F_Text_Sign1_4, MSGBOX_DEFAULT
	goto JubilifeCity_DexNavCompany_3F_EventScript_Sign1_2

JubilifeCity_DexNavCompany_3F_EventScript_Sign1_2_2_10::
	msgbox JubilifeCity_DexNavCompany_3F_Text_Sign1_5, MSGBOX_DEFAULT
	goto JubilifeCity_DexNavCompany_3F_EventScript_Sign1_2

JubilifeCity_DexNavCompany_3F_EventScript_Sign1_2_2_11::
	msgbox JubilifeCity_DexNavCompany_3F_Text_Sign1_6, MSGBOX_DEFAULT
	goto JubilifeCity_DexNavCompany_3F_EventScript_Sign1_2

JubilifeCity_DexNavCompany_3F_EventScript_Sign1_2_2_12::
	msgbox JubilifeCity_DexNavCompany_3F_Text_Sign1_7, MSGBOX_DEFAULT
	goto JubilifeCity_DexNavCompany_3F_EventScript_Sign1_2

JubilifeCity_DexNavCompany_3F_EventScript_Sign1_2_2_13::
	msgbox JubilifeCity_DexNavCompany_3F_Text_Sign1_8, MSGBOX_DEFAULT
	goto JubilifeCity_DexNavCompany_3F_EventScript_Sign1_2

JubilifeCity_DexNavCompany_3F_EventScript_Sign1_2_2_14::
	msgbox JubilifeCity_DexNavCompany_3F_Text_Sign1_9, MSGBOX_DEFAULT
	goto JubilifeCity_DexNavCompany_3F_EventScript_Sign1_2

JubilifeCity_DexNavCompany_3F_EventScript_Sign1_2_2_15::
	msgbox JubilifeCity_DexNavCompany_3F_Text_Sign1_10, MSGBOX_DEFAULT
	goto JubilifeCity_DexNavCompany_3F_EventScript_Sign1_2

JubilifeCity_DexNavCompany_3F_EventScript_Sign1_2_2_16::
	return

JubilifeCity_DexNavCompany_3F_EventScript_Sign1::
	lockall
	faceplayer
	msgbox JubilifeCity_DexNavCompany_3F_Text_Sign1_2, MSGBOX_DEFAULT
	goto JubilifeCity_DexNavCompany_3F_EventScript_Sign1_2

JubilifeCity_DexNavCompany_3F_Text_NPC2_2:
	.string "Do you have a Pokétch?\p"
	.string "There's a girl's model and a boy's model,\n"
	.string "each in different colors.$"

JubilifeCity_DexNavCompany_3F_Text_NPC3_2:
	.string "My husband's the president.\p"
	.string "We started out in a small workshop\n"
	.string "where he made what he liked.\p"
	.string "Now we're making something that makes\n"
	.string "the world happy. Imagine that!$"

JubilifeCity_DexNavCompany_3F_Text_Sign2_2:
	.string "There are descriptions of Pokétch\n"
	.string "apps.$"

JubilifeCity_DexNavCompany_3F_Text_Sign2_3:
	.string "Which Pokétch app would you like to\n"
	.string "read about?$"

JubilifeCity_DexNavCompany_3F_Text_Sign2_4:
	.string "The Digital Watch displays the current\n"
	.string "time.\p"
	.string "Don't be late for meetings with your\n"
	.string "friends!$"

JubilifeCity_DexNavCompany_3F_Text_Sign2_5:
	.string "The Analog Watch displays the current\n"
	.string "time.\p"
	.string "The short hand indicates the hour, and\n"
	.string "the long hand shows the minute!$"

JubilifeCity_DexNavCompany_3F_Text_Sign2_6:
	.string "The Stopwatch is used for measuring\n"
	.string "time precisely.\p"
	.string "How quickly can you zip through the\n"
	.string "Cycling Road?$"

JubilifeCity_DexNavCompany_3F_Text_Sign2_7:
	.string "The Kitchen Timer can count down from\n"
	.string "up to 99 minutes, but not precisely.\p"
	.string "Set the time with the center button,\n"
	.string "then start the countdown.$"

JubilifeCity_DexNavCompany_3F_Text_Sign2_8:
	.string "The Alarm Clock can be set to sound\n"
	.string "every 24 hours.\p"
	.string "Set the alarm time with the lower\n"
	.string "button. The top button turns it on.$"

JubilifeCity_DexNavCompany_3F_Text_Sign2_9:
	.string "Use the monthly Calendar to make a note\n"
	.string "of important dates.\p"
	.string "Touch any date to change its color.\n"
	.string "Touch it again to turn it back.$"

JubilifeCity_DexNavCompany_3F_Text_Sign1_2:
	.string "There are descriptions of Pokétch\n"
	.string "apps.$"

JubilifeCity_DexNavCompany_3F_Text_Sign1_3:
	.string "Which Pokétch app would you like to\n"
	.string "read about?$"

JubilifeCity_DexNavCompany_3F_Text_Sign1_4:
	.string "The Calculator can handle up to ten\n"
	.string "digits.\p"
	.string "It's perfect for figuring out math\n"
	.string "questions that might pop up.$"

JubilifeCity_DexNavCompany_3F_Text_Sign1_5:
	.string "The Memo Pad is useful for jotting down\n"
	.string "a note, or just doodling.\p"
	.string "There's an eraser, too, just in case you\n"
	.string "make a mistake.$"

JubilifeCity_DexNavCompany_3F_Text_Sign1_6:
	.string "The Friendship Checker indicates how\n"
	.string "friendly your Pokémon are to you.\p"
	.string "Touch the screen. The Pokémon that like\n"
	.string "you will come closer.$"

JubilifeCity_DexNavCompany_3F_Text_Sign1_7:
	.string "The Day-Care Checker shows the\n"
	.string "Pokémon you have in the Day Care.\p"
	.string "Check and see how your Pokémon are\n"
	.string "doing with the Day-Care Couple.$"

JubilifeCity_DexNavCompany_3F_Text_Sign1_8:
	.string "The Matchup Checker tests the\n"
	.string "attraction between Pokémon.\p"
	.string "The greater the number of hearts, the\n"
	.string "better likelihood of Eggs.$"

JubilifeCity_DexNavCompany_3F_Text_Sign1_9:
	.string "The Pokémon History keeps track of the\n"
	.string "Pokémon you have obtained.\p"
	.string "It shows the last twelve kinds of\n"
	.string "Pokémon you obtained.$"

JubilifeCity_DexNavCompany_3F_Text_Sign1_10:
	.string "The Berry Searcher is a map that shows\n"
	.string "the locations of Berries.\p"
	.string "It indicates the presence of Berries in\n"
	.string "areas you have already visited.$"
