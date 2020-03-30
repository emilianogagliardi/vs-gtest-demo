#include "moduleB/Stack.h"
#include <gtest/gtest.h>
#include <deque>

class StackSimpleTest : public testing::Test {
protected:

    // Called before each test run
    void SetUp() override {
        stackVecString = { "ciao", "a", "te" };
        stackDeqDouble = { 1, 2, 3 };
    }

    Stack<int> emptyStackVec;
    Stack<double, std::deque> emptyStackDeq;
    Stack<std::string> stackVecString;
    Stack<double, std::deque> stackDeqDouble;
};

TEST_F(StackSimpleTest, DefaultCtor)
{
    ASSERT_EQ(emptyStackVec.size(), 0);
    ASSERT_EQ(emptyStackDeq.size(), 0);
    ASSERT_TRUE(emptyStackVec.empty());
    ASSERT_TRUE(emptyStackDeq.empty());
}

TEST_F(StackSimpleTest, top)
{
    ASSERT_EQ(stackVecString.top(), "te");
    ASSERT_EQ(stackDeqDouble.top(), 3);
    stackVecString.top() = "string";
    ASSERT_EQ(stackVecString.top(), "string");
    stackDeqDouble.top() = 1.0;
    ASSERT_EQ(stackDeqDouble.top(), 1.0);
}

TEST_F(StackSimpleTest, pop)
{
    stackDeqDouble.pop();
    ASSERT_EQ(stackDeqDouble.top(), 2);
    stackDeqDouble.pop();
    ASSERT_EQ(stackDeqDouble.top(), 1);

    stackVecString.pop();
    ASSERT_EQ(stackVecString.top(), "a");
    stackVecString.pop();
    ASSERT_EQ(stackVecString.top(), "ciao");
}

TEST_F(StackSimpleTest, popEmpty)
{
    ASSERT_THROW(emptyStackDeq.pop(), std::out_of_range);
    ASSERT_THROW(emptyStackVec.pop(), std::out_of_range);
}

TEST_F(StackSimpleTest, topEmpty)
{
    ASSERT_THROW(emptyStackDeq.top(), std::out_of_range);
    ASSERT_THROW(emptyStackVec.top(), std::out_of_range);
}

TEST_F(StackSimpleTest, push)
{
    emptyStackDeq.push(1.0);
    ASSERT_EQ(emptyStackDeq.size(), 1);
    ASSERT_FALSE(emptyStackDeq.empty());

    stackVecString.push("string");
    ASSERT_EQ(stackVecString.top(), "string");
}