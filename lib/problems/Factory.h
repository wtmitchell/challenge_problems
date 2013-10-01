//===-- problem/Factory.h - Factory to create problem instances--*- C++ -*-===//
//
//===----------------------------------------------------------------------===//
///
/// \file
/// \brief Provides a factory to create problem instances
///
//===----------------------------------------------------------------------===//
#ifndef FACTORY_H
#define FACTORY_H

#include <functional>

typedef std::function<void(void)> problem;

namespace problem {
namespace Factory {
problem single_problem(unsigned int num);
}
}

#endif
