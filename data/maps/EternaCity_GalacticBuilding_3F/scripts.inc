EternaCity_GalacticBuilding_3F_MapScripts::
	.byte 0

EternaCity_GalacticBuilding_3F_EventScript_Trainer1::
	trainerbattle_single TRAINER_ETERNA_CITY_GALACTIC_BUILDING_3F_1, EternaCity_GalacticBuilding_3F_Text_Trainer1Intro, EternaCity_GalacticBuilding_3F_Text_Trainer1Defeated
	msgbox EternaCity_GalacticBuilding_3F_Text_Trainer1PostBattle, MSGBOX_AUTOCLOSE
	end

EternaCity_GalacticBuilding_3F_Text_Trainer1Intro:
	.string "Why, thank you!\p"
	.string "We love it when people come to us to\n"
	.string "donate their Pokémon!$"

EternaCity_GalacticBuilding_3F_Text_Trainer1Defeated:
	.string "What do you think you're doing?!$"

EternaCity_GalacticBuilding_3F_Text_Trainer1PostBattle:
	.string "You can catch Pokémon anywhere. What's\n"
	.string "so special about them?\p"
	.string "Trainers that lose theirs should quit\n"
	.string "whining and catch some more!$"

EternaCity_GalacticBuilding_3F_EventScript_Trainer2::
	trainerbattle_single TRAINER_ETERNA_CITY_GALACTIC_BUILDING_3F_2, EternaCity_GalacticBuilding_3F_Text_Trainer2Intro, EternaCity_GalacticBuilding_3F_Text_Trainer2Defeated
	msgbox EternaCity_GalacticBuilding_3F_Text_Trainer2PostBattle, MSGBOX_AUTOCLOSE
	end

EternaCity_GalacticBuilding_3F_Text_Trainer2Intro:
	.string "Our mission is to implement our\n"
	.string "operations without question.\p"
	.string "It is all for the new world order that\n"
	.string "our boss will lead!$"

EternaCity_GalacticBuilding_3F_Text_Trainer2Defeated:
	.string "This won't go unpunished...$"

EternaCity_GalacticBuilding_3F_Text_Trainer2PostBattle:
	.string "I'm quite prepared to do anything to be\n"
	.string "promoted.\p"
	.string "One day, and soon, you will learn the\n"
	.string "true might of Team Galactic!$"

EternaCity_GalacticBuilding_3F_EventScript_NPC1::
	@ poe:behavior {"mode":"plain","options":[{"id":0,"text":"EternaCity_GalacticBuilding_3F_Text_NPC1_2"}]}
	msgbox EternaCity_GalacticBuilding_3F_Text_NPC1_2, MSGBOX_NPC
	end

EternaCity_GalacticBuilding_3F_Text_NPC1_2:
	.string "Ordinary people like you can't\n"
	.string "understand Team Galactic's grand\l"
	.string "designs!\p"
	.string "Come to think of it... I don't even know\n"
	.string "what's going on...$"
