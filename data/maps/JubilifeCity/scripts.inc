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
	.string "Jubilife City\n"
	.string "City of Joy$"

JubilifeCity_Text_Sign2:
	.string "Jubilife TV\n"
	.string "The Fun-and-Games TV Station!$"

JubilifeCity_Text_Sign3:
	.string "Jubilife Condominiums\n"
	.string "Tenants Wanted!$"

JubilifeCity_Text_Sign4:
	.string "Jubilife City\n"
	.string "City of Joy$"

JubilifeCity_Text_Sign5:
	.string "Jubilife City\n"
	.string "City of Joy$"

JubilifeCity_Text_Sign6:
	.string "The DexNav Company Pokemon\n"
	.string "DexNavs for the World!$"

JubilifeCity_Text_Sign7:
	.string "Global Trade Station\n"
	.string "Worldwide Pokemon Trading$"

JubilifeCity_Text_Sign8:
	.string "Trainers' School\n"
	.string "The First Step for Trainers!$"

JubilifeCity_EventScript_NPC1::
	msgbox JubilifeCity_Text_NPC1, MSGBOX_NPC
	end

JubilifeCity_EventScript_NPC2::
	msgbox JubilifeCity_Text_NPC2, MSGBOX_NPC
	end

JubilifeCity_EventScript_NPC3::
	msgbox JubilifeCity_Text_NPC3, MSGBOX_NPC
	end

JubilifeCity_EventScript_NPC4::
	msgbox JubilifeCity_Text_NPC4, MSGBOX_NPC
	end

JubilifeCity_EventScript_NPC5::
	msgbox JubilifeCity_Text_NPC5, MSGBOX_NPC
	end

JubilifeCity_EventScript_NPC6::
	msgbox JubilifeCity_Text_NPC6, MSGBOX_NPC
	end

JubilifeCity_EventScript_NPC7::
	msgbox JubilifeCity_Text_NPC7, MSGBOX_NPC
	end

JubilifeCity_EventScript_NPC8::
	msgbox JubilifeCity_Text_NPC8, MSGBOX_NPC
	end

JubilifeCity_Text_NPC1:
	.string "JUBILIFE CITY NPC 1$"

JubilifeCity_Text_NPC2:
	.string "JUBILIFE CITY NPC 2$"

JubilifeCity_Text_NPC3:
	.string "JUBILIFE CITY NPC 3$"

JubilifeCity_Text_NPC4:
	.string "JUBILIFE CITY NPC 4$"

JubilifeCity_Text_NPC5:
	.string "JUBILIFE CITY NPC 5$"

JubilifeCity_Text_NPC6:
	.string "JUBILIFE CITY NPC 6$"

JubilifeCity_Text_NPC7:
	.string "JUBILIFE CITY NPC 7$"

JubilifeCity_Text_NPC8:
	.string "JUBILIFE CITY NPC 8$"
