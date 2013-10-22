//===-- number/Limits.h -----------------------------------------*- C++ -*-===//
//
// ProjectEuler.net solutions by Will Mitchell
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

#include <type_traits>

namespace number {
/// Maximum integer such that its square is representaible as the same type
template <typename T> T maxSqrt();
}

namespace number {
template <typename T> struct maxSqrtUnsigned {
  const static T value =
      (static_cast<T>(1) << sizeof(T) * 4) - static_cast<T>(1);
};

template <typename T> struct maxSqrtSigned {
  // Hopefully will break things quickly and obviously for this unsupported type
  const static T value = 0;
};

template <> struct maxSqrtSigned<short> {
  const static short value = 181;
};

template <> struct maxSqrtSigned<int> {
  const static int value = 46340;
};

template <> struct maxSqrtSigned<long> {
  const static long value = 3037000499l;
};

template <> struct maxSqrtSigned<long long> {
  const static long long value = 3037000499ll;
};

template <typename T> struct maxSqrtImpl {
  const static T value = std::is_unsigned<T>::value ? maxSqrtUnsigned<T>::value
                                                    : maxSqrtSigned<T>::value;
};

template <typename T> T maxSqrt() { return maxSqrtImpl<T>::value; }
}
#endif
