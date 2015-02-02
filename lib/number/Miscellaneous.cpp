//===-- number/Miscellaneous.cpp --------------------------------*- C++ -*-===//
//
// Challenge Problem solutions by Will Mitchell
//
// This file is distributed under the MIT License. See LICENSE for details.
//
//===----------------------------------------------------------------------===//
#include "number/Miscellaneous.h"

#include <gmpxx.h>

// Specialization for GMP Integers
namespace number {
template <>
mpz_class sumOfDigits(const mpz_class number, const unsigned radix) {
  assert(radix <= 10);
  assert(number >= 0);
  auto digits = number.get_str(static_cast<int>(radix));

  mpz_class sum(0);
  for (const auto i : digits)
    sum += i - '0';

  return sum;
}
}
