CanalaveCity_Library_1F_MapScripts::
	.byte 0

CanalaveCity_Library_1F_EventScript_NPC1::
	lock
	faceplayer
	goto_if_set FLAG_CANALAVE_CITY_FAT_MAN_1, CanalaveCity_Library_1F_EventScript_NPC1_2
	msgbox CanalaveCity_Library_1F_Text_NPC1_2, MSGBOX_DEFAULT
	closemessage
	release
	end

CanalaveCity_Library_1F_EventScript_NPC1_2::
	msgbox CanalaveCity_Library_1F_Text_NPC1_3, MSGBOX_DEFAULT
	closemessage
	release
	end

CanalaveCity_Library_1F_EventScript_NPC2::
	lockall
	goto_if_set FLAG_CANALAVE_CITY_FAT_MAN_1, CanalaveCity_Library_1F_EventScript_NPC2_2
	msgbox CanalaveCity_Library_1F_Text_NPC2_2, MSGBOX_DEFAULT
	faceplayer
	msgbox CanalaveCity_Library_1F_Text_NPC2_3, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CANALAVE_CITY_LIBRARY_1_F_LASS, CanalaveCity_Library_1F_Movement_Lass
	waitmovement 0
	releaseall
	end

CanalaveCity_Library_1F_EventScript_NPC2_2::
	faceplayer
	msgbox CanalaveCity_Library_1F_Text_NPC2_4, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

CanalaveCity_Library_1F_EventScript_Sign1::
	lockall
	msgbox CanalaveCity_Library_1F_Text_Sign1, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

CanalaveCity_Library_1F_EventScript_Sign2::
	lockall
	msgbox CanalaveCity_Library_1F_Text_Sign2, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

CanalaveCity_Library_1F_EventScript_Sign3::
	goto CanalaveCity_Library_1F_EventScript_Sign1
	end

CanalaveCity_Library_1F_EventScript_Sign4::
	goto CanalaveCity_Library_1F_EventScript_Sign1
	end

CanalaveCity_Library_1F_EventScript_Sign5::
	goto CanalaveCity_Library_1F_EventScript_Sign1
	end

CanalaveCity_Library_1F_EventScript_Sign6::
	goto CanalaveCity_Library_1F_EventScript_Sign1
	end

CanalaveCity_Library_1F_EventScript_Sign7::
	goto CanalaveCity_Library_1F_EventScript_Sign1
	end

CanalaveCity_Library_1F_EventScript_Sign8::
	goto CanalaveCity_Library_1F_EventScript_Sign2
	end

CanalaveCity_Library_1F_EventScript_Sign9::
	goto CanalaveCity_Library_1F_EventScript_Sign2
	end

CanalaveCity_Library_1F_EventScript_Sign10::
	goto CanalaveCity_Library_1F_EventScript_Sign2
	end

CanalaveCity_Library_1F_EventScript_Sign11::
	goto CanalaveCity_Library_1F_EventScript_Sign1
	end

CanalaveCity_Library_1F_EventScript_Sign12::
	goto CanalaveCity_Library_1F_EventScript_Sign1
	end

CanalaveCity_Library_1F_EventScript_Sign13::
	goto CanalaveCity_Library_1F_EventScript_Sign1
	end

CanalaveCity_Library_1F_EventScript_Sign14::
	goto CanalaveCity_Library_1F_EventScript_Sign1
	end

CanalaveCity_Library_1F_EventScript_Sign15::
	goto CanalaveCity_Library_1F_EventScript_Sign1
	end

CanalaveCity_Library_1F_EventScript_Sign16::
	goto CanalaveCity_Library_1F_EventScript_Sign1
	end

CanalaveCity_Library_1F_EventScript_Sign17::
	goto CanalaveCity_Library_1F_EventScript_Sign2
	end

CanalaveCity_Library_1F_EventScript_Sign18::
	goto CanalaveCity_Library_1F_EventScript_Sign2
	end

CanalaveCity_Library_1F_EventScript_Sign19::
	goto CanalaveCity_Library_1F_EventScript_Sign2
	end

CanalaveCity_Library_1F_EventScript_Sign20::
	goto CanalaveCity_Library_1F_EventScript_Sign2
	end

CanalaveCity_Library_1F_EventScript_Sign21::
	goto CanalaveCity_Library_1F_EventScript_Sign2
	end

CanalaveCity_Library_1F_Movement_Lass:
	face_up
	step_end

CanalaveCity_Library_1F_Text_NPC1_2:
	.string "Hello. This is the Canalave Library.\p"
	.string "Please keep quiet while you're on the\n"
	.string "premises.$"

CanalaveCity_Library_1F_Text_NPC1_3:
	.string "H-hello! This is the Canalave Library.\p"
	.string "Please keep quiet while you're on the\n"
	.string "premises.\p"
	.string "It certainly wasn't me who screamed,\n"
	.string "“Gyaaah!!” or shouted, “Help meee!!” No,\l"
	.string "really, that wasn't me screaming!$"

CanalaveCity_Library_1F_Text_NPC2_2:
	.string "...$"

CanalaveCity_Library_1F_Text_NPC2_3:
	.string "What is it? Please don't disturb me when\n"
	.string "I'm reading.$"

CanalaveCity_Library_1F_Text_NPC2_4:
	.string "I've been asking people not to disturb\n"
	.string "me while I'm reading...\p"
	.string "I shouldn't even have bothered... I'm all\n"
	.string "agitated now!$"

CanalaveCity_Library_1F_Text_Sign1:
	.string "The ceiling-high bookshelves are\n"
	.string "crammed with books.$"

CanalaveCity_Library_1F_Text_Sign2:
	.string "The shelves are lined with books worn\n"
	.string "from being read by many people.$"
