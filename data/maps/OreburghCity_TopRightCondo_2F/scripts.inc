OreburghCity_TopRightCondo_2F_MapScripts::
	.byte 0

OreburghCity_TopRightCondo_2F_EventScript_NPC1::
	msgbox OreburghCity_TopRightCondo_2F_Text_NPC1, MSGBOX_NPC
	end

OreburghCity_TopRightCondo_2F_EventScript_NPC2::
	@ poe:behavior {"mode":"gift","item":"ITEM_ABILITY_CAPSULE","qty":1}
	lock
	faceplayer
	goto_if_set FLAG_OREBURGHCITY_TOPRIGHTCONDO_2F_NPC2_GIFT, OreburghCity_TopRightCondo_2F_EventScript_NPC2After
	msgbox OreburghCity_TopRightCondo_2F_Text_NPC2, MSGBOX_DEFAULT
	giveitem ITEM_ABILITY_CAPSULE, 1
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_OREBURGHCITY_TOPRIGHTCONDO_2F_NPC2_GIFT
	msgbox OreburghCity_TopRightCondo_2F_Text_NPC2Received, MSGBOX_DEFAULT
	release
	end

OreburghCity_TopRightCondo_2F_EventScript_NPC2After::
	msgbox OreburghCity_TopRightCondo_2F_Text_NPC2After, MSGBOX_DEFAULT
	release
	end

OreburghCity_TopRightCondo_2F_Text_NPC2Received::
	.string "Your {COLOR DYNAMIC_COLOR3}Pokédex{COLOR DARK_GRAY} should be able to tell you\n"
	.string "what sort of abilities your Pokémon\l"
	.string "could have.$"

OreburghCity_TopRightCondo_2F_Text_NPC2After::
	.string "Have you changed any of your Pokémon's\n"
	.string "abilities?$"

OreburghCity_TopRightCondo_2F_EventScript_NPC3::
	msgbox OreburghCity_TopRightCondo_2F_Text_NPC3, MSGBOX_NPC
	end

OreburghCity_TopRightCondo_2F_EventScript_NPC4::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ROSELIA, CRY_MODE_NORMAL
	setspeaker OreburghCity_TopRightCondo_2F_Text_NPC4Speaker
	msgbox OreburghCity_TopRightCondo_2F_Text_NPC4, MSGBOX_DEFAULT
	waitmoncry
	release
	end

OreburghCity_TopRightCondo_2F_Text_NPC1:
	.string "The view is good from up here, but it's a\n"
	.string "pain going out.$"

OreburghCity_TopRightCondo_2F_Text_NPC2:
	.string "All Pokémon have a special power called\n"
	.string "an ability. Some of those Pokémon have\l"
	.string "more than one potential ability to\l"
	.string "choose from.\p"
	.string "You can change any Pokémon's ability to\n"
	.string "its secondary with an Ability Capsule,\l"
	.string "if you have one. Which you do now!$"

OreburghCity_TopRightCondo_2F_Text_NPC3:
	.string "How my Pokémon and I are alike...\p"
	.string "It's not anything I can explain easily.$"

OreburghCity_TopRightCondo_2F_Text_NPC4:
	.string "Roooose.$"

OreburghCity_TopRightCondo_2F_Text_NPC4Speaker:
	.string "Roselia$"
