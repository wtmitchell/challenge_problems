//===-- project_euler/Problem10.h -------------------------------*- C++ -*-===//
//
// ProjectEuler.net solutions by Will Mitchell
//
// This file is distributed under the MIT License. See LICENSE for details.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// \brief Problem 10: Summation of primes
///
//===----------------------------------------------------------------------===//
#ifndef PROJECT_EULER_PROBLEM10_H
#define PROJECT_EULER_PROBLEM10_H

#include <string>

#include "../Problem.h"

namespace project_euler {
class Problem10 : public Problem {
public:
  Problem10() : sum(0), solved(false) {}
  ~Problem10() = default;
  std::string answer();
  std::string description() const;
  void solve();

  /// Simple solution based on the Sieve of Eratosthenes
  unsigned long long sieveOfEratosthenes(const unsigned long long limit) const;

private:
  /// Cached answer
  unsigned long long sum;
  /// If cached answer is valid
  bool solved;
};
}

#endif
