//===-- problems/Problem.h - Base class for problems ------------*- C++ -*-===//
//
// ProjectEuler.net solutions by Will Mitchell
//
// This file is distributed under the MIT License. See LICENSE for details.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// \brief Base class for problems
///
//===----------------------------------------------------------------------===//

#ifndef PROBLEMS_PROBLEM_H
#define PROBLEMS_PROBLEM_H

#include <string>

namespace problems {
/// Base class for problems
class Problem {
public:
  virtual ~Problem();
  /// Returns a user readable answer to the problem
  virtual std::string answer() = 0;
  /// Returns a brief description of the problem
  virtual std::string description() const = 0;
  /// Where the work of the problem is done
  virtual void solve() = 0;
};
}

#endif
