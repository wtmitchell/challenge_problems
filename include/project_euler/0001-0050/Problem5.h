//===-- project_euler/Problem5.h --------------------------------*- C++ -*-===//
//
// Challenge Problem solutions by Will Mitchell
//
// This file is distributed under the MIT License. See LICENSE for details.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// \brief Problem 5: Smallest multiple
///
//===----------------------------------------------------------------------===//
#ifndef PROJECT_EULER_PROBLEM5_H
#define PROJECT_EULER_PROBLEM5_H

#include <string>

#include "../Problem.h"

#include <gmpxx.h>

namespace project_euler {
class Problem5 : public Problem {
public:
  Problem5() : lcm(0), solved(false) {}
  ~Problem5() = default;
  std::string answer();
  std::string description() const;
  void solve();

private:
  /// Cached answer
  mpz_class lcm;
  /// If cached answer is valid
  bool solved;
};
}

#endif
