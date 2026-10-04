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
	.string "You know how Pokemon have types like\n"
	.string "Water, Fire, and Grass?\p"
	.string "They say those types have strengths\n"
	.string "and weaknesses against other types.$"

JubilifeCity_PokemonCenter_1F_Text_NPC2:
	.string "I'd love one of those {COLOR DYNAMIC_COLOR3}DexNavs{COLOR DARK_GRAY}, but I\n"
	.string "guess I need my own Pokemon first...$"

JubilifeCity_PokemonCenter_1F_Text_NPC3:
	.string "You can still catch a Pokemon if you\n"
	.string "already have six traveling with you.\p"
	.string "It automatically gets sent to the PC\n"
	.string "network in Pokemon Centers.$"
