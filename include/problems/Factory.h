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

#include <functional>

typedef std::function<void(void)> Problem;

namespace problems {
namespace Factory {
Problem single_problem(unsigned int num);
}
}

#endif
