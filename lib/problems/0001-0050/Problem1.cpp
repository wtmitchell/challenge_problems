//===-- problems/Problem1.cpp - An invalid problem --------------*- C++ -*-===//
//
// ProjectEuler.net solutions by Will Mitchell
//
// This file is distributed under the MIT License. See LICENSE for details.
//
//===----------------------------------------------------------------------===//
//
/* Problem 1
 *
 * If we list all the natural numbers below 10 that are multiples of 3 or 5, we
 * get 3, 5, 6 and 9. The sum of these multiples is 23.
 *
 * Find the sum of all the multiples of 3 or 5 below 1000.
 */
//===----------------------------------------------------------------------===//
#include "Problem1.h"

#include <sstream>
using std::stringstream;
#include <string>
using std::string;

problems::Problem1::Problem1() : sum(0), solved(false) {}
problems::Problem1::~Problem1() {}

string problems::Problem1::answer() {
  if (!solved) solve();

  stringstream ss;

  ss << "Foo" << sum;

  return ss.str();
}

void problems::Problem1::solve() { sum = brute_force(); }

int problems::Problem1::brute_force() {
  int s = 0;
  for (int i = 0; i < 1000; ++i) {
    if ((i % 3 == 0) || (i % 5 == 0)) {
      s += i;
    }
  }
  return s;
}
