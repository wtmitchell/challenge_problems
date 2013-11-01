//===-- number/Miscellaneous.h ----------------------------------*- C++ -*-===//
//
// ProjectEuler.net solutions by Will Mitchell
//
// This file is distributed under the MIT License. See LICENSE for details.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// \brief Contains functions about numbers that don't fit elsewhere
///
//===----------------------------------------------------------------------===//
#ifndef NUMBER_MISCELLANEOUS_H_INCLUDED
#define NUMBER_MISCELLANEOUS_H_INCLUDED

#include <array>
#include <cassert>
#include <string>
#include <vector>
#include <gmpxx.h>

namespace number {
/// Sums the number digit by digit.
template <typename T> T sumOfDigits(const T n, const unsigned radix = 10);

/// \brief Converts the argument to an English string, using the short scale.
/// British English uses the word "and" in places where it is not used in
/// American English.
template <typename T, bool UseSpacesAndHyphens = true,
          bool UseBritishGrammar = false>
std::string toEnglishString(const T number);
}

// Skip Doxygen for implementation details
/// \cond Suppress Doxygen warning
namespace number{
  template <typename T> T sumOfDigits(const T number, const unsigned radix) {
    T sum = static_cast<T>(0);
    T n = number;

    assert(n >= 0);

    while (n > 0) {
      sum += n % radix;
      n /= radix;
    }
    return sum;
  }

  template <bool UseSpacesAndHyphens, bool UseAnd>
  std::string toEnglishStringSingleGroup(const unsigned group) {
    // Idiomatic names through nineteen
    const std::array<std::string, 20> smallNames = {
      { "zero",    "one",     "two",       "three",    "four",
        "five",    "six",     "seven",     "eight",    "nine",
        "ten",     "eleven",  "twelve",    "thirteen", "fourteen",
        "fifteen", "sixteen", "seventeen", "eighteen", "nineteen" }
    };
    // Names for groups of ten past above idiomatic names
    const std::array<std::string, 10> smallGroupNames = {
      { "",      "",      "twenty",  "thirty", "forty",
        "fifty", "sixty", "seventy", "eighty", "ninety" }
    };

    const unsigned hundred = group / 100;
    const unsigned remainder = group % 100;

    std::string result = "";

    // Handle hundreds digit
    if (hundred != 0) {
      result += smallNames[hundred];
      if (UseSpacesAndHyphens)
	result += " hundred ";
      else
	result += "hundred";
    }
    // Insert "and" if needed
    if (UseAnd && hundred != 0 && remainder != 0) {
      if (UseSpacesAndHyphens)
	result += " and ";
      else
	result += "and";
    }
    // Handle remaining digits
    if (remainder != 0) {
      if (remainder < 20) {
	// Uses idiomatic name
	result += smallNames[remainder];
      }
      else {
	// Uses tens-single format
	const unsigned tens = remainder / 10;
	const unsigned single = remainder % 10;

	result += smallGroupNames[tens];
	if (single != 0) {
	  if (UseSpacesAndHyphens)
	    result += "-";
	  result += smallNames[single];
	}
      }
    }

    return result;
  }

  // This function assumes each element of groups is at most 999 and in reverse
  // group ordering. You should use toEnglishString instead of this directly
  template <bool UseSpacesAndHyphens, bool UseBritishGrammar>
  std::string toEnglishStringByGroups(const std::vector<unsigned> &groups) {
    // Group names in third powers of ten, ie 10^0, 10^3, 10^6, etc...
    // for the short scale
    // List from http://en.wikipedia.org/wiki/Names_of_large_numbers
    // where there is agreement between American Heritage Dictionary 4th ed and
    // Oxford English Dictionary 2nd and New editions.
    const std::array<std::string, 12> groupNames = {
      { "",           "thousand",    "million",     "billion",
        "trillion",   "quadrillion", "quintillion", "sextillion",
        "septillion", "octillion",   "nonillion",   "decillion" }
    };

    // Verify we have enough group names
    if (groups.size() > 12)
      return "Error: Number too big. Exceeds 10^36 - 1.";

    std::string result = "";
    // Process each group
    // Last group handled separately because of British Grammar
    for (auto i = groups.size() - 1; i > 0; --i) {
      // We only add something for non-zero
      if (groups[i] == 0)
	continue;

      result += toEnglishStringSingleGroup<UseSpacesAndHyphens, false>(groups[i]);
      if (UseSpacesAndHyphens)
	result += " " + groupNames[i] + " ";
      else
	result += groupNames[i];
    }
    if (groups[0] != 0) {
      if (UseBritishGrammar) {
	if (groups[0] < 100 && result != "") {
	  // Need to force "and" here
	  if (UseSpacesAndHyphens)
	    result += " and ";
	  else
	    result += "and";
	}
	result += toEnglishStringSingleGroup<UseSpacesAndHyphens, true>(groups[0]);
      }
      else {
	// American Grammar
	result += toEnglishStringSingleGroup<UseSpacesAndHyphens, false>(groups[0]);
      }
    }

    return result;
  }

  // Note this class is used here to we can partially specialize based on
  // the type of T.
  template <typename T, bool UseSpacesAndHyphens, bool UseBritishGrammar>
  struct toEnglishStringImpl {
    static std::string convert(const T number) {
      // Break the number up into groups of three
      std::vector<unsigned> groups;

      T n = number;
      while (n > 0) {
        groups.push_back(static_cast<unsigned>(n % 1000));
        n /= 1000;
      }

      // Process each group
      return toEnglishStringByGroups<UseSpacesAndHyphens, UseBritishGrammar>(
          groups);
    }
  };

  template <bool UseSpacesAndHyphens, bool UseBritishGrammar>
  struct toEnglishStringImpl<mpz_class, UseSpacesAndHyphens,
                             UseBritishGrammar> {
    static std::string convert(const mpz_class number) {
      // Break the number up into groups of three
      std::vector<unsigned> groups;

      mpz_class n = number;
      while (n > 0) {
        groups.push_back(static_cast<unsigned>(mpz_class(n % 1000).get_ui()));
        n /= 1000;
      }

      // Process each group
      return toEnglishStringByGroups<UseSpacesAndHyphens, UseBritishGrammar>(
          groups);
    }
  };

  template <typename T, bool UseSpacesAndHyphens, bool UseBritishGrammar>
  std::string toEnglishString(const T number) {
    return toEnglishStringImpl<T, UseSpacesAndHyphens, UseBritishGrammar>::convert(number);
  }
}
/// \endcond
#endif
