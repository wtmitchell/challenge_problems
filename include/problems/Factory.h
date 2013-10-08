//===-- problem/Factory.h - Factory to create problem instances--*- C++ -*-===//
//
// ProjectEuler.net solutions by Will Mitchell
//
// This file is distributed under the MIT License. See LICENSE for details.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// \brief Defines a factory for Problem objects
///
//===----------------------------------------------------------------------===//
#ifndef FACTORY_H
#define FACTORY_H

#include <memory>
#include "Problem.h"

namespace problems {
namespace Factory {
std::unique_ptr<Problem> create(unsigned long num);
}
}

#endif
