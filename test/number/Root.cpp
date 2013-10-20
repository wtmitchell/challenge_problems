#include <gtest/gtest.h>

#include <vector>
using std::vector;

#include "number/Root.h"
using number::isqrt;

TEST(Root, isqrt) {
  EXPECT_EQ(3, isqrt(9));
}
