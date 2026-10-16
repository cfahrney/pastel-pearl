CanalaveCity_SailorEldritchHouse_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CanalaveCity_SailorEldritchHouse_OnTransition
	.byte 0

CanalaveCity_SailorEldritchHouse_EventScript_NPC1::
	goto_if_eq VAR_CANALAVE_CITY_STATE, 1, CanalaveCity_SailorEldritchHouse_EventScript_NPC1_2
	goto_if_eq VAR_CANALAVE_CITY_STATE, 2, CanalaveCity_SailorEldritchHouse_EventScript_NPC1_2
	goto_if_eq VAR_CANALAVE_CITY_STATE, 3, CanalaveCity_SailorEldritchHouse_EventScript_NPC1_2_2
	lockall
	faceplayer
	msgbox CanalaveCity_SailorEldritchHouse_Text_NPC1_2, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

CanalaveCity_SailorEldritchHouse_EventScript_NPC1_2::
	goto_if_unset FLAG_CANALAVE_CITY_SAILOR_1, CanalaveCity_SailorEldritchHouse_EventScript_NPC1_2_3
	goto_if_unset FLAG_CANALAVE_CITY_SAILOR_ELDRITCH_HOUSE_LITTLE_BOY_1, CanalaveCity_SailorEldritchHouse_EventScript_NPC1_2_4
	checkitem ITEM_NONE @ TODO(DP): ITEM_LUNAR_WING, 1
	goto_if_eq VAR_RESULT, FALSE, CanalaveCity_SailorEldritchHouse_EventScript_NPC1_2_4
	lockall
	setflag FLAG_CANALAVE_CITY_SIGN_2
	setvar VAR_CANALAVE_CITY_STATE, 3
	removeitem ITEM_NONE @ TODO(DP): ITEM_LUNAR_WING, 1
	msgbox CanalaveCity_SailorEldritchHouse_Text_NPC1_3, MSGBOX_DEFAULT
	message CanalaveCity_SailorEldritchHouse_Text_NPC1_4
	waitmessage
	playfanfare MUS_HEAL
	waitfanfare
	closemessage
	delay 30
	call CanalaveCity_SailorEldritchHouse_EventScript_NPC1_2_5
	msgbox CanalaveCity_SailorEldritchHouse_Text_NPC1_5, MSGBOX_DEFAULT
	call CanalaveCity_SailorEldritchHouse_EventScript_NPC1_2_6
	msgbox CanalaveCity_SailorEldritchHouse_Text_NPC1_6, MSGBOX_DEFAULT
	call CanalaveCity_SailorEldritchHouse_EventScript_NPC1_2_7
	msgbox CanalaveCity_SailorEldritchHouse_Text_NPC1_7, MSGBOX_DEFAULT
	closemessage
	call CanalaveCity_SailorEldritchHouse_EventScript_NPC1_2_8
	releaseall
	end

CanalaveCity_SailorEldritchHouse_EventScript_NPC1_2_2::
	lockall
	faceplayer
	msgbox CanalaveCity_SailorEldritchHouse_Text_NPC1_8, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

CanalaveCity_SailorEldritchHouse_EventScript_NPC1_2_3::
	setflag FLAG_CANALAVE_CITY_SAILOR_1
	setvar VAR_CANALAVE_CITY_STATE, 2
	goto CanalaveCity_SailorEldritchHouse_EventScript_NPC1_2_4

CanalaveCity_SailorEldritchHouse_EventScript_NPC1_2_4::
	lockall
	msgbox CanalaveCity_SailorEldritchHouse_Text_NPC1_9, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

CanalaveCity_SailorEldritchHouse_EventScript_NPC1_2_5::
	playse SE_EXIT
	waitse
	clearflag FLAG_HIDE_CANALAVE_CITY_SAILOR_ELDRITCH_HOUSE_SAILOR
	clearflag FLAG_HIDE_CANALAVE_CITY_SAILOR_ELDRITCH_HOUSE_SAILOR
	addobject LOCALID_CANALAVE_CITY_SAILOR_ELDRITCH_HOUSE_SAILOR
	delay 10
	applymovement LOCALID_CANALAVE_CITY_SAILOR_ELDRITCH_HOUSE_MIDDLE_AGED_WOMAN, CanalaveCity_SailorEldritchHouse_Movement_MiddleAgedWoman
	applymovement LOCALID_CANALAVE_CITY_SAILOR_ELDRITCH_HOUSE_LITTLE_BOY, CanalaveCity_SailorEldritchHouse_Movement_LittleBoy
	applymovement LOCALID_PLAYER, CanalaveCity_SailorEldritchHouse_Movement_Player
	waitmovement 0
	applymovement LOCALID_CANALAVE_CITY_SAILOR_ELDRITCH_HOUSE_SAILOR, CanalaveCity_SailorEldritchHouse_Movement_Sailor
	waitmovement 0
	applymovement LOCALID_PLAYER, CanalaveCity_SailorEldritchHouse_Movement_Player2
	waitmovement 0
	applymovement LOCALID_CANALAVE_CITY_SAILOR_ELDRITCH_HOUSE_SAILOR, CanalaveCity_SailorEldritchHouse_Movement_Sailor2
	waitmovement 0
	applymovement LOCALID_PLAYER, CanalaveCity_SailorEldritchHouse_Movement_Player3
	waitmovement 0
	return

CanalaveCity_SailorEldritchHouse_EventScript_NPC1_2_6::
	applymovement LOCALID_CANALAVE_CITY_SAILOR_ELDRITCH_HOUSE_SAILOR, CanalaveCity_SailorEldritchHouse_Movement_Sailor3
	waitmovement 0
	return

CanalaveCity_SailorEldritchHouse_EventScript_NPC1_2_7::
	applymovement LOCALID_CANALAVE_CITY_SAILOR_ELDRITCH_HOUSE_SAILOR, CanalaveCity_SailorEldritchHouse_Movement_Sailor4
	waitmovement 0
	return

CanalaveCity_SailorEldritchHouse_EventScript_NPC1_2_8::
	applymovement LOCALID_PLAYER, CanalaveCity_SailorEldritchHouse_Movement_Player
	applymovement LOCALID_CANALAVE_CITY_SAILOR_ELDRITCH_HOUSE_SAILOR, CanalaveCity_SailorEldritchHouse_Movement_Sailor5
	waitmovement 0
	setflag FLAG_HIDE_CANALAVE_CITY_SAILOR_ELDRITCH_HOUSE_SAILOR
	removeobject LOCALID_CANALAVE_CITY_SAILOR_ELDRITCH_HOUSE_SAILOR
	playse SE_EXIT
	waitse
	return

CanalaveCity_SailorEldritchHouse_EventScript_NPC2::
	copyvar VAR_0x8008, VAR_CANALAVE_CITY_STATE
	goto_if_eq VAR_0x8008, 1, CanalaveCity_SailorEldritchHouse_EventScript_NPC2_2
	goto_if_eq VAR_0x8008, 2, CanalaveCity_SailorEldritchHouse_EventScript_NPC2_2
	goto_if_eq VAR_0x8008, 3, CanalaveCity_SailorEldritchHouse_EventScript_NPC2_2_2
	lock
	faceplayer
	msgbox CanalaveCity_SailorEldritchHouse_Text_NPC2_2, MSGBOX_DEFAULT
	closemessage
	release
	end

CanalaveCity_SailorEldritchHouse_EventScript_NPC2_2::
	msgbox CanalaveCity_SailorEldritchHouse_Text_NPC2_3, MSGBOX_NPC
	end

CanalaveCity_SailorEldritchHouse_EventScript_NPC2_2_2::
	msgbox CanalaveCity_SailorEldritchHouse_Text_NPC2_4, MSGBOX_NPC
	end

CanalaveCity_SailorEldritchHouse_OnTransition::
	goto_if_eq VAR_CANALAVE_CITY_STATE, 0, CanalaveCity_SailorEldritchHouse_OnTransition_2
	call_if_eq VAR_CANALAVE_CITY_STATE, 3, CanalaveCity_SailorEldritchHouse_OnTransition_2_2
	call_if_ge VAR_CANALAVE_CITY_STATE, 1, CanalaveCity_SailorEldritchHouse_OnTransition_2_3
	goto CanalaveCity_SailorEldritchHouse_OnTransition_2_4

CanalaveCity_SailorEldritchHouse_OnTransition_2::
	goto_if_set FLAG_CANALAVE_CITY_SIGN_2, CanalaveCity_SailorEldritchHouse_OnTransition_2_4
	goto_if_unset FLAG_SYS_GAME_CLEAR, CanalaveCity_SailorEldritchHouse_OnTransition_2_4
	@ TODO(DP): NationalDex 2, 16384
	goto_if_unset FLAG_SYS_GAME_CLEAR, CanalaveCity_SailorEldritchHouse_OnTransition_2_4
	setvar VAR_CANALAVE_CITY_STATE, 1
	call CanalaveCity_SailorEldritchHouse_OnTransition_2_3
	end

CanalaveCity_SailorEldritchHouse_OnTransition_2_2::
	setvar VAR_CANALAVE_CITY_STATE, 0
	return

CanalaveCity_SailorEldritchHouse_OnTransition_2_3::
	setobjectxyperm LOCALID_CANALAVE_CITY_SAILOR_ELDRITCH_HOUSE_LITTLE_BOY, 7, 5
	setobjectmovementtype LOCALID_CANALAVE_CITY_SAILOR_ELDRITCH_HOUSE_LITTLE_BOY, MOVEMENT_TYPE_FACE_DOWN
	@ TODO(DP): DP movement type 0 for LOCALID_CANALAVE_CITY_SAILOR_ELDRITCH_HOUSE_LITTLE_BOY
	setobjectxyperm LOCALID_CANALAVE_CITY_SAILOR_ELDRITCH_HOUSE_MIDDLE_AGED_WOMAN, 8, 5
	setobjectmovementtype LOCALID_CANALAVE_CITY_SAILOR_ELDRITCH_HOUSE_MIDDLE_AGED_WOMAN, MOVEMENT_TYPE_FACE_LEFT
	return

CanalaveCity_SailorEldritchHouse_OnTransition_2_4::
	end

CanalaveCity_SailorEldritchHouse_Movement_MiddleAgedWoman:
	face_left
	step_end

CanalaveCity_SailorEldritchHouse_Movement_LittleBoy:
	face_left
	step_end

CanalaveCity_SailorEldritchHouse_Movement_Player:
	face_left
	step_end

CanalaveCity_SailorEldritchHouse_Movement_Sailor:
	walk_up
	walk_up
	walk_right
	walk_right
	step_end

CanalaveCity_SailorEldritchHouse_Movement_Player2:
	face_up
	lock_facing_direction
	walk_down
	unlock_facing_direction
	step_end

CanalaveCity_SailorEldritchHouse_Movement_Sailor2:
	walk_right
	step_end

CanalaveCity_SailorEldritchHouse_Movement_Player3:
	face_up
	step_end

CanalaveCity_SailorEldritchHouse_Movement_Sailor3:
	face_down
	step_end

CanalaveCity_SailorEldritchHouse_Movement_Sailor4:
	face_right
	step_end

CanalaveCity_SailorEldritchHouse_Movement_Sailor5:
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	step_end

CanalaveCity_SailorEldritchHouse_Text_NPC1_2:
	.string "I'm going to be a Sailor like my daddy!\p"
	.string "He's a real man among men! Even the sea\n"
	.string "doesn't scare him!\p"
	.string "Oh, but a Gym Leader'd be cool, too!\n"
	.string "Byron is so awesome!$"

CanalaveCity_SailorEldritchHouse_Text_NPC1_3:
	.string "The little boy is thrashing about in his\n"
	.string "sleep.\p"
	.string "{PLAYER}'s Lunar Wing began to glow...\p"
	.string "The boy's sleeping face became\n"
	.string "untroubled and serene!$"

CanalaveCity_SailorEldritchHouse_Text_NPC1_4:
	.string "The little boy woke up!$"

CanalaveCity_SailorEldritchHouse_Text_NPC1_5:
	.string "Oh, my gosh! You're awake!\p"
	.string "Oh, my son... I... I don't know what to\n"
	.string "say...$"

CanalaveCity_SailorEldritchHouse_Text_NPC1_6:
	.string "Thank you! We'll never forget you!$"

CanalaveCity_SailorEldritchHouse_Text_NPC1_7:
	.string "Seeing you back to normal makes me feel\n"
	.string "great!\p"
	.string "I've regained my spirit as a Sailor! Come\n"
	.string "sail with me later!$"

CanalaveCity_SailorEldritchHouse_Text_NPC1_8:
	.string "I couldn't wake up... I saw it...\p"
	.string "It was a scary dream... It was a dark\n"
	.string "place...\p"
	.string "And there was a dark Pokémon...\p"
	.string "But, Daddy, Mommy... I could always hear\n"
	.string "your voices...$"

CanalaveCity_SailorEldritchHouse_Text_NPC1_9:
	.string "The little boy is thrashing about in his\n"
	.string "sleep.\p"
	.string "He appears to be in torment... He is\n"
	.string "muttering something...\p"
	.string "“Dar... Dark...is watching...me...”$"

CanalaveCity_SailorEldritchHouse_Text_NPC2_2:
	.string "Our boy has too much energy! I wish he'd\n"
	.string "be a little quieter.$"

CanalaveCity_SailorEldritchHouse_Text_NPC2_3:
	.string "I never thought our boy would fall into\n"
	.string "this endless nightmare...\p"
	.string "It's happened in the past in Canalave...\p"
	.string "There were people who never woke up\n"
	.string "from their nightmares...$"

CanalaveCity_SailorEldritchHouse_Text_NPC2_4:
	.string "Thank you! We can't thank you enough,\n"
	.string "but thank you!$"
