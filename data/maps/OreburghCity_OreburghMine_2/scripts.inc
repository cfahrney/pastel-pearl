OreburghCity_OreburghMine_2_MapScripts::
	.byte 0

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

OreburghCity_OreburghMine_2_EventScript_NPC2::
	msgbox OreburghCity_OreburghMine_2_Text_NPC2, MSGBOX_NPC
	end

OreburghCity_OreburghMine_2_EventScript_NPC3::
	msgbox OreburghCity_OreburghMine_2_Text_NPC3, MSGBOX_NPC
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
	msgbox OreburghCity_OreburghMine_2_Text_NPC6, MSGBOX_NPC
	end

OreburghCity_OreburghMine_2_EventScript_NPC7::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MACHOP, CRY_MODE_NORMAL
	setspeaker OreburghCity_OreburghMine_2_Text_NPC7Speaker
	msgbox OreburghCity_OreburghMine_2_Text_NPC7, MSGBOX_DEFAULT
	waitmoncry
	release
	end

OreburghCity_OreburghMine_2_Text_NPC1:
	.string "OREBURGH MINE 2 NPC 1$"

OreburghCity_OreburghMine_2_Text_NPC2:
	.string "OREBURGH MINE 2 NPC 2$"

OreburghCity_OreburghMine_2_Text_NPC3:
	.string "OREBURGH MINE 2 NPC 3$"

OreburghCity_OreburghMine_2_Text_NPC4:
	.string "OREBURGH MINE 2 NPC 4$"

OreburghCity_OreburghMine_2_Text_NPC4Speaker:
	.string "Machop$"

OreburghCity_OreburghMine_2_Text_NPC5:
	.string "OREBURGH MINE 2 NPC 5$"

OreburghCity_OreburghMine_2_Text_NPC5Speaker:
	.string "Machop$"

OreburghCity_OreburghMine_2_Text_NPC6:
	.string "OREBURGH MINE 2 NPC 6$"

OreburghCity_OreburghMine_2_Text_NPC7:
	.string "OREBURGH MINE 2 NPC 7$"

OreburghCity_OreburghMine_2_Text_NPC7Speaker:
	.string "Machop$"

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
	playmoncry SPECIES_MACHOP, CRY_MODE_NORMAL
	setspeaker OreburghCity_OreburghMine_2_Text_NPC11Speaker
	msgbox OreburghCity_OreburghMine_2_Text_NPC11, MSGBOX_DEFAULT
	waitmoncry
	release
	end

OreburghCity_OreburghMine_2_Text_NPC8:
	.string "OREBURGH MINE 2 NPC 8$"

OreburghCity_OreburghMine_2_Text_NPC8Speaker:
	.string "Machop$"

OreburghCity_OreburghMine_2_Text_NPC9:
	.string "OREBURGH MINE 2 NPC 9$"

OreburghCity_OreburghMine_2_Text_NPC9Speaker:
	.string "Machop$"

OreburghCity_OreburghMine_2_Text_NPC10:
	.string "OREBURGH MINE 2 NPC 10$"

OreburghCity_OreburghMine_2_Text_NPC10Speaker:
	.string "Machop$"

OreburghCity_OreburghMine_2_Text_NPC11:
	.string "OREBURGH MINE 2 NPC 11$"

OreburghCity_OreburghMine_2_Text_NPC11Speaker:
	.string "Machop$"
