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
	.string "TV STATION 2F NPC 2$"

JubilifeCity_TVStation_2F_Text_NPC4:
	.string "TV STATION 2F NPC 4$"

JubilifeCity_TVStation_2F_EventScript_NPC1::
	msgbox JubilifeCity_TVStation_2F_Text_NPC1_2, MSGBOX_NPC
	end

JubilifeCity_TVStation_2F_EventScript_NPC3::
	lock
	faceplayer
	goto_if_set FLAG_JUBILIFE_CITY_TVSTATION_2F_NPC_1, JubilifeCity_TVStation_2F_EventScript_NPC3_2
	copyvar VAR_RESULT, VAR_STARTER_MON
	call_if_eq VAR_STARTER_MON, STARTER_TURTWIG, JubilifeCity_TVStation_2F_EventScript_NPC3_2_2
	call_if_eq VAR_STARTER_MON, STARTER_CHIMCHAR, JubilifeCity_TVStation_2F_EventScript_NPC3_2_3
	call_if_eq VAR_STARTER_MON, STARTER_PIPLUP, JubilifeCity_TVStation_2F_EventScript_NPC3_2_4
	copyvar VAR_JUBILIFE_CITY_TVSTATION_2F_STATE, VAR_0x8004
	@ TODO(DP): GetFashionNameWithArticle 0, 32772
	msgbox JubilifeCity_TVStation_2F_Text_NPC3_2, MSGBOX_DEFAULT
	setvar VAR_0x8005, 1
	@ TODO(DP): Common DP script 2015
	setflag FLAG_JUBILIFE_CITY_TVSTATION_2F_NPC_1
	closemessage
	release
	end

JubilifeCity_TVStation_2F_EventScript_NPC3_2::
	@ TODO(DP): GetFashionName 0, 16650
	msgbox JubilifeCity_TVStation_2F_Text_NPC3_3, MSGBOX_DEFAULT
	closemessage
	release
	end

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
	.string "The star of tomorrow is... You! Your\n"
	.string "Pokémon has a glow about it!\p"
	.string "So, a gift for our future star!$"

JubilifeCity_TVStation_2F_Text_NPC3_3:
	.string "That's a {STR_VAR_1}!\p"
	.string "I hope you get into collecting\n"
	.string "Accessories for your Pokémon!$"
