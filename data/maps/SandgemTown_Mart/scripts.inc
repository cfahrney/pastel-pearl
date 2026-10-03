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
	@ poe:behavior {"mode":"gift","item":"ITEM_POKE_BALL","qty":1}
	lock
	faceplayer
	goto_if_set FLAG_SANDGEMTOWN_MART_NPC1_GIFT, SandgemTown_Mart_EventScript_NPC1After
	msgbox SandgemTown_Mart_Text_NPC1, MSGBOX_DEFAULT
	giveitem ITEM_POKE_BALL, 1
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_SANDGEMTOWN_MART_NPC1_GIFT
	msgbox SandgemTown_Mart_Text_NPC1Received, MSGBOX_DEFAULT
	release
	end

SandgemTown_Mart_EventScript_NPC1After::
	msgbox SandgemTown_Mart_Text_NPC1After, MSGBOX_DEFAULT
	release
	end

SandgemTown_Mart_Text_NPC1Received::
	.string "Gotta catch 'em all, am I right?$"

SandgemTown_Mart_Text_NPC1After::
	.string "Gotta catch 'em all, am I right?$"

SandgemTown_Mart_EventScript_NPC2::
	msgbox SandgemTown_Mart_Text_NPC2, MSGBOX_NPC
	end

SandgemTown_Mart_Text_NPC1:
	.string "If you come across a Pokémon you've\n"
	.string "just gotta have, toss a Poké Ball! Never\l"
	.string "leave home without one! In, fact, here!$"

SandgemTown_Mart_Text_NPC2:
	.string "If a Pokémon loses all its HP, it can't\n"
	.string "battle anymore. I'm buying lots of\l"
	.string "Potions to avoid having that happen!$"
