//===-- test/util/Divisor.cpp -----------------------------------*- C++ -*-===//
//
// Challenge Problem solutions by Will Mitchell
//
// This file is distributed under the MIT License. See LICENSE for details.
//
//===----------------------------------------------------------------------===//
#include <gtest/gtest.h>

#include <array>
using std::array;
#include <vector>
using std::vector;

#include "number/Divisor.h"
using number::divisors;
using number::divisorList;
using number::divisorListUnsorted;

TEST(Divisor, divisors) {
  // Divisors for the first 1000 numbers
  array<unsigned, 1000> dofn = {
      {1, 2, 2, 3, 2, 4, 2, 4, 3, 4, 2, 6, 2, 4, 4, 5, 2, 6, 2, 6, 4, 4, 2, 8,
       3, 4, 4, 6, 2, 8, 2, 6, 4, 4, 4, 9, 2, 4, 4, 8, 2, 8, 2, 6, 6, 4, 2, 10,
       3, 6, 4, 6, 2, 8, 4, 8, 4, 4, 2, 12, 2, 4, 6, 7, 4, 8, 2, 6, 4, 8, 2, 12,
       2, 4, 6, 6, 4, 8, 2, 10, 5, 4, 2, 12, 4, 4, 4, 8, 2, 12, 4, 6, 4, 4, 4,
       12, 2, 6, 6, 9, 2, 8, 2, 8, 8, 4, 2, 12, 2, 8, 4, 10, 2, 8, 4, 6, 6, 4,
       4, 16, 3, 4, 4, 6, 4, 12, 2, 8, 4, 8, 2, 12, 4, 4, 8, 8, 2, 8, 2, 12, 4,
       4, 4, 15, 4, 4, 6, 6, 2, 12, 2, 8, 6, 8, 4, 12, 2, 4, 4, 12, 4, 10, 2, 6,
       8, 4, 2, 16, 3, 8, 6, 6, 2, 8, 6, 10, 4, 4, 2, 18, 2, 8, 4, 8, 4, 8, 4,
       6, 8, 8, 2, 14, 2, 4, 8, 9, 2, 12, 2, 12, 4, 4, 4, 12, 4, 4, 6, 10, 4,
       16, 2, 6, 4, 4, 4, 16, 4, 4, 4, 12, 4, 8, 2, 12, 9, 4, 2, 12, 2, 8, 8, 8,
       2, 12, 4, 6, 4, 8, 2, 20, 2, 6, 6, 6, 6, 8, 4, 8, 4, 8, 2, 18, 4, 4, 8,
       9, 2, 8, 4, 12, 6, 4, 2, 16, 4, 8, 4, 6, 2, 16, 2, 10, 8, 4, 6, 12, 2, 4,
       6, 16, 2, 8, 2, 6, 8, 8, 4, 18, 3, 8, 4, 6, 2, 12, 4, 8, 8, 4, 4, 18, 4,
       4, 4, 10, 4, 12, 2, 12, 4, 8, 2, 16, 2, 4, 12, 6, 2, 8, 4, 14, 4, 8, 4,
       15, 6, 4, 4, 8, 4, 16, 2, 6, 6, 4, 4, 20, 2, 6, 4, 12, 4, 12, 4, 8, 8, 4,
       2, 12, 2, 12, 8, 12, 2, 8, 4, 6, 8, 4, 2, 24, 3, 4, 6, 12, 4, 8, 2, 10,
       6, 8, 4, 12, 2, 8, 8, 8, 4, 16, 2, 12, 4, 4, 2, 16, 8, 4, 6, 6, 2, 16, 4,
       12, 4, 4, 4, 18, 2, 4, 8, 15, 2, 8, 4, 6, 10, 8, 4, 16, 2, 8, 4, 6, 4,
       12, 4, 12, 4, 8, 2, 24, 2, 4, 6, 8, 6, 8, 4, 6, 8, 8, 2, 20, 2, 8, 8, 6,
       4, 8, 2, 16, 9, 8, 2, 12, 4, 4, 4, 14, 2, 18, 4, 6, 4, 4, 8, 16, 2, 4, 8,
       12, 2, 16, 2, 10, 8, 4, 2, 18, 4, 8, 4, 8, 4, 8, 6, 12, 6, 4, 2, 24, 4,
       4, 8, 9, 4, 12, 2, 8, 4, 12, 2, 12, 4, 8, 12, 10, 4, 8, 2, 12, 4, 4, 2,
       24, 4, 8, 6, 6, 2, 16, 4, 10, 8, 4, 4, 12, 4, 8, 4, 16, 2, 12, 2, 6, 12,
       4, 4, 20, 3, 8, 6, 12, 4, 8, 4, 8, 4, 4, 6, 24, 2, 4, 4, 12, 4, 16, 2, 6,
       6, 12, 4, 16, 4, 4, 8, 6, 2, 12, 4, 20, 8, 4, 2, 12, 4, 4, 10, 8, 2, 16,
       2, 12, 4, 8, 6, 21, 2, 6, 4, 12, 4, 8, 4, 8, 12, 4, 2, 18, 4, 8, 4, 10,
       2, 16, 8, 6, 4, 8, 2, 24, 2, 8, 6, 6, 6, 8, 2, 12, 8, 8, 4, 18, 2, 4, 8,
       16, 2, 8, 2, 12, 8, 4, 4, 20, 5, 4, 8, 6, 4, 24, 2, 8, 4, 4, 4, 12, 6, 8,
       6, 16, 2, 8, 2, 12, 8, 8, 2, 20, 4, 12, 8, 6, 2, 8, 4, 10, 6, 8, 2, 24,
       2, 4, 8, 8, 8, 12, 4, 6, 4, 8, 4, 24, 2, 4, 12, 9, 2, 8, 4, 16, 4, 8, 2,
       18, 4, 8, 4, 10, 4, 16, 2, 6, 12, 4, 4, 16, 4, 4, 4, 18, 2, 16, 4, 14, 8,
       4, 4, 12, 2, 8, 6, 8, 4, 16, 8, 6, 4, 4, 2, 30, 4, 6, 4, 6, 6, 12, 2, 16,
       7, 8, 4, 12, 2, 4, 12, 12, 4, 12, 2, 12, 8, 8, 2, 16, 4, 4, 6, 12, 4, 16,
       2, 10, 4, 8, 4, 24, 2, 4, 8, 16, 2, 8, 4, 6, 12, 4, 4, 18, 2, 16, 4, 6,
       2, 12, 6, 8, 8, 4, 4, 24, 4, 8, 8, 15, 4, 8, 2, 6, 4, 8, 4, 24, 4, 4, 8,
       6, 2, 16, 4, 18, 6, 4, 4, 12, 8, 8, 4, 8, 2, 20, 2, 12, 4, 8, 4, 20, 4,
       4, 12, 12, 2, 8, 2, 8, 12, 8, 2, 18, 2, 8, 4, 14, 6, 8, 4, 12, 8, 4, 2,
       32, 3, 4, 4, 6, 6, 12, 6, 10, 4, 12, 4, 12, 2, 8, 12, 8, 2, 16, 2, 12, 8,
       4, 2, 24, 4, 4, 6, 12, 4, 16, 4, 8, 6, 8, 8, 12, 2, 4, 4, 20, 2, 18, 2,
       12, 8, 4, 2, 16, 4, 8, 10, 6, 4, 8, 4, 16, 8, 4, 4, 27, 4, 8, 8, 8, 4, 8,
       2, 6, 6, 16, 2, 20, 4, 4, 8, 6, 4, 16, 2, 16, 4, 4, 4, 24, 6, 4, 6, 12,
       2, 16, 6, 6, 4, 4, 8, 24, 2, 8, 4, 12, 2, 8, 4, 10, 16, 8, 2, 12, 4, 12,
       4, 16, 2, 12, 4, 6, 8, 4, 4, 28, 3, 8, 6, 6, 4, 16, 2, 12, 8, 8, 2, 18,
       4, 4, 12, 10, 2, 8, 4, 18, 6, 4, 2, 16, 4, 8, 8, 12, 4, 24, 2, 12, 4, 8,
       4, 12, 2, 4, 8, 16}};

  for (auto i = 0u; i < 15; ++i)
    EXPECT_EQ(dofn[i], divisors(i + 1)) << " i = " << i;

  EXPECT_EQ(2, divisors(4051u));
  EXPECT_EQ(3, divisors(4051u * 4051u));
}

TEST(Divisor, divisorList) {
  vector<unsigned> expected;
  expected.push_back(1);
  expected.push_back(2);
  expected.push_back(3);
  expected.push_back(6);

  EXPECT_EQ(expected, divisorList(6u));

  expected.push_back(9);
  expected.push_back(18);

  EXPECT_EQ(expected, divisorList(18u));
}

TEST(Divisor, divisorListUnsorted) {
  vector<unsigned> expected;
  expected.push_back(1);
  expected.push_back(6);
  expected.push_back(2);
  expected.push_back(3);

  EXPECT_EQ(expected, divisorListUnsorted(6u));

  expected.clear();
  expected.push_back(1);
  expected.push_back(18);
  expected.push_back(2);
  expected.push_back(9);
  expected.push_back(3);
  expected.push_back(6);

  EXPECT_EQ(expected, divisorListUnsorted(18u));
}
