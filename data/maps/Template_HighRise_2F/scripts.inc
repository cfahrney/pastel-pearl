Template_HighRise_2F_MapScripts::
	.byte 0

Template_HighRise_2F_EventScript_NPC1::
	msgbox Template_HighRise_2F_Text_NPC1, MSGBOX_NPC
	end

Template_HighRise_2F_EventScript_NPC2::
	msgbox Template_HighRise_2F_Text_NPC2, MSGBOX_NPC
	end

Template_HighRise_2F_EventScript_NPC3::
	msgbox Template_HighRise_2F_Text_NPC3, MSGBOX_NPC
	end

Template_HighRise_2F_EventScript_NPC4::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ROSELIA, CRY_MODE_NORMAL
	setspeaker Template_HighRise_2F_Text_NPC4Speaker
	msgbox Template_HighRise_2F_Text_NPC4, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Template_HighRise_2F_Text_NPC1:
	.string "HIGH RISE 2F NPC 1$"

Template_HighRise_2F_Text_NPC2:
	.string "HIGH RISE 2F NPC 2$"

Template_HighRise_2F_Text_NPC3:
	.string "HIGH RISE 2F NPC 3$"

Template_HighRise_2F_Text_NPC4:
	.string "HIGH RISE 2F NPC 4$"

Template_HighRise_2F_Text_NPC4Speaker:
	.string "Roselia$"
