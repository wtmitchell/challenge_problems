//===-- problems/Problem1.h - Problem 1 -------------------------*- C++ -*-===//
//
// ProjectEuler.net solutions by Will Mitchell
//
// This file is distributed under the MIT License. See LICENSE for details.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// \brief Problem1: Multiples of 3 and 5
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
