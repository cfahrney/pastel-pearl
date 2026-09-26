JubilifeCity_Mart_MapScripts::
	.byte 0

JubilifeCity_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart JubilifeCity_Mart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
JubilifeCity_Mart_Pokemart:
	.2byte ITEM_POKE_BALL
	.2byte ITEM_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	pokemartlistend

JubilifeCity_Mart_EventScript_NPC1::
	msgbox JubilifeCity_Mart_Text_NPC1, MSGBOX_NPC
	end

JubilifeCity_Mart_EventScript_NPC2::
	msgbox JubilifeCity_Mart_Text_NPC2, MSGBOX_NPC
	end

JubilifeCity_Mart_Text_NPC1:
	.string "I need potions most of all!\p"
	.string "If my Pokemon faints, my eyes grow dim\n"
	.string "and I can't see!\p"
	.string "Maybe I should get that checked out...$"

JubilifeCity_Mart_Text_NPC2:
	.string "If you're catching a Pokemon, you have\n"
	.string "to get its HP down.\p"
	.string "If you don't, Poke Balls won't be very\n"
	.string "effective.$"
