@ Sets VAR_OBJ_GFX_ID_1 to whichever protagonist (LUCAS/DAWN) the player
@ did NOT choose, for maps where the other one shows up as PROFESSOR
@ ROWAN's assistant (LAKE VERITY, ROUTE 201, and anywhere else this
@ character reappears). Call from MAP_SCRIPT_ON_TRANSITION so it's
@ resolved before the object ever gets a chance to spawn on screen.
@
@ This is the single source of truth for that gender check — every map
@ using the assistant should call this instead of keeping its own copy,
@ so the two can never drift out of sync with each other.
Common_EventScript_SetupLucasDawnAssistantGfxId::
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, Common_EventScript_SetupLucasDawnAssistantGfxIdFemale
	goto_if_eq VAR_RESULT, FEMALE, Common_EventScript_SetupLucasDawnAssistantGfxIdMale
	end

Common_EventScript_SetupLucasDawnAssistantGfxIdFemale::
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_DAWN_NORMAL
	return

Common_EventScript_SetupLucasDawnAssistantGfxIdMale::
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_LUCAS_NORMAL
	return
