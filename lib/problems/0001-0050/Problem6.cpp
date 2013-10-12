//===-- problems/Problem6.cpp -----------------------------------*- C++ -*-===//
//
// ProjectEuler.net solutions by Will Mitchell
//
// This file is distributed under the MIT License. See LICENSE for details.
//
//===----------------------------------------------------------------------===//
///
/// \class problems::Problem6
/// \brief Sum square difference
///
/// Question
/// --------
/// The sum of the squares of the first ten natural numbers is,
///  \f[1^2 + 2^2 + ... + 10^2 = 385 \f]
///
/// The square of the sum of the first ten natural numbers is,
/// \f[(1 + 2 + ... + 10)^22 = 55^2 = 3025\f]
///
/// Hence the difference between the sum of the squares of the first ten natural
/// numbers and the square of the sum is 3025 − 385 = 2640.
///
/// Find the difference between the sum of the squares of the first one hundred
/// natural numbers and the square of the sum.
///
/// Brute Force
/// -----------
/// Just the obvious loop.
///
/// Faster
/// ------
/// Solving analytically
/// \f{eqnarray*}{
/// \left(\Sigma_{j = 1}^n j \right)^2 - \Sigma_{i = 1}^n i^2
/// &=& \left(\frac{n(n+1)}{2}\right)^2 - \frac{n(n + 1)(2n + 1)}{6}\\
/// &=& \frac{n^2(n+1)^2}{4} - \frac{n(n+1)(2n+1)}{6}\\
/// &=& \frac{3n^2(n+1)^2 - 2n(n+1)(2n+1)}{12}\\
/// &=& \frac{n(n+1)\bigl(3n(n+1) - 2(2n+1)\bigr)}{12}\\
/// &=& \frac{(n(n+1)\bigl(3n^2 + 3n - 4n - 2\bigr)}{12}\\
/// &=& \frac{(n^2+n)\bigl(3n^2 - n - 2)\bigr)}{12}\\
/// &=& \frac{3n^4 - n^3 - 2n^2 + 3n^3 - n^2 - 2n}{12}\\
/// &=& \frac{3n^4 + 2n^3 - 3n^2  - 2n}{12}\\
/// &=& \frac{n(n(n(3n + 2) - 3)  - 2)}{12}\\
/// \f}
/// Note the last line is applying Horner's Method.
//===----------------------------------------------------------------------===//
#include "Problem6.h"

#include <sstream>
using std::stringstream;
#include <string>
using std::string;

string problems::Problem6::answer() {
  if (!solved)
    solve();

  stringstream ss;

  ss << "The difference between the sum of squares and the square of the sum "
        "of the first 100 natural numbers is  " << difference;

  return ss.str();
}

std::string problems::Problem6::description() const {
  return "Problem 6: Sum square difference";
}

void problems::Problem6::solve() {
  difference = faster(100);
  solved = true;
}

unsigned problems::Problem6::bruteForce(const unsigned limit) const {
  unsigned sum_squares = 0;
  unsigned square_sum = 0;

  for (unsigned i = 0; i <= limit; ++i) {
    sum_squares += i * i;
    square_sum += i;
  }
  square_sum *= square_sum;

  return square_sum - sum_squares;
}

unsigned problems::Problem6::faster(const unsigned limit) const {
  return (limit * (limit * (limit * (3 * limit + 2) - 3) - 2)) / 12;
}
