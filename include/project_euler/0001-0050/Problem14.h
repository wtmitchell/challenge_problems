//===-- project_euler/Problem14.h -------------------------------*- C++ -*-===//
//
// ProjectEuler.net solutions by Will Mitchell
//
// This file is distributed under the MIT License. See LICENSE for details.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// \brief Problem 14: Longest Collatz sequence
///
//===----------------------------------------------------------------------===//
#ifndef PROJECT_EULER_PROBLEM14_H
#define PROJECT_EULER_PROBLEM14_H

#include <string>
#include <vector>

#include "../Problem.h"

namespace project_euler {
class Problem14 : public Problem {
public:
  Problem14() : start(0), length(0), solved(false) {}
  ~Problem14() = default;
  std::string answer();
  std::string description() const;
  void solve();

  /// Simple brute force solution
  unsigned long long bruteForce(const unsigned long long limit) const;
  /// Simple brute force solution with memoization
  unsigned long long
  faster(const unsigned long long limit,
         const std::vector<unsigned long long>::size_type cacheSize) const;

private:
  /// Cached answer
  unsigned long long start;
  /// Cached answer
  mutable unsigned long long length;
  /// If cached answer is valid
  bool solved;
};
}

#endif
