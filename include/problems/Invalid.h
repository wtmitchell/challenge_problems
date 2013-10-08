//===-- problems/Invalid.h - Default case from Factory ----------*- C++ -*-===//
//
// ProjectEuler.net solutions by Will Mitchell
//
// This file is distributed under the MIT License. See LICENSE for details.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// \brief Default class for an invalid problem number
///
//===----------------------------------------------------------------------===//
#ifndef PROBLEMS_INVALID_H
#define PROBLEMS_INVALID_H

#include <string>

#include "Problem.h"

namespace problems {
/// Default class for an invalid problem number
class Invalid : public Problem {
public:
  Invalid();
  ~Invalid();
  std::string answer();
  std::string description() const;
  void solve();
};
}

#endif
