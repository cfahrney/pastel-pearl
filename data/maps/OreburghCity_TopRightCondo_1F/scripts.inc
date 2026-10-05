OreburghCity_TopRightCondo_1F_MapScripts::
	.byte 0

OreburghCity_TopRightCondo_1F_EventScript_NPC1::
	@ poe:behavior {"mode":"trade","want":"SPECIES_MACHOP","give":"SPECIES_ABRA","nickname":"Kazam","otName":"Abby","otGender":"FEMALE","heldItem":"ITEM_TWISTED_SPOON"}
	lock
	faceplayer
	goto_if_set FLAG_OREBURGHCITY_TOPRIGHTCONDO_1F_NPC1_TRADED, OreburghCity_TopRightCondo_1F_EventScript_NPC1After
	ingame_trade INGAME_TRADE_OREBURGHCITY_TOPRIGHTCONDO_1F_NPC1, OreburghCity_TopRightCondo_1F_Text_NPC1, OreburghCity_TopRightCondo_1F_EventScript_NPC1Decline, OreburghCity_TopRightCondo_1F_EventScript_NPC1Wrong, OreburghCity_TopRightCondo_1F_Text_NPC1Received
	setflag FLAG_OREBURGHCITY_TOPRIGHTCONDO_1F_NPC1_TRADED
	release
	end

OreburghCity_TopRightCondo_1F_EventScript_NPC1Decline::
	msgbox OreburghCity_TopRightCondo_1F_Text_NPC1Decline, MSGBOX_DEFAULT
	release
	end

OreburghCity_TopRightCondo_1F_EventScript_NPC1Wrong::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox OreburghCity_TopRightCondo_1F_Text_NPC1Wrong, MSGBOX_DEFAULT
	release
	end

OreburghCity_TopRightCondo_1F_EventScript_NPC1After::
	msgbox OreburghCity_TopRightCondo_1F_Text_NPC1After, MSGBOX_DEFAULT
	release
	end

OreburghCity_TopRightCondo_1F_Text_NPC1Decline::
	.string "Oh, OK...\n"
	.string "Well, I can't make you trade me.\p"
	.string "But if you change your mind, I'll be\n"
	.string "right here waiting!$"

OreburghCity_TopRightCondo_1F_Text_NPC1Wrong::
	.string "Uhh, I don't think that's a Machop.\p"
	.string "I swore they weren't too far from here,\n"
	.string "maybe somewhere to the north of the\l"
	.string "city.$"

OreburghCity_TopRightCondo_1F_Text_NPC1Received::
	.string "Wooo, this is awesome! Thank you so\n"
	.string "much! Take good care of my Kazam!$"

OreburghCity_TopRightCondo_1F_Text_NPC1After::
	.string "How's Kazam doing?$"

OreburghCity_TopRightCondo_1F_EventScript_NPC2::
	msgbox OreburghCity_TopRightCondo_1F_Text_NPC2, MSGBOX_NPC
	end

OreburghCity_TopRightCondo_1F_EventScript_NPC3::
	msgbox OreburghCity_TopRightCondo_1F_Text_NPC3, MSGBOX_NPC
	end

OreburghCity_TopRightCondo_1F_EventScript_NPC4::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_FURRET, CRY_MODE_NORMAL
	setspeaker OreburghCity_TopRightCondo_1F_Text_NPC4Speaker
	msgbox OreburghCity_TopRightCondo_1F_Text_NPC4, MSGBOX_DEFAULT
	waitmoncry
	release
	end

OreburghCity_TopRightCondo_1F_EventScript_NPC5::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_CLEFABLE, CRY_MODE_NORMAL
	setspeaker OreburghCity_TopRightCondo_1F_Text_NPC5Speaker
	msgbox OreburghCity_TopRightCondo_1F_Text_NPC5, MSGBOX_DEFAULT
	waitmoncry
	release
	end

OreburghCity_TopRightCondo_1F_Text_NPC1:
	.string "Listen, listen. Do you have a Pokémon\n"
	.string "called Machop?\p"
	.string "Would you be willing to trade your\n"
	.string "Machop for my Abra?$"

OreburghCity_TopRightCondo_1F_Text_NPC2:
	.string "A Pokémon obtained in a trade grows\n"
	.string "quickly.\p"
	.string "But if a Pokémon grows too much, it will\n"
	.string "often ignore the Trainer.\p"
	.string "Of course, it won't matter if you have\n"
	.string "lots of Gym Badges.$"

OreburghCity_TopRightCondo_1F_Text_NPC3:
	.string "I wonder if my Clefable would ever want\n"
	.string "to Mega Evolve...$"

OreburghCity_TopRightCondo_1F_Text_NPC4:
	.string "Fur?$"

OreburghCity_TopRightCondo_1F_Text_NPC4Speaker:
	.string "Furret$"

OreburghCity_TopRightCondo_1F_Text_NPC5:
	.string "Faaable!$"

OreburghCity_TopRightCondo_1F_Text_NPC5Speaker:
	.string "Clefable$"
