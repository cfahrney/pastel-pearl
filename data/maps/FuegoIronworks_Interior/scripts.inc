FuegoIronworks_Interior_MapScripts::
	.byte 0

FuegoIronworks_Interior_EventScript_Trainer1::
	trainerbattle_single TRAINER_FUEGO_IRONWORKS_INTERIOR_1, FuegoIronworks_Interior_Text_Trainer1Intro, FuegoIronworks_Interior_Text_Trainer1Defeated
	msgbox FuegoIronworks_Interior_Text_Trainer1PostBattle, MSGBOX_AUTOCLOSE
	end

FuegoIronworks_Interior_Text_Trainer1Intro:
	.string "Well! It's not often we get a visitor\n"
	.string "like you to the ironworks!\p"
	.string "Let's mark the occasion with a battle!$"

FuegoIronworks_Interior_Text_Trainer1Defeated:
	.string "Fire!$"

FuegoIronworks_Interior_Text_Trainer1PostBattle:
	.string "The floor panels move automatically.\n"
	.string "We're pretty proud of them here!$"

FuegoIronworks_Interior_EventScript_Trainer2::
	trainerbattle_single TRAINER_FUEGO_IRONWORKS_INTERIOR_2, FuegoIronworks_Interior_Text_Trainer2Intro, FuegoIronworks_Interior_Text_Trainer2Defeated
	msgbox FuegoIronworks_Interior_Text_Trainer2PostBattle, MSGBOX_AUTOCLOSE
	end

FuegoIronworks_Interior_Text_Trainer2Intro:
	.string "I work at a red-hot foundry. Watch out,\n"
	.string "I'm on fire!$"

FuegoIronworks_Interior_Text_Trainer2Defeated:
	.string "I burned out...$"

FuegoIronworks_Interior_Text_Trainer2PostBattle:
	.string "I toughened up my muscles from honest\n"
	.string "work.\p"
	.string "Pokémon have nothing on me!$"

FuegoIronworks_Interior_EventScript_NPC1::
	msgbox FuegoIronworks_Interior_Text_NPC1, MSGBOX_NPC
	end

FuegoIronworks_Interior_Text_NPC1:
	.string "Mr. Fuego: Well, hello! It's not often I\n"
	.string "get a visitor here.\p"
	.string "I tried to make the ironworks run\n"
	.string "better with the moving floor tiles.\p"
	.string "But no one was happy about it! They\n"
	.string "said the moving floor made them dizzy!\p"
	.string "But you don't want to listen to me\n"
	.string "whine. Here's a souvenir!$"

FuegoIronworks_Interior_EventScript_Trainer3::
	trainerbattle_single TRAINER_FUEGO_IRONWORKS_INTERIOR_3, FuegoIronworks_Interior_Text_Trainer3Intro, FuegoIronworks_Interior_Text_Trainer3Defeated
	msgbox FuegoIronworks_Interior_Text_Trainer3PostBattle, MSGBOX_AUTOCLOSE
	end

FuegoIronworks_Interior_Text_Trainer3Intro:
	.string "Are you maybe getting annoyed by where\n"
	.string "the floor panels take you?$"

FuegoIronworks_Interior_Text_Trainer3Defeated:
	.string "I'm going down in flames!$"

FuegoIronworks_Interior_Text_Trainer3PostBattle:
	.string "The sweat of a working man is beautiful\n"
	.string "to behold...\p"
	.string "There is also beauty in the tears wept\n"
	.string "from defeat...$"
