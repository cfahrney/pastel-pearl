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
	.string "Fine, all righty then. Just a quick\n"
	.string "battle on my break!$"

OreburghCity_OreburghMine_2_Text_Trainer1Defeated:
	.string "Wahaha! Mercy, I cry mercy!$"

OreburghCity_OreburghMine_2_Text_Trainer1PostBattle:
	.string "I'd better get on back to work...\p"
	.string "You know, I'd rather be traveling around\n"
	.string "with Pokémon the way you do.$"

OreburghCity_OreburghMine_2_Text_Trainer2Intro:
	.string "I'm gonna let you in on a secret... I\n"
	.string "snuck my Pokémon to work!$"

OreburghCity_OreburghMine_2_Text_Trainer2Defeated:
	.string "Well, now aren't you something!$"

OreburghCity_OreburghMine_2_Text_Trainer2PostBattle:
	.string "OK, OK, time for work! I'll work up a\n"
	.string "thirst with my Pokémon!$"

OreburghCity_OreburghMine_2_Text_NPC4:
	.string "Chop chop!$"

OreburghCity_OreburghMine_2_Text_NPC4Speaker:
	.string "Machop$"

OreburghCity_OreburghMine_2_Text_NPC5:
	.string "Chooop$"

OreburghCity_OreburghMine_2_Text_NPC5Speaker:
	.string "Machop$"

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

OreburghCity_OreburghMine_2_EventScript_NPC6::
	lockall
	faceplayer
	goto OreburghCity_OreburghMine_2_EventScript_NPC6_2

OreburghCity_OreburghMine_2_EventScript_NPC6_2::
	applymovement LOCALID_OREBURGHMINE_2_ROARK, OreburghCity_OreburghMine_2_Movement_LocalidOreburghmine2Roark
	waitmovement 0
	goto OreburghCity_OreburghMine_2_EventScript_NPC6_2_2

OreburghCity_OreburghMine_2_EventScript_NPC6_2_3::
	delay 2
	goto_if_eq VAR_0x8005, 0, OreburghCity_OreburghMine_2_EventScript_NPC6_2_3
	faceplayer
	msgbox OreburghCity_OreburghMine_2_Text_NPC6_3, MSGBOX_DEFAULT
	closemessage
	goto OreburghCity_OreburghMine_2_EventScript_NPC6_2_3_2

OreburghCity_OreburghMine_2_EventScript_NPC6_2_3_2::
	applymovement LOCALID_OREBURGHMINE_2_ROARK, OreburghCity_OreburghMine_2_Movement_LocalidOreburghmine2Roark2
	waitmovement 0
	goto OreburghCity_OreburghMine_2_EventScript_NPC6_2_3_2_2

OreburghCity_OreburghMine_2_EventScript_NPC6_2_3_2_2::
	removeobject LOCALID_OREBURGHMINE_2_ROARK
	setflag FLAG_OREBURGH_CITY_OREBURGH_MINE_2_ROARK_1
	setflag FLAG_OREBURGH_CITY_OREBURGH_MINE_2_ROARK_2
	releaseall
	end

OreburghCity_OreburghMine_2_EventScript_NPC6_2_2::
	msgbox OreburghCity_OreburghMine_2_Text_NPC6_2, MSGBOX_DEFAULT
	closemessage
	@ TODO(DP): HMEffect 2, 32773
	delay 20
	@ TODO(DP): hide DP object 1
	goto OreburghCity_OreburghMine_2_EventScript_NPC6_2_3

OreburghCity_OreburghMine_2_Movement_LocalidOreburghmine2Roark:
	delay_16
	delay_16
	walk_in_place_right
	delay_16
	delay_16
	delay_16
	delay_16
	step_end

OreburghCity_OreburghMine_2_Movement_LocalidOreburghmine2Roark2:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

OreburghCity_OreburghMine_2_Text_NPC6_2:
	.string "OK, stand back and watch this.\p"
	.string "Using the hidden move Rock Smash, a\n"
	.string "boulder blocking your way...$"

OreburghCity_OreburghMine_2_Text_NPC6_3:
	.string "Fallen boulders need to be smashed so\n"
	.string "they're out of the way.\p"
	.string "If you could get the Badge from the Gym\n"
	.string "in town, you'd be able to do this too.\p"
	.string "Of course, you'd have to beat the Gym\n"
	.string "Leader first. That'd be me!$"
