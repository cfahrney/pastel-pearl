VerityLakefront_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, VerityLakefront_OnFrame
	.byte 0

@ Fires when VAR_TWINLEAF_TOWN_STATE == 9, right after warping back from
@ LAKE VERITY. Swaps BARRY from follower to a stand-in object for the
@ walk-in, then restores him as a follower.
VerityLakefront_OnFrame:
	map_script_2 VAR_TWINLEAF_TOWN_STATE, 9, VerityLakefront_EventScript_ReturnFromLake
	.2byte 0

VerityLakefront_EventScript_ReturnFromLake::
	lockall
	destroyfollowernpc
	clearflag FLAG_HIDE_VERITY_LAKEFRONT_BARRY
	addobject LOCALID_VERITY_LAKEFRONT_BARRY
	applymovement LOCALID_PLAYER, VerityLakefront_Movement_WalkDown2
	applymovement LOCALID_VERITY_LAKEFRONT_BARRY, VerityLakefront_Movement_WalkDown3
	waitmovementall
	applymovement LOCALID_VERITY_LAKEFRONT_BARRY, Common_Movement_FaceUp
	waitmovement 0
	msgbox VerityLakefront_Text_YouGoAhead, MSGBOX_DEFAULT
	closemessage
	msgbox VerityLakefront_Text_HaveToReturnThesePokemon, MSGBOX_DEFAULT
	closemessage
	msgbox VerityLakefront_Text_LittleMoreTimeWithThisGuy, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_VERITY_LAKEFRONT_BARRY, VerityLakefront_Movement_BarryRejoin
	waitmovement 0
	setfollowernpc LOCALID_VERITY_LAKEFRONT_BARRY, FNPC_ALL
	setvar VAR_TWINLEAF_TOWN_STATE, 10
	releaseall
	end

@ Blocks the player from heading back to the lake while
@ VAR_TWINLEAF_TOWN_STATE == 10. Repeatable trigger, doesn't advance state.
VerityLakefront_EventScript_BarryStopsReturnToLake::
	lockall
	facefollowernpc
	msgbox VerityLakefront_Text_WhereAreYouGoing, MSGBOX_DEFAULT
	closemessage
	msgbox VerityLakefront_Text_HaveToReturnThesePokemonAgain, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, Common_Movement_WalkDown
	applymovement OBJ_EVENT_ID_NPC_FOLLOWER, Common_Movement_WalkDown
	waitmovementall
	releaseall
	end

@ Triggers on VAR_TWINLEAF_TOWN_STATE == 3. Has BARRY hype up the lake,
@ walk the player in, and warp to LAKE VERITY, advancing state to 4.
VerityLakefront_EventScript_BarryHypesUpTheLakeAtX4::
	lockall
	facefollowernpc
	msgbox VerityLakefront_Text_RedGyaradosLake, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, Common_Movement_WalkUp
	applymovement OBJ_EVENT_ID_NPC_FOLLOWER, Common_Movement_WalkUp
	waitmovementall
	setvar VAR_TWINLEAF_TOWN_STATE, 4
	warp MAP_LAKE_VERITY, 38, 41
	waitstate
	releaseall
	end

VerityLakefront_EventScript_BarryHypesUpTheLakeAtX5::
	lockall
	facefollowernpc
	msgbox VerityLakefront_Text_RedGyaradosLake, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, Common_Movement_WalkUp
	applymovement OBJ_EVENT_ID_NPC_FOLLOWER, Common_Movement_WalkUp
	waitmovementall
	setvar VAR_TWINLEAF_TOWN_STATE, 4
	warp MAP_LAKE_VERITY, 39, 41
	waitstate
	releaseall
	end

VerityLakefront_Text_RedGyaradosLake:
	.string "All right! To the lake!\n"
	.string "Let's find us a red GYARADOS!$"

VerityLakefront_Text_YouGoAhead:
	.string "You go ahead…$"

VerityLakefront_Text_HaveToReturnThesePokemon:
	.string "…I know we have to\n"
	.string "return these POKéMON.\l"
	.string "They're not ours.$"

VerityLakefront_Text_LittleMoreTimeWithThisGuy:
	.string "But I want to spend just a\n"
	.string "little more time with this\l"
	.string "little guy…$"

VerityLakefront_Text_WhereAreYouGoing:
	.string "Hey hey!\n"
	.string "Where do you think you're\l"
	.string "going?$"

VerityLakefront_Text_HaveToReturnThesePokemonAgain:
	.string "We have to go return these\n"
	.string "POKéMON…$"

VerityLakefront_Movement_WalkDown2:
	walk_down
	walk_down
	step_end

VerityLakefront_Movement_WalkDown3:
	walk_down
	walk_down
	walk_down
	step_end

VerityLakefront_Movement_BarryRejoin:
	walk_up
	face_right
	step_end
