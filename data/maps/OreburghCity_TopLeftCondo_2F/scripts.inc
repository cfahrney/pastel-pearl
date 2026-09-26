OreburghCity_TopLeftCondo_2F_MapScripts::
	.byte 0

OreburghCity_TopLeftCondo_2F_EventScript_NPC1::
	msgbox OreburghCity_TopLeftCondo_2F_Text_NPC1, MSGBOX_NPC
	end

OreburghCity_TopLeftCondo_2F_EventScript_NPC2::
	msgbox OreburghCity_TopLeftCondo_2F_Text_NPC2, MSGBOX_NPC
	end

OreburghCity_TopLeftCondo_2F_EventScript_NPC3::
	msgbox OreburghCity_TopLeftCondo_2F_Text_NPC3, MSGBOX_NPC
	end

OreburghCity_TopLeftCondo_2F_EventScript_NPC4::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_PSYDUCK, CRY_MODE_NORMAL
	setspeaker OreburghCity_TopLeftCondo_2F_Text_NPC4Speaker
	msgbox OreburghCity_TopLeftCondo_2F_Text_NPC4, MSGBOX_DEFAULT
	waitmoncry
	release
	end

OreburghCity_TopLeftCondo_2F_Text_NPC1:
	.string "TOP LEFT CONDO 2F NPC 1$"

OreburghCity_TopLeftCondo_2F_Text_NPC2:
	.string "TOP LEFT CONDO 2F NPC 2$"

OreburghCity_TopLeftCondo_2F_Text_NPC3:
	.string "TOP LEFT CONDO 2F NPC 3$"

OreburghCity_TopLeftCondo_2F_Text_NPC4:
	.string "TOP LEFT CONDO 2F NPC 4$"

OreburghCity_TopLeftCondo_2F_Text_NPC4Speaker:
	.string "Psyduck$"
