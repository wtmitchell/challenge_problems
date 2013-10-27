//===-- problems/Problem12.h ------------------------------------*- C++ -*-===//
//
// ProjectEuler.net solutions by Will Mitchell
//
// This file is distributed under the MIT License. See LICENSE for details.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// \brief Problem 12: Highly divisible triangular number
///
//===----------------------------------------------------------------------===//
#ifndef PROBLEMS_PROBLEM12_H
#define PROBLEMS_PROBLEM12_H

#include <string>

#include "../Problem.h"

namespace problems {
class Problem12 : public Problem {
public:
  Problem12() : value(0), solved(false) {}
  ~Problem12() = default;
  std::string answer();
  std::string description() const;
  void solve();

  /// Simple brute force solution
  unsigned long long bruteForce(const unsigned long long limit) const;
  /// Faster solution
  unsigned long long faster(const unsigned long long limit) const;

private:
  /// Cached answer
  unsigned long long value;
  /// Cached answer
  mutable unsigned long long n;
  /// If cached answer is valid
  bool solved;
};
}

#endif
