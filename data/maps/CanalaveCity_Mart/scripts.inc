CanalaveCity_Mart_MapScripts::
	.byte 0

CanalaveCity_Mart_EventScript_Clerk::
	@ poe:behavior {"mode":"mart","items":[{"item":"ITEM_POKE_BALL","badges":0},{"item":"ITEM_GREAT_BALL","badges":3},{"item":"ITEM_ULTRA_BALL","badges":5},{"item":"ITEM_POTION","badges":0},{"item":"ITEM_SUPER_POTION","badges":1},{"item":"ITEM_HYPER_POTION","badges":5},{"item":"ITEM_MAX_POTION","badges":7},{"item":"ITEM_FULL_RESTORE","badges":8},{"item":"ITEM_REVIVE","badges":3},{"item":"ITEM_ANTIDOTE","badges":0},{"item":"ITEM_PARALYZE_HEAL","badges":0},{"item":"ITEM_AWAKENING","badges":1},{"item":"ITEM_BURN_HEAL","badges":1},{"item":"ITEM_ICE_HEAL","badges":1},{"item":"ITEM_FULL_HEAL","badges":5},{"item":"ITEM_ESCAPE_ROPE","badges":1},{"item":"ITEM_REPEL","badges":1},{"item":"ITEM_SUPER_REPEL","badges":3},{"item":"ITEM_MAX_REPEL","badges":5},{"item":"ITEM_QUICK_BALL","badges":0},{"item":"ITEM_TIMER_BALL","badges":0},{"item":"ITEM_REPEAT_BALL","badges":0}]}
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	goto_if_set FLAG_BADGE08_GET, CanalaveCity_Mart_EventScript_ClerkB8
	goto_if_set FLAG_BADGE07_GET, CanalaveCity_Mart_EventScript_ClerkB7
	goto_if_set FLAG_BADGE05_GET, CanalaveCity_Mart_EventScript_ClerkB5
	goto_if_set FLAG_BADGE03_GET, CanalaveCity_Mart_EventScript_ClerkB3
	goto_if_set FLAG_BADGE01_GET, CanalaveCity_Mart_EventScript_ClerkB1
	pokemart CanalaveCity_Mart_EventScript_ClerkItems
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2

CanalaveCity_Mart_EventScript_ClerkItems::
	.2byte ITEM_POKE_BALL
	.2byte ITEM_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_QUICK_BALL
	.2byte ITEM_TIMER_BALL
	.2byte ITEM_REPEAT_BALL
	pokemartlistend

CanalaveCity_Mart_EventScript_ClerkB1::
	pokemart CanalaveCity_Mart_EventScript_ClerkB1Items
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2

CanalaveCity_Mart_EventScript_ClerkB1Items::
	.2byte ITEM_POKE_BALL
	.2byte ITEM_POTION
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_BURN_HEAL
	.2byte ITEM_ICE_HEAL
	.2byte ITEM_ESCAPE_ROPE
	.2byte ITEM_REPEL
	.2byte ITEM_QUICK_BALL
	.2byte ITEM_TIMER_BALL
	.2byte ITEM_REPEAT_BALL
	pokemartlistend

CanalaveCity_Mart_EventScript_ClerkB3::
	pokemart CanalaveCity_Mart_EventScript_ClerkB3Items
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2

CanalaveCity_Mart_EventScript_ClerkB3Items::
	.2byte ITEM_POKE_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_POTION
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_REVIVE
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_BURN_HEAL
	.2byte ITEM_ICE_HEAL
	.2byte ITEM_ESCAPE_ROPE
	.2byte ITEM_REPEL
	.2byte ITEM_SUPER_REPEL
	.2byte ITEM_QUICK_BALL
	.2byte ITEM_TIMER_BALL
	.2byte ITEM_REPEAT_BALL
	pokemartlistend

CanalaveCity_Mart_EventScript_ClerkB5::
	pokemart CanalaveCity_Mart_EventScript_ClerkB5Items
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2

CanalaveCity_Mart_EventScript_ClerkB5Items::
	.2byte ITEM_POKE_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_POTION
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_REVIVE
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_BURN_HEAL
	.2byte ITEM_ICE_HEAL
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_ESCAPE_ROPE
	.2byte ITEM_REPEL
	.2byte ITEM_SUPER_REPEL
	.2byte ITEM_MAX_REPEL
	.2byte ITEM_QUICK_BALL
	.2byte ITEM_TIMER_BALL
	.2byte ITEM_REPEAT_BALL
	pokemartlistend

CanalaveCity_Mart_EventScript_ClerkB7::
	pokemart CanalaveCity_Mart_EventScript_ClerkB7Items
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2

CanalaveCity_Mart_EventScript_ClerkB7Items::
	.2byte ITEM_POKE_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_POTION
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_MAX_POTION
	.2byte ITEM_REVIVE
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_BURN_HEAL
	.2byte ITEM_ICE_HEAL
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_ESCAPE_ROPE
	.2byte ITEM_REPEL
	.2byte ITEM_SUPER_REPEL
	.2byte ITEM_MAX_REPEL
	.2byte ITEM_QUICK_BALL
	.2byte ITEM_TIMER_BALL
	.2byte ITEM_REPEAT_BALL
	pokemartlistend

CanalaveCity_Mart_EventScript_ClerkB8::
	pokemart CanalaveCity_Mart_EventScript_ClerkB8Items
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2

CanalaveCity_Mart_EventScript_ClerkB8Items::
	.2byte ITEM_POKE_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_POTION
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_MAX_POTION
	.2byte ITEM_FULL_RESTORE
	.2byte ITEM_REVIVE
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_BURN_HEAL
	.2byte ITEM_ICE_HEAL
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_ESCAPE_ROPE
	.2byte ITEM_REPEL
	.2byte ITEM_SUPER_REPEL
	.2byte ITEM_MAX_REPEL
	.2byte ITEM_QUICK_BALL
	.2byte ITEM_TIMER_BALL
	.2byte ITEM_REPEAT_BALL
	pokemartlistend