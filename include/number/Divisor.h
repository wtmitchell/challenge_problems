//===-- number/Divisor.h ----------------------------------------*- C++ -*-===//
//
// ProjectEuler.net solutions by Will Mitchell
//
// This file is distributed under the MIT License. See LICENSE for details.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// \brief Contains functions relating to divisors
///
//===----------------------------------------------------------------------===//
#ifndef NUMBER_DIVISOR_H_INCLUDED
#define NUMBER_DIVISOR_H_INCLUDED

#include <vector>

namespace number {
/// Returns the number of divisors of the argument
template <typename T> T divisors(const T n);

/// Returns a vector of the divisors of the argument. Returned vector will be
/// sorted in increasing order.
template <class T> std::vector<T> divisorList(const T n);

/// Returns a vector of the divisors of the argument. Returned vector will not
/// be sorted
template <class T> std::vector<T> divisorListUnsorted(const T n);
}

// Convenience macro used in divisors
/// \cond Suppress Doxygen warning
#define PROCESS_DIVISOR(i)                                                     \
  if (n % static_cast<T>(i) == static_cast<T>(0)) {                            \
    T multiplicity = static_cast<T>(0);                                        \
    do {                                                                       \
      n /= static_cast<T>(i);                                                  \
      ++multiplicity;                                                          \
    } while (n % static_cast<T>(i) == static_cast<T>(0));                      \
    count *= multiplicity + 1;                                                 \
  }
/// \endcond

template <typename T> T number::divisors(const T number) {
  // Early exit for nonsense values
  if (number <= static_cast<T>(0))
    return static_cast<T>(0);

  T n = number;
  T count = static_cast<T>(1);

  PROCESS_DIVISOR(2);
  PROCESS_DIVISOR(3);
  PROCESS_DIVISOR(5);

  // Primes are +/- 1 mod 6, so we can skip 4 then 2
  for (T i = static_cast<T>(7); i * i <= n;) {
    PROCESS_DIVISOR(i);
    i += static_cast<T>(4);
    PROCESS_DIVISOR(i);
    i += static_cast<T>(2);
  }

  // The remaining part may still be prime, if so it may be present or not in a
  // divisor. This won't affect numbers where the largest prime has multiplicity
  // greater than one since they would be caught in the above loop.
  if (n != static_cast<T>(1))
    count *= 2;

  return count;
}

#undef PROCESS_DIVISOR

template <class T> std::vector<T> number::divisorList(const T n) {
  // Initially will contain divisors at most the sqrt
  std::vector<T> divisors;
  // Will contain divisors greater than the sqrt
  std::vector<T> big_divisors;

  // Find the divisors
  for (auto i = static_cast<T>(1); i * i <= n; ++i) {
    if (n % i == 0) {
      // Divisors come in pairs
      divisors.push_back(i);
      big_divisors.push_back(n / i);
    }
  }

  // Add the big_divisors to divisors
  divisors.reserve(divisors.size() * 2);
  for (auto i = big_divisors.rbegin(), e = big_divisors.rend(); i != e; ++i)
    divisors.push_back(*i);

  return divisors;
}

template <class T> std::vector<T> number::divisorListUnsorted(const T n) {
  std::vector<T> divisors;

  // Find the divisors
  for (auto i = static_cast<T>(1); i * i <= n; ++i) {
    if (n % i == 0) {
      // Divisors come in pairs
      divisors.push_back(i);
      divisors.push_back(n / i);
    }
  }

  return divisors;
}

#endif
