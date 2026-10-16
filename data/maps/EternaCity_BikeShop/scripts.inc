EternaCity_BikeShop_MapScripts::
	.byte 0

EternaCity_BikeShop_EventScript_Sign1::
	msgbox EternaCity_BikeShop_Text_Sign1, MSGBOX_SIGN
	end

EternaCity_BikeShop_Text_Sign1:
	.string "BIKE SHOP SIGN 1$"

EternaCity_BikeShop_EventScript_Sign2::
	msgbox EternaCity_BikeShop_Text_Sign2, MSGBOX_SIGN
	end

EternaCity_BikeShop_Text_Sign2:
	.string "BIKE SHOP SIGN 2$"

EternaCity_BikeShop_EventScript_Sign3::
	msgbox EternaCity_BikeShop_Text_Sign3, MSGBOX_SIGN
	end

EternaCity_BikeShop_Text_Sign3:
	.string "BIKE SHOP SIGN 3$"

EternaCity_BikeShop_EventScript_Sign4::
	msgbox EternaCity_BikeShop_Text_Sign4, MSGBOX_SIGN
	end

EternaCity_BikeShop_Text_Sign4:
	.string "BIKE SHOP SIGN 4$"

EternaCity_BikeShop_EventScript_NPC3::
	lock
	faceplayer
	goto_if_set FLAG_ETERNA_CITY_BIKE_SHOP_MIDDLE_AGED_MAN_1, EternaCity_BikeShop_EventScript_NPC3_2
	msgbox EternaCity_BikeShop_Text_NPC3_2, MSGBOX_DEFAULT
	setvar VAR_0x8004, ITEM_BICYCLE
	setvar VAR_0x8005, 1
	giveitem VAR_0x8004, VAR_0x8005
	setflag FLAG_ETERNA_CITY_BIKE_SHOP_MIDDLE_AGED_MAN_1
	@ TODO(DP): SetSpawn 9
	goto_if_eq VAR_ETERNA_CITY_STATE_3, 0, EternaCity_BikeShop_EventScript_NPC3_2_2
	goto EternaCity_BikeShop_EventScript_NPC3_2

EternaCity_BikeShop_EventScript_NPC3_2::
	msgbox EternaCity_BikeShop_Text_NPC3_3, MSGBOX_DEFAULT
	closemessage
	release
	end

EternaCity_BikeShop_EventScript_NPC3_2_2::
	setvar VAR_ETERNA_CITY_STATE_3, 1
	goto EternaCity_BikeShop_EventScript_NPC3_2

EternaCity_BikeShop_EventScript_NPC2::
	lock
	faceplayer
	goto_if_set FLAG_ETERNA_CITY_BIKE_SHOP_YOUNGSTER_1, EternaCity_BikeShop_EventScript_NPC2_2
	msgbox EternaCity_BikeShop_Text_NPC2_2, MSGBOX_DEFAULT
	closemessage
	release
	end

EternaCity_BikeShop_EventScript_NPC2_2::
	msgbox EternaCity_BikeShop_Text_NPC2_3, MSGBOX_DEFAULT
	closemessage
	release
	end

EternaCity_BikeShop_EventScript_NPC1::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_CLEFAIRY, CRY_MODE_NORMAL
	setspeaker EternaCity_BikeShop_Text_ClefairySpeaker
	message EternaCity_BikeShop_Text_NPC1_2
	waitmessage
	waitmoncry
	waitbuttonpress
	closemessage
	release
	end

EternaCity_BikeShop_EventScript_Sign5::
	lockall
	msgbox EternaCity_BikeShop_Text_Sign5, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

EternaCity_BikeShop_EventScript_Sign6::
	goto EternaCity_BikeShop_EventScript_Sign5
	end

EternaCity_BikeShop_EventScript_Sign7::
	lockall
	msgbox EternaCity_BikeShop_Text_Sign7, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

EternaCity_BikeShop_EventScript_Sign8::
	goto EternaCity_BikeShop_EventScript_Sign7
	end

EternaCity_BikeShop_Text_NPC3_2:
	.string "Thanks for rescuing me! This is\n"
	.string "something to show my thanks!\p"
	.string "It's the latest model {COLOR DYNAMIC_COLOR3}Bicycle{COLOR DARK_GRAY}! You must\n"
	.string "take it. I insist!$"

EternaCity_BikeShop_Text_NPC3_3:
	.string "It's the latest model, so I'll read the\n"
	.string "operating manual to you.\p"
	.string "“Press the B Button to shift up or\n"
	.string "down.” In third gear, you can't go all\l"
	.string "that fast, but it's easier to control.\p"
	.string "In fourth gear, it gets harder to steer\n"
	.string "and stop, but it's fast!$"

EternaCity_BikeShop_Text_NPC2_2:
	.string "The manager's gone off to the Team\n"
	.string "Galactic building and hasn't returned.\p"
	.string "I wonder what's holding him up?$"

EternaCity_BikeShop_Text_NPC2_3:
	.string "What was Team Galactic trying to do\n"
	.string "with other people's Pokémon?$"

EternaCity_BikeShop_Text_NPC1_2:
	.string "Pip piih!$"

EternaCity_BikeShop_Text_Sign5:
	.string "There is a manual on the latest model\n"
	.string "{COLOR DYNAMIC_COLOR3}Bicycle{COLOR DARK_GRAY}.\p"
	.string "Third gear for steering. Fourth gear for\n"
	.string "all-out speed!\p"
	.string "Change gears with the B Button for\n"
	.string "exhilarating cycling!$"

EternaCity_BikeShop_Text_Sign7:
	.string "There's a catalog on Bikes...\p"
	.string "Mach Bike--a folding Bike built solely\n"
	.string "for blazing speed!\p"
	.string "Acro Bike--a folding Bike designed for\n"
	.string "stunts like jumps and wheelies!$"

EternaCity_BikeShop_Text_ClefairySpeaker:
	.string "Clefairy$"
