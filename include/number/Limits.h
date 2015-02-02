//===-- number/Limits.h -----------------------------------------*- C++ -*-===//
//
// Challenge Problem solutions by Will Mitchell
//
// This file is distributed under the MIT License. See LICENSE for details.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// \brief Contains functions relating to limits of types.
///
//===----------------------------------------------------------------------===//
#ifndef NUMBER_LIMITS_H_INCLUDED
#define NUMBER_LIMITS_H_INCLUDED

#include <cstddef>
#include <type_traits>

namespace number {
/// Maximum integer such that its square is representaible as the same type
template <typename T> T maxSqrt();
}

// Skip Doxygen for implementation details
/// \cond Suppress Doxygen warning
namespace number {
template <typename T> struct maxSqrtUnsigned {
  const static T value =
      static_cast<T>((static_cast<T>(1) << sizeof(T) * 4) - static_cast<T>(1));
};

template <std::size_t size> struct maxSqrtSignedImpl {
  // Hopefully zero will be wrong enough to immediately make the program fail
  enum {
    value = 0
  };
};

// 8-bit
template <> struct maxSqrtSignedImpl<1> {
  // floor(sqrt(2^7 - 1))
  enum {
    value = 11
  };
};

// 16-bit
template <> struct maxSqrtSignedImpl<2> {
  // floor(sqrt(2^15 - 1))
  enum {
    value = 181
  };
};

// 32-bit
template <> struct maxSqrtSignedImpl<4> {
  // floor(sqrt(2^32 - 1))
  enum {
    value = 46340
  };
};

// 64-bit
template <> struct maxSqrtSignedImpl<8> {
  // floor(sqrt(2^63 - 1))
  enum {
    value = 3037000499
  };
};

// 128-bit
template <> struct maxSqrtSignedImpl<16> {
  // floor(sqrt(2^127 - 1))
  enum {
    value = 13043817825332782212u
  };
};

template <typename T> struct maxSqrtSigned {
  const static T value = maxSqrtSignedImpl<sizeof(T)>::value;
};

template <typename T> struct maxSqrtImpl {
  const static T value = std::is_unsigned<T>::value ? maxSqrtUnsigned<T>::value
                                                    : maxSqrtSigned<T>::value;
};

template <typename T> T maxSqrt() { return maxSqrtImpl<T>::value; }
}
/// \endcond
#endif
