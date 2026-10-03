SandgemTown_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SandgemTown_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

SandgemTown_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_SANDGEM_TOWN
	end

SandgemTown_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_SANDGEM_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	applymovement LOCALID_PLAYER, Common_Movement_FaceDown
	waitmovement 0
	release
	end

SandgemTown_PokemonCenter_1F_EventScript_NPC1::
	msgbox SandgemTown_PokemonCenter_1F_Text_NPC1, MSGBOX_NPC
	end

SandgemTown_PokemonCenter_1F_EventScript_NPC2::
	msgbox SandgemTown_PokemonCenter_1F_Text_NPC2, MSGBOX_NPC
	end

SandgemTown_PokemonCenter_1F_EventScript_NPC3::
	msgbox SandgemTown_PokemonCenter_1F_Text_NPC3, MSGBOX_NPC
	end

SandgemTown_PokemonCenter_1F_Text_NPC1:
	.string "Talk to the nice lady at the counter\n"
	.string "and hand her your Pokémon.\p"
	.string "She'll heal your Pokémon to perfect\n"
	.string "health in no time at all!$"

SandgemTown_PokemonCenter_1F_Text_NPC2:
	.string "There's not much to do in Sandgem Town,\n"
	.string "so I hang out in the Pokémon Center to\l"
	.string "see all the Pokémon people have.\p"
	.string "Yours is super cute!$"

SandgemTown_PokemonCenter_1F_Text_NPC3:
	.string "Do you see that PC over there?\p"
	.string "The fancy blue one?\p"
	.string "If you've got a Pokémon with you, it's\n"
	.string "free to use. s$"
