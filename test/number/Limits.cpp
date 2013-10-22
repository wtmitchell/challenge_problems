#include <gtest/gtest.h>

#include "number/Limits.h"
using number::maxSqrt;

TEST(Limits, maxSqrt) {
  // First test the unsigned types
  if (sizeof(unsigned short) == 2 && sizeof(unsigned int) == 4 &&
      sizeof(unsigned long) == 8 && sizeof(unsigned long long) == 8) {
    // LP64
    EXPECT_EQ((1u << 4) - 1, maxSqrt<unsigned char>());
    EXPECT_EQ((1u << 8) - 1, maxSqrt<unsigned short>());
    EXPECT_EQ((1u << 16) - 1, maxSqrt<unsigned int>());
    EXPECT_EQ((1ul << 32) - 1, maxSqrt<unsigned long>());
    EXPECT_EQ((1ull << 32) - 1, maxSqrt<unsigned long long>());
  } else {
    ASSERT_TRUE(false) << "Unknown data model for unsigned types";
  }

  // Now test the signed types
  if (sizeof(short) == 2 && sizeof(int) == 4 && sizeof(long) == 8 &&
      sizeof(long long) == 8) {
    // LP64
    // floor(sqrt(2^15 -1))
    EXPECT_EQ(181, maxSqrt<short>());
    // floor(sqrt(2^31 -1))
    EXPECT_EQ(46340, maxSqrt<int>());
    // floor(sqrt(2^63 -1))
    EXPECT_EQ(3037000499, maxSqrt<long>());
    EXPECT_EQ(3037000499, maxSqrt<long long>());
  } else {
    ASSERT_TRUE(false) << "Unknown data model for signed types";
  }
}
