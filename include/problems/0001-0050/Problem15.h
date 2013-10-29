//===-- problems/Problem15.h ------------------------------------*- C++ -*-===//
//
// ProjectEuler.net solutions by Will Mitchell
//
// This file is distributed under the MIT License. See LICENSE for details.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// \brief Problem 15: Lattice paths
///
//===----------------------------------------------------------------------===//
#ifndef PROBLEMS_PROBLEM15_H
#define PROBLEMS_PROBLEM15_H

#include <string>

#include <gmpxx.h>

#include "../Problem.h"

namespace problems {
class Problem15 : public Problem {
public:
  Problem15() : value(0), solved(false) {}
  ~Problem15() = default;
  std::string answer();
  std::string description() const;
  void solve();

  // Simple brute force solution
  unsigned long long bruteForce(const unsigned long long limit) const;

private:
  /// Cached answer
  mpz_class value;
  /// If cached answer is valid
  bool solved;
};
}

#endif
