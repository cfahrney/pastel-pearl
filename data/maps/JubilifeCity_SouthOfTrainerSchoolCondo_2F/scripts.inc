JubilifeCity_SouthOfTrainerSchoolCondo_2F_MapScripts::
	.byte 0

JubilifeCity_SouthOfTrainerSchoolCondo_2F_EventScript_NPC1::
	msgbox JubilifeCity_SouthOfTrainerSchoolCondo_2F_Text_NPC1, MSGBOX_NPC
	end

JubilifeCity_SouthOfTrainerSchoolCondo_2F_EventScript_NPC2::
	msgbox JubilifeCity_SouthOfTrainerSchoolCondo_2F_Text_NPC2, MSGBOX_NPC
	end

JubilifeCity_SouthOfTrainerSchoolCondo_2F_EventScript_NPC3::
	msgbox JubilifeCity_SouthOfTrainerSchoolCondo_2F_Text_NPC3, MSGBOX_NPC
	end

JubilifeCity_SouthOfTrainerSchoolCondo_2F_EventScript_NPC4::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ROSELIA, CRY_MODE_NORMAL
	setspeaker JubilifeCity_SouthOfTrainerSchoolCondo_2F_Text_NPC4Speaker
	msgbox JubilifeCity_SouthOfTrainerSchoolCondo_2F_Text_NPC4, MSGBOX_DEFAULT
	waitmoncry
	release
	end

JubilifeCity_SouthOfTrainerSchoolCondo_2F_Text_NPC1:
	.string "HIGH RISE 2F NPC 1$"

JubilifeCity_SouthOfTrainerSchoolCondo_2F_Text_NPC2:
	.string "HIGH RISE 2F NPC 2$"

JubilifeCity_SouthOfTrainerSchoolCondo_2F_Text_NPC3:
	.string "HIGH RISE 2F NPC 3$"

JubilifeCity_SouthOfTrainerSchoolCondo_2F_Text_NPC4:
	.string "HIGH RISE 2F NPC 4$"

JubilifeCity_SouthOfTrainerSchoolCondo_2F_Text_NPC4Speaker:
	.string "Roselia$"
