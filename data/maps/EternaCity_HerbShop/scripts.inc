EternaCity_HerbShop_MapScripts::
	.byte 0

EternaCity_HerbShop_EventScript_NPC1::
	msgbox EternaCity_HerbShop_Text_NPC1_2, MSGBOX_NPC
	end

EternaCity_HerbShop_EventScript_NPC3::
	lock
	faceplayer
	message EternaCity_HerbShop_Text_NPC3_2
	waitmessage
	@ TODO(DP): SpecialMart 4
	release
	end

EternaCity_HerbShop_EventScript_NPC2::
	msgbox EternaCity_HerbShop_Text_NPC2_2, MSGBOX_NPC
	end

EternaCity_HerbShop_Text_NPC1_2:
	.string "Herbal meds work most impressively. But\n"
	.string "your Pokémon won't like them.\p"
	.string "They're horribly bitter and smelly!$"

EternaCity_HerbShop_Text_NPC3_2:
	.string "Welcome to the Herb Shop, home of\n"
	.string "effective yet inexpensive medicine.$"

EternaCity_HerbShop_Text_NPC2_2:
	.string "Someone ought to invent herbal\n"
	.string "medicine that isn't bitter.\p"
	.string "That would be a medical breakthrough!$"
