SandgemTown_Mart_MapScripts::
	.byte 0

SandgemTown_Mart_EventScript_Clerk::
	@ poe:behavior {"mode":"mart","items":[{"item":"ITEM_POKE_BALL","badges":0},{"item":"ITEM_GREAT_BALL","badges":3},{"item":"ITEM_ULTRA_BALL","badges":5},{"item":"ITEM_POTION","badges":0},{"item":"ITEM_SUPER_POTION","badges":1},{"item":"ITEM_HYPER_POTION","badges":5},{"item":"ITEM_MAX_POTION","badges":7},{"item":"ITEM_FULL_RESTORE","badges":8},{"item":"ITEM_REVIVE","badges":3},{"item":"ITEM_ANTIDOTE","badges":0},{"item":"ITEM_PARALYZE_HEAL","badges":0},{"item":"ITEM_AWAKENING","badges":1},{"item":"ITEM_BURN_HEAL","badges":1},{"item":"ITEM_ICE_HEAL","badges":1},{"item":"ITEM_FULL_HEAL","badges":5},{"item":"ITEM_ESCAPE_ROPE","badges":1},{"item":"ITEM_REPEL","badges":1},{"item":"ITEM_SUPER_REPEL","badges":3},{"item":"ITEM_MAX_REPEL","badges":5}]}
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	goto_if_set FLAG_BADGE08_GET, SandgemTown_Mart_EventScript_ClerkB8
	goto_if_set FLAG_BADGE07_GET, SandgemTown_Mart_EventScript_ClerkB7
	goto_if_set FLAG_BADGE05_GET, SandgemTown_Mart_EventScript_ClerkB5
	goto_if_set FLAG_BADGE03_GET, SandgemTown_Mart_EventScript_ClerkB3
	goto_if_set FLAG_BADGE01_GET, SandgemTown_Mart_EventScript_ClerkB1
	pokemart SandgemTown_Mart_EventScript_ClerkItems
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2

SandgemTown_Mart_EventScript_ClerkItems::
	.2byte ITEM_POKE_BALL
	.2byte ITEM_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	pokemartlistend

SandgemTown_Mart_EventScript_ClerkB1::
	pokemart SandgemTown_Mart_EventScript_ClerkB1Items
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2

SandgemTown_Mart_EventScript_ClerkB1Items::
	.2byte ITEM_POKE_BALL
	.2byte ITEM_POTION
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_BURN_HEAL
	.2byte ITEM_ICE_HEAL
	.2byte ITEM_ESCAPE_ROPE
	.2byte ITEM_REPEL
	pokemartlistend

SandgemTown_Mart_EventScript_ClerkB3::
	pokemart SandgemTown_Mart_EventScript_ClerkB3Items
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2

SandgemTown_Mart_EventScript_ClerkB3Items::
	.2byte ITEM_POKE_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_POTION
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_REVIVE
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_BURN_HEAL
	.2byte ITEM_ICE_HEAL
	.2byte ITEM_ESCAPE_ROPE
	.2byte ITEM_REPEL
	.2byte ITEM_SUPER_REPEL
	pokemartlistend

SandgemTown_Mart_EventScript_ClerkB5::
	pokemart SandgemTown_Mart_EventScript_ClerkB5Items
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2

SandgemTown_Mart_EventScript_ClerkB5Items::
	.2byte ITEM_POKE_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_POTION
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_REVIVE
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_BURN_HEAL
	.2byte ITEM_ICE_HEAL
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_ESCAPE_ROPE
	.2byte ITEM_REPEL
	.2byte ITEM_SUPER_REPEL
	.2byte ITEM_MAX_REPEL
	pokemartlistend

SandgemTown_Mart_EventScript_ClerkB7::
	pokemart SandgemTown_Mart_EventScript_ClerkB7Items
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2

SandgemTown_Mart_EventScript_ClerkB7Items::
	.2byte ITEM_POKE_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_POTION
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_MAX_POTION
	.2byte ITEM_REVIVE
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_BURN_HEAL
	.2byte ITEM_ICE_HEAL
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_ESCAPE_ROPE
	.2byte ITEM_REPEL
	.2byte ITEM_SUPER_REPEL
	.2byte ITEM_MAX_REPEL
	pokemartlistend

SandgemTown_Mart_EventScript_ClerkB8::
	pokemart SandgemTown_Mart_EventScript_ClerkB8Items
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2

SandgemTown_Mart_EventScript_ClerkB8Items::
	.2byte ITEM_POKE_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_POTION
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_MAX_POTION
	.2byte ITEM_FULL_RESTORE
	.2byte ITEM_REVIVE
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_BURN_HEAL
	.2byte ITEM_ICE_HEAL
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_ESCAPE_ROPE
	.2byte ITEM_REPEL
	.2byte ITEM_SUPER_REPEL
	.2byte ITEM_MAX_REPEL
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
