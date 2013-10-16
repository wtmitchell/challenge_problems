//===-- problems/Problem9.cpp -----------------------------------*- C++ -*-===//
//
// ProjectEuler.net solutions by Will Mitchell
//
// This file is distributed under the MIT License. See LICENSE for details.
//
//===----------------------------------------------------------------------===//
///
/// \class problems::Problem9
/// \brief Special Pythagorean triplet
///
/// Question
/// --------
/// A Pythagorean triplet is a set of three natural numbers, a < b < c, for
///  which, a^2 + b^2 = c^2
///
/// For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.
///
/// There exists exactly one Pythagorean triplet for which a + b + c = 1000.
/// Find the product abc.
///
/// Analysis
/// --------
/// Recall that primitive Pythagorean triplets can be defined by positive
/// integers m > n, with a = m^2 - n^2, b = 2mn, c = m^2 + n^2.
///
/// Note: 1000 = 2^3 * 5^3
///
/// Therefore we need to consider the problem where the corresponding primitive
/// Pythagorean triplet sums to a divisor of 1000.
///
/// Observe
/// \f{eqnarray*}{
/// a + b + c &=& m^2 - n^2 + 2mn + m^2 + n^2\\
/// &=& 2m^2 + 2mn\\
/// &=& 2m(m + n)
/// \f}
/// and
/// \f{eqnarray*}{
/// abc &=& (m^2 - n^2)(2mn)(m^2 + n^2)\\
/// &=& (2m^3n - 2mn^3)(m^2 + n^2)\\
/// &=& 2m^5n + 2m^3n^3 - 2m^3n^3 - 2mn^5\\
/// &=& 2m^5n - 2mn^5\\
/// &=& 2mn(m^4 - n^4)
/// \f}
//===----------------------------------------------------------------------===//
#include "Problem9.h"

#include <cstring>
using std::strlen;
#include <sstream>
using std::stringstream;
#include <string>
using std::string;

string problems::Problem9::answer() {
  if (!solved)
    solve();

  stringstream ss;

  ss << "The product is " << product;

  return ss.str();
}

std::string problems::Problem9::description() const {
  return "Problem 9: Special Pythagorean triplet";
}

void problems::Problem9::solve() {
  product = 0;

  solved = true;
}
