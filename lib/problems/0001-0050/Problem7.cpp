//===-- problems/Problem7.cpp -----------------------------------*- C++ -*-===//
//
// ProjectEuler.net solutions by Will Mitchell
//
// This file is distributed under the MIT License. See LICENSE for details.
//
//===----------------------------------------------------------------------===//
///
/// \class problems::Problem7
/// \brief 10001st prime
///
/// Question
/// --------
/// By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see
/// that the 6th prime is 13.
///
/// What is the 10 001st prime number?
///
/// Brute Force
/// -----------
/// Just the obvious loop using isPrime.
///
/// Faster
/// ------
///
//===----------------------------------------------------------------------===//
#include "Problem7.h"

#include <sstream>
using std::stringstream;
#include <string>
using std::string;

#include "number/Prime.h"

string problems::Problem7::answer() {
  if (!solved)
    solve();

  stringstream ss;

  ss << "The 10001st prime number is " << prime;

  return ss.str();
}

std::string problems::Problem7::description() const {
  return "Problem 7: 10001st prime";
}

void problems::Problem7::solve() {
  prime = bruteForce2(10001);
  solved = true;
}

unsigned problems::Problem7::bruteForce(const unsigned limit) const {
  unsigned count = 1;
  unsigned p = 2;

  for (unsigned i = 3; count < limit; i += 2) {
    if (number::isPrime(i)) {
      p = i;
      ++count;
    }
  }

  return p;
}

unsigned problems::Problem7::bruteForce2(const unsigned limit) const {
  unsigned count = 3;
  unsigned p = 5;

  for (unsigned i = 7; count < limit;) {
    if (number::isPrime(i)) {
      p = i;
      if (++count == limit)
        break;
    }
    i += 4;
    if (number::isPrime(i)) {
      p = i;
      ++count;
    }
    i += 2;
  }

  return p;
}

unsigned problems::Problem7::bruteForce3(const unsigned limit) const {
  unsigned count = 1;
  unsigned p = 2;
  auto sieve = number::primesAtMost(100u);

  for (unsigned i = 3; count < limit; i += 2) {
    if (number::isPrime(i, sieve)) {
      p = i;
      ++count;
    }
  }

  return p;
}

unsigned problems::Problem7::bruteForce4(const unsigned limit) const {
  auto sieve = number::primesAtMost(104744u);

  return sieve[limit - 1];
}
