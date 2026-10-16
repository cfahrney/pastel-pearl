FloaromaTown_Mart_MapScripts::
	.byte 0

FloaromaTown_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart FloaromaTown_Mart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
FloaromaTown_Mart_Pokemart:
	.2byte ITEM_POKE_BALL
	.2byte ITEM_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	pokemartlistend

FloaromaTown_Mart_EventScript_NPC1::
	msgbox FloaromaTown_Mart_Text_NPC1, MSGBOX_NPC
	end

FloaromaTown_Mart_Text_NPC1:
	.string "I'm going to dress up my Pokémon with\n"
	.string "cute Accessories and take it to the\p"
	.string "TV station in {COLOR DYNAMIC_COLOR3}Jubilife City{COLOR DARK_GRAY}.\p"
	.string "That way, everyone in the region will be\n"
	.string "able to see my Pokémon!$"

FloaromaTown_Mart_EventScript_NPC2::
	msgbox FloaromaTown_Mart_Text_NPC2, MSGBOX_NPC
	end

FloaromaTown_Mart_Text_NPC2:
	.string "You can't buy Berries or Accessories at\n"
	.string "Poké Marts.$"
