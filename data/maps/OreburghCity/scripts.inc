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
	.string "OREBURGH CITY NPC 1$"

OreburghCity_Text_NPC2:
	.string "OREBURGH CITY NPC 2$"
