// Copyright (C) 2017 Florian Kromer - MIT

#ifndef TESTABLE_MULTIPLE_INSTANCE_MODULE_SRC_MODULE_UNDER_TEST_INTERNALS_H_
#define TESTABLE_MULTIPLE_INSTANCE_MODULE_SRC_MODULE_UNDER_TEST_INTERNALS_H_

#include "../inc/module_under_test.h"
#include <stdlib.h>

// compile time test hook:
// test build -> allow access to private interface
// production build -> hide private interface in private source file
#ifdef TEST
//  extern void PrivateMemberSetter(pointer_to_instance_data, int value);
//  extern int PrivateMemberGetter(pointer_to_instance_data);
  extern int PrivateFunction(int multiplicand);
#endif  // TEST

#endif  // TESTABLE_MULTIPLE_INSTANCE_MODULE_SRC_MODULE_UNDER_TEST_INTERNALS_H_
