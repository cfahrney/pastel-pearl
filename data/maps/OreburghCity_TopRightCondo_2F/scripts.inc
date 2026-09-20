OreburghCity_TopRightCondo_2F_MapScripts::
	.byte 0

OreburghCity_TopRightCondo_2F_EventScript_NPC1::
	msgbox OreburghCity_TopRightCondo_2F_Text_NPC1, MSGBOX_NPC
	end

OreburghCity_TopRightCondo_2F_EventScript_NPC2::
	msgbox OreburghCity_TopRightCondo_2F_Text_NPC2, MSGBOX_NPC
	end

OreburghCity_TopRightCondo_2F_EventScript_NPC3::
	msgbox OreburghCity_TopRightCondo_2F_Text_NPC3, MSGBOX_NPC
	end

OreburghCity_TopRightCondo_2F_EventScript_NPC4::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ROSELIA, CRY_MODE_NORMAL
	msgbox OreburghCity_TopRightCondo_2F_Text_NPC4, MSGBOX_DEFAULT
	waitmoncry
	release
	end

OreburghCity_TopRightCondo_2F_Text_NPC1:
	.string "TOP RIGHT CONDO 2F NPC 1$"

OreburghCity_TopRightCondo_2F_Text_NPC2:
	.string "TOP RIGHT CONDO 2F NPC 2$"

OreburghCity_TopRightCondo_2F_Text_NPC3:
	.string "TOP RIGHT CONDO 2F NPC 3$"

OreburghCity_TopRightCondo_2F_Text_NPC4:
	.string "TOP RIGHT CONDO 2F NPC 4$"
