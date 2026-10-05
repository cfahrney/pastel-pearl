OreburghCity_TopLeftCondo_1F_MapScripts::
	.byte 0

OreburghCity_TopLeftCondo_1F_EventScript_NPC1::
	@ poe:behavior {"mode":"gift","item":"ITEM_EXP_CANDY_S","qty":1}
	lock
	faceplayer
	goto_if_set FLAG_OREBURGHCITY_TOPLEFTCONDO_1F_NPC1_GIFT, OreburghCity_TopLeftCondo_1F_EventScript_NPC1After
	msgbox OreburghCity_TopLeftCondo_1F_Text_NPC1, MSGBOX_DEFAULT
	giveitem ITEM_EXP_CANDY_S, 1
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_OREBURGHCITY_TOPLEFTCONDO_1F_NPC1_GIFT
	msgbox OreburghCity_TopLeftCondo_1F_Text_NPC1Received, MSGBOX_DEFAULT
	release
	end

OreburghCity_TopLeftCondo_1F_EventScript_NPC1After::
	msgbox OreburghCity_TopLeftCondo_1F_Text_NPC1After, MSGBOX_DEFAULT
	release
	end

OreburghCity_TopLeftCondo_1F_Text_NPC1Received::
	.string "My Pokémon love these. You should see\n"
	.string "what yours thinks!$"

OreburghCity_TopLeftCondo_1F_Text_NPC1After::
	.string "My Pokémon love these. You should see\n"
	.string "what yours thinks!$"

OreburghCity_TopLeftCondo_1F_EventScript_NPC2::
	msgbox OreburghCity_TopLeftCondo_1F_Text_NPC2, MSGBOX_NPC
	end

OreburghCity_TopLeftCondo_1F_EventScript_NPC3::
	msgbox OreburghCity_TopLeftCondo_1F_Text_NPC3, MSGBOX_NPC
	end

OreburghCity_TopLeftCondo_1F_EventScript_NPC4::
	msgbox OreburghCity_TopLeftCondo_1F_Text_NPC4, MSGBOX_NPC
	end

OreburghCity_TopLeftCondo_1F_Text_NPC1:
	.string "Roark lets us train our Pokémon in the\n"
	.string "mine. Sometimes when I'm training, I\l"
	.string "come across these down there. Here,\l"
	.string "take one.$"

OreburghCity_TopLeftCondo_1F_Text_NPC2:
	.string "I'm playing Pokémon Crystal. I think\n"
	.string "Suicune looks super cool.$"

OreburghCity_TopLeftCondo_1F_Text_NPC3:
	.string "There are eight Gym Leaders in the\n"
	.string "{COLOR DYNAMIC_COLOR3}Sinnoh{COLOR DARK_GRAY} region.\p"
	.string "The objective for Trainers is to get\n"
	.string "Gym Badges from all of them.$"

OreburghCity_TopLeftCondo_1F_Text_NPC4:
	.string "I'm playing Link's Awakening! Have you\n"
	.string "played it before?$"
