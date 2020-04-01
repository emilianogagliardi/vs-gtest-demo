#include <gtest/gtest.h>
#include "moduleC/simple_mock_example.h"
#include "InterfaceMock.h"

// test for the ClassToTest class with mocked dependency

class ClassToTestTest : public testing::Test {
protected:
    
    ClassToTestTest() : 
        testing::Test(),
        iMock(),
        c(&iMock) 
        // note: iMock ctor is called first because of 
        // order of attributs declaration in class
    {

    }

    InterfaceMock iMock;
    ClassToTest c;
};

TEST_F(ClassToTestTest, doCoolStuffA)
{
    EXPECT_CALL(iMock, doA()).Times(1);
    c.doCoolStuffA();
}

TEST_F(ClassToTestTest, doCoolStuffB)
{
    EXPECT_CALL(iMock, doB(6))
        .Times(1);
    c.doCoolStuffB(5);
}

TEST_F(ClassToTestTest, doCoolStuffC)
{
    EXPECT_CALL(iMock, getC())
        .WillOnce(testing::Return(1));
    ASSERT_EQ(c.doCoolStuffC(), 2);
}