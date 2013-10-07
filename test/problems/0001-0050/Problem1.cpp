#include <gtest/gtest.h>

#include "problems/0001-0050/Problem1.h"
using problems::Problem1;

TEST(Problem1, Basics) {

  Problem1 p1;

  EXPECT_EQ(23, p1.brute_force(10));
  EXPECT_EQ(233168, p1.brute_force(1000));
  EXPECT_EQ(23, p1.faster(10));
  EXPECT_EQ(233168, p1.faster(1000));
}
