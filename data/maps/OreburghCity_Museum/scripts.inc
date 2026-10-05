OreburghCity_Museum_MapScripts::
	.byte 0

OreburghCity_Museum_EventScript_NPC1::
	msgbox OreburghCity_Museum_Text_NPC1, MSGBOX_NPC
	end

OreburghCity_Museum_EventScript_NPC2::
	msgbox OreburghCity_Museum_Text_NPC2, MSGBOX_NPC
	end

OreburghCity_Museum_EventScript_NPC3::
	msgbox OreburghCity_Museum_Text_NPC3, MSGBOX_NPC
	end

OreburghCity_Museum_EventScript_NPC4::
	msgbox OreburghCity_Museum_Text_NPC4, MSGBOX_NPC
	end

OreburghCity_Museum_EventScript_NPC5::
	msgbox OreburghCity_Museum_Text_NPC5, MSGBOX_NPC
	end

OreburghCity_Museum_EventScript_NPC6::
	msgbox OreburghCity_Museum_Text_NPC6, MSGBOX_NPC
	end

OreburghCity_Museum_EventScript_NPC7::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MIME_JR, CRY_MODE_NORMAL
	setspeaker OreburghCity_Museum_Text_NPC7Speaker
	msgbox OreburghCity_Museum_Text_NPC7, MSGBOX_DEFAULT
	waitmoncry
	release
	end

OreburghCity_Museum_EventScript_NPC8::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SHIELDON, CRY_MODE_NORMAL
	setspeaker OreburghCity_Museum_Text_NPC8Speaker
	msgbox OreburghCity_Museum_Text_NPC8, MSGBOX_DEFAULT
	waitmoncry
	release
	end

OreburghCity_Museum_Text_NPC1:
	.string "Welcome in!$"

OreburghCity_Museum_Text_NPC2:
	.string "Welcome, welcome! This is the {COLOR DYNAMIC_COLOR3}Oreburgh\n"
	.string "Mining Museum{COLOR DARK_GRAY}. Though, if I'm being\l"
	.string "honest, my true passion is in fossils. My\l"
	.string "Shieldsy here and I can't get enough,\l"
	.string "hah!\p"
	.string "Er-hem. Sorry. The Mining Museum covers\n"
	.string "much of {COLOR DYNAMIC_COLOR3}Oreburgh{COLOR DARK_GRAY}'s history. Please\l"
	.string "enjoy!$"

OreburghCity_Museum_Text_NPC3:
	.string "Wow, this is so cool. Simply amazed.$"

OreburghCity_Museum_Text_NPC4:
	.string "I don't think they've installed this\n"
	.string "exhibit yet...$"

OreburghCity_Museum_Text_NPC5:
	.string "Mime Jr. Loves the museum. We come here\n"
	.string "at least once a week!$"

OreburghCity_Museum_Text_NPC6:
	.string "I thought they'd have, like, an\n"
	.string "Aerodactyl here or something. Am I\l"
	.string "crazy? Whatever.$"

OreburghCity_Museum_Text_NPC7:
	.string "Mime mime!$"

OreburghCity_Museum_Text_NPC7Speaker:
	.string "Mime Jr.$"

OreburghCity_Museum_Text_NPC8:
	.string "Sheild?$"

OreburghCity_Museum_Text_NPC8Speaker:
	.string "Shieldon$"
