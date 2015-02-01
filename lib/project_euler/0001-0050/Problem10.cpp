//===-- project_euler/Problem10.cpp -----------------------------*- C++ -*-===//
//
// ProjectEuler.net solutions by Will Mitchell
//
// This file is distributed under the MIT License. See LICENSE for details.
//
//===----------------------------------------------------------------------===//
///
/// \class project_euler::Problem10
/// \brief Summation of primes
///
/// Question
/// --------
/// The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
///
/// Find the sum of all the primes below two million.
///
//===----------------------------------------------------------------------===//
#include "Problem10.h"

#include <algorithm>
#include <sstream>
using std::stringstream;
#include <string>
using std::string;

#include <iostream>
using std::cout;
using std::endl;

#include "number/Prime.h"

string project_euler::Problem10::answer() {
  if (!solved)
    solve();

  stringstream ss;

  ss << "The sum of all primes below 2 million is " << sum;

  return ss.str();
}

std::string project_euler::Problem10::description() const {
  return "Problem 10: Summation of primes";
}

void project_euler::Problem10::solve() {
  sum = sieveOfEratosthenes(2000000ull);
  solved = true;
}

unsigned long long
project_euler::Problem10::sieveOfEratosthenes(const unsigned long long limit) const {
  auto primes = number::primesAtMost(limit);
  return std::accumulate(primes.begin(), primes.end(), 0ull);
}
