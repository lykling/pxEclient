// Copyright (c) 2013 Legend, Lykling. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "util.h"

void TestGetMacFromDevice() {
  int error;
  uint8_t mac[6];
  error = GetMacFromDevice(mac, "enp5s0");
  fprintf(stdout, "[TEST][GetMacFromDevice]:error:%d\n", error);
  for (int i = 0; i < 6; ++i)
    fprintf(stdout, "%s%02x%c",
            (i)? "": "[TEST][GetMacFromDevice]:mac:",
            mac[i],
            (i == 5)? '\n': '\0');
}

void TestGetIpFromDevice() {
  int error;
  uint8_t ip[4];
  error = GetIpFromDevice(ip, "enp4s0");
  fprintf(stdout, "[TEST][GetIpFromDevice]:error:%d\n", error);
  fprintf(stdout, "[TEST][GetIpFromDevice]:ip:%s\n",
          inet_ntoa(*(struct in_addr *)ip));
}

int main(int argc, char **argv) {
  uint8_t mac[6];
  TestGetMacFromDevice();
  TestGetIpFromDevice();
  return EXIT_SUCCESS;
}
