Route205_House_MapScripts::
	.byte 0

Route205_House_EventScript_NPC1::
	lock
	faceplayer
	msgbox Route205_House_Text_NPC1_2, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route205_House_EventScript_NPC1_2
	goto_if_eq VAR_RESULT, NO, Route205_House_EventScript_NPC1_2_2
	end

Route205_House_EventScript_NPC1_2::
	closemessage
	fadescreen FADE_TO_BLACK
	playfanfare MUS_HEAL
	waitfanfare
	special HealPlayerParty
	fadescreen FADE_FROM_BLACK
	msgbox Route205_House_Text_NPC1_3, MSGBOX_DEFAULT
	closemessage
	release
	end

Route205_House_EventScript_NPC1_2_2::
	msgbox Route205_House_Text_NPC1_4, MSGBOX_DEFAULT
	closemessage
	release
	end

Route205_House_EventScript_NPC2::
	msgbox Route205_House_Text_NPC2_2, MSGBOX_NPC
	end

Route205_House_Text_NPC1_2:
	.string "You seem to be tired... Rest a while.$"

Route205_House_Text_NPC1_3:
	.string "You and your Pokémon look completely\n"
	.string "refreshed!$"

Route205_House_Text_NPC1_4:
	.string "Just because you're young doesn't mean\n"
	.string "you should push yourself.$"

Route205_House_Text_NPC2_2:
	.string "You think you can get through the\n"
	.string "Eterna Forest by yourself?$"
