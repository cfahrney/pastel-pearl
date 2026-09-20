OreburghCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, OreburghCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

OreburghCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_OREBURGH_CITY
	end

OreburghCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_OREBURGH_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	applymovement LOCALID_PLAYER, Common_Movement_FaceDown
	waitmovement 0
	release
	end

OreburghCity_PokemonCenter_1F_EventScript_NPC1::
	msgbox OreburghCity_PokemonCenter_1F_Text_NPC1, MSGBOX_NPC
	end

OreburghCity_PokemonCenter_1F_EventScript_NPC2::
	msgbox OreburghCity_PokemonCenter_1F_Text_NPC2, MSGBOX_NPC
	end

OreburghCity_PokemonCenter_1F_Text_NPC1:
	.string "POKEMON CENTER 1F NPC 1$"

OreburghCity_PokemonCenter_1F_Text_NPC2:
	.string "POKEMON CENTER 1F NPC 2$"
