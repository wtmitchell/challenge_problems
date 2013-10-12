//===-- problems/Problem5.cpp -----------------------------------*- C++ -*-===//
//
// ProjectEuler.net solutions by Will Mitchell
//
// This file is distributed under the MIT License. See LICENSE for details.
//
//===----------------------------------------------------------------------===//
///
/// \class problems::Problem5
/// \brief Smallest multiple
///
/// Question
/// --------
/// A palindromic number reads the same both ways. The largest palindrome made
/// from the product of two 2-digit numbers is 9009 = 91 * 99.
///
/// Find the largest palindrome made from the product of two 3-digit numbers.
///
//===----------------------------------------------------------------------===//
#include "Problem5.h"

#include <sstream>
using std::stringstream;
#include <string>
using std::string;

#include <gmpxx.h>

string problems::Problem5::answer() {
  if (!solved)
    solve();

  stringstream ss;

  ss << "The smallest positive number that is evenly divisible by all of the "
        "numbers from 1 to 20 is " << lcm;

  return ss.str();
}

std::string problems::Problem5::description() const {
  return "Problem 5: Smallest multiple";
}

void problems::Problem5::solve() {
  lcm = 1;

  for (unsigned long i = 1ul; i <= 20ul; ++i)
    mpz_lcm_ui(lcm.get_mpz_t(), lcm.get_mpz_t(), i);

  solved = true;
}
