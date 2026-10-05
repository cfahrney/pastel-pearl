JubilifeCity_SouthOfTrainerSchoolCondo_2F_MapScripts::
	.byte 0

JubilifeCity_SouthOfTrainerSchoolCondo_2F_EventScript_NPC1::
	msgbox JubilifeCity_SouthOfTrainerSchoolCondo_2F_Text_NPC1, MSGBOX_NPC
	end

JubilifeCity_SouthOfTrainerSchoolCondo_2F_EventScript_NPC2::
	@ poe:behavior {"mode":"gift","item":"ITEM_SILK_SCARF","qty":1}
	lock
	faceplayer
	goto_if_set FLAG_JUBILIFECITY_SOUTHOFTRAINERSCHOOLCONDO_2F_NPC2_GIFT, JubilifeCity_SouthOfTrainerSchoolCondo_2F_EventScript_NPC2After
	msgbox JubilifeCity_SouthOfTrainerSchoolCondo_2F_Text_NPC2, MSGBOX_DEFAULT
	giveitem ITEM_SILK_SCARF, 1
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_JUBILIFECITY_SOUTHOFTRAINERSCHOOLCONDO_2F_NPC2_GIFT
	msgbox JubilifeCity_SouthOfTrainerSchoolCondo_2F_Text_NPC2Received, MSGBOX_DEFAULT
	release
	end

JubilifeCity_SouthOfTrainerSchoolCondo_2F_EventScript_NPC2After::
	msgbox JubilifeCity_SouthOfTrainerSchoolCondo_2F_Text_NPC2After, MSGBOX_DEFAULT
	release
	end

JubilifeCity_SouthOfTrainerSchoolCondo_2F_Text_NPC2Received::
	.string "I mean, I bet it would look cute on one\n"
	.string "of your Pokémon too, to be clear.$"

JubilifeCity_SouthOfTrainerSchoolCondo_2F_Text_NPC2After::
	.string "I mean, I bet it would look cute on one\n"
	.string "of your Pokémon too, to be clear.$"

JubilifeCity_SouthOfTrainerSchoolCondo_2F_EventScript_NPC3::
	msgbox JubilifeCity_SouthOfTrainerSchoolCondo_2F_Text_NPC3, MSGBOX_NPC
	end

JubilifeCity_SouthOfTrainerSchoolCondo_2F_EventScript_NPC4::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_BUNEARY, CRY_MODE_NORMAL
	setspeaker JubilifeCity_SouthOfTrainerSchoolCondo_2F_Text_NPC4Speaker
	msgbox JubilifeCity_SouthOfTrainerSchoolCondo_2F_Text_NPC4, MSGBOX_DEFAULT
	waitmoncry
	release
	end

JubilifeCity_SouthOfTrainerSchoolCondo_2F_Text_NPC1:
	.string "I work over in {COLOR DYNAMIC_COLOR3}Oreburgh City{COLOR DARK_GRAY}. The\n"
	.string "commute isn't the worst, but I hate\l"
	.string "going through {COLOR DYNAMIC_COLOR3}Oreburgh Gate{COLOR DARK_GRAY}. Those\l"
	.string "dang Zubats are just all over the\l"
	.string "place...$"

JubilifeCity_SouthOfTrainerSchoolCondo_2F_Text_NPC2:
	.string "Don't you think this would look so cute\n"
	.string "on that Buneary over there?$"

JubilifeCity_SouthOfTrainerSchoolCondo_2F_Text_NPC3:
	.string "Evolution makes Pokémon just that much\n"
	.string "more fascinating, don't you think?\l"
	.string "Especially since the discovery of Mega\l"
	.string "Evolution!$"

JubilifeCity_SouthOfTrainerSchoolCondo_2F_Text_NPC4:
	.string "Buneeeary!$"

JubilifeCity_SouthOfTrainerSchoolCondo_2F_Text_NPC4Speaker:
	.string "Buneary$"
