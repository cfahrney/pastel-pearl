OreburghCity_OreburghMine_2_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, OreburghCity_OreburghMine_2_OnTransition
	.byte 0

OreburghCity_OreburghMine_2_OnTransition:
	@ Roark is only here for the Rock Smash demo (state < 2).
	setflag FLAG_HIDE_OREBURGHMINE_2_ROARK
	call_if_lt VAR_OREBURGH_CITY_STATE, 2, OreburghCity_OreburghMine_2_EventScript_ShowRoark
	end

OreburghCity_OreburghMine_2_EventScript_ShowRoark::
	clearflag FLAG_HIDE_OREBURGHMINE_2_ROARK
	return

OreburghCity_OreburghMine_2_EventScript_Rock1::
	lockall
	checkfieldmove FIELD_MOVE_ROCK_SMASH, TRUE
	goto_if_eq VAR_RESULT, PARTY_SIZE, EventScript_CantSmashRock
	setfieldeffectargument 0, VAR_RESULT
	bufferpartymonnick STR_VAR_1, VAR_RESULT
	buffermovename STR_VAR_2, MOVE_ROCK_SMASH
	msgbox Text_WantToSmash, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_CancelSmash
	msgbox Text_MonUsedFieldMove, MSGBOX_DEFAULT
	closemessage
	isfollowerfieldmoveuser VAR_0x8004
	setfieldeffectargument 3, VAR_0x8004
	dofieldeffect FLDEFF_USE_ROCK_SMASH
	waitstate
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	call_if_eq VAR_0x8004, TRUE, EventScript_FollowerFieldMove
	applymovement VAR_LAST_TALKED, Movement_SmashRock
	waitmovement 0
	removeobject VAR_LAST_TALKED
	setflag FLAG_HIDE_OREBURGH_MINE_2_ROCK1
	special RockSmashWildEncounter
	goto_if_eq VAR_RESULT, FALSE, EventScript_EndSmash
	waitstate
	releaseall
	end

OreburghCity_OreburghMine_2_EventScript_Rock2::
	lockall
	checkfieldmove FIELD_MOVE_ROCK_SMASH, TRUE
	goto_if_eq VAR_RESULT, PARTY_SIZE, EventScript_CantSmashRock
	setfieldeffectargument 0, VAR_RESULT
	bufferpartymonnick STR_VAR_1, VAR_RESULT
	buffermovename STR_VAR_2, MOVE_ROCK_SMASH
	msgbox Text_WantToSmash, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_CancelSmash
	msgbox Text_MonUsedFieldMove, MSGBOX_DEFAULT
	closemessage
	isfollowerfieldmoveuser VAR_0x8004
	setfieldeffectargument 3, VAR_0x8004
	dofieldeffect FLDEFF_USE_ROCK_SMASH
	waitstate
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	call_if_eq VAR_0x8004, TRUE, EventScript_FollowerFieldMove
	applymovement VAR_LAST_TALKED, Movement_SmashRock
	waitmovement 0
	removeobject VAR_LAST_TALKED
	setflag FLAG_HIDE_OREBURGH_MINE_2_ROCK2
	special RockSmashWildEncounter
	goto_if_eq VAR_RESULT, FALSE, EventScript_EndSmash
	waitstate
	releaseall
	end

OreburghCity_OreburghMine_2_EventScript_NPC1::
	msgbox OreburghCity_OreburghMine_2_Text_NPC1, MSGBOX_NPC
	end

OreburghCity_OreburghMine_2_EventScript_Trainer1::
	trainerbattle_single TRAINER_OREBURGH_CITY_OREBURGH_MINE_2_1, OreburghCity_OreburghMine_2_Text_Trainer1Intro, OreburghCity_OreburghMine_2_Text_Trainer1Defeated
	msgbox OreburghCity_OreburghMine_2_Text_Trainer1PostBattle, MSGBOX_AUTOCLOSE
	end

OreburghCity_OreburghMine_2_EventScript_Trainer2::
	trainerbattle_single TRAINER_OREBURGH_CITY_OREBURGH_MINE_2_2, OreburghCity_OreburghMine_2_Text_Trainer2Intro, OreburghCity_OreburghMine_2_Text_Trainer2Defeated
	msgbox OreburghCity_OreburghMine_2_Text_Trainer2PostBattle, MSGBOX_AUTOCLOSE
	end

OreburghCity_OreburghMine_2_EventScript_NPC4::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MACHOP, CRY_MODE_NORMAL
	setspeaker OreburghCity_OreburghMine_2_Text_NPC4Speaker
	msgbox OreburghCity_OreburghMine_2_Text_NPC4, MSGBOX_DEFAULT
	waitmoncry
	release
	end

OreburghCity_OreburghMine_2_EventScript_NPC5::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MACHOP, CRY_MODE_NORMAL
	setspeaker OreburghCity_OreburghMine_2_Text_NPC5Speaker
	msgbox OreburghCity_OreburghMine_2_Text_NPC5, MSGBOX_DEFAULT
	waitmoncry
	release
	end

OreburghCity_OreburghMine_2_EventScript_NPC6::
	lock
	goto_if_ge VAR_OREBURGH_CITY_STATE, 2, OreburghCity_OreburghMine_2_EventScript_NPC6Default
	applymovement LOCALID_OREBURGHMINE_2_ROARK, OreburghCity_OreburghMine_2_Movement_Roark_OnGreeting
	waitmovement LOCALID_OREBURGHMINE_2_ROARK
	setspeaker SP_NAME_ROARK
	msgbox OreburghCity_OreburghMine_2_Text_RoarkDemoIntro, MSGBOX_DEFAULT
	closemessage
	playse SE_M_ROCK_THROW
	applymovement LOCALID_OREBURGHMINE_2_ROCK2, Movement_SmashRock
	waitmovement LOCALID_OREBURGHMINE_2_ROCK2
	removeobject LOCALID_OREBURGHMINE_2_ROCK2
	setflag FLAG_HIDE_OREBURGH_MINE_2_ROCK2
	applymovement LOCALID_OREBURGHMINE_2_ROARK, OreburghCity_OreburghMine_2_Movement_Roark_AfterRockSmash
	waitmovement LOCALID_OREBURGHMINE_2_ROARK
	setspeaker SP_NAME_ROARK
	msgbox OreburghCity_OreburghMine_2_Text_RoarkDemoOutro, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_OREBURGHMINE_2_ROARK, OreburghCity_OreburghMine_2_Movement_Roark_OnSceneEnd
	waitmovement LOCALID_OREBURGHMINE_2_ROARK
	removeobject LOCALID_OREBURGHMINE_2_ROARK
	setflag FLAG_HIDE_OREBURGHMINE_2_ROARK
	setvar VAR_OREBURGH_CITY_STATE, 2
	release
	end

OreburghCity_OreburghMine_2_EventScript_NPC6Default::
	msgbox OreburghCity_OreburghMine_2_Text_NPC6, MSGBOX_DEFAULT
	release
	end

OreburghCity_OreburghMine_2_Movement_Roark_OnGreeting:
	face_down
	delay_16
	delay_16
	delay_16
	face_right
	step_end

OreburghCity_OreburghMine_2_Movement_Roark_AfterRockSmash:
	face_down
	delay_16
	delay_16
	step_end

OreburghCity_OreburghMine_2_Movement_Roark_OnSceneEnd:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	step_end

OreburghCity_OreburghMine_2_EventScript_NPC7::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_CARKOL, CRY_MODE_NORMAL
	setspeaker OreburghCity_OreburghMine_2_Text_NPC7Speaker
	msgbox OreburghCity_OreburghMine_2_Text_NPC7, MSGBOX_DEFAULT
	waitmoncry
	release
	end

OreburghCity_OreburghMine_2_Text_NPC1:
	.string "OREBURGH MINE 2 NPC 1$"

OreburghCity_OreburghMine_2_Text_Trainer1Intro:
	.string "OREBURGH MINE 2 TRAINER 1\nwants to battle!$"

OreburghCity_OreburghMine_2_Text_Trainer1Defeated:
	.string "OREBURGH MINE 2 TRAINER 1\nwas defeated!$"

OreburghCity_OreburghMine_2_Text_Trainer1PostBattle:
	.string "OREBURGH MINE 2 TRAINER 1\nhas nothing else to say.$"

OreburghCity_OreburghMine_2_Text_Trainer2Intro:
	.string "OREBURGH MINE 2 TRAINER 2\nwants to battle!$"

OreburghCity_OreburghMine_2_Text_Trainer2Defeated:
	.string "OREBURGH MINE 2 TRAINER 2\nwas defeated!$"

OreburghCity_OreburghMine_2_Text_Trainer2PostBattle:
	.string "OREBURGH MINE 2 TRAINER 2\nhas nothing else to say.$"

OreburghCity_OreburghMine_2_Text_NPC4:
	.string "Chop chop!$"

OreburghCity_OreburghMine_2_Text_NPC4Speaker:
	.string "Machop$"

OreburghCity_OreburghMine_2_Text_NPC5:
	.string "Chooop$"

OreburghCity_OreburghMine_2_Text_NPC5Speaker:
	.string "Machop$"

OreburghCity_OreburghMine_2_Text_NPC6:
	.string "OREBURGH MINE 2 NPC 6$"

OreburghCity_OreburghMine_2_Text_NPC7:
	.string "Kooool.$"

OreburghCity_OreburghMine_2_Text_NPC7Speaker:
	.string "Carkol$"

OreburghCity_OreburghMine_2_EventScript_NPC8::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MACHOP, CRY_MODE_NORMAL
	setspeaker OreburghCity_OreburghMine_2_Text_NPC8Speaker
	msgbox OreburghCity_OreburghMine_2_Text_NPC8, MSGBOX_DEFAULT
	waitmoncry
	release
	end

OreburghCity_OreburghMine_2_EventScript_NPC9::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MACHOP, CRY_MODE_NORMAL
	setspeaker OreburghCity_OreburghMine_2_Text_NPC9Speaker
	msgbox OreburghCity_OreburghMine_2_Text_NPC9, MSGBOX_DEFAULT
	waitmoncry
	release
	end

OreburghCity_OreburghMine_2_EventScript_NPC10::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MACHOP, CRY_MODE_NORMAL
	setspeaker OreburghCity_OreburghMine_2_Text_NPC10Speaker
	msgbox OreburghCity_OreburghMine_2_Text_NPC10, MSGBOX_DEFAULT
	waitmoncry
	release
	end

OreburghCity_OreburghMine_2_EventScript_NPC11::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ROLYCOLY, CRY_MODE_NORMAL
	setspeaker OreburghCity_OreburghMine_2_Text_NPC11Speaker
	msgbox OreburghCity_OreburghMine_2_Text_NPC11, MSGBOX_DEFAULT
	waitmoncry
	release
	end

OreburghCity_OreburghMine_2_Text_NPC8:
	.string "Chooop$"

OreburghCity_OreburghMine_2_Text_NPC8Speaker:
	.string "Machop$"

OreburghCity_OreburghMine_2_Text_NPC9:
	.string "Chooop$"

OreburghCity_OreburghMine_2_Text_NPC9Speaker:
	.string "Machop$"

OreburghCity_OreburghMine_2_Text_NPC10:
	.string "Chooop$"

OreburghCity_OreburghMine_2_Text_NPC10Speaker:
	.string "Machop$"

OreburghCity_OreburghMine_2_Text_NPC11:
	.string "Coly!$"

OreburghCity_OreburghMine_2_Text_NPC11Speaker:
	.string "Rolycoly$"

OreburghCity_OreburghMine_2_Text_RoarkDemoIntro:
	.string "OK, stand back and watch this.\p"
	.string "Using the hidden move Rock Smash, a\n"
	.string "boulder blocking your way...$"

OreburghCity_OreburghMine_2_Text_RoarkDemoOutro:
	.string "Fallen boulders need to be smashed so\n"
	.string "they're out of the way.\p"
	.string "If you could get the Badge from the Gym\n"
	.string "in town, you'd be able to do this too.\p"
	.string "Of course, you'd have to beat the Gym\n"
	.string "Leader first. That'd be me!$"
