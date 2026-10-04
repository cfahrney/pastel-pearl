OreburghCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, OreburghCity_OnTransition
	.byte 0

OreburghCity_OnTransition:
	setflag FLAG_VISITED_OREBURGH_CITY
	@ Barry only blocks the Gym until Roark sends the player back from the mine.
	setflag FLAG_HIDE_OREBURGHCITY_BARRY
	setflag FLAG_HIDE_OREBURGHCITY_BARRY_STARTER
	call_if_lt VAR_OREBURGH_CITY_STATE, 2, OreburghCity_EventScript_ShowBarry
	end

OreburghCity_EventScript_ShowBarry:
	clearflag FLAG_HIDE_OREBURGHCITY_BARRY
	clearflag FLAG_HIDE_OREBURGHCITY_BARRY_STARTER
	@ Barry's Pokémon is the starter the player didn't pick or counter.
	call_if_eq VAR_STARTER_MON, STARTER_TURTWIG, OreburghCity_EventScript_BarryStarterChimchar
	call_if_eq VAR_STARTER_MON, STARTER_CHIMCHAR, OreburghCity_EventScript_BarryStarterPiplup
	call_if_eq VAR_STARTER_MON, STARTER_PIPLUP, OreburghCity_EventScript_BarryStarterTurtwig
	return

OreburghCity_EventScript_BarryStarterChimchar:
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_SPECIES(MONFERNO)
	return

OreburghCity_EventScript_BarryStarterPiplup:
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_SPECIES(PRINPLUP)
	return

OreburghCity_EventScript_BarryStarterTurtwig:
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_SPECIES(GROTLE)
	return

OreburghCity_EventScript_Barry::
	lock
	faceplayer
	goto_if_ge VAR_OREBURGH_CITY_STATE, 1, OreburghCity_EventScript_BarryGymLeaderGone
	setspeaker SP_NAME_RIVAL
	msgbox OreburghCity_Text_BarryHunh, MSGBOX_DEFAULT
	closemessage
	setspeaker SP_NAME_RIVAL
	msgbox OreburghCity_Text_BarryYouFinallyGotHere, MSGBOX_DEFAULT
	closemessage
	setspeaker SP_NAME_RIVAL
	msgbox OreburghCity_Text_BarryGymLeaderLongGone, MSGBOX_DEFAULT
	closemessage
	setspeaker SP_NAME_RIVAL
	msgbox OreburghCity_Text_BarryHeWentToTheMine, MSGBOX_DEFAULT
	closemessage
	setspeaker SP_NAME_RIVAL
	msgbox OreburghCity_Text_BarryAlreadyGotMyBadge, MSGBOX_DEFAULT
	closemessage
	setvar VAR_OREBURGH_CITY_STATE, 1
	release
	end

OreburghCity_EventScript_BarryStarter::
	lock
	faceplayer
	waitse
	goto_if_eq VAR_STARTER_MON, STARTER_TURTWIG, OreburghCity_EventScript_BarryMonferno
	goto_if_eq VAR_STARTER_MON, STARTER_CHIMCHAR, OreburghCity_EventScript_BarryPrinplup
	goto OreburghCity_EventScript_BarryGrotle

OreburghCity_EventScript_BarryMonferno::
	playmoncry SPECIES_MONFERNO, CRY_MODE_NORMAL
	setspeaker OreburghCity_Text_BarryMonfernoSpeaker
	msgbox OreburghCity_Text_BarryMonferno, MSGBOX_DEFAULT
	waitmoncry
	release
	end

OreburghCity_EventScript_BarryPrinplup::
	playmoncry SPECIES_PRINPLUP, CRY_MODE_NORMAL
	setspeaker OreburghCity_Text_BarryPrinplupSpeaker
	msgbox OreburghCity_Text_BarryPrinplup, MSGBOX_DEFAULT
	waitmoncry
	release
	end

OreburghCity_EventScript_BarryGrotle::
	playmoncry SPECIES_GROTLE, CRY_MODE_NORMAL
	setspeaker OreburghCity_Text_BarryGrotleSpeaker
	msgbox OreburghCity_Text_BarryGrotle, MSGBOX_DEFAULT
	waitmoncry
	release
	end

OreburghCity_EventScript_BarryGymLeaderGone::
	setspeaker SP_NAME_RIVAL
	msgbox OreburghCity_Text_BarryToldYouNotHere, MSGBOX_DEFAULT
	closemessage
	setspeaker SP_NAME_RIVAL
	msgbox OreburghCity_Text_BarryGoDownToTheMine, MSGBOX_DEFAULT
	closemessage
	setspeaker SP_NAME_RIVAL
	msgbox OreburghCity_Text_BarryDifferentClass, MSGBOX_DEFAULT
	closemessage
	setspeaker SP_NAME_RIVAL
	msgbox OreburghCity_Text_BarryFeelingRunDown, MSGBOX_DEFAULT
	closemessage
	release
	end

OreburghCity_EventScript_NPC1::
	msgbox OreburghCity_Text_NPC1, MSGBOX_NPC
	end

OreburghCity_EventScript_NPC2::
	msgbox OreburghCity_Text_NPC2, MSGBOX_NPC
	end

OreburghCity_Text_NPC1:
	.string "The Gym Leader went off to work in the\n"
	.string "mine.$"

OreburghCity_Text_NPC2:
	.string "When I run around with my {COLOR DYNAMIC_COLOR3}Running Shoes{COLOR DARK_GRAY}\n"
	.string "on, it feels like I'm the center of\l"
	.string "attention!$"

OreburghCity_EventScript_NPC3::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MACHOP, CRY_MODE_NORMAL
	setspeaker OreburghCity_Text_NPC3Speaker
	msgbox OreburghCity_Text_NPC3, MSGBOX_DEFAULT
	waitmoncry
	release
	end

OreburghCity_Text_NPC3:
	.string "OREBURGH CITY NPC 3$"

OreburghCity_Text_NPC3Speaker:
	.string "Machop$"

OreburghCity_EventScript_Sign1::
	msgbox OreburghCity_Text_Sign1, MSGBOX_SIGN
	end

OreburghCity_EventScript_Sign2::
	msgbox OreburghCity_Text_Sign2, MSGBOX_SIGN
	end

OreburghCity_EventScript_Sign3::
	msgbox OreburghCity_Text_Sign3, MSGBOX_SIGN
	end

OreburghCity_EventScript_NPC4::
	msgbox OreburghCity_Text_NPC4, MSGBOX_NPC
	end

OreburghCity_EventScript_NPC5::
	msgbox OreburghCity_Text_NPC5, MSGBOX_NPC
	end

OreburghCity_EventScript_NPC6::
	msgbox OreburghCity_Text_NPC6, MSGBOX_NPC
	end

OreburghCity_EventScript_NPC7::
	msgbox OreburghCity_Text_NPC7, MSGBOX_NPC
	end

OreburghCity_EventScript_NPC8::
	msgbox OreburghCity_Text_NPC8, MSGBOX_NPC
	end

OreburghCity_EventScript_NPC9::
	msgbox OreburghCity_Text_NPC9, MSGBOX_NPC
	end

OreburghCity_Text_Sign1:
	.string "OREBURGH CITY SIGN 1$"

OreburghCity_Text_Sign2:
	.string "OREBURGH CITY SIGN 2$"

OreburghCity_Text_Sign3:
	.string "OREBURGH CITY SIGN 3$"

OreburghCity_Text_NPC4:
	.string "OREBURGH CITY NPC 4$"

OreburghCity_Text_NPC5:
	.string "OREBURGH CITY NPC 5$"

OreburghCity_Text_NPC6:
	.string "OREBURGH CITY NPC 6$"

OreburghCity_Text_NPC7:
	.string "OREBURGH CITY NPC 7$"

OreburghCity_Text_NPC8:
	.string "OREBURGH CITY NPC 8$"

OreburghCity_Text_NPC9:
	.string "OREBURGH CITY NPC 9$"

OreburghCity_Text_BarryHunh:
	.string "Hunh?$"

OreburghCity_Text_BarryYouFinallyGotHere:
	.string "Oh, it's you, {PLAYER}!\n"
	.string "You finally got here?\l"
	.string "You're slow like always.$"

OreburghCity_Text_BarryGymLeaderLongGone:
	.string "You're so slow, the Gym Leader's\n"
	.string "long gone now.$"

OreburghCity_Text_BarryHeWentToTheMine:
	.string "He said he had to go... Uh...\n"
	.string "Oh, yea, to {COLOR DYNAMIC_COLOR3}Oreburgh Mine{COLOR DARK_GRAY}!$"

OreburghCity_Text_BarryAlreadyGotMyBadge:
	.string "I got my Badge already, so it's no\n"
	.string "big deal to me, but...$"

OreburghCity_Text_BarryToldYouNotHere:
	.string "I told you, the Gym Leader isn't\n"
	.string "here.$"

OreburghCity_Text_BarryGoDownToTheMine:
	.string "If you want to take the Gym\n"
	.string "challenge, you'd better go down to\l"
	.string "the mine and ask him.$"

OreburghCity_Text_BarryDifferentClass:
	.string "But, boy, a Gym Leader is in a\n"
	.string "different class of toughness.$"

OreburghCity_Text_BarryFeelingRunDown:
	.string "Even I'm feeling run down.$"

OreburghCity_Text_BarryMonferno:
	.string "Mon Mon!$"

OreburghCity_Text_BarryMonfernoSpeaker:
	.string "Monferno$"

OreburghCity_Text_BarryPrinplup:
	.string "Prin! Priiinplup$"

OreburghCity_Text_BarryPrinplupSpeaker:
	.string "Prinplup$"

OreburghCity_Text_BarryGrotle:
	.string "Grooootle!$"

OreburghCity_Text_BarryGrotleSpeaker:
	.string "Grotle$"
