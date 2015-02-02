//===-- project_euler/Invalid.cpp -------------------------------*- C++ -*-===//
//
// Challenge Problem solutions by Will Mitchell
//
// This file is distributed under the MIT License. See LICENSE for details.
//
//===----------------------------------------------------------------------===//
#include "project_euler/Invalid.h"

#include <string>

project_euler::Invalid::Invalid() {}
project_euler::Invalid::~Invalid() {}
std::string project_euler::Invalid::answer() { return "Invalid problem"; }
std::string project_euler::Invalid::description() const {
  return "Problem ??: Invalid";
}
void project_euler::Invalid::solve() {}
