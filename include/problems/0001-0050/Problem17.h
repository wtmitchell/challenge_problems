//===-- problems/Problem17.h ------------------------------------*- C++ -*-===//
//
// ProjectEuler.net solutions by Will Mitchell
//
// This file is distributed under the MIT License. See LICENSE for details.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// \brief Problem 17: Number letter counts
///
//===----------------------------------------------------------------------===//
#ifndef PROBLEMS_PROBLEM17_H
#define PROBLEMS_PROBLEM17_H

#include <string>

#include "../Problem.h"

namespace problems {
class Problem17 : public Problem {
public:
  Problem17() : count(0), solved(false) {}
  ~Problem17() = default;
  std::string answer();
  std::string description() const;
  void solve();

  /// Simple brute force solution
  unsigned long bruteForce(const unsigned long limit) const;
  /// Simple brute force solution with optimization for 1000
  unsigned long bruteForce2() const;
  /// Simple brute force solution with more optimization for 1000
  unsigned long bruteForce3() const;

private:
  /// Cached answer
  unsigned long count;
  /// If cached answer is valid
  bool solved;
};
}

#endif
