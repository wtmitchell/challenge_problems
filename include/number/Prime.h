//===-- number/Primes.h ------------------------------ ----------*- C++ -*-===//
//
// ProjectEuler.net solutions by Will Mitchell
//
// This file is distributed under the MIT License. See LICENSE for details.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// \brief Contains functions relating to prime numbers
///
//===----------------------------------------------------------------------===//
#ifndef NUMBER_PRIMES_H_INCLUDED
#define NUMBER_PRIMES_H_INCLUDED

#include <algorithm>
#include <vector>

namespace number {
/// Determines whether the number is prime by pure trial division
template <class T> bool isPrime(const T candidate);

/// Determines whether a number is prime by using a sorted list of primes, then
/// trial division
template <class T> bool isPrime(const T candidate, const std::vector<T> primes);

/// Returns a vector of the prime divisors of the argument
template <class T> std::vector<T> primeDivisors(const T u);

/// Returns a vector of primes at most bound
template <class T> std::vector<T> primesAtMost(const T bound);
}

template <class T> bool number::isPrime(const T candidate) {
  // Primes are not negative, 0 or 1
  if (candidate < static_cast<T>(2))
    return false;

  // Individually check the first few primes until we are past 6
  if (candidate == static_cast<T>(2) || candidate == static_cast<T>(3) ||
      candidate == static_cast<T>(5))
    return true;
  if (candidate % static_cast<T>(2) == static_cast<T>(0) ||
      candidate % static_cast<T>(3) == static_cast<T>(0) ||
      candidate % static_cast<T>(5) == static_cast<T>(0))
    return false;

  // Primes are +/- 1 mod 6, so we can skip 2 then 4
  for (T i = static_cast<T>(5); i * i <= candidate;) {
    i += static_cast<T>(2);
    if (candidate % i == 0)
      return false;
    i += static_cast<T>(4);
    if (candidate % i == 0)
      return false;
  }

  // If we haven't found a divisor so far, it must be prime
  return true;
}

template <class T>
bool number::isPrime(const T candidate, const std::vector<T> primes) {
  // Prime numbers are positive and greater than 1
  if (candidate < static_cast<T>(2))
    return false;

  // Small enough that we can look up
  if (candidate < *primes.rbegin())
    return std::binary_search(primes.begin(), primes.end(), candidate);

  // Naively decide by trial division
  return number::isPrime<T>(candidate);
}

template <class T> std::vector<T> number::primeDivisors(const T number) {
  std::vector<T> divisors;
  T n = number;

// Create a convenience macro to prevent excess duplicate code
#define PROCESS(i)                                                             \
  if (n % static_cast<T>(i) == static_cast<T>(0)) {                            \
    divisors.push_back(static_cast<T>(i));                                     \
    do                                                                         \
      n /= static_cast<T>(i);                                                  \
    while (n % static_cast<T>(i) == static_cast<T>(0));                        \
  }

  // Individually check the first few primes until we are past 6
  PROCESS(2);
  PROCESS(3);
  PROCESS(5);

  // Primes are +/- 1 mod 6, so we can skip 2 then 4
  for (T i = static_cast<T>(5); i * i < number;) {
    i += static_cast<T>(2);
    PROCESS(i);
    i += static_cast<T>(4);
    PROCESS(i);
  }

// Limit the scope of our macro
#undef PROCESS

  if (n != static_cast<T>(1)) {
    // The remaining part of n is prime
    divisors.push_back(n);
  }

  return divisors;
}

// Uses the Sieve of Eratosthenes
template <class T> std::vector<T> number::primesAtMost(const T bound) {
  // sieve holds a list of the odd integers starting at 3 eventually a true
  // represent the number corresponding to that index is prime
  std::vector<bool> sieve((bound - 1) / 2);
  sieve.flip(); // Set all bits to true

  // Need only check to square root of bound since any composite greater than
  // the square root and less than bound must have one of its prime factors
  // less than the square root
  // Since we are only storing odds, index i corresponds to number 2*i + 3
  // and (2*i + 3)*(2*i + 3) = 4*i*(i + 3) + 9 represents the square root check
  for (std::vector<bool>::size_type i = 0;
       static_cast<T>(4 * i * (i + 3) + 9) < bound;) {
    // Find the corresponding prime
    const auto p = 2 * i + 3;

    // Sift out the multiples of p
    // Advancing by p each time is equivalent to adding 2p, which leads to the
    // next odd multiple
    for (auto j = i + p; j <= bound / 2; j += p)
      sieve[j] = false;

    // Find the next prime
    while (!sieve[++i])
      ;
  }

  // Convert sieve into integers
  std::vector<T> primes;
  primes.push_back(static_cast<T>(2));

  for (std::vector<bool>::size_type i = 0, e = sieve.size(); i < e; ++i) {
    if (sieve[i])
      primes.push_back(static_cast<T>(2 * i + 3));
  }

  return primes;
}

#endif
