OreburghCity_Mart_MapScripts::
	.byte 0

OreburghCity_Mart_EventScript_Clerk::
	@ poe:behavior {"mode":"mart","items":[{"item":"ITEM_POKE_BALL","badges":0},{"item":"ITEM_POTION","badges":0},{"item":"ITEM_ANTIDOTE","badges":0},{"item":"ITEM_PARALYZE_HEAL","badges":0},{"item":"ITEM_AWAKENING","badges":0},{"item":"ITEM_EXP_CANDY_XS","badges":1},{"item":"ITEM_EXP_CANDY_S","badges":2},{"item":"ITEM_EXP_CANDY_M","badges":5},{"item":"ITEM_EXP_CANDY_L","badges":6},{"item":"ITEM_EXP_CANDY_XL","badges":8}]}
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	goto_if_set FLAG_BADGE08_GET, OreburghCity_Mart_EventScript_ClerkB8
	goto_if_set FLAG_BADGE06_GET, OreburghCity_Mart_EventScript_ClerkB6
	goto_if_set FLAG_BADGE05_GET, OreburghCity_Mart_EventScript_ClerkB5
	goto_if_set FLAG_BADGE02_GET, OreburghCity_Mart_EventScript_ClerkB2
	goto_if_set FLAG_BADGE01_GET, OreburghCity_Mart_EventScript_ClerkB1
	pokemart OreburghCity_Mart_EventScript_ClerkItems
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2

OreburghCity_Mart_EventScript_ClerkItems::
	.2byte ITEM_POKE_BALL
	.2byte ITEM_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	pokemartlistend

OreburghCity_Mart_EventScript_ClerkB1::
	pokemart OreburghCity_Mart_EventScript_ClerkB1Items
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2

OreburghCity_Mart_EventScript_ClerkB1Items::
	.2byte ITEM_POKE_BALL
	.2byte ITEM_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_EXP_CANDY_XS
	pokemartlistend

OreburghCity_Mart_EventScript_ClerkB2::
	pokemart OreburghCity_Mart_EventScript_ClerkB2Items
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2

OreburghCity_Mart_EventScript_ClerkB2Items::
	.2byte ITEM_POKE_BALL
	.2byte ITEM_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_EXP_CANDY_XS
	.2byte ITEM_EXP_CANDY_S
	pokemartlistend

OreburghCity_Mart_EventScript_ClerkB5::
	pokemart OreburghCity_Mart_EventScript_ClerkB5Items
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2

OreburghCity_Mart_EventScript_ClerkB5Items::
	.2byte ITEM_POKE_BALL
	.2byte ITEM_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_EXP_CANDY_XS
	.2byte ITEM_EXP_CANDY_S
	.2byte ITEM_EXP_CANDY_M
	pokemartlistend

OreburghCity_Mart_EventScript_ClerkB6::
	pokemart OreburghCity_Mart_EventScript_ClerkB6Items
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2

OreburghCity_Mart_EventScript_ClerkB6Items::
	.2byte ITEM_POKE_BALL
	.2byte ITEM_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_EXP_CANDY_XS
	.2byte ITEM_EXP_CANDY_S
	.2byte ITEM_EXP_CANDY_M
	.2byte ITEM_EXP_CANDY_L
	pokemartlistend

OreburghCity_Mart_EventScript_ClerkB8::
	pokemart OreburghCity_Mart_EventScript_ClerkB8Items
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2

OreburghCity_Mart_EventScript_ClerkB8Items::
	.2byte ITEM_POKE_BALL
	.2byte ITEM_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_EXP_CANDY_XS
	.2byte ITEM_EXP_CANDY_S
	.2byte ITEM_EXP_CANDY_M
	.2byte ITEM_EXP_CANDY_L
	.2byte ITEM_EXP_CANDY_XL
	pokemartlistend

OreburghCity_Mart_EventScript_NPC1::
	msgbox OreburghCity_Mart_Text_NPC1, MSGBOX_NPC
	end

OreburghCity_Mart_EventScript_NPC2::
	@ poe:behavior {"mode":"gift","item":"ITEM_ROCK_GEM","qty":1}
	lock
	faceplayer
	goto_if_set FLAG_OREBURGHCITY_MART_NPC2_GIFT, OreburghCity_Mart_EventScript_NPC2After
	msgbox OreburghCity_Mart_Text_NPC2, MSGBOX_DEFAULT
	giveitem ITEM_ROCK_GEM, 1
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_OREBURGHCITY_MART_NPC2_GIFT
	msgbox OreburghCity_Mart_Text_NPC2Received, MSGBOX_DEFAULT
	release
	end

OreburghCity_Mart_EventScript_NPC2After::
	msgbox OreburghCity_Mart_Text_NPC2After, MSGBOX_DEFAULT
	release
	end

OreburghCity_Mart_Text_NPC2Received::
	.string "That gem rocks.$"

OreburghCity_Mart_Text_NPC2After::
	.string "It rocks, right?$"

OreburghCity_Mart_Text_NPC1:
	.string "I'm visiting from {COLOR DYNAMIC_COLOR3}Solaceon Town{COLOR DARK_GRAY}! Check\n"
	.string "out our Daycare when you're in town,\l"
	.string "it's a very well beloved service.$"

OreburghCity_Mart_Text_NPC2:
	.string "Here, don't ask, just take this.$"
