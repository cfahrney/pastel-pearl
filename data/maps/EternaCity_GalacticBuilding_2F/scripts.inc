EternaCity_GalacticBuilding_2F_MapScripts::
	.byte 0

EternaCity_GalacticBuilding_2F_EventScript_Trainer1::
	trainerbattle_single TRAINER_ETERNA_CITY_GALACTIC_BUILDING_2F_1, EternaCity_GalacticBuilding_2F_Text_Trainer1Intro, EternaCity_GalacticBuilding_2F_Text_Trainer1Defeated
	msgbox EternaCity_GalacticBuilding_2F_Text_Trainer1PostBattle, MSGBOX_AUTOCLOSE
	end

EternaCity_GalacticBuilding_2F_Text_Trainer1Intro:
	.string "Our objectives are incredible! Too\n"
	.string "incredible for me to understand!\p"
	.string "I'll fight blindly to defend them, and\n"
	.string "your intrusion won't be forgiven!$"

EternaCity_GalacticBuilding_2F_Text_Trainer1Defeated:
	.string "What was I fighting for, again?$"

EternaCity_GalacticBuilding_2F_Text_Trainer1PostBattle:
	.string "What do you have against taking\n"
	.string "Pokémon from others?\p"
	.string "Look in any field or forest! Those\n"
	.string "things aren't exactly rare!$"

EternaCity_GalacticBuilding_2F_EventScript_Trainer2::
	trainerbattle_single TRAINER_ETERNA_CITY_GALACTIC_BUILDING_2F_2, EternaCity_GalacticBuilding_2F_Text_Trainer2Intro, EternaCity_GalacticBuilding_2F_Text_Trainer2Defeated
	msgbox EternaCity_GalacticBuilding_2F_Text_Trainer2PostBattle, MSGBOX_AUTOCLOSE
	end

EternaCity_GalacticBuilding_2F_Text_Trainer2Intro:
	.string "Let's see how good this Pokémon is! I\n"
	.string "stole it from some weak Trainer.$"

EternaCity_GalacticBuilding_2F_Text_Trainer2Defeated:
	.string "What is this?!$"

EternaCity_GalacticBuilding_2F_Text_Trainer2PostBattle:
	.string "Wimpy little Pokémon...\p"
	.string "When I get promoted, I'll demand better\n"
	.string "stolen Pokémon.$"

EternaCity_GalacticBuilding_2F_EventScript_NPC1::
	msgbox EternaCity_GalacticBuilding_2F_Text_NPC1_2, MSGBOX_NPC
	end

EternaCity_GalacticBuilding_2F_Text_NPC1_2:
	.string "Team Galactic is working hard to find\n"
	.string "new energy sources for the future!$"

EternaCity_GalacticBuilding_2F_EventScript_NPC2::
	msgbox EternaCity_GalacticBuilding_2F_Text_NPC2, MSGBOX_NPC
	end

EternaCity_GalacticBuilding_2F_Text_NPC2:
	.string "We are conducting research on new\n"
	.string "forms of energy!\p"
	.string "We want to harness the mysterious\n"
	.string "power of Pokémon and use it as energy!$"
