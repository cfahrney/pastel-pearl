TwinleafTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, TwinleafTown_OnTransition
	.byte 0

@ MOM's "sandgem not far" line (see TwinleafTown_PlayerHouse_1F) is only
@ meant to be heard while the player is still inside the house right
@ after the homecoming scene. Stepping back outside clears it, so her
@ next indoor visit gets the repeatable welcome-home/rest offer instead.
TwinleafTown_OnTransition:
	setflag FLAG_VISITED_TWINLEAF_TOWN
	call_if_ge VAR_TWINLEAF_TOWN_STATE, 12, TwinleafTown_EventScript_ClearMomSandgemFlag
	@ No wild encounters before the player has a starter.
	call_if_lt VAR_TWINLEAF_TOWN_STATE, 12, TwinleafTown_EventScript_DisableWildEncounters
	call_if_ge VAR_TWINLEAF_TOWN_STATE, 12, TwinleafTown_EventScript_EnableWildEncounters
	end

TwinleafTown_EventScript_ClearMomSandgemFlag:
	clearflag FLAG_TWINLEAF_TOWN_PLAYER_HOUSE_MOM_MENTIONED_SANDGEM
	return

TwinleafTown_EventScript_DisableWildEncounters:
	setflag FLAG_WILD_ENCOUNTERS_DISABLED
	return

TwinleafTown_EventScript_EnableWildEncounters:
	clearflag FLAG_WILD_ENCOUNTERS_DISABLED
	return

TwinleafTown_EventScript_TechEnthusiast::
	msgbox TwinleafTown_Text_TechnologyBlowsMeAway, MSGBOX_NPC
	end

TwinleafTown_Text_TechnologyBlowsMeAway:
	.string "Technology just blows me away!\p"
	.string "I mean, now you can play with people\n"
	.string "around the world…wirelessly!$"

TwinleafTown_EventScript_Woman::
	goto_if_ge VAR_TWINLEAF_TOWN_STATE, 12, TwinleafTown_EventScript_WomanAfterStarterCaught
	msgbox TwinleafTown_Text_WildPokemonAttackButAlsoFriends, MSGBOX_NPC
	end

TwinleafTown_EventScript_WomanAfterStarterCaught::
	msgbox TwinleafTown_Text_LookGoodTogether, MSGBOX_NPC
	end

TwinleafTown_Text_WildPokemonAttackButAlsoFriends:
	.string "It's true that wild POKéMON do\n"
	.string "attack people sometimes…\p"
	.string "However, POKéMON also let you\n"
	.string "become friends with them.$"

TwinleafTown_Text_LookGoodTogether:
	.string "Oh! A POKéMON!\n"
	.string "You look good together!$"

@ Once VAR_TWINLEAF_TOWN_STATE reaches 2, BARRY has already run off toward
@ ROUTE 201 (see TwinleafTown_BarryHouse_2F_EventScript_BarryNoticesPlayer),
@ so the neighbor's line updates to match, same convention as
@ TwinleafTown_BarryHouse_1F_EventScript_Mom.
TwinleafTown_EventScript_Neighbor::
	goto_if_ge VAR_TWINLEAF_TOWN_STATE, 2, TwinleafTown_EventScript_NeighborAfterBarryLeft
	msgbox TwinleafTown_Text_BarryWasLookingForYou, MSGBOX_NPC
	end

TwinleafTown_EventScript_NeighborAfterBarryLeft::
	msgbox TwinleafTown_Text_BarryWentTearingOff, MSGBOX_NPC
	end

TwinleafTown_Text_BarryWasLookingForYou:
	.string "Hiya, {PLAYER}.\n"
	.string "{RIVAL} was looking for you.\p"
	.string "I think he's home now.\n"
	.string "Why don't you go check it out?$"

TwinleafTown_Text_BarryWentTearingOff:
	.string "Hiya, {PLAYER}.\n"
	.string "You're looking for {RIVAL}?\p"
	.string "He just went tearing off a little\n"
	.string "while ago.\p"
	.string "He's probably not gone too far.\n"
	.string "Why not go chase after him?$"

@ VAR_TWINLEAF_TOWN_STATE == 0: the neighbor runs up from his usual spot to
@ block the path north until the player has gone to see {RIVAL}. One wrapper
@ per trigger tile, since each starts him at a different horizontal distance
@ from his home position (6, 5) to reach (triggerX, 2) above the player.
@
@ Every approach path climbs from row 5 to row 2 via column 6 (his home
@ column) FIRST, then moves sideways along row 2 to line up over the trigger
@ column — row 2 and column 6 are never occupied by the player, who's
@ standing on row 3, so this never routes him through the player. The lone
@ exception is the X6 trigger itself (home column == trigger column), which
@ detours one tile right before climbing so it doesn't climb straight through
@ the player either. The return trip (after the dialogue) is the exact
@ reverse of whichever approach was used.
TwinleafTown_EventScript_NeighborBlocksPlayerAtX6::
	lockall
	applymovement LOCALID_TWINLEAF_NEIGHBOR, TwinleafTown_Movement_NeighborToX6
	waitmovement 0
	setvar VAR_0x8004, 6
	goto TwinleafTown_EventScript_NeighborBlocksPlayerCommon

TwinleafTown_EventScript_NeighborBlocksPlayerAtX7::
	lockall
	applymovement LOCALID_TWINLEAF_NEIGHBOR, TwinleafTown_Movement_NeighborToX7
	waitmovement 0
	setvar VAR_0x8004, 7
	goto TwinleafTown_EventScript_NeighborBlocksPlayerCommon

TwinleafTown_EventScript_NeighborBlocksPlayerAtX8::
	lockall
	applymovement LOCALID_TWINLEAF_NEIGHBOR, TwinleafTown_Movement_NeighborToX8
	waitmovement 0
	setvar VAR_0x8004, 8
	goto TwinleafTown_EventScript_NeighborBlocksPlayerCommon

TwinleafTown_EventScript_NeighborBlocksPlayerAtX9::
	lockall
	applymovement LOCALID_TWINLEAF_NEIGHBOR, TwinleafTown_Movement_NeighborToX9
	waitmovement 0
	setvar VAR_0x8004, 9
	goto TwinleafTown_EventScript_NeighborBlocksPlayerCommon

TwinleafTown_EventScript_NeighborBlocksPlayerAtX10::
	lockall
	applymovement LOCALID_TWINLEAF_NEIGHBOR, TwinleafTown_Movement_NeighborToX10
	waitmovement 0
	setvar VAR_0x8004, 10
	goto TwinleafTown_EventScript_NeighborBlocksPlayerCommon

TwinleafTown_EventScript_NeighborBlocksPlayerAtX11::
	lockall
	applymovement LOCALID_TWINLEAF_NEIGHBOR, TwinleafTown_Movement_NeighborToX11
	waitmovement 0
	setvar VAR_0x8004, 11
	goto TwinleafTown_EventScript_NeighborBlocksPlayerCommon

TwinleafTown_EventScript_NeighborBlocksPlayerAtX12::
	lockall
	applymovement LOCALID_TWINLEAF_NEIGHBOR, TwinleafTown_Movement_NeighborToX12
	waitmovement 0
	setvar VAR_0x8004, 12
	goto TwinleafTown_EventScript_NeighborBlocksPlayerCommon

TwinleafTown_EventScript_NeighborBlocksPlayerAtX13::
	lockall
	applymovement LOCALID_TWINLEAF_NEIGHBOR, TwinleafTown_Movement_NeighborToX13
	waitmovement 0
	setvar VAR_0x8004, 13
	goto TwinleafTown_EventScript_NeighborBlocksPlayerCommon

TwinleafTown_EventScript_NeighborBlocksPlayerCommon:
	applymovement LOCALID_TWINLEAF_NEIGHBOR, Common_Movement_FaceDown
	waitmovement 0
	msgbox TwinleafTown_Text_BarryWasLookingForYou, MSGBOX_DEFAULT
	@ Step the player back off the trigger tile so walking up again re-fires it,
	@ instead of silently slipping past since they'd already be standing on it.
	applymovement LOCALID_PLAYER, TwinleafTown_Movement_PlayerStepBack
	waitmovement 0
	goto_if_eq VAR_0x8004, 7, TwinleafTown_EventScript_NeighborReturnFromX7
	goto_if_eq VAR_0x8004, 8, TwinleafTown_EventScript_NeighborReturnFromX8
	goto_if_eq VAR_0x8004, 9, TwinleafTown_EventScript_NeighborReturnFromX9
	goto_if_eq VAR_0x8004, 10, TwinleafTown_EventScript_NeighborReturnFromX10
	goto_if_eq VAR_0x8004, 11, TwinleafTown_EventScript_NeighborReturnFromX11
	goto_if_eq VAR_0x8004, 12, TwinleafTown_EventScript_NeighborReturnFromX12
	goto_if_eq VAR_0x8004, 13, TwinleafTown_EventScript_NeighborReturnFromX13
	applymovement LOCALID_TWINLEAF_NEIGHBOR, TwinleafTown_Movement_NeighborBackFromX6
	waitmovement 0
	releaseall
	end

TwinleafTown_EventScript_NeighborReturnFromX7::
	applymovement LOCALID_TWINLEAF_NEIGHBOR, TwinleafTown_Movement_NeighborBackFromX7
	waitmovement 0
	releaseall
	end

TwinleafTown_EventScript_NeighborReturnFromX8::
	applymovement LOCALID_TWINLEAF_NEIGHBOR, TwinleafTown_Movement_NeighborBackFromX8
	waitmovement 0
	releaseall
	end

TwinleafTown_EventScript_NeighborReturnFromX9::
	applymovement LOCALID_TWINLEAF_NEIGHBOR, TwinleafTown_Movement_NeighborBackFromX9
	waitmovement 0
	releaseall
	end

TwinleafTown_EventScript_NeighborReturnFromX10::
	applymovement LOCALID_TWINLEAF_NEIGHBOR, TwinleafTown_Movement_NeighborBackFromX10
	waitmovement 0
	releaseall
	end

TwinleafTown_EventScript_NeighborReturnFromX11::
	applymovement LOCALID_TWINLEAF_NEIGHBOR, TwinleafTown_Movement_NeighborBackFromX11
	waitmovement 0
	releaseall
	end

TwinleafTown_EventScript_NeighborReturnFromX12::
	applymovement LOCALID_TWINLEAF_NEIGHBOR, TwinleafTown_Movement_NeighborBackFromX12
	waitmovement 0
	releaseall
	end

TwinleafTown_EventScript_NeighborReturnFromX13::
	applymovement LOCALID_TWINLEAF_NEIGHBOR, TwinleafTown_Movement_NeighborBackFromX13
	waitmovement 0
	releaseall
	end

TwinleafTown_Movement_PlayerStepBack:
	lock_facing_direction
	walk_down
	unlock_facing_direction
	step_end

TwinleafTown_Movement_NeighborToX6:
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_left
	step_end

TwinleafTown_Movement_NeighborToX7:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_right
	step_end

TwinleafTown_Movement_NeighborToX8:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	step_end

TwinleafTown_Movement_NeighborToX9:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

TwinleafTown_Movement_NeighborToX10:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

TwinleafTown_Movement_NeighborToX11:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

TwinleafTown_Movement_NeighborToX12:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

TwinleafTown_Movement_NeighborToX13:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

TwinleafTown_Movement_NeighborBackFromX6:
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_left
	step_end

TwinleafTown_Movement_NeighborBackFromX7:
	walk_fast_left
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

TwinleafTown_Movement_NeighborBackFromX8:
	walk_fast_left
	walk_fast_left
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

TwinleafTown_Movement_NeighborBackFromX9:
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

TwinleafTown_Movement_NeighborBackFromX10:
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

TwinleafTown_Movement_NeighborBackFromX11:
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

TwinleafTown_Movement_NeighborBackFromX12:
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

TwinleafTown_Movement_NeighborBackFromX13:
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

@ VAR_TWINLEAF_TOWN_STATE == 0: stepping onto the tile in front of BARRY's
@ door has him burst out and run into the player, tell them to meet him at
@ the lake, then rush partway there before realizing he forgot something and
@ ducking back inside. Advances the state var to 1 at the end, which is also
@ what lets the player past the neighbor's roadblock up north.
TwinleafTown_EventScript_BarryLeavesHouse::
	lockall
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	@ Door has to be fully open before BARRY appears, to read as him coming
	@ from inside rather than materializing on top of a still-closed door.
	opendoor 5, 10
	waitdooranim
	addobject LOCALID_TWINLEAF_BARRY
	applymovement LOCALID_TWINLEAF_BARRY, TwinleafTown_Movement_BarryExitHouse
	applymovement LOCALID_PLAYER, TwinleafTown_Movement_PlayerStepBack
	waitmovement 0
	@ Swings shut right as he clears the doorway, in sync with the THUD.
	closedoor 5, 10
	playse SE_WALL_HIT
	playbgm MUS_RIVAL_THEME, TRUE
	msgbox TwinleafTown_Text_ThudGoingToTheLake, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, Common_Movement_FaceRight
	applymovement LOCALID_TWINLEAF_BARRY, TwinleafTown_Movement_BarryRunToX8
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_TWINLEAF_BARRY, TwinleafTown_Movement_BarryExclaim
	waitmovement 0
	applymovement LOCALID_TWINLEAF_BARRY, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	applymovement LOCALID_TWINLEAF_BARRY, TwinleafTown_Movement_BarryRunBackAndFacePlayer
	waitmovement 0
	msgbox TwinleafTown_Text_ForgotSomething, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_TWINLEAF_BARRY, TwinleafTown_Movement_BarryFaceDoor
	waitmovement 0
	opendoor 5, 10
	waitdooranim
	applymovement LOCALID_TWINLEAF_BARRY, TwinleafTown_Movement_BarryWalkThroughDoor
	waitmovement 0
	@ Removed before closing, so the door doesn't visibly shut on top of
	@ him — he should vanish through the doorway first.
	removeobject LOCALID_TWINLEAF_BARRY
	closedoor 5, 10
	waitdooranim
	savebgm MUS_DUMMY
	fadedefaultbgm
	setvar VAR_TWINLEAF_TOWN_STATE, 1
	releaseall
	end

TwinleafTown_Text_ThudGoingToTheLake:
	.string "THUD!!\p"
	.string "What was that about?!\p"
	.string "Oh, hey, {PLAYER}!\p"
	.string "Hey! I'm going to the lake!\n"
	.string "You come too! And be quick about it!\p"
	.string "OK, {PLAYER}? I'm fining you a\n"
	.string "million bucks if you're late!$"

TwinleafTown_Text_ForgotSomething:
	.string "Oh, jeez! Forgot something!$"

TwinleafTown_Movement_BarryExitHouse:
	walk_down
	step_end

TwinleafTown_Movement_BarryRunToX8:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

TwinleafTown_Movement_BarryExclaim:
	emote_exclamation_mark
	step_end

TwinleafTown_Movement_BarryRunBackAndFacePlayer:
	walk_fast_left
	walk_fast_left
	walk_fast_left
	face_player
	step_end

TwinleafTown_Movement_BarryFaceDoor:
	face_up
	step_end

TwinleafTown_Movement_BarryWalkThroughDoor:
	walk_up
	step_end

TwinleafTown_EventScript_TownSign::
	msgbox TwinleafTown_Text_TownSign, MSGBOX_SIGN
	end

TwinleafTown_Text_TownSign:
	.string "Twinleaf Town\n"
	.string "“A refreshing town that smells\l"
	.string "of country living.”$"
