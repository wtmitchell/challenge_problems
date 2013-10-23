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
/// integers m > n > 0, where gcd(m,n) = 1, and exactly one of m or n is even,
/// then a = m^2 - n^2, b = 2mn, c = m^2 + n^2.
///
/// Therefore if (a,b,c) is a primitive triple, we are then looking for a triple
/// satisfying
/// \f[
/// d(a + b + c) = s
/// \f]
/// with s = 1000 in this case. Observe
/// \f{eqnarray*}{
/// a + b + c &=& m^2 - n^2 + 2mn + m^2 + n^2\\
/// &=& 2m^2 + 2mn\\
/// &=& 2m(m + n)
/// \f}
///
/// So we are looking for appropriate m and n such that
/// \f[
/// 2dm(m + n) = s
/// \f]
///
/// From the above equation we know that s is even, \f$d|s\f$, and \f$m|s\f$.
///
/// Solving for n:
/// \f{eqnarray*}{
/// 2dm(m + n) &=& s\\
/// m + n &=& \frac{s}{2dm}\\
/// n &=& \frac{s}{2dm} - m
/// \f}
/// Since \f$n > 0\f$, so is the above, leading to
/// \f{eqnarray*}{
/// 0 &<& \frac{s}{2dm} - m\\
/// m &<& \frac{s}{2dm}\\
/// m^2 &<& \frac{s}{2d}\\
/// m &<& \sqrt{\frac{s}{2d}}
/// \f}
///
/// Therefore we have the following restrictions:
/// \f[
/// 0 < n < m < \sqrt{\frac{s}{2d}}
/// \f]
/// and divisibility requirements:
/// \f[
/// 2|s \qquad d|\frac{s}{2} \qquad m | \frac{s}{2d}
/// \f]
///
/// So to solve we will go through possible values of d, then m and n. We can
/// stop as soon as we find the first d that works, relying on the problem to
/// be correct that the triple is unique. At that point we can calculate the
/// product as
///
/// \f{eqnarray*}{
/// abcd^3 &=& (m^2 - n^2)(2mn)(m^2 + n^2)d^3\\
/// &=& (2m^3n - 2mn^3)(m^2 + n^2)d^3\\
/// &=& (2m^5n + 2m^3n^3 - 2m^3n^3 - 2mn^5)d^3\\
/// &=& (2m^5n - 2mn^5)d^3\\
/// &=& 2mnd^3(m^4 - n^4)
/// \f}
/// or just work backwards to a, b, and c, and multiply them together.
///
//===----------------------------------------------------------------------===//
#include "Problem9.h"

#include <cstring>
using std::strlen;
#include <sstream>
using std::stringstream;
#include <string>
using std::string;

#include <iostream>
using std::cout;
using std::endl;
#include <cmath>

#include "number/Divisor.h"

string problems::Problem9::answer() {
  if (!solved)
    solve();

  stringstream ss;

  ss << "The product is " << product << " from the triple (" << a << ", " << b << ", " << c << ")";

  return ss.str();
}

std::string problems::Problem9::description() const {
  return "Problem 9: Special Pythagorean triplet";
}

void problems::Problem9::solve() {
  product = bruteForce(1000);
  solved = true;
}

unsigned problems::Problem9::bruteForce(const unsigned sum) {
  // WLOG, assume a < b
  // By the triangle inequality we know that i is at most sum/3
  // and must start at at least 3 since the smallest triple is (3,4,5)
  for (unsigned i = 3; i < sum/3; ++i) {
    const auto isq = i * i;
    // j can't be more than half of the remaining sum
    for (unsigned j = i + 1, e = (sum - i) / 2; j <= e; ++j) {
      const auto k = sum - i - j;

      if (isq + j * j == k * k) {
	a = i;
	b = j;
	c = k;
	return i * j * k;
      }
    }
  }
  return 0;
}

unsigned problems::Problem9::faster(const unsigned sum) {
  const auto sdiv2 = sum / 2;
  const auto divisors = number::divisors(sdiv2);

  for (auto d = divisors.begin(), de = --divisors.end(); d != de; ++d) {
    const auto sdiv2d = sdiv2 / *d;
    for (auto m = ++divisors.begin(); *m * *m < sdiv2d; ++m) {
      if (sdiv2d % *m != 0)
	continue;

      const auto n = sdiv2d / *m - *m;

      if (n <= 0 || n >= *m)
	continue;

      const auto msq = *m * *m;
      const auto nsq = n * n;
      const auto mn = *m * n;

      a = msq - nsq;
      b = 2 * mn;
      c = msq + nsq;

      return a * b * c * *d * *d * *d;
    }
  }

  return 0;
}

