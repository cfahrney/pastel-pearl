OreburghCity_OreburghMine_MapScripts::
	.byte 0

OreburghCity_OreburghMine_EventScript_NPC1::
	msgbox OreburghCity_OreburghMine_Text_NPC1, MSGBOX_NPC
	end

OreburghCity_OreburghMine_EventScript_NPC2::
	msgbox OreburghCity_OreburghMine_Text_NPC2, MSGBOX_NPC
	end

OreburghCity_OreburghMine_Text_NPC1:
	.string "Everyone that works in the coal mine\n"
	.string "keeps their own Pokémon with them.\p"
	.string "You may be challenged to battles!\n"
	.string "Hahaha!$"

OreburghCity_OreburghMine_Text_NPC2:
	.string "There were Pokémon that looked just\n"
	.string "like rocks! And some that looked just\l"
	.string "like mine carts! They sure surprised me!$"

OreburghCity_OreburghMine_EventScript_NPC3::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_GEODUDE, CRY_MODE_NORMAL
	setspeaker OreburghCity_OreburghMine_Text_NPC3Speaker
	msgbox OreburghCity_OreburghMine_Text_NPC3, MSGBOX_DEFAULT
	waitmoncry
	release
	end

OreburghCity_OreburghMine_Text_NPC3:
	.string "OREBURGH MINE NPC 3$"

OreburghCity_OreburghMine_Text_NPC3Speaker:
	.string "Geodude$"

OreburghCity_OreburghMine_EventScript_NPC4::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ROLYCOLY, CRY_MODE_NORMAL
	setspeaker OreburghCity_OreburghMine_Text_NPC4Speaker
	msgbox OreburghCity_OreburghMine_Text_NPC4, MSGBOX_DEFAULT
	waitmoncry
	release
	end

OreburghCity_OreburghMine_Text_NPC4:
	.string "OREBURGH MINE NPC 4$"

OreburghCity_OreburghMine_Text_NPC4Speaker:
	.string "Rolycoly$"

OreburghCity_OreburghMine_EventScript_NPC5::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_GRAVELER, CRY_MODE_NORMAL
	setspeaker OreburghCity_OreburghMine_Text_NPC5Speaker
	msgbox OreburghCity_OreburghMine_Text_NPC5, MSGBOX_DEFAULT
	waitmoncry
	release
	end

OreburghCity_OreburghMine_Text_NPC5:
	.string "OREBURGH MINE NPC 5$"

OreburghCity_OreburghMine_Text_NPC5Speaker:
	.string "Graveler$"
