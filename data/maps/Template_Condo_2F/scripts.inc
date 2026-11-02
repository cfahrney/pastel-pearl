Template_Condo_2F_MapScripts::
	.byte 0

Template_Condo_2F_EventScript_NPC1::
	msgbox Template_Condo_2F_Text_NPC1, MSGBOX_NPC
	end

Template_Condo_2F_EventScript_NPC2::
	msgbox Template_Condo_2F_Text_NPC2, MSGBOX_NPC
	end

Template_Condo_2F_EventScript_NPC3::
	msgbox Template_Condo_2F_Text_NPC3, MSGBOX_NPC
	end

Template_Condo_2F_EventScript_NPC4::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ROSELIA, CRY_MODE_NORMAL
	setspeaker Template_Condo_2F_Text_NPC4Speaker
	msgbox Template_Condo_2F_Text_NPC4, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Template_Condo_2F_Text_NPC1:
	.string "Condo 2F NPC 1$"

Template_Condo_2F_Text_NPC2:
	.string "Condo 2F NPC 2$"

Template_Condo_2F_Text_NPC3:
	.string "Condo 2F NPC 3$"

Template_Condo_2F_Text_NPC4:
	.string "Condo 2F NPC 4$"

Template_Condo_2F_Text_NPC4Speaker:
	.string "Roselia$"
