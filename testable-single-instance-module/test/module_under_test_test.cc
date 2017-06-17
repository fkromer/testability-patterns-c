// Copyright (C) 2017 Florian Kromer - MIT

#include "gtest/gtest.h"

extern "C" {
  #include "module_under_test.h"
}

// testing public functions is not problematic
TEST(PublicFunctionTest, ExemplaryGoodCase) {
  Create();
  int directTestInput = 1;
  int expectedDirectTestOutput = 42;
  EXPECT_EQ(expectedDirectTestOutput, PublicFunction(directTestInput));
  Destroy();
}

// accessing public data is not problematic
TEST(PublicDataTest, ExemplaryGoodCase) {
  Create();
  PublicDataSetter(5);
  int expectedIndirectTestOutput = 5;
  int observedIndirectTestOutput = PublicDataGetter();
  EXPECT_EQ(expectedIndirectTestOutput, observedIndirectTestOutput);
  Destroy();
}

// accessing the whole module state would not be possible without
// "Design For Testability"
TEST(ModuleStateTest, ExemplaryGoodCase) {
  Create();
  module_data_type expectedIndirectTestOutput;
  expectedIndirectTestOutput.public_data = 5;
  expectedIndirectTestOutput.private_data = 7;
  ModuleDataSetter(expectedIndirectTestOutput);
  module_data_type observedIndirectTestOutput = ModuleDataGetter();
  // EXPECT_EQ is not capable of evaluating:
  // EXPECT_EQ(expectedIndirectTestOutput, observedIndirectTestOutput)
  EXPECT_EQ(expectedIndirectTestOutput.public_data, observedIndirectTestOutput.public_data);
  EXPECT_EQ(expectedIndirectTestOutput.private_data, observedIndirectTestOutput.private_data);
  Destroy();
}

// accessing private data would not be possible without "Design For Testability"
TEST(PrivateDataTest, ExemplaryGoodCase) {
  Create();
  PrivateDataSetter(5);
  int expectedIndirectTestOutput = 5;
  int observedIndirectTestOutput = PrivateDataGetter();
  EXPECT_EQ(expectedIndirectTestOutput, observedIndirectTestOutput);
  Destroy();
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
