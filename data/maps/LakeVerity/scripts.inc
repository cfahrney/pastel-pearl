LakeVerity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LakeVerity_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LakeVerity_OnFrame
	.byte 0

@ Sets LUCAS/DAWN's object graphics to whichever protagonist the player
@ didn't choose.
LakeVerity_OnTransition:
	call LakeVerity_EventScript_SetupLucasDawnGfxId
	end

LakeVerity_EventScript_SetupLucasDawnGfxId::
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, LakeVerity_EventScript_SetupDawnGfxId
	goto_if_eq VAR_RESULT, FEMALE, LakeVerity_EventScript_SetupLucasGfxId
	end

LakeVerity_EventScript_SetupDawnGfxId::
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_DAWN_NORMAL
	return

LakeVerity_EventScript_SetupLucasGfxId::
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_LUCAS_NORMAL
	return

@ Fires when VAR_TWINLEAF_TOWN_STATE == 4, right after the player warps
@ in from VERITY LAKEFRONT with BARRY following. Swaps him to a stand-in
@ object for immediate visibility, runs the ROWAN/LUCAS-DAWN scene, then
@ restores him as a follower.
LakeVerity_OnFrame:
	map_script_2 VAR_TWINLEAF_TOWN_STATE, 4, LakeVerity_EventScript_ArriveAtLake
	.2byte 0

LakeVerity_EventScript_ArriveAtLake::
	lockall
	destroyfollowernpc
	clearflag FLAG_HIDE_LAKE_VERITY_BARRY
	addobject LOCALID_LAKE_VERITY_BARRY
	applymovement LOCALID_PLAYER, Common_Movement_WalkUp2
	applymovement LOCALID_LAKE_VERITY_BARRY, Common_Movement_WalkUp2
	waitmovementall
	msgbox LakeVerity_Text_WhatsGoingOn, MSGBOX_DEFAULT
	closemessage
	call LakeVerity_EventScript_BufferLucasDawnName
	setfollowernpc LOCALID_LAKE_VERITY_BARRY, FNPC_ALL
	special SpawnCameraObject
	applymovement LOCALID_CAMERA, LakeVerity_Movement_CameraPanToRowan
	waitmovement 0
	msgbox LakeVerity_Text_NothingUnusual, MSGBOX_DEFAULT
	closemessage
	msgbox LakeVerity_Text_RowanMayHaveBeenMistaken, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_LAKE_VERITY_PROFESSOR_ROWAN, Common_Movement_FaceRight
	waitmovement 0
	msgbox LakeVerity_Text_RowanWereLeaving, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_LAKE_VERITY_LUCASDAWN, Common_Movement_FaceLeft
	waitmovement 0
	msgbox LakeVerity_Text_LucasDawnFourYears, MSGBOX_DEFAULT
	closemessage
	msgbox LakeVerity_Text_RowanManyRarePokemon, MSGBOX_DEFAULT
	closemessage
	clearflag FLAG_HIDE_LAKE_VERITY_SUITCASE
    addobject LOCALID_LAKE_VERITY_SUITCASE
	@ ROWAN and LUCAS/DAWN approach as camera pans back down.
	applymovement LOCALID_LAKE_VERITY_PROFESSOR_ROWAN, LakeVerity_Movement_RowanApproachParty
	applymovement LOCALID_LAKE_VERITY_LUCASDAWN, LakeVerity_Movement_LucasDawnApproachParty
	applymovement LOCALID_CAMERA, LakeVerity_Movement_CameraPanBackToParty
	waitmovementall
	special RemoveCameraObject
	applymovement LOCALID_PLAYER, Common_Movement_FaceRight
	applymovement OBJ_EVENT_ID_NPC_FOLLOWER, LakeVerity_Movement_BarryStepRightAndFaceLeft
	waitmovementall
	msgbox LakeVerity_Text_ExcuseUsLetUsPass, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_LAKE_VERITY_PROFESSOR_ROWAN, LakeVerity_Movement_RowanExitToWarp
	waitmovement 0
	removeobject LOCALID_LAKE_VERITY_PROFESSOR_ROWAN
	@ Prevents ROWAN's template from respawning on camera scroll.
	setflag FLAG_HIDE_LAKE_VERITY_PROFESSOR_ROWAN
	@ LUCAS/DAWN steps into ROWAN's spot, says goodbye, leaves.
	applymovement LOCALID_LAKE_VERITY_LUCASDAWN, LakeVerity_Movement_LucasDawnRepositionToGap
	waitmovement 0
	applymovement LOCALID_LAKE_VERITY_LUCASDAWN, LakeVerity_Movement_LucasDawnLookAround
	waitmovement 0
	msgbox LakeVerity_Text_SorryFolks, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_LAKE_VERITY_LUCASDAWN, LakeVerity_Movement_LucasDawnExitToWarp
	waitmovement 0
	removeobject LOCALID_LAKE_VERITY_LUCASDAWN
	@ Same respawn-prevention for LUCAS/DAWN.
	setflag FLAG_HIDE_LAKE_VERITY_LUCASDAWN
	applymovement OBJ_EVENT_ID_NPC_FOLLOWER, LakeVerity_Movement_BarryReturnToPosition
	waitmovement 0
	msgbox LakeVerity_Text_WhatWasThatAbout, MSGBOX_DEFAULT
	closemessage
	delay 30
	applymovement OBJ_EVENT_ID_NPC_FOLLOWER, Common_Movement_FaceUp
	waitmovement 0
	msgbox LakeVerity_Text_LetsGoCheckThisOut, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_NPC_FOLLOWER, Common_Movement_FaceLeft
	waitmovement 0
	msgbox LakeVerity_Text_BarryEllipsis, MSGBOX_DEFAULT
	closemessage
	msgbox LakeVerity_Text_BarryTallGrassWarning, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, LakeVerity_Movement_PlayerEnterGrass
	applymovement OBJ_EVENT_ID_NPC_FOLLOWER, LakeVerity_Movement_BarryEnterGrass
	waitmovementall
	msgbox LakeVerity_Text_ItsABriefcase, MSGBOX_DEFAULT
	closemessage
	msgbox LakeVerity_Text_TheyForgotItHere, MSGBOX_DEFAULT
	closemessage
	msgbox LakeVerity_Text_HeardThemSayProfessor, MSGBOX_DEFAULT
	closemessage
	@ Spawns both STARLY and flies them in, one toward the player from the
	@ north, one toward BARRY from the east.
	clearflag FLAG_HIDE_LAKE_VERITY_PLAYER_STARLY
	clearflag FLAG_HIDE_LAKE_VERITY_BARRY_STARLY
	addobject LOCALID_LAKE_VERITY_PLAYER_STARLY
	addobject LOCALID_LAKE_VERITY_BARRY_STARLY
	applymovement LOCALID_LAKE_VERITY_PLAYER_STARLY, LakeVerity_Movement_PlayerStarlyApproach
	applymovement LOCALID_LAKE_VERITY_BARRY_STARLY, LakeVerity_Movement_BarryStarlyApproach
	waitmovementall
	@ PLAYER and BARRY turn to face their STARLY.
	applymovement LOCALID_PLAYER, Common_Movement_FaceDown
	applymovement OBJ_EVENT_ID_NPC_FOLLOWER, Common_Movement_FaceRight
	waitmovementall
	msgbox LakeVerity_Text_StarlyWaaah, MSGBOX_DEFAULT
	closemessage
	msgbox LakeVerity_Text_WhatsGoingOnStarly, MSGBOX_DEFAULT
	closemessage
	msgbox LakeVerity_Text_LookPokeBalls, MSGBOX_DEFAULT
	closemessage
	msgbox LakeVerity_Text_WhichOneDoYouWant, MSGBOX_DEFAULT
	closemessage
	@ special ChooseStarter gives the player their starter and runs the
	@ forced STARLY battle. The state var has to advance before the battle
	@ starts, since returning from battle briefly reactivates on-frame
	@ triggers and would refire this script if the state was still 4.
	setvar VAR_TWINLEAF_TOWN_STATE, 5
	@ Unlocks the POKEMON option in the start menu (see BuildStartMenuActions
	@ in start_menu.c).
	setflag FLAG_SYS_POKEMON_GET
	fadescreen FADE_TO_BLACK
	special ChooseStarter
	removeobject LOCALID_LAKE_VERITY_PLAYER_STARLY
	removeobject LOCALID_LAKE_VERITY_BARRY_STARLY
	@ STR_VAR_1 holds the new starter's species name. STR_VAR_2 holds the
	@ species that counters it, for BARRY's brag line below.
	bufferleadmonspeciesname STR_VAR_1
	call LakeVerity_EventScript_BufferCounterStarterName
	msgbox LakeVerity_Text_BarryFwaaah, MSGBOX_DEFAULT
	closemessage
	msgbox LakeVerity_Text_BarryMineWasTougher, MSGBOX_DEFAULT
	closemessage
	msgbox LakeVerity_Text_BarryOtherPeoplesPokemon, MSGBOX_DEFAULT
	closemessage
	msgbox LakeVerity_Text_BarryWeHadToUseThem, MSGBOX_DEFAULT
	closemessage
	@ LUCAS/DAWN returns for the briefcase; BARRY sidesteps to face them.
	addobject LOCALID_LAKE_VERITY_LUCASDAWN
	setobjectxy LOCALID_LAKE_VERITY_LUCASDAWN, 39, 41
	applymovement LOCALID_LAKE_VERITY_LUCASDAWN, LakeVerity_Movement_LucasDawnReturnApproach
	waitmovement 0
	applymovement LOCALID_LAKE_VERITY_LUCASDAWN, LakeVerity_Movement_LucasDawnTakeBarrysSpot
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	applymovement OBJ_EVENT_ID_NPC_FOLLOWER, LakeVerity_Movement_BarryStepAsideForLucasDawn
	waitmovementall
	msgbox LakeVerity_Text_LucasDawnWhewFoundBriefcase, MSGBOX_DEFAULT
	closemessage
	msgbox LakeVerity_Text_LucasDawnProfessorWouldveGoneThroughRoof, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_LAKE_VERITY_LUCASDAWN, LakeVerity_Movement_LucasDawnFidget
	waitmovement 0
	msgbox LakeVerity_Text_LucasDawnHunhWhaaaat, MSGBOX_DEFAULT
	closemessage
	msgbox LakeVerity_Text_LucasDawnDidYouUseThesePokemon, MSGBOX_DEFAULT
	closemessage
	msgbox LakeVerity_Text_LucasDawnHowExplainToProfessor, MSGBOX_DEFAULT
	closemessage
	msgbox LakeVerity_Text_LucasDawnIllTakeThisBriefcase, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_LAKE_VERITY_LUCASDAWN, Common_Movement_FaceLeft
	waitmovement 0
	delay 30
	setflag FLAG_HIDE_LAKE_VERITY_SUITCASE
	removeobject LOCALID_LAKE_VERITY_SUITCASE
	delay 30
	@ LUCAS/DAWN leaves back out; PLAYER and BARRY watch.
	applymovement LOCALID_PLAYER, Common_Movement_FaceDown
	applymovement OBJ_EVENT_ID_NPC_FOLLOWER, Common_Movement_FaceDown
	applymovement LOCALID_LAKE_VERITY_LUCASDAWN, LakeVerity_Movement_LucasDawnLeaveReturnPath
	waitmovement 0
	removeobject LOCALID_LAKE_VERITY_LUCASDAWN
	msgbox LakeVerity_Text_BarryWhatWasThatAboutNow, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_NPC_FOLLOWER, LakeVerity_Movement_BarryApproachPlayerAfterBattle
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_FaceRight
	msgbox LakeVerity_Text_BarryDontKnowLetsGetOutOfHere, MSGBOX_DEFAULT
	closemessage
	msgbox LakeVerity_Text_BarryPokemonGotHurt, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_NPC_FOLLOWER, Common_Movement_WalkDown
	waitmovement 0
	applymovement LOCALID_PLAYER, LakeVerity_Movement_PlayerLeaveLakeVerity
	applymovement OBJ_EVENT_ID_NPC_FOLLOWER, LakeVerity_Movement_BarryLeaveLakeVerity
	waitmovementall
	@ State must be set before the warp, since VerityLakefront's on-frame
	@ trigger can run before this script resumes from waitstate.
	setvar VAR_TWINLEAF_TOWN_STATE, 9
	warp MAP_VERITY_LAKEFRONT, 5, 2
	waitstate
	releaseall
	end

LakeVerity_EventScript_BufferLucasDawnName::
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, LakeVerity_EventScript_BufferDawnName
	goto_if_eq VAR_RESULT, FEMALE, LakeVerity_EventScript_BufferLucasName
	end

LakeVerity_EventScript_BufferDawnName::
	bufferstring STR_VAR_1, LakeVerity_Text_Dawn
	return

LakeVerity_EventScript_BufferLucasName::
	bufferstring STR_VAR_1, LakeVerity_Text_Lucas
	return

LakeVerity_EventScript_BufferCounterStarterName::
	goto_if_eq VAR_STARTER_MON, 0, LakeVerity_EventScript_BufferCounterStarterFire
	goto_if_eq VAR_STARTER_MON, 1, LakeVerity_EventScript_BufferCounterStarterWater
	goto_if_eq VAR_STARTER_MON, 2, LakeVerity_EventScript_BufferCounterStarterGrass
	end

LakeVerity_EventScript_BufferCounterStarterFire::
	bufferspeciesname STR_VAR_2, SPECIES_CHIMCHAR
	return

LakeVerity_EventScript_BufferCounterStarterWater::
	bufferspeciesname STR_VAR_2, SPECIES_PIPLUP
	return

LakeVerity_EventScript_BufferCounterStarterGrass::
	bufferspeciesname STR_VAR_2, SPECIES_TURTWIG
	return

LakeVerity_Text_Dawn:
	.string "DAWN$"

LakeVerity_Text_Lucas:
	.string "LUCAS$"

LakeVerity_Text_WhatsGoingOn:
	.string "What's going on…?$"

LakeVerity_Text_NothingUnusual:
	.string "Professor, there's nothing out\n"
	.string "of the ordinary on the other\l"
	.string "side, either!$"

LakeVerity_Text_RowanMayHaveBeenMistaken:
	.string "Hm… I may have been\n"
	.string "mistaken…\p"
	.string "Something appears to be\n"
	.string "different than it was before,\l"
	.string "but…\p"
	.string "Fine! It's enough that we\n"
	.string "have seen the lake.$"

LakeVerity_Text_RowanWereLeaving:
	.string "{STR_VAR_1}, we're leaving.$"

LakeVerity_Text_LucasDawnFourYears:
	.string "Professor, you've been gone\n"
	.string "for four years now.\p"
	.string "How are you enjoying being\n"
	.string "back in Sinnoh?$"

LakeVerity_Text_RowanManyRarePokemon:
	.string "…Hm. There is one thing\n"
	.string "I can say.\p"
	.string "There are many rare kinds\n"
	.string "of POKéMON in Sinnoh.\p"
	.string "The region should serve us\n"
	.string "very well in regards to our\l"
	.string "studies.$"

LakeVerity_Text_ExcuseUsLetUsPass:
	.string "Excuse me. Let us pass,\n"
	.string "please.$"

LakeVerity_Text_SorryFolks:
	.string "Sorry, folks.$"

LakeVerity_Text_WhatWasThatAbout:
	.string "What was that about?\n"
	.string "Those two…$"

LakeVerity_Text_LetsGoCheckThisOut:
	.string "Huh? {PLAYER}! Let's go\n"
	.string "check this out!$"

LakeVerity_Text_BarryEllipsis:
	.string "…\n"
	.string "…$"

LakeVerity_Text_BarryTallGrassWarning:
	.string "What's that? Don't go into\n"
	.string "the tall grass?\p"
	.string "No problem, no problem!\p"
	.string "We won't be in there long\n"
	.string "enough for a wild POKéMON to\l"
	.string "come out.$"

LakeVerity_Text_ItsABriefcase:
	.string "It's…\n"
	.string "A briefcase?$"

LakeVerity_Text_TheyForgotItHere:
	.string "Those people forgot it here.\n"
	.string "What are we supposed to do\l"
	.string "with it?$"

LakeVerity_Text_HeardThemSayProfessor:
	.string "We can try to deliver it, but\n"
	.string "who are they? I heard them\l"
	.string "say professor.$"

LakeVerity_Text_StarlyWaaah:
	.string "Waaah!\n"
	.string "Po-POKéMON?!$"

LakeVerity_Text_WhatsGoingOnStarly:
	.string "What's going on?$"

LakeVerity_Text_LookPokeBalls:
	.string "Look! These are POKé BALLS!\n"
	.string "Let's battle using these!$"

LakeVerity_Text_WhichOneDoYouWant:
	.string "Eh…?\n"
	.string "Which one do you want, then?$"

LakeVerity_Text_BarryFwaaah:
	.string "Fwaaah!\n"
	.string "Your {STR_VAR_1} totally rocked!$"

LakeVerity_Text_BarryMineWasTougher:
	.string "But my {STR_VAR_2} was way\n"
	.string "tougher than yours!$"

LakeVerity_Text_BarryOtherPeoplesPokemon:
	.string "…They were other people's\n"
	.string "POKéMON, though…$"

LakeVerity_Text_BarryWeHadToUseThem:
	.string "But we had to use them…\n"
	.string "They won't mind, will they?$"

LakeVerity_Text_LucasDawnWhewFoundBriefcase:
	.string "Whew! You found the\n"
	.string "briefcase?$"

LakeVerity_Text_LucasDawnProfessorWouldveGoneThroughRoof:
	.string "The professor would've gone\n"
	.string "through the roof if he knew\l"
	.string "I forgot it here.$"

LakeVerity_Text_LucasDawnHunhWhaaaat:
	.string "Hunh?\n"
	.string "Whaaaat?!$"

LakeVerity_Text_LucasDawnDidYouUseThesePokemon:
	.string "Did you guys…\n"
	.string "Did you use these POKéMON?!$"

LakeVerity_Text_LucasDawnHowExplainToProfessor:
	.string "Oh, man… How am I gonna\n"
	.string "explain this to the\l"
	.string "professor?$"

LakeVerity_Text_LucasDawnIllTakeThisBriefcase:
	.string "…This briefcase is the\n"
	.string "professor's, so I'll take it,\l"
	.string "OK?$"

LakeVerity_Text_BarryWhatWasThatAboutNow:
	.string "What was that about?$"

LakeVerity_Text_BarryDontKnowLetsGetOutOfHere:
	.string "I don't know what's going on.\n"
	.string "{PLAYER}, let's get out of here.$"

LakeVerity_Text_BarryPokemonGotHurt:
	.string "My POKéMON got hurt from\n"
	.string "that battle.\p"
	.string "If we get attacked, we might\n"
	.string "be in trouble.$"

LakeVerity_Movement_CameraPanToRowan:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

LakeVerity_Movement_CameraPanBackToParty:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

LakeVerity_Movement_RowanApproachParty:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

LakeVerity_Movement_LucasDawnApproachParty:
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

LakeVerity_Movement_BarryStepRightAndFaceLeft:
	walk_right
	face_left
	step_end

LakeVerity_Movement_RowanExitToWarp:
	walk_down
	walk_down
	walk_down
	step_end

LakeVerity_Movement_LucasDawnRepositionToGap:
	walk_down
	step_end

LakeVerity_Movement_LucasDawnLookAround:
      face_left
      delay_16
      delay_16
      face_right
      delay_16
      delay_16
      face_down
      step_end

LakeVerity_Movement_LucasDawnExitToWarp:
	walk_down
	walk_down
	step_end

LakeVerity_Movement_BarryReturnToPosition:
	walk_left
	face_down
	step_end

LakeVerity_Movement_PlayerEnterGrass:
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

LakeVerity_Movement_BarryEnterGrass:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_up
	face_left
	step_end

LakeVerity_Movement_PlayerStarlyApproach:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

LakeVerity_Movement_BarryStarlyApproach:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

LakeVerity_Movement_LucasDawnReturnApproach:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_up
	walk_up
	step_end

LakeVerity_Movement_LucasDawnTakeBarrysSpot:
	walk_up
	walk_up
	face_left
	step_end

LakeVerity_Movement_BarryStepAsideForLucasDawn:
	walk_right
	face_left
	step_end

LakeVerity_Movement_LucasDawnFidget:
	face_down
	delay_16
	delay_16
	face_right
	delay_16
	delay_8
	face_down
	delay_8
	face_right
	delay_8
	face_down
	step_end

LakeVerity_Movement_LucasDawnLeaveReturnPath:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

LakeVerity_Movement_BarryApproachPlayerAfterBattle:
	walk_left
	walk_down
	face_left
	step_end


LakeVerity_Movement_PlayerLeaveLakeVerity:
	face_down
	delay_16
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end


LakeVerity_Movement_BarryLeaveLakeVerity:
	walk_left
	walk_down
	walk_down
	walk_down
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end
