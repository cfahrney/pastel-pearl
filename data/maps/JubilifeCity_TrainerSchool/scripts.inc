JubilifeCity_TrainerSchool_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, JubilifeCity_TrainerSchool_OnTransition
	.byte 0

JubilifeCity_TrainerSchool_OnTransition:
	@ Barry is only inside after Lucas/Dawn mentions him and until he leaves with the Town Map.
	setflag FLAG_HIDE_TRAINERSCHOOL_BARRY
	call_if_eq VAR_JUBILIFE_CITY_STATE, 3, JubilifeCity_TrainerSchool_EventScript_ShowBarry
	end

JubilifeCity_TrainerSchool_EventScript_ShowBarry:
	clearflag FLAG_HIDE_TRAINERSCHOOL_BARRY
	return

JubilifeCity_TrainerSchool_EventScript_NPC1::
	msgbox JubilifeCity_TrainerSchool_Text_NPC1, MSGBOX_NPC
	end

JubilifeCity_TrainerSchool_EventScript_NPC2::
	msgbox JubilifeCity_TrainerSchool_Text_NPC2, MSGBOX_NPC
	end

JubilifeCity_TrainerSchool_EventScript_NPC3::
	msgbox JubilifeCity_TrainerSchool_Text_NPC3, MSGBOX_NPC
	end

JubilifeCity_TrainerSchool_EventScript_NPC4::
	msgbox JubilifeCity_TrainerSchool_Text_NPC4, MSGBOX_NPC
	end

JubilifeCity_TrainerSchool_EventScript_NPC5::
	msgbox JubilifeCity_TrainerSchool_Text_NPC5, MSGBOX_NPC
	end

JubilifeCity_TrainerSchool_EventScript_NPC6::
	msgbox JubilifeCity_TrainerSchool_Text_NPC6, MSGBOX_NPC
	end

JubilifeCity_TrainerSchool_EventScript_Trainer1::
	@ poe:behavior {"ask":true}
	lock
	faceplayer
	goto_if_defeated TRAINER_JUBILIFE_CITY_TRAINER_SCHOOL_1, JubilifeCity_TrainerSchool_EventScript_Trainer1PostBattle
	msgbox JubilifeCity_TrainerSchool_Text_Trainer1Ask, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, JubilifeCity_TrainerSchool_EventScript_Trainer1Decline
	trainerbattle_single TRAINER_JUBILIFE_CITY_TRAINER_SCHOOL_1, JubilifeCity_TrainerSchool_Text_Trainer1Intro, JubilifeCity_TrainerSchool_Text_Trainer1Defeated
	end

JubilifeCity_TrainerSchool_EventScript_Trainer1Decline::
	msgbox JubilifeCity_TrainerSchool_Text_Trainer1Decline, MSGBOX_DEFAULT
	release
	end

JubilifeCity_TrainerSchool_EventScript_Trainer1PostBattle::
	msgbox JubilifeCity_TrainerSchool_Text_Trainer1PostBattle, MSGBOX_DEFAULT
	release
	end

JubilifeCity_TrainerSchool_Text_Trainer1Ask::
	.string "Would you want to battle? I'm testing\n"
	.string "out a super new strategy!$"

JubilifeCity_TrainerSchool_Text_Trainer1Decline::
	.string "Okay! Well come find me when you do want\n"
	.string "to battle, then.$"

JubilifeCity_TrainerSchool_EventScript_Sign1::
	msgbox JubilifeCity_TrainerSchool_Text_Sign1, MSGBOX_SIGN
	end

JubilifeCity_TrainerSchool_EventScript_Sign2::
	msgbox JubilifeCity_TrainerSchool_Text_Sign2, MSGBOX_SIGN
	end

JubilifeCity_TrainerSchool_EventScript_Sign3::
	msgbox JubilifeCity_TrainerSchool_Text_Sign3, MSGBOX_SIGN
	end

JubilifeCity_TrainerSchool_EventScript_Sign4::
	msgbox JubilifeCity_TrainerSchool_Text_Sign4, MSGBOX_SIGN
	end

JubilifeCity_TrainerSchool_EventScript_Sign5::
	msgbox JubilifeCity_TrainerSchool_Text_Sign5, MSGBOX_SIGN
	end

JubilifeCity_TrainerSchool_Text_NPC1:
	.string "TRAINER SCHOOL NPC 1$"

JubilifeCity_TrainerSchool_Text_NPC2:
	.string "TRAINER SCHOOL NPC 2$"

JubilifeCity_TrainerSchool_Text_NPC3:
	.string "We learned about Pokémon types today.\n"
	.string "Umm...\p"
	.string "Grass is weak to Fire, Fire is weak to\n"
	.string "Water, and Water is weak to Grass!\p"
	.string "I think that's how it goes!$"

JubilifeCity_TrainerSchool_Text_NPC4:
	.string "Pokémon are smart enough to use items\n"
	.string "they're holding.\p"
	.string "But they won't know what to do with\n"
	.string "man-made items like Potions and\l"
	.string "Antidotes.$"

JubilifeCity_TrainerSchool_Text_NPC5:
	.string "I wrote an essay in my notebook on what\n"
	.string "makes a true Pokémon Trainer.$"

JubilifeCity_TrainerSchool_Text_NPC6:
	.string "You just became a Trainer, did you? You\n"
	.string "should look up topics you're not\l"
	.string "familiar with.$"

JubilifeCity_TrainerSchool_Text_Trainer1Intro:
	.string "Alright! Let's do this!$"

JubilifeCity_TrainerSchool_Text_Trainer1Defeated:
	.string "Well that didn't work.$"

JubilifeCity_TrainerSchool_Text_Trainer1PostBattle:
	.string "I guess I should have tried an\n"
	.string "attacking move.$"

JubilifeCity_TrainerSchool_Text_Sign1:
	.string "Physical attacking moves use a\n"
	.string "Pokémon's Attack stat, while Special\l"
	.string "attacking moves use the Pokémon's\l"
	.string "Special Attack stat.\p"
	.string "This used to be determined by the\n"
	.string "move's type, but now that isn't the\l"
	.string "case!$"

JubilifeCity_TrainerSchool_Text_Sign2:
	.string "Don't underestimate your {COLOR DYNAMIC_COLOR3}Pokédex{COLOR DARK_GRAY}!\p"
	.string "Your {COLOR DYNAMIC_COLOR3}Pokédex{COLOR DARK_GRAY} can be a handy tool. It\n"
	.string "can tell you many things about a\l"
	.string "Pokémon, like its stats, the moves it\l"
	.string "learns, and even how it evolves!$"

JubilifeCity_TrainerSchool_Text_Sign3:
	.string "The Fairy Type, first discovered in the\n"
	.string "{COLOR DYNAMIC_COLOR3}Kalos{COLOR DARK_GRAY} region, is very effective against\l"
	.string "the Dragon, Fighting, and Dark types.\p"
	.string "It is weak however to the Poison and\n"
	.string "Steel types.$"

JubilifeCity_TrainerSchool_Text_Sign4:
	.string "TMs are reusable and a Pokémon's\n"
	.string "learned moves can be relearned at any\l"
	.string "point. Make use of the flexibility by\l"
	.string "trying out different move sets to find\l"
	.string "strategies that work for you!$"

JubilifeCity_TrainerSchool_Text_Sign5:
	.string "TRAINER SCHOOL SIGN 5$"

@ Barry studies here until the player brings the parcel from his mom.
JubilifeCity_TrainerSchool_EventScript_Barry::
	lock
	faceplayer
	setspeaker SP_NAME_RIVAL
	msgbox JubilifeCity_TrainerSchool_Text_BarryStudy, MSGBOX_DEFAULT
	closemessage
	checkitem ITEM_PARCEL
	goto_if_eq VAR_RESULT, FALSE, JubilifeCity_TrainerSchool_EventScript_BarryNoParcel
	setspeaker SP_NAME_RIVAL
	msgbox JubilifeCity_TrainerSchool_Text_BarryWhatBringsYou, MSGBOX_DEFAULT
	closemessage
	removeitem ITEM_PARCEL
	playfanfare MUS_OBTAIN_TMHM
	message JubilifeCity_TrainerSchool_Text_PlayerDeliveredParcel
	waitmessage
	waitfanfare
	closemessage
	setspeaker SP_NAME_RIVAL
	msgbox JubilifeCity_TrainerSchool_Text_BarryWhatIsThis, MSGBOX_DEFAULT
	closemessage
	setspeaker SP_NAME_RIVAL
	msgbox JubilifeCity_TrainerSchool_Text_BarryScore, MSGBOX_DEFAULT
	closemessage
	playse SE_PIN
	applymovement LOCALID_TRAINERSCHOOL_BARRY, Common_Movement_ExclamationMark
	waitmovement LOCALID_TRAINERSCHOOL_BARRY
	setspeaker SP_NAME_RIVAL
	msgbox JubilifeCity_TrainerSchool_Text_BarryTwoMaps, MSGBOX_DEFAULT
	closemessage
	giveitem_msg JubilifeCity_TrainerSchool_Text_ObtainedTownMap, ITEM_TOWN_MAP
	setspeaker SP_NAME_RIVAL
	msgbox JubilifeCity_TrainerSchool_Text_BarryHmm, MSGBOX_DEFAULT
	closemessage
	setspeaker SP_NAME_RIVAL
	msgbox JubilifeCity_TrainerSchool_Text_BarryOreburgh, MSGBOX_DEFAULT
	closemessage
	getplayerxy VAR_0x8008, VAR_0x8009
	goto_if_eq VAR_0x8009, 4, JubilifeCity_TrainerSchool_EventScript_BarryLeavesPlayerBelow
	applymovement LOCALID_TRAINERSCHOOL_BARRY, JubilifeCity_TrainerSchool_Movement_BarryLeavesPlayerBeside
	waitmovement LOCALID_TRAINERSCHOOL_BARRY
	goto JubilifeCity_TrainerSchool_EventScript_BarryGone

JubilifeCity_TrainerSchool_EventScript_BarryLeavesPlayerBelow::
	applymovement LOCALID_TRAINERSCHOOL_BARRY, JubilifeCity_TrainerSchool_Movement_BarryLeavesPlayerBelow
	waitmovement LOCALID_TRAINERSCHOOL_BARRY
	goto JubilifeCity_TrainerSchool_EventScript_BarryGone

JubilifeCity_TrainerSchool_EventScript_BarryGone::
	playse SE_EXIT
	removeobject LOCALID_TRAINERSCHOOL_BARRY
	setflag FLAG_HIDE_TRAINERSCHOOL_BARRY
	setvar VAR_JUBILIFE_CITY_STATE, 6
	release
	end

JubilifeCity_TrainerSchool_EventScript_BarryNoParcel::
	release
	end

@ Player stood left (6,3) or right (8,3) of Barry.
JubilifeCity_TrainerSchool_Movement_BarryLeavesPlayerBeside:
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_down
	step_end

@ Player stood below Barry (7,4).
JubilifeCity_TrainerSchool_Movement_BarryLeavesPlayerBelow:
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_right
	walk_fast_down
	step_end

JubilifeCity_TrainerSchool_Text_BarryStudy:
	.string "Hey, {PLAYER}!\n"
	.string "Did you come to study, too?\p"
	.string "I went ahead and memorized\n"
	.string "everything that was up on the\l"
	.string "blackboard.\p"
	.string "After all, it's the Trainer's job to\n"
	.string "avoid having their precious Pokémon\l"
	.string "hurt in battle, right?$"

JubilifeCity_TrainerSchool_Text_BarryWhatBringsYou:
	.string "So, {PLAYER}, what brings you?\n"
	.string "Huh?\l"
	.string "You've got something for me?$"

JubilifeCity_TrainerSchool_Text_PlayerDeliveredParcel:
	.string "{PLAYER} delivered the {COLOR DYNAMIC_COLOR3}Parcel{COLOR DARK_GRAY}.$"

JubilifeCity_TrainerSchool_Text_BarryWhatIsThis:
	.string "So, what is this…?$"

JubilifeCity_TrainerSchool_Text_BarryScore:
	.string "Score!\n"
	.string "It's a {COLOR DYNAMIC_COLOR3}Town Map{COLOR DARK_GRAY}!$"

JubilifeCity_TrainerSchool_Text_BarryTwoMaps:
	.string "Huh?!\n"
	.string "Why are there two in here?\p"
	.string "I like it a lot, but I don't need\n"
	.string "two. Here, {PLAYER}, you take one!$"

JubilifeCity_TrainerSchool_Text_BarryHmm:
	.string "Hmm…$"

JubilifeCity_TrainerSchool_Text_BarryOreburgh:
	.string "Well, according to the {COLOR DYNAMIC_COLOR3}Town Map{COLOR DARK_GRAY},\n"
	.string "I guess {COLOR DYNAMIC_COLOR3}Oreburgh City{COLOR DARK_GRAY} is where I\l"
	.string "should be going next.\p"
	.string "There's a Gym, so it'd be perfect\n"
	.string "for raising the Pokémon I just\l"
	.string "caught.\p"
	.string "Well, I'm on the road to becoming\n"
	.string "the greatest Trainer of all time!\p"
	.string "See you around!$"

JubilifeCity_TrainerSchool_Text_ObtainedTownMap:
	.string "Obtained the {COLOR DYNAMIC_COLOR3}Town Map{COLOR DARK_GRAY}!$"

