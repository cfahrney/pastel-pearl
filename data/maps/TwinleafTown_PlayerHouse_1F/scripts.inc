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
	msgbox TwinleafTown_PlayerHouse_1F_Text_MomWhatsUpDear, MSGBOX_DEFAULT
	closemessage
	msgbox TwinleafTown_PlayerHouse_1F_Text_MomEllipsis, MSGBOX_DEFAULT
	closemessage
	msgbox TwinleafTown_PlayerHouse_1F_Text_MomWow, MSGBOX_DEFAULT
	closemessage
	msgbox TwinleafTown_PlayerHouse_1F_Text_MomGladUnharmed, MSGBOX_DEFAULT
	closemessage
	msgbox TwinleafTown_PlayerHouse_1F_Text_MomProfessorRowan, MSGBOX_DEFAULT
	closemessage
	msgbox TwinleafTown_PlayerHouse_1F_Text_MomHeardOfHim, MSGBOX_DEFAULT
	closemessage
	msgbox TwinleafTown_PlayerHouse_1F_Text_MomVisitSandgem, MSGBOX_DEFAULT
	closemessage
	msgbox TwinleafTown_PlayerHouse_1F_Text_MomDontWorry, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TWINLEAF_TOWN_STATE, 12
	releaseall
	end


TwinleafTown_PlayerHouse_1F_Movement_MomCooks:
	delay_16
	walk_left
	face_up
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
