OreburghCity_BottomRightCondo_2F_MapScripts::
	.byte 0

OreburghCity_BottomRightCondo_2F_EventScript_NPC1::
	msgbox OreburghCity_BottomRightCondo_2F_Text_NPC1, MSGBOX_NPC
	end

OreburghCity_BottomRightCondo_2F_EventScript_NPC2::
	msgbox OreburghCity_BottomRightCondo_2F_Text_NPC2, MSGBOX_NPC
	end

OreburghCity_BottomRightCondo_2F_EventScript_NPC3::
	msgbox OreburghCity_BottomRightCondo_2F_Text_NPC3, MSGBOX_NPC
	end

OreburghCity_BottomRightCondo_2F_EventScript_NPC4::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MURKROW, CRY_MODE_NORMAL
	msgbox OreburghCity_BottomRightCondo_2F_Text_NPC4, MSGBOX_DEFAULT
	waitmoncry
	release
	end

OreburghCity_BottomRightCondo_2F_Text_NPC1:
	.string "BOTTOM RIGHT CONDO 2F\nNPC 1$"

OreburghCity_BottomRightCondo_2F_Text_NPC2:
	.string "BOTTOM RIGHT CONDO 2F\nNPC 2$"

OreburghCity_BottomRightCondo_2F_Text_NPC3:
	.string "BOTTOM RIGHT CONDO 2F\nNPC 3$"

OreburghCity_BottomRightCondo_2F_Text_NPC4:
	.string "BOTTOM RIGHT CONDO 2F\nNPC 4$"
