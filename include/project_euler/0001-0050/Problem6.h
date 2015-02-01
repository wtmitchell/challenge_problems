//===-- project_euler/Problem6.h --------------------------------*- C++ -*-===//
//
// ProjectEuler.net solutions by Will Mitchell
//
// This file is distributed under the MIT License. See LICENSE for details.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// \brief Problem 6: Sum square difference
///
//===----------------------------------------------------------------------===//
#ifndef PROJECT_EULER_PROBLEM6_H
#define PROJECT_EULER_PROBLEM6_H

#include <string>

#include "../Problem.h"

namespace project_euler {
class Problem6 : public Problem {
public:
  Problem6() : difference(0), solved(false) {}
  ~Problem6() = default;
  std::string answer();
  std::string description() const;
  void solve();

  /// Simple brute force solution
  unsigned bruteForce(const unsigned limit) const;
  /// Faster analytically derived solution
  unsigned faster(const unsigned limit) const;

private:
  /// Cached answer
  unsigned difference;
  /// If cached answer is valid
  bool solved;
};
}

#endif
