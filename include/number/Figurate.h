//===-- number/Figurate.h ---------------------------------------*- C++ -*-===//
//
// ProjectEuler.net solutions by Will Mitchell
//
// This file is distributed under the MIT License. See LICENSE for details.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// \brief Contains functions relating to figurate numbers
///
//===----------------------------------------------------------------------===//
#ifndef NUMBER_FIGURATE_H_INCLUDED
#define NUMBER_FIGURATE_H_INCLUDED

#include "Root.h"

namespace number {
/// Determines whether the parameter is a square number
template <class T> bool isSquare(const T candidate);
}

template <class T> bool number::isSquare(const T candidate) {
  // Attempt to filter via mod 16. The squares mod 16 are 0, 1, 4, and 9.
  // This allows for 25% of possible numbers to pass through to the more
  // costly isqrt check.
  // Can be verified in Python via set([(i * i) % 16 for i in range(16)])
  // Moving to mod 32 allows 7/32 = 21.8% to pass through,
  // so likely isn't worth it.
  auto ultimateHexDigit = candidate % 16;

  if (ultimateHexDigit == 0) {
    // If 0 mod 16, the hex digit preceding the 0 must also be one of 0,1,4,9
    // This can be verified in Python via
    // set([floor((i * i) / 16) % 16 for i in range(256) if (i*i)%16 == 0])
    auto penultimateHexDigit = (candidate / 16) % 16;
    if (penultimateHexDigit != 0 && penultimateHexDigit != 1 &&
        penultimateHexDigit != 4 && penultimateHexDigit != 9)
      return false;
  } else if (ultimateHexDigit == 4) {
    // If 4 mod 16, the hex digit preceding the 4 must be even.
    // This can be verified in Python via
    // set([floor((i * i) / 16) % 16 for i in range(256) if (i*i)%16 == 4])
    auto penultimateHexDigit = (candidate / 16) % 16;
    if (penultimateHexDigit % 2 != 0)
      return false;
  } else if (ultimateHexDigit != 1 && ultimateHexDigit != 9) {
    return false;
  }

  const auto isqrt = number::isqrt(candidate);

  return isqrt * isqrt == candidate;
}

#endif
