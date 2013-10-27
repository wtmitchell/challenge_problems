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
/// Returns a vector of the divisors of the argument. Returned vector will be
/// sorted in increasing order.
template <class T> std::vector<T> divisorList(const T n);

/// Returns a vector of the divisors of the argument. Returned vector will not
/// be sorted
template <class T> std::vector<T> divisorListUnsorted(const T n);
}

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
