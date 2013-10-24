//===-- number/Root.cpp -----------------------------------------*- C++ -*-===//
//
// ProjectEuler.net solutions by Will Mitchell
//
// This file is distributed under the MIT License. See LICENSE for details.
//
//===----------------------------------------------------------------------===//
///
//===----------------------------------------------------------------------===//
#include "number/Root.h"

#include <gmpxx.h>

// Specialization for GMP Integers
namespace number {
template <> mpz_class isqrt<mpz_class>(const mpz_class n) {
  mpz_class result;
  mpz_sqrt(result.get_mpz_t(), n.get_mpz_t());
  return result;
}
}
