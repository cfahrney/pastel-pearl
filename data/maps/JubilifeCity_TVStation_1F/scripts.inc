JubilifeCity_TVStation_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, JubilifeCity_TVStation_1F_OnTransition
	.byte 0

JubilifeCity_TVStation_1F_EventScript_NPC2::
	msgbox JubilifeCity_TVStation_1F_Text_NPC2, MSGBOX_NPC
	end

JubilifeCity_TVStation_1F_EventScript_NPC3::
	msgbox JubilifeCity_TVStation_1F_Text_NPC3, MSGBOX_NPC
	end

JubilifeCity_TVStation_1F_EventScript_NPC4::
	msgbox JubilifeCity_TVStation_1F_Text_NPC4, MSGBOX_NPC
	end

JubilifeCity_TVStation_1F_Text_NPC2:
	.string "TV STATION 1F NPC 2$"

JubilifeCity_TVStation_1F_Text_NPC3:
	.string "TV STATION 1F NPC 3$"

JubilifeCity_TVStation_1F_Text_NPC4:
	.string "TV STATION 1F NPC 4$"

JubilifeCity_TVStation_1F_EventScript_NPC5::
	msgbox JubilifeCity_TVStation_1F_Text_NPC5_2, MSGBOX_NPC
	end

JubilifeCity_TVStation_1F_EventScript_NPC1::
	msgbox JubilifeCity_TVStation_1F_Text_NPC1_2, MSGBOX_NPC
	end

JubilifeCity_TVStation_1F_EventScript_NPC6::
	lock
	faceplayer
	goto_if_ne VAR_JUBILIFE_CITY_TVSTATION_1F_STATE, 0, JubilifeCity_TVStation_1F_EventScript_NPC6_2
	@ TODO(DP): goto if DP system flag 2729 is set
	msgbox JubilifeCity_TVStation_1F_Text_NPC6_2, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, JubilifeCity_TVStation_1F_EventScript_NPC6_2_3
	goto JubilifeCity_TVStation_1F_EventScript_NPC6_2_4

JubilifeCity_TVStation_1F_EventScript_NPC6_2::
	message JubilifeCity_TVStation_1F_Text_NPC6_3
	waitmessage
	copyvar VAR_0x8002, VAR_JUBILIFE_CITY_TVSTATION_1F_STATE
	goto JubilifeCity_TVStation_1F_EventScript_NPC6_2_5

JubilifeCity_TVStation_1F_EventScript_NPC6_2_2::
	msgbox JubilifeCity_TVStation_1F_Text_NPC6_4, MSGBOX_DEFAULT
	closemessage
	release
	end

JubilifeCity_TVStation_1F_EventScript_NPC6_2_3::
	@ TODO(DP): Set DP system flag 2729
	msgbox JubilifeCity_TVStation_1F_Text_NPC6_5, MSGBOX_DEFAULT
	@ TODO(DP): CheckLottoNumber 32768
	@ TODO(DP): SetvarIdNumber 0, 32768, 2, 5
	msgbox JubilifeCity_TVStation_1F_Text_NPC6_6, MSGBOX_DEFAULT
	@ TODO(DP): CompareLottoNumber 32769, 32770, 32771, 32768
	goto_if_eq VAR_0x8002, 0, JubilifeCity_TVStation_1F_EventScript_NPC6_2_6
	goto_if_eq VAR_0x8002, 1, JubilifeCity_TVStation_1F_EventScript_NPC6_2_7
	goto_if_eq VAR_0x8003, 0, JubilifeCity_TVStation_1F_EventScript_NPC6_2_8
	goto JubilifeCity_TVStation_1F_EventScript_NPC6_2_9

JubilifeCity_TVStation_1F_EventScript_NPC6_2_4::
	msgbox JubilifeCity_TVStation_1F_Text_NPC6_7, MSGBOX_DEFAULT
	closemessage
	release
	end

JubilifeCity_TVStation_1F_EventScript_NPC6_2_5::
	copyvar VAR_0x8008, VAR_0x8002
	goto_if_eq VAR_0x8008, 2, JubilifeCity_TVStation_1F_EventScript_NPC6_2_10
	goto_if_eq VAR_0x8008, 3, JubilifeCity_TVStation_1F_EventScript_NPC6_2_11
	goto_if_eq VAR_0x8008, 4, JubilifeCity_TVStation_1F_EventScript_NPC6_2_12
	goto_if_eq VAR_0x8008, 5, JubilifeCity_TVStation_1F_EventScript_NPC6_2_13
	end

JubilifeCity_TVStation_1F_EventScript_NPC6_2_6::
	msgbox JubilifeCity_TVStation_1F_Text_NPC6_8, MSGBOX_DEFAULT
	closemessage
	release
	end

JubilifeCity_TVStation_1F_EventScript_NPC6_2_22::
	@ TODO(DP): CheckAccessories2 32772, 32780
	goto_if_eq VAR_RESULT, 0, JubilifeCity_TVStation_1F_EventScript_NPC6_2_22_2
	addvar VAR_0x8004, 1
	goto_if_le VAR_0x8004, 13, JubilifeCity_TVStation_1F_EventScript_NPC6_2_22
	setflag FLAG_JUBILIFE_CITY_TVSTATION_1F_WOMAN_1
	goto JubilifeCity_TVStation_1F_EventScript_NPC6_2_6

JubilifeCity_TVStation_1F_EventScript_NPC6_2_22_2::
	msgbox JubilifeCity_TVStation_1F_Text_NPC6_9, MSGBOX_DEFAULT
	@ TODO(DP): GiveAccessories2 32772
	msgbox JubilifeCity_TVStation_1F_Text_NPC6_10, MSGBOX_DEFAULT
	closemessage
	release
	end

JubilifeCity_TVStation_1F_EventScript_NPC6_2_7::
	goto_if_set FLAG_JUBILIFE_CITY_TVSTATION_1F_WOMAN_1, JubilifeCity_TVStation_1F_EventScript_NPC6_2_6
	setvar VAR_0x8004, 1
	goto JubilifeCity_TVStation_1F_EventScript_NPC6_2_22

JubilifeCity_TVStation_1F_EventScript_NPC6_2_8::
	bufferpartymonnick STR_VAR_1, VAR_0x8001
	msgbox JubilifeCity_TVStation_1F_Text_NPC6_11, MSGBOX_DEFAULT
	goto JubilifeCity_TVStation_1F_EventScript_NPC6_2_14

JubilifeCity_TVStation_1F_EventScript_NPC6_2_9::
	@ TODO(DP): SetvarIdPokeBoxes 0, 32769
	msgbox JubilifeCity_TVStation_1F_Text_NPC6_12, MSGBOX_DEFAULT
	goto JubilifeCity_TVStation_1F_EventScript_NPC6_2_14

JubilifeCity_TVStation_1F_EventScript_NPC6_2_10::
	setvar VAR_0x8003, 51
	goto JubilifeCity_TVStation_1F_EventScript_NPC6_2_15

JubilifeCity_TVStation_1F_EventScript_NPC6_2_11::
	setvar VAR_0x8003, 216
	goto JubilifeCity_TVStation_1F_EventScript_NPC6_2_15

JubilifeCity_TVStation_1F_EventScript_NPC6_2_12::
	setvar VAR_0x8003, 29
	goto JubilifeCity_TVStation_1F_EventScript_NPC6_2_15

JubilifeCity_TVStation_1F_EventScript_NPC6_2_13::
	setvar VAR_0x8003, 1
	goto JubilifeCity_TVStation_1F_EventScript_NPC6_2_15

JubilifeCity_TVStation_1F_EventScript_NPC6_2_14::
	copyvar VAR_0x8008, VAR_0x8002
	goto_if_eq VAR_0x8008, 2, JubilifeCity_TVStation_1F_EventScript_NPC6_2_16
	goto_if_eq VAR_0x8008, 3, JubilifeCity_TVStation_1F_EventScript_NPC6_2_17
	goto_if_eq VAR_0x8008, 4, JubilifeCity_TVStation_1F_EventScript_NPC6_2_18
	goto_if_eq VAR_0x8008, 5, JubilifeCity_TVStation_1F_EventScript_NPC6_2_19
	end

JubilifeCity_TVStation_1F_EventScript_NPC6_2_15::
	copyvar VAR_0x8004, VAR_0x8003
	setvar VAR_0x8005, 1
	checkitemspace VAR_0x8004, VAR_0x8005
	goto_if_eq VAR_RESULT, FALSE, JubilifeCity_TVStation_1F_EventScript_NPC6_2_20
	giveitem VAR_0x8004, VAR_0x8005
	goto JubilifeCity_TVStation_1F_EventScript_NPC6_2_21

JubilifeCity_TVStation_1F_EventScript_NPC6_2_16::
	msgbox JubilifeCity_TVStation_1F_Text_NPC6_13, MSGBOX_DEFAULT
	goto JubilifeCity_TVStation_1F_EventScript_NPC6_2_5

JubilifeCity_TVStation_1F_EventScript_NPC6_2_17::
	msgbox JubilifeCity_TVStation_1F_Text_NPC6_14, MSGBOX_DEFAULT
	goto JubilifeCity_TVStation_1F_EventScript_NPC6_2_5

JubilifeCity_TVStation_1F_EventScript_NPC6_2_18::
	msgbox JubilifeCity_TVStation_1F_Text_NPC6_15, MSGBOX_DEFAULT
	goto JubilifeCity_TVStation_1F_EventScript_NPC6_2_5

JubilifeCity_TVStation_1F_EventScript_NPC6_2_19::
	msgbox JubilifeCity_TVStation_1F_Text_NPC6_16, MSGBOX_DEFAULT
	goto JubilifeCity_TVStation_1F_EventScript_NPC6_2_5

JubilifeCity_TVStation_1F_EventScript_NPC6_2_20::
	copyvar VAR_JUBILIFE_CITY_TVSTATION_1F_STATE, VAR_0x8002
	msgbox JubilifeCity_TVStation_1F_Text_NPC6_17, MSGBOX_DEFAULT
	closemessage
	release
	end

JubilifeCity_TVStation_1F_EventScript_NPC6_2_21::
	setvar VAR_JUBILIFE_CITY_TVSTATION_1F_STATE, 0
	msgbox JubilifeCity_TVStation_1F_Text_NPC6_18, MSGBOX_DEFAULT
	closemessage
	release
	end

JubilifeCity_TVStation_1F_EventScript_NPC8::
	lock
	faceplayer
	@ TODO(DP): goto if DP trainer #371 (Idol Grace) is beaten
	msgbox JubilifeCity_TVStation_1F_Text_NPC8, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, JubilifeCity_TVStation_1F_EventScript_NPC8_2_2
	msgbox JubilifeCity_TVStation_1F_Text_NPC8_2, MSGBOX_DEFAULT
	closemessage
	@ TODO(DP): Scripted battle against DP trainer #371 (Idol Grace)
	@ TODO(DP): Mark DP trainer #371 beaten
	@ TODO(DP): Set DP system flag 2735
	release
	end

JubilifeCity_TVStation_1F_EventScript_NPC8_2::
	msgbox JubilifeCity_TVStation_1F_Text_NPC8_3, MSGBOX_DEFAULT
	closemessage
	release
	end

JubilifeCity_TVStation_1F_EventScript_NPC8_2_2::
	msgbox JubilifeCity_TVStation_1F_Text_NPC8_4, MSGBOX_DEFAULT
	closemessage
	release
	end

JubilifeCity_TVStation_1F_EventScript_NPC8_2_3::
	release
	end

JubilifeCity_TVStation_1F_EventScript_NPC9::
	lock
	faceplayer
	@ TODO(DP): goto if DP trainer #370 (Reporter Kinsey) is beaten
	msgbox JubilifeCity_TVStation_1F_Text_NPC9, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, JubilifeCity_TVStation_1F_EventScript_NPC9_2_2
	msgbox JubilifeCity_TVStation_1F_Text_NPC9_2, MSGBOX_DEFAULT
	closemessage
	@ TODO(DP): Scripted battle against DP trainer #370 (Reporter Kinsey)
	@ TODO(DP): Mark DP trainer #370 beaten
	@ TODO(DP): Set DP system flag 2735
	release
	end

JubilifeCity_TVStation_1F_EventScript_NPC9_2::
	msgbox JubilifeCity_TVStation_1F_Text_NPC9_3, MSGBOX_DEFAULT
	closemessage
	release
	end

JubilifeCity_TVStation_1F_EventScript_NPC9_2_2::
	msgbox JubilifeCity_TVStation_1F_Text_NPC9_4, MSGBOX_DEFAULT
	closemessage
	release
	end

JubilifeCity_TVStation_1F_EventScript_NPC10::
	lock
	faceplayer
	@ TODO(DP): goto if DP trainer #369 (Cameraman Tevin) is beaten
	msgbox JubilifeCity_TVStation_1F_Text_NPC10, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, JubilifeCity_TVStation_1F_EventScript_NPC10_2_2
	msgbox JubilifeCity_TVStation_1F_Text_NPC10_2, MSGBOX_DEFAULT
	closemessage
	@ TODO(DP): Scripted battle against DP trainer #369 (Cameraman Tevin)
	@ TODO(DP): Mark DP trainer #369 beaten
	@ TODO(DP): Set DP system flag 2735
	release
	end

JubilifeCity_TVStation_1F_EventScript_NPC10_2::
	msgbox JubilifeCity_TVStation_1F_Text_NPC10_3, MSGBOX_DEFAULT
	closemessage
	release
	end

JubilifeCity_TVStation_1F_EventScript_NPC10_2_2::
	msgbox JubilifeCity_TVStation_1F_Text_NPC10_4, MSGBOX_DEFAULT
	closemessage
	release
	end

JubilifeCity_TVStation_1F_EventScript_NPC11::
	lock
	faceplayer
	@ TODO(DP): goto if DP trainer #460 (Clown Lee) is beaten
	msgbox JubilifeCity_TVStation_1F_Text_NPC11, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, JubilifeCity_TVStation_1F_EventScript_NPC11_2_2
	msgbox JubilifeCity_TVStation_1F_Text_NPC11_2, MSGBOX_DEFAULT
	closemessage
	@ TODO(DP): Scripted battle against DP trainer #460 (Clown Lee)
	@ TODO(DP): Mark DP trainer #460 beaten
	@ TODO(DP): Set DP system flag 2735
	release
	end

JubilifeCity_TVStation_1F_EventScript_NPC11_2::
	msgbox JubilifeCity_TVStation_1F_Text_NPC11_3, MSGBOX_DEFAULT
	closemessage
	release
	end

JubilifeCity_TVStation_1F_EventScript_NPC11_2_2::
	msgbox JubilifeCity_TVStation_1F_Text_NPC11_4, MSGBOX_DEFAULT
	closemessage
	release
	end

JubilifeCity_TVStation_1F_EventScript_NPC12::
	lock
	faceplayer
	@ TODO(DP): goto if DP trainer #368 (Interviewers Roxy & Oli) is beaten
	@ TODO(DP): CountAvailablePartyMons_IgnoreSlot 32780, 6
	goto_if_ge VAR_RESULT, 2, JubilifeCity_TVStation_1F_EventScript_NPC12_2_2
	msgbox JubilifeCity_TVStation_1F_Text_NPC12, MSGBOX_DEFAULT
	closemessage
	release
	end

JubilifeCity_TVStation_1F_EventScript_NPC12_2::
	msgbox JubilifeCity_TVStation_1F_Text_NPC12_2, MSGBOX_DEFAULT
	closemessage
	release
	end

JubilifeCity_TVStation_1F_EventScript_NPC12_2_2::
	msgbox JubilifeCity_TVStation_1F_Text_NPC12_3, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, JubilifeCity_TVStation_1F_EventScript_NPC12_2_3
	msgbox JubilifeCity_TVStation_1F_Text_NPC12_4, MSGBOX_DEFAULT
	closemessage
	@ TODO(DP): Scripted battle against DP trainer #368 (Interviewers Roxy & Oli)
	@ TODO(DP): Mark DP trainer #368 beaten
	@ TODO(DP): Set DP system flag 2735
	release
	end

JubilifeCity_TVStation_1F_EventScript_NPC12_2_3::
	msgbox JubilifeCity_TVStation_1F_Text_NPC12_5, MSGBOX_DEFAULT
	closemessage
	release
	end

JubilifeCity_TVStation_1F_EventScript_NPC13::
	lock
	faceplayer
	@ TODO(DP): goto if DP trainer #465 (Poké Kid Ariel) is beaten
	msgbox JubilifeCity_TVStation_1F_Text_NPC13, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, JubilifeCity_TVStation_1F_EventScript_NPC13_2_2
	msgbox JubilifeCity_TVStation_1F_Text_NPC13_2, MSGBOX_DEFAULT
	closemessage
	@ TODO(DP): Scripted battle against DP trainer #465 (Poké Kid Ariel)
	@ TODO(DP): Mark DP trainer #465 beaten
	@ TODO(DP): Set DP system flag 2735
	release
	end

JubilifeCity_TVStation_1F_EventScript_NPC13_2::
	msgbox JubilifeCity_TVStation_1F_Text_NPC13_3, MSGBOX_DEFAULT
	closemessage
	release
	end

JubilifeCity_TVStation_1F_EventScript_NPC13_2_2::
	msgbox JubilifeCity_TVStation_1F_Text_NPC13_4, MSGBOX_DEFAULT
	closemessage
	release
	end

JubilifeCity_TVStation_1F_EventScript_NPC14::
	lock
	faceplayer
	@ TODO(DP): goto if DP trainer #431 (Guitarist Arturo) is beaten
	msgbox JubilifeCity_TVStation_1F_Text_NPC14, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, JubilifeCity_TVStation_1F_EventScript_NPC14_2_2
	msgbox JubilifeCity_TVStation_1F_Text_NPC14_2, MSGBOX_DEFAULT
	closemessage
	@ TODO(DP): Scripted battle against DP trainer #431 (Guitarist Arturo)
	@ TODO(DP): Mark DP trainer #431 beaten
	@ TODO(DP): Set DP system flag 2735
	release
	end

JubilifeCity_TVStation_1F_EventScript_NPC14_2::
	msgbox JubilifeCity_TVStation_1F_Text_NPC14_3, MSGBOX_DEFAULT
	closemessage
	release
	end

JubilifeCity_TVStation_1F_EventScript_NPC14_2_2::
	msgbox JubilifeCity_TVStation_1F_Text_NPC14_4, MSGBOX_DEFAULT
	closemessage
	release
	end

JubilifeCity_TVStation_1F_EventScript_NPC7::
	msgbox JubilifeCity_TVStation_1F_Text_NPC7_2, MSGBOX_NPC
	end

JubilifeCity_TVStation_1F_OnTransition::
	@ TODO(DP): goto if DP system flag 2735 is set
	@ TODO(DP): Unmark DP trainer #371 beaten
	@ TODO(DP): Unmark DP trainer #370 beaten
	@ TODO(DP): Unmark DP trainer #369 beaten
	@ TODO(DP): Unmark DP trainer #460 beaten
	@ TODO(DP): Unmark DP trainer #368 beaten
	@ TODO(DP): Unmark DP trainer #465 beaten
	@ TODO(DP): Unmark DP trainer #431 beaten
	goto JubilifeCity_TVStation_1F_OnTransition_2

JubilifeCity_TVStation_1F_OnTransition_2::
	setflag FLAG_HIDE_JUBILIFE_CITY_TVSTATION_1F_IDOL
	setflag FLAG_HIDE_JUBILIFE_CITY_TVSTATION_1F_REPORTER
	setflag FLAG_HIDE_JUBILIFE_CITY_TVSTATION_1F_CAMERAMAN
	setflag FLAG_HIDE_JUBILIFE_CITY_TVSTATION_1F_CLOWN
	setflag FLAG_HIDE_JUBILIFE_CITY_TVSTATION_1F_REPORTER_2
	setflag FLAG_JUBILIFE_CITY_TVSTATION_1F_EVENT_1
	setflag FLAG_HIDE_JUBILIFE_CITY_TVSTATION_1F_PIKACHU
	setflag FLAG_HIDE_JUBILIFE_CITY_TVSTATION_1F_MAN
	@ TODO(DP): GetDayOfWeek 16384
	goto_if_eq VAR_TEMP_0, 0, JubilifeCity_TVStation_1F_OnTransition_2_2
	goto_if_eq VAR_TEMP_0, 1, JubilifeCity_TVStation_1F_OnTransition_2_3
	goto_if_eq VAR_TEMP_0, 2, JubilifeCity_TVStation_1F_OnTransition_2_4
	goto_if_eq VAR_TEMP_0, 3, JubilifeCity_TVStation_1F_OnTransition_2_5
	goto_if_eq VAR_TEMP_0, 4, JubilifeCity_TVStation_1F_OnTransition_2_6
	goto_if_eq VAR_TEMP_0, 5, JubilifeCity_TVStation_1F_OnTransition_2_7
	goto_if_eq VAR_TEMP_0, 6, JubilifeCity_TVStation_1F_OnTransition_2_8
	end

JubilifeCity_TVStation_1F_OnTransition_2_2::
	clearflag FLAG_HIDE_JUBILIFE_CITY_TVSTATION_1F_IDOL
	end

JubilifeCity_TVStation_1F_OnTransition_2_3::
	clearflag FLAG_HIDE_JUBILIFE_CITY_TVSTATION_1F_REPORTER
	end

JubilifeCity_TVStation_1F_OnTransition_2_4::
	clearflag FLAG_HIDE_JUBILIFE_CITY_TVSTATION_1F_CAMERAMAN
	end

JubilifeCity_TVStation_1F_OnTransition_2_5::
	clearflag FLAG_HIDE_JUBILIFE_CITY_TVSTATION_1F_CLOWN
	end

JubilifeCity_TVStation_1F_OnTransition_2_6::
	clearflag FLAG_HIDE_JUBILIFE_CITY_TVSTATION_1F_REPORTER_2
	clearflag FLAG_JUBILIFE_CITY_TVSTATION_1F_EVENT_1
	end

JubilifeCity_TVStation_1F_OnTransition_2_7::
	clearflag FLAG_HIDE_JUBILIFE_CITY_TVSTATION_1F_PIKACHU
	end

JubilifeCity_TVStation_1F_OnTransition_2_8::
	clearflag FLAG_HIDE_JUBILIFE_CITY_TVSTATION_1F_MAN
	end

JubilifeCity_TVStation_1F_Text_NPC5_2:
	.string "They keep records of things like how\n"
	.string "many battles you've won in a row, or how\l"
	.string "many Pokémon you've caught.\p"
	.string "You can check everyone's records up on\n"
	.string "the third floor.$"

JubilifeCity_TVStation_1F_Text_NPC1_2:
	.string "Why don't you try dressing up your\n"
	.string "Pokémon now?\p"
	.string "We have a Fitting Room on the second\n"
	.string "floor.\p"
	.string "Dress up your Pokémon nicely with\n"
	.string "Accessories!$"

JubilifeCity_TVStation_1F_Text_NPC6_2:
	.string "This is the Pokémon Lottery Corner.\p"
	.string "If your drawn number matches the ID No.\n"
	.string "of any of your Pokémon, starting with\l"
	.string "the far right digit, you will receive a\l"
	.string "fabulous gift.\p"
	.string "Would you like to draw a Pokémon Loto\n"
	.string "Ticket?$"

JubilifeCity_TVStation_1F_Text_NPC6_3:
	.string "{PLAYER}? Yes, I've been expecting you.\p"
	.string "This is the prize we've been holding for\n"
	.string "you. Here you go!$"

JubilifeCity_TVStation_1F_Text_NPC6_4:
	.string "You've already drawn a Loto Ticket\n"
	.string "today. Please come back tomorrow.$"

JubilifeCity_TVStation_1F_Text_NPC6_5:
	.string "Please draw a Loto Ticket.\p"
	.string "...$"

JubilifeCity_TVStation_1F_Text_NPC6_6:
	.string "Your Loto Ticket number is {PLAYER}.\p"
	.string "Now, let's see if it matches the ID No.\n"
	.string "of any of your Pokémon.$"

JubilifeCity_TVStation_1F_Text_NPC6_7:
	.string "Oh. I see. Please do visit us again.$"

JubilifeCity_TVStation_1F_Text_NPC6_8:
	.string "I'm sorry. You didn't get a match...$"

JubilifeCity_TVStation_1F_Text_NPC6_9:
	.string "The last digit matched, so you win the\n"
	.string "fourth prize!$"

JubilifeCity_TVStation_1F_Text_NPC6_10:
	.string "You gained a new Backdrop for use in\n"
	.string "Fitting Rooms.$"

JubilifeCity_TVStation_1F_Text_NPC6_11:
	.string "Congratulations!\p"
	.string "The ID No. of your team's {STR_VAR_1}\n"
	.string "matches your Loto Ticket number!$"

JubilifeCity_TVStation_1F_Text_NPC6_12:
	.string "Congratulations!\p"
	.string "The ID No. of your PC-boxed {STR_VAR_1}\n"
	.string "matches your Loto Ticket number!$"

JubilifeCity_TVStation_1F_Text_NPC6_13:
	.string "The last two digits matched, so you win\n"
	.string "the third prize!$"

JubilifeCity_TVStation_1F_Text_NPC6_14:
	.string "The last three digits matched, so you\n"
	.string "win the second prize!$"

JubilifeCity_TVStation_1F_Text_NPC6_15:
	.string "The last four digits matched, so you win\n"
	.string "the first prize!$"

JubilifeCity_TVStation_1F_Text_NPC6_16:
	.string "Oh, my goodness, all five digits\n"
	.string "matched!\p"
	.string "You've won the jackpot prize! This is\n"
	.string "just so incredible!\p"
	.string "...Oh, I'm sorry! Your prize! I got carried\n"
	.string "away there.\p"
	.string "Here you go!$"

JubilifeCity_TVStation_1F_Text_NPC6_17:
	.string "...Oh? You seem to have no room for this.\p"
	.string "Please make room in your Bag and then\n"
	.string "let me know.$"

JubilifeCity_TVStation_1F_Text_NPC6_18:
	.string "Please do visit again.$"

JubilifeCity_TVStation_1F_Text_NPC8:
	.string "More than singing! More than dancing!\p"
	.string "I love Pokémon! So, shall we battle?$"

JubilifeCity_TVStation_1F_Text_NPC8_2:
	.string "I'll let you join my fan club if you can\n"
	.string "beat me!$"

JubilifeCity_TVStation_1F_Text_NPC8_3:
	.string "Well, that's me and my Pokémon! I hope\n"
	.string "you'll support us!\p"
	.string "Just so you know, our latest single is\n"
	.string "called “Jigglin' Pokémon Wub!”$"

JubilifeCity_TVStation_1F_Text_NPC8_4:
	.string "Aww... That's heartbreaking... I'm an\n"
	.string "Idol, too...$"

JubilifeCity_TVStation_1F_Text_NPC9:
	.string "I'm working on a story. Can you battle\n"
	.string "me?$"

JubilifeCity_TVStation_1F_Text_NPC9_2:
	.string "Join me for a live report!$"

JubilifeCity_TVStation_1F_Text_NPC9_3:
	.string "Interviews are about taking the\n"
	.string "initiative.$"

JubilifeCity_TVStation_1F_Text_NPC9_4:
	.string "Press coverage denied... But you're so\n"
	.string "intriguing!$"

JubilifeCity_TVStation_1F_Text_NPC10:
	.string "I've spotted a charismatic Trainer! Is\n"
	.string "it OK to go for the scoop?$"

JubilifeCity_TVStation_1F_Text_NPC10_2:
	.string "As a professional cameraman, I always\n"
	.string "go for the best shot!$"

JubilifeCity_TVStation_1F_Text_NPC10_3:
	.string "The lively expressions on you and your\n"
	.string "Pokémon's faces...\p"
	.string "It makes for some great TV!$"

JubilifeCity_TVStation_1F_Text_NPC10_4:
	.string "That's a downer...\p"
	.string "I thought I'd found a Trainer and\n"
	.string "Pokémon who'd shine on camera.$"

JubilifeCity_TVStation_1F_Text_NPC11:
	.string "Are we all ready to have some fun? I\n"
	.string "sure am! Aren't you having fun?!\p"
	.string "Let's make it fun! OK?!$"

JubilifeCity_TVStation_1F_Text_NPC11_2:
	.string "OK, how shall we do this? Shall we do\n"
	.string "something fantastical?$"

JubilifeCity_TVStation_1F_Text_NPC11_3:
	.string "A clown's makeup is a face that's crying\n"
	.string "while laughing.\p"
	.string "It defines what we do!$"

JubilifeCity_TVStation_1F_Text_NPC11_4:
	.string "Oh, how shall I say this...? It makes me\n"
	.string "all lonely, I say...$"

JubilifeCity_TVStation_1F_Text_NPC12:
	.string "Oh, no. What we really want to see is you\n"
	.string "in action with two Pokémon!$"

JubilifeCity_TVStation_1F_Text_NPC12_2:
	.string "I lost but I'm totally thrilled! We made\n"
	.string "a wonderful spectacle!$"

JubilifeCity_TVStation_1F_Text_NPC12_3:
	.string "Giggle! Will you have a battle with us?$"

JubilifeCity_TVStation_1F_Text_NPC12_4:
	.string "We'll check you out thoroughly as a\n"
	.string "Trainer!$"

JubilifeCity_TVStation_1F_Text_NPC12_5:
	.string "Oh, too bad! I wanted to check out your\n"
	.string "Pokémon!$"

JubilifeCity_TVStation_1F_Text_NPC13:
	.string "Po-Po-Pokémon!\p"
	.string "I want to become more like a Pikachu!\n"
	.string "Will you battle me?$"

JubilifeCity_TVStation_1F_Text_NPC13_2:
	.string "Pi-pikachu!$"

JubilifeCity_TVStation_1F_Text_NPC13_3:
	.string "I need to get more into the character\n"
	.string "of a Pokémon...$"

JubilifeCity_TVStation_1F_Text_NPC13_4:
	.string "Pikachu!$"

JubilifeCity_TVStation_1F_Text_NPC14:
	.string "Come on, let's show off our Pokémon!\n"
	.string "Let's do battle, kiddo!$"

JubilifeCity_TVStation_1F_Text_NPC14_2:
	.string "Your spirit's vibes... I can feel you've\n"
	.string "got rock in your veins!$"

JubilifeCity_TVStation_1F_Text_NPC14_3:
	.string "Rock is about your spirit! Battling is\n"
	.string "about spirit, too!\p"
	.string "That's why a battle is rock!$"

JubilifeCity_TVStation_1F_Text_NPC14_4:
	.string "Now, that is so lame. You have to let\n"
	.string "your passion burn!$"

JubilifeCity_TVStation_1F_Text_NPC7_2:
	.string "The Trainers that gather over there are\n"
	.string "looking for battles.\p"
	.string "That corner used to be for karaoke, but\n"
	.string "now it's all battling!$"
