//===-- problems/Problem16.cpp ----------------------------------*- C++ -*-===//
//
// ProjectEuler.net solutions by Will Mitchell
//
// This file is distributed under the MIT License. See LICENSE for details.
//
//===----------------------------------------------------------------------===//
///
/// \class problems::Problem16
/// \brief Power digit sum
///
/// Question
/// --------
/// 2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.
///
/// What is the sum of the digits of the number 2^1000?
//===----------------------------------------------------------------------===//
#include "Problem16.h"

#include <sstream>
using std::stringstream;
#include <string>
using std::string;

#include "number/Miscellaneous.h"
using number::sumOfDigits;

string problems::Problem16::answer() {
  if (!solved)
    solve();

  stringstream ss;

  ss << "The sum of the digits of 2^1000 is " << sum;

  return ss.str();
}

std::string problems::Problem16::description() const {
  return "Problem 16: Power digit sum";
}

void problems::Problem16::solve() {
  mpz_class foo(0);
  mpz_ui_pow_ui(foo.get_mpz_t(), 2, 1000);
  sum = sumOfDigits(foo).get_ui();
  solved = true;
}
