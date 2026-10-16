Route218_CanalaveGatehouse_MapScripts::
	.byte 0

Route218_CanalaveGatehouse_EventScript_NPC1::
	msgbox Route218_CanalaveGatehouse_Text_NPC1, MSGBOX_NPC
	end

Route218_CanalaveGatehouse_Text_NPC1:
	.string "CANALAVE GATEHOUSE NPC 1$"

Route218_CanalaveGatehouse_EventScript_NPC2::
	msgbox Route218_CanalaveGatehouse_Text_NPC2_2, MSGBOX_NPC
	end

Route218_CanalaveGatehouse_EventScript_Trigger1::
	lockall
	call Route218_CanalaveGatehouse_EventScript_Trigger1_2
	checkplayergender
	goto_if_eq VAR_RESULT, 0, Route218_CanalaveGatehouse_EventScript_Trigger1_2_2
	goto Route218_CanalaveGatehouse_EventScript_Trigger1_2_3

Route218_CanalaveGatehouse_EventScript_Trigger1_2::
	getplayerxy VAR_0x8005, VAR_0x8006
	goto_if_eq VAR_0x8006, 5, Route218_CanalaveGatehouse_EventScript_Trigger1_2_4
	goto Route218_CanalaveGatehouse_EventScript_Trigger1_2_5

Route218_CanalaveGatehouse_EventScript_Trigger1_2_2::
	msgbox Route218_CanalaveGatehouse_Text_Trigger1, MSGBOX_DEFAULT
	goto Route218_CanalaveGatehouse_EventScript_Trigger1_2_6

Route218_CanalaveGatehouse_EventScript_Trigger1_2_3::
	msgbox Route218_CanalaveGatehouse_Text_Trigger1_2, MSGBOX_DEFAULT
	goto Route218_CanalaveGatehouse_EventScript_Trigger1_2_6

Route218_CanalaveGatehouse_EventScript_Trigger1_2_4::
	playse SE_PIN
	applymovement LOCALID_ROUTE218_CANALAVE_GATEHOUSE_ASSISTANT, Route218_CanalaveGatehouse_Movement_Assistant
	waitmovement 0
	return

Route218_CanalaveGatehouse_EventScript_Trigger1_2_5::
	playse SE_PIN
	applymovement LOCALID_ROUTE218_CANALAVE_GATEHOUSE_ASSISTANT, Route218_CanalaveGatehouse_Movement_Assistant2
	waitmovement 0
	return

Route218_CanalaveGatehouse_EventScript_Trigger1_2_6::
	msgbox Route218_CanalaveGatehouse_Text_Trigger1_3, MSGBOX_DEFAULT
	closemessage
	@ TODO(DP): UnlockGenderEntries
	call Route218_CanalaveGatehouse_EventScript_Trigger1_2_7
	setflag FLAG_HIDE_ROUTE218_CANALAVE_GATEHOUSE_ASSISTANT
	removeobject LOCALID_ROUTE218_CANALAVE_GATEHOUSE_ASSISTANT
	setvar VAR_ROUTE218_CANALAVE_GATEHOUSE_STATE, 1
	releaseall
	end

Route218_CanalaveGatehouse_EventScript_Trigger1_2_7::
	getplayerxy VAR_0x8005, VAR_0x8006
	goto_if_eq VAR_0x8006, 5, Route218_CanalaveGatehouse_EventScript_Trigger1_2_8
	goto Route218_CanalaveGatehouse_EventScript_Trigger1_2_9

Route218_CanalaveGatehouse_EventScript_Trigger1_2_8::
	applymovement LOCALID_ROUTE218_CANALAVE_GATEHOUSE_ASSISTANT, Route218_CanalaveGatehouse_Movement_Assistant3
	waitmovement 0
	return

Route218_CanalaveGatehouse_EventScript_Trigger1_2_9::
	applymovement LOCALID_ROUTE218_CANALAVE_GATEHOUSE_ASSISTANT, Route218_CanalaveGatehouse_Movement_Assistant4
	waitmovement 0
	return

Route218_CanalaveGatehouse_Movement_Assistant:
	emote_exclamation_mark
	walk_right
	walk_up
	walk_in_place_right
	step_end

Route218_CanalaveGatehouse_Movement_Assistant2:
	emote_exclamation_mark
	walk_right
	step_end

Route218_CanalaveGatehouse_Movement_Assistant3:
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

Route218_CanalaveGatehouse_Movement_Assistant4:
	walk_up
	walk_right
	walk_right
	walk_right
	walk_down
	walk_right
	step_end

Route218_CanalaveGatehouse_Text_NPC2_2:
	.string "Boy... I sure am thirsty...$"

Route218_CanalaveGatehouse_Text_Trigger1:
	.string "{PLAYER}, long time, no see!\p"
	.string "Oh? You look puzzled. You're wondering\n"
	.string "who I am.\p"
	.string "I'm Professor Rowan's assistant and {ASSISTANT}'s\n"
	.string "father.\p"
	.string "The professor asked that I upgrade\n"
	.string "your {COLOR DYNAMIC_COLOR3}Pokédex{COLOR DARK_GRAY}, you see.\p"
	.string "So I'd chosen this spot on a hunch that\n"
	.string "you'd pass through.\p"
	.string "{PLAYER}, may I have your {COLOR DYNAMIC_COLOR3}Pokédex{COLOR DARK_GRAY} for a\n"
	.string "moment?$"

Route218_CanalaveGatehouse_Text_Trigger1_2:
	.string "{PLAYER}, long time, no see!\p"
	.string "Oh? You look puzzled. You're wondering\n"
	.string "who I am.\p"
	.string "I'm Professor Rowan's assistant and {ASSISTANT}'s\n"
	.string "father.\p"
	.string "The professor asked that I upgrade\n"
	.string "your {COLOR DYNAMIC_COLOR3}Pokédex{COLOR DARK_GRAY}, you see.\p"
	.string "So I'd chosen this spot on a hunch that\n"
	.string "you'd pass through.\p"
	.string "{PLAYER}, may I have your {COLOR DYNAMIC_COLOR3}Pokédex{COLOR DARK_GRAY} for a\n"
	.string "moment?$"

Route218_CanalaveGatehouse_Text_Trigger1_3:
	.string "Let's see... Was I supposed to put in the\n"
	.string "software here...?\p"
	.string "Ka-chunk. Ka-chunk!\p"
	.string "All done! I've upgraded your {COLOR DYNAMIC_COLOR3}Pokédex{COLOR DARK_GRAY}!\p"
	.string "I should explain how it's been upgraded,\n"
	.string "shouldn't I?\p"
	.string "It can now display images of male and\n"
	.string "female Pokémon.\p"
	.string "OK, I'll leave you to carry on with your\n"
	.string "project for the professor...\p"
	.string "...May I also ask you to keep an eye on\n"
	.string "Team Galactic?\p"
	.string "The professor is concerned about what\n"
	.string "happened in {COLOR DYNAMIC_COLOR3}Jubilife City{COLOR DARK_GRAY}...\p"
	.string "It's probably nothing to worry over! I'll\n"
	.string "be on my way now.$"
