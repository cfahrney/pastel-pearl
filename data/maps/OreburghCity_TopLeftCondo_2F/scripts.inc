OreburghCity_TopLeftCondo_2F_MapScripts::
	.byte 0

OreburghCity_TopLeftCondo_2F_EventScript_NPC1::
	msgbox OreburghCity_TopLeftCondo_2F_Text_NPC1, MSGBOX_NPC
	end

OreburghCity_TopLeftCondo_2F_EventScript_NPC2::
	@ poe:behavior {"mode":"gift","item":"ITEM_DUSK_BALL","qty":1}
	lock
	faceplayer
	goto_if_set FLAG_OREBURGHCITY_TOPLEFTCONDO_2F_NPC2_GIFT, OreburghCity_TopLeftCondo_2F_EventScript_NPC2After
	msgbox OreburghCity_TopLeftCondo_2F_Text_NPC2, MSGBOX_DEFAULT
	giveitem ITEM_DUSK_BALL, 1
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_OREBURGHCITY_TOPLEFTCONDO_2F_NPC2_GIFT
	msgbox OreburghCity_TopLeftCondo_2F_Text_NPC2Received, MSGBOX_DEFAULT
	release
	end

OreburghCity_TopLeftCondo_2F_EventScript_NPC2After::
	msgbox OreburghCity_TopLeftCondo_2F_Text_NPC2After, MSGBOX_DEFAULT
	release
	end

OreburghCity_TopLeftCondo_2F_Text_NPC2Received::
	.string "The Dusk Ball is a Poké Ball designed\n"
	.string "for use in darkness. It works best if\l"
	.string "you use it at night or in caves.$"

OreburghCity_TopLeftCondo_2F_Text_NPC2After::
	.string "I caught my Geodude with a Dusk Ball in\n"
	.string "{COLOR DYNAMIC_COLOR3}Oreburgh Mine{COLOR DARK_GRAY}!$"

OreburghCity_TopLeftCondo_2F_EventScript_NPC3::
	msgbox OreburghCity_TopLeftCondo_2F_Text_NPC3, MSGBOX_NPC
	end

OreburghCity_TopLeftCondo_2F_EventScript_NPC4::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_PSYDUCK, CRY_MODE_NORMAL
	setspeaker OreburghCity_TopLeftCondo_2F_Text_NPC4Speaker
	msgbox OreburghCity_TopLeftCondo_2F_Text_NPC4, MSGBOX_DEFAULT
	waitmoncry
	release
	end

OreburghCity_TopLeftCondo_2F_Text_NPC1:
	.string "Giving nicknames to Pokémon is the way\n"
	.string "to go.\p"
	.string "It makes you feel as if they're your\n"
	.string "very own.$"

OreburghCity_TopLeftCondo_2F_Text_NPC2:
	.string "Are you catching Pokémon?\n"
	.string "Here, take this if you'd like.$"

OreburghCity_TopLeftCondo_2F_Text_NPC3:
	.string "But he named our Psyduck “Yellow” just\n"
	.string "because of its color...\p"
	.string "I don't understand the logic behind\n"
	.string "that at all.$"

OreburghCity_TopLeftCondo_2F_Text_NPC4:
	.string "Duuuuck?$"

OreburghCity_TopLeftCondo_2F_Text_NPC4Speaker:
	.string "Psyduck$"
