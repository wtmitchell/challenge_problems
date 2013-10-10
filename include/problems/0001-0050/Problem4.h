//===-- problems/Problem4.h -------------------------------------*- C++ -*-===//
//
// ProjectEuler.net solutions by Will Mitchell
//
// This file is distributed under the MIT License. See LICENSE for details.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// \brief Problem 4: Largest palindrome product
///
//===----------------------------------------------------------------------===//
#ifndef PROBLEMS_PROBLEM4_H
#define PROBLEMS_PROBLEM4_H

#include <string>

#include "../Problem.h"

namespace problems {
class Problem4 : public Problem {
public:
  Problem4() : factor1(0), factor2(0), solved(false) {}
  ~Problem4() = default;
  std::string answer();
  std::string description() const;
  void solve();

private:
  /// Cached answer
  unsigned int factor1;
  unsigned int factor2;
  /// If cached answer is valid
  bool solved;
};
}

#endif
