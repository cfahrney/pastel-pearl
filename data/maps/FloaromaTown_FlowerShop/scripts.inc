FloaromaTown_FlowerShop_MapScripts::
	.byte 0

FloaromaTown_FlowerShop_EventScript_NPC1::
	msgbox FloaromaTown_FlowerShop_Text_NPC1, MSGBOX_NPC
	end

FloaromaTown_FlowerShop_Text_NPC1:
	.string "Trainer, please water Berries using this\n"
	.string "Sprayduck watering can.$"

FloaromaTown_FlowerShop_EventScript_NPC2::
	msgbox FloaromaTown_FlowerShop_Text_NPC2, MSGBOX_NPC
	end

FloaromaTown_FlowerShop_Text_NPC2:
	.string "A single Berry will grow into a plant\n"
	.string "that makes several Berries.\p"
	.string "By planting one, there will be more and\n"
	.string "more Berries in the world.\p"
	.string "I hope you will help us spread more\n"
	.string "Berries everywhere!$"

FloaromaTown_FlowerShop_EventScript_NPC3::
	@ poe:behavior {"mode":"mart","items":[{"item":"ITEM_BERRY_JUICE","badges":0}]}
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart FloaromaTown_FlowerShop_EventScript_NPC3Items
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2

FloaromaTown_FlowerShop_EventScript_NPC3Items::
	.2byte ITEM_BERRY_JUICE
	pokemartlistend

FloaromaTown_FlowerShop_Text_NPC3:
	.string "FLOWER SHOP NPC 3$"

FloaromaTown_FlowerShop_EventScript_NPC4::
	lock
	faceplayer
	@ TODO(DP): AccessoriesShop
	release
	end
