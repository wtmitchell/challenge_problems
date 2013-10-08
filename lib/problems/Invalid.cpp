//===-- problems/Invalid.cpp - An invalid problem ---------------*- C++ -*-===//
//
// ProjectEuler.net solutions by Will Mitchell
//
// This file is distributed under the MIT License. See LICENSE for details.
//
//===----------------------------------------------------------------------===//
//
//===----------------------------------------------------------------------===//
#include "problems/Invalid.h"

#include <string>

problems::Invalid::Invalid() {}
problems::Invalid::~Invalid() {}
std::string problems::Invalid::answer() { return "Invalid problem"; }
std::string problems::Invalid::description() const {
  return "Problem ??: Invalid";
}
void problems::Invalid::solve() {}
