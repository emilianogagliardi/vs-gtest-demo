#include "moduleA/CoolClass.h"
#include <gtest/gtest.h>

TEST(CoolClass, ctor)
{
    CoolClass c(1);
    ASSERT_EQ(c.get(), 1);
}

TEST(CoolClass, inc)
{
    CoolClass c(1);
    c.inc();
    ASSERT_EQ(c.get(), 2);
}

TEST(CoolClass, dec)
{
    CoolClass c(1);
    c.dec();
    ASSERT_EQ(c.get(), 0);
}

TEST(CoolClass, equal)
{
    CoolClass c(2);
    CoolClass c1(2);
    ASSERT_EQ(c, c1);
}