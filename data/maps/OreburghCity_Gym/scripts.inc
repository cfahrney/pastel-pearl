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
	trainerbattle_single TRAINER_OREBURGH_CITY_GYM_3, OreburghCity_Gym_Text_Trainer3Intro, OreburghCity_Gym_Text_Trainer3Defeated
	msgbox OreburghCity_Gym_Text_Trainer3PostBattle, MSGBOX_AUTOCLOSE
	end

OreburghCity_Gym_EventScript_NPC1::
	msgbox OreburghCity_Gym_Text_NPC1, MSGBOX_NPC
	end

OreburghCity_Gym_Text_Trainer1Intro:
	.string "GYM TRAINER 1\nwants to battle!$"

OreburghCity_Gym_Text_Trainer1Defeated:
	.string "GYM TRAINER 1\nwas defeated!$"

OreburghCity_Gym_Text_Trainer1PostBattle:
	.string "GYM TRAINER 1\nhas nothing else to say.$"

OreburghCity_Gym_Text_Trainer2Intro:
	.string "GYM TRAINER 2\nwants to battle!$"

OreburghCity_Gym_Text_Trainer2Defeated:
	.string "GYM TRAINER 2\nwas defeated!$"

OreburghCity_Gym_Text_Trainer2PostBattle:
	.string "GYM TRAINER 2\nhas nothing else to say.$"

OreburghCity_Gym_Text_Trainer3Intro:
	.string "GYM TRAINER 3\nwants to battle!$"

OreburghCity_Gym_Text_Trainer3Defeated:
	.string "GYM TRAINER 3\nwas defeated!$"

OreburghCity_Gym_Text_Trainer3PostBattle:
	.string "GYM TRAINER 3\nhas nothing else to say.$"

OreburghCity_Gym_Text_NPC1:
	.string "GYM NPC 1$"
