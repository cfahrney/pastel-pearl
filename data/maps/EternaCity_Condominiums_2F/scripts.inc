EternaCity_Condominiums_2F_MapScripts::
	.byte 0

EternaCity_Condominiums_2F_EventScript_NPC1::
	lock
	faceplayer
	goto_if_set FLAG_ETERNA_CITY_CONDOMINIUMS_2F_OLD_WOMAN_1, EternaCity_Condominiums_2F_EventScript_NPC1_2
	msgbox EternaCity_Condominiums_2F_Text_NPC1, MSGBOX_DEFAULT
	setvar VAR_0x8004, ITEM_TM_RECYCLE
	setvar VAR_0x8005, 1
	checkitemspace VAR_0x8004, VAR_0x8005
	goto_if_eq VAR_RESULT, FALSE, EternaCity_Condominiums_2F_EventScript_NPC1_2_2
	setflag FLAG_ETERNA_CITY_CONDOMINIUMS_2F_OLD_WOMAN_1
	giveitem VAR_0x8004, VAR_0x8005
	closemessage
	release
	end

EternaCity_Condominiums_2F_EventScript_NPC1_2::
	msgbox EternaCity_Condominiums_2F_Text_NPC1_2, MSGBOX_DEFAULT
	closemessage
	release
	end

EternaCity_Condominiums_2F_EventScript_NPC1_2_2::
	msgbox gText_TooBadBagIsFull, MSGBOX_DEFAULT
	closemessage
	release
	end

EternaCity_Condominiums_2F_EventScript_NPC2::
	msgbox EternaCity_Condominiums_2F_Text_NPC2, MSGBOX_NPC
	end

EternaCity_Condominiums_2F_Text_NPC1:
	.string "I've had this TM Recycle for such a long\n"
	.string "time now.\p"
	.string "It's not anything that I have much use\n"
	.string "for these days.\p"
	.string "I do hope you'll put it to good use,\n"
	.string "young Trainer.$"

EternaCity_Condominiums_2F_Text_NPC1_2:
	.string "Folks like me have a long history we can\n"
	.string "look back on.\p"
	.string "Young people like you have only the\n"
	.string "future to look forward to.$"

EternaCity_Condominiums_2F_Text_NPC2:
	.string "Gardenia, our Gym Leader, goes out to\n"
	.string "Eterna Forest every so often.\p"
	.string "I always wonder what she does there.$"
