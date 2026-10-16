OreburghGate_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, OreburghGate_OnTransition
	.byte 0

OreburghGate_EventScript_Trainer2::
	trainerbattle_single TRAINER_OREBURGH_GATE_2, OreburghGate_Text_Trainer2Intro, OreburghGate_Text_Trainer2Defeated
	msgbox OreburghGate_Text_Trainer2PostBattle, MSGBOX_AUTOCLOSE
	end

OreburghGate_EventScript_Trainer3::
	trainerbattle_single TRAINER_OREBURGH_GATE_3, OreburghGate_Text_Trainer3Intro, OreburghGate_Text_Trainer3Defeated
	msgbox OreburghGate_Text_Trainer3PostBattle, MSGBOX_AUTOCLOSE
	end

OreburghGate_Text_Trainer2Intro:
	.string "To celebrate my getting through this\n"
	.string "cave, I'm going to battle you!$"

OreburghGate_Text_Trainer2Defeated:
	.string "Well, I guess losing is something to\n"
	.string "commemorate, too...$"

OreburghGate_Text_Trainer2PostBattle:
	.string "Getting through that cave feels like an\n"
	.string "adventure.$"

OreburghGate_Text_Trainer3Intro:
	.string "We Trainers will accept challenges\n"
	.string "anywhere! It's what we do.$"

OreburghGate_Text_Trainer3Defeated:
	.string "Hmm... Insufficiently raised?$"

OreburghGate_Text_Trainer3PostBattle:
	.string "Gee... When you're in a cave, wild\n"
	.string "Pokémon can appear anytime!$"

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

OreburghGate_EventScript_NPC1::
	lock
	faceplayer
	goto_if_unset FLAG_BADGE01_GET, OreburghGate_EventScript_NPC1_2
	msgbox OreburghGate_Text_NPC1, MSGBOX_DEFAULT
	closemessage
	release
	end

OreburghGate_EventScript_NPC1_2::
	goto_if_set FLAG_OREBURGH_GATE_HIKER_1, OreburghGate_EventScript_NPC1_2_2
	msgbox OreburghGate_Text_NPC1_2, MSGBOX_DEFAULT
	setvar VAR_0x8004, ITEM_HM_ROCK_SMASH
	setvar VAR_0x8005, 1
	giveitem VAR_0x8004, VAR_0x8005
	call OreburghGate_EventScript_NPC1_2_3
	goto OreburghGate_EventScript_NPC1_2_2

OreburghGate_EventScript_NPC1_2_2::
	msgbox OreburghGate_Text_NPC1_3, MSGBOX_DEFAULT
	closemessage
	release
	end

OreburghGate_EventScript_NPC1_2_3::
	setflag FLAG_OREBURGH_GATE_HIKER_1
	setvar VAR_OREBURGH_GATE_STATE, 2
	return

OreburghGate_EventScript_Trigger1::
	lockall
	playse SE_PIN
	applymovement LOCALID_OREBURGH_GATE_HIKER, OreburghGate_Movement_Hiker
	applymovement LOCALID_PLAYER, OreburghGate_Movement_Player
	waitmovement 0
	msgbox OreburghGate_Text_NPC1_2, MSGBOX_DEFAULT
	setvar VAR_0x8004, ITEM_HM_ROCK_SMASH
	setvar VAR_0x8005, 1
	giveitem VAR_0x8004, VAR_0x8005
	call OreburghGate_EventScript_NPC1_2_3
	msgbox OreburghGate_Text_NPC1_3, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

OreburghGate_OnTransition::
	@ DP: set system flag 2511 (not needed here)
	end

OreburghGate_Movement_Hiker:
	walk_in_place_down
	emote_exclamation_mark
	walk_down
	step_end

OreburghGate_Movement_Player:
	delay_16
	walk_in_place_up
	step_end

OreburghGate_Text_NPC1:
	.string "Oh! Good golly! That's {COLOR DYNAMIC_COLOR3}Oreburgh City{COLOR DARK_GRAY}'s\n"
	.string "Gym Badge!\p"
	.string "All right! Now you can use the hidden\n"
	.string "move Rock Smash on small boulders!$"

OreburghGate_Text_NPC1_2:
	.string "Oh, lookie there! You've got a Pokétch!\p"
	.string "Hmm... You're still a pretty new Trainer,\n"
	.string "aren't you?\p"
	.string "But it's all good! You're a new fellow\n"
	.string "friend of Pokémon!\p"
	.string "So, let me make a gift of this Hidden\n"
	.string "Machine to you!$"

OreburghGate_Text_NPC1_3:
	.string "That Hidden Machine, or HM for short,\n"
	.string "contains the hidden move Rock Smash.\p"
	.string "A Pokémon learning Rock Smash can\n"
	.string "smash small boulders in the field.\p"
	.string "But the Trainer has to have the Gym\n"
	.string "Badge from {COLOR DYNAMIC_COLOR3}Oreburgh City{COLOR DARK_GRAY}.\p"
	.string "If you don't have that Badge, you can't\n"
	.string "make a Pokémon use the hidden move\l"
	.string "Rock Smash outside of battle.$"
