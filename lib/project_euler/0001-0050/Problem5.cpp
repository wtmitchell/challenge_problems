//===-- project_euler/Problem5.cpp ------------------------------*- C++ -*-===//
//
// ProjectEuler.net solutions by Will Mitchell
//
// This file is distributed under the MIT License. See LICENSE for details.
//
//===----------------------------------------------------------------------===//
///
/// \class project_euler::Problem5
/// \brief Smallest multiple
///
/// Question
/// --------
/// 2520 is the smallest number that can be divided by each of the numbers from
/// 1 to 10 without any remainder.
///
/// What is the smallest positive number that is evenly divisible by all of the
/// numbers from 1 to 20?
///
//===----------------------------------------------------------------------===//
#include "Problem5.h"

#include <sstream>
using std::stringstream;
#include <string>
using std::string;

#include <gmpxx.h>

string project_euler::Problem5::answer() {
  if (!solved)
    solve();

  stringstream ss;

  ss << "The smallest positive number that is evenly divisible by all of the "
        "numbers from 1 to 20 is "
     << lcm;

  return ss.str();
}

std::string project_euler::Problem5::description() const {
  return "Problem 5: Smallest multiple";
}

void project_euler::Problem5::solve() {
  lcm = 1;

  for (unsigned long i = 1ul; i <= 20ul; ++i)
    mpz_lcm_ui(lcm.get_mpz_t(), lcm.get_mpz_t(), i);

  solved = true;
}
