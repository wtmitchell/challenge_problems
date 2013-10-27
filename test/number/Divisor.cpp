#include <gtest/gtest.h>

#include <vector>
using std::vector;

#include "number/Divisor.h"
using number::divisorList;
using number::divisorListUnsorted;

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
