CanalaveCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CanalaveCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

CanalaveCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_CANALAVE_CITY
	end

CanalaveCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_CANALAVE_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	applymovement LOCALID_PLAYER, Common_Movement_FaceDown
	waitmovement 0
	release
	end

CanalaveCity_PokemonCenter_1F_EventScript_NPC2::
	msgbox CanalaveCity_PokemonCenter_1F_Text_NPC2_2, MSGBOX_NPC
	end

CanalaveCity_PokemonCenter_1F_EventScript_NPC1::
	msgbox CanalaveCity_PokemonCenter_1F_Text_NPC1_2, MSGBOX_NPC
	end

CanalaveCity_PokemonCenter_1F_Text_NPC2_2:
	.string "I can't use the hidden move Strength\n"
	.string "until I beat Byron, the Gym Leader.\p"
	.string "I already got the Strength HM from the\n"
	.string "Lost Tower on {COLOR DYNAMIC_COLOR3}Route 209{COLOR DARK_GRAY}, also...$"

CanalaveCity_PokemonCenter_1F_Text_NPC1_2:
	.string "The same kinds of Pokémon can\n"
	.string "sometimes have different abilities.\p"
	.string "Maybe I ought to raise two with\n"
	.string "different natures.$"
