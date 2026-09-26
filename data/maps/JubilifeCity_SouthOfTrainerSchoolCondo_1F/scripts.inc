JubilifeCity_SouthOfTrainerSchoolCondo_1F_MapScripts::
	.byte 0

JubilifeCity_SouthOfTrainerSchoolCondo_1F_EventScript_NPC1::
	msgbox JubilifeCity_SouthOfTrainerSchoolCondo_1F_Text_NPC1, MSGBOX_NPC
	end

JubilifeCity_SouthOfTrainerSchoolCondo_1F_EventScript_NPC2::
	msgbox JubilifeCity_SouthOfTrainerSchoolCondo_1F_Text_NPC2, MSGBOX_NPC
	end

JubilifeCity_SouthOfTrainerSchoolCondo_1F_EventScript_NPC3::
	msgbox JubilifeCity_SouthOfTrainerSchoolCondo_1F_Text_NPC3, MSGBOX_NPC
	end

JubilifeCity_SouthOfTrainerSchoolCondo_1F_EventScript_NPC4::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SENTRET, CRY_MODE_NORMAL
	setspeaker JubilifeCity_SouthOfTrainerSchoolCondo_1F_Text_NPC4Speaker
	msgbox JubilifeCity_SouthOfTrainerSchoolCondo_1F_Text_NPC4, MSGBOX_DEFAULT
	waitmoncry
	release
	end

JubilifeCity_SouthOfTrainerSchoolCondo_1F_EventScript_NPC5::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_CLEFFA, CRY_MODE_NORMAL
	setspeaker JubilifeCity_SouthOfTrainerSchoolCondo_1F_Text_NPC5Speaker
	msgbox JubilifeCity_SouthOfTrainerSchoolCondo_1F_Text_NPC5, MSGBOX_DEFAULT
	waitmoncry
	release
	end

JubilifeCity_SouthOfTrainerSchoolCondo_1F_Text_NPC1:
	.string "HIGH RISE 1F NPC 1$"

JubilifeCity_SouthOfTrainerSchoolCondo_1F_Text_NPC2:
	.string "HIGH RISE 1F NPC 2$"

JubilifeCity_SouthOfTrainerSchoolCondo_1F_Text_NPC3:
	.string "HIGH RISE 1F NPC 3$"

JubilifeCity_SouthOfTrainerSchoolCondo_1F_Text_NPC4:
	.string "HIGH RISE 1F NPC 4$"

JubilifeCity_SouthOfTrainerSchoolCondo_1F_Text_NPC4Speaker:
	.string "Sentret$"

JubilifeCity_SouthOfTrainerSchoolCondo_1F_Text_NPC5:
	.string "HIGH RISE 1F NPC 5$"

JubilifeCity_SouthOfTrainerSchoolCondo_1F_Text_NPC5Speaker:
	.string "Cleffa$"
