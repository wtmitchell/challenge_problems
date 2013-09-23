//===-- util/Bits.h - Common bit manipulation routines ----------*- C++ -*-===//
//
//===----------------------------------------------------------------------===//
///
/// \file
/// \brief This file defines basic routines for bit manipulation
///
//===----------------------------------------------------------------------===//
#ifndef UTIL_BITS_H_INCLUDED
#define UTIL_BITS_H_INCLUDED

#include <cassert>

namespace util {
// This really should only exist for std::is_integral and std::is_unsigned
// but those require C++11
template <typename T> T pop_count(T in) {
  // TODO, use __builtin_popcount() when available (gcc/clang)
  // or __popcnt16(), __popcnt(), __popcnt64() (MSVC)
  T pop;

  for (pop = 0; in != 0; ++pop)
    in &= in - 1;

  return pop;
}

// snoob - same number of one bits
// (adapted from Fig 2-1 p 14 Hackers Delight 1st ed)
// This increments index to the next larger integer containing the same
// number of ones as index. When through all possible combinations, then
// increase the number of one bits set
// Uses N bits of in to express this
//
// This really should only exist for std::is_integral and std::is_unsigned
// but those require C++11
template <typename T> T snoob(T in, T N) {
  // Can't do this with in == 0, since would trigger division by zero
  assert(in != 0);

  T smallest = in & -in;
  T ripple = in + smallest;
  T ones = in ^ ripple;
  ones = (ones >> 2) / smallest;

  if (ripple >= (1 << N)) {
    // Add in another bit
    ones = (ones << 2) | 3;
    ripple = 0;
  }
  return ripple | ones;
}
}

#endif
