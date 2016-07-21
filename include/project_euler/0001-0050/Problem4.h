//===-- project_euler/Problem4.h --------------------------------*- C++ -*-===//
//
// Challenge Problem solutions by Will Mitchell
//
// This file is distributed under the MIT License. See LICENSE for details.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// \brief Problem 4: Largest palindrome product
///
//===----------------------------------------------------------------------===//
#ifndef PROJECT_EULER_PROBLEM4_H
#define PROJECT_EULER_PROBLEM4_H

#include <string>

#include "../Problem.h"

namespace project_euler {
class Problem4 : public Problem {
public:
  Problem4() : factor1(0), factor2(0), solved(false) {}
  ~Problem4() = default;
  std::string answer();
  std::string description() const;
  void solve();

  /// Look through all potential numbers
  void brute_force();

private:
  /// Cached answer
  unsigned int factor1;
  /// Cached answer
  unsigned int factor2;
  /// If cached answer is valid
  bool solved;
};
}

#endif
