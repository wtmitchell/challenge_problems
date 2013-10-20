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
/// Note: 1000 = 2^3 * 5^3 and 500 = 2^2 * 5^3
///
/// Therefore we need to consider the problem where the corresponding primitive
/// Pythagorean triplet sums to a divisor of 1000.
///
/// Therefore we need \f$2m(m + n) | 1000\f$ or \f$m(m + n) | 500\f$.
/// or \f$dm(m + n) = 500\f$. Let \f$d=2^u5^v\f$, \f$m=2^w5^x\f$ and
/// \f$m + n = 2^y5^z\f$ where u,v,w,x,y,z >= 0 and u+w+y = 2 and v+x+z = 3.
///
/// Solving for n
/// \f{eqnarray*}{
/// m + n &=& 2^y5^z\\
/// n &=& 2^y5^z - m\\
/// n &=& 2^y5^z - 2^w5^x\\
/// n &=& 2^w5^x(2^{y-w}5^{z-x} - 1)
/// \f}
/// With y >= w, z >= x and at least one of those inequalities is strict, which
/// follows because n is positive.
///
/// Therefore we are looking for u,v,w,x >= 0, y >= w, z >= x subject to
/// u+w+y = 2, v+x+z = 3.
///
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

#include <iostream>
using std::cout;
using std::endl;
#include <cmath>

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

  for (int u = 0; u <= 2; ++u) {
    for (int w = 0; u + w <= 2; ++w) {
      int y = 2 - u - w;
      if (y < w)
	continue;
      for (int v = 0; v <= 3; ++v) {
	for (int x = 0; v + x <= 3; ++x) {
	  int z = 3 - v - x;
	  if (z < x)
	    continue;
	  if (y == w && z == x)
	    continue;
	  cout << "Here with u = " << u << " v = " << v << " w = " << w << " x = " << x << " y = " << y << " z = " << z << "\n";
	  auto m = pow(2.0, w) * pow(5.0, x);
	  auto n = pow(2.0, y) * pow(5.0, z) - m;
	  cout << "m = " << m << " n = " << n << endl;
	}
      }
    }
  }

  solved = true;
}
