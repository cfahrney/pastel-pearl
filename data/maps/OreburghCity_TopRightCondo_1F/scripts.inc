OreburghCity_TopRightCondo_1F_MapScripts::
	.byte 0

OreburghCity_TopRightCondo_1F_EventScript_NPC1::
	msgbox OreburghCity_TopRightCondo_1F_Text_NPC1, MSGBOX_NPC
	end

OreburghCity_TopRightCondo_1F_EventScript_NPC2::
	msgbox OreburghCity_TopRightCondo_1F_Text_NPC2, MSGBOX_NPC
	end

OreburghCity_TopRightCondo_1F_EventScript_NPC3::
	msgbox OreburghCity_TopRightCondo_1F_Text_NPC3, MSGBOX_NPC
	end

OreburghCity_TopRightCondo_1F_EventScript_NPC4::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SENTRET, CRY_MODE_NORMAL
	setspeaker OreburghCity_TopRightCondo_1F_Text_NPC4Speaker
	msgbox OreburghCity_TopRightCondo_1F_Text_NPC4, MSGBOX_DEFAULT
	waitmoncry
	release
	end

OreburghCity_TopRightCondo_1F_EventScript_NPC5::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_CLEFFA, CRY_MODE_NORMAL
	setspeaker OreburghCity_TopRightCondo_1F_Text_NPC5Speaker
	msgbox OreburghCity_TopRightCondo_1F_Text_NPC5, MSGBOX_DEFAULT
	waitmoncry
	release
	end

OreburghCity_TopRightCondo_1F_Text_NPC1:
	.string "TOP RIGHT CONDO 1F NPC 1$"

OreburghCity_TopRightCondo_1F_Text_NPC2:
	.string "TOP RIGHT CONDO 1F NPC 2$"

OreburghCity_TopRightCondo_1F_Text_NPC3:
	.string "TOP RIGHT CONDO 1F NPC 3$"

OreburghCity_TopRightCondo_1F_Text_NPC4:
	.string "TOP RIGHT CONDO 1F NPC 4$"

OreburghCity_TopRightCondo_1F_Text_NPC4Speaker:
	.string "Sentret$"

OreburghCity_TopRightCondo_1F_Text_NPC5:
	.string "TOP RIGHT CONDO 1F NPC 5$"

OreburghCity_TopRightCondo_1F_Text_NPC5Speaker:
	.string "Cleffa$"
