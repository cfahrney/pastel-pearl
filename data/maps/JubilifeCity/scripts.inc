JubilifeCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, JubilifeCity_OnTransition
	.byte 0

JubilifeCity_OnTransition:
	setflag FLAG_VISITED_JUBILIFE_CITY
	end

JubilifeCity_EventScript_Sign1::
	msgbox JubilifeCity_Text_Sign1, MSGBOX_SIGN
	end

JubilifeCity_EventScript_Sign2::
	msgbox JubilifeCity_Text_Sign2, MSGBOX_SIGN
	end

JubilifeCity_EventScript_Sign3::
	msgbox JubilifeCity_Text_Sign3, MSGBOX_SIGN
	end

JubilifeCity_EventScript_Sign4::
	msgbox JubilifeCity_Text_Sign4, MSGBOX_SIGN
	end

JubilifeCity_EventScript_Sign5::
	msgbox JubilifeCity_Text_Sign5, MSGBOX_SIGN
	end

JubilifeCity_EventScript_Sign6::
	msgbox JubilifeCity_Text_Sign6, MSGBOX_SIGN
	end

JubilifeCity_EventScript_Sign7::
	msgbox JubilifeCity_Text_Sign7, MSGBOX_SIGN
	end

JubilifeCity_EventScript_Sign8::
	msgbox JubilifeCity_Text_Sign8, MSGBOX_SIGN
	end

JubilifeCity_Text_Sign1:
	.string "JUBILIFE CITY SIGN 1$"

JubilifeCity_Text_Sign2:
	.string "JUBILIFE CITY SIGN 2$"

JubilifeCity_Text_Sign3:
	.string "JUBILIFE CITY SIGN 3$"

JubilifeCity_Text_Sign4:
	.string "JUBILIFE CITY SIGN 4$"

JubilifeCity_Text_Sign5:
	.string "JUBILIFE CITY SIGN 5$"

JubilifeCity_Text_Sign6:
	.string "JUBILIFE CITY SIGN 6$"

JubilifeCity_Text_Sign7:
	.string "JUBILIFE CITY SIGN 7$"

JubilifeCity_Text_Sign8:
	.string "JUBILIFE CITY SIGN 8$"
