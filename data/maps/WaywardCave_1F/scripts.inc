WaywardCave_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, WaywardCave_1F_OnTransition
	.byte 0

WaywardCave_1F_EventScript_NPC1::
	lock
	faceplayer
	@ TODO(DP): RideBike 0
	goto_if_ge VAR_WAYWARD_CAVE_1F_STATE, 1, WaywardCave_1F_EventScript_NPC1_2
	call_if_unset FLAG_WAYWARD_CAVE_1F_NPC_1, WaywardCave_1F_EventScript_NPC1_2_2
	call_if_set FLAG_WAYWARD_CAVE_1F_NPC_1, WaywardCave_1F_EventScript_NPC1_2_3
	@ TODO(DP): fanfare SEQ_GONIN
	message WaywardCave_1F_Text_NPC1
	waitmessage
	waitfanfare
	setflag FLAG_WAYWARD_CAVE_1F_NPC_1
	setvar VAR_WAYWARD_CAVE_1F_STATE, 1
	setspeaker WaywardCave_1F_Text_MiraSpeaker
	msgbox WaywardCave_1F_Text_NPC1_2, MSGBOX_DEFAULT
	closemessage
	setvar VAR_ETERNA_FOREST_STATE_2, 612
	@ TODO(DP): StartFollow
	@ TODO(DP): SetEventMovement 4, 48
	release
	end

WaywardCave_1F_EventScript_NPC1_2::
	goto_if_ge VAR_WAYWARD_CAVE_1F_STATE_2, 2, WaywardCave_1F_EventScript_NPC1_2_4
	goto_if_eq VAR_WAYWARD_CAVE_1F_STATE_2, 1, WaywardCave_1F_EventScript_NPC1_2_5
	setspeaker WaywardCave_1F_Text_MiraSpeaker
	message WaywardCave_1F_Text_NPC1_3
	waitmessage
	goto WaywardCave_1F_EventScript_NPC1_2_6

WaywardCave_1F_EventScript_NPC1_2_2::
	msgbox WaywardCave_1F_Text_NPC1_4, MSGBOX_DEFAULT
	return

WaywardCave_1F_EventScript_NPC1_2_3::
	msgbox WaywardCave_1F_Text_NPC1_5, MSGBOX_DEFAULT
	return

WaywardCave_1F_EventScript_NPC1_2_4::
	setspeaker WaywardCave_1F_Text_MiraSpeaker
	msgbox WaywardCave_1F_Text_NPC1_6, MSGBOX_DEFAULT
	closemessage
	release
	end

WaywardCave_1F_EventScript_NPC1_2_5::
	setspeaker WaywardCave_1F_Text_MiraSpeaker
	message WaywardCave_1F_Text_NPC1_7
	waitmessage
	goto WaywardCave_1F_EventScript_NPC1_2_6

WaywardCave_1F_EventScript_NPC1_2_6::
	addvar VAR_WAYWARD_CAVE_1F_STATE_2, 1
	waitbuttonpress
	closemessage
	release
	end

WaywardCave_1F_EventScript_Trigger1::
	lockall
	@ TODO(DP): StopFollow
	@ TODO(DP): SetEventMovement 4, 16
	copyvar VAR_RESULT, VAR_FACING
	goto_if_eq VAR_RESULT, DIR_WEST, WaywardCave_1F_EventScript_Trigger1_2
	goto WaywardCave_1F_EventScript_Trigger1_2_2

WaywardCave_1F_EventScript_Trigger1_2::
	applymovement LOCALID_PLAYER, WaywardCave_1F_Movement_Player
	playse SE_PIN
	applymovement LOCALID_WAYWARD_CAVE_1_F_NPC, WaywardCave_1F_Movement_Npc
	waitmovement 0
	goto WaywardCave_1F_EventScript_Trigger1_2_3

WaywardCave_1F_EventScript_Trigger1_2_2::
	applymovement LOCALID_PLAYER, WaywardCave_1F_Movement_Player2
	playse SE_PIN
	applymovement LOCALID_WAYWARD_CAVE_1_F_NPC, WaywardCave_1F_Movement_Npc2
	waitmovement 0
	goto WaywardCave_1F_EventScript_Trigger1_2_3

WaywardCave_1F_EventScript_Trigger1_2_3::
	setspeaker WaywardCave_1F_Text_MiraSpeaker
	msgbox WaywardCave_1F_Text_Trigger1, MSGBOX_DEFAULT
	closemessage
	copyvar VAR_RESULT, VAR_FACING
	goto_if_eq VAR_RESULT, DIR_EAST, WaywardCave_1F_EventScript_Trigger1_2_4
	goto WaywardCave_1F_EventScript_Trigger1_2_5

WaywardCave_1F_EventScript_Trigger1_2_4::
	applymovement LOCALID_PLAYER, WaywardCave_1F_Movement_Player3
	applymovement LOCALID_WAYWARD_CAVE_1_F_NPC, WaywardCave_1F_Movement_Npc3
	waitmovement 0
	goto WaywardCave_1F_EventScript_Trigger1_2_6

WaywardCave_1F_EventScript_Trigger1_2_5::
	applymovement LOCALID_PLAYER, WaywardCave_1F_Movement_Player4
	applymovement LOCALID_WAYWARD_CAVE_1_F_NPC, WaywardCave_1F_Movement_Npc4
	waitmovement 0
	goto WaywardCave_1F_EventScript_Trigger1_2_6

WaywardCave_1F_EventScript_Trigger1_2_6::
	removeobject LOCALID_WAYWARD_CAVE_1_F_NPC
	setflag FLAG_WAYWARD_CAVE_1F_TRIGGER_1
	setvar VAR_WAYWARD_CAVE_1F_STATE, 2
	releaseall
	end

WaywardCave_1F_OnTransition::
	@ DP: set system flag 2519 (not needed here)
	goto_if_unset FLAG_WAYWARD_CAVE_1F_TRIGGER_1, WaywardCave_1F_OnTransition_2
	end

WaywardCave_1F_OnTransition_2::
	setvar VAR_WAYWARD_CAVE_1F_STATE, 0
	end

WaywardCave_1F_Movement_Player:
	walk_in_place_right
	step_end

WaywardCave_1F_Movement_Npc:
	walk_in_place_left
	emote_exclamation_mark
	step_end

WaywardCave_1F_Movement_Player2:
	walk_in_place_up
	step_end

WaywardCave_1F_Movement_Npc2:
	walk_in_place_down
	emote_exclamation_mark
	step_end

WaywardCave_1F_Movement_Player3:
	walk_up
	walk_in_place_down
	step_end

WaywardCave_1F_Movement_Npc3:
	delay_16
	delay_16
	delay_16
	walk_left
	walk_in_place_down
	step_end

WaywardCave_1F_Movement_Player4:
	walk_right
	walk_in_place_left
	step_end

WaywardCave_1F_Movement_Npc4:
	delay_16
	delay_16
	delay_16
	walk_down
	walk_in_place_down
	step_end

WaywardCave_1F_Text_NPC1:
	.string "{PLAYER} decided to go with Mira!$"

WaywardCave_1F_Text_NPC1_2:
	.string "I'll keep your Pokémon healthy all the\n"
	.string "time!$"

WaywardCave_1F_Text_NPC1_3:
	.string "I like helpful Pokémon moves like Growl\n"
	.string "and Minimize.\p"
	.string "Those kinds of moves are my favorites.$"

WaywardCave_1F_Text_NPC1_4:
	.string "I'm Mira...\p"
	.string "I was catching Pokémon, and then I got\n"
	.string "lost...\p"
	.string "I'm so scared...\p"
	.string "Please! Please take me to the exit!$"

WaywardCave_1F_Text_NPC1_5:
	.string "Trainer, your name is {PLAYER}?\p"
	.string "My name is Mira. I like your name!$"

WaywardCave_1F_Text_NPC1_6:
	.string "{PLAYER}, did you get to be so good\n"
	.string "because you're always with your\l"
	.string "Pokémon?\p"
	.string "Yes! That has to be it! Mira will try like\n"
	.string "you!$"

WaywardCave_1F_Text_NPC1_7:
	.string "This cave... It's so easy to get\n"
	.string "confused.\p"
	.string "Do you know where we are?$"

WaywardCave_1F_Text_Trigger1:
	.string "Oh! There's the exit!\p"
	.string "I want to get tougher so I won't be\n"
	.string "such a scaredy-cat.\p"
	.string "{PLAYER}, bye-bye! Thank you!$"

WaywardCave_1F_EventScript_Trainer1::
	trainerbattle_single TRAINER_WAYWARD_CAVE_1F_1, WaywardCave_1F_Text_Trainer1Intro, WaywardCave_1F_Text_Trainer1Defeated
	msgbox WaywardCave_1F_Text_Trainer1PostBattle, MSGBOX_AUTOCLOSE
	end

WaywardCave_1F_Text_Trainer1Intro:
	.string "Humph! You're lost, aren't you? I'll\n"
	.string "guide you if you can beat me.$"

WaywardCave_1F_Text_Trainer1Defeated:
	.string "I said I'm going to win!$"

WaywardCave_1F_Text_Trainer1PostBattle:
	.string "I'm not lost, I tell you! I'm camping!\n"
	.string "That's my story!$"

WaywardCave_1F_EventScript_Trainer2::
	trainerbattle_single TRAINER_WAYWARD_CAVE_1F_2, WaywardCave_1F_Text_Trainer2Intro, WaywardCave_1F_Text_Trainer2Defeated
	msgbox WaywardCave_1F_Text_Trainer2PostBattle, MSGBOX_AUTOCLOSE
	end

WaywardCave_1F_Text_Trainer2Intro:
	.string "Where am I? Am I lost? Who are you? Are\n"
	.string "you a Pokémon Trainer?$"

WaywardCave_1F_Text_Trainer2Defeated:
	.string "OK, so we're both Trainers. That's a\n"
	.string "start, right?$"

WaywardCave_1F_Text_Trainer2PostBattle:
	.string "I just wanted to have a picnic under\n"
	.string "the Cycling Road.\p"
	.string "I didn't think I would get lost in a\n"
	.string "place like this...$"

WaywardCave_1F_EventScript_Trainer3::
	trainerbattle_single TRAINER_WAYWARD_CAVE_1F_3, WaywardCave_1F_Text_Trainer3Intro, WaywardCave_1F_Text_Trainer3Defeated
	msgbox WaywardCave_1F_Text_Trainer3PostBattle, MSGBOX_AUTOCLOSE
	end

WaywardCave_1F_Text_Trainer3Intro:
	.string "Hush now, lost little Pokémon, don't you\n"
	.string "cry.\p"
	.string "I'm here to take care of you!$"

WaywardCave_1F_Text_Trainer3Defeated:
	.string "Sniffle... W-who's crying now?$"

WaywardCave_1F_Text_Trainer3PostBattle:
	.string "Speaking of crying, I'm positive I heard\n"
	.string "crying from deeper in the cave.$"

WaywardCave_1F_EventScript_Trainer4::
	trainerbattle_single TRAINER_WAYWARD_CAVE_1F_4, WaywardCave_1F_Text_Trainer4Intro, WaywardCave_1F_Text_Trainer4Defeated
	msgbox WaywardCave_1F_Text_Trainer4PostBattle, MSGBOX_AUTOCLOSE
	end

WaywardCave_1F_Text_Trainer4Intro:
	.string "Did you come to play, too? Wanna play\n"
	.string "battle with me?$"

WaywardCave_1F_Text_Trainer4Defeated:
	.string "You were just toying with me!$"

WaywardCave_1F_Text_Trainer4PostBattle:
	.string "I'm playing hide-and-seek here. I like\n"
	.string "some underground tag, too.$"

WaywardCave_1F_EventScript_Trainer5::
	trainerbattle_single TRAINER_WAYWARD_CAVE_1F_5, WaywardCave_1F_Text_Trainer5Intro, WaywardCave_1F_Text_Trainer5Defeated
	msgbox WaywardCave_1F_Text_Trainer5PostBattle, MSGBOX_AUTOCLOSE
	end

WaywardCave_1F_Text_Trainer5Intro:
	.string "Look! A Trainer lost in Wayward Cave!$"

WaywardCave_1F_Text_Trainer5Defeated:
	.string "I strayed from the battle plan!$"

WaywardCave_1F_Text_Trainer5PostBattle:
	.string "Me? No, I'm not lost. I live here!$"

WaywardCave_1F_EventScript_Trainer6::
	trainerbattle_single TRAINER_WAYWARD_CAVE_1F_6, WaywardCave_1F_Text_Trainer6Intro, WaywardCave_1F_Text_Trainer6Defeated
	msgbox WaywardCave_1F_Text_Trainer6PostBattle, MSGBOX_AUTOCLOSE
	end

WaywardCave_1F_Text_Trainer6Intro:
	.string "You look like you might just have the\n"
	.string "Pokémon I've been looking for!$"

WaywardCave_1F_Text_Trainer6Defeated:
	.string "You didn't have a single Pokémon I\n"
	.string "wanted... You're no Collector!$"

WaywardCave_1F_Text_Trainer6PostBattle:
	.string "I'm very picky, so I want to collect\n"
	.string "every Pokémon without anyone's help.\p"
	.string "...I do have friends, though. No,\n"
	.string "seriously! I do!$"

WaywardCave_1F_EventScript_Trainer7::
	trainerbattle_single TRAINER_WAYWARD_CAVE_1F_7, WaywardCave_1F_Text_Trainer7Intro, WaywardCave_1F_Text_Trainer7Defeated
	msgbox WaywardCave_1F_Text_Trainer7PostBattle, MSGBOX_AUTOCLOSE
	end

WaywardCave_1F_Text_Trainer7Intro:
	.string "What every good picnic needs is a cute\n"
	.string "setting, good food, and a fun battle!$"

WaywardCave_1F_Text_Trainer7Defeated:
	.string "That wasn't any fun for me!$"

WaywardCave_1F_Text_Trainer7PostBattle:
	.string "Why have a picnic here? I don't know.\n"
	.string "There's no deep meaning to it.$"

WaywardCave_1F_EventScript_Trainer8::
	trainerbattle_single TRAINER_WAYWARD_CAVE_1F_8, WaywardCave_1F_Text_Trainer8Intro, WaywardCave_1F_Text_Trainer8Defeated
	msgbox WaywardCave_1F_Text_Trainer8PostBattle, MSGBOX_AUTOCLOSE
	end

WaywardCave_1F_Text_Trainer8Intro:
	.string "Huh? Are you lost too? No? It doesn't\n"
	.string "matter.\p"
	.string "Let's have a quick Pokémon battle!$"

WaywardCave_1F_Text_Trainer8Defeated:
	.string "Not fair! We're not on the same level!$"

WaywardCave_1F_Text_Trainer8PostBattle:
	.string "I got separated from my friends...\p"
	.string "I've got my Pokémon with me, so I'm OK,\n"
	.string "but...$"

WaywardCave_1F_EventScript_Trainer9::
	trainerbattle_single TRAINER_WAYWARD_CAVE_1F_9, WaywardCave_1F_Text_Trainer9Intro, WaywardCave_1F_Text_Trainer9Defeated
	msgbox WaywardCave_1F_Text_Trainer9PostBattle, MSGBOX_AUTOCLOSE
	end

WaywardCave_1F_Text_Trainer9Intro:
	.string "In deep tunnels and caves, there're a\n"
	.string "couple things you're sure to see.\p"
	.string "Zubat and Ruin Maniacs!$"

WaywardCave_1F_Text_Trainer9Defeated:
	.string "Your awesome power... It's mystifying.$"

WaywardCave_1F_Text_Trainer9PostBattle:
	.string "I've scoured every inch of this place...\n"
	.string "Most of it while I was lost.\p"
	.string "Anyway, if there's one thing I can say,\n"
	.string "this place can't be called ruins!$"

WaywardCave_1F_EventScript_Trainer10::
	trainerbattle_single TRAINER_WAYWARD_CAVE_1F_10, WaywardCave_1F_Text_Trainer10Intro, WaywardCave_1F_Text_Trainer10Defeated
	msgbox WaywardCave_1F_Text_Trainer10PostBattle, MSGBOX_AUTOCLOSE
	end

WaywardCave_1F_Text_Trainer10Intro:
	.string "Wandering around, I got hungry, so I ate\n"
	.string "some wild mushrooms...\p"
	.string "They gave me gas, and now I can't stop\n"
	.string "burping! Bluurrf!$"

WaywardCave_1F_Text_Trainer10Defeated:
	.string "Bleff! Hurk! I think...I'm getting\n"
	.string "better...$"

WaywardCave_1F_Text_Trainer10PostBattle:
	.string "I hear there's a Pokémon that has\n"
	.string "mushrooms growing on its back.\p"
	.string "Not around here, somewhere far away. I\n"
	.string "wonder if they taste any good?$"

WaywardCave_1F_Text_MiraSpeaker:
	.string "Mira$"
