//===-- number/Primes.h -----------------------------------------*- C++ -*-===//
//
// Challenge Problem solutions by Will Mitchell
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
/// trial division. Assumes primes contains at least 2, 3, and 5
template <class T>
bool isPrime(const T candidate, const std::vector<T> &primes);

/// Returns a sorted vector of the prime divisors of the argument
template <class T> std::vector<T> primeDivisors(const T u);

/// Returns a vector of the prime divisors of the argument. Using a sorted list
/// of primes to accelerate the divisor checks. Assumes primes contains at least
/// 2, 3, and 5
template <class T>
std::vector<T> primeDivisors(const T u, const std::vector<T> &primes);

/// Returns a sorted vector of primes at most bound
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

  // Primes are +/- 1 mod 6, so we can skip 4 then 2
  for (T i = static_cast<T>(7); i * i <= candidate;) {
    if (candidate % i == 0)
      return false;
    i += static_cast<T>(4);
    if (candidate % i == 0)
      return false;
    i += static_cast<T>(2);
  }

  // If we haven't found a divisor so far, it must be prime
  return true;
}

template <class T>
bool number::isPrime(const T candidate, const std::vector<T> &primes) {
  // Prime numbers are positive and greater than 1
  if (candidate < static_cast<T>(2))
    return false;

  // Small enough that we can look up in the list
  if (candidate <= *primes.rbegin())
    return std::binary_search(primes.begin(), primes.end(), candidate);

  // Check if any of the known primes are divisors
  for (const auto i : primes) {
    if (candidate % i == static_cast<T>(0))
      return false;
  }

  // Resort to trial division
  T p = *primes.rbegin();

  // Get on +2 / +4 cycle
  if (p % static_cast<T>(6) == static_cast<T>(1))
    p += static_cast<T>(4);

  // Continue on +2 / +4 cycle
  while (p * p <= candidate) {
    if (candidate % p == static_cast<T>(0))
      return false;
    p += static_cast<T>(2);
    if (candidate % p == static_cast<T>(0))
      return false;
    p += static_cast<T>(4);
  }

  // If we haven't found a divisor so far, it must be prime
  return true;
}

// Create a convenience macro to prevent excess duplicate code in primeDivisors
/// \cond Suppress Doxygen warning
#define PROCESS_DIVISOR(i)                                                     \
  if (n % static_cast<T>(i) == static_cast<T>(0)) {                            \
    divisors.push_back(static_cast<T>(i));                                     \
    do                                                                         \
      n /= static_cast<T>(i);                                                  \
    while (n % static_cast<T>(i) == static_cast<T>(0));                        \
  }
/// \endcond

template <class T> std::vector<T> number::primeDivisors(const T number) {
  std::vector<T> divisors;
  T n = number;

  // Individually check the first few primes until we are past 6
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

  // The remaining part of n is prime
  if (n != static_cast<T>(1))
    divisors.push_back(n);

  return divisors;
}

template <class T>
std::vector<T> number::primeDivisors(const T number,
                                     const std::vector<T> &primes) {
  std::vector<T> divisors;
  T n = number;

  // Check the primes in the known list
  for (const auto i : primes) {
    PROCESS_DIVISOR(i);

    // Check if we found all the factors
    if (n == static_cast<T>(1))
      return divisors;
  }

  // Get on +2 / +4 cycle
  T p = *primes.rbegin();

  if (p % static_cast<T>(6) == static_cast<T>(1))
    p += static_cast<T>(4);

  // Primes are +/- 1 mod 6, so we can skip 2 then 4
  while (p * p <= n) {
    PROCESS_DIVISOR(p);
    p += static_cast<T>(2);
    PROCESS_DIVISOR(p);
    p += static_cast<T>(4);
  }

  // The remaining part of n is prime
  if (n != static_cast<T>(1))
    divisors.push_back(n);

  return divisors;
}

// Limit the scope of our macro
#undef PROCESS_DIVISOR

// Uses the Sieve of Eratosthenes
template <class T> std::vector<T> number::primesAtMost(const T bound) {
  // sieve holds a list of the odd integers starting at 3. Eventually a true
  // represent the number corresponding to that index is prime
  std::vector<bool> sieve((bound - 1) / 2);
  sieve.flip(); // Set all bits to true

  // Need only check to square root of bound since any composite greater than
  // the square root and less than bound must have one of its prime factors
  // less than the square root
  // Since we are only storing odds, index i corresponds to number 2*i + 3
  // and (2*i + 3)*(2*i + 3) = 4*i*(i + 3) + 9 represents the square root check
  for (std::vector<bool>::size_type i = 0, p = 2 * i + 3, pSquared = p * p;
       static_cast<T>(pSquared) < bound; p = 2 * i + 3, pSquared = p * p) {
    // Sift out the multiples of p
    // Advancing by p each time is equivalent to adding 2p, which leads to the
    // next odd multiple
    // Start at the index of p*p since any composite less than p*p which has p
    // as a factor also has a smaller prime as a factor and it would be sieved
    // by that prime.
    for (auto j = (pSquared - 3) / 2, e = sieve.size(); j < e; j += p)
      sieve[j] = false;

    // Find the next prime
    while (!sieve[++i])
      ;
  }


  // Implementation inspired by "From Mathematics to Generic Programming"
  // by Stepanov and Rose, pp 23-28
  //
  // Empirically this seems to be a little slower than the above.
  // My conjecture why is that despite the above calculating p explicitly
  // each time, it is only done for primes. Whereas this implementation
  // calculates p incrementally, it is done for all odd integers, not
  // just primes.
  //
  /*
  // Need to only check to square root of bound
  for (std::vector<bool>::size_type i = 0, iSquared = 3, p = 3;
       iSquared < bound;) {
    if (sieve[i]) {
      // Index i corresponds to the prime p, sift out multiples of it
      // starting at its square
      for (auto j = iSquared, e = sieve.size(); j < e; j += p)
	sieve[j] = false;
    }
    ++i;
    iSquared += p;
    p += 2;
    iSquared += p;
  }
  */

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
