OreburghGate_MapScripts::
	.byte 0

OreburghGate_EventScript_Trainer1::
	trainerbattle_single TRAINER_OREBURGH_GATE_1, OreburghGate_Text_Trainer1Intro, OreburghGate_Text_Trainer1Defeated
	msgbox OreburghGate_Text_Trainer1PostBattle, MSGBOX_AUTOCLOSE
	end

OreburghGate_EventScript_Trainer2::
	trainerbattle_single TRAINER_OREBURGH_GATE_2, OreburghGate_Text_Trainer2Intro, OreburghGate_Text_Trainer2Defeated
	msgbox OreburghGate_Text_Trainer2PostBattle, MSGBOX_AUTOCLOSE
	end

OreburghGate_EventScript_Trainer3::
	trainerbattle_single TRAINER_OREBURGH_GATE_3, OreburghGate_Text_Trainer3Intro, OreburghGate_Text_Trainer3Defeated
	msgbox OreburghGate_Text_Trainer3PostBattle, MSGBOX_AUTOCLOSE
	end

OreburghGate_Text_Trainer1Intro:
	.string "OREBURGH GATE TRAINER 1\n"
	.string "wants to battle!$"

OreburghGate_Text_Trainer1Defeated:
	.string "OREBURGH GATE TRAINER 1\n"
	.string "was defeated!$"

OreburghGate_Text_Trainer1PostBattle:
	.string "OREBURGH GATE TRAINER 1\n"
	.string "has nothing else to say.$"

OreburghGate_Text_Trainer2Intro:
	.string "OREBURGH GATE TRAINER 2\n"
	.string "wants to battle!$"

OreburghGate_Text_Trainer2Defeated:
	.string "OREBURGH GATE TRAINER 2\n"
	.string "was defeated!$"

OreburghGate_Text_Trainer2PostBattle:
	.string "Getting through that cave feels like an\n"
	.string "adventure.$"

OreburghGate_Text_Trainer3Intro:
	.string "OREBURGH GATE TRAINER 3\n"
	.string "wants to battle!$"

OreburghGate_Text_Trainer3Defeated:
	.string "OREBURGH GATE TRAINER 3\n"
	.string "was defeated!$"

OreburghGate_Text_Trainer3PostBattle:
	.string "OREBURGH GATE TRAINER 3\n"
	.string "has nothing else to say.$"

OreburghGate_EventScript_Rock1::
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
	setflag FLAG_HIDE_OREBURGH_GATE_ROCK1
	specialvar VAR_RESULT, TryUpdateRusturfTunnelState
	goto_if_eq VAR_RESULT, TRUE, EventScript_EndSmash
	special RockSmashWildEncounter
	goto_if_eq VAR_RESULT, FALSE, EventScript_EndSmash
	waitstate
	releaseall
	end

OreburghGate_EventScript_Rock2::
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
	setflag FLAG_HIDE_OREBURGH_GATE_ROCK2
	specialvar VAR_RESULT, TryUpdateRusturfTunnelState
	goto_if_eq VAR_RESULT, TRUE, EventScript_EndSmash
	special RockSmashWildEncounter
	goto_if_eq VAR_RESULT, FALSE, EventScript_EndSmash
	waitstate
	releaseall
	end

OreburghGate_EventScript_Rock3::
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
	setflag FLAG_HIDE_OREBURGH_GATE_ROCK3
	specialvar VAR_RESULT, TryUpdateRusturfTunnelState
	goto_if_eq VAR_RESULT, TRUE, EventScript_EndSmash
	special RockSmashWildEncounter
	goto_if_eq VAR_RESULT, FALSE, EventScript_EndSmash
	waitstate
	releaseall
	end

OreburghGate_EventScript_Rock4::
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
	setflag FLAG_HIDE_OREBURGH_GATE_ROCK4
	specialvar VAR_RESULT, TryUpdateRusturfTunnelState
	goto_if_eq VAR_RESULT, TRUE, EventScript_EndSmash
	special RockSmashWildEncounter
	goto_if_eq VAR_RESULT, FALSE, EventScript_EndSmash
	waitstate
	releaseall
	end

OreburghGate_EventScript_Rock5::
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
	setflag FLAG_HIDE_OREBURGH_GATE_ROCK5
	specialvar VAR_RESULT, TryUpdateRusturfTunnelState
	goto_if_eq VAR_RESULT, TRUE, EventScript_EndSmash
	special RockSmashWildEncounter
	goto_if_eq VAR_RESULT, FALSE, EventScript_EndSmash
	waitstate
	releaseall
	end

OreburghGate_EventScript_Rock6::
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
	setflag FLAG_HIDE_OREBURGH_GATE_ROCK6
	specialvar VAR_RESULT, TryUpdateRusturfTunnelState
	goto_if_eq VAR_RESULT, TRUE, EventScript_EndSmash
	special RockSmashWildEncounter
	goto_if_eq VAR_RESULT, FALSE, EventScript_EndSmash
	waitstate
	releaseall
	end

OreburghGate_EventScript_Rock7::
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
	setflag FLAG_HIDE_OREBURGH_GATE_ROCK7
	specialvar VAR_RESULT, TryUpdateRusturfTunnelState
	goto_if_eq VAR_RESULT, TRUE, EventScript_EndSmash
	special RockSmashWildEncounter
	goto_if_eq VAR_RESULT, FALSE, EventScript_EndSmash
	waitstate
	releaseall
	end

OreburghGate_EventScript_Rock8::
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
	setflag FLAG_HIDE_OREBURGH_GATE_ROCK8
	specialvar VAR_RESULT, TryUpdateRusturfTunnelState
	goto_if_eq VAR_RESULT, TRUE, EventScript_EndSmash
	special RockSmashWildEncounter
	goto_if_eq VAR_RESULT, FALSE, EventScript_EndSmash
	waitstate
	releaseall
	end

OreburghGate_EventScript_Rock9::
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
	setflag FLAG_HIDE_OREBURGH_GATE_ROCK9
	specialvar VAR_RESULT, TryUpdateRusturfTunnelState
	goto_if_eq VAR_RESULT, TRUE, EventScript_EndSmash
	special RockSmashWildEncounter
	goto_if_eq VAR_RESULT, FALSE, EventScript_EndSmash
	waitstate
	releaseall
	end
