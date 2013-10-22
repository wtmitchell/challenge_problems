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

// Specialization for GMP Integers
namespace number {
template <> mpz_class isqrt<mpz_class>(const mpz_class n) {
  mpz_class result;
  mpz_sqrt(result.get_mpz_t(), n.get_mpz_t());
  return result;
}

// This is based on the simple binary search method in Hacker's Delight
// 2nd ed by Henry Warren Jr. Fig 11-3 p 284
// Adapted to work for arbitrary T.
template <typename T> T isqrt(const T n) {
  T a = static_cast<T>(1);
  T b = n / static_cast<T>(32) + static_cast<T>(8); // approximate initial guess

  // clamp b to the largest the sqrt could ever be (such that b * b can be
  // represented as type T)
  if (std::is_unsigned<T>::value) {
    if (b > (static_cast<T>(1) << sizeof(T) * 4) - static_cast<T>(1))
      b = (static_cast<T>(1) << sizeof(T) * 4) - static_cast<T>(1);
  } else {
    // Work for some reasonable values for the signed case.
    // TODO: Make this general
    switch (sizeof(T)) {
    case 1:       // 8-bit
      if (b > 11) // floor(sqrt(2^7 -1))
        b = 11;
      break;
    case 2: {      // 16-bit
      if (b > 181) // floor(sqrt(2^15 - 1))
        b = 181;
      break;
    }
    case 4: {        // 32-bit
      if (b > 46340) // floor(sqrt(2^31 - 1))
        b = 46340;
      break;
    }
    case 8: {             // 64-bit
      if (b > 3037000499) // floor(sqrt(2^63 - 1))
        b = 3037000499;
      break;
    }
    /*
  case 16: { // 128-bit
    if (b > 13043817825332782212) // floor(sqrt(2^127 - 1))
      b = 13043817825332782212;
    break;
  }
    */
    default:
      // Quickly and obviously break things since we haven't planned for this
      // situation
      b = 1;
    }
  }

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
