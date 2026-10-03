SandgemTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SandgemTown_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SandgemTown_OnFrame
	.byte 0

SandgemTown_OnTransition:
	setflag FLAG_VISITED_SANDGEM_TOWN
	call Common_EventScript_SetupLucasDawnAssistantGfxId
	@ BARRY is only ever added by the arrival scene.
	setflag FLAG_HIDE_SANDGEM_TOWN_BARRY
	setflag FLAG_HIDE_SANDGEMTOWN_LUCASDAWN
	call_if_eq VAR_SANDGEM_TOWN_STATE, 0, SandgemTown_EventScript_ShowLucasDawn
	call_if_eq VAR_SANDGEM_TOWN_STATE, 6, SandgemTown_EventScript_ShowLucasDawnAtLabDoor
	end

SandgemTown_EventScript_ShowLucasDawnAtLabDoor:
	clearflag FLAG_HIDE_SANDGEMTOWN_LUCASDAWN
	@ Perm variant: no live object exists yet on transition. Template already faces up.
	setobjectxyperm LOCALID_SANDGEMTOWN_LUCASDAWN, 8, 12
	return

SandgemTown_OnFrame:
	map_script_2 VAR_SANDGEM_TOWN_STATE, 6, SandgemTown_EventScript_TownTour
	.2byte 0

SandgemTown_EventScript_ShowLucasDawn:
	clearflag FLAG_HIDE_SANDGEMTOWN_LUCASDAWN
	return

SandgemTown_EventScript_Sign1::
	msgbox SandgemTown_Text_Sign1, MSGBOX_SIGN
	end

SandgemTown_EventScript_Sign2::
	msgbox SandgemTown_Text_Sign2, MSGBOX_SIGN
	end

SandgemTown_EventScript_Sign3::
	msgbox SandgemTown_Text_Sign3, MSGBOX_SIGN
	end

SandgemTown_EventScript_Sign4::
	msgbox SandgemTown_Text_Sign4, MSGBOX_SIGN
	end

SandgemTown_EventScript_Sign5::
	msgbox SandgemTown_Text_Sign5, MSGBOX_SIGN
	end

SandgemTown_Text_Sign1:
	.string "Pokémon Research Lab$"

SandgemTown_Text_Sign2:
	.string "Heal your Pokémon!\n"
	.string "Pokémon Center$"

SandgemTown_Text_Sign3:
	.string "All your items needs fulfilled!\n"
	.string "Pokémon Mart$"

SandgemTown_Text_Sign4:
	.string "Sandgem Town\n"
	.string "Town of Sand!$"

SandgemTown_Text_Sign5:
	.string "{ASSISTANT}'s House$"

SandgemTown_EventScript_NPC1::
	msgbox SandgemTown_Text_NPC1, MSGBOX_NPC
	end

SandgemTown_EventScript_NPC2::
	msgbox SandgemTown_Text_NPC2, MSGBOX_NPC
	end

SandgemTown_EventScript_NPC3::
	msgbox SandgemTown_Text_NPC3, MSGBOX_NPC
	end

SandgemTown_Text_NPC1:
	.string "That thing you have!\p"
	.string "It's a Pokédex, isn't it?!\p"
	.string "You're off to see all kinds of Pokémon\n"
	.string "now! Lucky you!$"

SandgemTown_Text_NPC2:
	.string "I'm from here but if I'm being honest...\p"
	.string "I don't like sand. It's coarse and rough\n"
	.string "and irritating, and it gets everywhere.$"

SandgemTown_Text_NPC3:
	.string "Oh, wow!\n"
	.string "Pokémon are so cool!\p"
	.string "You can make yours battle and make\n"
	.string "them stronger!\p"
	.string "I wish I had some!\n"
	.string "It's so cool!$"

@ Ambient rooftop Pokemon: turn and cry, no text box.
SandgemTown_EventScript_NPC4::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_HOOTHOOT, CRY_MODE_NORMAL
	waitmoncry
	release
	end

SandgemTown_EventScript_NPC5::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_STARLY, CRY_MODE_NORMAL
	waitmoncry
	release
	end

@ VAR_SANDGEM_TOWN_STATE == 0: LUCAS/DAWN spots the player, walks over, and
@ leads them to the lab door, where BARRY bursts out and runs off.
Route201_EventScript_DawnLucasNoticesPlayerAtY12::
	lockall
	playse SE_PIN
	applymovement LOCALID_SANDGEMTOWN_LUCASDAWN, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_SANDGEMTOWN_LUCASDAWN, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_SANDGEMTOWN_LUCASDAWN, SandgemTown_Movement_LucasDawnApproachAtY12
	applymovement LOCALID_PLAYER, Common_Movement_FaceRight
	waitmovementall
	goto SandgemTown_EventScript_LucasDawnLeadsToLabAtY12

Route201_EventScript_DawnLucasNoticesPlayerAtY13::
	lockall
	playse SE_PIN
	applymovement LOCALID_SANDGEMTOWN_LUCASDAWN, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_SANDGEMTOWN_LUCASDAWN, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_SANDGEMTOWN_LUCASDAWN, SandgemTown_Movement_LucasDawnApproachAtY13
	applymovement LOCALID_PLAYER, Common_Movement_FaceRight
	waitmovementall
	goto SandgemTown_EventScript_LucasDawnLeadsToLabAtY13

Route201_EventScript_DawnLucasNoticesPlayerAtY14::
	lockall
	playse SE_PIN
	applymovement LOCALID_SANDGEMTOWN_LUCASDAWN, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_SANDGEMTOWN_LUCASDAWN, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_SANDGEMTOWN_LUCASDAWN, SandgemTown_Movement_LucasDawnApproachAtY14
	applymovement LOCALID_PLAYER, Common_Movement_FaceRight
	waitmovementall
	goto SandgemTown_EventScript_LucasDawnLeadsToLabAtY14

Route201_EventScript_DawnLucasNoticesPlayerAtY15::
	lockall
	playse SE_PIN
	applymovement LOCALID_SANDGEMTOWN_LUCASDAWN, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_SANDGEMTOWN_LUCASDAWN, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_SANDGEMTOWN_LUCASDAWN, SandgemTown_Movement_LucasDawnApproachAtY15
	applymovement LOCALID_PLAYER, Common_Movement_FaceRight
	waitmovementall
	goto SandgemTown_EventScript_LucasDawnLeadsToLabAtY15

SandgemTown_Movement_LucasDawnApproachAtY12:
	walk_left
	walk_left
	walk_up
	face_left
	step_end

SandgemTown_EventScript_LucasDawnLeadsToLabAtY12:
	setspeaker SP_NAME_ASSISTANT
	msgbox SandgemTown_Text_WaitingForYou, MSGBOX_DEFAULT
	closemessage
	setvar VAR_0x8004, LOCALID_SANDGEMTOWN_LUCASDAWN
	special SetPlayerCollisionExemption
	applymovement LOCALID_SANDGEMTOWN_LUCASDAWN, SandgemTown_Movement_LucasDawnLeadsAtY12
	applymovement LOCALID_PLAYER, SandgemTown_Movement_PlayerFollowsAtY12
	waitmovementall
	goto SandgemTown_EventScript_LabArrival

SandgemTown_Movement_LucasDawnLeadsAtY12:
	walk_right
	walk_right
	walk_right
	step_end

SandgemTown_Movement_PlayerFollowsAtY12:
	walk_right
	walk_right
	walk_right
	step_end

SandgemTown_Movement_LucasDawnApproachAtY13:
	walk_left
	walk_left
	face_left
	step_end

SandgemTown_EventScript_LucasDawnLeadsToLabAtY13:
	setspeaker SP_NAME_ASSISTANT
	msgbox SandgemTown_Text_WaitingForYou, MSGBOX_DEFAULT
	closemessage
	setvar VAR_0x8004, LOCALID_SANDGEMTOWN_LUCASDAWN
	special SetPlayerCollisionExemption
	applymovement LOCALID_SANDGEMTOWN_LUCASDAWN, SandgemTown_Movement_LucasDawnLeadsAtY13
	applymovement LOCALID_PLAYER, SandgemTown_Movement_PlayerFollowsAtY13
	waitmovementall
	goto SandgemTown_EventScript_LabArrival

SandgemTown_Movement_LucasDawnLeadsAtY13:
	walk_up
	walk_right
	walk_right
	walk_right
	step_end

SandgemTown_Movement_PlayerFollowsAtY13:
	walk_right
	walk_up
	walk_right
	walk_right
	step_end

SandgemTown_Movement_LucasDawnApproachAtY14:
	walk_left
	walk_left
	walk_down
	face_left
	step_end

SandgemTown_EventScript_LucasDawnLeadsToLabAtY14:
	setspeaker SP_NAME_ASSISTANT
	msgbox SandgemTown_Text_WaitingForYou, MSGBOX_DEFAULT
	closemessage
	setvar VAR_0x8004, LOCALID_SANDGEMTOWN_LUCASDAWN
	special SetPlayerCollisionExemption
	applymovement LOCALID_SANDGEMTOWN_LUCASDAWN, SandgemTown_Movement_LucasDawnLeadsAtY14
	applymovement LOCALID_PLAYER, SandgemTown_Movement_PlayerFollowsAtY14
	waitmovementall
	goto SandgemTown_EventScript_LabArrival

SandgemTown_Movement_LucasDawnLeadsAtY14:
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	step_end

SandgemTown_Movement_PlayerFollowsAtY14:
	walk_right
	walk_up
	walk_up
	walk_right
	walk_right
	step_end

SandgemTown_Movement_LucasDawnApproachAtY15:
	walk_left
	walk_left
	walk_down
	walk_down
	face_left
	step_end

SandgemTown_EventScript_LucasDawnLeadsToLabAtY15:
	setspeaker SP_NAME_ASSISTANT
	msgbox SandgemTown_Text_WaitingForYou, MSGBOX_DEFAULT
	closemessage
	setvar VAR_0x8004, LOCALID_SANDGEMTOWN_LUCASDAWN
	special SetPlayerCollisionExemption
	applymovement LOCALID_SANDGEMTOWN_LUCASDAWN, SandgemTown_Movement_LucasDawnLeadsAtY15
	applymovement LOCALID_PLAYER, SandgemTown_Movement_PlayerFollowsAtY15
	waitmovementall
	goto SandgemTown_EventScript_LabArrival

SandgemTown_Movement_LucasDawnLeadsAtY15:
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	step_end

SandgemTown_Movement_PlayerFollowsAtY15:
	walk_right
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	step_end

SandgemTown_EventScript_LabArrival:
	applymovement LOCALID_SANDGEMTOWN_LUCASDAWN, Common_Movement_FaceUp
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	waitmovementall
	setspeaker SP_NAME_ASSISTANT
	msgbox SandgemTown_Text_ThisIsTheLab, MSGBOX_DEFAULT
	closemessage
	@ Plain door tile, so no open/close animation, just the exit sound.
	playse SE_EXIT
	addobject LOCALID_SANDGEM_BARRY
	applymovement LOCALID_SANDGEM_BARRY, SandgemTown_Movement_BarryExitLab
	waitmovement 0
	playse SE_WALL_HIT
	playbgm MUS_RIVAL_THEME, TRUE
	msgbox SandgemTown_Text_Thud, MSGBOX_DEFAULT
	setspeaker SP_NAME_RIVAL
	msgbox SandgemTown_Text_ThudBarryLeaves, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SANDGEM_BARRY, SandgemTown_Movement_BarryRunRight
	applymovement LOCALID_SANDGEMTOWN_LUCASDAWN, Common_Movement_FaceRight
	applymovement LOCALID_PLAYER, Common_Movement_FaceRight
	waitmovementall
	removeobject LOCALID_SANDGEM_BARRY
	setflag FLAG_HIDE_SANDGEM_TOWN_BARRY
	savebgm MUS_DUMMY
	fadedefaultbgm
	applymovement LOCALID_SANDGEMTOWN_LUCASDAWN, Common_Movement_FaceLeft
	waitmovement 0
	setspeaker SP_NAME_ASSISTANT
	msgbox SandgemTown_Text_WhatWasThat, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SANDGEMTOWN_LUCASDAWN, SandgemTown_Movement_LucasDawnEntersLab
	waitmovement 0
	playse SE_EXIT
	removeobject LOCALID_SANDGEMTOWN_LUCASDAWN
	applymovement LOCALID_PLAYER, SandgemTown_Movement_PlayerEntersLab
	waitmovement 0
	special ClearPlayerCollisionExemption
	setvar VAR_SANDGEM_TOWN_STATE, 3
	warp MAP_SANDGEM_TOWN_PROFESSOR_ROWANS_LAB, 0
	waitstate
	releaseall
	end

SandgemTown_Text_WaitingForYou:
	.string "Hi! I've been waiting for you!\p"
	.string "Please come with me. The\n"
	.string "professor's been waiting to see\l"
	.string "you.$"

SandgemTown_Text_ThisIsTheLab:
	.string "See? This is our Pokémon\n"
	.string "Research Lab.\p"
	.string "We'll just go ahead and…$"

SandgemTown_Text_Thud:
	.string "THUD!!$"

SandgemTown_Text_ThudBarryLeaves:
	.string "What the…\p"
	.string "Oh, it's you, {PLAYER}!\p"
	.string "That old guy… He's not scary so\n"
	.string "much as he is totally out there!\p"
	.string "Aww, it doesn't matter, {PLAYER}.\n"
	.string "I'm out of here. See you later!$"

SandgemTown_Text_WhatWasThat:
	.string "What was that?!\p"
	.string "Your friend always seems to be in\n"
	.string "such a rush.\p"
	.string "Anyway…\n"
	.string "Let's go in.$"

SandgemTown_Movement_BarryExitLab:
	walk_down
	step_end

SandgemTown_Movement_BarryRunRight:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

SandgemTown_Movement_LucasDawnEntersLab:
	walk_up
	walk_left
	walk_up
	step_end

SandgemTown_Movement_PlayerEntersLab:
	walk_up
	walk_up
	step_end

@ VAR_SANDGEM_TOWN_STATE == 6: on leaving the lab, LUCAS/DAWN gives the town tour
@ (Pokémon Center, Poké Mart), then walks off north. Player leaves the lab on (8, 10).
SandgemTown_EventScript_TownTour::
	lockall
	setvar VAR_0x8004, LOCALID_SANDGEMTOWN_LUCASDAWN
	special SetPlayerCollisionExemption
	setspeaker SP_NAME_ASSISTANT
	msgbox SandgemTown_Text_TourIntro, MSGBOX_DEFAULT
	closemessage
	getplayerxy VAR_0x8004, VAR_0x8005
	goto_if_eq VAR_0x8005, 10, SandgemTown_EventScript_TourLeadToCenterFromY10
	goto SandgemTown_EventScript_TourLeadToCenterFromY11

@ Walking out of the lab door may leave the player on y10 or y11; step to y11 first.
SandgemTown_EventScript_TourLeadToCenterFromY10:
	applymovement LOCALID_PLAYER, Common_Movement_WalkDown
	waitmovement 0

SandgemTown_EventScript_TourLeadToCenterFromY11:
	applymovement LOCALID_SANDGEMTOWN_LUCASDAWN, SandgemTown_Movement_LucasDawnToCenter
	applymovement LOCALID_PLAYER, SandgemTown_Movement_PlayerToCenterFromY11
	waitmovementall
	goto SandgemTown_EventScript_TourPokemonCenter

SandgemTown_EventScript_TourPokemonCenter:
	applymovement LOCALID_SANDGEMTOWN_LUCASDAWN, Common_Movement_FaceUp
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	waitmovementall
	setspeaker SP_NAME_ASSISTANT
	msgbox SandgemTown_Text_TourPokemonCenter, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SANDGEMTOWN_LUCASDAWN, SandgemTown_Movement_LucasDawnToMart
	applymovement LOCALID_PLAYER, SandgemTown_Movement_PlayerToMart
	waitmovementall
	applymovement LOCALID_SANDGEMTOWN_LUCASDAWN, Common_Movement_FaceUp
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	waitmovementall
	setspeaker SP_NAME_ASSISTANT
	msgbox SandgemTown_Text_TourPokeMart, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SANDGEMTOWN_LUCASDAWN, Common_Movement_FaceLeft
	applymovement LOCALID_PLAYER, Common_Movement_FaceRight
	waitmovementall
	playse SE_PIN
	applymovement LOCALID_SANDGEMTOWN_LUCASDAWN, Common_Movement_ExclamationMark
	waitmovement 0
	setspeaker SP_NAME_ASSISTANT
	msgbox SandgemTown_Text_TourFarewell, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SANDGEMTOWN_LUCASDAWN, SandgemTown_Movement_LucasDawnWalksAroundPlayer
	applymovement LOCALID_PLAYER, Common_Movement_FaceDown
	waitmovementall
	applymovement LOCALID_SANDGEMTOWN_LUCASDAWN, SandgemTown_Movement_LucasDawnWalksOffNorth
	applymovement LOCALID_PLAYER, Common_Movement_FaceLeft
	waitmovementall
	removeobject LOCALID_SANDGEMTOWN_LUCASDAWN
	setflag FLAG_HIDE_SANDGEMTOWN_LUCASDAWN
	setvar VAR_SANDGEM_TOWN_STATE, 9
	setvar VAR_TWINLEAF_TOWN_STATE, 13
	special ClearPlayerCollisionExemption
	releaseall
	end

SandgemTown_Text_TourIntro:
	.string "Hey, {PLAYER}!\n"
	.string "I want to show you a few things.\l"
	.string "So, follow me!$"

SandgemTown_Text_TourPokemonCenter:
	.string "This building with the red roof is\n"
	.string "the Pokémon Center.\p"
	.string "You can get your Pokémon healed\n"
	.string "here if it's been hurt in battle.\p"
	.string "You'll find a Pokémon Center in\n"
	.string "most towns.$"

SandgemTown_Text_TourPokeMart:
	.string "Over here, the building with the\n"
	.string "blue roof is the Poké Mart.\p"
	.string "It's a shop where you can buy and\n"
	.string "sell all sorts of items.\p"
	.string "{PLAYER}, since you're a rookie\n"
	.string "trainer, you won't be able to buy\l"
	.string "very much stuff. That'll change as\l"
	.string "you progress, so don't worry about\l"
	.string "it, OK?$"

SandgemTown_Text_TourFarewell:
	.string "Oh, yea, right!\n"
	.string "{PLAYER}…\p"
	.string "You should let your family know\n"
	.string "you're helping Prof. Rowan put\l"
	.string "together his Pokédex.\p"
	.string "Sometimes, you have to go far\n"
	.string "away, so you should let someone\l"
	.string "know.\p"
	.string "Oh, but first, go heal up your\n"
	.string "Pokémon at the Pokémon Center.\l"
	.string "You'll be safe then.\l"
	.string "OK, be seeing you!$"

SandgemTown_Movement_LucasDawnToCenter:
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

SandgemTown_Movement_PlayerToCenterFromY11:
	walk_down
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

SandgemTown_Movement_LucasDawnToMart:
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

SandgemTown_Movement_PlayerToMart:
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

SandgemTown_Movement_LucasDawnWalksAroundPlayer:
	walk_down
	walk_left
	step_end

SandgemTown_Movement_LucasDawnWalksOffNorth:
	walk_left
	walk_left
	walk_left
	walk_left
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
	walk_up
	step_end
