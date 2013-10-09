//===-- problems/Problem2.h -------------------------------------*- C++ -*-===//
//
// ProjectEuler.net solutions by Will Mitchell
//
// This file is distributed under the MIT License. See LICENSE for details.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// \brief Problem 2: Even Fibonacci Numbers
///
//===----------------------------------------------------------------------===//
#ifndef PROBLEMS_PROBLEM2_H
#define PROBLEMS_PROBLEM2_H

#include <string>

#include "../Problem.h"

namespace problems {
class Problem2 : public Problem {
public:
  Problem2() : sum(0), solved(false) {}
  ~Problem2() = default;
  std::string answer();
  std::string description() const;
  void solve();

  /// Brute force solution
  unsigned int brute_force(const unsigned int limit);
  /// Faster solution
  unsigned int faster(const unsigned int limit);

private:
  /// Cached answer
  unsigned int sum;
  /// If cached answer is valid
  bool solved;
};
}

#endif
