CanalaveCity_Library_3F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CanalaveCity_Library_3F_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CanalaveCity_Library_3F_OnFrame
	.byte 0

CanalaveCity_Library_3F_EventScript_NPC1::
	lock
	faceplayer
	goto_if_set FLAG_CANALAVE_CITY_FAT_MAN_1, CanalaveCity_Library_3F_EventScript_NPC1_2
	msgbox CanalaveCity_Library_3F_Text_NPC1_2, MSGBOX_DEFAULT
	closemessage
	release
	end

CanalaveCity_Library_3F_EventScript_NPC1_2::
	msgbox CanalaveCity_Library_3F_Text_NPC1_3, MSGBOX_DEFAULT
	closemessage
	release
	end

CanalaveCity_Library_3F_EventScript_NPC2::
	lock
	faceplayer
	goto_if_set FLAG_CANALAVE_CITY_FAT_MAN_1, CanalaveCity_Library_3F_EventScript_NPC2_2
	msgbox CanalaveCity_Library_3F_Text_NPC2_2, MSGBOX_DEFAULT
	closemessage
	release
	end

CanalaveCity_Library_3F_EventScript_NPC2_2::
	msgbox CanalaveCity_Library_3F_Text_NPC2_3, MSGBOX_DEFAULT
	closemessage
	release
	end

CanalaveCity_Library_3F_EventScript_Sign1::
	lockall
	msgbox CanalaveCity_Library_3F_Text_Sign1_2, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, CanalaveCity_Library_3F_EventScript_Sign1_2
	goto_if_eq VAR_RESULT, NO, CanalaveCity_Library_3F_EventScript_Sign1_2_2
	end

CanalaveCity_Library_3F_EventScript_Sign1_2::
	msgbox CanalaveCity_Library_3F_Text_Sign1_3, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

CanalaveCity_Library_3F_EventScript_Sign1_2_2::
	msgbox CanalaveCity_Library_3F_Text_Sign1_4, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

CanalaveCity_Library_3F_EventScript_Sign2::
	goto CanalaveCity_Library_3F_EventScript_Sign1
	end

CanalaveCity_Library_3F_EventScript_Sign3::
	lockall
	msgbox CanalaveCity_Library_3F_Text_Sign3, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, CanalaveCity_Library_3F_EventScript_Sign3_2
	goto_if_eq VAR_RESULT, NO, CanalaveCity_Library_3F_EventScript_Sign3_2_2
	end

CanalaveCity_Library_3F_EventScript_Sign3_2::
	msgbox CanalaveCity_Library_3F_Text_Sign3_2, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

CanalaveCity_Library_3F_EventScript_Sign3_2_2::
	msgbox CanalaveCity_Library_3F_Text_Sign3_3, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

CanalaveCity_Library_3F_EventScript_Sign4::
	goto CanalaveCity_Library_3F_EventScript_Sign3
	end

CanalaveCity_Library_3F_EventScript_Sign5::
	lockall
	msgbox CanalaveCity_Library_3F_Text_Sign5, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, CanalaveCity_Library_3F_EventScript_Sign5_2
	goto_if_eq VAR_RESULT, NO, CanalaveCity_Library_3F_EventScript_Sign5_2_2
	end

CanalaveCity_Library_3F_EventScript_Sign5_2::
	msgbox CanalaveCity_Library_3F_Text_Sign5_2, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

CanalaveCity_Library_3F_EventScript_Sign5_2_2::
	msgbox CanalaveCity_Library_3F_Text_Sign5_3, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

CanalaveCity_Library_3F_EventScript_Sign6::
	goto CanalaveCity_Library_3F_EventScript_Sign5
	end

CanalaveCity_Library_3F_EventScript_Sign7::
	lockall
	msgbox CanalaveCity_Library_3F_Text_Sign7, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, CanalaveCity_Library_3F_EventScript_Sign7_2
	goto_if_eq VAR_RESULT, NO, CanalaveCity_Library_3F_EventScript_Sign7_2_2
	end

CanalaveCity_Library_3F_EventScript_Sign7_2::
	msgbox CanalaveCity_Library_3F_Text_Sign7_2, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, CanalaveCity_Library_3F_EventScript_Sign7_2_2
	msgbox CanalaveCity_Library_3F_Text_Sign7_3, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, CanalaveCity_Library_3F_EventScript_Sign7_2_2
	msgbox CanalaveCity_Library_3F_Text_Sign7_4, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

CanalaveCity_Library_3F_EventScript_Sign7_2_2::
	msgbox CanalaveCity_Library_3F_Text_Sign7_5, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

CanalaveCity_Library_3F_EventScript_Sign8::
	goto CanalaveCity_Library_3F_EventScript_Sign7
	end

CanalaveCity_Library_3F_EventScript_Sign9::
	lockall
	msgbox CanalaveCity_Library_3F_Text_Sign9, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, CanalaveCity_Library_3F_EventScript_Sign9_2
	goto_if_eq VAR_RESULT, NO, CanalaveCity_Library_3F_EventScript_Sign9_2_2
	end

CanalaveCity_Library_3F_EventScript_Sign9_2::
	msgbox CanalaveCity_Library_3F_Text_Sign9_2, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, CanalaveCity_Library_3F_EventScript_Sign9_2_2
	msgbox CanalaveCity_Library_3F_Text_Sign9_3, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, CanalaveCity_Library_3F_EventScript_Sign9_2_2
	msgbox CanalaveCity_Library_3F_Text_Sign9_4, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

CanalaveCity_Library_3F_EventScript_Sign9_2_2::
	msgbox CanalaveCity_Library_3F_Text_Sign9_5, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

CanalaveCity_Library_3F_EventScript_Sign10::
	goto CanalaveCity_Library_3F_EventScript_Sign9
	end

CanalaveCity_Library_3F_EventScript_Sign11::
	lockall
	msgbox CanalaveCity_Library_3F_Text_Sign11, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, CanalaveCity_Library_3F_EventScript_Sign11_2
	goto_if_eq VAR_RESULT, NO, CanalaveCity_Library_3F_EventScript_Sign11_2_2
	end

CanalaveCity_Library_3F_EventScript_Sign11_2::
	msgbox CanalaveCity_Library_3F_Text_Sign11_2, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

CanalaveCity_Library_3F_EventScript_Sign11_2_2::
	msgbox CanalaveCity_Library_3F_Text_Sign11_3, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

CanalaveCity_Library_3F_EventScript_Sign12::
	goto CanalaveCity_Library_3F_EventScript_Sign11
	end

CanalaveCity_Library_3F_EventScript_Sign13::
	lockall
	msgbox CanalaveCity_Library_3F_Text_Sign13, MSGBOX_DEFAULT
	message CanalaveCity_Library_3F_Text_Sign13_2
	waitmessage
	@ TODO(DP): Multi 1, 1, 0, 1, 32780
	@ TODO(DP): ChoiceMulti 259, 0
	@ TODO(DP): ChoiceMulti 260, 1
	@ TODO(DP): ChoiceMulti 261, 2
	@ TODO(DP): ChoiceMulti 262, 3
	@ TODO(DP): CloseMulti
	goto_if_eq VAR_RESULT, 0, CanalaveCity_Library_3F_EventScript_Sign13_2
	goto_if_eq VAR_RESULT, 1, CanalaveCity_Library_3F_EventScript_Sign13_2_2
	goto_if_eq VAR_RESULT, 2, CanalaveCity_Library_3F_EventScript_Sign13_2_3
	goto CanalaveCity_Library_3F_EventScript_Sign13_2_4

CanalaveCity_Library_3F_EventScript_Sign13_2::
	msgbox CanalaveCity_Library_3F_Text_Sign13_3, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

CanalaveCity_Library_3F_EventScript_Sign13_2_2::
	msgbox CanalaveCity_Library_3F_Text_Sign13_4, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

CanalaveCity_Library_3F_EventScript_Sign13_2_3::
	msgbox CanalaveCity_Library_3F_Text_Sign13_5, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

CanalaveCity_Library_3F_EventScript_Sign13_2_4::
	msgbox CanalaveCity_Library_3F_Text_Sign13_6, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

CanalaveCity_Library_3F_EventScript_Sign14::
	goto CanalaveCity_Library_3F_EventScript_Sign13
	end

CanalaveCity_Library_3F_EventScript_Sign15::
	lockall
	msgbox CanalaveCity_Library_3F_Text_Sign15, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

CanalaveCity_Library_3F_EventScript_Sign16::
	goto CanalaveCity_Library_3F_EventScript_Sign9
	end

CanalaveCity_Library_3F_EventScript_Sign17::
	goto CanalaveCity_Library_3F_EventScript_Sign9
	end

CanalaveCity_Library_3F_EventScript_Sign18::
	goto CanalaveCity_Library_3F_EventScript_Sign9
	end

CanalaveCity_Library_3F_EventScript_Sign19::
	goto CanalaveCity_Library_3F_EventScript_Sign11
	end

CanalaveCity_Library_3F_EventScript_Sign20::
	goto CanalaveCity_Library_3F_EventScript_Sign11
	end

CanalaveCity_Library_3F_EventScript_Sign21::
	goto CanalaveCity_Library_3F_EventScript_Sign13
	end

CanalaveCity_Library_3F_EventScript_Sign22::
	goto CanalaveCity_Library_3F_EventScript_Sign13
	end

CanalaveCity_Library_3F_OnTransition::
	call Common_EventScript_SetupLucasDawnAssistantGfxId
	checkplayergender
	copyvar VAR_TEMP_0, VAR_RESULT
	goto_if_eq VAR_TEMP_0, 0, CanalaveCity_Library_3F_OnTransition_2
	goto_if_eq VAR_TEMP_0, 1, CanalaveCity_Library_3F_OnTransition_2_2
	end

CanalaveCity_Library_3F_OnTransition_2::
	setvar VAR_CANALAVE_CITY_STATE_4, 97
	end

CanalaveCity_Library_3F_OnTransition_2_2::
	setvar VAR_CANALAVE_CITY_STATE_4, 0
	end

CanalaveCity_Library_3F_EventScript_OnFrame::
	lockall
	setspeaker SP_NAME_RIVAL
	msgbox CanalaveCity_Library_3F_Text_OnFrame, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CANALAVE_CITY_LIBRARY_3_F_BARRY, CanalaveCity_Library_3F_Movement_Barry
	applymovement LOCALID_PLAYER, CanalaveCity_Library_3F_Movement_Player
	waitmovement 0
	getplayerxy VAR_0x8004, VAR_0x8005
	@ TODO(DP): LockCamera 32772, 32773
	@ TODO(DP): Move the camera
	waitmovement 0
	delay 60
	setspeaker SP_NAME_RIVAL
	msgbox CanalaveCity_Library_3F_Text_OnFrame_2, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CANALAVE_CITY_LIBRARY_3_F_BARRY, CanalaveCity_Library_3F_Movement_Barry2
	waitmovement 0
	setspeaker SP_NAME_ROWAN
	msgbox CanalaveCity_Library_3F_Text_OnFrame_3, MSGBOX_DEFAULT
	setspeaker SP_NAME_RIVAL
	msgbox CanalaveCity_Library_3F_Text_OnFrame_4, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CANALAVE_CITY_LIBRARY_3_F_BARRY, CanalaveCity_Library_3F_Movement_Barry3
	waitmovement 0
	delay 20
	setspeaker SP_NAME_ROWAN
	msgbox CanalaveCity_Library_3F_Text_OnFrame_5, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CANALAVE_CITY_LIBRARY_3_F_PROF_ROWAN, CanalaveCity_Library_3F_Movement_ProfRowan
	waitmovement 0
	msgbox CanalaveCity_Library_3F_Text_OnFrame_6, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CANALAVE_CITY_LIBRARY_3_F_PROF_ROWAN, CanalaveCity_Library_3F_Movement_ProfRowan2
	waitmovement 0
	msgbox CanalaveCity_Library_3F_Text_OnFrame_7, MSGBOX_DEFAULT
	setspeaker SP_NAME_RIVAL
	msgbox CanalaveCity_Library_3F_Text_OnFrame_8, MSGBOX_DEFAULT
	setspeaker SP_NAME_ROWAN
	msgbox CanalaveCity_Library_3F_Text_OnFrame_9, MSGBOX_DEFAULT
	checkplayergender
	goto_if_eq VAR_RESULT, 0, CanalaveCity_Library_3F_EventScript_OnFrame_2
	goto CanalaveCity_Library_3F_EventScript_OnFrame_2_2

CanalaveCity_Library_3F_EventScript_OnFrame_2::
	setspeaker SP_NAME_ASSISTANT
	msgbox CanalaveCity_Library_3F_Text_OnFrame_10, MSGBOX_DEFAULT
	goto CanalaveCity_Library_3F_EventScript_OnFrame_2_3

CanalaveCity_Library_3F_EventScript_OnFrame_2_2::
	setspeaker SP_NAME_ASSISTANT
	msgbox CanalaveCity_Library_3F_Text_OnFrame_11, MSGBOX_DEFAULT
	goto CanalaveCity_Library_3F_EventScript_OnFrame_2_3

CanalaveCity_Library_3F_EventScript_OnFrame_2_3::
	setspeaker SP_NAME_ROWAN
	msgbox CanalaveCity_Library_3F_Text_OnFrame_12, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CANALAVE_CITY_LIBRARY_3_F_PROF_ROWAN, CanalaveCity_Library_3F_Movement_ProfRowan3
	applymovement LOCALID_CANALAVE_CITY_LIBRARY_3_F_NPC, CanalaveCity_Library_3F_Movement_Npc
	waitmovement 0
	checkplayergender
	goto_if_eq VAR_RESULT, 0, CanalaveCity_Library_3F_EventScript_OnFrame_2_4
	goto CanalaveCity_Library_3F_EventScript_OnFrame_2_5

CanalaveCity_Library_3F_EventScript_OnFrame_2_4::
	setspeaker SP_NAME_ROWAN
	msgbox CanalaveCity_Library_3F_Text_OnFrame_13, MSGBOX_DEFAULT
	setspeaker SP_NAME_ASSISTANT
	msgbox CanalaveCity_Library_3F_Text_OnFrame_14, MSGBOX_DEFAULT
	goto CanalaveCity_Library_3F_EventScript_OnFrame_2_6

CanalaveCity_Library_3F_EventScript_OnFrame_2_5::
	setspeaker SP_NAME_ROWAN
	msgbox CanalaveCity_Library_3F_Text_OnFrame_15, MSGBOX_DEFAULT
	setspeaker SP_NAME_ASSISTANT
	msgbox CanalaveCity_Library_3F_Text_OnFrame_16, MSGBOX_DEFAULT
	goto CanalaveCity_Library_3F_EventScript_OnFrame_2_6

CanalaveCity_Library_3F_EventScript_OnFrame_2_6::
	closemessage
	applymovement LOCALID_CANALAVE_CITY_LIBRARY_3_F_PROF_ROWAN, CanalaveCity_Library_3F_Movement_ProfRowan4
	applymovement LOCALID_CANALAVE_CITY_LIBRARY_3_F_NPC, CanalaveCity_Library_3F_Movement_Npc2
	waitmovement 0
	setspeaker SP_NAME_ROWAN
	msgbox CanalaveCity_Library_3F_Text_OnFrame_17, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CANALAVE_CITY_LIBRARY_3_F_BARRY, CanalaveCity_Library_3F_Movement_Barry4
	waitmovement 0
	setspeaker SP_NAME_RIVAL
	msgbox CanalaveCity_Library_3F_Text_OnFrame_18, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CANALAVE_CITY_LIBRARY_3_F_BARRY, CanalaveCity_Library_3F_Movement_Barry5
	waitmovement 0
	setspeaker SP_NAME_ROWAN
	msgbox CanalaveCity_Library_3F_Text_OnFrame_19, MSGBOX_DEFAULT
	closemessage
	waitse
	@ TODO(DP): ShakeCamera 1
	setspeaker SP_NAME_ROWAN
	msgbox CanalaveCity_Library_3F_Text_OnFrame_20, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CANALAVE_CITY_LIBRARY_3_F_NPC, CanalaveCity_Library_3F_Movement_Npc3
	applymovement LOCALID_CANALAVE_CITY_LIBRARY_3_F_BARRY, CanalaveCity_Library_3F_Movement_Barry6
	applymovement LOCALID_CANALAVE_CITY_LIBRARY_3_F_PROF_ROWAN, CanalaveCity_Library_3F_Movement_ProfRowan5
	@ TODO(DP): Move the camera
	waitmovement 0
	removeobject LOCALID_CANALAVE_CITY_LIBRARY_3_F_BARRY
	removeobject LOCALID_CANALAVE_CITY_LIBRARY_3_F_NPC
	@ TODO(DP): ReleaseCamera
	applymovement LOCALID_PLAYER, CanalaveCity_Library_3F_Movement_Player2
	waitmovement 0
	setspeaker SP_NAME_ROWAN
	msgbox CanalaveCity_Library_3F_Text_OnFrame_21, MSGBOX_DEFAULT
	closemessage
	@ TODO(DP): StopFanfare 1500
	applymovement LOCALID_CANALAVE_CITY_LIBRARY_3_F_PROF_ROWAN, CanalaveCity_Library_3F_Movement_ProfRowan6
	waitmovement 0
	playse SE_EXIT
	removeobject LOCALID_CANALAVE_CITY_LIBRARY_3_F_PROF_ROWAN
	@ TODO(DP): StopFanfare 1539
	setvar VAR_CANALAVE_CITY_STATE_2, 4
	setvar VAR_CANALAVE_CITY_STATE_5, 2
	setflag FLAG_CANALAVE_CITY_FAT_MAN_1
	setflag FLAG_CANALAVE_CITY_LIBRARY_3F_EVENT_1
	clearflag FLAG_HIDE_CANALAVE_CITY_PROF_ROWAN
	clearflag FLAG_HIDE_CANALAVE_CITY_NPC
	clearflag FLAG_HIDE_CANALAVE_CITY_BARRY
	releaseall
	end

CanalaveCity_Library_3F_OnFrame:
	map_script_2 VAR_CANALAVE_CITY_STATE_5, 1, CanalaveCity_Library_3F_EventScript_OnFrame
	.2byte 0

CanalaveCity_Library_3F_Movement_Barry:
	walk_down
	walk_right
	walk_right
	walk_in_place_up
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	step_end

CanalaveCity_Library_3F_Movement_Player:
	delay_16
	delay_16
	delay_16
	walk_in_place_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	step_end

CanalaveCity_Library_3F_Movement_Barry2:
	walk_fast_up
	walk_fast_up
	walk_in_place_down
	step_end

CanalaveCity_Library_3F_Movement_Barry3:
	walk_down
	walk_down
	step_end

CanalaveCity_Library_3F_Movement_ProfRowan:
	walk_slow_right
	walk_in_place_down
	step_end

CanalaveCity_Library_3F_Movement_ProfRowan2:
	walk_left
	walk_in_place_up
	step_end

CanalaveCity_Library_3F_Movement_ProfRowan3:
	walk_in_place_left
	step_end

CanalaveCity_Library_3F_Movement_Npc:
	walk_in_place_right
	step_end

CanalaveCity_Library_3F_Movement_ProfRowan4:
	walk_in_place_up
	step_end

CanalaveCity_Library_3F_Movement_Npc2:
	walk_in_place_up
	step_end

CanalaveCity_Library_3F_Movement_Barry4:
	walk_in_place_fast_right
	step_end

CanalaveCity_Library_3F_Movement_Barry5:
	walk_in_place_down
	step_end

CanalaveCity_Library_3F_Movement_Npc3:
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_up
	walk_up
	walk_in_place_right
	set_invisible
	step_end

CanalaveCity_Library_3F_Movement_Barry6:
	walk_fast_up
	walk_fast_up
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_in_place_fast_right
	set_invisible
	step_end

CanalaveCity_Library_3F_Movement_ProfRowan5:
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_in_place_down
	step_end

CanalaveCity_Library_3F_Movement_Player2:
	walk_in_place_up
	step_end

CanalaveCity_Library_3F_Movement_ProfRowan6:
	walk_in_place_right
	step_end

CanalaveCity_Library_3F_Text_NPC1_2:
	.string "Every book contains someone's memories\n"
	.string "of various places and times.\p"
	.string "Libraries aren't just buildings where\n"
	.string "books are kept, you know.\p"
	.string "They're where different places and\n"
	.string "times are gathered together.$"

CanalaveCity_Library_3F_Text_NPC1_3:
	.string "W-was that an earthquake? I didn't\n"
	.string "imagine it?$"

CanalaveCity_Library_3F_Text_NPC2_2:
	.string "Someone's always checked out the book\n"
	.string "I want to read...$"

CanalaveCity_Library_3F_Text_NPC2_3:
	.string "I'm feeling wobbly...\p"
	.string "Even though the tremor has ended, my\n"
	.string "knees still feel like jelly...$"

CanalaveCity_Library_3F_Text_Sign1_2:
	.string "This book is titled “{COLOR DYNAMIC_COLOR3}Sinnoh{COLOR DARK_GRAY} Myth.” Want\n"
	.string "to read it?$"

CanalaveCity_Library_3F_Text_Sign1_3:
	.string "“{COLOR DYNAMIC_COLOR3}Sinnoh{COLOR DARK_GRAY} Myth” Betray not your anger,\n"
	.string "lest ??? will come.\p"
	.string "Weep not with sorrow, or ??? will draw\n"
	.string "near.\p"
	.string "When joy and enjoyment come natural as\n"
	.string "the very air, that is happiness.\p"
	.string "Let such be blessed by the hand of\n"
	.string "Master ???.\p"
	.string "Those words were spoken often as\n"
	.string "customary.$"

CanalaveCity_Library_3F_Text_Sign1_4:
	.string "{PLAYER} put the book back.$"

CanalaveCity_Library_3F_Text_Sign3:
	.string "This book is titled “{COLOR DYNAMIC_COLOR3}Sinnoh{COLOR DARK_GRAY} Region's\n"
	.string "Mythology.” Want to read it?$"

CanalaveCity_Library_3F_Text_Sign3_2:
	.string "“{COLOR DYNAMIC_COLOR3}Sinnoh{COLOR DARK_GRAY} Region's Mythology” Long ago,\n"
	.string "when {COLOR DYNAMIC_COLOR3}Sinnoh{COLOR DARK_GRAY} had just been made,\l"
	.string "Pokémon and humans led separate lives.\p"
	.string "That is not to say they did not help\n"
	.string "each other. No, indeed they did.\p"
	.string "They supplied each other with goods,\n"
	.string "and supported each other.\p"
	.string "A Pokémon proposed to the others to\n"
	.string "always be ready to help humans.\p"
	.string "It asked that Pokémon be ready to\n"
	.string "appear before humans always.\p"
	.string "Thus, to this day, Pokémon appear to us\n"
	.string "if we venture into tall grass.$"

CanalaveCity_Library_3F_Text_Sign3_3:
	.string "{PLAYER} put the book back.$"

CanalaveCity_Library_3F_Text_Sign5:
	.string "This book is titled “{COLOR DYNAMIC_COLOR3}Sinnoh{COLOR DARK_GRAY}'s Myth.”\n"
	.string "Want to read it?$"

CanalaveCity_Library_3F_Text_Sign5_2:
	.string "“{COLOR DYNAMIC_COLOR3}Sinnoh{COLOR DARK_GRAY}'s Myth” Three Pokémon there\n"
	.string "were.\p"
	.string "Into the lakes they dove. Deep, deep,\n"
	.string "drawing no breath.\p"
	.string "Deeper, deeper they dove. Into\n"
	.string "suffocating depths they dove.\p"
	.string "Deeper, then deepest they alight. From\n"
	.string "the lake floor they rise.\p"
	.string "Bearing with them the power to make\n"
	.string "vast lands, they rise again.$"

CanalaveCity_Library_3F_Text_Sign5_3:
	.string "{PLAYER} put the book back.$"

CanalaveCity_Library_3F_Text_Sign7:
	.string "This book is titled “Veilstone's Myth.”\n"
	.string "Want to read it?$"

CanalaveCity_Library_3F_Text_Sign7_2:
	.string "“Veilstone's Myth” A young man, callow\n"
	.string "and foolish in innocence, came to own a\l"
	.string "sword.\p"
	.string "With it, he smote Pokémon, which gave\n"
	.string "sustenance, with carefree abandon.\p"
	.string "Those not taken as food, he discarded,\n"
	.string "with no afterthought.\p"
	.string "The following year, no Pokémon\n"
	.string "appeared. Larders grew bare.\p"
	.string "...Would you like to keep reading?$"

CanalaveCity_Library_3F_Text_Sign7_3:
	.string "The young man, seeking the missing\n"
	.string "Pokémon, journeyed afar.\p"
	.string "Long did he search. And far and wide,\n"
	.string "too, until one he did find.\p"
	.string "Asked he, “Why do you hide?” To which\n"
	.string "the Pokémon replied...\p"
	.string "“If you bear your sword to bring harm\n"
	.string "upon us, with claws and fangs, we will\l"
	.string "exact a toll.\p"
	.string "“From your kind we will take our toll,\n"
	.string "for it must be done.\p"
	.string "“Done it must be to guard ourselves and\n"
	.string "for it, I apologize.” ...Would you like to\l"
	.string "keep reading?$"

CanalaveCity_Library_3F_Text_Sign7_4:
	.string "To the skies, the young man shouted his\n"
	.string "dismay.\p"
	.string "“In having found the sword, I have lost\n"
	.string "so much.\p"
	.string "“Gorged with power, I grew blind to\n"
	.string "Pokémon being alive.\p"
	.string "“I will never fall savage again. This\n"
	.string "sword I denounce and forsake.\p"
	.string "“I plead for forgiveness, for I was but\n"
	.string "a fool.” So saying, the young man hurled\l"
	.string "the sword to the ground, snapping it.\p"
	.string "Seeing this, the Pokémon disappeared\n"
	.string "to a place beyond seeing...$"

CanalaveCity_Library_3F_Text_Sign7_5:
	.string "{PLAYER} put the book back.$"

CanalaveCity_Library_3F_Text_Sign9:
	.string "This ancient book is titled “The\n"
	.string "Original Story.” Want to read it?$"

CanalaveCity_Library_3F_Text_Sign9_2:
	.string "In the beginning, there was only a\n"
	.string "churning turmoil of chaos.\p"
	.string "At the heart of chaos, where all things\n"
	.string "became one, appeared an Egg.\p"
	.string "Having tumbled from the vortex, the Egg\n"
	.string "gave rise to the Original One.\p"
	.string "...Would you like to keep reading?$"

CanalaveCity_Library_3F_Text_Sign9_3:
	.string "From itself, two beings the Original One\n"
	.string "did make.\p"
	.string "Time started to spin. Space began to\n"
	.string "expand.\p"
	.string "From itself again, three living things\n"
	.string "the Original One did make.\p"
	.string "...Would you like to keep reading?$"

CanalaveCity_Library_3F_Text_Sign9_4:
	.string "The two beings wished, and from them,\n"
	.string "matter came to be.\p"
	.string "The three living things wished, and from\n"
	.string "them, spirit came to be.\p"
	.string "The world created, the Original One took\n"
	.string "to unyielding sleep...$"

CanalaveCity_Library_3F_Text_Sign9_5:
	.string "{PLAYER} put the book back.$"

CanalaveCity_Library_3F_Text_Sign11:
	.string "This book is titled “A Horrific Myth.”\n"
	.string "Want to read it?$"

CanalaveCity_Library_3F_Text_Sign11_2:
	.string "Look not into the Pokémon's eyes.\p"
	.string "In but an instant, you'll have no\n"
	.string "recollection of who you are.\p"
	.string "Return home, but how? When there is\n"
	.string "nothing to remember?\p"
	.string "Dare not touch the Pokémon's body.\p"
	.string "In but three short days, all emotions\n"
	.string "will drain away.\p"
	.string "Above all, above all, harm not the\n"
	.string "Pokémon.\p"
	.string "In a scant five days, the offender will\n"
	.string "grow immobile in entirety.$"

CanalaveCity_Library_3F_Text_Sign11_3:
	.string "{PLAYER} put the book back.$"

CanalaveCity_Library_3F_Text_Sign13:
	.string "This book is titled “{COLOR DYNAMIC_COLOR3}Sinnoh{COLOR DARK_GRAY} Folk\n"
	.string "Stories.”$"

CanalaveCity_Library_3F_Text_Sign13_2:
	.string "Which story would you like to read?$"

CanalaveCity_Library_3F_Text_Sign13_3:
	.string "“{COLOR DYNAMIC_COLOR3}Sinnoh{COLOR DARK_GRAY} Folk Story 1” Pick clean the\n"
	.string "bones of Pokémon caught in the sea or\l"
	.string "stream.\p"
	.string "Thank them for the meals they provide,\n"
	.string "and pick their bones clean.\p"
	.string "When the bones are as clean as can be,\n"
	.string "set them free in the water from which\l"
	.string "they came.\p"
	.string "The Pokémon will return, fully fleshed,\n"
	.string "and it begins anew.$"

CanalaveCity_Library_3F_Text_Sign13_4:
	.string "“{COLOR DYNAMIC_COLOR3}Sinnoh{COLOR DARK_GRAY} Folk Story 2” There lived a\n"
	.string "Pokémon in a forest.\p"
	.string "In the forest, the Pokémon shed its\n"
	.string "hide to sleep as a human.\p"
	.string "Awakened, the human dons the Pokémon\n"
	.string "hide to roam villages.$"

CanalaveCity_Library_3F_Text_Sign13_5:
	.string "“{COLOR DYNAMIC_COLOR3}Sinnoh{COLOR DARK_GRAY} Folk Story 3” There once were\n"
	.string "Pokémon that became very close to\l"
	.string "humans.\p"
	.string "There once were humans and Pokémon\n"
	.string "that ate together at the same table.\p"
	.string "It was a time when there existed no\n"
	.string "differences to distinguish the two.$"

CanalaveCity_Library_3F_Text_Sign13_6:
	.string "{PLAYER} put the book back.$"

CanalaveCity_Library_3F_Text_Sign15:
	.string "On this floor, you will find many books\n"
	.string "on the myths and legends of the {COLOR DYNAMIC_COLOR3}Sinnoh{COLOR DARK_GRAY}\l"
	.string "region.$"

CanalaveCity_Library_3F_Text_OnFrame:
	.string "Hey, {PLAYER}! Over here! This way!$"

CanalaveCity_Library_3F_Text_OnFrame_2:
	.string "OK, gramps! I brought {PLAYER} like I\n"
	.string "said!\p"
	.string "All right, I'll be outta here!$"

CanalaveCity_Library_3F_Text_OnFrame_3:
	.string "... ...\p"
	.string "... ...\p"
	.string "... ...$"

CanalaveCity_Library_3F_Text_OnFrame_4:
	.string "...OK... I get it...$"

CanalaveCity_Library_3F_Text_OnFrame_5:
	.string "Hm! Everyone's here finally. {PLAYER},\n"
	.string "everyone, listen.\p"
	.string "You may have forgotten already, but I\n"
	.string "study the evolution of Pokémon.$"

CanalaveCity_Library_3F_Text_OnFrame_6:
	.string "But the more I study, the more\n"
	.string "mysteries appear and multiply.\p"
	.string "Pokémon that evolve, and those that\n"
	.string "don't...\p"
	.string "What makes them different from each\n"
	.string "other?\p"
	.string "Do those that are immature as living\n"
	.string "beings evolve to ones more mature?\p"
	.string "If so, what do we make of the legendary\n"
	.string "Pokémon that don't evolve?\p"
	.string "Are we to assume that the legendary\n"
	.string "Pokémon are complete as creatures?$"

CanalaveCity_Library_3F_Text_OnFrame_7:
	.string "This is where you three come in.\p"
	.string "In the three lakes of {COLOR DYNAMIC_COLOR3}Sinnoh{COLOR DARK_GRAY}, there are\n"
	.string "said to be mirage Pokémon.\p"
	.string "If we can obtain data on them, it may\n"
	.string "shed some light on how the process of\l"
	.string "Pokémon evolution works.\p"
	.string "I need help from each one of you on this\n"
	.string "grand undertaking.\p"
	.string "Help me find these Pokémon that are\n"
	.string "considered to be mirages.$"

CanalaveCity_Library_3F_Text_OnFrame_8:
	.string "What are you saying? I didn't get no\n"
	.string "{COLOR DYNAMIC_COLOR3}Pokédex{COLOR DARK_GRAY}!$"

CanalaveCity_Library_3F_Text_OnFrame_9:
	.string "...And who was it that bolted from the\n"
	.string "lab before I had a chance to give you a\l"
	.string "{COLOR DYNAMIC_COLOR3}Pokédex{COLOR DARK_GRAY}?\p"
	.string "But that's water under the bridge!\p"
	.string "Seeing Pokémon with your own eyes is\n"
	.string "important for you in becoming a better\l"
	.string "Trainer, too.$"

CanalaveCity_Library_3F_Text_OnFrame_10:
	.string "You can count on me! It will help with my\n"
	.string "{COLOR DYNAMIC_COLOR3}Pokédex{COLOR DARK_GRAY}, too.\p"
	.string "{PLAYER}, you'll go too, won't you?$"

CanalaveCity_Library_3F_Text_OnFrame_11:
	.string "You bet, Professor!\p"
	.string "This will add to the {COLOR DYNAMIC_COLOR3}Pokédex{COLOR DARK_GRAY} database\n"
	.string "and help advance your research.$"

CanalaveCity_Library_3F_Text_OnFrame_12:
	.string "Hm! I would have made all of you go\n"
	.string "regardless... Anyway.\p"
	.string "Now, there are three lakes.\n"
	.string "Fortuitously, there are three of you.\p"
	.string "You should therefore split up and\n"
	.string "investigate the lakes individually.$"

CanalaveCity_Library_3F_Text_OnFrame_13:
	.string "Dawn, you go to {COLOR DYNAMIC_COLOR3}Lake Verity{COLOR DARK_GRAY}.$"

CanalaveCity_Library_3F_Text_OnFrame_14:
	.string "Will do!$"

CanalaveCity_Library_3F_Text_OnFrame_15:
	.string "Lucas, you go to {COLOR DYNAMIC_COLOR3}Lake Verity{COLOR DARK_GRAY}.$"

CanalaveCity_Library_3F_Text_OnFrame_16:
	.string "Yes, sir!$"

CanalaveCity_Library_3F_Text_OnFrame_17:
	.string "{RIVAL}, I want you to investigate\n"
	.string "Lake Acuity.\p"
	.string "That would take you almost to\n"
	.string "Snowpoint City.\p"
	.string "The road there is harsh. I need a tough\n"
	.string "Trainer to go.$"

CanalaveCity_Library_3F_Text_OnFrame_18:
	.string "Uh... Yeah, of course! Gramps, you know\n"
	.string "how to call it!\p"
	.string "You can tell I'm the hotness!$"

CanalaveCity_Library_3F_Text_OnFrame_19:
	.string "And that leaves {PLAYER} with Lake\n"
	.string "Valor.\p"
	.string "The lake is between Veilstone and\n"
	.string "Pastoria, if memory serves...$"

CanalaveCity_Library_3F_Text_OnFrame_20:
	.string "... ...Has it stopped?\p"
	.string "Are all of you unharmed?\p"
	.string "Let's go outside, but be careful. I'm\n"
	.string "concerned about the city.$"

CanalaveCity_Library_3F_Text_OnFrame_21:
	.string "{PLAYER}, hurry along. But beware of\n"
	.string "aftershocks.$"
