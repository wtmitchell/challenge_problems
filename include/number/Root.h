//===-- number/Root.h -------------------------------------------*- C++ -*-===//
//
// ProjectEuler.net solutions by Will Mitchell
//
// This file is distributed under the MIT License. See LICENSE for details.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// \brief Contains functions relating to roots of numbers
///
//===----------------------------------------------------------------------===//
#ifndef NUMBER_ROOT_H_INCLUDED
#define NUMBER_ROOT_H_INCLUDED

#include <cmath>

namespace number {
/// Integer Square Root
template <class T> T isqrt(const T n);
}

template <class T> T number::isqrt(const T n) {
  return static_cast<T>(std::sqrt(n));
}

#endif
