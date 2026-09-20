JubilifeCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, JubilifeCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

JubilifeCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_JUBILIFE_CITY
	end

JubilifeCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_JUBILIFE_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	applymovement LOCALID_PLAYER, Common_Movement_FaceDown
	waitmovement 0
	release
	end

JubilifeCity_PokemonCenter_1F_EventScript_NPC1::
	msgbox JubilifeCity_PokemonCenter_1F_Text_NPC1, MSGBOX_NPC
	end

JubilifeCity_PokemonCenter_1F_EventScript_NPC2::
	msgbox JubilifeCity_PokemonCenter_1F_Text_NPC2, MSGBOX_NPC
	end

JubilifeCity_PokemonCenter_1F_EventScript_NPC3::
	msgbox JubilifeCity_PokemonCenter_1F_Text_NPC3, MSGBOX_NPC
	end

JubilifeCity_PokemonCenter_1F_Text_NPC1:
	.string "POKEMON CENTER 1F NPC 1$"

JubilifeCity_PokemonCenter_1F_Text_NPC2:
	.string "POKEMON CENTER 1F NPC 2$"

JubilifeCity_PokemonCenter_1F_Text_NPC3:
	.string "POKEMON CENTER 1F NPC 3$"
