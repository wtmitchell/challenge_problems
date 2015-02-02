//===-- project_euler/Problem15.h -------------------------------*- C++ -*-===//
//
// Challenge Problem solutions by Will Mitchell
//
// This file is distributed under the MIT License. See LICENSE for details.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// \brief Problem 15: Lattice paths
///
//===----------------------------------------------------------------------===//
#ifndef PROJECT_EULER_PROBLEM15_H
#define PROJECT_EULER_PROBLEM15_H

#include <string>

#include <gmpxx.h>

#include "../Problem.h"

namespace project_euler {
class Problem15 : public Problem {
public:
  Problem15() : value(0), solved(false) {}
  ~Problem15() = default;
  std::string answer();
  std::string description() const;
  void solve();

private:
  /// Cached answer
  mpz_class value;
  /// If cached answer is valid
  bool solved;
};
}

#endif
