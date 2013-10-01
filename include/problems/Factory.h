//===-- problem/Factory.h - Factory to create problem instances--*- C++ -*-===//
//
//===----------------------------------------------------------------------===//
///
/// \file
/// \brief This file defines basic routines for bit manipulation
///
//===----------------------------------------------------------------------===//
#ifndef FACTORY_H
#define FACTORY_H

#include <functional>

typedef std::function<void(void)> problem;

namespace problems {
namespace Factory {
problem single_problem(unsigned int num);
}
}

#endif
