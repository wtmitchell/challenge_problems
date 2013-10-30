//===-- problems/Problem16.h ------------------------------------*- C++ -*-===//
//
// ProjectEuler.net solutions by Will Mitchell
//
// This file is distributed under the MIT License. See LICENSE for details.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// \brief Problem 16: Power digit sum
///
//===----------------------------------------------------------------------===//
#ifndef PROBLEMS_PROBLEM16_H
#define PROBLEMS_PROBLEM16_H

#include <string>

#include <gmpxx.h>

#include "../Problem.h"

namespace problems {
class Problem16 : public Problem {
public:
  Problem16() : sum(0), solved(false) {}
  ~Problem16() = default;
  std::string answer();
  std::string description() const;
  void solve();

private:
  /// Cached answer
  unsigned long sum;
  /// If cached answer is valid
  bool solved;
};
}

#endif
