EternaCity_GalacticBuilding_1F_MapScripts::
	.byte 0

EternaCity_GalacticBuilding_1F_EventScript_Trainer1::
	trainerbattle_single TRAINER_ETERNA_CITY_GALACTIC_BUILDING_1F_1, EternaCity_GalacticBuilding_1F_Text_Trainer1Intro, EternaCity_GalacticBuilding_1F_Text_Trainer1Defeated
	msgbox EternaCity_GalacticBuilding_1F_Text_Trainer1PostBattle, MSGBOX_AUTOCLOSE
	end

EternaCity_GalacticBuilding_1F_Text_Trainer1Intro:
	.string "Sorry, deary! Team Galactic doesn't\n"
	.string "accept children as members!$"

EternaCity_GalacticBuilding_1F_Text_Trainer1Defeated:
	.string "B-but, deary, you're just a kid!$"

EternaCity_GalacticBuilding_1F_Text_Trainer1PostBattle:
	.string "You wanted to go up? Well, why didn't\n"
	.string "you?$"

EternaCity_GalacticBuilding_1F_EventScript_Trainer2::
	trainerbattle_single TRAINER_ETERNA_CITY_GALACTIC_BUILDING_1F_2, EternaCity_GalacticBuilding_1F_Text_Trainer2Intro, EternaCity_GalacticBuilding_1F_Text_Trainer2Defeated
	msgbox EternaCity_GalacticBuilding_1F_Text_Trainer2PostBattle, MSGBOX_AUTOCLOSE
	end

EternaCity_GalacticBuilding_1F_Text_Trainer2Intro:
	.string "We are gathering Pokémon for an\n"
	.string "astonishing undertaking!\p"
	.string "Your meddling won't be tolerated!$"

EternaCity_GalacticBuilding_1F_Text_Trainer2Defeated:
	.string "I feel like I got meddled with...$"

EternaCity_GalacticBuilding_1F_Text_Trainer2PostBattle:
	.string "Our astonishing undertaking is most\n"
	.string "certainly breathtaking.\p"
	.string "If you ever hope to see its glorious\n"
	.string "unveiling, then don't meddle with us!$"

EternaCity_GalacticBuilding_1F_EventScript_NPC2::
	@ poe:behavior {"mode":"plain","options":[{"id":0,"text":"EternaCity_GalacticBuilding_1F_Text_NPC2_2"}]}
	msgbox EternaCity_GalacticBuilding_1F_Text_NPC2_2, MSGBOX_NPC
	end

EternaCity_GalacticBuilding_1F_EventScript_NPC1::
	@ poe:behavior {"mode":"plain","options":[{"id":0,"text":"EternaCity_GalacticBuilding_1F_Text_NPC1_2"}]}
	msgbox EternaCity_GalacticBuilding_1F_Text_NPC1_2, MSGBOX_NPC
	end

EternaCity_GalacticBuilding_1F_Text_NPC2_2:
	.string "Welcome to Team Galactic. Are you here\n"
	.string "to donate your Pokémon?\p"
	.string "What? You're not? Then kindly get off\n"
	.string "our property!\p"
	.string "Do we have to bring the pain like we did\n"
	.string "with the Cycle Shop manager?$"

EternaCity_GalacticBuilding_1F_Text_NPC1_2:
	.string "Team Galactic isn't interested in the\n"
	.string "world. Our gaze is beyond the stars!$"
