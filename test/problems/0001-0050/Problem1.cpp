#include <gtest/gtest.h>

#include "problems/0001-0050/Problem1.h"
using problems::Problem1;

TEST(Problem1, Basics) {

  Problem1 p1;

  EXPECT_EQ(1, p1.brute_force());
}
