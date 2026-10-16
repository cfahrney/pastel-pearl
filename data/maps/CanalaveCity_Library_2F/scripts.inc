CanalaveCity_Library_2F_MapScripts::
	.byte 0

CanalaveCity_Library_2F_EventScript_NPC1::
	lock
	faceplayer
	goto_if_set FLAG_CANALAVE_CITY_FAT_MAN_1, CanalaveCity_Library_2F_EventScript_NPC1_2
	msgbox CanalaveCity_Library_2F_Text_NPC1_2, MSGBOX_DEFAULT
	closemessage
	release
	end

CanalaveCity_Library_2F_EventScript_NPC1_2::
	msgbox CanalaveCity_Library_2F_Text_NPC1_3, MSGBOX_DEFAULT
	closemessage
	release
	end

CanalaveCity_Library_2F_EventScript_Sign1::
	lockall
	msgbox CanalaveCity_Library_2F_Text_Sign1, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

CanalaveCity_Library_2F_EventScript_Sign2::
	goto CanalaveCity_Library_2F_EventScript_Sign1
	end

CanalaveCity_Library_2F_EventScript_Sign3::
	lockall
	msgbox CanalaveCity_Library_2F_Text_Sign3, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

CanalaveCity_Library_2F_EventScript_Sign4::
	goto CanalaveCity_Library_2F_EventScript_Sign3
	end

CanalaveCity_Library_2F_EventScript_Sign5::
	goto CanalaveCity_Library_2F_EventScript_Sign3
	end

CanalaveCity_Library_2F_EventScript_Sign6::
	goto CanalaveCity_Library_2F_EventScript_Sign3
	end

CanalaveCity_Library_2F_EventScript_Sign7::
	goto CanalaveCity_Library_2F_EventScript_Sign3
	end

CanalaveCity_Library_2F_EventScript_Sign8::
	goto CanalaveCity_Library_2F_EventScript_Sign3
	end

CanalaveCity_Library_2F_EventScript_Sign9::
	goto CanalaveCity_Library_2F_EventScript_Sign3
	end

CanalaveCity_Library_2F_EventScript_Sign10::
	goto CanalaveCity_Library_2F_EventScript_Sign3
	end

CanalaveCity_Library_2F_EventScript_Sign11::
	goto CanalaveCity_Library_2F_EventScript_Sign3
	end

CanalaveCity_Library_2F_EventScript_Sign12::
	goto CanalaveCity_Library_2F_EventScript_Sign3
	end

CanalaveCity_Library_2F_EventScript_Sign13::
	goto CanalaveCity_Library_2F_EventScript_Sign3
	end

CanalaveCity_Library_2F_EventScript_Sign14::
	goto CanalaveCity_Library_2F_EventScript_Sign3
	end

CanalaveCity_Library_2F_EventScript_Sign15::
	goto CanalaveCity_Library_2F_EventScript_Sign1
	end

CanalaveCity_Library_2F_EventScript_Sign16::
	goto CanalaveCity_Library_2F_EventScript_Sign1
	end

CanalaveCity_Library_2F_EventScript_Sign17::
	goto CanalaveCity_Library_2F_EventScript_Sign1
	end

CanalaveCity_Library_2F_EventScript_Sign18::
	goto CanalaveCity_Library_2F_EventScript_Sign1
	end

CanalaveCity_Library_2F_EventScript_Sign19::
	goto CanalaveCity_Library_2F_EventScript_Sign1
	end

CanalaveCity_Library_2F_EventScript_Sign20::
	goto CanalaveCity_Library_2F_EventScript_Sign1
	end

CanalaveCity_Library_2F_EventScript_Sign21::
	lockall
	msgbox CanalaveCity_Library_2F_Text_Sign21, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

CanalaveCity_Library_2F_EventScript_Sign22::
	goto CanalaveCity_Library_2F_EventScript_Sign3
	end

CanalaveCity_Library_2F_EventScript_Sign23::
	goto CanalaveCity_Library_2F_EventScript_Sign3
	end

CanalaveCity_Library_2F_EventScript_Sign24::
	goto CanalaveCity_Library_2F_EventScript_Sign3
	end

CanalaveCity_Library_2F_EventScript_Sign25::
	goto CanalaveCity_Library_2F_EventScript_Sign3
	end

CanalaveCity_Library_2F_EventScript_Sign26::
	goto CanalaveCity_Library_2F_EventScript_Sign3
	end

CanalaveCity_Library_2F_EventScript_Sign27::
	goto CanalaveCity_Library_2F_EventScript_Sign3
	end

CanalaveCity_Library_2F_EventScript_Sign28::
	goto CanalaveCity_Library_2F_EventScript_Sign3
	end

CanalaveCity_Library_2F_EventScript_Sign29::
	goto CanalaveCity_Library_2F_EventScript_Sign3
	end

CanalaveCity_Library_2F_EventScript_Sign30::
	goto CanalaveCity_Library_2F_EventScript_Sign3
	end

CanalaveCity_Library_2F_EventScript_Sign31::
	goto CanalaveCity_Library_2F_EventScript_Sign3
	end

CanalaveCity_Library_2F_EventScript_Sign32::
	goto CanalaveCity_Library_2F_EventScript_Sign3
	end

CanalaveCity_Library_2F_EventScript_Sign33::
	goto CanalaveCity_Library_2F_EventScript_Sign3
	end

CanalaveCity_Library_2F_EventScript_Sign34::
	goto CanalaveCity_Library_2F_EventScript_Sign3
	end

CanalaveCity_Library_2F_EventScript_Sign35::
	goto CanalaveCity_Library_2F_EventScript_Sign3
	end

CanalaveCity_Library_2F_Text_NPC1_2:
	.string "The books on the third floor are easy\n"
	.string "to read.\p"
	.string "The ones down here are all too tough\n"
	.string "for me to understand...$"

CanalaveCity_Library_2F_Text_NPC1_3:
	.string "I looked up a book called “Surviving\n"
	.string "Disasters” right away!$"

CanalaveCity_Library_2F_Text_Sign1:
	.string "The ceiling-high bookshelves are\n"
	.string "crammed with books.$"

CanalaveCity_Library_2F_Text_Sign3:
	.string "The shelves are lined with books worn\n"
	.string "from being read by many.$"

CanalaveCity_Library_2F_Text_Sign21:
	.string "Please refrain from bringing food or\n"
	.string "beverages into the library.$"
