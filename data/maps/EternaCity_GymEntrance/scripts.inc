EternaCity_GymEntrance_MapScripts::
	.byte 0

EternaCity_GymEntrance_EventScript_NPC1::
	lock
	faceplayer
	goto_if_set FLAG_BADGE02_GET, EternaCity_GymEntrance_EventScript_NPC1_2
	msgbox EternaCity_GymEntrance_Text_NPC1_2, MSGBOX_DEFAULT
	closemessage
	release
	end

EternaCity_GymEntrance_EventScript_NPC1_2::
	msgbox EternaCity_GymEntrance_Text_NPC1_3, MSGBOX_DEFAULT
	closemessage
	release
	end

EternaCity_GymEntrance_EventScript_NPC2::
	lockall
	faceplayer
	setspeaker SP_NAME_GARDENIA
	msgbox EternaCity_GymEntrance_Text_NPC2, MSGBOX_DEFAULT
	closemessage
	delay 30
	applymovement LOCALID_ETERNA_CITY_GYM_ENTRANCE_GARDENIA, EternaCity_GymEntrance_Movement_Gardenia
	waitmovement 0
	playse SE_EXIT
	removeobject LOCALID_ETERNA_CITY_GYM_ENTRANCE_GARDENIA
	waitse
	releaseall
	end

EternaCity_GymEntrance_EventScript_Sign1::
	lockall
	goto_if_set FLAG_BADGE02_GET, EternaCity_GymEntrance_EventScript_Sign1_2
	msgbox EternaCity_GymEntrance_Text_Sign1_2, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

EternaCity_GymEntrance_EventScript_Sign1_2::
	msgbox EternaCity_GymEntrance_Text_Sign1_3, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

EternaCity_GymEntrance_EventScript_Sign2::
	goto EternaCity_GymEntrance_EventScript_Sign1
	end

EternaCity_GymEntrance_Movement_Gardenia:
	walk_in_place_fast_up
	step_end

EternaCity_GymEntrance_Text_NPC1_2:
	.string "Hey, there! How's it going,\n"
	.string "Champ-to-be?\p"
	.string "Actually, that's what I said to some boy\n"
	.string "who zipped in here earlier, too!\p"
	.string "The Gym Leader, Gardenia, is a user of\n"
	.string "Grass-type Pokémon.\p"
	.string "It should be obvious, but Grass-type\n"
	.string "Pokémon really hate fire.\p"
	.string "Oh, wait a second. I should tell you\n"
	.string "about the Gym itself first.\p"
	.string "You can't challenge the Gym Leader\n"
	.string "until you find and beat all the Gym's\l"
	.string "Trainers who've hidden themselves.\p"
	.string "It's a bit challenging, but just think of\n"
	.string "it as good training and go for it!$"

EternaCity_GymEntrance_Text_NPC1_3:
	.string "Oh! {PLAYER}! You've beaten the Gym\n"
	.string "Leader!\p"
	.string "Your Pokémon look much tougher than\n"
	.string "when they went in, too!\p"
	.string "At least that's how I see it!$"

EternaCity_GymEntrance_Text_NPC2:
	.string "At my Gym, no one gets to battle with\n"
	.string "the Gym Leader--me--until they've\l"
	.string "beaten all the other Trainers.\p"
	.string "I'll be waiting for you in the back. Good\n"
	.string "luck, challenger!$"

EternaCity_GymEntrance_Text_Sign1_2:
	.string "Eterna City Pokémon Gym Leader:\n"
	.string "Gardenia Certified Trainers: {RIVAL}$"

EternaCity_GymEntrance_Text_Sign1_3:
	.string "Eterna City Pokémon Gym Leader:\n"
	.string "Gardenia Certified Trainers: {RIVAL}\l"
	.string "{PLAYER}$"
