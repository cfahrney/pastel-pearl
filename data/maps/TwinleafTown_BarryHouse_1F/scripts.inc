TwinleafTown_BarryHouse_1F_MapScripts::
	.byte 0

TwinleafTown_BarryHouse_1F_EventScript_Mom::
	goto_if_ge VAR_TWINLEAF_TOWN_STATE, 12, TwinleafTown_BarryHouse_1F_EventScript_MomAfterStarterCaught
	goto_if_ge VAR_TWINLEAF_TOWN_STATE, 2, TwinleafTown_BarryHouse_1F_EventScript_MomAfterBarryLeft
	msgbox TwinleafTown_BarryHouse_1F_Text_HeCantSitStill, MSGBOX_NPC
	end

TwinleafTown_BarryHouse_1F_EventScript_MomAfterBarryLeft::
	msgbox TwinleafTown_BarryHouse_1F_Text_RocketedOffAgain, MSGBOX_NPC
	end

TwinleafTown_BarryHouse_1F_EventScript_MomAfterStarterCaught::
	msgbox TwinleafTown_BarryHouse_1F_Text_FriendsWithAPokemon, MSGBOX_NPC
	end

TwinleafTown_BarryHouse_1F_Text_HeCantSitStill:
	.string "Oh, hi, {PLAYER}.\p"
	.string "Did you come calling on {RIVAL}?\p"
	.string "He was gone for a second, but then\n"
	.string "he came running right back home.\p"
	.string "He just can't sit still, that boy.\n"
	.string "I wonder who he takes after.$"

TwinleafTown_BarryHouse_1F_Text_RocketedOffAgain:
	.string "That kid rocketed off again like\n"
	.string "usual.\p"
	.string "I guess he would be out on\n"
	.string "Route 201 by now?\p"
	.string "He just can't sit still, that boy.\n"
	.string "I wonder who he takes after?$"

TwinleafTown_BarryHouse_1F_Text_FriendsWithAPokemon:
	.string "Oh, you've become friends with a\n"
	.string "Pokémon, too.$"
