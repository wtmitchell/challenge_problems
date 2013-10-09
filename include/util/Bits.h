//===-- util/Bits.h ---------------------------------------------*- C++ -*-===//
//
// ProjectEuler.net solutions by Will Mitchell
//
// This file is distributed under the MIT License. See LICENSE for details.
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
#include <type_traits>

namespace util {
// This only exists for types that are std::is_integral and std::is_unsigned
/// Population Count of the parameter
template <typename T>
typename std::enable_if<std::is_integral<T>::value &&std::is_unsigned<T>::value,
                        T>::type
pop_count(T in) {
  // TODO, use __builtin_popcount() when available (gcc/clang)
  // or __popcnt16(), __popcnt(), __popcnt64() (MSVC)
  T pop;

  for (pop = 0; in != 0; ++pop)
    in &= in - 1;

  return pop;
}

///  Same Number of One Bits - restricted width
// (adapted from Fig 2-1 p 14 Hackers Delight 1st ed)
// This increments in to the next larger integer containing the same
// number of ones as in. When through all possible combinations, then
// increase the number of one bits set
// Uses N bits of in to express this
//
// There are two versions here. The one argument version assumes you want
// the whole width of the type. The two argument version allows you to
// specify using only some of the bits
//
// This only exists for types that are std::is_integral and std::is_unsigned
template <typename T>
typename std::enable_if<std::is_integral<T>::value &&std::is_unsigned<T>::value,
                        T>::type
snoob(T in) {
  // Can't do this with in == 0, since would trigger division by zero
  assert(in != 0);

  T smallest = in & -in;
  T ripple = in + smallest;
  T ones = in ^ ripple;
  ones = (ones >> 2) / smallest;
  return ripple | ones;
}

/// Same Number of One Bits - full width of type
template <typename T>
typename std::enable_if<std::is_integral<T>::value &&std::is_unsigned<T>::value,
                        T>::type
snoob(T in, T N) {
  // Can't do this with in == 0, since would trigger division by zero
  assert(in != 0);

  T smallest = in & -in;
  T ripple = in + smallest;
  T ones = in ^ ripple;
  ones = (ones >> 2) / smallest;

  if (ripple >= (static_cast<T>(1) << N)) {
    // Add in another bit
    ones = (ones << 2) | 3;
    ripple = 0;
  }
  return ripple | ones;
}
}

#endif
