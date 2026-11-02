EternaCity_Condominiums_1F_MapScripts::
	.byte 0

EternaCity_Condominiums_1F_EventScript_NPC1::
	lock
	faceplayer
	goto_if_set FLAG_ETERNA_CITY_CONDOMINIUMS_1F_LITTLE_BOY_1, EternaCity_Condominiums_1F_EventScript_NPC1_2
	msgbox EternaCity_Condominiums_1F_Text_NPC1, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, EternaCity_Condominiums_1F_EventScript_NPC1_2_2
	goto EternaCity_Condominiums_1F_EventScript_NPC1_2_3

EternaCity_Condominiums_1F_EventScript_NPC1_2::
	msgbox EternaCity_Condominiums_1F_Text_NPC1_2, MSGBOX_DEFAULT
	closemessage
	release
	end

EternaCity_Condominiums_1F_EventScript_NPC1_2_2::
	closemessage
	fadescreen FADE_TO_BLACK
	@ TODO(DP): OpenTradeScreen
	copyvar VAR_RESULT, VAR_0x8004
	fadescreen FADE_FROM_BLACK
	goto_if_eq VAR_RESULT, PARTY_NOTHING_CHOSEN, EternaCity_Condominiums_1F_EventScript_NPC1_2_3
	@ TODO(DP): NPCTradeInit 1
	copyvar VAR_0x8004, VAR_RESULT
	specialvar VAR_0x8005, ScriptGetPartyMonSpecies
	@ TODO(DP): NPCTradeGetRequestedSpecies 32780
	goto_if_ne VAR_0x8005, VAR_RESULT, EternaCity_Condominiums_1F_EventScript_NPC1_2_4
	@ TODO(DP): NPCTradeExecute 32772
	@ TODO(DP): NPCTradeEnd
	setflag FLAG_ETERNA_CITY_CONDOMINIUMS_1F_LITTLE_BOY_1
	msgbox EternaCity_Condominiums_1F_Text_NPC1_3, MSGBOX_DEFAULT
	closemessage
	release
	end

EternaCity_Condominiums_1F_EventScript_NPC1_2_3::
	msgbox EternaCity_Condominiums_1F_Text_NPC1_4, MSGBOX_DEFAULT
	closemessage
	release
	end

EternaCity_Condominiums_1F_EventScript_NPC1_2_4::
	@ TODO(DP): NPCTradeEnd
	msgbox EternaCity_Condominiums_1F_Text_NPC1_5, MSGBOX_DEFAULT
	closemessage
	release
	end

EternaCity_Condominiums_1F_EventScript_NPC2::
	lock
	faceplayer
	gettimeofday
	goto_if_eq VAR_RESULT, TIME_NIGHT, EternaCity_Condominiums_1F_EventScript_NPC2_2
	goto EternaCity_Condominiums_1F_EventScript_NPC2_2_2

EternaCity_Condominiums_1F_EventScript_NPC2_2::
	msgbox EternaCity_Condominiums_1F_Text_NPC2, MSGBOX_DEFAULT
	closemessage
	release
	end

EternaCity_Condominiums_1F_EventScript_NPC2_2_2::
	msgbox EternaCity_Condominiums_1F_Text_NPC2_2, MSGBOX_DEFAULT
	closemessage
	release
	end

EternaCity_Condominiums_1F_EventScript_NPC3::
	lock
	faceplayer
	msgbox EternaCity_Condominiums_1F_Text_NPC3, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, EternaCity_Condominiums_1F_EventScript_NPC3_2
	goto EternaCity_Condominiums_1F_EventScript_NPC3_2_2

EternaCity_Condominiums_1F_EventScript_NPC3_2::
	msgbox EternaCity_Condominiums_1F_Text_NPC3_2, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	special ChoosePartyMon
	copyvar VAR_RESULT, VAR_0x8004
	fadescreen FADE_FROM_BLACK
	goto_if_eq VAR_RESULT, PARTY_NOTHING_CHOSEN, EternaCity_Condominiums_1F_EventScript_NPC3_2_2
	copyvar VAR_0x8005, VAR_RESULT
	copyvar VAR_0x8004, VAR_0x8005
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	goto_if_eq VAR_RESULT, SPECIES_NONE, EternaCity_Condominiums_1F_EventScript_NPC3_2_3
	@ TODO(DP): CheckPartyMonOTID 32773, 32780
	goto_if_eq VAR_RESULT, SPECIES_BULBASAUR, EternaCity_Condominiums_1F_EventScript_NPC3_2_4
	bufferpartymonnick STR_VAR_1, VAR_0x8005
	msgbox EternaCity_Condominiums_1F_Text_NPC3_3, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, EternaCity_Condominiums_1F_EventScript_NPC3_2_5
	goto EternaCity_Condominiums_1F_EventScript_NPC3_2_2

EternaCity_Condominiums_1F_EventScript_NPC3_2_2::
	msgbox EternaCity_Condominiums_1F_Text_NPC3_4, MSGBOX_DEFAULT
	closemessage
	release
	end

EternaCity_Condominiums_1F_EventScript_NPC3_2_3::
	msgbox EternaCity_Condominiums_1F_Text_NPC3_5, MSGBOX_DEFAULT
	closemessage
	release
	end

EternaCity_Condominiums_1F_EventScript_NPC3_2_4::
	bufferpartymonnick STR_VAR_1, VAR_0x8005
	msgbox EternaCity_Condominiums_1F_Text_NPC3_6, MSGBOX_DEFAULT
	closemessage
	release
	end

EternaCity_Condominiums_1F_EventScript_NPC3_2_5::
	msgbox EternaCity_Condominiums_1F_Text_NPC3_7, MSGBOX_DEFAULT
	closemessage
	setvar VAR_RESULT, 0
	fadescreen FADE_TO_BLACK
	@ TODO(DP): NamePokemonScreen 32773, 32780
	fadescreen FADE_FROM_BLACK
	goto_if_eq VAR_RESULT, 1, EternaCity_Condominiums_1F_EventScript_NPC3_2_6
	@ TODO(DP): StorePokeNickname 32773
	bufferpartymonnick STR_VAR_1, VAR_0x8005
	msgbox EternaCity_Condominiums_1F_Text_NPC3_8, MSGBOX_DEFAULT
	closemessage
	release
	end

EternaCity_Condominiums_1F_EventScript_NPC3_2_6::
	bufferpartymonnick STR_VAR_1, VAR_0x8005
	msgbox EternaCity_Condominiums_1F_Text_NPC3_9, MSGBOX_DEFAULT
	closemessage
	release
	end

EternaCity_Condominiums_1F_Text_NPC1:
	.string "Excuse me, but do you got that Pokémon\n"
	.string "named Buizel?\p"
	.string "Wanna trade it for my Chatot?$"

EternaCity_Condominiums_1F_Text_NPC1_2:
	.string "Did that Chatot I traded you totally\n"
	.string "learn that Chatter move?\p"
	.string "It will mimic your speech if you use\n"
	.string "that move outside of battle.$"

EternaCity_Condominiums_1F_Text_NPC1_3:
	.string "Yes! So awesome! A Buizel! I so promise\n"
	.string "I'll be good to it!\p"
	.string "Oh yeah, Chatot can learn some human\n"
	.string "speech pretty quickly.\p"
	.string "Try out its move Chatter. You'll totally\n"
	.string "see what I mean.$"

EternaCity_Condominiums_1F_Text_NPC1_4:
	.string "Oh, OK. Totally got it. It's all right if\n"
	.string "you don't want to.\p"
	.string "But if you change your mind, let's\n"
	.string "totally trade some Pokémon.$"

EternaCity_Condominiums_1F_Text_NPC1_5:
	.string "What I totally want is a Buizel...$"

EternaCity_Condominiums_1F_Text_NPC2:
	.string "I'm...building...superintendent...\n"
	.string "...maintain...24-hour watch... Zzz...$"

EternaCity_Condominiums_1F_Text_NPC2_2:
	.string "Hi! I'm the building superintendent. I\n"
	.string "maintain a vigilant 24-hour watch!$"

EternaCity_Condominiums_1F_Text_NPC3:
	.string "Hello, hello! I am the official Name\n"
	.string "Rater!\p"
	.string "Want me to rate the nicknames of your\n"
	.string "Pokémon?$"

EternaCity_Condominiums_1F_Text_NPC3_2:
	.string "Which Pokémon's nickname should I\n"
	.string "critique?$"

EternaCity_Condominiums_1F_Text_NPC3_3:
	.string "{STR_VAR_1}, is it? That's a decent\n"
	.string "nickname!\p"
	.string "But would you like to give it an even\n"
	.string "better name?\p"
	.string "How about it?$"

EternaCity_Condominiums_1F_Text_NPC3_4:
	.string "I see. Please come visit again.$"

EternaCity_Condominiums_1F_Text_NPC3_5:
	.string "Now, now. That is merely an Egg! An Egg\n"
	.string "can go by no other name!$"

EternaCity_Condominiums_1F_Text_NPC3_6:
	.string "{STR_VAR_1}, is it? That is a truly\n"
	.string "impeccable name!\p"
	.string "Take good care of {STR_VAR_1}!$"

EternaCity_Condominiums_1F_Text_NPC3_7:
	.string "Ah, good. Then, what shall the new\n"
	.string "nickname be?$"

EternaCity_Condominiums_1F_Text_NPC3_8:
	.string "Done! From now on, this Pokémon shall be\n"
	.string "known as {STR_VAR_1}!\p"
	.string "It is a better name than before! How\n"
	.string "fortunate for you!$"

EternaCity_Condominiums_1F_Text_NPC3_9:
	.string "Done! From now on, this Pokémon shall be\n"
	.string "known as {STR_VAR_1}!\p"
	.string "It looks no different from before, and\n"
	.string "yet, this is vastly superior!\p"
	.string "How fortunate for you!$"
