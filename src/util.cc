// Copyright (c) 2013 Legend, Lykling. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "util.h"

int GetMacFromDevice(uint8_t *mac, const char *devicename) {
  int error;
  int fd;
  struct ifreq ifreq;

  fd = socket(AF_INET, SOCK_STREAM, 0);
  if (fd == -1) {
    perror("SOCKET");
    return FALSE;
  }

  strncpy(ifreq.ifr_name, devicename, IFNAMSIZ);
  ifreq.ifr_addr.sa_family = AF_INET;

  error = ioctl(fd, SIOCGIFHWADDR, &ifreq);
  if (error == -1) {
    perror("IOCTL");
    return FALSE;
  }

  memcpy(mac, ifreq.ifr_hwaddr.sa_data, 6);
  return TRUE;
}

int GetIpFromDevice(uint8_t *ip, const char *devicename) {
  int error;
  int fd;
  struct ifreq ifreq;

  fd = socket(AF_INET, SOCK_DGRAM, 0);
  if (fd == -1) {
    perror("SOCKET");
    return FALSE;
  }

  strncpy(ifreq.ifr_name, devicename, IFNAMSIZ);
  ifreq.ifr_addr.sa_family = AF_INET;

  error = ioctl(fd, SIOCGIFADDR, &ifreq);
  if (error == 0)
    memcpy(ip, &(((struct sockaddr_in *)(&ifreq.ifr_addr))->sin_addr), 4);
  else {
    memset(ip, 0x00, 4);
    return FALSE;
  }
  return TRUE;
}
