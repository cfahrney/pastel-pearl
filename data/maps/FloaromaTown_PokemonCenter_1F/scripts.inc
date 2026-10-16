FloaromaTown_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FloaromaTown_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

FloaromaTown_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_FLOAROMA_TOWN
	end

FloaromaTown_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_FLOAROMA_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	applymovement LOCALID_PLAYER, Common_Movement_FaceDown
	waitmovement 0
	release
	end

FloaromaTown_PokemonCenter_1F_EventScript_NPC1::
	msgbox FloaromaTown_PokemonCenter_1F_Text_NPC1, MSGBOX_NPC
	end

FloaromaTown_PokemonCenter_1F_Text_NPC1:
	.string "If you've got Pokémon with you, it's\n"
	.string "safe for even a kid like you\p"
	.string "to go off traveling alone.$"

FloaromaTown_PokemonCenter_1F_EventScript_NPC2::
	msgbox FloaromaTown_PokemonCenter_1F_Text_NPC2, MSGBOX_NPC
	end

FloaromaTown_PokemonCenter_1F_Text_NPC2:
	.string "I had a battle the other day, and my\n"
	.string "Pokémon's HP got low, and I thought we\l"
	.string "were done for, and then, all of a sudden,\l"
	.string "my Pokémon ate the Berry it was\l"
	.string "holding! Whew!$"
