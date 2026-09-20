SandgemTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SandgemTown_OnTransition
	.byte 0

SandgemTown_OnTransition:
	setflag FLAG_VISITED_SANDGEM_TOWN
	end

SandgemTown_EventScript_Sign1::
	msgbox SandgemTown_Text_Sign1, MSGBOX_SIGN
	end

SandgemTown_EventScript_Sign2::
	msgbox SandgemTown_Text_Sign2, MSGBOX_SIGN
	end

SandgemTown_EventScript_Sign3::
	msgbox SandgemTown_Text_Sign3, MSGBOX_SIGN
	end

SandgemTown_EventScript_Sign4::
	msgbox SandgemTown_Text_Sign4, MSGBOX_SIGN
	end

SandgemTown_EventScript_Sign5::
	msgbox SandgemTown_Text_Sign5, MSGBOX_SIGN
	end

SandgemTown_Text_Sign1:
	.string "SANDGEM TOWN SIGN 1$"

SandgemTown_Text_Sign2:
	.string "SANDGEM TOWN SIGN 2$"

SandgemTown_Text_Sign3:
	.string "SANDGEM TOWN SIGN 3$"

SandgemTown_Text_Sign4:
	.string "SANDGEM TOWN SIGN 4$"

SandgemTown_Text_Sign5:
	.string "SANDGEM TOWN SIGN 5$"

SandgemTown_EventScript_NPC1::
	msgbox SandgemTown_Text_NPC1, MSGBOX_NPC
	end

SandgemTown_EventScript_NPC2::
	msgbox SandgemTown_Text_NPC2, MSGBOX_NPC
	end

SandgemTown_EventScript_NPC3::
	msgbox SandgemTown_Text_NPC3, MSGBOX_NPC
	end

SandgemTown_Text_NPC1:
	.string "SANDGEM TOWN NPC 1$"

SandgemTown_Text_NPC2:
	.string "SANDGEM TOWN NPC 2$"

SandgemTown_Text_NPC3:
	.string "SANDGEM TOWN NPC 3$"

@ Ambient rooftop Pokemon: turn and cry, no text box.
SandgemTown_EventScript_NPC4::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_HOOTHOOT, CRY_MODE_NORMAL
	waitmoncry
	release
	end

SandgemTown_EventScript_NPC5::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_STARLY, CRY_MODE_NORMAL
	waitmoncry
	release
	end
