//===-- problems/Problem3.h -------------------------------------*- C++ -*-===//
//
// ProjectEuler.net solutions by Will Mitchell
//
// This file is distributed under the MIT License. See LICENSE for details.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// \brief Problem 3: Largest prime factor
///
//===----------------------------------------------------------------------===//
#ifndef PROBLEMS_PROBLEM3_H
#define PROBLEMS_PROBLEM3_H

#include <string>

#include "../Problem.h"

namespace problems {
class Problem3 : public Problem {
public:
  Problem3() : factor(0), solved(false) {}
  ~Problem3() = default;
  std::string answer();
  std::string description() const;
  void solve();

  /// Faster solution
  unsigned long long faster(const unsigned long long limit);

private:
  /// Cached answer
  unsigned long long factor;
  /// If cached answer is valid
  bool solved;
};
}

#endif
