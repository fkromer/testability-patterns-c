// Copyright (C) 2017 Florian Kromer - MIT

#include "module_under_test.h"

// compile time test hook:
// production build -> hide private interface in private source file
// test build -> allow access to private interface
#ifndef TEST
//  static void PrivateMemberSetter(pointer_to_instance_data, int value);
//  static int PrivateMemberGetter(pointer_to_instance_data);
  static int PrivateFunction(int multiplicand);
#endif

struct instance_data_type {
  int public_member;
  int private_member;
} instance_data_type;

pointer_to_instance_data Create(void) {
  pointer_to_instance_data self = calloc(1, sizeof(instance_data_type));
  self->public_member = 0;
  self->private_member = 0;
  return self;
}

void Destroy(pointer_to_instance_data self) {
  //free(self->public_member);
  //free(self->private_member);
  free(self);
  self = NULL;
  return;
}

void PublicMemberSetter(pointer_to_instance_data self, int value) {
  self->public_member = value;
  return;
}

int PublicMemberGetter(pointer_to_instance_data self) {
  return self->public_member;
}

int PublicFunction(pointer_to_instance_data self, int multiplicand) {
  int multiplier = 42;
  self->private_member = PrivateFunction(1);
  return multiplier*multiplicand;
}

//void PrivateMemberSetter(pointer_to_instance_data self, int value) {
//  self->private_member = value;
//  return;
//}

//int PrivateMemberGetter(pointer_to_instance_data self) {
//  return self->private_member;
//}

int PrivateFunction(int multiplicand) {
  int multiplier = 42;
  return multiplier*multiplicand;
}
