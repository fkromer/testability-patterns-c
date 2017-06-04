// Copyright (C) 2017 Florian Kromer - MIT

#include "gtest/gtest.h"

extern "C" {
  #include "module_under_test.h"
}

// testing public functions is not critical
TEST(PublicFunctionTest, ExemplaryGoodCase) {
  Create();
  int directTestInput = 1;
  int expectedDirectTestOutput = 42;
  EXPECT_EQ(expectedDirectTestOutput, PublicFunction(directTestInput));
  Destroy();
}

//TEST(PublicMemberTest, ExemplaryGoodCase) {
//  PublicMemberSetter(5);
//  int expectedIndirectTestOutput = 5;
//  int observedIndirectTestOutput = PublicMemberGetter();
//  EXPECT_EQ(expectedIndirectTestOutput, observedIndirectTestOutput);
//}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
