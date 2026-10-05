OreburghCity_BottomRightCondo_2F_MapScripts::
	.byte 0

OreburghCity_BottomRightCondo_2F_EventScript_NPC1::
	@ poe:behavior {"mode":"gift","item":"ITEM_GREAT_BALL","qty":1}
	lock
	faceplayer
	goto_if_set FLAG_OREBURGHCITY_BOTTOMRIGHTCONDO_2F_NPC1_GIFT, OreburghCity_BottomRightCondo_2F_EventScript_NPC1After
	msgbox OreburghCity_BottomRightCondo_2F_Text_NPC1, MSGBOX_DEFAULT
	giveitem ITEM_GREAT_BALL, 1
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_OREBURGHCITY_BOTTOMRIGHTCONDO_2F_NPC1_GIFT
	msgbox OreburghCity_BottomRightCondo_2F_Text_NPC1Received, MSGBOX_DEFAULT
	release
	end

OreburghCity_BottomRightCondo_2F_EventScript_NPC1After::
	msgbox OreburghCity_BottomRightCondo_2F_Text_NPC1After, MSGBOX_DEFAULT
	release
	end

OreburghCity_BottomRightCondo_2F_Text_NPC1Received::
	.string "You know how Pokémon stay inside their\n"
	.string "Poké Balls?\p"
	.string "I try to think about what would be the\n"
	.string "best Poké Balls for them.$"

OreburghCity_BottomRightCondo_2F_Text_NPC1After::
	.string "My favorite is probably the Great Ball...\n"
	.string "obviously!$"

OreburghCity_BottomRightCondo_2F_EventScript_NPC2::
	msgbox OreburghCity_BottomRightCondo_2F_Text_NPC2, MSGBOX_NPC
	end

OreburghCity_BottomRightCondo_2F_EventScript_NPC3::
	msgbox OreburghCity_BottomRightCondo_2F_Text_NPC3, MSGBOX_NPC
	end

OreburghCity_BottomRightCondo_2F_EventScript_NPC4::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ROLYCOLY, CRY_MODE_NORMAL
	setspeaker OreburghCity_BottomRightCondo_2F_Text_NPC4Speaker
	msgbox OreburghCity_BottomRightCondo_2F_Text_NPC4, MSGBOX_DEFAULT
	waitmoncry
	release
	end

OreburghCity_BottomRightCondo_2F_Text_NPC1:
	.string "Wow... Your Pokémon's eyes are twinkling\n"
	.string "brightly!\p"
	.string "Seeing that makes me happy! Here, I\n"
	.string "want you to have this!$"

OreburghCity_BottomRightCondo_2F_Text_NPC2:
	.string "The {COLOR DYNAMIC_COLOR3}Oreburgh Mine{COLOR DARK_GRAY} is operated with the\n"
	.string "utmost care.\p"
	.string "We avoid causing any damage to the\n"
	.string "natural habitats of Pokémon.$"

OreburghCity_BottomRightCondo_2F_Text_NPC3:
	.string "The whole system of taking coal out of\n"
	.string "the mine is automated nowadays. The\l"
	.string "Carkol don't mind the break!$"

OreburghCity_BottomRightCondo_2F_Text_NPC4:
	.string "Coooly!$"

OreburghCity_BottomRightCondo_2F_Text_NPC4Speaker:
	.string "Rolycoly$"
