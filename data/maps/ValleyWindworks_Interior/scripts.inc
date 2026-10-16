ValleyWindworks_Interior_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ValleyWindworks_Interior_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, ValleyWindworks_Interior_OnFrame
	.byte 0

ValleyWindworks_Interior_EventScript_Trainer1::
	trainerbattle_single TRAINER_VALLEY_WINDWORKS_INTERIOR_1, ValleyWindworks_Interior_Text_Trainer1Intro, ValleyWindworks_Interior_Text_Trainer1Defeated
	msgbox ValleyWindworks_Interior_Text_Trainer1PostBattle, MSGBOX_AUTOCLOSE
	end

ValleyWindworks_Interior_Text_Trainer1Intro:
	.string "I ain't fooling around, kid. This is how a\n"
	.string "professional does it!$"

ValleyWindworks_Interior_Text_Trainer1Defeated:
	.string "You messed up my job... Now I'm not\n"
	.string "gonna get a bonus...$"

ValleyWindworks_Interior_Text_Trainer1PostBattle:
	.string "I hear they're going to do something\n"
	.string "with electricity, I think.$"

ValleyWindworks_Interior_EventScript_NPC1::
	msgbox ValleyWindworks_Interior_Text_NPC1, MSGBOX_NPC
	end

ValleyWindworks_Interior_Text_NPC1:
	.string "I'm one of Team Galactic's three\n"
	.string "Commanders.\p"
	.string "We've been trying to create a new world\n"
	.string "that's better than this one...\p"
	.string "But people have shown little\n"
	.string "understanding about what we do.\p"
	.string "You don't understand either, do you?\n"
	.string "It's a little saddening...\p"
	.string "So, let's have a battle to decide what\n"
	.string "we should do next.\p"
	.string "If I win, you leave.\p"
	.string "If you win, we, Team Galactic, will leave!$"

ValleyWindworks_Interior_EventScript_NPC2::
	msgbox ValleyWindworks_Interior_Text_NPC2, MSGBOX_NPC
	end

ValleyWindworks_Interior_Text_NPC2:
	.string "My Pokémon can't battle anymore.\p"
	.string "They're gonna take away my Pokémon for\n"
	.string "messing this one up...\p"
	.string "Humph! Just you wait! Our Commander will\n"
	.string "smoosh you!$"

ValleyWindworks_Interior_EventScript_NPC3::
	msgbox ValleyWindworks_Interior_Text_NPC3, MSGBOX_NPC
	end

ValleyWindworks_Interior_Text_NPC3:
	.string "Little girl: Thank you, Trainer! You made\n"
	.string "those bad people go away!\p"
	.string "I think the balloon Pokémon will come\n"
	.string "visiting again!$"

ValleyWindworks_Interior_EventScript_Trainer3::
	trainerbattle_single TRAINER_VALLEY_WINDWORKS_INTERIOR_3, ValleyWindworks_Interior_Text_Trainer3Intro, ValleyWindworks_Interior_Text_Trainer3Defeated
	msgbox ValleyWindworks_Interior_Text_Trainer3PostBattle, MSGBOX_AUTOCLOSE
	end

ValleyWindworks_Interior_Text_Trainer3Intro:
	.string "Collecting electricity from the Valley\n"
	.string "Windworks... That's our mission.$"

ValleyWindworks_Interior_Text_Trainer3Defeated:
	.string "I really don't like kids who also happen\n"
	.string "to be tough Trainers...$"

ValleyWindworks_Interior_Text_Trainer3PostBattle:
	.string "You don't have an inkling of what Team\n"
	.string "Galactic is trying to achieve!\p"
	.string "Of course, they don't tell a grunt like\n"
	.string "me anything, either... But still!$"

ValleyWindworks_Interior_EventScript_NPC4::
	lock
	faceplayer
	goto_if_ge VAR_VALLEY_WINDWORKS_STATE, 3, ValleyWindworks_Interior_EventScript_NPC4_2
	setspeaker ValleyWindworks_Interior_Text_PapaSpeaker
	msgbox ValleyWindworks_Interior_Text_NPC4, MSGBOX_DEFAULT
	closemessage
	release
	end

ValleyWindworks_Interior_EventScript_NPC4_2::
	msgbox ValleyWindworks_Interior_Text_NPC4_2, MSGBOX_DEFAULT
	closemessage
	release
	end

ValleyWindworks_Interior_EventScript_Trigger1::
	lockall
	getplayerxy VAR_0x8004, VAR_0x8005
	goto_if_eq VAR_0x8005, 6, ValleyWindworks_Interior_EventScript_Trigger1_2
	goto_if_eq VAR_0x8005, 7, ValleyWindworks_Interior_EventScript_Trigger1_2_2
	end

ValleyWindworks_Interior_EventScript_Trigger1_2::
	playse SE_PIN
	applymovement LOCALID_VALLEY_WINDWORKS_INTERIOR_MARS, ValleyWindworks_Interior_Movement_Mars
	waitmovement 0
	goto ValleyWindworks_Interior_EventScript_Trigger1_2_3

ValleyWindworks_Interior_EventScript_Trigger1_2_2::
	playse SE_PIN
	applymovement LOCALID_VALLEY_WINDWORKS_INTERIOR_MARS, ValleyWindworks_Interior_Movement_Mars2
	waitmovement 0
	goto ValleyWindworks_Interior_EventScript_Trigger1_2_3

ValleyWindworks_Interior_EventScript_Trigger1_2_3::
	msgbox ValleyWindworks_Interior_Text_Trigger1, MSGBOX_DEFAULT
	closemessage
	@ TODO(DP): Scripted battle against DP trainer #295 (Commander Mars)
	msgbox ValleyWindworks_Interior_Text_Trigger1_2, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_VALLEY_WINDWORKS_INTERIOR_MARS
	removeobject LOCALID_VALLEY_WINDWORKS_INTERIOR_GALACTIC_GRUNT_4
	removeobject LOCALID_VALLEY_WINDWORKS_INTERIOR_GALACTIC_GRUNT_2
	removeobject LOCALID_VALLEY_WINDWORKS_INTERIOR_GALACTIC_GRUNT_3
	setflag FLAG_VALLEY_WINDWORKS_INTERIOR_TRIGGER_1
	setflag FLAG_HIDE_ROUTE205_GALACTIC_GRUNT
	setvar VAR_ROUTE205_STATE, 2
	@ TODO(DP): Set DP system flag 2728
	fadescreen FADE_FROM_BLACK
	getplayerxy VAR_0x8004, VAR_0x8005
	goto_if_eq VAR_0x8005, 6, ValleyWindworks_Interior_EventScript_Trigger1_2_5
	goto_if_eq VAR_0x8005, 7, ValleyWindworks_Interior_EventScript_Trigger1_2_6
	end

ValleyWindworks_Interior_EventScript_Trigger1_2_4::
	releaseall
	end

ValleyWindworks_Interior_EventScript_Trigger1_2_5::
	applymovement LOCALID_VALLEY_WINDWORKS_INTERIOR_ASSISTANT, ValleyWindworks_Interior_Movement_Assistant
	waitmovement 0
	goto ValleyWindworks_Interior_EventScript_Trigger1_2_7

ValleyWindworks_Interior_EventScript_Trigger1_2_6::
	applymovement LOCALID_VALLEY_WINDWORKS_INTERIOR_ASSISTANT, ValleyWindworks_Interior_Movement_Assistant2
	waitmovement 0
	goto ValleyWindworks_Interior_EventScript_Trigger1_2_7

ValleyWindworks_Interior_EventScript_Trigger1_2_7::
	msgbox ValleyWindworks_Interior_Text_Trigger1_3, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_HIDE_ROUTE205_LITTLE_GIRL
	clearflag FLAG_HIDE_VALLEY_WINDWORKS_INTERIOR_LITTLE_GIRL
	setobjectmovementtype LOCALID_VALLEY_WINDWORKS_INTERIOR_LITTLE_GIRL, MOVEMENT_TYPE_FACE_LEFT
	clearflag FLAG_HIDE_VALLEY_WINDWORKS_INTERIOR_LITTLE_GIRL
	addobject LOCALID_VALLEY_WINDWORKS_INTERIOR_LITTLE_GIRL
	lock
	getplayerxy VAR_0x8004, VAR_0x8005
	goto_if_eq VAR_0x8005, 6, ValleyWindworks_Interior_EventScript_Trigger1_2_8
	goto_if_eq VAR_0x8005, 7, ValleyWindworks_Interior_EventScript_Trigger1_2_9
	end

ValleyWindworks_Interior_EventScript_Trigger1_2_8::
	applymovement LOCALID_VALLEY_WINDWORKS_INTERIOR_LITTLE_GIRL, ValleyWindworks_Interior_Movement_LittleGirl
	applymovement LOCALID_VALLEY_WINDWORKS_INTERIOR_ASSISTANT, ValleyWindworks_Interior_Movement_Assistant3
	waitmovement 0
	goto ValleyWindworks_Interior_EventScript_Trigger1_2_10

ValleyWindworks_Interior_EventScript_Trigger1_2_9::
	applymovement LOCALID_VALLEY_WINDWORKS_INTERIOR_LITTLE_GIRL, ValleyWindworks_Interior_Movement_LittleGirl2
	applymovement LOCALID_VALLEY_WINDWORKS_INTERIOR_ASSISTANT, ValleyWindworks_Interior_Movement_Assistant4
	waitmovement 0
	goto ValleyWindworks_Interior_EventScript_Trigger1_2_10

ValleyWindworks_Interior_EventScript_Trigger1_2_10::
	msgbox ValleyWindworks_Interior_Text_Trigger1_4, MSGBOX_DEFAULT
	closemessage
	getplayerxy VAR_0x8004, VAR_0x8005
	goto_if_eq VAR_0x8005, 6, ValleyWindworks_Interior_EventScript_Trigger1_2_11
	goto_if_eq VAR_0x8005, 7, ValleyWindworks_Interior_EventScript_Trigger1_2_12
	end

ValleyWindworks_Interior_EventScript_Trigger1_2_11::
	applymovement LOCALID_VALLEY_WINDWORKS_INTERIOR_ASSISTANT, ValleyWindworks_Interior_Movement_Assistant5
	waitmovement 0
	goto ValleyWindworks_Interior_EventScript_Trigger1_2_13

ValleyWindworks_Interior_EventScript_Trigger1_2_12::
	applymovement LOCALID_VALLEY_WINDWORKS_INTERIOR_ASSISTANT, ValleyWindworks_Interior_Movement_Assistant6
	waitmovement 0
	goto ValleyWindworks_Interior_EventScript_Trigger1_2_13

ValleyWindworks_Interior_EventScript_Trigger1_2_13::
	setspeaker ValleyWindworks_Interior_Text_PapaSpeaker
	msgbox ValleyWindworks_Interior_Text_Trigger1_5, MSGBOX_DEFAULT
	msgbox ValleyWindworks_Interior_Text_Trigger1_6, MSGBOX_DEFAULT
	closemessage
	setvar VAR_VALLEY_WINDWORKS_STATE, 2
	@ TODO(DP): Set DP system flag 2440
	releaseall
	end

ValleyWindworks_Interior_OnTransition::
	@ DP: set system flag 2499 (not needed here)
	goto_if_ge VAR_ROUTE205_STATE, 2, ValleyWindworks_Interior_OnTransition_2
	end

ValleyWindworks_Interior_OnTransition_2::
	setobjectxyperm LOCALID_VALLEY_WINDWORKS_INTERIOR_LITTLE_GIRL, 21, 5
	setobjectmovementtype LOCALID_VALLEY_WINDWORKS_INTERIOR_LITTLE_GIRL, MOVEMENT_TYPE_FACE_LEFT
	setobjectmovementtype LOCALID_VALLEY_WINDWORKS_INTERIOR_LITTLE_GIRL, MOVEMENT_TYPE_FACE_LEFT
	setobjectxyperm LOCALID_VALLEY_WINDWORKS_INTERIOR_ASSISTANT, 18, 4
	setobjectmovementtype LOCALID_VALLEY_WINDWORKS_INTERIOR_ASSISTANT, MOVEMENT_TYPE_FACE_DOWN
	setobjectmovementtype LOCALID_VALLEY_WINDWORKS_INTERIOR_ASSISTANT, MOVEMENT_TYPE_FACE_DOWN
	end

ValleyWindworks_Interior_EventScript_OnFrame::
	lockall
	msgbox ValleyWindworks_Interior_Text_OnFrame, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_VALLEY_WINDWORKS_INTERIOR_GALACTIC_GRUNT, ValleyWindworks_Interior_Movement_GalacticGrunt
	waitmovement 0
	removeobject LOCALID_VALLEY_WINDWORKS_INTERIOR_GALACTIC_GRUNT
	setvar VAR_VALLEY_WINDWORKS_STATE, 1
	releaseall
	end

ValleyWindworks_Interior_OnFrame:
	map_script_2 VAR_VALLEY_WINDWORKS_STATE, 0, ValleyWindworks_Interior_EventScript_OnFrame
	.2byte 0

ValleyWindworks_Interior_Movement_Mars:
	emote_exclamation_mark
	walk_up
	walk_in_place_left
	step_end

ValleyWindworks_Interior_Movement_Mars2:
	emote_exclamation_mark
	walk_in_place_left
	step_end

ValleyWindworks_Interior_Movement_Assistant:
	walk_down
	walk_down
	walk_down
	walk_left
	step_end

ValleyWindworks_Interior_Movement_Assistant2:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	step_end

ValleyWindworks_Interior_Movement_LittleGirl:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_in_place_fast_up
	step_end

ValleyWindworks_Interior_Movement_Assistant3:
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	walk_in_place_down
	step_end

ValleyWindworks_Interior_Movement_LittleGirl2:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_in_place_fast_down
	step_end

ValleyWindworks_Interior_Movement_Assistant4:
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	walk_in_place_up
	step_end

ValleyWindworks_Interior_Movement_Assistant5:
	face_right
	delay_16
	delay_16
	face_left
	delay_16
	delay_16
	face_down
	step_end

ValleyWindworks_Interior_Movement_Assistant6:
	face_right
	delay_16
	delay_16
	face_left
	delay_16
	delay_16
	face_up
	step_end

ValleyWindworks_Interior_Movement_GalacticGrunt:
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

ValleyWindworks_Interior_Text_NPC4:
	.string "Oh, yes, a balloon Pokémon appears in\n"
	.string "front of the windworks.\p"
	.string "It's always a certain day of the week,\n"
	.string "but I'm not sure which day.\p"
	.string "Could its appearance have something to\n"
	.string "do with this windworks using\l"
	.string "wind-generated energy?$"

ValleyWindworks_Interior_Text_NPC4_2:
	.string "The Valley Windworks uses turbines to\n"
	.string "capture energy from winds driven from\l"
	.string "the mountains in this canyon.\p"
	.string "We produce energy from the power of\n"
	.string "nature itself. It's quite wonderful.$"

ValleyWindworks_Interior_Text_Trigger1:
	.string "I'm one of Team Galactic's three\n"
	.string "Commanders.\p"
	.string "We've been trying to create a new world\n"
	.string "that's better than this one...\p"
	.string "But people have shown little\n"
	.string "understanding about what we do.\p"
	.string "You don't understand either, do you?\n"
	.string "It's a little saddening...\p"
	.string "So, let's have a battle to decide what\n"
	.string "we should do next.\p"
	.string "If I win, you leave.\p"
	.string "If you win, we, Team Galactic, will leave!$"

ValleyWindworks_Interior_Text_Trigger1_2:
	.string "Oops! I messed that one up!\p"
	.string "That's all right, though. I quite\n"
	.string "enjoyed our battle.\p"
	.string "I guess it's time to say good-bye and\n"
	.string "leave for the time being!$"

ValleyWindworks_Interior_Text_Trigger1_3:
	.string "Team Galactic...\p"
	.string "They were saying they had to gather\n"
	.string "Pokémon and energy no matter what.\p"
	.string "It was for creating a new universe, or\n"
	.string "so they claimed.\p"
	.string "Nothing they said made any sort of\n"
	.string "sense to me.\p"
	.string "I can't tell you how grateful I am for\n"
	.string "saving me.\p"
	.string "I can finally see my little daughter\n"
	.string "again!$"

ValleyWindworks_Interior_Text_Trigger1_4:
	.string "Little girl: Papa!\p"
	.string "Yuck! Papa, you're stinky! Go shower\n"
	.string "now, stinky!$"

ValleyWindworks_Interior_Text_Trigger1_5:
	.string "Oh, sorry! Ahaha! They had me working\n"
	.string "nonstop!$"

ValleyWindworks_Interior_Text_Trigger1_6:
	.string "Little girl: Thank you, Trainer! You made\n"
	.string "those bad people go away!\p"
	.string "I think the balloon Pokémon will come\n"
	.string "visiting again!$"

ValleyWindworks_Interior_Text_OnFrame:
	.string "What?! No way! You have the key?\p"
	.string "Locking the door was meaningless! I am\n"
	.string "the loser in this after all!\p"
	.string "This is no time for self-pity! I've got\n"
	.string "to alert the Commander!$"

ValleyWindworks_Interior_Text_PapaSpeaker:
	.string "Papa$"
