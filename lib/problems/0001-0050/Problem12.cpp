//===-- problems/Problem12.cpp ----------------------------------*- C++ -*-===//
//
// ProjectEuler.net solutions by Will Mitchell
//
// This file is distributed under the MIT License. See LICENSE for details.
//
//===----------------------------------------------------------------------===//
///
/// \class problems::Problem12
/// \brief Highly divisible triangular number
///
/// Question
/// --------
/// The sequence of triangle numbers is generated by adding the natural numbers.
/// So the 7th triangle number would be 1 + 2 + 3 + 4 + 5 + 6 + 7 = 28. The
/// first ten terms would be:
///
/// 1, 3, 6, 10, 15, 21, 28, 36, 45, 55, ...
///
/// Let us list the factors of the first seven triangle numbers:
///
///     1: 1
///     3: 1,3
///     6: 1,2,3,6
///    10: 1,2,5,10
///    15: 1,3,5,15
///    21: 1,3,7,21
///    28: 1,2,4,7,14,28
///
/// We can see that 28 is the first triangle number to have over five divisors.
///
/// What is the value of the first triangle number to have over five hundred
/// divisors?
///
/// Analysis
/// --------
/// The nth triangular number, being the sum of the first n integers, is just
/// \f[ T_n = \frac{n(n+1)}{2} \f]
///
/// Since \f$ gcd(n, n+1) = 1 \f$, either \f$ gcd(n/2, n+1) = 1 \f$ or \f$
/// gcd(n, (n+1)/2) = 1\f$, depending on the parity of n.
///
/// Therefore we can reduce the computation for the divisors of \f$ T_n \f$:
/// \f[
/// D(T_n) = D\left(\frac{n(n+1)}{2}\right) = D(n/2) \cdot D(n+1) \text{ or }
/// D(n) \cdot D((n+1)/2)
/// \f]
//===----------------------------------------------------------------------===//
#include "Problem12.h"

#include <sstream>
using std::stringstream;
#include <string>
using std::string;

#include <iostream>
using std::cout;
using std::endl;

#include "number/Divisor.h"

string problems::Problem12::answer() {
  if (!solved)
    solve();

  stringstream ss;

  ss << "The " << n << "th triangular number is the first triangular number "
                       "with over 500 divisors. It is " << value;

  return ss.str();
}

std::string problems::Problem12::description() const {
  return "Problem 12: Highly divisible triangular number";
}

void problems::Problem12::solve() {
  value = bruteForce(500ull);
  solved = true;
}

unsigned long long
problems::Problem12::bruteForce(const unsigned long long limit) const {
  for (auto i = 1ull, j = 1ull;; i += ++j) {
    const auto divisors = number::divisors(i);

    if (divisors.size() >= limit) {
      n = j;
      return i;
    }
  }
}