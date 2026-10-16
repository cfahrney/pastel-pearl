#include "global.h"
#include "event_data.h"
#include "test/test.h"

TEST("Extra vars are stored apart from the base vars")
{
    VarSet(EXTRA_VARS_START, 123);
    VarSet(EXTRA_VARS_END, 456);
    VarSet(VARS_END, 789);
    EXPECT_EQ(VarGet(EXTRA_VARS_START), 123);
    EXPECT_EQ(VarGet(EXTRA_VARS_END), 456);
    EXPECT_EQ(VarGet(VARS_END), 789);
    EXPECT_EQ(gSaveBlock1Ptr->varsExtra[0], 123);
}

TEST("Values between the var ranges are literals")
{
    EXPECT_EQ(VarGet(VARS_END + 1), VARS_END + 1);
    EXPECT_EQ(VarGet(EXTRA_VARS_START - 1), EXTRA_VARS_START - 1);
    EXPECT(!VarSet(VARS_END + 1, 5));
}

TEST("Extra flags are stored apart from the base flags")
{
    FlagClear(EXTRA_FLAGS_START);
    FlagClear(EXTRA_FLAGS_END);
    FlagSet(FLAGS_COUNT - 1);
    EXPECT(!FlagGet(EXTRA_FLAGS_START));
    FlagSet(EXTRA_FLAGS_START);
    FlagSet(EXTRA_FLAGS_END);
    EXPECT(FlagGet(EXTRA_FLAGS_START));
    EXPECT(FlagGet(EXTRA_FLAGS_END));
    EXPECT_EQ(gSaveBlock1Ptr->flagsExtra[0] & 1, 1);
}
