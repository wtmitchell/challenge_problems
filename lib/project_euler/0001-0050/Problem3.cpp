//===-- project_euler/Problem3.cpp ------------------------------*- C++ -*-===//
//
// ProjectEuler.net solutions by Will Mitchell
//
// This file is distributed under the MIT License. See LICENSE for details.
//
//===----------------------------------------------------------------------===//
///
/// \class project_euler::Problem3
/// \brief Largest prime factor
///
/// Question
/// --------
/// The prime factors of 13195 are 5, 7, 13 and 29.
///
/// What is the largest prime factor of the number 600851475143 ?
///
//===----------------------------------------------------------------------===//
#include "Problem3.h"

#include <sstream>
using std::stringstream;
#include <string>
using std::string;

#include "number/Prime.h"

string project_euler::Problem3::answer() {
  if (!solved)
    solve();

  stringstream ss;

  ss << "The largest prime factor of the number 600851475143 is " << factor;

  return ss.str();
}

std::string project_euler::Problem3::description() const {
  return "Problem 3: Largest prime factor";
}

void project_euler::Problem3::solve() {
  factor = divisor_list(600851475143ull);
  solved = true;
}

unsigned long long
project_euler::Problem3::divisor_list(const unsigned long long number) const {
  auto divisors = number::primeDivisors(number);

  return *divisors.rbegin();
}
