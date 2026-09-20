SandgemTown_Mart_MapScripts::
	.byte 0

SandgemTown_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart SandgemTown_Mart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
SandgemTown_Mart_Pokemart:
	.2byte ITEM_POKE_BALL
	.2byte ITEM_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	pokemartlistend

SandgemTown_Mart_EventScript_NPC1::
	msgbox SandgemTown_Mart_Text_NPC1, MSGBOX_NPC
	end

SandgemTown_Mart_EventScript_NPC2::
	msgbox SandgemTown_Mart_Text_NPC2, MSGBOX_NPC
	end

SandgemTown_Mart_Text_NPC1:
	.string "MART NPC 1$"

SandgemTown_Mart_Text_NPC2:
	.string "MART NPC 2$"
