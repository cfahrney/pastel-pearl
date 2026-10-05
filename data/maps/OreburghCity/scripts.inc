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
	call OreburghCity_EventScript_SetBarryStarterGfx
	return

OreburghCity_EventScript_SetBarryStarterGfx:
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
	.string "Machooop! Chop chop!$"

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
	@ poe:behavior {"mode":"gift","item":"ITEM_SUPER_POTION","qty":1}
	lock
	faceplayer
	goto_if_set FLAG_OREBURGHCITY_NPC6_GIFT, OreburghCity_EventScript_NPC6After
	msgbox OreburghCity_Text_NPC6, MSGBOX_DEFAULT
	giveitem ITEM_SUPER_POTION, 1
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_OREBURGHCITY_NPC6_GIFT
	msgbox OreburghCity_Text_NPC6Received, MSGBOX_DEFAULT
	release
	end

OreburghCity_EventScript_NPC6After::
	msgbox OreburghCity_Text_NPC6After, MSGBOX_DEFAULT
	release
	end

OreburghCity_Text_NPC6Received::
	.string "Feeling hale and heart puts a smile on\n"
	.string "my face. And that makes me happy.$"

OreburghCity_Text_NPC6After::
	.string "Feeling hale and heart puts a smile on\n"
	.string "my face. And that makes me happy.$"

OreburghCity_EventScript_NPC7::
	msgbox OreburghCity_Text_NPC7, MSGBOX_NPC
	end

OreburghCity_EventScript_NPC8::
	msgbox OreburghCity_Text_NPC8, MSGBOX_NPC
	end

OreburghCity_EventScript_NPC9::
	@ poe:behavior {"mode":"plain","options":[{"id":0,"cond":{"var":"VAR_OREBURGH_CITY_STATE","op":"lt","value":3}},{"id":1,"cond":{"var":"VAR_OREBURGH_CITY_STATE","op":"gt","value":3}}]}
	goto_if_lt VAR_OREBURGH_CITY_STATE, 3, OreburghCity_EventScript_NPC9Var0
	msgbox OreburghCity_Text_NPC9Var1, MSGBOX_NPC
	end

OreburghCity_EventScript_NPC9Var0::
	msgbox OreburghCity_Text_NPC9, MSGBOX_NPC
	end

OreburghCity_Text_NPC9Var1::
	.string "Wow, you really did it, you beat Roark!\n"
	.string "That is super impressive! I always\l"
	.string "heard his Cranidos was one tough\l"
	.string "Pokémon.$"

OreburghCity_Text_Sign1:
	.string "Oreburgh City\n"
	.string "City of Energy$"

OreburghCity_Text_Sign2:
	.string "Oreburgh Pokémon Gym\n"
	.string "Leader: Roark$"

OreburghCity_Text_Sign3:
	.string "Oreburgh Mining Museum\n"
	.string "“Coal Mining and You!”$"

OreburghCity_Text_NPC4:
	.string "These rocks make up what is called a\n"
	.string "slag heap. It's the waste from sorting\l"
	.string "all the coal.$"

OreburghCity_Text_NPC5:
	.string "Chop, cop, Machop!\n"
	.string "Chop, chop away on rocks! ~$"

OreburghCity_Text_NPC6:
	.string "There's no question. This is hard, hard\n"
	.string "work.\p"
	.string "But working alongside Pokémon...\n"
	.string "It gives me a boost somehow.\p"
	.string "Here, take this.$"

OreburghCity_Text_NPC7:
	.string "Everyone's proud of the mine. They're\n"
	.string "digging for coal under the sea as we\l"
	.string "speak...\p"
	.string "It's amazing how they do it!$"

OreburghCity_Text_NPC8:
	.string "Up ahead there's a huge mountain that\n"
	.string "towers above everything. It divides\l"
	.string "{COLOR DYNAMIC_COLOR3}Sinnoh{COLOR DARK_GRAY} into two, distinct halves.$"

OreburghCity_Text_NPC9:
	.string "I think Roark does a good job to\n"
	.string "represent {COLOR DYNAMIC_COLOR3}Oreburgh City{COLOR DARK_GRAY}. Do you think\l"
	.string "you'll try to battle him?$"

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

OreburghCity_EventScript_NPC10::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_CARKOL, CRY_MODE_NORMAL
	setspeaker OreburghCity_Text_NPC10Speaker
	msgbox OreburghCity_Text_NPC10, MSGBOX_DEFAULT
	waitmoncry
	release
	end

OreburghCity_Text_NPC10:
	.string "OREBURGH CITY NPC 10$"

OreburghCity_Text_NPC10Speaker:
	.string "Carkol$"

OreburghCity_EventScript_NPC11::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ROLYCOLY, CRY_MODE_NORMAL
	setspeaker OreburghCity_Text_NPC11Speaker
	msgbox OreburghCity_Text_NPC11, MSGBOX_DEFAULT
	waitmoncry
	release
	end

OreburghCity_Text_NPC11:
	.string "OREBURGH CITY NPC 11$"

OreburghCity_Text_NPC11Speaker:
	.string "Rolycoly$"

OreburghCity_EventScript_BarryRunsIntoPlayerAtY11::
	lockall
	setobjectxyperm LOCALID_OREBURGHCITY_BARRY, 17, 13
	setobjectxyperm LOCALID_OREBURGHCITY_BARRY_STARTER, 18, 13
	call OreburghCity_EventScript_SetBarryStarterGfx
	clearflag FLAG_HIDE_OREBURGHCITY_BARRY
	clearflag FLAG_HIDE_OREBURGHCITY_BARRY_STARTER
	addobject LOCALID_OREBURGHCITY_BARRY
	addobject LOCALID_OREBURGHCITY_BARRY_STARTER
	applymovement LOCALID_OREBURGHCITY_BARRY, OreburghCity_Movement_Barry_E11
	applymovement LOCALID_OREBURGHCITY_BARRY_STARTER, OreburghCity_Movement_BarryStarter_E11
	waitmovementall
	applymovement LOCALID_OREBURGHCITY_BARRY, OreburghCity_Movement_Barry_E11Bump
	applymovement LOCALID_OREBURGHCITY_BARRY_STARTER, OreburghCity_Movement_BarryStarter_E11Bump
	waitmovementall
	playse SE_WALL_HIT
	applymovement LOCALID_PLAYER, OreburghCity_Movement_Player_E11
	waitmovement LOCALID_PLAYER
	setvar VAR_0x8008, 11
	goto OreburghCity_EventScript_BarryRunsIntoPlayerFinish
	end

OreburghCity_EventScript_BarryRunsIntoPlayerAtY12::
	lockall
	setobjectxyperm LOCALID_OREBURGHCITY_BARRY, 17, 14
	setobjectxyperm LOCALID_OREBURGHCITY_BARRY_STARTER, 18, 14
	call OreburghCity_EventScript_SetBarryStarterGfx
	clearflag FLAG_HIDE_OREBURGHCITY_BARRY
	clearflag FLAG_HIDE_OREBURGHCITY_BARRY_STARTER
	addobject LOCALID_OREBURGHCITY_BARRY
	addobject LOCALID_OREBURGHCITY_BARRY_STARTER
	applymovement LOCALID_OREBURGHCITY_BARRY, OreburghCity_Movement_Barry_E12
	applymovement LOCALID_OREBURGHCITY_BARRY_STARTER, OreburghCity_Movement_BarryStarter_E12
	waitmovementall
	applymovement LOCALID_OREBURGHCITY_BARRY, OreburghCity_Movement_Barry_E12Bump
	applymovement LOCALID_OREBURGHCITY_BARRY_STARTER, OreburghCity_Movement_BarryStarter_E12Bump
	waitmovementall
	playse SE_WALL_HIT
	applymovement LOCALID_PLAYER, OreburghCity_Movement_Player_E12
	waitmovement LOCALID_PLAYER
	setvar VAR_0x8008, 12
	goto OreburghCity_EventScript_BarryRunsIntoPlayerFinish
	end

OreburghCity_EventScript_BarryRunsIntoPlayerAtY13::
	lockall
	setobjectxyperm LOCALID_OREBURGHCITY_BARRY, 17, 15
	setobjectxyperm LOCALID_OREBURGHCITY_BARRY_STARTER, 18, 15
	call OreburghCity_EventScript_SetBarryStarterGfx
	clearflag FLAG_HIDE_OREBURGHCITY_BARRY
	clearflag FLAG_HIDE_OREBURGHCITY_BARRY_STARTER
	addobject LOCALID_OREBURGHCITY_BARRY
	addobject LOCALID_OREBURGHCITY_BARRY_STARTER
	applymovement LOCALID_OREBURGHCITY_BARRY, OreburghCity_Movement_Barry_E13
	applymovement LOCALID_OREBURGHCITY_BARRY_STARTER, OreburghCity_Movement_BarryStarter_E13
	waitmovementall
	applymovement LOCALID_OREBURGHCITY_BARRY, OreburghCity_Movement_Barry_E13Bump
	applymovement LOCALID_OREBURGHCITY_BARRY_STARTER, OreburghCity_Movement_BarryStarter_E13Bump
	waitmovementall
	playse SE_WALL_HIT
	applymovement LOCALID_PLAYER, OreburghCity_Movement_Player_E13
	waitmovement LOCALID_PLAYER
	setvar VAR_0x8008, 13
	goto OreburghCity_EventScript_BarryRunsIntoPlayerFinish
	end

OreburghCity_EventScript_BarryRunsIntoPlayerFinish::
	msgbox OreburghCity_Text_Thud, MSGBOX_DEFAULT
	applymovement LOCALID_OREBURGHCITY_BARRY, Common_Movement_FacePlayer
	waitmovement LOCALID_OREBURGHCITY_BARRY
	setspeaker SP_NAME_RIVAL
	msgbox OreburghCity_Text_BarryWhoops, MSGBOX_DEFAULT
	closemessage
	goto_if_eq VAR_0x8008, 11, OreburghCity_EventScript_BarryRunsIntoPlayerLeaveY11
	goto_if_eq VAR_0x8008, 12, OreburghCity_EventScript_BarryRunsIntoPlayerLeaveY12
	goto OreburghCity_EventScript_BarryRunsIntoPlayerLeaveY13
	end

OreburghCity_EventScript_BarryRunsIntoPlayerLeaveY11::
	applymovement LOCALID_OREBURGHCITY_BARRY, OreburghCity_Movement_Barry_E11Followup
	applymovement LOCALID_OREBURGHCITY_BARRY_STARTER, OreburghCity_Movement_BarryStarter_E11Followup
	waitmovementall
	goto OreburghCity_EventScript_BarryRunsIntoPlayerWrapUp
	end

OreburghCity_EventScript_BarryRunsIntoPlayerLeaveY12::
	applymovement LOCALID_OREBURGHCITY_BARRY, OreburghCity_Movement_Barry_E12Followup
	applymovement LOCALID_OREBURGHCITY_BARRY_STARTER, OreburghCity_Movement_BarryStarter_E12Followup
	waitmovementall
	goto OreburghCity_EventScript_BarryRunsIntoPlayerWrapUp
	end

OreburghCity_EventScript_BarryRunsIntoPlayerLeaveY13::
	applymovement LOCALID_OREBURGHCITY_BARRY, OreburghCity_Movement_Barry_E13Followup
	applymovement LOCALID_OREBURGHCITY_BARRY_STARTER, OreburghCity_Movement_BarryStarter_E13Followup
	waitmovementall
	goto OreburghCity_EventScript_BarryRunsIntoPlayerWrapUp
	end

OreburghCity_EventScript_BarryRunsIntoPlayerWrapUp::
	playse SE_EXIT
	removeobject LOCALID_OREBURGHCITY_BARRY
	removeobject LOCALID_OREBURGHCITY_BARRY_STARTER
	setflag FLAG_HIDE_OREBURGHCITY_BARRY
	setflag FLAG_HIDE_OREBURGHCITY_BARRY_STARTER
	setvar VAR_OREBURGH_CITY_STATE, 4
	releaseall
	end

OreburghCity_Movement_Barry_E11:
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

OreburghCity_Movement_Barry_E11Bump:
	walk_fast_left
	step_end

OreburghCity_Movement_Barry_E11Followup:
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

OreburghCity_Movement_Barry_E12:
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

OreburghCity_Movement_Barry_E12Bump:
	walk_fast_left
	step_end

OreburghCity_Movement_Barry_E12Followup:
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_up
	walk_fast_left
	walk_fast_left
	step_end

OreburghCity_Movement_Barry_E13:
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

OreburghCity_Movement_Barry_E13Bump:
	walk_fast_left
	step_end

OreburghCity_Movement_Barry_E13Followup:
	walk_fast_up
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

OreburghCity_Movement_BarryStarter_E11:
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

OreburghCity_Movement_BarryStarter_E11Bump:
	walk_fast_left
	step_end

OreburghCity_Movement_BarryStarter_E11Followup:
	walk_fast_left
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

OreburghCity_Movement_BarryStarter_E12:
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

OreburghCity_Movement_BarryStarter_E12Bump:
	walk_fast_left
	step_end

OreburghCity_Movement_BarryStarter_E12Followup:
	walk_fast_left
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_up
	walk_fast_left
	walk_fast_left
	step_end

OreburghCity_Movement_BarryStarter_E13:
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

OreburghCity_Movement_BarryStarter_E13Bump:
	walk_fast_left
	step_end

OreburghCity_Movement_BarryStarter_E13Followup:
	walk_fast_left
	walk_fast_up
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

OreburghCity_Movement_Player_E11:
	walk_left
	face_right
	delay_16
	step_end

OreburghCity_Movement_Player_E12:
	walk_left
	face_right
	delay_16
	step_end

OreburghCity_Movement_Player_E13:
	walk_left
	face_right
	delay_16
	step_end

OreburghCity_Text_Thud:
	.string "THUD!!$"

OreburghCity_Text_BarryWhoops:
	.string "Whoops! {PLAYER}!\n"
	.string "You got the Gym Badge, huh?\p"
	.string "Eterna City is the next place with a Gym\n"
	.string "that gives away Badges, right?\p"
	.string "So, yea, I went to {COLOR DYNAMIC_COLOR3}Route 207{COLOR DARK_GRAY}, but you\n"
	.string "can't go there without a {COLOR DYNAMIC_COLOR3}Bicycle{COLOR DARK_GRAY}.\p"
	.string "I made my team battle and toughened\n"
	.string "them up, so it wasn't a waste.\p"
	.string "So, I'm going back to {COLOR DYNAMIC_COLOR3}Jubilife City{COLOR DARK_GRAY}. Next\n"
	.string "stop, the Eterna Gym Badge!\p"
	.string "Ten seconds before I dash!\p"
	.string "Nine...\p"
	.string "Bah! Who's got time to count?!$"
