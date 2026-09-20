Route204_MapScripts::
	.byte 0

Route204_EventScript_Trainer1::
	trainerbattle_single TRAINER_ROUTE204_1, Route204_Text_Trainer1Intro, Route204_Text_Trainer1Defeated
	msgbox Route204_Text_Trainer1PostBattle, MSGBOX_AUTOCLOSE
	end

Route204_EventScript_Trainer2::
	trainerbattle_single TRAINER_ROUTE204_2, Route204_Text_Trainer2Intro, Route204_Text_Trainer2Defeated
	msgbox Route204_Text_Trainer2PostBattle, MSGBOX_AUTOCLOSE
	end

Route204_Text_Trainer1Intro:
	.string "May I please trouble you for a battle?$"

Route204_Text_Trainer1Defeated:
	.string "Wow, you're so strong...$"

Route204_Text_Trainer1PostBattle:
	.string "Maybe I could have won if my Pokemon\n"
	.string "was holding a Berry...$"

Route204_Text_Trainer2Intro:
	.string "Oh, a weak-looking Trainer... Do you want\n"
	.string "to have a go?$"

Route204_Text_Trainer2Defeated:
	.string "Aw... I should have said no...$"

Route204_Text_Trainer2PostBattle:
	.string "I didn't know you're so tough... I'm going\n"
	.string "to train harder too!$"

Route204_EventScript_Tree1::
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
	setflag FLAG_HIDE_ROUTE204_TREE1
	releaseall
	end

Route204_EventScript_NPC1::
	msgbox Route204_Text_NPC1, MSGBOX_NPC
	end

Route204_EventScript_NPC2::
	msgbox Route204_Text_NPC2, MSGBOX_NPC
	end

Route204_EventScript_NPC3::
	msgbox Route204_Text_NPC3, MSGBOX_NPC
	end

Route204_Text_NPC1:
	.string "My dad gave me some Pokemon! They're\n"
	.string "gonna win for me!$"

Route204_Text_NPC2:
	.string "There are boulders blocking the way\n"
	.string "inside the cavern... I think a Pokemon\l"
	.string "would be able to break those boulders,\l"
	.string "though.$"

Route204_Text_NPC3:
	.string "Are you raising different kinds of\n"
	.string "Pokemon? If you only have the same\l"
	.string "type of Pokemon, you'll have a hard time\l"
	.string "against types it's weak to.$"

Route204_EventScript_Sign1::
	msgbox Route204_Text_Sign1, MSGBOX_SIGN
	end

Route204_EventScript_NPC4::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_BEAUTIFLY, CRY_MODE_NORMAL
	msgbox Route204_Text_NPC4, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route204_EventScript_NPC5::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_DUSTOX, CRY_MODE_NORMAL
	msgbox Route204_Text_NPC5, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route204_EventScript_Trainer3::
	trainerbattle_single TRAINER_ROUTE204_3, Route204_Text_Trainer3Intro, Route204_Text_Trainer3Defeated
	msgbox Route204_Text_Trainer3PostBattle, MSGBOX_AUTOCLOSE
	end

Route204_Text_Sign1:
	.string "ROUTE 204 SIGN 1$"

Route204_Text_NPC4:
	.string "ROUTE 204 NPC 4$"

Route204_Text_NPC5:
	.string "ROUTE 204 NPC 5$"

Route204_Text_Trainer3Intro:
	.string "ROUTE 204 TRAINER 3\nwants to battle!$"

Route204_Text_Trainer3Defeated:
	.string "ROUTE 204 TRAINER 3\nwas defeated!$"

Route204_Text_Trainer3PostBattle:
	.string "ROUTE 204 TRAINER 3\nhas nothing else to say.$"
