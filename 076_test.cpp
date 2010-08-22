#include <gtest/gtest.h>

#include <076.h>

TEST(P76, GoodBracketStructures)
{
    EXPECT_EQ(0, getDistanceToRight(""));
    EXPECT_EQ(0, getDistanceToRight("(())"));
    EXPECT_EQ(0, getDistanceToRight("()()"));
    EXPECT_EQ(0, getDistanceToRight("((()()))"));
}

TEST(P76, Simple)
{
    EXPECT_EQ(1, getDistanceToRight("(("));
    EXPECT_EQ(1, getDistanceToRight("()()()((()"));
}

TEST(P76, Broken)
{
    EXPECT_EQ(-1, getDistanceToRight("("));
    EXPECT_EQ(-1, getDistanceToRight("(()"));
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


