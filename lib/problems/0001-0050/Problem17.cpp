//===-- problems/Problem17.cpp ----------------------------------*- C++ -*-===//
//
// ProjectEuler.net solutions by Will Mitchell
//
// This file is distributed under the MIT License. See LICENSE for details.
//
//===----------------------------------------------------------------------===//
///
/// \class problems::Problem17
/// \brief Number letter counts
///
/// Question
/// --------
/// If the numbers 1 to 5 are written out in words: one, two, three, four, five,
/// then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.
///
/// If all the numbers from 1 to 1000 (one thousand) inclusive were written out
/// in words, how many letters would be used?
///
/// NOTE: Do not count spaces or hyphens. For example, 342 (three hundred and
/// forty-two) contains 23 letters and 115 (one hundred and fifteen) contains 20
/// letters. The use of "and" when writing out numbers is in compliance with
/// British usage.
//===----------------------------------------------------------------------===//
#include "Problem17.h"

#include <sstream>
using std::stringstream;
#include <string>
using std::string;

#include "number/Miscellaneous.h"
using number::sumOfDigits;

string problems::Problem17::answer() {
  if (!solved)
    solve();

  stringstream ss;

  ss << "The number of letters used to write 1 to 1000 with British usage is  "
     << count;

  return ss.str();
}

std::string problems::Problem17::description() const {
  return "Problem 17: Number letter counts";
}

void problems::Problem17::solve() {
  count = bruteForce(1000);
  solved = true;
}

unsigned long problems::Problem17::bruteForce(const unsigned long limit) const {
  return 0;
}
