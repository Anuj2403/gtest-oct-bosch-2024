#include "gtest/gtest.h"
#include "TestChallenge.h"

TEST(AddTest, CorrectSum) {
    int result = 0;
    add(5, 3, &result);
    EXPECT_EQ(result, 8);
}

TEST(AddTest, IncorrectOutput) {
    int result = 0;
    add(5, 3, &result);
    EXPECT_EQ(to_string(result), "8");
}
