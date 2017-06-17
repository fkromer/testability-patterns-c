// Copyright (C) 2017 Florian Kromer - MIT

#include "module_under_test.h"

// compile time test hook:
// test build -> undefine static to allow making entities public in public header file
#ifdef TEST
  #define static
#endif

// compile time test hook:
// production build -> declare in private source file
// test build -> declare in public header to allow accessing whole module state
#ifndef TEST
  typedef struct {
    int public_data;
    int private_data;
  } module_data_type;
#endif

// persistent single instance data
static module_data_type module_data;

// compile time test hook:
// production build -> "static" function prototypes for private functions
#ifndef TEST
  static int PrivateFunction(int multiplicand);
  static void ModuleDataSetter(module_data_type data);
  static module_data_type ModuleDataSetter(void);
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

void ModuleDataSetter(module_data_type data) {
  module_data = data;
  return;
}

module_data_type ModuleDataGetter(void) {
  return module_data;
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
