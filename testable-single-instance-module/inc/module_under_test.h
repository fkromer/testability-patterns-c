// Copyright (C) 2017 Florian Kromer - MIT

#ifndef TESTABLE_SINGLE_INSTANCE_MODULE_INC_MODULE_UNDER_TEST_H_
#define TESTABLE_SINGLE_INSTANCE_MODULE_INC_MODULE_UNDER_TEST_H_

#include "../src/module_under_test_internals.h"  // hide private test only interface
#include <stdlib.h>

extern void Create(void);
extern void Destroy(void);
extern void PublicDataSetter(int value);
extern int PublicDataGetter(void);
extern int PublicFunction(int multiplicand);

#endif  // TESTABLE_SINGLE_INSTANCE_MODULE_INC_MODULE_UNDER_TEST_H_
