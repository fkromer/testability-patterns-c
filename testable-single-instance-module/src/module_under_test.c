// Copyright (C) 2017 Florian Kromer - MIT

#include "module_under_test.h"

// compile time test hook (broadening of API)
#ifdef TEST
  #define static
#endif
// single instance module with dynamic memory allocation for its data

typedef struct {
  int public_data;
  int private_data;
} module_data_type;

// persistent single instance data
static module_data_type module_data;

// "static" function prototypes for private functions in production
#ifndef TEST
  static int PrivateFunction(int multiplicand);
  static void PrivateDataSetter(int value);
  static int PrivateDataGetter(void);
#endif

void Create(void) {
  module_data.public_data = 0;
  module_data.private_data = 0;
  return;
}

void Destroy(void) {
  // nothing to do in this simple case
  return;
}

void PublicDataSetter(int value) {
  module_data.public_data = value;
  return;
}

int PublicDataGetter(void) {
  return module_data.public_data;
}

int PublicFunction(int multiplicand) {
  int multiplier = 42;
  module_data.private_data = PrivateFunction(1);
  return multiplier*multiplicand;
}

void PrivateDataSetter(int value) {
  module_data.private_data = value;
  return;
}

int PrivateDataGetter(void) {
  return module_data.private_data;
}

int PrivateFunction(int multiplicand) {
  int multiplier = 42;
  return multiplier*multiplicand;
}
