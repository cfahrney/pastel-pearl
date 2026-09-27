TwinleafTown_PlayerHouse_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, TwinleafTown_PlayerHouse_1F_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, TwinleafTown_PlayerHouse_1F_OnFrame
	.byte 0

@ MOM idles at (6,5) normally, and gets relocated to (1,3) here for the
@ homecoming scene when VAR_TWINLEAF_TOWN_STATE == 11.
TwinleafTown_PlayerHouse_1F_OnTransition:
	@ The neighbor only exists during the AfterSandgemTour scene.
	setflag FLAG_HIDE_TWINLEAFPLAYERHOUSE_1F_BARRY_MOM
	call_if_eq VAR_TWINLEAF_TOWN_STATE, 11, TwinleafTown_PlayerHouse_1F_EventScript_PositionMomForHomecoming
	call_if_ge VAR_TWINLEAF_TOWN_STATE, 13, TwinleafTown_PlayerHouse_1F_EventScript_RestoreMomSpot
	end

@ Undo the homecoming relocation (setobjectxyperm is permanent).
TwinleafTown_PlayerHouse_1F_EventScript_RestoreMomSpot:
	setobjectxyperm LOCALID_PLAYER_MOM, 6, 5
	setobjectmovementtype LOCALID_PLAYER_MOM, MOVEMENT_TYPE_FACE_UP
	return

TwinleafTown_PlayerHouse_1F_EventScript_PositionMomForHomecoming:
	setobjectxyperm LOCALID_PLAYER_MOM, 1, 3
	setobjectmovementtype LOCALID_PLAYER_MOM, MOVEMENT_TYPE_FACE_DOWN
	return

TwinleafTown_PlayerHouse_1F_OnFrame:
	map_script_2 VAR_TWINLEAF_TOWN_PLAYER_HOUSE_STATE, 0, TwinleafTown_PlayerHouse_1F_EventScript_MomGivesRunningShoes
	map_script_2 VAR_TWINLEAF_TOWN_STATE, 11, TwinleafTown_PlayerHouse_1F_EventScript_MomHomecoming
	map_script_2 VAR_TWINLEAF_TOWN_STATE, 13, TwinleafTown_PlayerHouse_1F_EventScript_HomeAfterSandgemTour
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

@ VAR_TWINLEAF_TOWN_STATE == 13: the moment the player walks in from the Sandgem tour they
@ walk to MOM at (5,5), MOM heals them, then the scene below runs. Fixed positions on purpose,
@ so nothing depends on which side the player would have talked to MOM from.
TwinleafTown_PlayerHouse_1F_EventScript_HomeAfterSandgemTour::
	lockall
	applymovement LOCALID_PLAYER, TwinleafTown_PlayerHouse_1F_Movement_PlayerWalksToMom
	waitmovement LOCALID_PLAYER
	applymovement LOCALID_PLAYER_MOM, Common_Movement_FaceLeft
	waitmovement LOCALID_PLAYER_MOM
	setspeaker SP_NAME_MOM
	msgbox TwinleafTown_PlayerHouse_1F_Text_MomWelcomeHomeRest, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	playfanfare MUS_HEAL
	waitfanfare
	special HealPlayerParty
	fadescreen FADE_FROM_BLACK
	goto TwinleafTown_PlayerHouse_1F_EventScript_AfterSandgemTour

TwinleafTown_PlayerHouse_1F_Movement_PlayerWalksToMom:
	walk_up
	walk_up
	walk_up
	face_right
	step_end

@ MOM gives the EXP. SHARE, then the neighbor drops by with a parcel for RIVAL.
TwinleafTown_PlayerHouse_1F_EventScript_AfterSandgemTour::
	setspeaker SP_NAME_MOM
	msgbox TwinleafTown_PlayerHouse_1F_Text_TourMomWhatsUp, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_EXP_SHARE
	@ Starts switched on; the player can toggle it from the Bag.
	setflag FLAG_EXP_SHARE_ON
	setspeaker SP_NAME_MOM
	msgbox TwinleafTown_PlayerHouse_1F_Text_TourMomAboutExpShare, MSGBOX_DEFAULT
	closemessage
	@ Spawn the neighbor at the door; her object sits off-map and hidden until now.
	setobjectxyperm LOCALID_TWINLEAFPLAYERHOUSE_1F_BARRY_MOM, 5, 8
	setobjectmovementtype LOCALID_TWINLEAFPLAYERHOUSE_1F_BARRY_MOM, MOVEMENT_TYPE_FACE_UP
	clearflag FLAG_HIDE_TWINLEAFPLAYERHOUSE_1F_BARRY_MOM
	addobject LOCALID_TWINLEAFPLAYERHOUSE_1F_BARRY_MOM
	playse SE_EXIT
	waitse
	playse SE_PIN
	applymovement LOCALID_PLAYER, Common_Movement_FaceDown
	applymovement LOCALID_PLAYER_MOM, TwinleafTown_PlayerHouse_1F_Movement_MomNoticesNeighbor
	waitmovementall
	applymovement LOCALID_TWINLEAFPLAYERHOUSE_1F_BARRY_MOM, TwinleafTown_PlayerHouse_1F_Movement_NeighborWalksIn
	waitmovement LOCALID_TWINLEAFPLAYERHOUSE_1F_BARRY_MOM
	setspeaker SP_NAME_RIVAL_MOM
	msgbox TwinleafTown_PlayerHouse_1F_Text_NeighborExcuseMe, MSGBOX_DEFAULT
	closemessage
	setspeaker SP_NAME_MOM
	msgbox TwinleafTown_PlayerHouse_1F_Text_MomNoHesNot, MSGBOX_DEFAULT
	closemessage
	setspeaker SP_NAME_RIVAL_MOM
	msgbox TwinleafTown_PlayerHouse_1F_Text_NeighborMustHaveLeft, MSGBOX_DEFAULT
	closemessage
	setspeaker SP_NAME_MOM
	msgbox TwinleafTown_PlayerHouse_1F_Text_MomPlayerWillDeliver, MSGBOX_DEFAULT
	closemessage
	@ MOM (6,5) and the player (5,5) look at each other.
	applymovement LOCALID_PLAYER_MOM, Common_Movement_FaceLeft
	applymovement LOCALID_PLAYER, Common_Movement_FaceRight
	waitmovementall
	setspeaker SP_NAME_MOM
	msgbox TwinleafTown_PlayerHouse_1F_Text_MomWontYou, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, Common_Movement_FaceDown
	applymovement LOCALID_TWINLEAFPLAYERHOUSE_1F_BARRY_MOM, TwinleafTown_PlayerHouse_1F_Movement_NeighborReacts
	waitmovementall
	setspeaker SP_NAME_RIVAL_MOM
	msgbox TwinleafTown_PlayerHouse_1F_Text_NeighborReallyForMe, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_PARCEL
	setspeaker SP_NAME_RIVAL_MOM
	msgbox TwinleafTown_PlayerHouse_1F_Text_NeighborLetMeThink, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_TWINLEAFPLAYERHOUSE_1F_BARRY_MOM, TwinleafTown_PlayerHouse_1F_Movement_NeighborLeaves
	waitmovement LOCALID_TWINLEAFPLAYERHOUSE_1F_BARRY_MOM
	playse SE_EXIT
	removeobject LOCALID_TWINLEAFPLAYERHOUSE_1F_BARRY_MOM
	setflag FLAG_HIDE_TWINLEAFPLAYERHOUSE_1F_BARRY_MOM
	setvar VAR_TWINLEAF_TOWN_STATE, 14
	releaseall
	end

TwinleafTown_PlayerHouse_1F_Text_TourMomWhatsUp:
	.string "What's up, {PLAYER}?\p"
	.string "…\p"
	.string "Wow. PROFESSOR ROWAN asked you to\n"
	.string "do something that big.\p"
	.string "OK, dear, go for it!\n"
	.string "Your mom's got your back!\p"
	.string "Oh, I know! {PLAYER}, I've got\n"
	.string "something that you'll find useful.$"

TwinleafTown_PlayerHouse_1F_Text_TourMomAboutExpShare:
	.string "That's an Exp. Share! It will\n"
	.string "allow all the POKéMON on your team\l"
	.string "to receive Exp. Points from\l"
	.string "battles.\p"
	.string "Don't worry, you can toggle it off\n"
	.string "in your Bag if you'd prefer.\p"
	.string "Anywho…\n"
	.string "I'll be all right by myself, so\l"
	.string "you go and enjoy your adventure!\p"
	.string "When you're exposed to new things,\n"
	.string "and experience new sensations… It\l"
	.string "makes your mother happy too.\p"
	.string "… But come back sometimes.\p"
	.string "I would like to see the kinds of\n"
	.string "POKéMON you've caught, dear.$"

TwinleafTown_PlayerHouse_1F_Text_NeighborExcuseMe:
	.string "Excuse me.\n"
	.string "Is my little {RIVAL} here?$"

TwinleafTown_PlayerHouse_1F_Text_MomNoHesNot:
	.string "Oh?\n"
	.string "No, he's not…$"

TwinleafTown_PlayerHouse_1F_Text_NeighborMustHaveLeft:
	.string "Oh…\n"
	.string "Then, he must have left already…\l"
	.string "What to do…\p"
	.string "That boy shouted about going on an\n"
	.string "adventure, then he bolted.\p"
	.string "He's so headstrong and reckless… I\n"
	.string "at least wanted him to take this…$"

TwinleafTown_PlayerHouse_1F_Text_MomPlayerWillDeliver:
	.string "Not to worry, {PLAYER} will deliver\n"
	.string "that to him.$"

TwinleafTown_PlayerHouse_1F_Text_MomWontYou:
	.string "Won't you, {PLAYER}?$"

TwinleafTown_PlayerHouse_1F_Text_NeighborReallyForMe:
	.string "Oh, really? You'd do that for me?\p"
	.string "{PLAYER}, please take this to\n"
	.string "{RIVAL} for me.$"

TwinleafTown_PlayerHouse_1F_Text_NeighborLetMeThink:
	.string "Let me think…\p"
	.string "Knowing my boy, he would probably\n"
	.string "head straight to JUBILIFE CITY…\p"
	.string "OK, please take that to my\n"
	.string "{RIVAL}.$"

TwinleafTown_PlayerHouse_1F_Movement_MomNoticesNeighbor:
	face_down
	emote_exclamation_mark
	step_end

TwinleafTown_PlayerHouse_1F_Movement_NeighborWalksIn:
	walk_up
	walk_up
	face_right
	step_end

TwinleafTown_PlayerHouse_1F_Movement_NeighborReacts:
	face_up
	walk_in_place_up
	step_end

TwinleafTown_PlayerHouse_1F_Movement_NeighborLeaves:
	face_down
	walk_down
	walk_down
	step_end
