SandgemTown_ProfessorRowansLab_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SandgemTown_ProfessorRowansLab_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SandgemTown_ProfessorRowansLab_OnFrame
	.byte 0

SandgemTown_ProfessorRowansLab_OnTransition:
	call Common_EventScript_SetupLucasDawnAssistantGfxId
	setflag FLAG_HIDE_PROFESSORROWANSLAB_LUCASDAWN
	call_if_eq VAR_SANDGEM_TOWN_STATE, 3, SandgemTown_ProfessorRowansLab_EventScript_ShowLucasDawn
	end

SandgemTown_ProfessorRowansLab_EventScript_ShowLucasDawn:
	clearflag FLAG_HIDE_PROFESSORROWANSLAB_LUCASDAWN
	return

SandgemTown_ProfessorRowansLab_OnFrame:
	map_script_2 VAR_SANDGEM_TOWN_STATE, 3, SandgemTown_ProfessorRowansLab_EventScript_RowanIntro
	.2byte 0

@ VAR_SANDGEM_TOWN_STATE == 3: LUCAS/DAWN leads the player to ROWAN, who hands
@ over the starter and the Pokédex. Player always enters from warp 0 at (6, 12).
SandgemTown_ProfessorRowansLab_EventScript_RowanIntro::
	lockall
	setvar VAR_0x8004, LOCALID_PROFESSORROWANSLAB_LUCASDAWN
	special SetPlayerCollisionExemption
	applymovement LOCALID_PROFESSORROWANSLAB_LUCASDAWN, SandgemTown_ProfessorRowansLab_Movement_LucasDawnTurnAround
	waitmovement 0
	applymovement LOCALID_PROFESSORROWANSLAB_LUCASDAWN, SandgemTown_ProfessorRowansLab_Movement_LucasDawnLeadsToRowan
	applymovement LOCALID_PLAYER, SandgemTown_ProfessorRowansLab_Movement_PlayerFollowsToRowan
	waitmovementall
	bufferleadmonspeciesname STR_VAR_1
	setspeaker SP_NAME_ROWAN
	msgbox SandgemTown_ProfessorRowansLab_Text_RowanFinallyYouveCome, MSGBOX_DEFAULT
	msgbox SandgemTown_ProfessorRowansLab_Text_RowanGiveNickname, MSGBOX_YESNO
	closemessage
	goto_if_eq VAR_RESULT, YES, SandgemTown_ProfessorRowansLab_EventScript_NicknameStarter
	goto SandgemTown_ProfessorRowansLab_EventScript_AfterNickname

SandgemTown_ProfessorRowansLab_EventScript_NicknameStarter:
	setvar VAR_0x8004, 0
	call Common_EventScript_NameReceivedPartyMon
	goto SandgemTown_ProfessorRowansLab_EventScript_AfterNickname

SandgemTown_ProfessorRowansLab_EventScript_AfterNickname:
	bufferleadmonspeciesname STR_VAR_1
	setspeaker SP_NAME_ROWAN
	msgbox SandgemTown_ProfessorRowansLab_Text_RowanRivalToldMe, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PROFESSORROWANSLAB_LUCASDAWN, Common_Movement_WalkInPlaceLeft
	applymovement LOCALID_PLAYER, Common_Movement_FaceRight
	waitmovementall
	setspeaker SP_NAME_ASSISTANT
	msgbox SandgemTown_ProfessorRowansLab_Text_LucasDawnGladYoureKind, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PROFESSORROWANSLAB_ROWAN, SandgemTown_ProfessorRowansLab_Movement_RowanWalkInPlace
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	waitmovementall
	setspeaker SP_NAME_ROWAN
	msgbox SandgemTown_ProfessorRowansLab_Text_RowanMainTopic, MSGBOX_DEFAULT
	goto SandgemTown_ProfessorRowansLab_EventScript_AskAboutPokedex

SandgemTown_ProfessorRowansLab_EventScript_AskAboutPokedex:
	setspeaker SP_NAME_ROWAN
	msgbox SandgemTown_ProfessorRowansLab_Text_RowanEntrustPokedex, MSGBOX_YESNO
	closemessage
	goto_if_eq VAR_RESULT, YES, SandgemTown_ProfessorRowansLab_EventScript_AcceptedPokedex
	setspeaker SP_NAME_ROWAN
	msgbox SandgemTown_ProfessorRowansLab_Text_RowanSilence, MSGBOX_DEFAULT
	goto SandgemTown_ProfessorRowansLab_EventScript_AskAboutPokedex

SandgemTown_ProfessorRowansLab_EventScript_AcceptedPokedex:
	setspeaker SP_NAME_ROWAN
	msgbox SandgemTown_ProfessorRowansLab_Text_RowanGoodAnswer, MSGBOX_DEFAULT
	closemessage
	playfanfare MUS_OBTAIN_ITEM
	message SandgemTown_ProfessorRowansLab_Text_ReceivedPokedex
	waitfanfare
	setflag FLAG_SYS_POKEDEX_GET
	special SetUnlockedPokedexFlags
	setspeaker SP_NAME_ROWAN
	msgbox SandgemTown_ProfessorRowansLab_Text_RowanPokedexSpeech, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PROFESSORROWANSLAB_LUCASDAWN, Common_Movement_WalkInPlaceLeft
	applymovement LOCALID_PLAYER, Common_Movement_FaceRight
	waitmovementall
	setspeaker SP_NAME_ASSISTANT
	msgbox SandgemTown_ProfessorRowansLab_Text_LucasDawnSamePokedex, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PROFESSORROWANSLAB_LUCASDAWN, SandgemTown_ProfessorRowansLab_Movement_LucasDawnLeavesLab
	applymovement LOCALID_PLAYER, Common_Movement_FaceDown
	waitmovementall
	playse SE_EXIT
	removeobject LOCALID_PROFESSORROWANSLAB_LUCASDAWN
	setflag FLAG_HIDE_PROFESSORROWANSLAB_LUCASDAWN
	special ClearPlayerCollisionExemption
	setvar VAR_SANDGEM_TOWN_STATE, 6
	releaseall
	end

SandgemTown_ProfessorRowansLab_Movement_LucasDawnTurnAround:
	delay_16
	face_up
	step_end

SandgemTown_ProfessorRowansLab_Movement_LucasDawnLeadsToRowan:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	face_left
	step_end

SandgemTown_ProfessorRowansLab_Movement_PlayerFollowsToRowan:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

SandgemTown_ProfessorRowansLab_Movement_RowanWalkInPlace:
	walk_in_place_down
	step_end

SandgemTown_ProfessorRowansLab_Movement_LucasDawnLeavesLab:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

SandgemTown_ProfessorRowansLab_EventScript_NPC1::
	msgbox SandgemTown_ProfessorRowansLab_Text_NPC1, MSGBOX_NPC
	end

SandgemTown_ProfessorRowansLab_EventScript_NPC2::
	msgbox SandgemTown_ProfessorRowansLab_Text_NPC2, MSGBOX_NPC
	end

SandgemTown_ProfessorRowansLab_EventScript_NPC3::
	msgbox SandgemTown_ProfessorRowansLab_Text_NPC3, MSGBOX_NPC
	end

SandgemTown_ProfessorRowansLab_Text_NPC1:
	.string "PROFESSOR ROWANS LAB NPC 1$"

SandgemTown_ProfessorRowansLab_Text_NPC2:
	.string "PROFESSOR ROWANS LAB NPC 2$"

SandgemTown_ProfessorRowansLab_Text_NPC3:
	.string "PROFESSOR ROWANS LAB NPC 3$"

SandgemTown_ProfessorRowansLab_Text_RowanFinallyYouveCome:
	.string "…\p"
	.string "Finally, you've come. {PLAYER}, was\n"
	.string "it?\p"
	.string "Let me see your Pokémon again.\p"
	.string "…\p"
	.string "Hm… I see…\p"
	.string "This Pokémon seems to be rather\n"
	.string "happy.\p"
	.string "All righty then!\p"
	.string "I'll give you that {STR_VAR_1} as a\n"
	.string "gift.$"

SandgemTown_ProfessorRowansLab_Text_RowanGiveNickname:
	.string "Now that it's yours, would you\n"
	.string "like to give it a nickname?$"

SandgemTown_ProfessorRowansLab_Text_RowanRivalToldMe:
	.string "Your friend {RIVAL} told me what\n"
	.string "happened at the lake.\p"
	.string "I heard you battled very well,\n"
	.string "despite it being your first time.\p"
	.string "And, from what I can see, there is\n"
	.string "a growing bond between you and\l"
	.string "that Pokémon, though it is still\l"
	.string "young.\p"
	.string "That's why I would like to entrust\n"
	.string "you with {STR_VAR_1}.$"

SandgemTown_ProfessorRowansLab_Text_LucasDawnGladYoureKind:
	.string "Boy, am I glad you're kind toward\n"
	.string "Pokémon.\p"
	.string "If you weren't, well… I don't even\n"
	.string "want to think about it.$"

SandgemTown_ProfessorRowansLab_Text_RowanMainTopic:
	.string "Er-hem! Let's move on to the main\n"
	.string "topic.\p"
	.string "There is something I want you to\n"
	.string "do for me. My name is Rowan. I\l"
	.string "study Pokémon.\p"
	.string "First of all, I want to know\n"
	.string "exactly what kinds of Pokémon live\l"
	.string "in the Sinnoh region.\p"
	.string "To do so, it is necessary to\n"
	.string "collect data using the Pokédex.\l"
	.string "This is what I wish to ask of you.$"

SandgemTown_ProfessorRowansLab_Text_RowanEntrustPokedex:
	.string "I want to entrust you with this\n"
	.string "Pokédex.\p"
	.string "Will you use it to record data on\n"
	.string "all the Pokémon in Sinnoh for me?$"

SandgemTown_ProfessorRowansLab_Text_RowanSilence:
	.string "…\p"
	.string "…\p"
	.string "…\p"
	.string "…\p"
	.string "I can stand here without speaking\n"
	.string "for hours. I'm a very patient man.\p"
	.string "Let me ask you again, {PLAYER}.$"

SandgemTown_ProfessorRowansLab_Text_RowanGoodAnswer:
	.string "Hm!\p"
	.string "Good answer!$"

SandgemTown_ProfessorRowansLab_Text_ReceivedPokedex:
	.string "{PLAYER} received the Pokédex!$"

SandgemTown_ProfessorRowansLab_Text_RowanPokedexSpeech:
	.string "That Pokédex is a very high-tech\n"
	.string "device. It will automatically\l"
	.string "record data on every kind of\l"
	.string "Pokémon you encounter.\p"
	.string "{PLAYER}, I ask that you go\n"
	.string "everywhere and meet every kind of\l"
	.string "Pokémon in this region!\p"
	.string "When you walked up Route 201 with\n"
	.string "your Pokémon, what did you feel?\p"
	.string "I've lived for 60 long years. Even\n"
	.string "now, I get a thrill when I'm with\l"
	.string "a Pokémon.\p"
	.string "Now, you should know that there\n"
	.string "are countless Pokémon in this\l"
	.string "world. That means there are just\l"
	.string "as many thrills waiting for you\l"
	.string "out there!\p"
	.string "Now go! {PLAYER}, your grand\n"
	.string "adventure begins right now!$"

SandgemTown_ProfessorRowansLab_Text_LucasDawnSamePokedex:
	.string "I've got the same kind of Pokédex\n"
	.string "as you. The professor asked me to\l"
	.string "help out, so I'm going to go out\l"
	.string "and fill the Pokédex pages, too.\p"
	.string "That makes us comrades working\n"
	.string "toward the same goal. I'll teach\l"
	.string "you stuff later, OK?$"
