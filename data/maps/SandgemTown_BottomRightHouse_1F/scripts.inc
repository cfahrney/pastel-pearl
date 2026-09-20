SandgemTown_BottomRightHouse_1F_MapScripts::
	.byte 0

SandgemTown_BottomRightHouse_1F_EventScript_NPC1::
	msgbox SandgemTown_BottomRightHouse_1F_Text_NPC1, MSGBOX_NPC
	end

SandgemTown_BottomRightHouse_1F_EventScript_NPC2::
	msgbox SandgemTown_BottomRightHouse_1F_Text_NPC2, MSGBOX_NPC
	end

SandgemTown_BottomRightHouse_1F_EventScript_NPC3::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_BIDOOF, CRY_MODE_NORMAL
	msgbox SandgemTown_BottomRightHouse_1F_Text_NPC3, MSGBOX_DEFAULT
	waitmoncry
	release
	end

SandgemTown_BottomRightHouse_1F_Text_NPC1:
	.string "BOTTOM RIGHT HOUSE 1F NPC 1$"

SandgemTown_BottomRightHouse_1F_Text_NPC2:
	.string "BOTTOM RIGHT HOUSE 1F NPC 2$"

SandgemTown_BottomRightHouse_1F_Text_NPC3:
	.string "BOTTOM RIGHT HOUSE 1F NPC 3$"
