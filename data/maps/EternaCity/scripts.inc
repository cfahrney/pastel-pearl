EternaCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, EternaCity_OnTransition
	.byte 0

EternaCity_EventScript_NPC1::
	msgbox EternaCity_Text_NPC1, MSGBOX_NPC
	end

EternaCity_Text_NPC1:
	.string "Have you seen our building?\p"
	.string "Team Galactic is so stinking rich that\n"
	.string "we can have one built instantly!$"

EternaCity_EventScript_NPC2::
	msgbox EternaCity_Text_NPC2, MSGBOX_NPC
	end

EternaCity_Text_NPC2:
	.string "My friend said Team Galactic took his\n"
	.string "favorite Pokémon away.\p"
	.string "I don't think he's telling the truth.\n"
	.string "Team Galactic looks so cool.\p"
	.string "They don't look like common thugs.$"

EternaCity_EventScript_NPC3::
	msgbox EternaCity_Text_NPC3, MSGBOX_NPC
	end

EternaCity_Text_NPC3:
	.string "Oh, wow! You got a {COLOR DYNAMIC_COLOR3}Bicycle{COLOR DARK_GRAY}!\p"
	.string "You can ride down Cycling Road and end\n"
	.string "up in Hearthome City.\p"
	.string "It's a fast and fun ride. You should\n"
	.string "check it out!$"

EternaCity_EventScript_NPC4::
	msgbox EternaCity_Text_NPC4, MSGBOX_NPC
	end

EternaCity_Text_NPC4:
	.string "Eterna City's not anything like it was\n"
	.string "before, way back in the day.$"

EternaCity_EventScript_NPC5::
	msgbox EternaCity_Text_NPC5, MSGBOX_NPC
	end

EternaCity_Text_NPC5:
	.string "Since that Team Galactic building went\n"
	.string "up, the city's atmosphere has gotten\p"
	.string "all creepy and tense.\p"
	.string "I don't know what those people are\n"
	.string "doing up in that place...$"

EternaCity_EventScript_NPC6::
	msgbox EternaCity_Text_NPC6, MSGBOX_NPC
	end

EternaCity_Text_NPC6:
	.string "ETERNA CITY NPC 6$"

EternaCity_EventScript_NPC7::
	msgbox EternaCity_Text_NPC7, MSGBOX_NPC
	end

EternaCity_Text_NPC7:
	.string "They say this is an old city.\p"
	.string "It doesn't look it, though. Not with all\n"
	.string "these tall buildings.$"

EternaCity_EventScript_NPC8::
	msgbox EternaCity_Text_NPC8, MSGBOX_NPC
	end

EternaCity_Text_NPC8:
	.string "If you're visiting Eterna, you need to\n"
	.string "get yourself a {COLOR DYNAMIC_COLOR3}Bicycle{COLOR DARK_GRAY} and take a\p"
	.string "ride down the Cycling Road.$"

EternaCity_EventScript_NPC9::
	msgbox EternaCity_Text_NPC9, MSGBOX_NPC
	end

EternaCity_Text_NPC9:
	.string "Going underground with the Explorer Kit\n"
	.string "is a blast, isn't it?$"

EternaCity_EventScript_NPC10::
	msgbox EternaCity_Text_NPC10, MSGBOX_NPC
	end

EternaCity_Text_NPC10:
	.string "Hey! You there, kid! Stay away from that\n"
	.string "Pokémon statue!\p"
	.string "Team Galactic is conducting an official\n"
	.string "investigation here!$"

EternaCity_EventScript_NPC11::
	msgbox EternaCity_Text_NPC11, MSGBOX_NPC
	end

EternaCity_Text_NPC11:
	.string "Hey, you! Yeah, you, Trainer!\p"
	.string "Errr... It's OK. Never mind. You look\n"
	.string "tough.\p"
	.string "I won't take... Um, I'll just let you keep\n"
	.string "your Pokémon. Carry on!$"

EternaCity_EventScript_NPC12::
	msgbox EternaCity_Text_NPC12, MSGBOX_NPC
	end

EternaCity_Text_NPC12:
	.string "They say this is a Pokémon that lived\n"
	.string "long, long ago.$"

EternaCity_EventScript_Sign1::
	msgbox EternaCity_Text_Sign1, MSGBOX_SIGN
	end

EternaCity_Text_Sign1:
	.string "Eterna City History Living$"

EternaCity_EventScript_Sign2::
	msgbox EternaCity_Text_Sign2, MSGBOX_SIGN
	end

EternaCity_Text_Sign2:
	.string "Eterna City History Living$"

EternaCity_EventScript_Sign3::
	msgbox EternaCity_Text_Sign3, MSGBOX_SIGN
	end

EternaCity_Text_Sign3:
	.string "ETERNA CITY SIGN 3$"

EternaCity_EventScript_Sign4::
	msgbox EternaCity_Text_Sign4, MSGBOX_SIGN
	end

EternaCity_Text_Sign4:
	.string "There is some writing on the Pokémon\n"
	.string "statue...\p"
	.string "...birth of Pal... ...creator of parallel\n"
	.string "dimensions...\p"
	.string "Alive, yet not alive... ...rifts in space...\p"
	.string "To arrive in the same univer... ...the\n"
	.string "blessing of Pal...\p"
	.string "The text is barely legible and has faded\n"
	.string "completely in places...$"

EternaCity_EventScript_Sign5::
	msgbox EternaCity_Text_Sign5, MSGBOX_SIGN
	end

EternaCity_Text_Sign5:
	.string "Underground Man's House Goin' Down for\n"
	.string "Adventure!$"

EternaCity_EventScript_Sign6::
	msgbox EternaCity_Text_Sign6, MSGBOX_SIGN
	end

EternaCity_Text_Sign6:
	.string "Team Galactic Eterna Building We Want\n"
	.string "Your Pokémon!$"

EternaCity_EventScript_Sign7::
	msgbox EternaCity_Text_Sign7, MSGBOX_SIGN
	end

EternaCity_EventScript_Sign8::
	msgbox EternaCity_Text_Sign8, MSGBOX_SIGN
	end

EternaCity_EventScript_Sign9::
	msgbox EternaCity_Text_Sign9, MSGBOX_SIGN
	end

EternaCity_EventScript_Trigger1::
	lockall
	getplayerxy VAR_0x8004, VAR_0x8005
	goto_if_eq VAR_0x8005, 11, EternaCity_EventScript_Trigger1_2
	goto_if_eq VAR_0x8005, 12, EternaCity_EventScript_Trigger1_2_2
	goto_if_eq VAR_0x8005, 13, EternaCity_EventScript_Trigger1_2_3
	end

EternaCity_EventScript_Trigger1_2::
	setobjectxyperm LOCALID_ETERNA_CITY_CYNTHIA, 24, 11
	goto EternaCity_EventScript_Trigger1_2_4

EternaCity_EventScript_Trigger1_2_2::
	setobjectxyperm LOCALID_ETERNA_CITY_CYNTHIA, 24, 12
	goto EternaCity_EventScript_Trigger1_2_4

EternaCity_EventScript_Trigger1_2_3::
	setobjectxyperm LOCALID_ETERNA_CITY_CYNTHIA, 24, 13
	goto EternaCity_EventScript_Trigger1_2_4

EternaCity_EventScript_Trigger1_2_4::
	clearflag FLAG_HIDE_ETERNA_CITY_CYNTHIA
	clearflag FLAG_HIDE_ETERNA_CITY_CYNTHIA
	addobject LOCALID_ETERNA_CITY_CYNTHIA
	playse SE_PIN
	applymovement LOCALID_ETERNA_CITY_CYNTHIA, EternaCity_Movement_Cynthia
	waitmovement 0
	msgbox EternaCity_Text_Trigger1, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ETERNA_CITY_CYNTHIA, EternaCity_Movement_Cynthia2
	waitmovement 0
	msgbox EternaCity_Text_Trigger1_2, MSGBOX_DEFAULT
	setvar VAR_0x8004, 420
	setvar VAR_0x8005, 1
	giveitem VAR_0x8004, VAR_0x8005
	setspeaker SP_NAME_CYNTHIA
	msgbox EternaCity_Text_Trigger1_3, MSGBOX_DEFAULT
	closemessage
	getplayerxy VAR_0x8004, VAR_0x8005
	goto_if_eq VAR_0x8005, 11, EternaCity_EventScript_Trigger1_2_5
	goto_if_eq VAR_0x8005, 12, EternaCity_EventScript_Trigger1_2_6
	goto_if_eq VAR_0x8005, 13, EternaCity_EventScript_Trigger1_2_7
	end

EternaCity_EventScript_Trigger1_2_5::
	applymovement LOCALID_ETERNA_CITY_CYNTHIA, EternaCity_Movement_Cynthia3
	applymovement LOCALID_PLAYER, EternaCity_Movement_Player
	waitmovement 0
	goto EternaCity_EventScript_Trigger1_2_8

EternaCity_EventScript_Trigger1_2_6::
	applymovement LOCALID_ETERNA_CITY_CYNTHIA, EternaCity_Movement_Cynthia3
	applymovement LOCALID_PLAYER, EternaCity_Movement_Player
	waitmovement 0
	goto EternaCity_EventScript_Trigger1_2_8

EternaCity_EventScript_Trigger1_2_7::
	applymovement LOCALID_ETERNA_CITY_CYNTHIA, EternaCity_Movement_Cynthia4
	applymovement LOCALID_PLAYER, EternaCity_Movement_Player2
	waitmovement 0
	goto EternaCity_EventScript_Trigger1_2_8

EternaCity_EventScript_Trigger1_2_8::
	removeobject LOCALID_ETERNA_CITY_CYNTHIA
	setvar VAR_ETERNA_CITY_STATE, 1
	releaseall
	end

EternaCity_EventScript_Trigger2::
	lockall
	getplayerxy VAR_0x8004, VAR_0x8005
	call_if_eq VAR_0x8004, 15, EternaCity_EventScript_Trigger2_2
	call_if_eq VAR_0x8004, 16, EternaCity_EventScript_Trigger2_2_2
	call_if_eq VAR_0x8004, 17, EternaCity_EventScript_Trigger2_2_3
	call_if_eq VAR_0x8004, 18, EternaCity_EventScript_Trigger2_2_4
	call_if_eq VAR_0x8004, 19, EternaCity_EventScript_Trigger2_2_5
	applymovement LOCALID_PLAYER, EternaCity_Movement_Player3
	waitmovement 0
	msgbox EternaCity_Text_Trigger2, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_0x8004, 15, EternaCity_EventScript_Trigger2_2_6
	call_if_eq VAR_0x8004, 16, EternaCity_EventScript_Trigger2_2_7
	call_if_eq VAR_0x8004, 17, EternaCity_EventScript_Trigger2_2_8
	call_if_eq VAR_0x8004, 18, EternaCity_EventScript_Trigger2_2_9
	call_if_eq VAR_0x8004, 19, EternaCity_EventScript_Trigger2_2_10
	applymovement LOCALID_PLAYER, EternaCity_Movement_Player4
	waitmovement 0
	releaseall
	end

EternaCity_EventScript_Trigger2_2::
	playse SE_PIN
	applymovement LOCALID_ETERNA_CITY_WOMAN, EternaCity_Movement_Woman
	waitmovement 0
	return

EternaCity_EventScript_Trigger2_2_2::
	playse SE_PIN
	applymovement LOCALID_ETERNA_CITY_WOMAN, EternaCity_Movement_Woman2
	waitmovement 0
	return

EternaCity_EventScript_Trigger2_2_3::
	playse SE_PIN
	applymovement LOCALID_ETERNA_CITY_WOMAN, EternaCity_Movement_Woman3
	waitmovement 0
	return

EternaCity_EventScript_Trigger2_2_4::
	playse SE_PIN
	applymovement LOCALID_ETERNA_CITY_WOMAN, EternaCity_Movement_Woman4
	waitmovement 0
	return

EternaCity_EventScript_Trigger2_2_5::
	playse SE_PIN
	applymovement LOCALID_ETERNA_CITY_WOMAN, EternaCity_Movement_Woman5
	waitmovement 0
	return

EternaCity_EventScript_Trigger2_2_6::
	return

EternaCity_EventScript_Trigger2_2_7::
	applymovement LOCALID_ETERNA_CITY_WOMAN, EternaCity_Movement_Woman6
	waitmovement 0
	return

EternaCity_EventScript_Trigger2_2_8::
	applymovement LOCALID_ETERNA_CITY_WOMAN, EternaCity_Movement_Woman7
	waitmovement 0
	return

EternaCity_EventScript_Trigger2_2_9::
	applymovement LOCALID_ETERNA_CITY_WOMAN, EternaCity_Movement_Woman8
	waitmovement 0
	return

EternaCity_EventScript_Trigger2_2_10::
	applymovement LOCALID_ETERNA_CITY_WOMAN, EternaCity_Movement_Woman9
	waitmovement 0
	return

EternaCity_EventScript_Trigger3::
	lockall
	getplayerxy VAR_0x8004, VAR_0x8005
	call_if_eq VAR_0x8005, 20, EternaCity_EventScript_Trigger3_2
	call_if_eq VAR_0x8005, 21, EternaCity_EventScript_Trigger3_2_2
	call_if_eq VAR_0x8005, 22, EternaCity_EventScript_Trigger3_2_3
	applymovement LOCALID_PLAYER, EternaCity_Movement_Player5
	waitmovement 0
	msgbox EternaCity_Text_Trigger3, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_0x8005, 20, EternaCity_EventScript_Trigger3_2_4
	call_if_eq VAR_0x8005, 21, EternaCity_EventScript_Trigger3_2_5
	call_if_eq VAR_0x8005, 22, EternaCity_EventScript_Trigger3_2_6
	releaseall
	end

EternaCity_EventScript_Trigger3_2::
	playse SE_PIN
	applymovement LOCALID_ETERNA_CITY_BOY, EternaCity_Movement_Boy
	waitmovement 0
	return

EternaCity_EventScript_Trigger3_2_2::
	playse SE_PIN
	applymovement LOCALID_ETERNA_CITY_BOY, EternaCity_Movement_Boy2
	waitmovement 0
	return

EternaCity_EventScript_Trigger3_2_3::
	playse SE_PIN
	applymovement LOCALID_ETERNA_CITY_BOY, EternaCity_Movement_Boy3
	waitmovement 0
	return

EternaCity_EventScript_Trigger3_2_4::
	applymovement LOCALID_ETERNA_CITY_BOY, EternaCity_Movement_Boy4
	applymovement LOCALID_PLAYER, EternaCity_Movement_Player6
	waitmovement 0
	return

EternaCity_EventScript_Trigger3_2_5::
	applymovement LOCALID_ETERNA_CITY_BOY, EternaCity_Movement_Boy5
	applymovement LOCALID_PLAYER, EternaCity_Movement_Player6
	waitmovement 0
	return

EternaCity_EventScript_Trigger3_2_6::
	applymovement LOCALID_ETERNA_CITY_BOY, EternaCity_Movement_Boy6
	applymovement LOCALID_PLAYER, EternaCity_Movement_Player6
	waitmovement 0
	return

EternaCity_OnTransition::
	checkitem ITEM_BICYCLE, 1
	copyvar VAR_TEMP_0, VAR_RESULT
	goto_if_eq VAR_TEMP_0, FALSE, EternaCity_OnTransition_2
	checkitem ITEM_NONE @ TODO(DP): DP item 428, 1
	copyvar VAR_TEMP_0, VAR_RESULT
	goto_if_eq VAR_TEMP_0, TRUE, EternaCity_OnTransition_2
	setvar VAR_ETERNA_CITY_STATE_2, 0
	end

EternaCity_OnTransition_2::
	setvar VAR_ETERNA_CITY_STATE_2, 1
	end

EternaCity_Movement_Cynthia:
	walk_left
	walk_left
	emote_exclamation_mark
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

EternaCity_Movement_Cynthia2:
	walk_in_place_right
	delay_16
	delay_16
	walk_in_place_left
	step_end

EternaCity_Movement_Cynthia3:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

EternaCity_Movement_Player:
	delay_16
	walk_in_place_down
	delay_16
	walk_in_place_left
	step_end

EternaCity_Movement_Cynthia4:
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

EternaCity_Movement_Player2:
	delay_16
	walk_in_place_up
	delay_16
	walk_in_place_left
	step_end

EternaCity_Movement_Player3:
	walk_in_place_left
	step_end

EternaCity_Movement_Player4:
	walk_up
	step_end

EternaCity_Movement_Woman:
	walk_in_place_fast_right
	emote_exclamation_mark
	delay_8
	step_end

EternaCity_Movement_Woman2:
	walk_in_place_fast_right
	emote_exclamation_mark
	delay_8
	walk_right
	step_end

EternaCity_Movement_Woman3:
	walk_in_place_fast_right
	emote_exclamation_mark
	delay_8
	walk_right
	walk_right
	step_end

EternaCity_Movement_Woman4:
	walk_in_place_fast_right
	emote_exclamation_mark
	delay_8
	walk_right
	walk_right
	walk_right
	step_end

EternaCity_Movement_Woman5:
	walk_in_place_fast_right
	emote_exclamation_mark
	delay_8
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

EternaCity_Movement_Woman6:
	walk_left
	walk_in_place_fast_right
	step_end

EternaCity_Movement_Woman7:
	walk_left
	walk_left
	walk_in_place_fast_right
	step_end

EternaCity_Movement_Woman8:
	walk_left
	walk_left
	walk_left
	walk_in_place_fast_right
	step_end

EternaCity_Movement_Woman9:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_fast_right
	step_end

EternaCity_Movement_Player5:
	face_up
	step_end

EternaCity_Movement_Boy:
	face_down
	emote_exclamation_mark
	step_end

EternaCity_Movement_Boy2:
	face_down
	emote_exclamation_mark
	walk_down
	step_end

EternaCity_Movement_Boy3:
	face_down
	emote_exclamation_mark
	walk_down
	walk_down
	step_end

EternaCity_Movement_Boy4:
	walk_down
	walk_up
	walk_in_place_down
	step_end

EternaCity_Movement_Player6:
	walk_right
	walk_in_place_left
	step_end

EternaCity_Movement_Boy5:
	walk_down
	walk_up
	walk_up
	walk_in_place_down
	step_end

EternaCity_Movement_Boy6:
	walk_down
	walk_up
	walk_up
	walk_up
	walk_in_place_down
	step_end

EternaCity_Text_Sign7:
	.string "Eterna City Pokémon Gym Leader:\n"
	.string "Gardenia Master of Vivid Plant Pokémon!$"

EternaCity_Text_Sign8:
	.string "Rad Rickshaw's Cycle Shop\n"
	.string "Get On and Ride!$"

EternaCity_Text_Sign9:
	.string "Eterna Condominiums\n"
	.string "Name-Rating Services Available$"

EternaCity_Text_Trigger1:
	.string "Oh, is that a {COLOR DYNAMIC_COLOR3}Pokédex{COLOR DARK_GRAY}? You must be\n"
	.string "helping Professor Rowan?\p"
	.string "What's your name?\p"
	.string "...\p"
	.string "OK, hello, {PLAYER}. I'll be sure to\n"
	.string "remember that name!\p"
	.string "My name is Cynthia. I'm a Trainer just\n"
	.string "like you.\p"
	.string "I've been studying Pokémon mythology\n"
	.string "lately, just out of curiosity.$"

EternaCity_Text_Trigger1_2:
	.string "Here in Eterna City, there is a statue\n"
	.string "of an ancient Pokémon.\p"
	.string "According to myth, it was an extremely\n"
	.string "powerful Pokémon.\p"
	.string "Who knows? You may encounter\n"
	.string "something like it while you're traveling\l"
	.string "with your {COLOR DYNAMIC_COLOR3}Pokédex{COLOR DARK_GRAY}.\p"
	.string "Try using this. It should help you on\n"
	.string "your way.$"

EternaCity_Text_Trigger1_3:
	.string "Remember, the hidden move Cut can be\n"
	.string "used in the field.\p"
	.string "It will let you go places that were\n"
	.string "previously inaccessible to you.\p"
	.string "That's important for filling up your\n"
	.string "{COLOR DYNAMIC_COLOR3}Pokédex{COLOR DARK_GRAY}, right?\p"
	.string "Then luck be with you, young Trainer!$"

EternaCity_Text_Trigger2:
	.string "Oh, don't tell me you don't have an\n"
	.string "Explorer Kit?\p"
	.string "You should have a word with the man\n"
	.string "next door to the Pokémon Center.$"

EternaCity_Text_Trigger3:
	.string "Oh, wow! You got a {COLOR DYNAMIC_COLOR3}Bicycle{COLOR DARK_GRAY}!\p"
	.string "You can ride down Cycling Road and end\n"
	.string "up in Hearthome City.\p"
	.string "It's a fast and fun ride. You should\n"
	.string "check it out!$"
