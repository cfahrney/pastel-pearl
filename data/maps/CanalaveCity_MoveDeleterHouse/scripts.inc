CanalaveCity_MoveDeleterHouse_MapScripts::
	.byte 0

CanalaveCity_MoveDeleterHouse_EventScript_NPC1::
	lock
	faceplayer
	goto_if_set FLAG_CANALAVE_CITY_MOVE_DELETER_HOUSE_OLD_MAN_1, CanalaveCity_MoveDeleterHouse_EventScript_NPC1_2
	msgbox CanalaveCity_MoveDeleterHouse_Text_NPC1_2, MSGBOX_DEFAULT
	setflag FLAG_CANALAVE_CITY_MOVE_DELETER_HOUSE_OLD_MAN_1
	goto CanalaveCity_MoveDeleterHouse_EventScript_NPC1_2

CanalaveCity_MoveDeleterHouse_EventScript_NPC1_2::
	msgbox CanalaveCity_MoveDeleterHouse_Text_NPC1_3, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, CanalaveCity_MoveDeleterHouse_EventScript_NPC1_2_2
	goto_if_eq VAR_RESULT, NO, CanalaveCity_MoveDeleterHouse_EventScript_NPC1_2_3
	end

CanalaveCity_MoveDeleterHouse_EventScript_NPC1_2_2::
	msgbox CanalaveCity_MoveDeleterHouse_Text_NPC1_4, MSGBOX_DEFAULT
	closemessage
	goto CanalaveCity_MoveDeleterHouse_EventScript_NPC1_2_4

CanalaveCity_MoveDeleterHouse_EventScript_NPC1_2_3::
	msgbox CanalaveCity_MoveDeleterHouse_Text_NPC1_5, MSGBOX_DEFAULT
	closemessage
	release
	end

CanalaveCity_MoveDeleterHouse_EventScript_NPC1_2_4::
	fadescreen FADE_TO_BLACK
	special ChoosePartyMon
	copyvar VAR_0x8002, VAR_0x8004
	fadescreen FADE_FROM_BLACK
	goto_if_eq VAR_0x8002, PARTY_NOTHING_CHOSEN, CanalaveCity_MoveDeleterHouse_EventScript_NPC1_2_3
	copyvar VAR_0x8004, VAR_0x8002
	specialvar VAR_0x8001, ScriptGetPartyMonSpecies
	goto_if_eq VAR_0x8001, SPECIES_NONE, CanalaveCity_MoveDeleterHouse_EventScript_NPC1_2_5
	@ TODO(DP): CountPartyMonMoves 32780, 32770
	goto_if_eq VAR_RESULT, NO, CanalaveCity_MoveDeleterHouse_EventScript_NPC1_2_6
	msgbox CanalaveCity_MoveDeleterHouse_Text_NPC1_6, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	@ TODO(DP): StorePokeDelete 32770
	@ TODO(DP): StoreMoveDelete 32769
	fadescreen FADE_FROM_BLACK
	goto_if_eq VAR_0x8001, SPECIES_TORCHIC, CanalaveCity_MoveDeleterHouse_EventScript_NPC1_2_2
	@ TODO(DP): GetPokemonMoveName 0, 32770, 32769
	msgbox CanalaveCity_MoveDeleterHouse_Text_NPC1_7, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, CanalaveCity_MoveDeleterHouse_EventScript_NPC1_2_7
	goto_if_eq VAR_RESULT, NO, CanalaveCity_MoveDeleterHouse_EventScript_NPC1_2_2
	end

CanalaveCity_MoveDeleterHouse_EventScript_NPC1_2_5::
	msgbox CanalaveCity_MoveDeleterHouse_Text_NPC1_8, MSGBOX_DEFAULT
	closemessage
	goto CanalaveCity_MoveDeleterHouse_EventScript_NPC1_2_4

CanalaveCity_MoveDeleterHouse_EventScript_NPC1_2_6::
	msgbox CanalaveCity_MoveDeleterHouse_Text_NPC1_9, MSGBOX_DEFAULT
	closemessage
	goto CanalaveCity_MoveDeleterHouse_EventScript_NPC1_2_4

CanalaveCity_MoveDeleterHouse_EventScript_NPC1_2_7::
	@ TODO(DP): ForgetPartyMonMove 32770, 32769
	message CanalaveCity_MoveDeleterHouse_Text_NPC1_10
	waitmessage
	@ TODO(DP): fanfare SEQ_WASURE
	waitfanfare
	waitbuttonpress
	closemessage
	end

CanalaveCity_MoveDeleterHouse_Text_NPC1_2:
	.string "Um... Who did you say I was again?\p"
	.string "... ...\p"
	.string "Oh, yes, I remember now! I'm the Move\n"
	.string "Deleter!$"

CanalaveCity_MoveDeleterHouse_Text_NPC1_3:
	.string "You've come to make me force your\n"
	.string "Pokémon to forget some moves?$"

CanalaveCity_MoveDeleterHouse_Text_NPC1_4:
	.string "Which Pokémon should forget a move?$"

CanalaveCity_MoveDeleterHouse_Text_NPC1_5:
	.string "Remember me if there are moves that\n"
	.string "need to be forgotten.$"

CanalaveCity_MoveDeleterHouse_Text_NPC1_6:
	.string "OK, then. Which move should be\n"
	.string "forgotten?$"

CanalaveCity_MoveDeleterHouse_Text_NPC1_7:
	.string "Hm! The move {STR_VAR_1}? Should that\n"
	.string "move be forgotten?$"

CanalaveCity_MoveDeleterHouse_Text_NPC1_8:
	.string "What? That's an Egg. No Egg should know\n"
	.string "any moves.$"

CanalaveCity_MoveDeleterHouse_Text_NPC1_9:
	.string "That Pokémon knows only one move, so it\n"
	.string "can't be forgotten...$"

CanalaveCity_MoveDeleterHouse_Text_NPC1_10:
	.string "It worked perfectly!\p"
	.string "Your Pokémon has forgotten the move\n"
	.string "{STR_VAR_1} completely.$"
