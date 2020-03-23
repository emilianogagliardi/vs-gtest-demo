#include "pch.h"
#include "..\to_test\include\add.h";

TEST(TestCaseName, TestName) {
  EXPECT_EQ(add(1, 1), 2);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}