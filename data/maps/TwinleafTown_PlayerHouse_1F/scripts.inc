TwinleafTown_PlayerHouse_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, TwinleafTown_PlayerHouse_1F_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, TwinleafTown_PlayerHouse_1F_OnFrame
	.byte 0

@ MOM idles at (6,5) normally, and gets relocated to (1,3) here for the
@ homecoming scene when VAR_TWINLEAF_TOWN_STATE == 11.
TwinleafTown_PlayerHouse_1F_OnTransition:
	call_if_eq VAR_TWINLEAF_TOWN_STATE, 11, TwinleafTown_PlayerHouse_1F_EventScript_PositionMomForHomecoming
	end

TwinleafTown_PlayerHouse_1F_EventScript_PositionMomForHomecoming:
	setobjectxyperm LOCALID_PLAYER_MOM, 1, 3
	setobjectmovementtype LOCALID_PLAYER_MOM, MOVEMENT_TYPE_FACE_DOWN
	return

TwinleafTown_PlayerHouse_1F_OnFrame:
	map_script_2 VAR_TWINLEAF_TOWN_PLAYER_HOUSE_STATE, 0, TwinleafTown_PlayerHouse_1F_EventScript_MomGivesRunningShoes
	map_script_2 VAR_TWINLEAF_TOWN_STATE, 11, TwinleafTown_PlayerHouse_1F_EventScript_MomHomecoming
	.2byte 0

@ Triggers when VAR_TWINLEAF_TOWN_STATE == 11, right after the player
@ warps home from ROUTE 201. MOM greets the player and sends them to
@ SANDGEM TOWN.
TwinleafTown_PlayerHouse_1F_EventScript_MomHomecoming::
	lockall
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	waitmovement LOCALID_PLAYER
	applymovement LOCALID_PLAYER_MOM, TwinleafTown_PlayerHouse_1F_Movement_MomCooks
	waitmovement LOCALID_PLAYER_MOM
	applymovement LOCALID_PLAYER, Common_Movement_FaceRight
	applymovement LOCALID_PLAYER_MOM, TwinleafTown_PlayerHouse_1F_Movement_MomWalksOutOfKitchen
	waitmovement LOCALID_PLAYER_MOM
	applymovement LOCALID_PLAYER_MOM, TwinleafTown_PlayerHouse_1F_Movement_MomWalksToCenterAndTurns
	applymovement LOCALID_PLAYER, TwinleafTown_PlayerHouse_1F_Movement_PlayerFollowsMom
	waitmovementall
	setspeaker SP_NAME_MOM
	msgbox TwinleafTown_PlayerHouse_1F_Text_MomWhatsUpDear, MSGBOX_DEFAULT
	closemessage
	setspeaker SP_NAME_MOM
	msgbox TwinleafTown_PlayerHouse_1F_Text_MomEllipsis, MSGBOX_DEFAULT
	closemessage
	setspeaker SP_NAME_MOM
	msgbox TwinleafTown_PlayerHouse_1F_Text_MomWow, MSGBOX_DEFAULT
	closemessage
	setspeaker SP_NAME_MOM
	msgbox TwinleafTown_PlayerHouse_1F_Text_MomGladUnharmed, MSGBOX_DEFAULT
	closemessage
	setspeaker SP_NAME_MOM
	msgbox TwinleafTown_PlayerHouse_1F_Text_MomProfessorRowan, MSGBOX_DEFAULT
	closemessage
	setspeaker SP_NAME_MOM
	msgbox TwinleafTown_PlayerHouse_1F_Text_MomHeardOfHim, MSGBOX_DEFAULT
	closemessage
	setspeaker SP_NAME_MOM
	msgbox TwinleafTown_PlayerHouse_1F_Text_MomVisitSandgem, MSGBOX_DEFAULT
	closemessage
	setspeaker SP_NAME_MOM
	msgbox TwinleafTown_PlayerHouse_1F_Text_MomDontWorry, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TWINLEAF_TOWN_STATE, 12
	@ Cleared by TwinleafTown_OnTransition the moment the player steps
	@ back outside, so MOM's repeatable rest offer takes over after that.
	setflag FLAG_TWINLEAF_TOWN_PLAYER_HOUSE_MOM_MENTIONED_SANDGEM
	releaseall
	end


TwinleafTown_PlayerHouse_1F_Movement_MomCooks:
	delay_16
	walk_left
	face_up
	delay_16
    delay_16
	walk_right
	step_end


TwinleafTown_PlayerHouse_1F_Movement_MomWalksOutOfKitchen:
	walk_right
	walk_right
	walk_down
	walk_down
	step_end


TwinleafTown_PlayerHouse_1F_Movement_MomWalksToCenterAndTurns:	
	walk_right
	walk_right
	walk_right
	face_left
	delay_16
	step_end

TwinleafTown_PlayerHouse_1F_Movement_PlayerFollowsMom:
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

TwinleafTown_PlayerHouse_1F_Text_MomWhatsUpDear:
	.string "What's up, dear?$"

TwinleafTown_PlayerHouse_1F_Text_MomEllipsis:
	.string "…$"

TwinleafTown_PlayerHouse_1F_Text_MomWow:
	.string "Wow.\n"
	.string "I can't believe that happened to you.$"

TwinleafTown_PlayerHouse_1F_Text_MomGladUnharmed:
	.string "Am I ever glad that both you\n"
	.string "and {RIVAL} are unharmed.$"

TwinleafTown_PlayerHouse_1F_Text_MomProfessorRowan:
	.string "The professor you mentioned is most\n"
	.string "likely Professor Rowan of Sandgem Town.$"

TwinleafTown_PlayerHouse_1F_Text_MomHeardOfHim:
	.string "I've heard that he is well known for\n"
	.string "his studies on POKéMON.\p"
	.string "I hear he's also quite intimidating…$"

TwinleafTown_PlayerHouse_1F_Text_MomVisitSandgem:
	.string "{PLAYER}, I think you need to visit\n"
	.string "him in Sandgem Town.\p"
	.string "You need to properly explain why you\n"
	.string "had no choice but to use his POKéMON.$"

TwinleafTown_PlayerHouse_1F_Text_MomDontWorry:
	.string "Don't worry! I'm sure he'll understand.$"

@ Triggers when VAR_TWINLEAF_TOWN_PLAYER_HOUSE_STATE == 0, the instant the
@ player lands on this map for the very first time (coming downstairs, at
@ (9,1)). Runs on-frame rather than a coordinate/step trigger, since
@ those are unreliable on the game's very first-ever warp (the new-game
@ startup path loads the map synchronously in one frame instead of the
@ normal multi-frame warp sequence every other warp uses).
@
@ This uses its own dedicated var, NOT VAR_TWINLEAF_TOWN_STATE — that one
@ is already spoken for by TwinleafTown's neighbor-blocks-the-path /
@ BARRY's-house sequence, which also starts at 0. Advancing
@ VAR_TWINLEAF_TOWN_STATE here instead would fast-forward straight past
@ that entire sequence before the player ever leaves the house.
@
@ MOM gives the player Running Shoes and advances this var so the door
@ reminder below can fire next.
TwinleafTown_PlayerHouse_1F_EventScript_MomGivesRunningShoes::
	lockall
	playse SE_PIN
	applymovement LOCALID_PLAYER_MOM, TwinleafTown_PlayerHouse_1F_Movement_MomGivesShoes
	waitmovement LOCALID_PLAYER_MOM
	setspeaker SP_NAME_MOM
	msgbox TwinleafTown_PlayerHouse_1F_Text_MomExclaimsPlayerName, MSGBOX_DEFAULT
	closemessage
	setspeaker SP_NAME_MOM
	msgbox TwinleafTown_PlayerHouse_1F_Text_MomRivalCameCalling, MSGBOX_DEFAULT
	closemessage
	setspeaker SP_NAME_MOM
	msgbox TwinleafTown_PlayerHouse_1F_Text_MomDontKnowWhatItWasAbout, MSGBOX_DEFAULT
	closemessage
	setspeaker SP_NAME_MOM
	msgbox TwinleafTown_PlayerHouse_1F_Text_MomPleaseWearThese, MSGBOX_DEFAULT
	setspeaker SP_NAME_NONE
	playfanfare MUS_OBTAIN_ITEM
	message TwinleafTown_PlayerHouse_1F_Text_ReceivedRunningShoes
	waitfanfare
	setflag FLAG_RECEIVED_RUNNING_SHOES
	setflag FLAG_SYS_B_DASH
	closemessage
	setspeaker SP_NAME_MOM
	msgbox TwinleafTown_PlayerHouse_1F_Text_MomPressBButton, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER_MOM, TwinleafTown_PlayerHouse_1F_Movement_MomReturnsToSpot
	waitmovement LOCALID_PLAYER_MOM
	setvar VAR_TWINLEAF_TOWN_PLAYER_HOUSE_STATE, 1
	releaseall
	end

@ Triggers when VAR_TWINLEAF_TOWN_PLAYER_HOUSE_STATE == 1, on either door
@ tile, once the player is free to move again after receiving the
@ running shoes. Advances this same dedicated var to 2 (not
@ VAR_TWINLEAF_TOWN_STATE — see the comment above the shoes scene); the
@ real story state stays untouched at 0 until the player actually leaves
@ and runs into the neighbor/BARRY's house sequence outside.
TwinleafTown_PlayerHouse_1F_EventScript_MomDoorReminder::
	lockall
	applymovement LOCALID_PLAYER_MOM, TwinleafTown_PlayerHouse_1F_Movement_MomFacesPlayerAtDoor
	waitmovement LOCALID_PLAYER_MOM
	applymovement LOCALID_PLAYER, TwinleafTown_PlayerHouse_1F_Movement_PlayerFacesMomAtDoor
	waitmovement LOCALID_PLAYER
	setspeaker SP_NAME_MOM
	msgbox TwinleafTown_PlayerHouse_1F_Text_MomOhYesPlayerName, MSGBOX_DEFAULT
	closemessage
	setspeaker SP_NAME_MOM
	msgbox TwinleafTown_PlayerHouse_1F_Text_MomDontGoInTallGrass, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TWINLEAF_TOWN_PLAYER_HOUSE_STATE, 2
	releaseall
	end

TwinleafTown_PlayerHouse_1F_Movement_MomGivesShoes:
	emote_exclamation_mark
	delay_16
    delay_16
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	step_end

TwinleafTown_PlayerHouse_1F_Movement_MomReturnsToSpot:
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	face_up
	step_end

TwinleafTown_PlayerHouse_1F_Movement_MomFacesPlayerAtDoor:
	face_down
	delay_16
	step_end

TwinleafTown_PlayerHouse_1F_Movement_PlayerFacesMomAtDoor:
	face_up
	step_end

TwinleafTown_PlayerHouse_1F_Text_MomExclaimsPlayerName:
	.string "{PLAYER}!$"

TwinleafTown_PlayerHouse_1F_Text_MomRivalCameCalling:
	.string "{RIVAL} came calling for you a\n"
	.string "little while ago.$"

TwinleafTown_PlayerHouse_1F_Text_MomDontKnowWhatItWasAbout:
	.string "I don't know what it was about,\n"
	.string "but he said it was an emergency.$"

TwinleafTown_PlayerHouse_1F_Text_MomPleaseWearThese:
	.string "I don't know if I believe that boy\n"
	.string "when he says emergency, but just\l"
	.string "in case, please wear these.$"

TwinleafTown_PlayerHouse_1F_Text_ReceivedRunningShoes:
	.string "{PLAYER} received a pair of\n"
	.string "Running Shoes!$"

TwinleafTown_PlayerHouse_1F_Text_MomPressBButton:
	.string "Just press the B Button while\n"
	.string "moving and you'll get to {RIVAL}\l"
	.string "in no time.$"

TwinleafTown_PlayerHouse_1F_Text_MomOhYesPlayerName:
	.string "Oh, yes!\n"
	.string "{PLAYER}!$"

TwinleafTown_PlayerHouse_1F_Text_MomDontGoInTallGrass:
	.string "Don't go into the tall grass.\n"
	.string "Wild POKéMON might attack you.\p"
	.string "It would be OK if you had your\n"
	.string "own POKéMON, but you don't…\l"
	.string "So…$"

@ MOM's own interact line. First checks whether the intro house scenes
@ (VAR_TWINLEAF_TOWN_PLAYER_HOUSE_STATE) are still in progress — only
@ state 1 (shoes given, hasn't reached the door yet) has anything to say,
@ since state 0 is never actually reachable here (the shoes scene fires
@ on-frame before the player can act) and state 2 means both intro
@ scenes are done and the REAL story (VAR_TWINLEAF_TOWN_STATE) has
@ taken over. From there: state 12+ (home safe) splits on
@ FLAG_TWINLEAF_TOWN_PLAYER_HOUSE_MOM_MENTIONED_SANDGEM (set for the
@ whole visit right after the homecoming scene, cleared the moment the
@ player steps back outside via TwinleafTown_OnTransition), otherwise
@ she's just wondering where BARRY ran off to.
TwinleafTown_PlayerHouse_1F_EventScript_Mom::
	goto_if_eq VAR_TWINLEAF_TOWN_PLAYER_HOUSE_STATE, 1, TwinleafTown_PlayerHouse_1F_EventScript_MomImpatientRival
	goto_if_lt VAR_TWINLEAF_TOWN_PLAYER_HOUSE_STATE, 2, TwinleafTown_PlayerHouse_1F_EventScript_MomNothingToSayYet
	goto_if_ge VAR_TWINLEAF_TOWN_STATE, 12, TwinleafTown_PlayerHouse_1F_EventScript_MomHomeSafe
	goto TwinleafTown_PlayerHouse_1F_EventScript_MomWhileBarryGone

TwinleafTown_PlayerHouse_1F_EventScript_MomNothingToSayYet::
	end

TwinleafTown_PlayerHouse_1F_EventScript_MomImpatientRival::
	setspeaker SP_NAME_MOM
	msgbox TwinleafTown_PlayerHouse_1F_Text_MomImpatientRival, MSGBOX_NPC
	end

TwinleafTown_PlayerHouse_1F_EventScript_MomWhileBarryGone::
	setspeaker SP_NAME_MOM
	msgbox TwinleafTown_PlayerHouse_1F_Text_MomIsntRivalWaiting, MSGBOX_NPC
	end

TwinleafTown_PlayerHouse_1F_EventScript_MomHomeSafe::
	goto_if_unset FLAG_TWINLEAF_TOWN_PLAYER_HOUSE_MOM_MENTIONED_SANDGEM, TwinleafTown_PlayerHouse_1F_EventScript_MomOffersRest
	bufferleadmonspeciesname STR_VAR_1
	setspeaker SP_NAME_MOM
	msgbox TwinleafTown_PlayerHouse_1F_Text_MomSandgemNotFar, MSGBOX_NPC
	end

@ Repeatable from here on: MOM offers a free full heal, same
@ fade/fanfare/heal beats as a POKéMON CENTER visit, just without the
@ nurse's counter animation since she's just tucking the player in at
@ home.
TwinleafTown_PlayerHouse_1F_EventScript_MomOffersRest::
	lock
	faceplayer
	setspeaker SP_NAME_MOM
	msgbox TwinleafTown_PlayerHouse_1F_Text_MomWelcomeHomeRest, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	playfanfare MUS_HEAL
	waitfanfare
	special HealPlayerParty
	fadescreen FADE_FROM_BLACK
	release
	end

TwinleafTown_PlayerHouse_1F_Text_MomImpatientRival:
	.string "You know how impatient {RIVAL} is.\n"
	.string "He took off before I could even ask\l"
	.string "what it was about.$"

TwinleafTown_PlayerHouse_1F_Text_MomIsntRivalWaiting:
	.string "What is it, dear?\n"
	.string "Isn't {RIVAL} waiting for you?$"

TwinleafTown_PlayerHouse_1F_Text_MomSandgemNotFar:
	.string "Sandgem Town is not far from\n"
	.string "Twinleaf, I'm sure you and\l"
	.string "{STR_VAR_1} can make it there in no\l"
	.string "time.$"

TwinleafTown_PlayerHouse_1F_Text_MomWelcomeHomeRest:
	.string "Welcome home, {PLAYER}.\n"
	.string "Are you and your POKéMON healthy?\p"
	.string "Take a quick rest, dear.$"

TwinleafTown_PlayerHouse_1F_EventScript_NPC1::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_GLAMEOW, CRY_MODE_NORMAL
	setspeaker TwinleafTown_PlayerHouse_1F_Text_NPC1Speaker
	msgbox TwinleafTown_PlayerHouse_1F_Text_NPC1, MSGBOX_DEFAULT
	waitmoncry
	release
	end

TwinleafTown_PlayerHouse_1F_Text_NPC1:
	.string "Glaaam!$"

TwinleafTown_PlayerHouse_1F_Text_NPC1Speaker:
	.string "Glameow$"
