//===-- problems/Invalid.h - Default case from Factory ----------*- C++ -*-===//
//
// ProjectEuler.net solutions by Will Mitchell
//
// This file is distributed under the MIT License. See LICENSE for details.
//
//===----------------------------------------------------------------------===//
///
///
//===----------------------------------------------------------------------===//
#ifndef PROBLEMS_PROBLEM1_H
#define PROBLEMS_PROBLEM1_H

#include <string>

#include "../Problem.h"

namespace problems {
class Problem1 : public Problem {
public:
  Problem1();
  ~Problem1();
  std::string answer();
  void solve();

  int brute_force();
private:
  int sum;
  bool solved;
};
}

#endif
