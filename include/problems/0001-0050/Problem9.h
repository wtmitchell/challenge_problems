//===-- problems/Problem9.h -------------------------------------*- C++ -*-===//
//
// ProjectEuler.net solutions by Will Mitchell
//
// This file is distributed under the MIT License. See LICENSE for details.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// \brief Problem 9: Special Pythagorean triplet
///
//===----------------------------------------------------------------------===//
#ifndef PROBLEMS_PROBLEM9_H
#define PROBLEMS_PROBLEM9_H

#include <string>

#include "../Problem.h"

namespace problems {
class Problem9 : public Problem {
public:
  Problem9() : product(0), solved(false) {}
  ~Problem9() = default;
  std::string answer();
  std::string description() const;
  void solve();

  /// Solve using brute force
  unsigned bruteForce(const unsigned sum);

  /// Solve using analytic improvements
  unsigned faster(const unsigned sum);

private:
  /// Cached answer
  unsigned a;
  /// Cached answer
  unsigned b;
  /// Cached answer
  unsigned c;
  /// Cached answer
  unsigned product;
  /// If cached answer is valid
  bool solved;
};
}

#endif
