#include <gtest/gtest.h>
#include "moduleB/Counter.h"

template<typename T> 
class CounterTest : public testing::Test {
protected:
    T counter;
};

typedef testing::Types<PrefixCounter, PostfixCounter> Implementations;

TYPED_TEST_CASE(CounterTest, Implementations);

TYPED_TEST(CounterTest, DefCtor)
{
    ASSERT_EQ(counter.get(), 0);
}

TYPED_TEST(CounterTest, Inc)
{
    counter.inc();
    ASSERT_EQ(counter.get(), 1);
}