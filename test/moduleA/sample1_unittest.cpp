#include "moduleA/sample1.h"
#include <gtest/gtest.h>

TEST(AddTest, Zero)
{
    for(auto x : {10, 20, 11, 23, 1, 78})
        ASSERT_EQ(add(x, 0), x);
}
TEST(AddTest, Positive)
{
    ASSERT_EQ(add(1, 2), 3);
    ASSERT_EQ(add(2, 2), 4);
    ASSERT_EQ(add(2, 3), 5);
}
TEST(AddTest, Negative)
{
    ASSERT_EQ(add(1, -2), -1);
    ASSERT_EQ(add(-2, -2), -4);
    ASSERT_EQ(add(-2, 3), 1);
}

TEST(SubTest, Zero)
{
    for (auto x : { 1, 2, 3, 4, 5 }) {
        ASSERT_EQ(sub(x, 0), x);
        ASSERT_EQ(sub(0, x), -x);
    }
}

TEST(SubTest, Equal)
{
    for (auto x : { 1, 2, 3, 4, 5 }) {
        ASSERT_EQ(sub(x, x), 0);
    }
}

TEST(SubTest, General)
{
    ASSERT_EQ(sub(1, -2), 3);
    ASSERT_EQ(sub(3, 2), 1);
    ASSERT_EQ(sub(-2, 3), -5);
}