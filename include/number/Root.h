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

namespace number {
/// Greatest integer at most square root of argument
template <typename T> T isqrt(const T n);
}

namespace number {
template <> mpz_class isqrt<mpz_class>(const mpz_class n) {
  mpz_class result;
  mpz_sqrt(result.get_mpz_t(), n.get_mpz_t());
  return result;
}
}

namespace number {
template <typename T>
T isqrt(const T n) {
  // This is a poor way to calculate in general. It suffers from accuracy
  // errors when number can't be completely represented as a double
  return static_cast<T>(std::floor(std::sqrt(n)));
}
}
#endif
