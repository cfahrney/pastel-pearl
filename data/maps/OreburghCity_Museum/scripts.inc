OreburghCity_Museum_MapScripts::
	.byte 0

OreburghCity_Museum_EventScript_NPC1::
	msgbox OreburghCity_Museum_Text_NPC1, MSGBOX_NPC
	end

OreburghCity_Museum_EventScript_NPC2::
	msgbox OreburghCity_Museum_Text_NPC2, MSGBOX_NPC
	end

OreburghCity_Museum_EventScript_NPC3::
	msgbox OreburghCity_Museum_Text_NPC3, MSGBOX_NPC
	end

OreburghCity_Museum_EventScript_NPC4::
	msgbox OreburghCity_Museum_Text_NPC4, MSGBOX_NPC
	end

OreburghCity_Museum_EventScript_NPC5::
	msgbox OreburghCity_Museum_Text_NPC5, MSGBOX_NPC
	end

OreburghCity_Museum_EventScript_NPC6::
	msgbox OreburghCity_Museum_Text_NPC6, MSGBOX_NPC
	end

OreburghCity_Museum_EventScript_NPC7::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MIME_JR, CRY_MODE_NORMAL
	msgbox OreburghCity_Museum_Text_NPC7, MSGBOX_DEFAULT
	waitmoncry
	release
	end

OreburghCity_Museum_EventScript_NPC8::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SHIELDON, CRY_MODE_NORMAL
	msgbox OreburghCity_Museum_Text_NPC8, MSGBOX_DEFAULT
	waitmoncry
	release
	end

OreburghCity_Museum_Text_NPC1:
	.string "MUSEUM NPC 1$"

OreburghCity_Museum_Text_NPC2:
	.string "MUSEUM NPC 2$"

OreburghCity_Museum_Text_NPC3:
	.string "MUSEUM NPC 3$"

OreburghCity_Museum_Text_NPC4:
	.string "MUSEUM NPC 4$"

OreburghCity_Museum_Text_NPC5:
	.string "MUSEUM NPC 5$"

OreburghCity_Museum_Text_NPC6:
	.string "MUSEUM NPC 6$"

OreburghCity_Museum_Text_NPC7:
	.string "MUSEUM NPC 7$"

OreburghCity_Museum_Text_NPC8:
	.string "MUSEUM NPC 8$"
