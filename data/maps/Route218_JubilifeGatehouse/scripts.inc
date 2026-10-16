Route218_JubilifeGatehouse_MapScripts::
	.byte 0

Route218_JubilifeGatehouse_EventScript_NPC2::
	msgbox Route218_JubilifeGatehouse_Text_NPC2_2, MSGBOX_NPC
	end

Route218_JubilifeGatehouse_EventScript_NPC1::
	lock
	faceplayer
	setvar VAR_0x8004, ITEM_OLD_ROD
	bufferitemname STR_VAR_1, VAR_0x8004
	goto_if_set FLAG_ROUTE218_JUBILIFE_GATEHOUSE_FISHERMAN_1, Route218_JubilifeGatehouse_EventScript_NPC1_2
	msgbox Route218_JubilifeGatehouse_Text_NPC1_2, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route218_JubilifeGatehouse_EventScript_NPC1_2_2
	goto_if_eq VAR_RESULT, NO, Route218_JubilifeGatehouse_EventScript_NPC1_2_3
	end

Route218_JubilifeGatehouse_EventScript_NPC1_2::
	bufferitemname STR_VAR_1, VAR_0x8004
	msgbox Route218_JubilifeGatehouse_Text_NPC1_3, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route218_JubilifeGatehouse_EventScript_NPC1_2_4
	goto_if_eq VAR_RESULT, NO, Route218_JubilifeGatehouse_EventScript_NPC1_2_5
	end

Route218_JubilifeGatehouse_EventScript_NPC1_2_2::
	bufferitemname STR_VAR_1, VAR_0x8004
	msgbox Route218_JubilifeGatehouse_Text_NPC1_4, MSGBOX_DEFAULT
	setvar VAR_0x8005, 1
	giveitem VAR_0x8004, VAR_0x8005
	setflag FLAG_ROUTE218_JUBILIFE_GATEHOUSE_FISHERMAN_1
	goto Route218_JubilifeGatehouse_EventScript_NPC1_2

Route218_JubilifeGatehouse_EventScript_NPC1_2_3::
	msgbox Route218_JubilifeGatehouse_Text_NPC1_5, MSGBOX_DEFAULT
	closemessage
	release
	end

Route218_JubilifeGatehouse_EventScript_NPC1_2_4::
	msgbox Route218_JubilifeGatehouse_Text_NPC1_6, MSGBOX_DEFAULT
	closemessage
	release
	end

Route218_JubilifeGatehouse_EventScript_NPC1_2_5::
	msgbox Route218_JubilifeGatehouse_Text_NPC1_7, MSGBOX_DEFAULT
	closemessage
	release
	end

Route218_JubilifeGatehouse_Text_NPC2_2:
	.string "{COLOR DYNAMIC_COLOR3}Route 218{COLOR DARK_GRAY} up ahead is a great fishing\n"
	.string "hole that's almost unknown to people.$"

Route218_JubilifeGatehouse_Text_NPC1_2:
	.string "Yes, sir! An {COLOR DYNAMIC_COLOR3}Old Rod{COLOR DARK_GRAY} is a good thing!\p"
	.string "You think so too, am I right?$"

Route218_JubilifeGatehouse_Text_NPC1_3:
	.string "You should fish wherever there is a\n"
	.string "body of water.\p"
	.string "Oh, and by the way, did you need any\n"
	.string "tips on using that fishing rod?$"

Route218_JubilifeGatehouse_Text_NPC1_4:
	.string "Yes! Good answer! We can be friends!\p"
	.string "Here you go. That's my {STR_VAR_1}!$"

Route218_JubilifeGatehouse_Text_NPC1_5:
	.string "Oh, really? You don't like to fish?$"

Route218_JubilifeGatehouse_Text_NPC1_6:
	.string "First, you face any body of water, then\n"
	.string "you use your fishing rod.\p"
	.string "Next, you focus! If a Pokémon bites, “!”\n"
	.string "appears.\p"
	.string "That's your cue to reel it in!$"

Route218_JubilifeGatehouse_Text_NPC1_7:
	.string "When you're fishing for Pokémon, the\n"
	.string "first hurdle is getting a bite.\p"
	.string "When you reel the Pokémon in, you've got\n"
	.string "to battle it.\p"
	.string "So, fishing gives you twice the fun!$"
