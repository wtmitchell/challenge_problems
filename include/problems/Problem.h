//===-- problems/Problem.h - Base class for problems ------------*- C++ -*-===//
//
// ProjectEuler.net solutions by Will Mitchell
//
// This file is distributed under the MIT License. See LICENSE for details.
//
//===----------------------------------------------------------------------===//
///
/// \brief Base class for problems
///
//===----------------------------------------------------------------------===//

#ifndef PROBLEMS_PROBLEM_H
#define PROBLEMS_PROBLEM_H

#include <string>

namespace problems {
  class Problem {
    virtual std::string answer() = 0;
    virtual void solve() = 0;
  };
}

#endif
