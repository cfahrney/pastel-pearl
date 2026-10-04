JubilifeCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, JubilifeCity_OnTransition
	.byte 0

JubilifeCity_OnTransition:
	setflag FLAG_VISITED_JUBILIFE_CITY
	call Common_EventScript_SetupLucasDawnAssistantGfxId
	@ Lucas/Dawn only waits here until the player has been pointed to the Trainer School.
	setflag FLAG_HIDE_JUBILIFECITY_LUCASDAWN
	call_if_eq VAR_JUBILIFE_CITY_STATE, 0, JubilifeCity_EventScript_ShowLucasDawn
	end

JubilifeCity_EventScript_ShowLucasDawn:
	clearflag FLAG_HIDE_JUBILIFECITY_LUCASDAWN
	return

JubilifeCity_EventScript_Sign1::
	msgbox JubilifeCity_Text_Sign1, MSGBOX_SIGN
	end

JubilifeCity_EventScript_Sign2::
	msgbox JubilifeCity_Text_Sign2, MSGBOX_SIGN
	end

JubilifeCity_EventScript_Sign3::
	msgbox JubilifeCity_Text_Sign3, MSGBOX_SIGN
	end

JubilifeCity_EventScript_Sign4::
	msgbox JubilifeCity_Text_Sign4, MSGBOX_SIGN
	end

JubilifeCity_EventScript_Sign5::
	msgbox JubilifeCity_Text_Sign5, MSGBOX_SIGN
	end

JubilifeCity_EventScript_Sign6::
	msgbox JubilifeCity_Text_Sign6, MSGBOX_SIGN
	end

JubilifeCity_EventScript_Sign7::
	msgbox JubilifeCity_Text_Sign7, MSGBOX_SIGN
	end

JubilifeCity_EventScript_Sign8::
	msgbox JubilifeCity_Text_Sign8, MSGBOX_SIGN
	end

JubilifeCity_Text_Sign1:
	.string "Jubilife City\n"
	.string "City of Joy$"

JubilifeCity_Text_Sign2:
	.string "Jubilife TV\n"
	.string "The Fun-and-Games TV Station!$"

JubilifeCity_Text_Sign3:
	.string "Jubilife Condominiums\n"
	.string "Tenants Wanted!$"

JubilifeCity_Text_Sign4:
	.string "Jubilife City\n"
	.string "City of Joy$"

JubilifeCity_Text_Sign5:
	.string "Jubilife City\n"
	.string "City of Joy$"

JubilifeCity_Text_Sign6:
	.string "The DexNav Company Pokemon\n"
	.string "DexNavs for the World!$"

JubilifeCity_Text_Sign7:
	.string "Jubilife Battle Dome\n"
	.string "Put your battling skills to the test!$"

JubilifeCity_Text_Sign8:
	.string "Trainers' School\n"
	.string "The First Step for Trainers!$"

JubilifeCity_EventScript_NPC1::
	msgbox JubilifeCity_Text_NPC1, MSGBOX_NPC
	end

JubilifeCity_EventScript_NPC2::
	msgbox JubilifeCity_Text_NPC2, MSGBOX_NPC
	end

JubilifeCity_EventScript_NPC3::
	msgbox JubilifeCity_Text_NPC3, MSGBOX_NPC
	end

JubilifeCity_EventScript_NPC4::
	msgbox JubilifeCity_Text_NPC4, MSGBOX_NPC
	end

JubilifeCity_EventScript_NPC5::
	msgbox JubilifeCity_Text_NPC5, MSGBOX_NPC
	end

JubilifeCity_EventScript_NPC6::
	msgbox JubilifeCity_Text_NPC6, MSGBOX_NPC
	end

JubilifeCity_EventScript_NPC7::
	msgbox JubilifeCity_Text_NPC7, MSGBOX_NPC
	end

JubilifeCity_EventScript_NPC8::
	msgbox JubilifeCity_Text_NPC8, MSGBOX_NPC
	end

JubilifeCity_Text_NPC1:
	.string "By the way, have you visited the {COLOR DYNAMIC_COLOR3}Trainer\n"
	.string "School{COLOR DARK_GRAY}?\p"
	.string "Not yet, right? You really must visit\n"
	.string "there!$"

JubilifeCity_Text_NPC2:
	.string "Hiya! Where'd you come from?\p"
	.string "...\p"
	.string "{COLOR DYNAMIC_COLOR3}Twinleaf Town{COLOR DARK_GRAY}, huh...\n"
	.string "It's a nice place. Quiet and all.\p"
	.string "{COLOR DYNAMIC_COLOR3}Jubilife{COLOR DARK_GRAY} is a big place, so it might be a\n"
	.string "bit of a shock to you.$"

JubilifeCity_Text_NPC3:
	.string "Gible and I are going to take on the\n"
	.string "champion one day! I heard she also has\l"
	.string "a Gible...$"

JubilifeCity_Text_NPC4:
	.string "{COLOR DYNAMIC_COLOR3}Jubilife City{COLOR DARK_GRAY}'s built on land they\n"
	.string "carved out of a mountain.\p"
	.string "The people and Pokemon of {COLOR DYNAMIC_COLOR3}Oreburgh\n"
	.string "City{COLOR DARK_GRAY} helps out with the undertaking.$"

JubilifeCity_Text_NPC5:
	.string "Okay, set six Poke Balls in my belt...\p"
	.string "Yeah, that'll do it. At most, you can\n"
	.string "have six Pokemon with you.$"

JubilifeCity_Text_NPC6:
	.string "Hello! Have you visited the {COLOR DYNAMIC_COLOR3}Trainer\n"
	.string "School{COLOR DARK_GRAY} yet? It's very useful for young\l"
	.string "trainers like yourself!$"

JubilifeCity_Text_NPC7:
	.string "I'm trading Pokemon with my buddy!$"

JubilifeCity_Text_NPC8:
	.string "I made my Pokemon hold an item before\n"
	.string "trading it. That will make my friend\l"
	.string "double happy!$"

JubilifeCity_EventScript_NPC9::
	msgbox JubilifeCity_Text_NPC9, MSGBOX_NPC
	end

JubilifeCity_EventScript_NPC10::
	msgbox JubilifeCity_Text_NPC10, MSGBOX_NPC
	end

JubilifeCity_EventScript_NPC11::
	msgbox JubilifeCity_Text_NPC11, MSGBOX_NPC
	end

JubilifeCity_EventScript_NPC12::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_NOCTOWL, CRY_MODE_NORMAL
	setspeaker JubilifeCity_Text_NPC12Speaker
	msgbox JubilifeCity_Text_NPC12, MSGBOX_DEFAULT
	waitmoncry
	release
	end

JubilifeCity_EventScript_NPC13::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_PIPLUP, CRY_MODE_NORMAL
	setspeaker JubilifeCity_Text_NPC13Speaker
	msgbox JubilifeCity_Text_NPC13, MSGBOX_DEFAULT
	waitmoncry
	release
	end

JubilifeCity_Text_NPC9:
	.string "I'm always glad to see the city add more\n"
	.string "bike parking. It's such a useful way to\l"
	.string "get around all of {COLOR DYNAMIC_COLOR3}Sinnoh{COLOR DARK_GRAY}!$"

JubilifeCity_Text_NPC10:
	.string "I enjoy watching my Piplup play by the\n"
	.string "fountains.$"

JubilifeCity_Text_NPC11:
	.string "My Noctowl is always great company for\n"
	.string "a walk. I caught him when he was just a\l"
	.string "wee Hoothoot!$"

JubilifeCity_Text_NPC12:
	.string "Noctoooowl!$"

JubilifeCity_Text_NPC12Speaker:
	.string "Noctowl$"

JubilifeCity_Text_NPC13:
	.string "Piiiip!$"

JubilifeCity_Text_NPC13Speaker:
	.string "Piplup$"

JubilifeCity_EventScript_NPC14::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_GIBLE, CRY_MODE_NORMAL
	setspeaker JubilifeCity_Text_NPC14Speaker
	msgbox JubilifeCity_Text_NPC14, MSGBOX_DEFAULT
	waitmoncry
	release
	end

JubilifeCity_Text_NPC14:
	.string "Gible! Gible Gible!$"

JubilifeCity_Text_NPC14Speaker:
	.string "Gible$"

JubilifeCity_EventScript_NPC15::
	msgbox JubilifeCity_Text_NPC15, MSGBOX_NPC
	end

JubilifeCity_Text_NPC15:
	.string "JUBILIFE CITY NPC 15$"

@ VAR_JUBILIFE_CITY_STATE == 0: LUCAS/DAWN runs down from the north and points the player to the Trainer School.
JubilifeCity_EventScript_LucasDawnStopsPlayerAtX53::
	lockall
	applymovement LOCALID_JUBILIFECITY_LUCASDAWN, JubilifeCity_Movement_LucasDawnEntersFrame
	waitmovement LOCALID_JUBILIFECITY_LUCASDAWN
	call JubilifeCity_EventScript_LucasDawnNoticesPlayer
	applymovement LOCALID_JUBILIFECITY_LUCASDAWN, JubilifeCity_Movement_LucasDawnApproachX53
	waitmovement LOCALID_JUBILIFECITY_LUCASDAWN
	goto JubilifeCity_EventScript_LucasDawnPointsToTrainerSchool

JubilifeCity_EventScript_LucasDawnStopsPlayerAtX54::
	lockall
	applymovement LOCALID_JUBILIFECITY_LUCASDAWN, JubilifeCity_Movement_LucasDawnEntersFrame
	waitmovement LOCALID_JUBILIFECITY_LUCASDAWN
	call JubilifeCity_EventScript_LucasDawnNoticesPlayer
	applymovement LOCALID_JUBILIFECITY_LUCASDAWN, JubilifeCity_Movement_LucasDawnApproachX54
	waitmovement LOCALID_JUBILIFECITY_LUCASDAWN
	goto JubilifeCity_EventScript_LucasDawnPointsToTrainerSchool

JubilifeCity_EventScript_LucasDawnStopsPlayerAtX55::
	lockall
	applymovement LOCALID_JUBILIFECITY_LUCASDAWN, JubilifeCity_Movement_LucasDawnEntersFrame
	waitmovement LOCALID_JUBILIFECITY_LUCASDAWN
	call JubilifeCity_EventScript_LucasDawnNoticesPlayer
	applymovement LOCALID_JUBILIFECITY_LUCASDAWN, JubilifeCity_Movement_LucasDawnApproachX55
	waitmovement LOCALID_JUBILIFECITY_LUCASDAWN
	goto JubilifeCity_EventScript_LucasDawnPointsToTrainerSchool

JubilifeCity_EventScript_LucasDawnNoticesPlayer::
	playse SE_PIN
	applymovement LOCALID_JUBILIFECITY_LUCASDAWN, Common_Movement_ExclamationMark
	waitmovement LOCALID_JUBILIFECITY_LUCASDAWN
	delay 45
	return

JubilifeCity_EventScript_LucasDawnPointsToTrainerSchool::
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	waitmovement LOCALID_PLAYER
	setspeaker SP_NAME_ASSISTANT
	msgbox JubilifeCity_Text_LucasDawnUsingPokeBalls, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_JUBILIFECITY_LUCASDAWN, JubilifeCity_Movement_LucasDawnWalksOffNorth
	waitmovement LOCALID_JUBILIFECITY_LUCASDAWN
	removeobject LOCALID_JUBILIFECITY_LUCASDAWN
	setflag FLAG_HIDE_JUBILIFECITY_LUCASDAWN
	setvar VAR_JUBILIFE_CITY_STATE, 3
	releaseall
	end

JubilifeCity_Movement_LucasDawnEntersFrame:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

JubilifeCity_Movement_LucasDawnApproachX53:
	walk_down
	walk_left
	walk_down
	face_down
	step_end

JubilifeCity_Movement_LucasDawnApproachX54:
	walk_down
	walk_down
	face_down
	step_end

JubilifeCity_Movement_LucasDawnApproachX55:
	walk_down
	walk_right
	walk_down
	face_down
	step_end

JubilifeCity_Movement_LucasDawnWalksOffNorth:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

JubilifeCity_Text_LucasDawnUsingPokeBalls:
	.string "Hey, {PLAYER}!\n"
	.string "I hope you're making use of those\l"
	.string "Poké Balls and catching lots of\l"
	.string "Pokémon!\p"
	.string "It might be more of a challenge to\n"
	.string "raise a lot of Pokémon…\p"
	.string "But it's worth it. The more Pokémon\n"
	.string "you have, the happier you'll be.\p"
	.string "In {COLOR DYNAMIC_COLOR3}Jubilife City{COLOR DARK_GRAY}, there's the\n"
	.string "{COLOR DYNAMIC_COLOR3}Trainer School{COLOR DARK_GRAY}. Check it out,\l"
	.string "{PLAYER}.\p"
	.string "Oh yeah, {RIVAL} went to the {COLOR DYNAMIC_COLOR3}Trainer\n"
	.string "School{COLOR DARK_GRAY} earlier.\p"
	.string "OK, see you around!\n"
	.string "Work hard on your {COLOR DYNAMIC_COLOR3}Pokédex{COLOR DARK_GRAY}!$"
