// Copyright (c) 2013 Legend, Lykling. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "util.h"

int GetMacFromDevice(uint8_t *mac, const char *devicename) {
  int err;
  int fd;
  struct ifreq ifreq;

  fd = socket(AF_INET, SOCK_STREAM, 0);
  if (fd == -1) {
    perror("SOCKET");
    return FALSE;
  }

  strncpy(ifreq.ifr_name, devicename, IFNAMSIZ);
  ifreq.ifr_addr.sa_family = AF_INET;

  err = ioctl(fd, SIOCGIFHWADDR, &ifreq);
  if (err == -1) {
    perror("IOCTL");
    return FALSE;
  }

  memcpy(mac, ifreq.ifr_hwaddr.sa_data, 6);
  return TRUE;
}

