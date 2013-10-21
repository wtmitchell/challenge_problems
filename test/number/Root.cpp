#include <gtest/gtest.h>

#include <vector>
using std::vector;

#include "number/Root.h"
using number::isqrt;

#include <gmpxx.h>

TEST(Root, isqrt) {
  EXPECT_EQ(2, isqrt(8));
  EXPECT_EQ(3, isqrt(9));
  EXPECT_EQ(3, isqrt(10));
  EXPECT_EQ(3u, isqrt(15u));
  EXPECT_EQ(4u, isqrt(16u));
  EXPECT_EQ(4u, isqrt(17u));

  // Near the size limit of 32 bits unsigned
  EXPECT_EQ(65534u, isqrt(4294836224u));
  EXPECT_EQ(65535u, isqrt(4294836225u));
  EXPECT_EQ(65535u, isqrt(4294836226u));

  EXPECT_EQ(65535u, isqrt(4294967295u));
  EXPECT_EQ(65536u, isqrt(4294967296u));

  // Near the size limit of 64 bits unsigned
  // EXPECT_EQ(4294967294ul, isqrt(18446744065119617024ul));
  EXPECT_EQ(4294967295ul, isqrt(18446744065119617025ul));
  EXPECT_EQ(4294967295ul, isqrt(18446744065119617026ul));

  // 2^32 - 1 is the  sqrt of 2^64 - 1
  // EXPECT_EQ(4294967295ul , isqrt(18446744073709551615ul));

  // Near the size limit of 128 bit unsigned
  // EXPECT_EQ(18446744073709551616ull,
  // isqrt(340282366920938463463374607431768211456ull));

  mpz_class test("12345678901234567890123456789012345678901234567890");
  mpz_class testsq = test * test;
  EXPECT_EQ(test - 1, isqrt(mpz_class(testsq - 1)));
  EXPECT_EQ(test, isqrt(mpz_class(testsq)));
  EXPECT_EQ(test, isqrt(mpz_class(testsq + 1)));
  EXPECT_EQ(test, isqrt(mpz_class(testsq + 2)));
  EXPECT_EQ(test, isqrt(mpz_class(testsq + 3)));
  EXPECT_EQ(test, isqrt(mpz_class(testsq + 4)));
}
