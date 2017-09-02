// Copyright (C) 2017 Florian Kromer - MIT

#include "gtest/gtest.h"

extern "C" {
  #include "module_under_test.h"
}

// testing public functions is not critical
TEST(SingleInstanceUnderTest, PublicFunctionExemplaryGoodCase) {
  pointer_to_instance_data instanceUnderTest;
  instanceUnderTest = Create();
  int directTestInput = 1;
  int expectedDirectTestOutput = 42;
  EXPECT_EQ(expectedDirectTestOutput, PublicFunction(instanceUnderTest, directTestInput));
  Destroy(instanceUnderTest);
}

// testing private function would not be possible without test related consideration
TEST(SingleInstanceUnderTest, PrivateFunctionExemplaryGoodCase) {
  pointer_to_instance_data instanceUnderTest;
  instanceUnderTest = Create();
  int directTestInput = 1;
  int expectedDirectTestOutput = 42;
  EXPECT_EQ(expectedDirectTestOutput, PrivateFunction(directTestInput));
  Destroy(instanceUnderTest);
}

// using public member setter/getter in tests (controllability, observability)
// is not problematic
TEST(SingleInstanceUnderTest, PublicMemberExemplaryGoodCase) {
  pointer_to_instance_data instanceUnderTest;
  instanceUnderTest = Create();
  int directTestInput = 5;
  int expectedDirectTestOutput = directTestInput;
  PublicMemberSetter(instanceUnderTest, directTestInput);
  int observedDirectTestOutput = PublicMemberGetter(instanceUnderTest);
  EXPECT_EQ(expectedDirectTestOutput, observedDirectTestOutput);
  Destroy(instanceUnderTest);
}

// using private member setter/getter in tests (controllability, observability)
// would not be possible without test related consideration
//TEST(SingleInstanceUnderTest, PrivateMemberExemplaryGoodCase) {
//  pointer_to_instance_data instanceUnderTest;
//  instanceUnderTest = Create();
//  int directTestInput = 5;
//  int expectedDirectTestOutput = directTestInput;
//  PrivateMemberSetter(instanceUnderTest, directTestInput);
//  int observedDirectTestOutput = PrivateMemberGetter(instanceUnderTest);
//  EXPECT_EQ(expectedDirectTestOutput, observedDirectTestOutput);
//  Destroy(instanceUnderTest);
//}

// which would be required to test the exemplary public function (which modifies
// the module private state)
//TEST(SingleInstanceUnderTest, PrivateMemberIndirectTestOutputExemplaryGoodCase) {
//  pointer_to_instance_data instanceUnderTest;
//  instanceUnderTest = Create();
//  int expectedIndirectTestOutput = 5;
//  int irrelevantTestInput = 1;
//  PublicFunction(instanceUnderTest, irrelevantTestInput);  // call modifies private member
//  int observedIndirectTestOutput = PrivateMemberGetter(instanceUnderTest);
//  EXPECT_EQ(expectedDirectTestOutput, observedIndirectTestOutput);
//}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
