#include <gtest/gtest.h>

#include <vector>
using std::vector;

#include "number/Divisor.h"
using number::divisors;
using number::divisorsUnsorted;

TEST(Divisor, divisor) {
  vector<unsigned> expected;
  expected.push_back(1);
  expected.push_back(2);
  expected.push_back(3);
  expected.push_back(6);

  EXPECT_EQ(expected, divisors(6u));

  expected.push_back(9);
  expected.push_back(18);

  EXPECT_EQ(expected, divisors(18u));
}

TEST(Divisor, divisorUnsorted) {
  vector<unsigned> expected;
  expected.push_back(1);
  expected.push_back(6);
  expected.push_back(2);
  expected.push_back(3);

  EXPECT_EQ(expected, divisorsUnsorted(6u));

  expected.clear();
  expected.push_back(1);
  expected.push_back(18);
  expected.push_back(2);
  expected.push_back(9);
  expected.push_back(3);
  expected.push_back(6);

  EXPECT_EQ(expected, divisorsUnsorted(18u));
}
