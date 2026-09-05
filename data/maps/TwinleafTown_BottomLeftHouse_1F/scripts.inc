TwinleafTown_BottomLeftHouse_1F_MapScripts::
	.byte 0

TwinleafTown_BottomLeftHouse_1F_EventScript_OldWoman::
	msgbox TwinleafTown_BottomLeftHouse_1F_Text_ProfessorReturned, MSGBOX_NPC
	end

TwinleafTown_BottomLeftHouse_1F_Text_ProfessorReturned:
	.string "Did you hear?\p"
	.string "The POKéMON Professor returned\n"
	.string "to the next town over.\p"
	.string "They say he was gone for four\n"
	.string "long years.\p"
	.string "I wonder if he found some\n"
	.string "amazing POKéMON while he was\l"
	.string "gone?$"

TwinleafTown_BottomLeftHouse_1F_EventScript_LittleGirl::
	msgbox TwinleafTown_BottomLeftHouse_1F_Text_WantACutePokemon, MSGBOX_NPC
	end

TwinleafTown_BottomLeftHouse_1F_Text_WantACutePokemon:
	.string "Listen, listen, {PLAYER}.\n"
	.string "I want a cute POKéMON!$"
