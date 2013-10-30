//===-- number/Miscellaneous.h ----------------------------------*- C++ -*-===//
//
// ProjectEuler.net solutions by Will Mitchell
//
// This file is distributed under the MIT License. See LICENSE for details.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// \brief Contains functions about numbers that don't fit elsewhere
///
//===----------------------------------------------------------------------===//
#ifndef NUMBER_MISCELLANEOUS_H_INCLUDED
#define NUMBER_MISCELLANEOUS_H_INCLUDED

#include <cassert>
#include <gmpxx.h>

namespace number {
/// Sums the number digit by digit.
template <typename T> T sumOfDigits(const T n, const unsigned radix = 10);
}

// Skip Doxygen for implementation details
/// \cond Suppress Doxygen warning
namespace number{
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

  template <typename T> T sumOfDigits(const T number, const unsigned radix) {
    T sum = static_cast<T>(0);
    T n = number;

    assert(n >= 0);

    while (n > 0) {
      sum += n % radix;
      n /= radix;
    }
    return sum;
  }
}
/// \endcond
#endif
