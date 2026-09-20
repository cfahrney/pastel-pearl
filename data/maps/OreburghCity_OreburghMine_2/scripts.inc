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
	msgbox OreburghCity_OreburghMine_2_Text_NPC4, MSGBOX_DEFAULT
	waitmoncry
	release
	end

OreburghCity_OreburghMine_2_EventScript_NPC5::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MACHOP, CRY_MODE_NORMAL
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

OreburghCity_OreburghMine_2_Text_NPC5:
	.string "OREBURGH MINE 2 NPC 5$"

OreburghCity_OreburghMine_2_Text_NPC6:
	.string "OREBURGH MINE 2 NPC 6$"

OreburghCity_OreburghMine_2_Text_NPC7:
	.string "OREBURGH MINE 2 NPC 7$"
