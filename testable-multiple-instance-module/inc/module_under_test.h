// Copyright (C) 2017 Florian Kromer - MIT

#ifndef TESTABLE_MULTIPLE_INSTANCE_MODULE_INC_MODULE_UNDER_TEST_H_
#define TESTABLE_MULTIPLE_INSTANCE_MODULE_INC_MODULE_UNDER_TEST_H_

#include "../src/module_under_test_internals.h"
#include <stdlib.h>

// forward declaration of abstract data type
typedef struct instance_data_type * pointer_to_instance_data;

extern pointer_to_instance_data Create(void);
extern void Destroy(pointer_to_instance_data);
extern void PublicMemberSetter(pointer_to_instance_data, int value);
extern int PublicMemberGetter(pointer_to_instance_data);
extern int PublicFunction(pointer_to_instance_data, int multiplicand);

#endif  // TESTABLE_MULTIPLE_INSTANCE_MODULE_INC_MODULE_UNDER_TEST_H_
