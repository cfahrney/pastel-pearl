JubilifeCity_SouthOfBattleDomeCondo_2F_MapScripts::
	.byte 0

JubilifeCity_SouthOfBattleDomeCondo_2F_EventScript_NPC1::
	msgbox JubilifeCity_SouthOfBattleDomeCondo_2F_Text_NPC1, MSGBOX_NPC
	end

JubilifeCity_SouthOfBattleDomeCondo_2F_EventScript_NPC2::
	msgbox JubilifeCity_SouthOfBattleDomeCondo_2F_Text_NPC2, MSGBOX_NPC
	end

JubilifeCity_SouthOfBattleDomeCondo_2F_EventScript_NPC3::
	msgbox JubilifeCity_SouthOfBattleDomeCondo_2F_Text_NPC3, MSGBOX_NPC
	end

JubilifeCity_SouthOfBattleDomeCondo_2F_EventScript_NPC4::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_FLAAFFY, CRY_MODE_NORMAL
	setspeaker JubilifeCity_SouthOfBattleDomeCondo_2F_Text_NPC4Speaker
	msgbox JubilifeCity_SouthOfBattleDomeCondo_2F_Text_NPC4, MSGBOX_DEFAULT
	waitmoncry
	release
	end

JubilifeCity_SouthOfBattleDomeCondo_2F_Text_NPC1:
	.string "I come from {COLOR DYNAMIC_COLOR3}Johto{COLOR DARK_GRAY}! I'm here to see the\n"
	.string "Pokémon I traded to my friend here.$"

JubilifeCity_SouthOfBattleDomeCondo_2F_Text_NPC2:
	.string "If everyone around the world had\n"
	.string "Pokémon...\p"
	.string "Then everyone around the world could\n"
	.string "communicate!$"

JubilifeCity_SouthOfBattleDomeCondo_2F_Text_NPC3:
	.string "I love to look at the Pokémon I got from\n"
	.string "a friend in trade. It makes me think of\l"
	.string "my friend!$"

JubilifeCity_SouthOfBattleDomeCondo_2F_Text_NPC4:
	.string "Flaaaffy!$"

JubilifeCity_SouthOfBattleDomeCondo_2F_Text_NPC4Speaker:
	.string "Flaaffy$"
