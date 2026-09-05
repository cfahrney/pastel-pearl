Route201_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route201_OnTransition
	.byte 0

@ Shows BARRY while VAR_TWINLEAF_TOWN_STATE == 2, and ROWAN/LUCAS-DAWN
@ while it's == 10.
Route201_OnTransition:
	setflag FLAG_HIDE_ROUTE201_BARRY
	call_if_eq VAR_TWINLEAF_TOWN_STATE, 2, Route201_EventScript_ShowBarry
	setflag FLAG_HIDE_ROUTE201_LUCASDAWNROWAN
	call_if_eq VAR_TWINLEAF_TOWN_STATE, 10, Route201_EventScript_ShowRowanAndLucasDawn
	end

Route201_EventScript_ShowBarry:
	clearflag FLAG_HIDE_ROUTE201_BARRY
	return

Route201_EventScript_ShowRowanAndLucasDawn:
	clearflag FLAG_HIDE_ROUTE201_LUCASDAWNROWAN
	return

@ Triggers when VAR_TWINLEAF_TOWN_STATE == 2. Has BARRY run down to meet
@ the player and join as a follower.
Route201_EventScript_BarryNoticesPlayerAtX22::
	lockall
	playse SE_PIN
	applymovement LOCALID_ROUTE201_BARRY, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_ROUTE201_BARRY, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_ROUTE201_BARRY, Route201_Movement_BarryToX22
	waitmovement 0
	goto Route201_EventScript_BarryJoinsPlayer

Route201_EventScript_BarryNoticesPlayerAtX23::
	lockall
	playse SE_PIN
	applymovement LOCALID_ROUTE201_BARRY, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_ROUTE201_BARRY, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_ROUTE201_BARRY, Route201_Movement_BarryToX23
	waitmovement 0
	goto Route201_EventScript_BarryJoinsPlayer

Route201_EventScript_BarryNoticesPlayerAtX24::
	lockall
	playse SE_PIN
	applymovement LOCALID_ROUTE201_BARRY, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_ROUTE201_BARRY, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_ROUTE201_BARRY, Route201_Movement_BarryToX24
	waitmovement 0
	goto Route201_EventScript_BarryJoinsPlayer

Route201_EventScript_BarryNoticesPlayerAtX25::
	lockall
	playse SE_PIN
	applymovement LOCALID_ROUTE201_BARRY, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_ROUTE201_BARRY, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_ROUTE201_BARRY, Route201_Movement_BarryToX25
	waitmovement 0
	goto Route201_EventScript_BarryJoinsPlayer

Route201_EventScript_BarryJoinsPlayer:
	msgbox Route201_Text_RedGyaradosLake, MSGBOX_DEFAULT
	closemessage
	setfollowernpc LOCALID_ROUTE201_BARRY, FNPC_ALL
	setvar VAR_TWINLEAF_TOWN_STATE, 3
	releaseall
	end

Route201_Text_RedGyaradosLake:
	.string "Hey, you saw that news report\n"
	.string "that was on TV, right?\p"
	.string "You know, “Search for the Red\n"
	.string "GYARADOS!\p"
	.string "The mysterious appearance of the\n"
	.string "furious POKéMON in a lake!”\p"
	.string "That show got me thinking.\p"
	.string "I'll bet our local lake has a\n"
	.string "POKéMON like that in it, too!\p"
	.string "So, that's what we're gonna do.\n"
	.string "We'll go find a POKéMON like\l"
	.string "that!$"

Route201_Movement_BarryToX22:
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	face_down
	step_end

Route201_Movement_BarryToX23:
	walk_fast_down
	walk_fast_down
	walk_fast_left
	face_down
	step_end

Route201_Movement_BarryToX24:
	walk_fast_down
	walk_fast_down
	face_down
	step_end

Route201_Movement_BarryToX25:
	walk_fast_down
	walk_fast_down
	walk_fast_right
	face_down
	step_end

@ Blocks the player from entering the tall grass while
@ VAR_TWINLEAF_TOWN_STATE == 3. Repeatable trigger, doesn't advance state.
Route201_EventScript_BarryStopsPlayerFromGrass::
	lockall
	facefollowernpc
	msgbox Route201_Text_DontGoInTallGrass, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_NPC_FOLLOWER, Route201_Movement_StepBackLeft
	waitmovement 0
	applymovement LOCALID_PLAYER, Route201_Movement_StepBackLeft
	waitmovement 0
	releaseall
	end

@ Blocks the player from returning to Twinleaf while
@ VAR_TWINLEAF_TOWN_STATE == 3. Repeatable trigger, doesn't advance state.
Route201_EventScript_BarryStopsPlayerFromLeaving::
	lockall
	facefollowernpc
	msgbox Route201_Text_ForgetGoingHome, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, Route201_Movement_WalkUp
	waitmovement 0
	releaseall
	end

Route201_Text_DontGoInTallGrass:
	.string "Remember what your mother said?\p"
	.string "“{PLAYER}! Don't go into the tall\n"
	.string "grass!\p"
	.string "Remember, wild POKéMON may\n"
	.string "attack you if you're walking in\l"
	.string "tall grass.\p"
	.string "It would be OK if you had your\n"
	.string "own POKéMON, but…”$"

Route201_Text_ForgetGoingHome:
	.string "Hey! Where are you wandering off\n"
	.string "to?!\p"
	.string "That mystery POKéMON on TV!\n"
	.string "It's calling out to me!\p"
	.string "Forget about going back home!$"

Route201_Movement_StepBackLeft:
	walk_left
	step_end

Route201_Movement_WalkUp:
	walk_up
	step_end

@ Triggers when VAR_TWINLEAF_TOWN_STATE == 10, having ROWAN catch up
@ with the player.
Route201_EventScript_RowanNoticesPlayerAtY8::
	lockall
	playse SE_PIN
	applymovement OBJ_EVENT_ID_NPC_FOLLOWER, Common_Movement_ExclamationMark
	applymovement LOCALID_ROUTE201_ROWAN, Route201_Movement_RowanFaceLeftAndPause
	waitmovementall
	msgbox Route201_Text_HeyItsThosePeople, MSGBOX_DEFAULT
	closemessage
	delay 16
	applymovement LOCALID_ROUTE201_ROWAN, Route201_Movement_RowanApproachAtY8
	waitmovement 0
	goto Route201_EventScript_RowanConfrontsPlayer

Route201_EventScript_RowanNoticesPlayerAtY9::
	lockall
	playse SE_PIN
	applymovement OBJ_EVENT_ID_NPC_FOLLOWER, Common_Movement_ExclamationMark
	applymovement LOCALID_ROUTE201_ROWAN, Route201_Movement_RowanFaceLeftAndPause
	waitmovementall
	msgbox Route201_Text_HeyItsThosePeople, MSGBOX_DEFAULT
	closemessage
	delay 16
	applymovement LOCALID_ROUTE201_ROWAN, Route201_Movement_RowanApproachAtY9
	applymovement LOCALID_ROUTE201_LUCASDAWN Common_Movement_FaceLeft
	waitmovementall
	goto Route201_EventScript_RowanConfrontsPlayer

Route201_EventScript_RowanConfrontsPlayer:
	call Route201_EventScript_BufferAssistantName
	msgbox Route201_Text_RowanHmm, MSGBOX_DEFAULT
	closemessage
	msgbox Route201_Text_RowanHeardFromAssistant, MSGBOX_DEFAULT
	closemessage
	bufferleadmonspeciesname STR_VAR_2
	call Route201_EventScript_BufferBarryCounterStarterName
	msgbox Route201_Text_RowanHmSpecies, MSGBOX_DEFAULT
	closemessage
	msgbox Route201_Text_RowanEllipsis, MSGBOX_DEFAULT
	closemessage
	msgbox Route201_Text_RowanHmm, MSGBOX_DEFAULT
	closemessage
	msgbox Route201_Text_RowanISee, MSGBOX_DEFAULT
	closemessage
	msgbox Route201_Text_RowanGoingBackToLab, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ROUTE201_ROWAN, Route201_Movement_RowanExitRight
	applymovement LOCALID_ROUTE201_LUCASDAWN, Route201_Movement_LucasDawnFidgetWhileRowanLeaves
	waitmovementall
	removeobject LOCALID_ROUTE201_ROWAN
	@ Safe to set now, since the flag only blocks respawning and doesn't
	@ affect an object that's already active.
	setflag FLAG_HIDE_ROUTE201_LUCASDAWNROWAN
	msgbox Route201_Text_UhYeaOfCourse, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ROUTE201_LUCASDAWN, Common_Movement_FaceLeft
	waitmovement 0
	msgbox Route201_Text_VisitOurLab, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ROUTE201_LUCASDAWN, Route201_Movement_LucasDawnExitRight
	waitmovement 0
	removeobject LOCALID_ROUTE201_LUCASDAWN
	msgbox Route201_Text_BarryWhatWasThatCraziness, MSGBOX_DEFAULT
	closemessage
	msgbox Route201_Text_BarryCouldveJustYelled, MSGBOX_DEFAULT
	closemessage
	msgbox Route201_Text_BarryWeShouldGoHomeToo, MSGBOX_DEFAULT
	closemessage
	@ Drops BARRY's follower status so the player's lead POKéMON takes over
	@ as follower (see UpdateFollowingPokemon in event_object_movement.c).
	destroyfollowernpc
	setvar VAR_TWINLEAF_TOWN_STATE, 11
	warp MAP_TWINLEAF_TOWN_PLAYER_HOUSE_1F, 1, 5
	waitstate
	releaseall
	end

Route201_EventScript_BufferAssistantName:
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, Route201_EventScript_BufferDawnName
	goto_if_eq VAR_RESULT, FEMALE, Route201_EventScript_BufferLucasName
	end

Route201_EventScript_BufferDawnName:
	bufferstring STR_VAR_1, Route201_Text_Dawn
	return

Route201_EventScript_BufferLucasName:
	bufferstring STR_VAR_1, Route201_Text_Lucas
	return

@ Gets the species name that counters the player's starter, for BARRY's
@ brag line. Same type-counter logic as
@ LakeVerity_EventScript_BufferCounterStarterName.
Route201_EventScript_BufferBarryCounterStarterName:
	goto_if_eq VAR_STARTER_MON, 0, Route201_EventScript_BufferCounterFire
	goto_if_eq VAR_STARTER_MON, 1, Route201_EventScript_BufferCounterWater
	goto_if_eq VAR_STARTER_MON, 2, Route201_EventScript_BufferCounterGrass
	end

Route201_EventScript_BufferCounterFire:
	bufferspeciesname STR_VAR_3, SPECIES_CHIMCHAR
	return

Route201_EventScript_BufferCounterWater:
	bufferspeciesname STR_VAR_3, SPECIES_PIPLUP
	return

Route201_EventScript_BufferCounterGrass:
	bufferspeciesname STR_VAR_3, SPECIES_TURTWIG
	return

Route201_Text_Dawn:
	.string "DAWN$"

Route201_Text_Lucas:
	.string "LUCAS$"

Route201_Text_HeyItsThosePeople:
	.string "Hey, it's those people!\n"
	.string "Is that old guy staring at\l"
	.string "us?$"

Route201_Text_RowanHmm:
	.string "Hmm…$"

Route201_Text_RowanHeardFromAssistant:
	.string "I heard from {STR_VAR_1} that you\n"
	.string "used our POKéMON? Let me see\l"
	.string "them, please.$"

Route201_Text_RowanHmSpecies:
	.string "Hm… {STR_VAR_2} and\n"
	.string "{STR_VAR_3}…$"

Route201_Text_RowanEllipsis:
	.string "…$"

Route201_Text_RowanISee:
	.string "I see…\n"
	.string "That's how it is…$"

Route201_Text_RowanGoingBackToLab:
	.string "{STR_VAR_1}!\n"
	.string "I'm going back to my lab!$"

Route201_Text_UhYeaOfCourse:
	.string "Uh… Yea, of course!\n"
	.string "Professor, wait for me!$"

Route201_Text_VisitOurLab:
	.string "You should visit us at our\n"
	.string "lab later, I think.\p"
	.string "We'll be seeing!$"

Route201_Text_BarryWhatWasThatCraziness:
	.string "What was all that craziness\n"
	.string "about?$"

Route201_Text_BarryCouldveJustYelled:
	.string "I mean, if he was angry, he\n"
	.string "could've just yelled at us, or\l"
	.string "whatever…\p"
	.string "And he didn't want their\n"
	.string "POKéMON back…?$"

Route201_Text_BarryWeShouldGoHomeToo:
	.string "{PLAYER}…\n"
	.string "We should go home, too…$"

Route201_Movement_RowanFaceLeftAndPause:
	face_left
	delay_16
	step_end

Route201_Movement_RowanApproachAtY8:
	walk_left
	walk_left
	step_end

Route201_Movement_RowanApproachAtY9:
	walk_left
	walk_down
	walk_left
	step_end

Route201_Movement_RowanExitRight:
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

Route201_Movement_LucasDawnFidgetWhileRowanLeaves:
	walk_up
	face_down
	face_right
	step_end

Route201_Movement_LucasDawnExitRight:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end
