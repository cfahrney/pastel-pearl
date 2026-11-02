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

EternaForest_Exterior_EventScript_NPC1::
	lock
	faceplayer
	goto_if_set FLAG_ETERNA_FOREST_EXTERIOR_WOMAN_1, EternaForest_Exterior_EventScript_NPC1_2
	setvar VAR_0x8004, 95
	@ TODO(DP): GetFashionName 0, 32772
	msgbox EternaForest_Exterior_Text_NPC1, MSGBOX_DEFAULT
	setvar VAR_0x8005, 1
	@ TODO(DP): Common DP script 2015
	setflag FLAG_ETERNA_FOREST_EXTERIOR_WOMAN_1
	closemessage
	release
	end

EternaForest_Exterior_EventScript_NPC1_2::
	msgbox EternaForest_Exterior_Text_NPC1_2, MSGBOX_DEFAULT
	closemessage
	release
	end

EternaForest_Exterior_Text_NPC1:
	.string "Oh, are you collecting Accessories?\n"
	.string "I've got something for you.$"

EternaForest_Exterior_Text_NPC1_2:
	.string "I collect Berries and trade them for\n"
	.string "Accessories in {COLOR DYNAMIC_COLOR3}Floaroma Town{COLOR DARK_GRAY}.\p"
	.string "I sometimes worry for days on end about\n"
	.string "what Accessories I should be putting\l"
	.string "on my Pokémon.$"
