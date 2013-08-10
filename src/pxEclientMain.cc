// Copyright (c) 2013 Legend, Lykling. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.


#include "auth.h"
#include "option.h"
#include "packet.h"

int main(int argc, char *argv[]) {
  option::OptionCheck option_check(argc, argv);
  option_check.RunCheckLoop();
  return 0;
}
