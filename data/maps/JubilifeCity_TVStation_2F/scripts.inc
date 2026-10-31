JubilifeCity_TVStation_2F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, JubilifeCity_TVStation_2F_OnTransition
	.byte 0

JubilifeCity_TVStation_2F_EventScript_NPC2::
	msgbox JubilifeCity_TVStation_2F_Text_NPC2, MSGBOX_NPC
	end

JubilifeCity_TVStation_2F_EventScript_NPC4::
	msgbox JubilifeCity_TVStation_2F_Text_NPC4, MSGBOX_NPC
	end

JubilifeCity_TVStation_2F_Text_NPC2:
	.string "Fooo$"

JubilifeCity_TVStation_2F_Text_NPC4:
	.string "Foo bar$"

JubilifeCity_TVStation_2F_EventScript_NPC1::
	msgbox JubilifeCity_TVStation_2F_Text_NPC1_2, MSGBOX_NPC
	end

JubilifeCity_TVStation_2F_EventScript_NPC3::
	msgbox JubilifeCity_TVStation_2F_Text_NPC3, MSGBOX_NPC
	end

JubilifeCity_TVStation_2F_Text_NPC3::
	.string "Foooooooo$"

JubilifeCity_TVStation_2F_EventScript_NPC3_2_2::
	setvar VAR_0x8004, 92
	return

JubilifeCity_TVStation_2F_EventScript_NPC3_2_3::
	setvar VAR_0x8004, 93
	return

JubilifeCity_TVStation_2F_EventScript_NPC3_2_4::
	setvar VAR_0x8004, 94
	return

JubilifeCity_TVStation_2F_OnTransition::
	@ TODO(DP): CheckStatusPhraseBox 9, 16384
	goto_if_eq VAR_TEMP_0, 0, JubilifeCity_TVStation_2F_OnTransition_2
	clearflag FLAG_HIDE_JUBILIFE_CITY_TVSTATION_2F_REPORTER
	end

JubilifeCity_TVStation_2F_OnTransition_2::
	setflag FLAG_HIDE_JUBILIFE_CITY_TVSTATION_2F_REPORTER
	end

JubilifeCity_TVStation_2F_Text_NPC1_2:
	.string "I don't know what to do.\p"
	.string "What Accessories will go well with my\n"
	.string "dress today?$"

JubilifeCity_TVStation_2F_Text_NPC3_2:
	.string "Fooo$"

JubilifeCity_TVStation_2F_Text_NPC3_3:
	.string "That's a {STR_VAR_1}!\p"
	.string "I hope you get into collecting\n"
	.string "Accessories for your Pokémon!$"
