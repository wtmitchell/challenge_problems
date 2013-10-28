#include <gtest/gtest.h>

#include <vector>
using std::vector;

#include "number/Divisor.h"
using number::divisors;
using number::divisorList;
using number::divisorListUnsorted;

TEST(Divisor, divisors) {
  EXPECT_EQ(4, divisors(6u));
  EXPECT_EQ(4, divisors(10u));
  EXPECT_EQ(5, divisors(16u));
  EXPECT_EQ(6, divisors(20u));
  EXPECT_EQ(8, divisors(30u));
  EXPECT_EQ(7, divisors(64u));
  EXPECT_EQ(12, divisors(72u));
  EXPECT_EQ(12, divisors(96u));
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
