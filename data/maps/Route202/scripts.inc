Route202_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route202_OnTransition
	.byte 0

Route202_OnTransition:
	call Common_EventScript_SetupLucasDawnAssistantGfxId
	setflag FLAG_HIDE_ROUTE202_LUCASDAWN
	call_if_eq VAR_SANDGEM_TOWN_STATE, 9, Route202_EventScript_ShowLucasDawn
	end

Route202_EventScript_ShowLucasDawn:
	clearflag FLAG_HIDE_ROUTE202_LUCASDAWN
	return

Route202_EventScript_Sign1::
	msgbox Route202_Text_Sign1, MSGBOX_SIGN
	end

Route202_EventScript_Sign2::
	msgbox Route202_Text_Sign2, MSGBOX_SIGN
	end

Route202_EventScript_Sign3::
	msgbox Route202_Text_Sign3, MSGBOX_SIGN
	end

Route202_Text_Sign1:
	.string "Route 202\n"
	.string "{DOWN_ARROW} Sandgem Town$"

Route202_Text_Sign2:
	.string "Trainer Tips!\p"
	.string "Some Pokemon only appear in the\n"
	.string "morning. Some only come out during the\l"
	.string "day, or at night.\p"
	.string "Be sure to check a route throughout a\n"
	.string "day to see who else could appear!$"

Route202_Text_Sign3:
	.string "Route 202\n"
	.string "{UP_ARROW} Jubilife City$"

Route202_EventScript_Trainer1::
	trainerbattle_single TRAINER_ROUTE202_1, Route202_Text_Trainer1Intro, Route202_Text_Trainer1Defeated
	msgbox Route202_Text_Trainer1PostBattle, MSGBOX_AUTOCLOSE
	end

Route202_EventScript_Trainer2::
	trainerbattle_single TRAINER_ROUTE202_2, Route202_Text_Trainer2Intro, Route202_Text_Trainer2Defeated
	msgbox Route202_Text_Trainer2PostBattle, MSGBOX_AUTOCLOSE
	end

Route202_EventScript_Trainer3::
	trainerbattle_single TRAINER_ROUTE202_3, Route202_Text_Trainer3Intro, Route202_Text_Trainer3Defeated
	msgbox Route202_Text_Trainer3PostBattle, MSGBOX_AUTOCLOSE
	end

Route202_EventScript_Trainer4::
	trainerbattle_single TRAINER_ROUTE202_4, Route202_Text_Trainer4Intro, Route202_Text_Trainer4Defeated
	msgbox Route202_Text_Trainer4PostBattle, MSGBOX_AUTOCLOSE
	end

Route202_Text_Trainer1Intro:
	.string "You're a Pokemon Trainer!\n"
	.string "I happen to be a Pokemon Trainer!\l"
	.string "Our eyes met, so battle we must!$"

Route202_Text_Trainer1Defeated:
	.string "Wow, you showed me, alright!$"

Route202_Text_Trainer1PostBattle:
	.string "Don't be shy about talking to Trainers\n"
	.string "you'd like to battle. Pokemon grow\l"
	.string "stronger and stronger from battling.$"

Route202_Text_Trainer2Intro:
	.string "Where do you stand on Bug Pokemon?$"

Route202_Text_Trainer2Defeated:
	.string "Ahhh! My bugs!$"

Route202_Text_Trainer2PostBattle:
	.string "My bugs are all tuckered out! I need to\n"
	.string "go to a Pokemon Center!$"

Route202_Text_Trainer3Intro:
	.string "Zap zap!$"

Route202_Text_Trainer3Defeated:
	.string "Aww..no more zaps.$"

Route202_Text_Trainer3PostBattle:
	.string "It's nice being able to avoid the tall\n"
	.string "grass by jumping down all these ledges.\l"
	.string "It makes getting back to {COLOR DYNAMIC_COLOR3}Sandgem Town{COLOR DARK_GRAY}\l"
	.string "super easy!$"

Route202_Text_Trainer4Intro:
	.string "Let's have a Pokemon battle! Humph! But\n"
	.string "I'm gonna win!$"

Route202_Text_Trainer4Defeated:
	.string "You're like, wow!$"

Route202_Text_Trainer4PostBattle:
	.string "It's fun to battle others!\n"
	.string "I'm gonna battle all sorts of people!$"

Route202_EventScript_NPC1::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SHINX, CRY_MODE_NORMAL
	setspeaker Route202_Text_NPC1Speaker
	msgbox Route202_Text_NPC1, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route202_EventScript_NPC2::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_GROWLITHE, CRY_MODE_NORMAL
	setspeaker Route202_Text_NPC2Speaker
	msgbox Route202_Text_NPC2, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route202_Text_NPC1Speaker:
	.string "Shinx$"

Route202_Text_NPC1:
	.string "ROUTE 202 NPC 1$"

Route202_Text_NPC2Speaker:
	.string "Growlithe$"

Route202_Text_NPC2:
	.string "ROUTE 202 NPC 2$"

@ VAR_SANDGEM_TOWN_STATE == 9: LUCAS/DAWN waits at (20, 27) and catches the player on x26 (y25-29).

Route202_EventScript_LucasDawnStopsPlayerAtY25::
	lockall
	setvar VAR_0x8004, LOCALID_ROUTE202_LUCASDAWN
	special SetPlayerCollisionExemption
	applymovement LOCALID_ROUTE202_LUCASDAWN, Route202_Movement_LucasDawnToPlayerAtY25
	applymovement LOCALID_PLAYER, Common_Movement_FaceLeft
	waitmovementall
	goto Route202_EventScript_LucasDawnStopsPlayer

Route202_EventScript_LucasDawnStopsPlayerAtY26::
	lockall
	setvar VAR_0x8004, LOCALID_ROUTE202_LUCASDAWN
	special SetPlayerCollisionExemption
	applymovement LOCALID_ROUTE202_LUCASDAWN, Route202_Movement_LucasDawnToPlayerAtY26
	applymovement LOCALID_PLAYER, Common_Movement_FaceLeft
	waitmovementall
	goto Route202_EventScript_LucasDawnStopsPlayer

Route202_EventScript_LucasDawnStopsPlayerAtY27::
	lockall
	setvar VAR_0x8004, LOCALID_ROUTE202_LUCASDAWN
	special SetPlayerCollisionExemption
	applymovement LOCALID_ROUTE202_LUCASDAWN, Route202_Movement_LucasDawnToPlayerAtY27
	applymovement LOCALID_PLAYER, Common_Movement_FaceLeft
	waitmovementall
	goto Route202_EventScript_LucasDawnStopsPlayer

Route202_EventScript_LucasDawnStopsPlayerAtY28::
	lockall
	setvar VAR_0x8004, LOCALID_ROUTE202_LUCASDAWN
	special SetPlayerCollisionExemption
	applymovement LOCALID_ROUTE202_LUCASDAWN, Route202_Movement_LucasDawnToPlayerAtY28
	applymovement LOCALID_PLAYER, Common_Movement_FaceLeft
	waitmovementall
	goto Route202_EventScript_LucasDawnStopsPlayer

Route202_EventScript_LucasDawnStopsPlayerAtY29::
	lockall
	setvar VAR_0x8004, LOCALID_ROUTE202_LUCASDAWN
	special SetPlayerCollisionExemption
	applymovement LOCALID_ROUTE202_LUCASDAWN, Route202_Movement_LucasDawnToPlayerAtY29
	applymovement LOCALID_PLAYER, Common_Movement_FaceLeft
	waitmovementall
	goto Route202_EventScript_LucasDawnStopsPlayer

Route202_EventScript_LucasDawnStopsPlayer::
	goto_if_ge VAR_TWINLEAF_TOWN_STATE, 14, Route202_EventScript_LucasDawnCatchingTips
	setspeaker SP_NAME_ASSISTANT
	msgbox Route202_Text_LucasDawnTellYourFamily, MSGBOX_DEFAULT
	closemessage
	getplayerxy VAR_0x8008, VAR_0x8009
	applymovement LOCALID_PLAYER, Common_Movement_WalkRight
	call_if_eq VAR_0x8009, 25, Route202_EventScript_LucasDawnReturnsFromY25
	call_if_eq VAR_0x8009, 26, Route202_EventScript_LucasDawnReturnsFromY26
	call_if_eq VAR_0x8009, 27, Route202_EventScript_LucasDawnReturnsFromY27
	call_if_eq VAR_0x8009, 28, Route202_EventScript_LucasDawnReturnsFromY28
	call_if_eq VAR_0x8009, 29, Route202_EventScript_LucasDawnReturnsFromY29
	waitmovementall
	special ClearPlayerCollisionExemption
	releaseall
	end

Route202_EventScript_LucasDawnReturnsFromY25::
	applymovement LOCALID_ROUTE202_LUCASDAWN, Route202_Movement_LucasDawnReturnsFromY25
	return

Route202_EventScript_LucasDawnReturnsFromY26::
	applymovement LOCALID_ROUTE202_LUCASDAWN, Route202_Movement_LucasDawnReturnsFromY26
	return

Route202_EventScript_LucasDawnReturnsFromY27::
	applymovement LOCALID_ROUTE202_LUCASDAWN, Route202_Movement_LucasDawnReturnsFromY27
	return

Route202_EventScript_LucasDawnReturnsFromY28::
	applymovement LOCALID_ROUTE202_LUCASDAWN, Route202_Movement_LucasDawnReturnsFromY28
	return

Route202_EventScript_LucasDawnReturnsFromY29::
	applymovement LOCALID_ROUTE202_LUCASDAWN, Route202_Movement_LucasDawnReturnsFromY29
	return

Route202_EventScript_LucasDawnCatchingTips::
	setspeaker SP_NAME_ASSISTANT
	msgbox Route202_Text_LucasDawnKnowHowToCatch, MSGBOX_YESNO
	closemessage
	goto_if_eq VAR_RESULT, YES, Route202_EventScript_LucasDawnKnowsHowToCatch

@ Walks into the grass, then plays the catch tutorial battle.
Route202_EventScript_LucasDawnTeachesCatching::
	setspeaker SP_NAME_ASSISTANT
	msgbox Route202_Text_LucasDawnWatchThis, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ROUTE202_LUCASDAWN, Route202_Movement_LucasDawnIntoGrass
	applymovement LOCALID_PLAYER, Route202_Movement_PlayerIntoGrass
	waitmovementall
	special SavePlayerParty
	special LoadAssistantStarter
	special StartAssistantTutorialBattle
	special LoadPlayerParty
	applymovement LOCALID_ROUTE202_LUCASDAWN, Common_Movement_FaceRight
	applymovement LOCALID_PLAYER, Common_Movement_FaceLeft
	waitmovementall
	setspeaker SP_NAME_ASSISTANT
	msgbox Route202_Text_LucasDawnThatsHowItsDone, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_POKE_BALL, 10
	goto Route202_EventScript_LucasDawnFarewell

Route202_EventScript_LucasDawnKnowsHowToCatch::
	setspeaker SP_NAME_ASSISTANT
	msgbox Route202_Text_LucasDawnImpressed, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_POKE_BALL, 10
	goto Route202_EventScript_LucasDawnFarewell

Route202_EventScript_LucasDawnFarewell::
	setspeaker SP_NAME_ASSISTANT
	msgbox Route202_Text_LucasDawnTravelFarther, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ROUTE202_LUCASDAWN, Route202_Movement_LucasDawnWalksOff
	waitmovement LOCALID_ROUTE202_LUCASDAWN
	removeobject LOCALID_ROUTE202_LUCASDAWN
	setflag FLAG_HIDE_ROUTE202_LUCASDAWN
	setvar VAR_SANDGEM_TOWN_STATE, 12
	special ClearPlayerCollisionExemption
	releaseall
	end

Route202_Movement_LucasDawnToPlayerAtY25:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	face_right
	step_end

Route202_Movement_LucasDawnReturnsFromY25:
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	face_right
	step_end

Route202_Movement_LucasDawnToPlayerAtY26:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	face_right
	step_end

Route202_Movement_LucasDawnReturnsFromY26:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	face_right
	step_end

Route202_Movement_LucasDawnToPlayerAtY27:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	face_right
	step_end

Route202_Movement_LucasDawnReturnsFromY27:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	face_right
	step_end

Route202_Movement_LucasDawnToPlayerAtY28:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	face_right
	step_end

Route202_Movement_LucasDawnReturnsFromY28:
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	face_right
	step_end

Route202_Movement_LucasDawnToPlayerAtY29:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	face_right
	step_end

Route202_Movement_LucasDawnReturnsFromY29:
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	face_right
	step_end

Route202_Movement_LucasDawnIntoGrass:
	walk_left
	walk_left
	step_end

Route202_Movement_PlayerIntoGrass:
	walk_left
	walk_left
	step_end

Route202_Movement_LucasDawnWalksOff:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

Route202_Text_LucasDawnTellYourFamily:
	.string "Why don't you go tell your family\n"
	.string "that the professor asked for your\l"
	.string "help?\p"
	.string "You should do it right away.$"

Route202_Text_LucasDawnKnowHowToCatch:
	.string "{PLAYER}, do you know how to catch\n"
	.string "a Pokémon?$"

Route202_Text_LucasDawnImpressed:
	.string "Oh wow, look at you! I'm impressed\n"
	.string "to hear that.\p"
	.string "Well, if you don't need my help,\n"
	.string "then here, take these!$"

Route202_Text_LucasDawnWatchThis:
	.string "That's okay! I can teach you.\n"
	.string "Come watch this!$"

Route202_Text_LucasDawnThatsHowItsDone:
	.string "And that's how it's done.\p"
	.string "Actually, I should have lowered the\n"
	.string "target's HP some more.\p"
	.string "Yup, the important thing is to lower\n"
	.string "the Pokémon's HP as much as\l"
	.string "possible. A healthy Pokémon isn't\l"
	.string "easy to catch.\p"
	.string "They'll also become easier to catch\n"
	.string "if you make one of your Pokémon put\l"
	.string "them to sleep or such.\p"
	.string "Here, {PLAYER}, I'll give you these\n"
	.string "to get you started.$"

Route202_Text_LucasDawnTravelFarther:
	.string "If you have lots of Pokémon with\n"
	.string "you, you'll be able to travel\l"
	.string "farther.\p"
	.string "That way, you'll have a better shot\n"
	.string "at meeting more Pokémon.\p"
	.string "See you around!$"
