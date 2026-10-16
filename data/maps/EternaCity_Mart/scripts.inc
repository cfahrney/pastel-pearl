EternaCity_Mart_MapScripts::
	.byte 0

EternaCity_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart EternaCity_Mart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2

EternaCity_Mart_Pokemart:
	.2byte ITEM_POKE_BALL
	.2byte ITEM_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	pokemartlistend

EternaCity_Mart_EventScript_NPC1::
	msgbox EternaCity_Mart_Text_NPC1_2, MSGBOX_NPC
	end

EternaCity_Mart_Text_NPC1_2:
	.string "Let me tell you something. I got into a\n"
	.string "bad situation in Eterna Forest.\p"
	.string "From now on, I'm not going anywhere\n"
	.string "without an Escape Rope.$"
