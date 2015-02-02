//===-- project_euler/Invalid.h ---------------------------------*- C++ -*-===//
//
// Challenge Problem solutions by Will Mitchell
//
// This file is distributed under the MIT License. See LICENSE for details.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// \brief Default class for an invalid problem number
///
//===----------------------------------------------------------------------===//
#ifndef PROJECT_EULER_INVALID_H
#define PROJECT_EULER_INVALID_H

#include <string>

#include "Problem.h"

namespace project_euler {
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
