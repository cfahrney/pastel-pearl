#include "global.h"
#include "event_data.h"
#include "string_util.h"
#include "trade.h"
#include "constants/event_objects.h"
#include "test/overworld_script.h"
#include "test/test.h"

// Trade Pokémon: RememberTradedMon (run by ingame_trade) keeps the player's mon so its overworld object can show it.

TEST("(Trade) RememberTradedMon saves the chosen party mon's sprite and nickname")
{
    static const u8 nickname[] = _("Blu");

    ZeroPlayerPartyMons();
    RUN_OVERWORLD_SCRIPT(givemon SPECIES_ZUBAT, 10, gender=MON_FEMALE;);
    SetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_NICKNAME, nickname);
    gSpecialVar_0x8004 = 0;
    gSpecialVar_0x8005 = INGAME_TRADE_SEEDOT;
    RememberTradedMon();

    EXPECT_EQ(gSaveBlock3Ptr->tradedMons[INGAME_TRADE_SEEDOT].gfxId & OBJ_EVENT_MON_SPECIES_MASK, SPECIES_ZUBAT);
    EXPECT(gSaveBlock3Ptr->tradedMons[INGAME_TRADE_SEEDOT].gfxId & OBJ_EVENT_MON);
    EXPECT(gSaveBlock3Ptr->tradedMons[INGAME_TRADE_SEEDOT].gfxId & OBJ_EVENT_MON_FEMALE);
    EXPECT_EQ(StringCompare(gSaveBlock3Ptr->tradedMons[INGAME_TRADE_SEEDOT].nickname, nickname), 0);
}

TEST("(Trade) BufferTradedMon gives the traded mon's name and species, or SPECIES_NONE before the trade")
{
    static const u8 nickname[] = _("Blu");

    memset(gSaveBlock3Ptr->tradedMons, 0, sizeof(gSaveBlock3Ptr->tradedMons));
    gSpecialVar_0x8005 = INGAME_TRADE_PLUSLE;
    BufferTradedMon();
    EXPECT_EQ(gSpecialVar_Result, SPECIES_NONE);

    gSaveBlock3Ptr->tradedMons[INGAME_TRADE_PLUSLE].gfxId = SPECIES_ZUBAT + OBJ_EVENT_MON;
    StringCopy(gSaveBlock3Ptr->tradedMons[INGAME_TRADE_PLUSLE].nickname, nickname);
    BufferTradedMon();
    EXPECT_EQ(gSpecialVar_Result, SPECIES_ZUBAT);
    EXPECT_EQ(StringCompare(gStringVar1, nickname), 0);
}
