// Copyright (c) 2013 Legend, Lykling. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include <cstdio>
#include "option.h"

namespace {
  const char sExamples[] =
      "Example:\n\tpxEclient -uusername -ppassword -deth0\n";
  const char sOptions[] = "Options:\n \
      \t-u, username\t\tinput your NetID\n \
      \t-p, password\t\tinput your password\n \
      \t-d, device\t\tinput your net device\n";
  const char sUsage[] = "Usage:\n\tpxEclient [OPTIONS..]\n";
}

namespace option {

OptionCheck::OptionCheck() {
  argc_ = 0;
  argv_ = NULL;
  is_valid_ = false;
}

OptionCheck::OptionCheck(int argc, char** argv) {
  argc_ = argc;
  argv_ = argv;
  is_valid_ = false;
}

OptionCheck::~OptionCheck() {
}

void OptionCheck::PrintOptions(int status) {
  switch (status) {
    case 0:
      printf("%s", sUsage);
      printf("%s", sOptions);
      printf("%s", sExamples);
      break;
    case 1:
      printf("Too much parameters!!!\n");
      printf("%s", sUsage);
      printf("%s", sOptions);
      printf("%s", sExamples);
      break;
    default:
      break;
  }
}

void OptionCheck::RunCheckLoop() {
  if (argc_ <= 1) {
    PrintOptions(0);
  } else if (argc_ >= 4) {
    PrintOptions(1);
  }
  // TODO(legend): main logic block to do.
  while (!is_valid_) {
    printf("%s\n", argv_[0]);
    is_valid_ = true;
  }
}

}  // namespace option
