#include <gtest/gtest.h>

#include <gmpxx.h>

#include "number/Miscellaneous.h"
using number::sumOfDigits;

TEST(Miscellaneous, sumOfDigits) {
  EXPECT_EQ(2, sumOfDigits(11u));
  EXPECT_EQ(3, sumOfDigits(111u));
  EXPECT_EQ(4, sumOfDigits(1111u));
  EXPECT_EQ(5, sumOfDigits(11111u));

  EXPECT_EQ(3, sumOfDigits(12u));
  EXPECT_EQ(6, sumOfDigits(123u));
  EXPECT_EQ(10, sumOfDigits(1234u));
  EXPECT_EQ(15, sumOfDigits(12345u));

  EXPECT_EQ(2, sumOfDigits(mpz_class("11")));
  EXPECT_EQ(90, sumOfDigits(mpz_class("123456789123456789")));
}
