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
#include <type_traits>
#include <gmpxx.h>

#include "Limits.h"

namespace number {
/// Greatest integer at most square root of argument
template <typename T> T isqrt(const T n);
}

namespace number {
// Specialization for GMP Integers
/// \cond Suppress Doxygen warning
template <> mpz_class isqrt<mpz_class>(const mpz_class n);
/// \endcond

// This is based on the simple binary search method in Hacker's Delight
// 2nd ed by Henry Warren Jr. Fig 11-3 p 284
// Adapted to work for arbitrary T.
template <typename T> T isqrt(const T n) {
  T a = static_cast<T>(1);
  T b = n / static_cast<T>(32) + static_cast<T>(8); // approximate initial guess

  // clamp b to the largest the sqrt could ever be
  if (b > number::maxSqrt<T>())
    b = number::maxSqrt<T>();

  do {
    const T m = a + (b - a) / static_cast<T>(2);
    if (m * m > n)
      b = m - 1;
    else
      a = m + 1;
  } while (b >= a);

  return a - static_cast<T>(1);
}
}
#endif
