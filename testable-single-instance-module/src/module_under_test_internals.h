// Copyright (C) 2017 Florian Kromer - MIT

#ifndef TESTABLE_SINGLE_INSTANCE_MODULE_SRC_MODULE_UNDER_TEST_INTERNALS_H_
#define TESTABLE_SINGLE_INSTANCE_MODULE_SRC_MODULE_UNDER_TEST_INTERNALS_H_

#include <stdlib.h>

// compile time test code side test hook
#ifdef TEST
  extern int PrivateFunction(int multiplicand);
  extern void PrivateDataSetter(int value);
  extern int PrivateDataGetter();
#endif  // TEST

#endif  // TESTABLE_SINGLE_INSTANCE_MODULE_SRC_MODULE_UNDER_TEST_INTERNALS_H_
