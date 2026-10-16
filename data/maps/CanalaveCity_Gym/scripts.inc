CanalaveCity_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CanalaveCity_Gym_OnTransition
	.byte 0

CanalaveCity_Gym_EventScript_Trainer1::
	trainerbattle_single TRAINER_CANALAVE_CITY_GYM_1, CanalaveCity_Gym_Text_Trainer1Intro, CanalaveCity_Gym_Text_Trainer1Defeated
	msgbox CanalaveCity_Gym_Text_Trainer1PostBattle, MSGBOX_AUTOCLOSE
	end

CanalaveCity_Gym_Text_Trainer1Intro:
	.string "Steel represents an unbending spirit!\p"
	.string "If one refuses to accept defeat, the\n"
	.string "path to victory reveals itself!$"

CanalaveCity_Gym_Text_Trainer1Defeated:
	.string "I never gave up, but still I failed to\n"
	.string "win...$"

CanalaveCity_Gym_Text_Trainer1PostBattle:
	.string "If you give up, well, that's when\n"
	.string "everything ends for you!$"

CanalaveCity_Gym_EventScript_Trainer2::
	trainerbattle_single TRAINER_CANALAVE_CITY_GYM_2, CanalaveCity_Gym_Text_Trainer2Intro, CanalaveCity_Gym_Text_Trainer2Defeated
	msgbox CanalaveCity_Gym_Text_Trainer2PostBattle, MSGBOX_AUTOCLOSE
	end

CanalaveCity_Gym_Text_Trainer2Intro:
	.string "A Pokémon Gym isn't only about seeing\n"
	.string "how tough your Pokémon happen to be.\p"
	.string "It's so much deeper than just that. It's\n"
	.string "a test of you as a person.$"

CanalaveCity_Gym_Text_Trainer2Defeated:
	.string "That move was devastating!$"

CanalaveCity_Gym_Text_Trainer2PostBattle:
	.string "I get to work all day with my Pokémon,\n"
	.string "and even battle sometimes.\p"
	.string "I get all the fun I need every day!$"

CanalaveCity_Gym_EventScript_Trainer3::
	trainerbattle_single TRAINER_CANALAVE_CITY_GYM_3, CanalaveCity_Gym_Text_Trainer3Intro, CanalaveCity_Gym_Text_Trainer3Defeated
	msgbox CanalaveCity_Gym_Text_Trainer3PostBattle, MSGBOX_AUTOCLOSE
	end

CanalaveCity_Gym_Text_Trainer3Intro:
	.string "An ace has the knowledge and\n"
	.string "experience of battling at high levels.\p"
	.string "I'll demonstrate what that means to a\n"
	.string "noob like you!$"

CanalaveCity_Gym_Text_Trainer3Defeated:
	.string "Wow... I'm in the mood to sing a lullaby...$"

CanalaveCity_Gym_Text_Trainer3PostBattle:
	.string "Your earnest enthusiasm... I guess that\n"
	.string "kinda makes you an ace.\p"
	.string "Maybe you're a Trainer who has the\n"
	.string "potential to surpass aces!$"

CanalaveCity_Gym_EventScript_Trainer4::
	trainerbattle_single TRAINER_CANALAVE_CITY_GYM_4, CanalaveCity_Gym_Text_Trainer4Intro, CanalaveCity_Gym_Text_Trainer4Defeated
	msgbox CanalaveCity_Gym_Text_Trainer4PostBattle, MSGBOX_AUTOCLOSE
	end

CanalaveCity_Gym_Text_Trainer4Intro:
	.string "By focusing on only one type, you can\n"
	.string "really see the strengths and\l"
	.string "weaknesses of that Pokémon.$"

CanalaveCity_Gym_Text_Trainer4Defeated:
	.string "My focus was too narrow minded...$"

CanalaveCity_Gym_Text_Trainer4PostBattle:
	.string "Start by becoming friendly with your\n"
	.string "Pokémon. I mean really friendly.\p"
	.string "If you do that, you'll learn naturally\n"
	.string "how you should battle with it.$"

CanalaveCity_Gym_EventScript_Trainer5::
	trainerbattle_single TRAINER_CANALAVE_CITY_GYM_5, CanalaveCity_Gym_Text_Trainer5Intro, CanalaveCity_Gym_Text_Trainer5Defeated
	msgbox CanalaveCity_Gym_Text_Trainer5PostBattle, MSGBOX_AUTOCLOSE
	end

CanalaveCity_Gym_Text_Trainer5Intro:
	.string "Aiyaah! We're coming out swinging with\n"
	.string "super-heavy judo chops!$"

CanalaveCity_Gym_Text_Trainer5Defeated:
	.string "That was... A complete trashing!$"

CanalaveCity_Gym_Text_Trainer5PostBattle:
	.string "I must rededicate myself to training.\n"
	.string "The road extends into infinity...$"

CanalaveCity_Gym_EventScript_Trainer6::
	trainerbattle_single TRAINER_CANALAVE_CITY_GYM_6, CanalaveCity_Gym_Text_Trainer6Intro, CanalaveCity_Gym_Text_Trainer6Defeated
	msgbox CanalaveCity_Gym_Text_Trainer6PostBattle, MSGBOX_AUTOCLOSE
	end

CanalaveCity_Gym_Text_Trainer6Intro:
	.string "Up and down you go on the lifts. Me? I\n"
	.string "like to battle!$"

CanalaveCity_Gym_Text_Trainer6Defeated:
	.string "You've got me feeling down!$"

CanalaveCity_Gym_Text_Trainer6PostBattle:
	.string "I can't keep this up! I'll go back to\n"
	.string "working on the lifts.$"

CanalaveCity_Gym_EventScript_Trainer7::
	trainerbattle_single TRAINER_CANALAVE_CITY_GYM_7, CanalaveCity_Gym_Text_Trainer7Intro, CanalaveCity_Gym_Text_Trainer7Defeated
	msgbox CanalaveCity_Gym_Text_Trainer7PostBattle, MSGBOX_AUTOCLOSE
	end

CanalaveCity_Gym_Text_Trainer7Intro:
	.string "Pokémon and people have worked\n"
	.string "together for many years.\p"
	.string "Let us show you an example of that\n"
	.string "history!$"

CanalaveCity_Gym_Text_Trainer7Defeated:
	.string "A spectacular loss! But it's still a\n"
	.string "loss!$"

CanalaveCity_Gym_Text_Trainer7PostBattle:
	.string "The way you helped each other... That is\n"
	.string "what made you prevail!$"

CanalaveCity_Gym_EventScript_NPC1::
	lock
	faceplayer
	goto_if_set FLAG_BADGE06_GET, CanalaveCity_Gym_EventScript_NPC1_2
	msgbox CanalaveCity_Gym_Text_NPC1_2, MSGBOX_DEFAULT
	closemessage
	release
	end

CanalaveCity_Gym_EventScript_NPC1_2::
	msgbox CanalaveCity_Gym_Text_NPC1_3, MSGBOX_DEFAULT
	closemessage
	release
	end

CanalaveCity_Gym_EventScript_NPC2::
	lock
	faceplayer
	goto_if_set FLAG_BADGE06_GET, CanalaveCity_Gym_EventScript_NPC2_2
	@ TODO(DP): DeActivateLeader 9, 35, 0, 0, 0
	msgbox CanalaveCity_Gym_Text_NPC2_2, MSGBOX_DEFAULT
	closemessage
	@ TODO(DP): Scripted battle against DP trainer #250 (Leader Byron)
	msgbox CanalaveCity_Gym_Text_NPC2_3, MSGBOX_DEFAULT
	message CanalaveCity_Gym_Text_NPC2_4
	waitmessage
	playfanfare MUS_OBTAIN_BADGE
	waitfanfare
	setflag FLAG_BADGE06_GET
	@ TODO(DP): AddSpecialGameStat 23
	@ TODO(DP): Mark DP trainer #232 beaten
	@ TODO(DP): Mark DP trainer #256 beaten
	@ TODO(DP): Mark DP trainer #257 beaten
	@ TODO(DP): Mark DP trainer #279 beaten
	@ TODO(DP): Mark DP trainer #283 beaten
	@ TODO(DP): Mark DP trainer #314 beaten
	@ TODO(DP): Mark DP trainer #367 beaten
	@ TODO(DP): DeActivateLeader 10, 35, 250, 0, 0
	clearflag FLAG_HIDE_CANALAVE_CITY_BARRY
	clearflag FLAG_CANALAVE_CITY_GYM_CANDICE_1
	clearflag FLAG_CANALAVE_CITY_GYM_CANDICE_2
	clearflag FLAG_CANALAVE_CITY_GYM_CANDICE_3
	setvar VAR_CANALAVE_CITY_STATE_2, 2
	setflag FLAG_CANALAVE_CITY_GYM_CANDICE_4
	msgbox CanalaveCity_Gym_Text_NPC2_5, MSGBOX_DEFAULT
	goto CanalaveCity_Gym_EventScript_NPC2_2_3

CanalaveCity_Gym_EventScript_NPC2_2::
	goto_if_unset FLAG_CANALAVE_CITY_GYM_CANDICE_5, CanalaveCity_Gym_EventScript_NPC2_2_3
	msgbox CanalaveCity_Gym_Text_NPC2_6, MSGBOX_DEFAULT
	closemessage
	release
	end

CanalaveCity_Gym_EventScript_NPC2_2_2::
	release
	end

CanalaveCity_Gym_EventScript_NPC2_2_3::
	setvar VAR_0x8004, ITEM_TM_FLASH_CANNON
	setvar VAR_0x8005, 1
	checkitemspace VAR_0x8004, VAR_0x8005
	goto_if_eq VAR_RESULT, FALSE, CanalaveCity_Gym_EventScript_NPC2_2_4
	giveitem VAR_0x8004, VAR_0x8005
	setflag FLAG_CANALAVE_CITY_GYM_CANDICE_5
	bufferitemname STR_VAR_1, VAR_0x8004
	@ TODO(DP): move name into STR_VAR_2
	msgbox CanalaveCity_Gym_Text_NPC2_7, MSGBOX_DEFAULT
	closemessage
	release
	end

CanalaveCity_Gym_EventScript_NPC2_2_4::
	msgbox gText_TooBadBagIsFull, MSGBOX_DEFAULT
	closemessage
	release
	end

CanalaveCity_Gym_EventScript_Sign1::
	lockall
	goto_if_set FLAG_BADGE06_GET, CanalaveCity_Gym_EventScript_Sign1_2
	msgbox CanalaveCity_Gym_Text_Sign1_2, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

CanalaveCity_Gym_EventScript_Sign1_2::
	msgbox CanalaveCity_Gym_Text_Sign1_3, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

CanalaveCity_Gym_EventScript_Sign2::
	goto CanalaveCity_Gym_EventScript_Sign1
	end

CanalaveCity_Gym_OnTransition::
	@ TODO(DP): InitCanalaveGym
	end

CanalaveCity_Gym_Text_NPC1_2:
	.string "Hey, there! Champ-to-be!\p"
	.string "The Gym Leader here uses Steel-type\n"
	.string "Pokémon.\p"
	.string "Steel-type Pokémon have high Defense,\n"
	.string "so you'd have to hit them hard!$"

CanalaveCity_Gym_Text_NPC1_3:
	.string "Oh! {PLAYER}! You've beaten the Gym\n"
	.string "Leader!\p"
	.string "Good going! That makes it six Gym\n"
	.string "Badges!\p"
	.string "I tell you what, you're really turning\n"
	.string "into one fine Trainer.\p"
	.string "If you were to say you're going to try\n"
	.string "to become the Pokémon Champ...\p"
	.string "No one'd laugh at you now! I'm in your\n"
	.string "corner, kiddo!$"

CanalaveCity_Gym_Text_NPC2_2:
	.string "Ah! That's {COLOR DYNAMIC_COLOR3}Oreburgh{COLOR DARK_GRAY}'s Gym Badge!\p"
	.string "I see, I see! You've defeated my son.\p"
	.string "But that's no surprise. He still has\n"
	.string "much to learn.\p"
	.string "In place of my son Roark, I, Byron, will\n"
	.string "take your challenge!$"

CanalaveCity_Gym_Text_NPC2_3:
	.string "You were strong enough to take down my\n"
	.string "prized team of Pokémon.\p"
	.string "In recognition of that power, I give you\n"
	.string "this: the Mine Badge!$"

CanalaveCity_Gym_Text_NPC2_4:
	.string "{PLAYER} received the Mine Badge from\n"
	.string "Byron!$"

CanalaveCity_Gym_Text_NPC2_5:
	.string "Having the Mine Badge enables you to\n"
	.string "use the hidden move Strength anytime\l"
	.string "outside of battle.\p"
	.string "And you now have six Gym Badges.\p"
	.string "That means all Pokémon up to Lv. 70 will\n"
	.string "obey you without question.\p"
	.string "Here! Take this, too!$"

CanalaveCity_Gym_Text_NPC2_6:
	.string "Gwahahahaha! The {COLOR DYNAMIC_COLOR3}Sinnoh{COLOR DARK_GRAY} region is vast!\p"
	.string "Tough Trainers like you and {RIVAL}\n"
	.string "crop up constantly to challenge the old\l"
	.string "guard!\p"
	.string "With more young Trainers like my son and\n"
	.string "you two taking charge, the future of\l"
	.string "Pokémon is bright!\p"
	.string "But I'm not stepping aside just yet!\p"
	.string "I merely need to rededicate myself to\n"
	.string "training on Iron Island.$"

CanalaveCity_Gym_Text_NPC2_7:
	.string "That {STR_VAR_1} contains the move\n"
	.string "{STR_VAR_2}.\p"
	.string "If it hits, it may also lower the\n"
	.string "target's Special Defense.$"

CanalaveCity_Gym_Text_Sign1_2:
	.string "Canalave City Pokémon Gym Leader:\n"
	.string "Byron Certified Trainers: {RIVAL}$"

CanalaveCity_Gym_Text_Sign1_3:
	.string "Canalave City Pokémon Gym Leader:\n"
	.string "Byron Certified Trainers: {RIVAL}\l"
	.string "{PLAYER}$"
