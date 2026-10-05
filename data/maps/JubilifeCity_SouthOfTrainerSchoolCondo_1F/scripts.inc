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
	playmoncry SPECIES_AMBIPOM, CRY_MODE_NORMAL
	setspeaker JubilifeCity_SouthOfTrainerSchoolCondo_1F_Text_NPC4Speaker
	msgbox JubilifeCity_SouthOfTrainerSchoolCondo_1F_Text_NPC4, MSGBOX_DEFAULT
	waitmoncry
	release
	end

JubilifeCity_SouthOfTrainerSchoolCondo_1F_EventScript_NPC5::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_CHATOT, CRY_MODE_NORMAL
	setspeaker JubilifeCity_SouthOfTrainerSchoolCondo_1F_Text_NPC5Speaker
	msgbox JubilifeCity_SouthOfTrainerSchoolCondo_1F_Text_NPC5, MSGBOX_DEFAULT
	waitmoncry
	release
	end

JubilifeCity_SouthOfTrainerSchoolCondo_1F_Text_NPC1:
	.string "Hello there, Trainer!\p"
	.string "If you get stumped and don't know what\n"
	.string "to do...\p"
	.string "Talk to people!\n"
	.string "Talk to everyone you see!\p"
	.string "Go places!\n"
	.string "Go wherever you can!\p"
	.string "You'll find many new places by doing\n"
	.string "just that.$"

JubilifeCity_SouthOfTrainerSchoolCondo_1F_Text_NPC2:
	.string "Pokémon are wonderful, deeply\n"
	.string "mysterious creatures.\p"
	.string "But to Trainers, it seems the only thing\n"
	.string "that matters is battling!$"

JubilifeCity_SouthOfTrainerSchoolCondo_1F_Text_NPC3:
	.string "Did you know?\p"
	.string "Your {COLOR DYNAMIC_COLOR3}Pokédex{COLOR DARK_GRAY} can tell you all sorts of\n"
	.string "information about a Pokémon's\l"
	.string "evolutions.$"

JubilifeCity_SouthOfTrainerSchoolCondo_1F_Text_NPC4:
	.string "Aaaambi.$"

JubilifeCity_SouthOfTrainerSchoolCondo_1F_Text_NPC4Speaker:
	.string "Ambipom$"

JubilifeCity_SouthOfTrainerSchoolCondo_1F_Text_NPC5:
	.string "Tot! Tot tot!$"

JubilifeCity_SouthOfTrainerSchoolCondo_1F_Text_NPC5Speaker:
	.string "Chatot$"
