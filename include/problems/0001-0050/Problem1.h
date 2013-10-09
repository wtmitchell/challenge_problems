//===-- problems/Problem1.h -------------------------------------*- C++ -*-===//
//
// ProjectEuler.net solutions by Will Mitchell
//
// This file is distributed under the MIT License. See LICENSE for details.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// \brief Problem 1: Multiples of 3 and 5
///
//===----------------------------------------------------------------------===//
#ifndef PROBLEMS_PROBLEM1_H
#define PROBLEMS_PROBLEM1_H

#include <string>

#include "../Problem.h"

namespace problems {
class Problem1 : public Problem {
public:
  Problem1() : sum(0), solved(false) {}
  ~Problem1() = default;
  std::string answer();
  std::string description() const;
  void solve();

  /// Brute force solution
  int brute_force(const int limit);
  /// Faster analytic solution
  int faster(const int limit);

private:
  /// Cached answer
  int sum;
  /// If cached answer is valid
  bool solved;
};
}

#endif
