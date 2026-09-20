OreburghCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, OreburghCity_OnTransition
	.byte 0

OreburghCity_OnTransition:
	setflag FLAG_VISITED_OREBURGH_CITY
	end

OreburghCity_EventScript_NPC1::
	msgbox OreburghCity_Text_NPC1, MSGBOX_NPC
	end

OreburghCity_EventScript_NPC2::
	msgbox OreburghCity_Text_NPC2, MSGBOX_NPC
	end

OreburghCity_Text_NPC1:
	.string "The Gym Leader went off to work in the\n"
	.string "mine.$"

OreburghCity_Text_NPC2:
	.string "When I run around with my Running Shoes\n"
	.string "on, it feels like I'm the center of\l"
	.string "attention!$"

OreburghCity_EventScript_NPC3::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MACHOP, CRY_MODE_NORMAL
	msgbox OreburghCity_Text_NPC3, MSGBOX_DEFAULT
	waitmoncry
	release
	end

OreburghCity_Text_NPC3:
	.string "OREBURGH CITY NPC 3$"

OreburghCity_EventScript_Sign1::
	msgbox OreburghCity_Text_Sign1, MSGBOX_SIGN
	end

OreburghCity_EventScript_Sign2::
	msgbox OreburghCity_Text_Sign2, MSGBOX_SIGN
	end

OreburghCity_EventScript_Sign3::
	msgbox OreburghCity_Text_Sign3, MSGBOX_SIGN
	end

OreburghCity_EventScript_NPC4::
	msgbox OreburghCity_Text_NPC4, MSGBOX_NPC
	end

OreburghCity_EventScript_NPC5::
	msgbox OreburghCity_Text_NPC5, MSGBOX_NPC
	end

OreburghCity_EventScript_NPC6::
	msgbox OreburghCity_Text_NPC6, MSGBOX_NPC
	end

OreburghCity_EventScript_NPC7::
	msgbox OreburghCity_Text_NPC7, MSGBOX_NPC
	end

OreburghCity_EventScript_NPC8::
	msgbox OreburghCity_Text_NPC8, MSGBOX_NPC
	end

OreburghCity_EventScript_NPC9::
	msgbox OreburghCity_Text_NPC9, MSGBOX_NPC
	end

OreburghCity_Text_Sign1:
	.string "OREBURGH CITY SIGN 1$"

OreburghCity_Text_Sign2:
	.string "OREBURGH CITY SIGN 2$"

OreburghCity_Text_Sign3:
	.string "OREBURGH CITY SIGN 3$"

OreburghCity_Text_NPC4:
	.string "OREBURGH CITY NPC 4$"

OreburghCity_Text_NPC5:
	.string "OREBURGH CITY NPC 5$"

OreburghCity_Text_NPC6:
	.string "OREBURGH CITY NPC 6$"

OreburghCity_Text_NPC7:
	.string "OREBURGH CITY NPC 7$"

OreburghCity_Text_NPC8:
	.string "OREBURGH CITY NPC 8$"

OreburghCity_Text_NPC9:
	.string "OREBURGH CITY NPC 9$"
