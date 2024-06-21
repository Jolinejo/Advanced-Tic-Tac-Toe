#include <gtest/gtest.h>
#include <queue>
#include <string>
#include <vector>
#include <iostream>
#include <gamehistory.h>


namespace testing {

TEST(IsValidStringTest, HandlesValidStrings) {
    EXPECT_TRUE(isValidString("XOXO*1234*5678*"));
    EXPECT_TRUE(isValidString("XO*12*3*45678*"));
    EXPECT_TRUE(isValidString("1234567890*XOXOXO*"));
}

TEST(IsValidStringTest, HandlesInvalidStrings) {
    EXPECT_FALSE(isValidString("XOXO*12A4*5678*")); // contains 'A'
    EXPECT_FALSE(isValidString("XO*12*3*4@5678*")); // contains '@'
    EXPECT_FALSE(isValidString("XOXO 1234")); // contains space
}

// Google Test for splitAndEnqueue
TEST(SplitAndEnqueueTest, HandlesMultipleParts) {
    string testStr1 = "part1*part2*part3*part4";
    queue<string> resultQueue1 = splitAndEnqueue(testStr1);

    EXPECT_EQ(resultQueue1.size(), 4);
    EXPECT_EQ(resultQueue1.front(), "part1");
    resultQueue1.pop();
    EXPECT_EQ(resultQueue1.front(), "part2");
    resultQueue1.pop();
    EXPECT_EQ(resultQueue1.front(), "part3");
    resultQueue1.pop();
    EXPECT_EQ(resultQueue1.front(), "part4");
    resultQueue1.pop();
}

TEST(SplitAndEnqueueTest, HandlesSinglePart) {
    string testStr2 = "onlyonepart";
    queue<string> resultQueue2 = splitAndEnqueue(testStr2);

    EXPECT_EQ(resultQueue2.size(), 1);
    EXPECT_EQ(resultQueue2.front(), "onlyonepart");
    resultQueue2.pop();
}

TEST(SplitAndEnqueueTest, HandlesTrailingDelimiter) {
    string testStr3 = "part1*part2*";
    queue<string> resultQueue3 = splitAndEnqueue(testStr3);

    EXPECT_EQ(resultQueue3.size(), 2);
    EXPECT_EQ(resultQueue3.front(), "part1");
    resultQueue3.pop();
    EXPECT_EQ(resultQueue3.front(), "part2");
    resultQueue3.pop();
}

} // namespace testing





