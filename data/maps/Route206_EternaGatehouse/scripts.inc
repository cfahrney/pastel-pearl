Route206_EternaGatehouse_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route206_EternaGatehouse_OnTransition
	.byte 0

Route206_EternaGatehouse_EventScript_NPC2::
	msgbox Route206_EternaGatehouse_Text_NPC2, MSGBOX_NPC
	end

Route206_EternaGatehouse_EventScript_NPC1::
	goto Route206_EternaGatehouse_EventScript_NPC2
	end

Route206_EternaGatehouse_EventScript_NPC3::
	lock
	faceplayer
	goto_if_set FLAG_ROUTE206_ETERNA_GATEHOUSE_ASSISTANT_1, Route206_EternaGatehouse_EventScript_NPC3_2
	checkplayergender
	copyvar VAR_TEMP_0, VAR_RESULT
	goto_if_eq VAR_TEMP_0, 0, Route206_EternaGatehouse_EventScript_NPC3_2_2
	goto Route206_EternaGatehouse_EventScript_NPC3_2_3

Route206_EternaGatehouse_EventScript_NPC3_2::
	msgbox Route206_EternaGatehouse_Text_NPC3, MSGBOX_DEFAULT
	closemessage
	release
	end

Route206_EternaGatehouse_EventScript_NPC3_2_2::
	msgbox Route206_EternaGatehouse_Text_NPC3_2, MSGBOX_DEFAULT
	goto Route206_EternaGatehouse_EventScript_NPC3_2_4

Route206_EternaGatehouse_EventScript_NPC3_2_3::
	msgbox Route206_EternaGatehouse_Text_NPC3_3, MSGBOX_DEFAULT
	goto Route206_EternaGatehouse_EventScript_NPC3_2_4

Route206_EternaGatehouse_EventScript_NPC3_2_4::
	@ TODO(DP): CountNationalDexSeen 32772
	buffernumberstring STR_VAR_2, VAR_0x8004
	goto_if_lt VAR_0x8004, 35, Route206_EternaGatehouse_EventScript_NPC3_2_5
	msgbox Route206_EternaGatehouse_Text_NPC3_4, MSGBOX_DEFAULT
	setvar VAR_0x8004, ITEM_NONE @ TODO(DP): ITEM_EXP__SHARE
	setvar VAR_0x8005, 1
	checkitemspace VAR_0x8004, VAR_0x8005
	goto_if_eq VAR_RESULT, FALSE, Route206_EternaGatehouse_EventScript_NPC3_2_6
	setflag FLAG_ROUTE206_ETERNA_GATEHOUSE_ASSISTANT_1
	giveitem VAR_0x8004, VAR_0x8005
	closemessage
	release
	end

Route206_EternaGatehouse_EventScript_NPC3_2_5::
	msgbox Route206_EternaGatehouse_Text_NPC3_5, MSGBOX_DEFAULT
	closemessage
	release
	end

Route206_EternaGatehouse_EventScript_NPC3_2_6::
	msgbox gText_TooBadBagIsFull, MSGBOX_DEFAULT
	closemessage
	release
	end

Route206_EternaGatehouse_EventScript_Trigger1::
	lockall
	playse SE_PIN
	applymovement LOCALID_ROUTE206_ETERNA_GATEHOUSE_CLERK, Route206_EternaGatehouse_Movement_Clerk
	waitmovement 0
	msgbox Route206_EternaGatehouse_Text_Trigger1, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, Route206_EternaGatehouse_Movement_Player
	waitmovement 0
	releaseall
	end

Route206_EternaGatehouse_OnTransition::
	call_if_set FLAG_ROUTE206_ETERNA_GATEHOUSE_ASSISTANT_1, Route206_EternaGatehouse_OnTransition_2
	checkitem ITEM_BICYCLE, 1
	copyvar VAR_ROUTE206_ETERNA_GATEHOUSE_STATE, VAR_RESULT
	end

Route206_EternaGatehouse_OnTransition_2::
	setflag FLAG_HIDE_ROUTE206_ETERNA_GATEHOUSE_ASSISTANT
	return

Route206_EternaGatehouse_Movement_Clerk:
	emote_exclamation_mark
	step_end

Route206_EternaGatehouse_Movement_Player:
	walk_up
	step_end

Route206_EternaGatehouse_Text_NPC2:
	.string "Learn how to shift gears, and you'll be\n"
	.string "able to ride anywhere.$"

Route206_EternaGatehouse_Text_NPC3:
	.string "A Pokémon holding an {COLOR DYNAMIC_COLOR3}Exp. Share{COLOR DARK_GRAY} will be\n"
	.string "given some of the Exp. Points from\l"
	.string "battle.\p"
	.string "It will get Exp. Points even if it didn't\n"
	.string "actually battle.\p"
	.string "I would say an {COLOR DYNAMIC_COLOR3}Exp. Share{COLOR DARK_GRAY} is quite\n"
	.string "useful for raising weak Pokémon.\p"
	.string "Also, a Pokémon you get in a trade may\n"
	.string "disobey you if it is too high in level.\p"
	.string "Don't worry, though. It will obey if you\n"
	.string "have enough Gym Badges.$"

Route206_EternaGatehouse_Text_NPC3_2:
	.string "{PLAYER}, long time, no see!\p"
	.string "Oh? You look puzzled. You're wondering\n"
	.string "who I am.\p"
	.string "I'm Professor Rowan's assistant and {ASSISTANT}'s\n"
	.string "father.\p"
	.string "I've come a long way to help you on your\n"
	.string "adventure at the professor's behest.\p"
	.string "{PLAYER}, let me ask you, how many\n"
	.string "Pokémon have you met?$"

Route206_EternaGatehouse_Text_NPC3_3:
	.string "{PLAYER}, long time, no see!\p"
	.string "Oh? You look puzzled. You're wondering\n"
	.string "who I am.\p"
	.string "I'm Professor Rowan's assistant and {ASSISTANT}'s\n"
	.string "father.\p"
	.string "I've come a long way to help you on your\n"
	.string "adventure at the professor's behest.\p"
	.string "{PLAYER}, let me ask you, how many\n"
	.string "Pokémon have you met?$"

Route206_EternaGatehouse_Text_NPC3_4:
	.string "Oh, my! You've met {STR_VAR_2} Pokémon!\p"
	.string "Wonderful! Yes, bravo! Professor Rowan\n"
	.string "should be delighted!\p"
	.string "Here is something for you!$"

Route206_EternaGatehouse_Text_NPC3_5:
	.string "You've met only {STR_VAR_2} Pokémon?\p"
	.string "Hmm... You've got to find at least 35.\p"
	.string "If you can't, it will be tough to\n"
	.string "complete the {COLOR DYNAMIC_COLOR3}Sinnoh{COLOR DARK_GRAY} {COLOR DYNAMIC_COLOR3}Pokédex{COLOR DARK_GRAY}.$"

Route206_EternaGatehouse_Text_Trigger1:
	.string "You need a {COLOR DYNAMIC_COLOR3}Bicycle{COLOR DARK_GRAY} to go out on Cycling\n"
	.string "Road!$"
