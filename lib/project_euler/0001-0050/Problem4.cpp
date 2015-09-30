//===-- project_euler/Problem4.cpp ------------------------------*- C++ -*-===//
//
// ProjectEuler.net solutions by Will Mitchell
//
// This file is distributed under the MIT License. See LICENSE for details.
//
//===----------------------------------------------------------------------===//
///
/// \class project_euler::Problem4
/// \brief Largest palindrome product
///
/// Question
/// --------
/// A palindromic number reads the same both ways. The largest palindrome made
/// from the product of two 2-digit numbers is 9009 = 91 * 99.
///
/// Find the largest palindrome made from the product of two 3-digit numbers.
///
//===----------------------------------------------------------------------===//
#include "Problem4.h"

#include <sstream>
using std::stringstream;
#include <string>
using std::string;

#include "number/Palindrome.h"
using number::isPalindrome;

string project_euler::Problem4::answer() {
  if (!solved)
    solve();

  stringstream ss;

  ss << "The largest palindrome that is a product of two 3-digit numbers is "
     << factor1 << " * " << factor2 << " = " << factor1 * factor2;

  return ss.str();
}

std::string project_euler::Problem4::description() const {
  return "Problem 4: Largest palindrome product";
}

void project_euler::Problem4::solve() {
  unsigned int max = 0;

  // Ranges are for 3-digit numbers. Extra i * i check is to ensure that getting
  // a product larger than what we already know about is even possible
  for (unsigned int i = 999; i >= 100 && i * i > max; --i) {
    for (unsigned int j = i; j >= 100 && i * j > max; --j) {
      if (isPalindrome(i * j)) {
        max = i * j;
        factor1 = i;
        factor2 = j;
      }
    }
  }

  solved = true;
}
