//===-- problems/Problem1.cpp -----------------------------------*- C++ -*-===//
//
// ProjectEuler.net solutions by Will Mitchell
//
// This file is distributed under the MIT License. See LICENSE for details.
//
//===----------------------------------------------------------------------===//
///
/// \class problems::Problem1
/// \brief Multiples of 3 and 5
///
/// Question
/// --------
/// If we list all the natural numbers below 10 that are multiples of 3 or 5,
/// we get 3, 5, 6 and 9. The sum of these multiples is 23.
///
/// Find the sum of all the multiples of 3 or 5 below 1000.
///
/// Brute Force
/// -----------
/// Simple loop through for multiples of 3 or 5.
///
/// Faster
/// ------
/// Note that there are n/d numbers at most n that are divisible by d.
/// Thus we can sum up the divisors of 3 and 5. However, we must use the
/// principle of inclusion-exclusion to deal with over counting.
///
/// Hence:
/// \f{eqnarray*}{
/// sum &=& \sum_{i=0}^{\lfloor n/3\rfloor} 3i
///         + \sum_{j=0}^{\lfloor n/5\rfloor} 5j
///         - \sum_{k=0}^{\lfloor n/15\rfloor} 15k\\
/// &=& 3\sum_{i=0}^{\lfloor n/3\rfloor} i + 5 \sum_{j=0}^{\lfloor n/5\rfloor} j
///     - 15\sum_{k=0}^{\lfloor n/15\rfloor} k\\
/// &=& 3\frac{\lfloor\frac{n}{3}\rfloor(\lfloor\frac{n}{3}\rfloor+1)}{2}
///     + 5\frac{\lfloor\frac{n}{5}\rfloor(\lfloor\frac{n}{5}\rfloor+1)}{2}
///     - 15\frac{\lfloor\frac{n}{15}\rfloor(\lfloor\frac{n}{15}\rfloor+1)}{2}\\
/// \f}
/// Note that in the problem below 1000 implies we want to have n = 999, or
/// simply substitute in n-1.
//===----------------------------------------------------------------------===//
#include "Problem1.h"

#include <sstream>
using std::stringstream;
#include <string>
using std::string;

string problems::Problem1::answer() {
  if (!solved)
    solve();

  stringstream ss;

  ss << "The sum of all multiples of 3 or 5 below 1000 is " << sum;

  return ss.str();
}

std::string problems::Problem1::description() const {
  return "Problem 1: Multiples of 3 and 5";
}

void problems::Problem1::solve() {
  sum = faster(1000);
  solved = true;
}

int problems::Problem1::brute_force(const int limit) {
  int s = 0;
  for (int i = 0; i < limit; ++i) {
    if ((i % 3 == 0) || (i % 5 == 0))
      s += i;
  }
  return s;
}

int problems::Problem1::faster(const int limit) {
  return 3 * ((limit - 1) / 3 * ((limit - 1) / 3 + 1)) / 2 +
         5 * ((limit - 1) / 5 * ((limit - 1) / 5 + 1)) / 2 -
         15 * ((limit - 1) / 15 * ((limit - 1) / 15 + 1)) / 2;
}
