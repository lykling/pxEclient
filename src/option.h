// Copyright (c) 2013 Legend, Lykling. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef SRC_OPTION_H_
#define SRC_OPTION_H_

namespace option {

enum OptionType {
  OptionUsername,
  OptionPassword,
  OptionDevices
};

class OptionCheck {
  public:
    OptionCheck();
    OptionCheck(int argc, char* argv[]);
    ~OptionCheck();
    void RunCheckLoop();
  protected:
    void PrintOptions(int status);
  private:
    bool is_valid_;
    char** argv_;
    int argc_;
};

}  // namespace option


#endif  // SRC_OPTION_H_
