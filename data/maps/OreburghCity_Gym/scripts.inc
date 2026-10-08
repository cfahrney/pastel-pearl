OreburghCity_Gym_MapScripts::
	.byte 0

OreburghCity_Gym_EventScript_Trainer1::
	trainerbattle_single TRAINER_OREBURGH_CITY_GYM_1, OreburghCity_Gym_Text_Trainer1Intro, OreburghCity_Gym_Text_Trainer1Defeated
	msgbox OreburghCity_Gym_Text_Trainer1PostBattle, MSGBOX_AUTOCLOSE
	end

OreburghCity_Gym_EventScript_Trainer2::
	trainerbattle_single TRAINER_OREBURGH_CITY_GYM_2, OreburghCity_Gym_Text_Trainer2Intro, OreburghCity_Gym_Text_Trainer2Defeated
	msgbox OreburghCity_Gym_Text_Trainer2PostBattle, MSGBOX_AUTOCLOSE
	end

OreburghCity_Gym_EventScript_Trainer3::
	@ poe:behavior {"reward":{"item":"ITEM_TM_STEALTH_ROCK","qty":1},"setStates":[{"var":"VAR_OREBURGH_CITY_STATE","value":3},{"var":"VAR_JUBILIFE_CITY_STATE","value":5}],"gym":{"badge":1}}
	trainerbattle_single TRAINER_OREBURGH_CITY_GYM_3, OreburghCity_Gym_Text_Trainer3Intro, OreburghCity_Gym_Text_Trainer3Defeated, OreburghCity_Gym_EventScript_Trainer3Won, NO_MUSIC
	goto_if_unset FLAG_OREBURGHCITY_GYM_TRAINER3_REWARD, OreburghCity_Gym_EventScript_Trainer3Reward
	setspeaker SP_NAME_ROARK
	msgbox OreburghCity_Gym_Text_Trainer3PostBattle, MSGBOX_AUTOCLOSE
	end

OreburghCity_Gym_EventScript_Trainer3Badge::
	special DefeatMapTrainers
	setspeaker SP_NAME_ROARK
	msgbox OreburghCity_Gym_Text_Trainer3BadgeIntro, MSGBOX_DEFAULT
	setspeaker SP_NAME_NONE
	message OreburghCity_Gym_Text_Trainer3Badge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	setspeaker SP_NAME_ROARK
	msgbox OreburghCity_Gym_Text_Trainer3BadgeInfo, MSGBOX_DEFAULT
	setflag FLAG_BADGE01_GET
	goto OreburghCity_Gym_EventScript_Trainer3Reward

OreburghCity_Gym_EventScript_Trainer3Reward::
	lock
	faceplayer
	setspeaker SP_NAME_ROARK
	msgbox OreburghCity_Gym_Text_Trainer3Reward, MSGBOX_DEFAULT
	setspeaker SP_NAME_NONE
	giveitem ITEM_TM_STEALTH_ROCK, 1
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_OREBURGHCITY_GYM_TRAINER3_REWARD
	setspeaker SP_NAME_ROARK
	msgbox OreburghCity_Gym_Text_Trainer3RewardAfter, MSGBOX_DEFAULT
	release
	end

OreburghCity_Gym_EventScript_Trainer3Won::
	setvar VAR_OREBURGH_CITY_STATE, 3
	setvar VAR_JUBILIFE_CITY_STATE, 5
	goto OreburghCity_Gym_EventScript_Trainer3Badge

OreburghCity_Gym_Text_Trainer3BadgeIntro::
	.string "This is embarrassing...\p"
	.string "I went and lost to a Trainer who didn't\n"
	.string "have a single Gym Badge...\p"
	.string "But that's tough. You were strong, and I\n"
	.string "was weak. That's all there is.\p"
	.string "According to the Pokémon League rules,\n"
	.string "I have to give you our Gym Badge since\l"
	.string "you've beaten me, the Leader. Here's\l"
	.string "your official Pokémon League Coal\l"
	.string "Badge.$"

OreburghCity_Gym_Text_Trainer3Badge::
	.string "{PLAYER} received the Coal Badge from\n"
	.string "Roark!$"

OreburghCity_Gym_Text_Trainer3BadgeInfo::
	.string "Having that Coal Badge means your\n"
	.string "Pokémon can now use the hidden move\l"
	.string "Rock Smash outside of battle.$"

OreburghCity_Gym_Text_Trainer3RewardAfter::
	.string "That TM76 contains the move Stealth\n"
	.string "Rock. It's a move that inflicts damage\l"
	.string "on foes that switch into battle.\l"
	.string "Incidentally, a TM will teach its move to\l"
	.string "a Pokémon instantly. And they're\l"
	.string "unlimited use, too!$"

OreburghCity_Gym_Text_Trainer3Reward::
	.string "You should also take this, too.$"

OreburghCity_Gym_EventScript_NPC1::
	@ poe:behavior {"mode":"plain","options":[{"id":0,"cond":{"var":"VAR_OREBURGH_CITY_STATE","op":"ge","value":3}},{"id":1,"cond":{"var":"VAR_OREBURGH_CITY_STATE","op":"lt","value":3}}]}
	goto_if_ge VAR_OREBURGH_CITY_STATE, 3, OreburghCity_Gym_EventScript_NPC1Var0
	msgbox OreburghCity_Gym_Text_NPC1Var1, MSGBOX_NPC
	end

OreburghCity_Gym_EventScript_NPC1Var0::
	msgbox OreburghCity_Gym_Text_NPC1, MSGBOX_NPC
	end

OreburghCity_Gym_Text_NPC1Var1::
	.string "Yo! Champ in the making!\p"
	.string "Roark is a master of Rock-type\n"
	.string "Pokémon, you hear? I hope you have\l"
	.string "something to handle that crazy\l"
	.string "defense.$"

OreburghCity_Gym_Text_Trainer1Intro:
	.string "You avoided the long way around?\n"
	.string "Let's see why you'd do that!$"

OreburghCity_Gym_Text_Trainer1Defeated:
	.string "Now I understand why you decided to\n"
	.string "battle with me.$"

OreburghCity_Gym_Text_Trainer1PostBattle:
	.string "You should go whichever way you want,\n"
	.string "shortcut or the long way!$"

OreburghCity_Gym_Text_Trainer2Intro:
	.string "Only those who want to win can\n"
	.string "challenge a Pokémon Gym!$"

OreburghCity_Gym_Text_Trainer2Defeated:
	.string "Gggh...\n"
	.string "This is humiliating!$"

OreburghCity_Gym_Text_Trainer2PostBattle:
	.string "One day, I'm going to become a tough\n"
	.string "Trainer like you.$"

OreburghCity_Gym_Text_Trainer3Intro:
	.string "Welcome!\n"
	.string "This is the Oreburgh Pokémon Gym!\p"
	.string "I'm Roark, the Gym Leader!\p"
	.string "I'm but one Trainer who decided to walk\n"
	.string "proudly with Rock-type Pokémon!\p"
	.string "As the Gym Leader, I need to see your\n"
	.string "potential as a Trainer.\p"
	.string "And, I'll need to see the toughness of\n"
	.string "the Pokémon that battle with you!$"

OreburghCity_Gym_Text_Trainer3Defeated:
	.string "W-what? That can't be!\n"
	.string "My buffed-up Pokémon!$"

OreburghCity_Gym_Text_Trainer3PostBattle:
	.string "In this region of {COLOR DYNAMIC_COLOR3}Sinnoh{COLOR DARK_GRAY}, there are\n"
	.string "seven other Gym Leaders.\p"
	.string "I should warn you-- they're a lot\n"
	.string "tougher than I am!$"

OreburghCity_Gym_Text_NPC1:
	.string "Oh! PLAYER!\n"
	.string "You've taken care of the Gym Leader!\p"
	.string "So, did my advice come in handy or what?\p"
	.string "If my advice was useful, it'd be great if\n"
	.string "you'd become my fan!$"

OreburghCity_Gym_EventScript_NPC2::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SHIELDON, CRY_MODE_NORMAL
	setspeaker OreburghCity_Gym_Text_NPC2Speaker
	msgbox OreburghCity_Gym_Text_NPC2, MSGBOX_DEFAULT
	waitmoncry
	release
	end

OreburghCity_Gym_Text_NPC2Speaker:
	.string "Shieldon$"

OreburghCity_Gym_Text_NPC2:
	.string "Shiiiield!$"

OreburghCity_Gym_EventScript_NPC3::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_CRANIDOS, CRY_MODE_NORMAL
	setspeaker OreburghCity_Gym_Text_NPC3Speaker
	msgbox OreburghCity_Gym_Text_NPC3, MSGBOX_DEFAULT
	waitmoncry
	release
	end

OreburghCity_Gym_Text_NPC3Speaker:
	.string "Cranidos$"

OreburghCity_Gym_Text_NPC3:
	.string "Craaanidos.$"
