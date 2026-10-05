JubilifeCity_SouthOfBattleDomeCondo_1F_MapScripts::
	.byte 0

JubilifeCity_SouthOfBattleDomeCondo_1F_EventScript_NPC1::
	@ poe:behavior {"mode":"gift","item":"ITEM_HEAL_BALL","qty":3}
	lock
	faceplayer
	goto_if_set FLAG_JUBILIFECITY_SOUTHOFBATTLEDOMECONDO_1F_NPC1_GIFT, JubilifeCity_SouthOfBattleDomeCondo_1F_EventScript_NPC1After
	msgbox JubilifeCity_SouthOfBattleDomeCondo_1F_Text_NPC1, MSGBOX_DEFAULT
	giveitem ITEM_HEAL_BALL, 3
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_JUBILIFECITY_SOUTHOFBATTLEDOMECONDO_1F_NPC1_GIFT
	msgbox JubilifeCity_SouthOfBattleDomeCondo_1F_Text_NPC1Received, MSGBOX_DEFAULT
	release
	end

JubilifeCity_SouthOfBattleDomeCondo_1F_EventScript_NPC1After::
	msgbox JubilifeCity_SouthOfBattleDomeCondo_1F_Text_NPC1After, MSGBOX_DEFAULT
	release
	end

JubilifeCity_SouthOfBattleDomeCondo_1F_Text_NPC1Received::
	.string "A Heal Ball completely heals the\n"
	.string "Pokémon it captures on the spot. That\l"
	.string "means you can catch a Pokémon and have\l"
	.string "it battle-ready right away. Of course,\l"
	.string "if your team has six Pokémon in it, it\l"
	.string "won't do any good.$"

JubilifeCity_SouthOfBattleDomeCondo_1F_Text_NPC1After::
	.string "A Heal Ball completely heals the\n"
	.string "Pokémon it captures on the spot. That\l"
	.string "means you can catch a Pokémon and have\l"
	.string "it battle-ready right away. Of course,\l"
	.string "if your team has six Pokémon in it, it\l"
	.string "won't do any good.$"

JubilifeCity_SouthOfBattleDomeCondo_1F_EventScript_NPC2::
	msgbox JubilifeCity_SouthOfBattleDomeCondo_1F_Text_NPC2, MSGBOX_NPC
	end

JubilifeCity_SouthOfBattleDomeCondo_1F_EventScript_NPC3::
	msgbox JubilifeCity_SouthOfBattleDomeCondo_1F_Text_NPC3, MSGBOX_NPC
	end

JubilifeCity_SouthOfBattleDomeCondo_1F_EventScript_NPC4::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_HOOTHOOT, CRY_MODE_NORMAL
	setspeaker JubilifeCity_SouthOfBattleDomeCondo_1F_Text_NPC4Speaker
	msgbox JubilifeCity_SouthOfBattleDomeCondo_1F_Text_NPC4, MSGBOX_DEFAULT
	waitmoncry
	release
	end

JubilifeCity_SouthOfBattleDomeCondo_1F_EventScript_NPC5::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_VULPIX_ALOLA, CRY_MODE_NORMAL
	setspeaker JubilifeCity_SouthOfBattleDomeCondo_1F_Text_NPC5Speaker
	msgbox JubilifeCity_SouthOfBattleDomeCondo_1F_Text_NPC5, MSGBOX_DEFAULT
	waitmoncry
	release
	end

JubilifeCity_SouthOfBattleDomeCondo_1F_Text_NPC1:
	.string "Here, take these!$"

JubilifeCity_SouthOfBattleDomeCondo_1F_Text_NPC2:
	.string "I like making my Pokémon use their\n"
	.string "attacks. Sometimes, when they get\l"
	.string "stronger, they learn new moves.\p"
	.string "It's super handy that you can relearn\n"
	.string "any moves your Pokémon might be able to\l"
	.string "learn from the Pokémon menu.$"

JubilifeCity_SouthOfBattleDomeCondo_1F_Text_NPC3:
	.string "I got my Vulpix through a trade from\n"
	.string "somewhere in the world. Obviously,\l"
	.string "though, she is from the {COLOR DYNAMIC_COLOR3}Alola{COLOR DARK_GRAY} Region.\l"
	.string "She's super cute.$"

JubilifeCity_SouthOfBattleDomeCondo_1F_Text_NPC4:
	.string "Hooot!$"

JubilifeCity_SouthOfBattleDomeCondo_1F_Text_NPC4Speaker:
	.string "Hoothoot$"

JubilifeCity_SouthOfBattleDomeCondo_1F_Text_NPC5:
	.string "Vulllpix!$"

JubilifeCity_SouthOfBattleDomeCondo_1F_Text_NPC5Speaker:
	.string "Vulpix$"
