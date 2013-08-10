// Copyright (c) 2013 Legend, Lykling. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef SRC_UTIL_H_
#define SRC_UTIL_H_

#include <assert.h>
#include <errno.h>
#include <pcap.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <arpa/inet.h>
#include <net/if.h>
#include <netinet/in.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <sys/wait.h>


#define FALSE 0
#define TRUE 1

int GetMacFromDevice(uint8_t *mac, const char *devicename);

#endif  // SRC_UTIL_H_
