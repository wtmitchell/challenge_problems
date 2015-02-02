//===-- project_euler/Problem7.h --------------------------------*- C++ -*-===//
//
// Challenge Problem solutions by Will Mitchell
//
// This file is distributed under the MIT License. See LICENSE for details.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// \brief Problem 7: 10001st prime
///
//===----------------------------------------------------------------------===//
#ifndef PROJECT_EULER_PROBLEM7_H
#define PROJECT_EULER_PROBLEM7_H

#include <string>

#include "../Problem.h"

namespace project_euler {
class Problem7 : public Problem {
public:
  Problem7() : prime(0), solved(false) {}
  ~Problem7() = default;
  std::string answer();
  std::string description() const;
  void solve();

  /// Simple brute force solution
  unsigned bruteForce(const unsigned limit) const;
  /// Simple brute force solution
  unsigned bruteForce2(const unsigned limit) const;
  /// Simple brute force solution
  unsigned bruteForce3(const unsigned limit) const;
  /// Simple brute force solution
  unsigned bruteForce4(const unsigned limit) const;

private:
  /// Cached answer
  unsigned prime;
  /// If cached answer is valid
  bool solved;
};
}

#endif
