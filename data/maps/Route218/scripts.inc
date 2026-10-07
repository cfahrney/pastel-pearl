Route218_MapScripts::
	.byte 0

Route218_EventScript_Trainer1::
	trainerbattle_single TRAINER_ROUTE218_1, Route218_Text_Trainer1Intro, Route218_Text_Trainer1Defeated
	msgbox Route218_Text_Trainer1PostBattle, MSGBOX_AUTOCLOSE
	end

Route218_EventScript_Trainer2::
	trainerbattle_single TRAINER_ROUTE218_2, Route218_Text_Trainer2Intro, Route218_Text_Trainer2Defeated
	msgbox Route218_Text_Trainer2PostBattle, MSGBOX_AUTOCLOSE
	end

Route218_EventScript_Trainer3::
	trainerbattle_single TRAINER_ROUTE218_3, Route218_Text_Trainer3Intro, Route218_Text_Trainer3Defeated
	msgbox Route218_Text_Trainer3PostBattle, MSGBOX_AUTOCLOSE
	end

Route218_EventScript_Trainer4::
	trainerbattle_single TRAINER_ROUTE218_4, Route218_Text_Trainer4Intro, Route218_Text_Trainer4Defeated
	msgbox Route218_Text_Trainer4PostBattle, MSGBOX_AUTOCLOSE
	end

Route218_EventScript_Trainer5::
	@ poe:behavior {"ask":true}
	lock
	faceplayer
	goto_if_defeated TRAINER_ROUTE218_5, Route218_EventScript_Trainer5PostBattle
	msgbox Route218_Text_Trainer5Ask, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route218_EventScript_Trainer5Decline
	trainerbattle_single TRAINER_ROUTE218_5, Route218_Text_Trainer5Intro, Route218_Text_Trainer5Defeated
	end

Route218_EventScript_Trainer5Decline::
	msgbox Route218_Text_Trainer5Decline, MSGBOX_DEFAULT
	release
	end

Route218_EventScript_Trainer5PostBattle::
	msgbox Route218_Text_Trainer5PostBattle, MSGBOX_DEFAULT
	release
	end

Route218_Text_Trainer5Ask::
	.string "We met at the {COLOR DYNAMIC_COLOR3}Jubilife Battle Dome{COLOR DARK_GRAY} when\n"
	.string "we were young. Our first ever battle\l"
	.string "ended in a draw, can you believe it?\p"
	.string "Say, sweetie, would you care for a\n"
	.string "battle yourself? I could use a warm up,\l"
	.string "hah!$"

Route218_Text_Trainer5Decline::
	.string "No worries! We are here often, Judy and\n"
	.string "I!$"

Route218_EventScript_Trainer6::
	@ poe:behavior {"ask":true}
	lock
	faceplayer
	goto_if_defeated TRAINER_ROUTE218_6, Route218_EventScript_Trainer6PostBattle
	msgbox Route218_Text_Trainer6Ask, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route218_EventScript_Trainer6Decline
	trainerbattle_single TRAINER_ROUTE218_6, Route218_Text_Trainer6Intro, Route218_Text_Trainer6Defeated
	end

Route218_EventScript_Trainer6Decline::
	msgbox Route218_Text_Trainer6Decline, MSGBOX_DEFAULT
	release
	end

Route218_EventScript_Trainer6PostBattle::
	msgbox Route218_Text_Trainer6PostBattle, MSGBOX_DEFAULT
	release
	end

Route218_Text_Trainer6Ask::
	.string "Oh! Hello there, dear! What brings you\n"
	.string "out this way?\p"
	.string "My wife and I have been coming to this\n"
	.string "spot for decades to battle and picnic!\l"
	.string "We only live a short ways away in\l"
	.string "{COLOR DYNAMIC_COLOR3}Jubilife{COLOR DARK_GRAY}.\p"
	.string "Would you care for a quick battle while\n"
	.string "you're here, dear? Fair warning, I'm no\l"
	.string "laughing matter!$"

Route218_Text_Trainer6Decline::
	.string "I understand! We can battle another\n"
	.string "time.$"

Route218_EventScript_Sign1::
	msgbox Route218_Text_Sign1, MSGBOX_SIGN
	end

Route218_EventScript_Sign2::
	msgbox Route218_Text_Sign2, MSGBOX_SIGN
	end

Route218_Text_Trainer1Intro:
	.string "Yeah, yeah...\n"
	.string "Nothing's biting.$"

Route218_Text_Trainer1Defeated:
	.string "...$"

Route218_Text_Trainer1PostBattle:
	.string "When nothing is biting, the smart thing\n"
	.string "to do is just call it a day.$"

Route218_Text_Trainer2Intro:
	.string "Outdoor fishing for the win!\p"
	.string "Shouting doesn't help my fishing any,\n"
	.string "but shout I must!$"

Route218_Text_Trainer2Defeated:
	.string "Gwaaah! This is hurting!$"

Route218_Text_Trainer2PostBattle:
	.string "Oh, right... My shouting is scaring away\n"
	.string "the Pokémon.$"

Route218_Text_Trainer3Intro:
	.string "Let it rock, dude!$"

Route218_Text_Trainer3Defeated:
	.string "Can you hear that? That's my guitar\n"
	.string "weeping...$"

Route218_Text_Trainer3PostBattle:
	.string "I'm too torn up to sing anymore...\n"
	.string "I am so cool that way...$"

Route218_Text_Trainer4Intro:
	.string "Do you like the color green?$"

Route218_Text_Trainer4Defeated:
	.string "I like the color green.$"

Route218_Text_Trainer4PostBattle:
	.string "I caught him as a Poliwag. Love 'em to\n"
	.string "bits.$"

Route218_Text_Trainer5Intro:
	.string "Alright, let's see what you're made of!$"

Route218_Text_Trainer5Defeated:
	.string "Woohoo, that was a blast!$"

Route218_Text_Trainer5PostBattle:
	.string "The thrill of battling has never waned\n"
	.string "over the years.$"

Route218_Text_Trainer6Intro:
	.string "I like your guts! Let's see how you do.$"

Route218_Text_Trainer6Defeated:
	.string "Hah! What a fun battle that was!$"

Route218_Text_Trainer6PostBattle:
	.string "I'm glad to see young people exploring.\n"
	.string "It's important to do! You never know\l"
	.string "what's around the corner.$"

Route218_Text_Sign1:
	.string "Route 218\n"
	.string "{LEFT_ARROW} Canalize City$"

Route218_Text_Sign2:
	.string "Route 218\n"
	.string "{RIGHT_ARROW} Jubilife City$"
