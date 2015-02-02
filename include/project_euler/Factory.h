//===-- project_euler/Factory.h ----------------------------------*- C++ -*-===//
//
// Challenge Problem solutions by Will Mitchell
//
// This file is distributed under the MIT License. See LICENSE for details.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// \brief Defines a factory for Problem objects
///
//===----------------------------------------------------------------------===//
#ifndef PROJECT_EULER_FACTORY_H
#define PROJECT_EULER_FACTORY_H

#include <memory>
#include <vector>
#include "Problem.h"

namespace project_euler {
namespace Factory {
/// Returns an instance of the requested problem
std::unique_ptr<Problem> create(unsigned long num);
/// Returns a list of all problems
std::vector<unsigned long> list();
}
}

#endif
