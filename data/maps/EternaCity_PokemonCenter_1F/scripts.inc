EternaCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, EternaCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

EternaCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_ETERNA_CITY
	end

EternaCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_ETERNA_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	applymovement LOCALID_PLAYER, Common_Movement_FaceDown
	waitmovement 0
	release
	end

EternaCity_PokemonCenter_1F_EventScript_NPC2::
	lock
	faceplayer
	goto_if_set FLAG_ETERNA_CITY_BIKE_SHOP_YOUNGSTER_1, EternaCity_PokemonCenter_1F_EventScript_NPC2_2
	msgbox EternaCity_PokemonCenter_1F_Text_NPC2_2, MSGBOX_DEFAULT
	closemessage
	release
	end

EternaCity_PokemonCenter_1F_EventScript_NPC2_2::
	msgbox EternaCity_PokemonCenter_1F_Text_NPC2_3, MSGBOX_DEFAULT
	closemessage
	release
	end

EternaCity_PokemonCenter_1F_EventScript_NPC1::
	msgbox EternaCity_PokemonCenter_1F_Text_NPC1_2, MSGBOX_NPC
	end

EternaCity_PokemonCenter_1F_EventScript_NPC3::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_BUNEARY, CRY_MODE_NORMAL
	setspeaker EternaCity_PokemonCenter_1F_Text_BunearySpeaker
	message EternaCity_PokemonCenter_1F_Text_NPC3_2
	waitmessage
	waitmoncry
	waitbuttonpress
	closemessage
	release
	end

EternaCity_PokemonCenter_1F_EventScript_NPC4::
	lock
	faceplayer
	goto_if_eq VAR_TEMP_0, 1, EternaCity_PokemonCenter_1F_EventScript_NPC4_2
	@ TODO(DP): CheckPoketchApp 5, 32780
	goto_if_eq VAR_RESULT, 0, EternaCity_PokemonCenter_1F_EventScript_NPC4_2_2
	@ TODO(DP): GetLeadingPartyMonSlot 32768
	bufferspeciesname STR_VAR_1, VAR_0x8000
	msgbox EternaCity_PokemonCenter_1F_Text_NPC4_2, MSGBOX_DEFAULT
	@ TODO(DP): GetPartyMonFriendship 32780, 32768
	goto_if_ge VAR_RESULT, 120, EternaCity_PokemonCenter_1F_EventScript_NPC4_2_3
	goto_if_ge VAR_RESULT, 70, EternaCity_PokemonCenter_1F_EventScript_NPC4_2_4
	goto EternaCity_PokemonCenter_1F_EventScript_NPC4_2_5

EternaCity_PokemonCenter_1F_EventScript_NPC4_2::
	msgbox EternaCity_PokemonCenter_1F_Text_NPC4_3, MSGBOX_DEFAULT
	closemessage
	release
	end

EternaCity_PokemonCenter_1F_EventScript_NPC4_2_2::
	msgbox EternaCity_PokemonCenter_1F_Text_NPC4_4, MSGBOX_DEFAULT
	setvar VAR_TEMP_0, 1
	setvar VAR_0x8004, 5
	@ TODO(DP): Common DP script 2009
	waitbuttonpress
	closemessage
	release
	end

EternaCity_PokemonCenter_1F_EventScript_NPC4_2_3::
	msgbox EternaCity_PokemonCenter_1F_Text_NPC4_5, MSGBOX_DEFAULT
	closemessage
	release
	end

EternaCity_PokemonCenter_1F_EventScript_NPC4_2_4::
	msgbox EternaCity_PokemonCenter_1F_Text_NPC4_6, MSGBOX_DEFAULT
	closemessage
	release
	end

EternaCity_PokemonCenter_1F_EventScript_NPC4_2_5::
	msgbox EternaCity_PokemonCenter_1F_Text_NPC4_7, MSGBOX_DEFAULT
	closemessage
	release
	end

EternaCity_PokemonCenter_1F_Text_NPC2_2:
	.string "Team Galactic took my Pokémon away.\n"
	.string "They took other people's, too.\p"
	.string "Something should be done, but Team\n"
	.string "Galactic creeps everyone out...\p"
	.string "What are they doing to my Pokémon?$"

EternaCity_PokemonCenter_1F_Text_NPC2_3:
	.string "I got my Pokémon back!\p"
	.string "I'm so happy, I feel like riding my Bike\n"
	.string "down Cycling Road together with it!$"

EternaCity_PokemonCenter_1F_Text_NPC1_2:
	.string "When a Pokémon faints, it just means it\n"
	.string "doesn't have the power to battle.\p"
	.string "But it can still use hidden moves\n"
	.string "outside of battle!$"

EternaCity_PokemonCenter_1F_Text_NPC3_2:
	.string "Bunbun!$"

EternaCity_PokemonCenter_1F_Text_NPC4_2:
	.string "Hi, you cute little Trainer! What kinds\n"
	.string "of Pokémon are with you?\p"
	.string "Oh, your {STR_VAR_1}...$"

EternaCity_PokemonCenter_1F_Text_NPC4_3:
	.string "If you spend enough time with them, all\n"
	.string "Pokémon will open up to you.$"

EternaCity_PokemonCenter_1F_Text_NPC4_4:
	.string "Hi, you cute little Trainer! What kinds\n"
	.string "of Pokémon are with you?\p"
	.string "This Pokétch app will show how close\n"
	.string "your Pokémon feel to you.$"

EternaCity_PokemonCenter_1F_Text_NPC4_5:
	.string "It seems to like you. It must be happy\n"
	.string "being with you.$"

EternaCity_PokemonCenter_1F_Text_NPC4_6:
	.string "It's becoming comfortable around you, I\n"
	.string "think.$"

EternaCity_PokemonCenter_1F_Text_NPC4_7:
	.string "Hmm... It needs to get used to you more.$"

EternaCity_PokemonCenter_1F_Text_BunearySpeaker:
	.string "Buneary$"
