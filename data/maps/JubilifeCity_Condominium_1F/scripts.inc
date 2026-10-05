JubilifeCity_Condominium_1F_MapScripts::
	.byte 0

JubilifeCity_Condominium_1F_EventScript_NPC1::
	msgbox JubilifeCity_Condominium_1F_Text_NPC1, MSGBOX_NPC
	end

JubilifeCity_Condominium_1F_EventScript_NPC2::
	msgbox JubilifeCity_Condominium_1F_Text_NPC2, MSGBOX_NPC
	end

JubilifeCity_Condominium_1F_EventScript_NPC3::
	msgbox JubilifeCity_Condominium_1F_Text_NPC3, MSGBOX_NPC
	end

JubilifeCity_Condominium_1F_EventScript_NPC4::
	msgbox JubilifeCity_Condominium_1F_Text_NPC4, MSGBOX_NPC
	end

JubilifeCity_Condominium_1F_EventScript_NPC5::
	@ poe:behavior {"mode":"gift","item":"ITEM_QUICK_CLAW","qty":1}
	lock
	faceplayer
	goto_if_set FLAG_JUBILIFECITY_CONDOMINIUM_1F_NPC5_GIFT, JubilifeCity_Condominium_1F_EventScript_NPC5After
	msgbox JubilifeCity_Condominium_1F_Text_NPC5, MSGBOX_DEFAULT
	giveitem ITEM_QUICK_CLAW, 1
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_JUBILIFECITY_CONDOMINIUM_1F_NPC5_GIFT
	msgbox JubilifeCity_Condominium_1F_Text_NPC5Received, MSGBOX_DEFAULT
	release
	end

JubilifeCity_Condominium_1F_EventScript_NPC5After::
	msgbox JubilifeCity_Condominium_1F_Text_NPC5After, MSGBOX_DEFAULT
	release
	end

JubilifeCity_Condominium_1F_Text_NPC5Received::
	.string "A Pokémon holding that Quick Claw can\n"
	.string "sometimes attack first, even if it's\l"
	.string "normally a little bit slow.\p"
	.string "There are other items that are only\n"
	.string "useful when given to a Pokémon.\p"
	.string "...I sound like I'm a teacher or\n"
	.string "something.$"

JubilifeCity_Condominium_1F_Text_NPC5After::
	.string "A Pokémon holding that Quick Claw can\n"
	.string "sometimes attack first, even if it's\l"
	.string "normally a little bit slow.\p"
	.string "There are other items that are only\n"
	.string "useful when given to a Pokémon.\p"
	.string "...I sound like I'm a teacher or\n"
	.string "something.$"

JubilifeCity_Condominium_1F_EventScript_NPC6::
	msgbox JubilifeCity_Condominium_1F_Text_NPC6, MSGBOX_NPC
	end

JubilifeCity_Condominium_1F_EventScript_NPC7::
	msgbox JubilifeCity_Condominium_1F_Text_NPC7, MSGBOX_NPC
	end

JubilifeCity_Condominium_1F_Text_NPC1:
	.string "Welcome to Jubilife Condominiums!\n"
	.string "Please let me know if you'd like an\l"
	.string "application to fill out for a rental.$"

JubilifeCity_Condominium_1F_Text_NPC2:
	.string "Hi, welcome to Jubilife Condominiums! We\n"
	.string "are happy to help you however we may.$"

JubilifeCity_Condominium_1F_Text_NPC3:
	.string "I'm sorry, our condos are off limits\n"
	.string "right now unless you yourself are a\l"
	.string "resident.$"

JubilifeCity_Condominium_1F_Text_NPC4:
	.string "Isn't my {COLOR DYNAMIC_COLOR3}DexNav{COLOR DARK_GRAY} soooo cool? A Trainer\n"
	.string "trying to complete the {COLOR DYNAMIC_COLOR3}Pokédex{COLOR DARK_GRAY} would\l"
	.string "be simply lost without one, really!$"

JubilifeCity_Condominium_1F_Text_NPC5:
	.string "Oh your Pokémon is just adorable! Here,\n"
	.string "try giving it this item.$"

JubilifeCity_Condominium_1F_Text_NPC6:
	.string "Pachipachii?$"

JubilifeCity_Condominium_1F_Text_NPC7:
	.string "I'm sorry, our condos are off limits\n"
	.string "right now unless you yourself are a\l"
	.string "resident.$"

JubilifeCity_Condominium_1F_EventScript_Sign1::
	msgbox JubilifeCity_Condominium_1F_Text_Sign1, MSGBOX_SIGN
	end

JubilifeCity_Condominium_1F_Text_Sign1:
	.string "CONDOMINIUM 1F SIGN 1$"
