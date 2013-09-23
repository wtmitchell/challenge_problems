#include <gtest/gtest.h>

#include "util/Bits.h"
using util::pop_count;

TEST(BitsPopCount, Basics) {
  EXPECT_EQ(1, pop_count(1));
}

