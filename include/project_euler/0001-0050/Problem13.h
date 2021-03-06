//===-- project_euler/Problem13.h -------------------------------*- C++ -*-===//
//
// Challenge Problem solutions by Will Mitchell
//
// This file is distributed under the MIT License. See LICENSE for details.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// \brief Problem 13: Large sum
///
//===----------------------------------------------------------------------===//
#ifndef PROJECT_EULER_PROBLEM13_H
#define PROJECT_EULER_PROBLEM13_H

#include <string>

#include <gmpxx.h>

#include "../Problem.h"

namespace project_euler {
class Problem13 : public Problem {
public:
  Problem13() : value(""), sum(0), solved(false) {}
  ~Problem13() = default;
  std::string answer();
  std::string description() const;
  void solve();

private:
  /// Cached answer
  std::string value;
  /// Cached answer
  mpz_class sum;
  /// If cached answer is valid
  bool solved;
};
}

#endif
