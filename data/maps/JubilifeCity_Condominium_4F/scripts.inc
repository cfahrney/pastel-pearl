JubilifeCity_Condominium_4F_MapScripts::
	.byte 0

JubilifeCity_Condominium_4F_EventScript_NPC1::
	msgbox JubilifeCity_Condominium_4F_Text_NPC1, MSGBOX_NPC
	end

JubilifeCity_Condominium_4F_EventScript_NPC3::
	msgbox JubilifeCity_Condominium_4F_Text_NPC3, MSGBOX_NPC
	end

JubilifeCity_Condominium_4F_Text_NPC1:
	.string "CONDOMINIUM 4F NPC 1$"

JubilifeCity_Condominium_4F_Text_NPC3:
	.string "CONDOMINIUM 4F NPC 3$"

JubilifeCity_Condominium_4F_EventScript_NPC2::
	lock
	faceplayer
	goto_if_set FLAG_JUBILIFE_CITY_CONDOMINIUM_4F_WOMAN_1, JubilifeCity_Condominium_4F_EventScript_NPC2_2
	msgbox JubilifeCity_Condominium_4F_Text_NPC2_2, MSGBOX_DEFAULT
	setvar VAR_0x8004, ITEM_FOCUS_BAND
	setvar VAR_0x8005, 1
	checkitemspace VAR_0x8004, VAR_0x8005
	goto_if_eq VAR_RESULT, FALSE, JubilifeCity_Condominium_4F_EventScript_NPC2_2_2
	setflag FLAG_JUBILIFE_CITY_CONDOMINIUM_4F_WOMAN_1
	giveitem VAR_0x8004, VAR_0x8005
	closemessage
	release
	end

JubilifeCity_Condominium_4F_EventScript_NPC2_2::
	msgbox JubilifeCity_Condominium_4F_Text_NPC2_3, MSGBOX_DEFAULT
	closemessage
	release
	end

JubilifeCity_Condominium_4F_EventScript_NPC2_2_2::
	msgbox gText_TooBadBagIsFull, MSGBOX_DEFAULT
	closemessage
	release
	end

JubilifeCity_Condominium_4F_Text_NPC2_2:
	.string "You managed to come out here? That\n"
	.string "takes focus!\p"
	.string "For someone like you, this {STR_VAR_1}\n"
	.string "might be perfect.\p"
	.string "Let a Pokémon hold it, yah?$"

JubilifeCity_Condominium_4F_Text_NPC2_3:
	.string "There are items that are useful only\n"
	.string "when they're held by Pokémon.\p"
	.string "Try finding other items like that and\n"
	.string "spice up your adventure!$"
