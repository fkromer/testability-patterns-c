// Copyright (C) 2017 Florian Kromer - MIT

#ifndef TESTABLE_SINGLE_INSTANCE_MODULE_SRC_MODULE_UNDER_TEST_INTERNALS_H_
#define TESTABLE_SINGLE_INSTANCE_MODULE_SRC_MODULE_UNDER_TEST_INTERNALS_H_

#include <stdlib.h>

// compile time test hook:
// test build -> allow access to private interface
// production build -> hide private interface in private source file
#ifdef TEST
  typedef struct {
    int public_data;
    int private_data;
  } module_data_type;

  extern int PrivateFunction(int multiplicand);
  extern void SetModuleData();
  extern void ModuleDataSetter(module_data_type data);
  extern module_data_type ModuleDataGetter(void);
  extern void PrivateDataSetter(int value);
  extern int PrivateDataGetter();
#endif  // TEST

#endif  // TESTABLE_SINGLE_INSTANCE_MODULE_SRC_MODULE_UNDER_TEST_INTERNALS_H_
