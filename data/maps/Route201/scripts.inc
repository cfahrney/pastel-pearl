Route201_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route201_OnTransition
	.byte 0

@ Shows BARRY while VAR_TWINLEAF_TOWN_STATE == 2, and ROWAN/LUCAS-DAWN
@ while it's == 10.
Route201_OnTransition:
	call Common_EventScript_SetupLucasDawnAssistantGfxId
	setflag FLAG_HIDE_ROUTE201_BARRY
	call_if_eq VAR_TWINLEAF_TOWN_STATE, 2, Route201_EventScript_ShowBarry
	setflag FLAG_HIDE_ROUTE201_LUCASDAWNROWAN
	call_if_eq VAR_TWINLEAF_TOWN_STATE, 10, Route201_EventScript_ShowRowanAndLucasDawn
	@ No wild encounters before the player has a starter.
	call_if_lt VAR_TWINLEAF_TOWN_STATE, 12, Route201_EventScript_DisableWildEncounters
	call_if_ge VAR_TWINLEAF_TOWN_STATE, 12, Route201_EventScript_EnableWildEncounters
	end

Route201_EventScript_DisableWildEncounters:
	setflag FLAG_WILD_ENCOUNTERS_DISABLED
	return

Route201_EventScript_EnableWildEncounters:
	clearflag FLAG_WILD_ENCOUNTERS_DISABLED
	return

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
	setspeaker SP_NAME_RIVAL
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
	.string "Gyarados!\p"
	.string "The mysterious appearance of the\n"
	.string "furious Pokémon in a lake!”\p"
	.string "That show got me thinking.\p"
	.string "I'll bet our local lake has a\n"
	.string "Pokémon like that in it, too!\p"
	.string "So, that's what we're gonna do.\n"
	.string "We'll go find a Pokémon like\l"
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
	setspeaker SP_NAME_RIVAL
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
	setspeaker SP_NAME_RIVAL
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
	.string "Remember, wild Pokémon may\n"
	.string "attack you if you're walking in\l"
	.string "tall grass.\p"
	.string "It would be OK if you had your\n"
	.string "own Pokémon, but…”$"

Route201_Text_ForgetGoingHome:
	.string "Hey! Where are you wandering off\n"
	.string "to?!\p"
	.string "That mystery Pokémon on TV!\n"
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
	setspeaker SP_NAME_RIVAL
	msgbox Route201_Text_HeyItsThosePeople, MSGBOX_DEFAULT
	closemessage
	delay 16
	applymovement LOCALID_ROUTE201_ROWAN, Route201_Movement_RowanApproachAtY8
	waitmovement 0
	goto Route201_EventScript_RowanConfrontsPlayerAtY8

Route201_EventScript_RowanNoticesPlayerAtY9::
	lockall
	playse SE_PIN
	applymovement OBJ_EVENT_ID_NPC_FOLLOWER, Common_Movement_ExclamationMark
	applymovement LOCALID_ROUTE201_ROWAN, Route201_Movement_RowanFaceLeftAndPause
	waitmovementall
	setspeaker SP_NAME_RIVAL
	msgbox Route201_Text_HeyItsThosePeople, MSGBOX_DEFAULT
	closemessage
	delay 16
	applymovement LOCALID_ROUTE201_ROWAN, Route201_Movement_RowanApproachAtY9
	applymovement LOCALID_ROUTE201_LUCASDAWN Common_Movement_FaceLeft
	waitmovementall
	goto Route201_EventScript_RowanConfrontsPlayerAtY9

Route201_EventScript_RowanConfrontsPlayerAtY8:
	setspeaker SP_NAME_ROWAN
	msgbox Route201_Text_RowanHmm, MSGBOX_DEFAULT
	closemessage
	setspeaker SP_NAME_ROWAN
	msgbox Route201_Text_RowanHeardFromAssistant, MSGBOX_DEFAULT
	closemessage
	bufferleadmonspeciesname STR_VAR_2
	call Route201_EventScript_BufferBarryCounterStarterName
	setspeaker SP_NAME_ROWAN
	msgbox Route201_Text_RowanHmSpecies, MSGBOX_DEFAULT
	closemessage
	setspeaker SP_NAME_ROWAN
	msgbox Route201_Text_RowanEllipsis, MSGBOX_DEFAULT
	closemessage
	setspeaker SP_NAME_ROWAN
	msgbox Route201_Text_RowanHmm, MSGBOX_DEFAULT
	closemessage
	setspeaker SP_NAME_ROWAN
	msgbox Route201_Text_RowanISee, MSGBOX_DEFAULT
	closemessage
	setspeaker SP_NAME_ROWAN
	msgbox Route201_Text_RowanGoingBackToLab, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ROUTE201_ROWAN, Route201_Movement_RowanExitRight
	applymovement LOCALID_ROUTE201_LUCASDAWN, Route201_Movement_LucasDawnFidgetWhileRowanLeavesAtY8
	waitmovementall
	removeobject LOCALID_ROUTE201_ROWAN
	@ Safe to set now, since the flag only blocks respawning and doesn't
	@ affect an object that's already active.
	setflag FLAG_HIDE_ROUTE201_LUCASDAWNROWAN
	setspeaker SP_NAME_ASSISTANT
	msgbox Route201_Text_UhYeaOfCourse, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ROUTE201_LUCASDAWN, Common_Movement_FaceLeft
	waitmovement 0
	setspeaker SP_NAME_ASSISTANT
	msgbox Route201_Text_VisitOurLab, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ROUTE201_LUCASDAWN, Route201_Movement_LucasDawnExitRight
	waitmovement 0
	removeobject LOCALID_ROUTE201_LUCASDAWN
	setspeaker SP_NAME_RIVAL
	msgbox Route201_Text_BarryWhatWasThatCraziness, MSGBOX_DEFAULT
	closemessage
	setspeaker SP_NAME_RIVAL
	msgbox Route201_Text_BarryCouldveJustYelled, MSGBOX_DEFAULT
	closemessage
	setspeaker SP_NAME_RIVAL
	msgbox Route201_Text_BarryWeShouldGoHomeToo, MSGBOX_DEFAULT
	closemessage
	@ Drops BARRY's follower status so the player's lead Pokémon takes over
	@ as follower (see UpdateFollowingPokemon in event_object_movement.c).
	destroyfollowernpc
	setvar VAR_TWINLEAF_TOWN_STATE, 11
	warp MAP_TWINLEAF_TOWN_PLAYER_HOUSE_1F, 1, 5
	waitstate
	releaseall
	end

Route201_EventScript_RowanConfrontsPlayerAtY9:
	setspeaker SP_NAME_ROWAN
	msgbox Route201_Text_RowanHmm, MSGBOX_DEFAULT
	closemessage
	setspeaker SP_NAME_ROWAN
	msgbox Route201_Text_RowanHeardFromAssistant, MSGBOX_DEFAULT
	closemessage
	bufferleadmonspeciesname STR_VAR_2
	call Route201_EventScript_BufferBarryCounterStarterName
	setspeaker SP_NAME_ROWAN
	msgbox Route201_Text_RowanHmSpecies, MSGBOX_DEFAULT
	closemessage
	setspeaker SP_NAME_ROWAN
	msgbox Route201_Text_RowanEllipsis, MSGBOX_DEFAULT
	closemessage
	setspeaker SP_NAME_ROWAN
	msgbox Route201_Text_RowanHmm, MSGBOX_DEFAULT
	closemessage
	setspeaker SP_NAME_ROWAN
	msgbox Route201_Text_RowanISee, MSGBOX_DEFAULT
	closemessage
	setspeaker SP_NAME_ROWAN
	msgbox Route201_Text_RowanGoingBackToLab, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ROUTE201_ROWAN, Route201_Movement_RowanExitRight
	applymovement LOCALID_ROUTE201_LUCASDAWN, Route201_Movement_LucasDawnFidgetWhileRowanLeavesAtY9
	waitmovementall
	removeobject LOCALID_ROUTE201_ROWAN
	@ Safe to set now, since the flag only blocks respawning and doesn't
	@ affect an object that's already active.
	setflag FLAG_HIDE_ROUTE201_LUCASDAWNROWAN
	setspeaker SP_NAME_ASSISTANT
	msgbox Route201_Text_UhYeaOfCourse, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ROUTE201_LUCASDAWN, Common_Movement_FaceLeft
	waitmovement 0
	setspeaker SP_NAME_ASSISTANT
	msgbox Route201_Text_VisitOurLab, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ROUTE201_LUCASDAWN, Route201_Movement_LucasDawnExitRight
	waitmovement 0
	removeobject LOCALID_ROUTE201_LUCASDAWN
	setspeaker SP_NAME_RIVAL
	msgbox Route201_Text_BarryWhatWasThatCraziness, MSGBOX_DEFAULT
	closemessage
	setspeaker SP_NAME_RIVAL
	msgbox Route201_Text_BarryCouldveJustYelled, MSGBOX_DEFAULT
	closemessage
	setspeaker SP_NAME_RIVAL
	msgbox Route201_Text_BarryWeShouldGoHomeToo, MSGBOX_DEFAULT
	closemessage
	@ Drops BARRY's follower status so the player's lead Pokémon takes over
	@ as follower (see UpdateFollowingPokemon in event_object_movement.c).
	destroyfollowernpc
	setvar VAR_TWINLEAF_TOWN_STATE, 11
	warp MAP_TWINLEAF_TOWN_PLAYER_HOUSE_1F, 1, 5
	waitstate
	releaseall
	end

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

Route201_Text_HeyItsThosePeople:
	.string "Hey, it's those people!\n"
	.string "Is that old guy staring at\l"
	.string "us?$"

Route201_Text_RowanHmm:
	.string "Hmm…$"

Route201_Text_RowanHeardFromAssistant:
	.string "I heard from {ASSISTANT} that you\n"
	.string "used our Pokémon? Let me see\l"
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
	.string "{ASSISTANT}!\n"
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
	.string "Pokémon back…?$"

Route201_Text_BarryWeShouldGoHomeToo:
	.string "{PLAYER}…\n"
	.string "We should go home, too…$"

Route201_EventScript_RouteSign::
	msgbox Route201_Text_RouteSign, MSGBOX_SIGN
	end

Route201_Text_RouteSign:
	.string "Route 201\n"
	.string "{DOWN_ARROW} Twinleaf Town$"

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

Route201_Movement_LucasDawnFidgetWhileRowanLeavesAtY8:
	face_up
	delay_16
    delay_16
	face_right
	step_end

Route201_Movement_LucasDawnFidgetWhileRowanLeavesAtY9:
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

Route201_EventScript_Trainer1::
	trainerbattle_single TRAINER_ROUTE201_1, Route201_Text_Trainer1Intro, Route201_Text_Trainer1Defeated
	msgbox Route201_Text_Trainer1PostBattle, MSGBOX_AUTOCLOSE
	end

Route201_Text_Trainer1Intro:
	.string "Hiya! Care for a quick battle! I'm\n"
	.string "pretty new to this.$"

Route201_Text_Trainer1Defeated:
	.string "Wow, you're good!$"

Route201_Text_Trainer1PostBattle:
	.string "That ledge is one way. Jump down for a\n"
	.string "shortcut to {COLOR DYNAMIC_COLOR3}Twinleaf Town{COLOR DARK_GRAY}!$"

Route201_EventScript_NPC1::
	@ poe:behavior {"mode":"gift","item":"ITEM_POTION","qty":1}
	lock
	faceplayer
	goto_if_set FLAG_ROUTE201_NPC1_GIFT, Route201_EventScript_NPC1After
	msgbox Route201_Text_NPC1, MSGBOX_DEFAULT
	giveitem ITEM_POTION, 1
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_ROUTE201_NPC1_GIFT
	msgbox Route201_Text_NPC1Received, MSGBOX_DEFAULT
	release
	end

Route201_EventScript_NPC1After::
	msgbox Route201_Text_NPC1After, MSGBOX_DEFAULT
	release
	end

Route201_Text_NPC1Received::
	.string "Use it when your Pokémon's HP is low!$"

Route201_Text_NPC1After::
	.string "You can find a Pokémon Mart in cities\n"
	.string "and most major towns.$"

Route201_EventScript_NPC2::
	msgbox Route201_Text_NPC2, MSGBOX_NPC
	end

Route201_EventScript_NPC3::
	msgbox Route201_Text_NPC3, MSGBOX_NPC
	end

Route201_Text_NPC1:
	.string "Hi! I work at the Pokémon Mart. Did you\n"
	.string "know we items to help restore your\l"
	.string "Pokémon's HP?\p"
	.string "Here! Since you seem new to this, you\n"
	.string "can have this one as a freebie.$"

Route201_Text_NPC2:
	.string "I sure wish I had some Berries to plant\n"
	.string "here. Maybe I'll plan a trip to {COLOR DYNAMIC_COLOR3}Floaroma\l"
	.string "Town{COLOR DARK_GRAY} soon...$"

Route201_Text_NPC3:
	.string "Wild Pokémon lurk in the tall grass, but\n"
	.string "some will roam around the grass too!\p"
	.string "If they see you, be prepared for a\n"
	.string "battle.$"

Route201_EventScript_Sign1::
	msgbox Route201_Text_Sign1, MSGBOX_SIGN
	end

Route201_Text_Sign1:
	.string "Trainer Tips!\p"
	.string "Don't be shy! Talk to anyone and\n"
	.string "everyone you happen to see. By talking\l"
	.string "to people, you will get invaluable\l"
	.string "information and advice.$"

Route201_EventScript_Sign2::
	msgbox Route201_Text_Sign2, MSGBOX_SIGN
	end

Route201_Text_Sign2:
	.string "Route 201\n"
	.string "{RIGHT_ARROW} Sandgem Town$"
