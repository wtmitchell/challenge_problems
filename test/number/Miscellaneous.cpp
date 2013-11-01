#include <gtest/gtest.h>

#include <gmpxx.h>

#include "number/Miscellaneous.h"
using number::sumOfDigits;
using number::toEnglishString;

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

TEST(Miscellaneous, toEnglishString) {

  // Limit of our group names
  // 10^36
  auto tenE36 = mpz_class("1000000000000000000000000000000000000");
  EXPECT_EQ("Error: Number too big. Exceeds 10^36 - 1.",
            toEnglishString(tenE36));
  EXPECT_EQ(mpz_class("999999999999999999999999999999999999"),
	    mpz_class(tenE36 - 1));
  EXPECT_EQ("nine hundred ninety-nine decillion nine hundred ninety-nine "
            "nonillion nine hundred ninety-nine octillion nine hundred "
            "ninety-nine septillion nine hundred ninety-nine sextillion nine "
            "hundred ninety-nine quintillion nine hundred ninety-nine "
            "quadrillion nine hundred ninety-nine trillion nine hundred "
            "ninety-nine billion nine hundred ninety-nine million nine hundred "
            "ninety-nine thousand nine hundred ninety-nine",
            toEnglishString(mpz_class(tenE36 - 1)));
}
