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
///
/// Analysis
/// --------
/// Observe that for this case, we have a lot of redundancies. For instance,
/// one, two, ... ninety-nine will occur 10 total times. The word "and" will
/// occur 99 times per group of one hundred above 100, for a total of 99*8 times
/// Then "one hundred" occurs 100 times, "two hundred" occurs 100 times etc.
//===----------------------------------------------------------------------===//
#include "Problem17.h"

#include <sstream>
using std::stringstream;
#include <string>
using std::string;

#include "number/Miscellaneous.h"
using number::toEnglishString;
using number::toEnglishStringUnder1000;

string problems::Problem17::answer() {
  if (!solved)
    solve();

  stringstream ss;

  ss << "The number of letters used to write 1 to 1000 with British usage is "
     << count;

  return ss.str();
}

std::string problems::Problem17::description() const {
  return "Problem 17: Number letter counts";
}

void problems::Problem17::solve() {
  count = bruteForce3();
  solved = true;
}

unsigned long problems::Problem17::bruteForce(const unsigned long limit) const {
  unsigned long letters = 0;
  for (auto i = 1ul; i <= limit; ++i)
    letters += toEnglishString<unsigned long, false, true>(i).length();

  return letters;
}

unsigned long problems::Problem17::bruteForce2() const {
  unsigned long letters = 0;
  for (auto i = 1u; i <= 999; ++i)
    letters += toEnglishStringUnder1000<false, true>(i).length();

  letters += string("onethousand").length();

  return letters;
}

unsigned long problems::Problem17::bruteForce3() const {
  unsigned long letters = 0;

  // one, two, ... ninety-nine occur ten times total
  for (auto i = 1u; i <= 99; ++i)
    letters += toEnglishStringUnder1000<false>(i).length();
  letters *= 10;

  // All the "and" from British grammar
  letters += 3 * 99 * 9;

  // All the "one hundred", "two hundred", etc
  for (auto i = 1u; i <= 9; ++i)
    letters += 100 * toEnglishStringUnder1000<false>(i * 100).length();

  // Finally one thousand is an odd-ball
  letters += string("onethousand").length();

  return letters;
}
