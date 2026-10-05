JubilifeCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, JubilifeCity_OnTransition
	.byte 0

JubilifeCity_OnTransition:
	setflag FLAG_VISITED_JUBILIFE_CITY
	call Common_EventScript_SetupLucasDawnAssistantGfxId
	@ Lucas/Dawn only waits here until the player has been pointed to the Trainer School.
	setflag FLAG_HIDE_JUBILIFECITY_LUCASDAWN
	call_if_eq VAR_JUBILIFE_CITY_STATE, 0, JubilifeCity_EventScript_ShowLucasDawn
	@ The DexNav President only waits at the north end once the player has the Town Map.
	setflag FLAG_HIDE_JUBILIFECITY_DEXNAVPRESIDENT
	call_if_eq VAR_JUBILIFE_CITY_STATE, 2, JubilifeCity_EventScript_ShowDexNavPresident
	@ Galactic grunts and Rowan are hidden until their scene shows them.
	setflag FLAG_HIDE_JUBILIFECITY_GALACTIC_GRUNTS
	setflag FLAG_HIDE_JUBILIFECITY_PROF_ROWAN
	call_if_eq VAR_JUBILIFE_CITY_STATE, 5, JubilifeCity_EventScript_ShowGalacticScene
	end

JubilifeCity_EventScript_ShowGalacticScene:
	setobjectxyperm LOCALID_JUBILIFECITY_LUCASDAWN, 55, 4
	clearflag FLAG_HIDE_JUBILIFECITY_LUCASDAWN
	clearflag FLAG_HIDE_JUBILIFECITY_GALACTIC_GRUNTS
	clearflag FLAG_HIDE_JUBILIFECITY_PROF_ROWAN
	return

JubilifeCity_EventScript_ShowDexNavPresident:
	clearflag FLAG_HIDE_JUBILIFECITY_DEXNAVPRESIDENT
	return

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
	.string "The DexNav Company Pokémon\n"
	.string "DexNavs for the World!$"

JubilifeCity_Text_Sign7:
	.string "Jubilife Battle Dome\n"
	.string "Put your battling skills to the test!$"

JubilifeCity_Text_Sign8:
	.string "Trainers' School\n"
	.string "The First Step for Trainers!$"

JubilifeCity_EventScript_NPC1::
	goto_if_ge VAR_JUBILIFE_CITY_STATE, 2, JubilifeCity_EventScript_NPC1AfterTownMap
	msgbox JubilifeCity_Text_NPC1, MSGBOX_NPC
	end

JubilifeCity_EventScript_NPC1AfterTownMap::
	msgbox JubilifeCity_Text_NPC1AfterTownMap, MSGBOX_NPC
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
	.string "Have you visited the {COLOR DYNAMIC_COLOR3}Trainer School{COLOR DARK_GRAY}?\p"
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
	.string "The people and Pokémon of {COLOR DYNAMIC_COLOR3}Oreburgh\n"
	.string "City{COLOR DARK_GRAY} helps out with the undertaking.$"

JubilifeCity_Text_NPC5:
	.string "Okay, set six Poké Balls in my belt...\p"
	.string "Yeah, that'll do it. At most, you can\n"
	.string "have six Pokémon with you.$"

JubilifeCity_Text_NPC6:
	.string "Hello! Have you visited the {COLOR DYNAMIC_COLOR3}Trainer\n"
	.string "School{COLOR DARK_GRAY} yet? It's very useful for young\l"
	.string "trainers like yourself!$"

JubilifeCity_Text_NPC7:
	.string "I'm trading Pokémon with my buddy!$"

JubilifeCity_Text_NPC8:
	.string "I made my Pokémon hold an item before\n"
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
	.string "Hey there, kiddo! Sorry, but the\n"
	.string "{COLOR DYNAMIC_COLOR3}Jubilife Battle Dome{COLOR DARK_GRAY} is currently\l"
	.string "closed. We are working on some wicked\l"
	.string "cool stuff, though! Come back after you\l"
	.string "have a few badges!$"

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
	setvar VAR_JUBILIFE_CITY_STATE, 1
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

JubilifeCity_Text_NPC1AfterTownMap:
	.string "Hello! Yes, you!\p"
	.string "You should have seen the boy that\n"
	.string "came running by earlier.\p"
	.string "He ran past me so quickly, I couldn't\n"
	.string "even manage a hello.$"

@ Progression guard: until the player has the Town Map (state < 2) the FAT MAN stops them at the east exit.
JubilifeCity_EventScript_FatManNoticesPlayerAtY21::
	goto JubilifeCity_EventScript_FatManStopsPlayer

JubilifeCity_EventScript_FatManNoticesPlayerAtY22::
	goto JubilifeCity_EventScript_FatManStopsPlayer

JubilifeCity_EventScript_FatManNoticesPlayerAtY23::
	goto JubilifeCity_EventScript_FatManStopsPlayer

JubilifeCity_EventScript_FatManNoticesPlayerAtY24::
	goto JubilifeCity_EventScript_FatManStopsPlayer

JubilifeCity_EventScript_FatManStopsPlayer::
	goto_if_ge VAR_JUBILIFE_CITY_STATE, 2, JubilifeCity_EventScript_FatManLetsPlayerPass
	lockall
	playse SE_PIN
	applymovement LOCALID_JUBILIFECITY_FATMAN, Common_Movement_ExclamationMark
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	waitmovementall
	delay 45
	applymovement LOCALID_JUBILIFECITY_FATMAN, Common_Movement_FaceRight
	waitmovement LOCALID_JUBILIFECITY_FATMAN
	msgbox JubilifeCity_Text_NPC1, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, Common_Movement_WalkLeft
	waitmovement LOCALID_PLAYER
	releaseall
	end

JubilifeCity_EventScript_FatManLetsPlayerPass::
	end

@ VAR_JUBILIFE_CITY_STATE == 2: the DexNav President walks down from the north and gives the player the DexNav.
JubilifeCity_EventScript_DexnavPresidentStopsPlayerAtX52::
	lockall
	call JubilifeCity_EventScript_DexNavPresidentNoticesPlayer
	applymovement LOCALID_JUBILIFECITY_DEXNAVPRESIDENT, JubilifeCity_Movement_DexNavPresidentApproachX52
	waitmovement LOCALID_JUBILIFECITY_DEXNAVPRESIDENT
	goto JubilifeCity_EventScript_DexNavPresidentGivesDexNav

JubilifeCity_EventScript_DexnavPresidentStopsPlayerAtX53::
	lockall
	call JubilifeCity_EventScript_DexNavPresidentNoticesPlayer
	applymovement LOCALID_JUBILIFECITY_DEXNAVPRESIDENT, JubilifeCity_Movement_DexNavPresidentApproachX53
	waitmovement LOCALID_JUBILIFECITY_DEXNAVPRESIDENT
	goto JubilifeCity_EventScript_DexNavPresidentGivesDexNav

JubilifeCity_EventScript_DexnavPresidentStopsPlayerAtX54::
	lockall
	call JubilifeCity_EventScript_DexNavPresidentNoticesPlayer
	applymovement LOCALID_JUBILIFECITY_DEXNAVPRESIDENT, JubilifeCity_Movement_DexNavPresidentApproachX54
	waitmovement LOCALID_JUBILIFECITY_DEXNAVPRESIDENT
	goto JubilifeCity_EventScript_DexNavPresidentGivesDexNav

JubilifeCity_EventScript_DexnavPresidentStopsPlayerAtX55::
	lockall
	call JubilifeCity_EventScript_DexNavPresidentNoticesPlayer
	applymovement LOCALID_JUBILIFECITY_DEXNAVPRESIDENT, JubilifeCity_Movement_DexNavPresidentApproachX55
	waitmovement LOCALID_JUBILIFECITY_DEXNAVPRESIDENT
	goto JubilifeCity_EventScript_DexNavPresidentGivesDexNav

JubilifeCity_EventScript_DexnavPresidentStopsPlayerAtX56::
	lockall
	call JubilifeCity_EventScript_DexNavPresidentNoticesPlayer
	applymovement LOCALID_JUBILIFECITY_DEXNAVPRESIDENT, JubilifeCity_Movement_DexNavPresidentApproachX56
	waitmovement LOCALID_JUBILIFECITY_DEXNAVPRESIDENT
	goto JubilifeCity_EventScript_DexNavPresidentGivesDexNav

JubilifeCity_EventScript_DexNavPresidentNoticesPlayer::
	playse SE_PIN
	applymovement LOCALID_JUBILIFECITY_DEXNAVPRESIDENT, Common_Movement_ExclamationMark
	waitmovement LOCALID_JUBILIFECITY_DEXNAVPRESIDENT
	applymovement LOCALID_JUBILIFECITY_DEXNAVPRESIDENT, Common_Movement_FaceDown
	waitmovement LOCALID_JUBILIFECITY_DEXNAVPRESIDENT
	delay 45
	return

JubilifeCity_EventScript_DexNavPresidentGivesDexNav::
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	waitmovement LOCALID_PLAYER
	msgbox JubilifeCity_Text_DexNavPresidentIntro, MSGBOX_DEFAULT
	closemessage
	setspeaker SP_NAME_DEXNAV_PRESIDENT
	msgbox JubilifeCity_Text_DexNavPresidentCampaign, MSGBOX_DEFAULT
	closemessage
	playfanfare MUS_OBTAIN_ITEM
	message JubilifeCity_Text_PlayerReceivedDexNav
	waitmessage
	waitfanfare
	setflag FLAG_SYS_DEXNAV_GET
	setspeaker SP_NAME_DEXNAV_PRESIDENT
	msgbox JubilifeCity_Text_DexNavPresidentExplains, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_JUBILIFECITY_DEXNAVPRESIDENT, JubilifeCity_Movement_DexNavPresidentWalksOffNorth
	waitmovement LOCALID_JUBILIFECITY_DEXNAVPRESIDENT
	removeobject LOCALID_JUBILIFECITY_DEXNAVPRESIDENT
	setflag FLAG_HIDE_JUBILIFECITY_DEXNAVPRESIDENT
	setvar VAR_JUBILIFE_CITY_STATE, 3
	releaseall
	end

@ He starts at (54, 35); the player stands on y39 at x52-56.
JubilifeCity_Movement_DexNavPresidentApproachX52:
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	face_down
	step_end

JubilifeCity_Movement_DexNavPresidentApproachX53:
	walk_down
	walk_down
	walk_down
	walk_left
	face_down
	step_end

JubilifeCity_Movement_DexNavPresidentApproachX54:
	walk_down
	walk_down
	walk_down
	face_down
	step_end

JubilifeCity_Movement_DexNavPresidentApproachX55:
	walk_down
	walk_down
	walk_down
	walk_right
	face_down
	step_end

JubilifeCity_Movement_DexNavPresidentApproachX56:
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	face_down
	step_end

JubilifeCity_Movement_DexNavPresidentWalksOffNorth:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

JubilifeCity_Text_DexNavPresidentIntro:
	.string "Oh, oh, oh?\p"
	.string "You call yourself a Pokémon Trainer?\n"
	.string "And yet you have no {COLOR DYNAMIC_COLOR3}DexNav{COLOR DARK_GRAY}?\p"
	.string "Oh my, you are a rare case indeed!\p"
	.string "You see, I invented, and now\n"
	.string "manufacture, {COLOR DYNAMIC_COLOR3}DexNavs{COLOR DARK_GRAY}.$"

JubilifeCity_Text_DexNavPresidentCampaign:
	.string "Not only that, I'm now conducting the\n"
	.string "{COLOR DYNAMIC_COLOR3}DexNav{COLOR DARK_GRAY} promotional campaign!\p"
	.string "Isn't it your lucky day! Here,\n"
	.string "welcome to the world of {COLOR DYNAMIC_COLOR3}DexNav{COLOR DARK_GRAY}!$"

JubilifeCity_Text_PlayerReceivedDexNav:
	.string "{PLAYER} received the {COLOR DYNAMIC_COLOR3}DexNav{COLOR DARK_GRAY}!$"

JubilifeCity_Text_DexNavPresidentExplains:
	.string "That device will help you find and\n"
	.string "track and chain all sorts of Pokémon,\l"
	.string "and on every route!\p"
	.string "Be sure to stop by our headquarters\n"
	.string "in the city if you'd like more info.$"

JubilifeCity_EventScript_NPC16::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_HOUNDOUR, CRY_MODE_NORMAL
	setspeaker JubilifeCity_Text_NPC16Speaker
	msgbox JubilifeCity_Text_NPC16, MSGBOX_DEFAULT
	waitmoncry
	release
	end

JubilifeCity_Text_NPC16:
	.string "Houndooour$"

JubilifeCity_Text_NPC16Speaker:
	.string "Houndour$"

JubilifeCity_EventScript_NPC17::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_PICHU, CRY_MODE_NORMAL
	setspeaker JubilifeCity_Text_NPC17Speaker
	msgbox JubilifeCity_Text_NPC17, MSGBOX_DEFAULT
	waitmoncry
	release
	end

JubilifeCity_Text_NPC17:
	.string "Chuuu$"

JubilifeCity_Text_NPC17Speaker:
	.string "Pichu$"

JubilifeCity_EventScript_NPC18::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_PICHU, CRY_MODE_NORMAL
	setspeaker JubilifeCity_Text_NPC18Speaker
	msgbox JubilifeCity_Text_NPC18, MSGBOX_DEFAULT
	waitmoncry
	release
	end

JubilifeCity_Text_NPC18:
	.string "Chu?$"

JubilifeCity_Text_NPC18Speaker:
	.string "Pichu$"

JubilifeCity_EventScript_RowanNoticesPlayerAtX52::
	lockall
	playse SE_PIN
	applymovement LOCALID_JUBILIFECITY_PROF_ROWAN, JubilifeCity_Movement_Rowan_NoticesPlayer
	waitmovement LOCALID_JUBILIFECITY_PROF_ROWAN
	applymovement LOCALID_PLAYER, JubilifeCity_Movement_Player_E52
	waitmovement LOCALID_PLAYER
	goto JubilifeCity_EventScript_PlayerBattlesGalacticGrunts
	end

JubilifeCity_EventScript_RowanNoticesPlayerAtX53::
	lockall
	playse SE_PIN
	applymovement LOCALID_JUBILIFECITY_PROF_ROWAN, JubilifeCity_Movement_Rowan_NoticesPlayer
	waitmovement LOCALID_JUBILIFECITY_PROF_ROWAN
	applymovement LOCALID_PLAYER, JubilifeCity_Movement_Player_E53
	waitmovement LOCALID_PLAYER
	goto JubilifeCity_EventScript_PlayerBattlesGalacticGrunts
	end

JubilifeCity_EventScript_RowanNoticesPlayerAtX54::
	lockall
	playse SE_PIN
	applymovement LOCALID_JUBILIFECITY_PROF_ROWAN, JubilifeCity_Movement_Rowan_NoticesPlayer
	waitmovement LOCALID_JUBILIFECITY_PROF_ROWAN
	applymovement LOCALID_PLAYER, JubilifeCity_Movement_Player_E54
	waitmovement LOCALID_PLAYER
	goto JubilifeCity_EventScript_PlayerBattlesGalacticGrunts
	end

JubilifeCity_EventScript_RowanNoticesPlayerAtX55::
	lockall
	playse SE_PIN
	applymovement LOCALID_JUBILIFECITY_PROF_ROWAN, JubilifeCity_Movement_Rowan_NoticesPlayer
	waitmovement LOCALID_JUBILIFECITY_PROF_ROWAN
	applymovement LOCALID_PLAYER, JubilifeCity_Movement_Player_E55
	waitmovement LOCALID_PLAYER
	goto JubilifeCity_EventScript_PlayerBattlesGalacticGrunts
	end

JubilifeCity_EventScript_PlayerBattlesGalacticGrunts::
	setspeaker SP_NAME_ROWAN
	msgbox JubilifeCity_Text_RowanShowThemManners, MSGBOX_DEFAULT
	closemessage
	setspeaker SP_NAME_MYSTERY_MAN
	msgbox JubilifeCity_Text_MysteryManBusinessmen, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_JUBILIFECITY_LUCASDAWN, JubilifeCity_Movement_LucasDawn_InitialCallout
	waitmovement LOCALID_JUBILIFECITY_LUCASDAWN
	setspeaker SP_NAME_ASSISTANT
	msgbox JubilifeCity_Text_AssistantJoinMe, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_JUBILIFECITY_LUCASDAWN, JubilifeCity_Movement_LucasDawn_InitialCalloutFollowup
	waitmovement LOCALID_JUBILIFECITY_LUCASDAWN
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, JubilifeCity_EventScript_GruntBattleWithDawn
	goto JubilifeCity_EventScript_GruntBattleWithLucas
	end

JubilifeCity_EventScript_GruntBattleWithDawn::
	goto_if_eq VAR_STARTER_MON, STARTER_TURTWIG, JubilifeCity_EventScript_GruntBattleDawnTurtwig
	goto_if_eq VAR_STARTER_MON, STARTER_CHIMCHAR, JubilifeCity_EventScript_GruntBattleDawnChimchar
	goto JubilifeCity_EventScript_GruntBattleDawnPiplup
	end

JubilifeCity_EventScript_GruntBattleDawnTurtwig::
	multi_2_vs_2 TRAINER_JUBILIFE_CITY_GALACTIC_GRUNT_1_JUBILIFE_FIGHT, JubilifeCity_Text_Grunt1Defeated, TRAINER_JUBILIFE_CITY_GALACTIC_GRUNT_2_JUBILIFE_FIGHT, JubilifeCity_Text_Grunt2Defeated, PARTNER_DAWN_PLAYER_CHOSE_TURTWIG
	goto JubilifeCity_EventScript_GruntBattleResult
	end

JubilifeCity_EventScript_GruntBattleDawnChimchar::
	multi_2_vs_2 TRAINER_JUBILIFE_CITY_GALACTIC_GRUNT_1_JUBILIFE_FIGHT, JubilifeCity_Text_Grunt1Defeated, TRAINER_JUBILIFE_CITY_GALACTIC_GRUNT_2_JUBILIFE_FIGHT, JubilifeCity_Text_Grunt2Defeated, PARTNER_DAWN_PLAYER_CHOSE_CHIMCHAR
	goto JubilifeCity_EventScript_GruntBattleResult
	end

JubilifeCity_EventScript_GruntBattleDawnPiplup::
	multi_2_vs_2 TRAINER_JUBILIFE_CITY_GALACTIC_GRUNT_1_JUBILIFE_FIGHT, JubilifeCity_Text_Grunt1Defeated, TRAINER_JUBILIFE_CITY_GALACTIC_GRUNT_2_JUBILIFE_FIGHT, JubilifeCity_Text_Grunt2Defeated, PARTNER_DAWN_PLAYER_CHOSE_PIPLUP
	goto JubilifeCity_EventScript_GruntBattleResult
	end

JubilifeCity_EventScript_GruntBattleWithLucas::
	goto_if_eq VAR_STARTER_MON, STARTER_TURTWIG, JubilifeCity_EventScript_GruntBattleLucasTurtwig
	goto_if_eq VAR_STARTER_MON, STARTER_CHIMCHAR, JubilifeCity_EventScript_GruntBattleLucasChimchar
	goto JubilifeCity_EventScript_GruntBattleLucasPiplup
	end

JubilifeCity_EventScript_GruntBattleLucasTurtwig::
	multi_2_vs_2 TRAINER_JUBILIFE_CITY_GALACTIC_GRUNT_1_JUBILIFE_FIGHT, JubilifeCity_Text_Grunt1Defeated, TRAINER_JUBILIFE_CITY_GALACTIC_GRUNT_2_JUBILIFE_FIGHT, JubilifeCity_Text_Grunt2Defeated, PARTNER_LUCAS_PLAYER_CHOSE_TURTWIG
	goto JubilifeCity_EventScript_GruntBattleResult
	end

JubilifeCity_EventScript_GruntBattleLucasChimchar::
	multi_2_vs_2 TRAINER_JUBILIFE_CITY_GALACTIC_GRUNT_1_JUBILIFE_FIGHT, JubilifeCity_Text_Grunt1Defeated, TRAINER_JUBILIFE_CITY_GALACTIC_GRUNT_2_JUBILIFE_FIGHT, JubilifeCity_Text_Grunt2Defeated, PARTNER_LUCAS_PLAYER_CHOSE_CHIMCHAR
	goto JubilifeCity_EventScript_GruntBattleResult
	end

JubilifeCity_EventScript_GruntBattleLucasPiplup::
	multi_2_vs_2 TRAINER_JUBILIFE_CITY_GALACTIC_GRUNT_1_JUBILIFE_FIGHT, JubilifeCity_Text_Grunt1Defeated, TRAINER_JUBILIFE_CITY_GALACTIC_GRUNT_2_JUBILIFE_FIGHT, JubilifeCity_Text_Grunt2Defeated, PARTNER_LUCAS_PLAYER_CHOSE_PIPLUP
	goto JubilifeCity_EventScript_GruntBattleResult
	end

JubilifeCity_EventScript_GruntBattleResult::
	switch VAR_RESULT
	case 1, JubilifeCity_EventScript_GruntsDefeated
	fadescreen FADE_TO_BLACK
	special SetCB2WhiteOut
	waitstate
	end

JubilifeCity_EventScript_GruntsDefeated::
	setspeaker SP_NAME_GRUNT
	msgbox JubilifeCity_Text_GruntRetreat, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_JUBILIFECITY_GALACTIC_GRUNT_2, JubilifeCity_Movement_Grunt2_OnEnd
	applymovement LOCALID_JUBILIFECITY_GALACTIC_GRUNT_1, JubilifeCity_Movement_Grunt1_OnEnd
	waitmovementall
	removeobject LOCALID_JUBILIFECITY_GALACTIC_GRUNT_1
	removeobject LOCALID_JUBILIFECITY_GALACTIC_GRUNT_2
	setflag FLAG_HIDE_JUBILIFECITY_GALACTIC_GRUNTS
	applymovement LOCALID_JUBILIFECITY_LUCASDAWN, JubilifeCity_Movement_LucasDawn_AfterBattle
	waitmovement LOCALID_JUBILIFECITY_LUCASDAWN
	setspeaker SP_NAME_ROWAN
	msgbox JubilifeCity_Text_RowanTeamGalactic, MSGBOX_DEFAULT
	closemessage
	setspeaker SP_NAME_ASSISTANT
	msgbox JubilifeCity_Text_AssistantEvolutionResearch, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_JUBILIFECITY_LUCASDAWN, JubilifeCity_Movement_LucasDawn_OnEnd
	applymovement LOCALID_JUBILIFECITY_PROF_ROWAN, JubilifeCity_Movement_Rowan_OnEnd
	waitmovementall
	removeobject LOCALID_JUBILIFECITY_LUCASDAWN
	removeobject LOCALID_JUBILIFECITY_PROF_ROWAN
	setflag FLAG_HIDE_JUBILIFECITY_LUCASDAWN
	setflag FLAG_HIDE_JUBILIFECITY_PROF_ROWAN
	setvar VAR_JUBILIFE_CITY_STATE, 6
	releaseall
	end

JubilifeCity_Movement_Rowan_NoticesPlayer:
	face_down
	emote_exclamation_mark
	delay_16
	delay_16
	step_end

JubilifeCity_Movement_Rowan_OnEnd:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

JubilifeCity_Movement_LucasDawn_InitialCallout:
	walk_in_place_down
	delay_16
	step_end

JubilifeCity_Movement_LucasDawn_InitialCalloutFollowup:
	walk_left
	step_end

JubilifeCity_Movement_LucasDawn_AfterBattle:
	walk_left
	walk_down
	delay_16
	step_end

JubilifeCity_Movement_LucasDawn_OnEnd:
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

JubilifeCity_Movement_Grunt1_OnEnd:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

JubilifeCity_Movement_Grunt2_OnEnd:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

JubilifeCity_Movement_Player_E52:
	walk_up
	walk_right
	face_up
	delay_16
	step_end

JubilifeCity_Movement_Player_E53:
	walk_up
	delay_16
	step_end

JubilifeCity_Movement_Player_E54:
	walk_up
	walk_left
	face_up
	step_end

JubilifeCity_Movement_Player_E55:
	walk_up
	walk_left
	walk_left
	face_up
	step_end

JubilifeCity_Text_RowanShowThemManners:
	.string "Ah, {PLAYER}.\n"
	.string "Impeccable timing as always.\p"
	.string "This miscreants are babbling utter\n"
	.string "nonsense that I just can't stomach.\p"
	.string "Show them some manners, if you will.$"

JubilifeCity_Text_MysteryManBusinessmen:
	.string "Oh, Professor Pokémon, must you be so\n"
	.string "difficult?\p"
	.string "We are approaching you strictly as\n"
	.string "businessmen.\p"
	.string "All you must do is provide us with all\n"
	.string "your research findings.\p"
	.string "In return, we'll refrain from causing\n"
	.string "massive damage to your assistant.$"

JubilifeCity_Text_AssistantJoinMe:
	.string "{PLAYER}!\n"
	.string "Join me and battle these guys!$"

JubilifeCity_Text_GruntRetreat:
	.string "You leave us no option.\n"
	.string "We will retreat for now.\p"
	.string "Because Team Galactic is benevolent to\n"
	.string "all, we shall leave.$"

JubilifeCity_Text_RowanTeamGalactic:
	.string "That lot...\n"
	.string "They call themselves Team Galactic.\p"
	.string "When Pokémon evolve, they seem to\n"
	.string "release som type of energy...\p"
	.string "However, I believe that it's a mystic\n"
	.string "power far beyond our control.\p"
	.string "But Team Galactic seems to be trying to\n"
	.string "use that power for something...\p"
	.string "Anyway, {PLAYER}, well done!\n"
	.string "You battle quite capably,\p"
	.string "The sight of you Trainers and Pokémon\n"
	.string "battling together...\p"
	.string "I made the right decision in entrusting\n"
	.string "you with a {COLOR DYNAMIC_COLOR3}Pokédex{COLOR DARK_GRAY}!$"

JubilifeCity_Text_AssistantEvolutionResearch:
	.string "{PLAYER}, did you know about this?\p"
	.string "The professor studies about the\n"
	.string "evolution of Pokémon, too.\p"
	.string "According to his research, 90% of all\n"
	.string "Pokémon are somehow tied to evolution!\p"
	.string "I guess that means some Pokémon must\n"
	.string "undergo weird evolutions.\p"
	.string "So, {PLAYER}...\n"
	.string "Let's keep working on our {COLOR DYNAMIC_COLOR3}Pokédex{COLOR DARK_GRAY}\l"
	.string "project for the prof!$"

JubilifeCity_Text_Grunt1Defeated:
	.string "How is this madness possible?\n"
	.string "The two of us, losing to children?$"

JubilifeCity_Text_Grunt2Defeated:
	.string "This won't do...\n"
	.string "Time to retreat.\pThis mission is a failure.$"
