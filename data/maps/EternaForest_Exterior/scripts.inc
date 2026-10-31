EternaForest_Exterior_MapScripts::
	.byte 0

EternaForest_Exterior_EventScript_Tree1::
	lockall
	checkfieldmove FIELD_MOVE_CUT, TRUE
	goto_if_eq VAR_RESULT, PARTY_SIZE, EventScript_CheckTreeCantCut
	setfieldeffectargument 0, VAR_RESULT
	bufferpartymonnick STR_VAR_1, VAR_RESULT
	buffermovename STR_VAR_2, MOVE_CUT
	msgbox Text_WantToCut, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_CancelCut
	msgbox Text_MonUsedFieldMove, MSGBOX_DEFAULT
	closemessage
	isfollowerfieldmoveuser VAR_0x8004
	setfieldeffectargument 3, VAR_0x8004
	dofieldeffect FLDEFF_USE_CUT_ON_TREE
	waitstate
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	call_if_eq VAR_0x8004, TRUE, EventScript_FollowerFieldMove
	applymovement VAR_LAST_TALKED, Movement_CutTreeDown
	waitmovement 0
	removeobject VAR_LAST_TALKED
	setflag FLAG_HIDE_ETERNA_FOREST_EXTERIOR_TREE1
	releaseall
	end

EternaForest_Exterior_EventScript_Tree2::
	lockall
	checkfieldmove FIELD_MOVE_CUT, TRUE
	goto_if_eq VAR_RESULT, PARTY_SIZE, EventScript_CheckTreeCantCut
	setfieldeffectargument 0, VAR_RESULT
	bufferpartymonnick STR_VAR_1, VAR_RESULT
	buffermovename STR_VAR_2, MOVE_CUT
	msgbox Text_WantToCut, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_CancelCut
	msgbox Text_MonUsedFieldMove, MSGBOX_DEFAULT
	closemessage
	isfollowerfieldmoveuser VAR_0x8004
	setfieldeffectargument 3, VAR_0x8004
	dofieldeffect FLDEFF_USE_CUT_ON_TREE
	waitstate
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	call_if_eq VAR_0x8004, TRUE, EventScript_FollowerFieldMove
	applymovement VAR_LAST_TALKED, Movement_CutTreeDown
	waitmovement 0
	removeobject VAR_LAST_TALKED
	setflag FLAG_HIDE_ETERNA_FOREST_EXTERIOR_TREE2
	releaseall
	end

EternaForest_Exterior_EventScript_Trainer1::
	trainerbattle_single TRAINER_ETERNA_FOREST_EXTERIOR_1, EternaForest_Exterior_Text_Trainer1Intro, EternaForest_Exterior_Text_Trainer1Defeated
	msgbox EternaForest_Exterior_Text_Trainer1PostBattle, MSGBOX_AUTOCLOSE
	end

EternaForest_Exterior_Text_Trainer1Intro:
	.string "EXTERIOR TRAINER 1$"

EternaForest_Exterior_Text_Trainer1Defeated:
	.string "EXTERIOR TRAINER 1$"

EternaForest_Exterior_Text_Trainer1PostBattle:
	.string "EXTERIOR TRAINER 1$"

EternaForest_Exterior_EventScript_Trainer2::
	trainerbattle_single TRAINER_ETERNA_FOREST_EXTERIOR_2, EternaForest_Exterior_Text_Trainer2Intro, EternaForest_Exterior_Text_Trainer2Defeated
	msgbox EternaForest_Exterior_Text_Trainer2PostBattle, MSGBOX_AUTOCLOSE
	end

EternaForest_Exterior_Text_Trainer2Intro:
	.string "EXTERIOR TRAINER 2$"

EternaForest_Exterior_Text_Trainer2Defeated:
	.string "EXTERIOR TRAINER 2$"

EternaForest_Exterior_Text_Trainer2PostBattle:
	.string "EXTERIOR TRAINER 2$"

EternaForest_Exterior_EventScript_NPC1::
	msgbox EternaForest_Exterior_Text_NPC1, MSGBOX_NPC
	end

EternaForest_Exterior_Text_NPC1:
	.string "EXTERIOR NPC 1$"
