// Copyright (c) 2013 Legend, Lykling. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "util.h"

void TestGetMacFromDevice() {
  int error;
  uint8_t mac[6];
  error = GetMacFromDevice(mac, "enp5s1");
  fprintf(stdout, "%d", error);
}

int main(int argc, char **argv) {
  uint8_t mac[6];
  TestGetMacFromDevice();
  return EXIT_SUCCESS;
}
