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
  EXPECT_EQ("nine hundred ninety-nine decillion nine hundred ninety-nine "
            "nonillion nine hundred ninety-nine octillion nine hundred "
            "ninety-nine septillion nine hundred ninety-nine sextillion nine "
            "hundred ninety-nine quintillion nine hundred ninety-nine "
            "quadrillion nine hundred ninety-nine trillion nine hundred "
            "ninety-nine billion nine hundred ninety-nine million nine hundred "
            "ninety-nine thousand nine hundred ninety-nine",
            toEnglishString(mpz_class(tenE36 - 1)));
  EXPECT_EQ("nine hundred ninety-nine decillion nine hundred ninety-nine "
            "nonillion nine hundred ninety-nine octillion nine hundred "
            "ninety-nine septillion nine hundred ninety-nine sextillion nine "
            "hundred ninety-nine quintillion nine hundred ninety-nine "
            "quadrillion nine hundred ninety-nine trillion nine hundred "
            "ninety-nine billion nine hundred ninety-nine million nine hundred "
            "ninety-nine thousand nine hundred and ninety-nine",
            (toEnglishString<mpz_class, true, true>(mpz_class(tenE36 - 1))));
  EXPECT_EQ("ninehundredninetyninedecillionninehundredninetyninenonillionninehu"
            "ndredninetynineoctillionninehundredninetynineseptillionninehundred"
            "ninetyninesextillionninehundredninetyninequintillionninehundrednin"
            "etyninequadrillionninehundredninetyninetrillionninehundredninetyni"
            "nebillionninehundredninetyninemillionninehundredninetyninethousand"
            "ninehundredninetynine",
            (toEnglishString<mpz_class, false, false>(mpz_class(tenE36 - 1))));
  EXPECT_EQ("ninehundredninetyninedecillionninehundredninetyninenonillionninehu"
            "ndredninetynineoctillionninehundredninetynineseptillionninehundred"
            "ninetyninesextillionninehundredninetyninequintillionninehundrednin"
            "etyninequadrillionninehundredninetyninetrillionninehundredninetyni"
            "nebillionninehundredninetyninemillionninehundredninetyninethousand"
            "ninehundredandninetynine",
            (toEnglishString<mpz_class, false, true>(mpz_class(tenE36 - 1))));

  // Test each of the group names
  EXPECT_EQ("one decillion ",
            (toEnglishString<mpz_class, true, false>(
                mpz_class("1000000000000000000000000000000000"))));
  EXPECT_EQ("one decillion ", (toEnglishString<mpz_class, true, true>(mpz_class(
                                  "1000000000000000000000000000000000"))));
  EXPECT_EQ("onedecillion", (toEnglishString<mpz_class, false, false>(mpz_class(
                                "1000000000000000000000000000000000"))));
  EXPECT_EQ("onedecillion", (toEnglishString<mpz_class, false, true>(mpz_class(
                                "1000000000000000000000000000000000"))));

  EXPECT_EQ("one nonillion ",
            (toEnglishString<mpz_class, true, false>(
                mpz_class("1000000000000000000000000000000"))));
  EXPECT_EQ("one nonillion ", (toEnglishString<mpz_class, true, true>(mpz_class(
                                  "1000000000000000000000000000000"))));
  EXPECT_EQ("onenonillion", (toEnglishString<mpz_class, false, false>(
                                mpz_class("1000000000000000000000000000000"))));
  EXPECT_EQ("onenonillion", (toEnglishString<mpz_class, false, true>(
                                mpz_class("1000000000000000000000000000000"))));

  EXPECT_EQ("one octillion ", (toEnglishString<mpz_class, true, false>(
                                  mpz_class("1000000000000000000000000000"))));
  EXPECT_EQ("one octillion ", (toEnglishString<mpz_class, true, true>(
                                  mpz_class("1000000000000000000000000000"))));
  EXPECT_EQ("oneoctillion", (toEnglishString<mpz_class, false, false>(
                                mpz_class("1000000000000000000000000000"))));
  EXPECT_EQ("oneoctillion", (toEnglishString<mpz_class, false, true>(
                                mpz_class("1000000000000000000000000000"))));

  EXPECT_EQ("one septillion ", (toEnglishString<mpz_class, true, false>(
                                   mpz_class("1000000000000000000000000"))));
  EXPECT_EQ("one septillion ", (toEnglishString<mpz_class, true, true>(
                                   mpz_class("1000000000000000000000000"))));
  EXPECT_EQ("oneseptillion", (toEnglishString<mpz_class, false, false>(
                                 mpz_class("1000000000000000000000000"))));
  EXPECT_EQ("oneseptillion", (toEnglishString<mpz_class, false, true>(
                                 mpz_class("1000000000000000000000000"))));

  EXPECT_EQ("one sextillion ", (toEnglishString<mpz_class, true, false>(
                                   mpz_class("1000000000000000000000"))));
  EXPECT_EQ("one sextillion ", (toEnglishString<mpz_class, true, true>(
                                   mpz_class("1000000000000000000000"))));
  EXPECT_EQ("onesextillion", (toEnglishString<mpz_class, false, false>(
                                 mpz_class("1000000000000000000000"))));
  EXPECT_EQ("onesextillion", (toEnglishString<mpz_class, false, true>(
                                 mpz_class("1000000000000000000000"))));

  EXPECT_EQ("one quintillion ", (toEnglishString<mpz_class, true, false>(
                                    mpz_class("1000000000000000000"))));
  EXPECT_EQ("one quintillion ", (toEnglishString<mpz_class, true, true>(
                                    mpz_class("1000000000000000000"))));
  EXPECT_EQ("onequintillion", (toEnglishString<mpz_class, false, false>(
                                  mpz_class("1000000000000000000"))));
  EXPECT_EQ("onequintillion", (toEnglishString<mpz_class, false, true>(
                                  mpz_class("1000000000000000000"))));

  EXPECT_EQ("one quadrillion ", (toEnglishString<mpz_class, true, false>(
                                    mpz_class("1000000000000000"))));
  EXPECT_EQ("one quadrillion ", (toEnglishString<mpz_class, true, true>(
                                    mpz_class("1000000000000000"))));
  EXPECT_EQ("onequadrillion", (toEnglishString<mpz_class, false, false>(
                                  mpz_class("1000000000000000"))));
  EXPECT_EQ("onequadrillion", (toEnglishString<mpz_class, false, true>(
                                  mpz_class("1000000000000000"))));

  EXPECT_EQ("one trillion ", (toEnglishString<mpz_class, true, false>(
                                 mpz_class("1000000000000"))));
  EXPECT_EQ("one trillion ", (toEnglishString<mpz_class, true, true>(
                                 mpz_class("1000000000000"))));
  EXPECT_EQ("onetrillion", (toEnglishString<mpz_class, false, false>(
                               mpz_class("1000000000000"))));
  EXPECT_EQ("onetrillion", (toEnglishString<mpz_class, false, true>(
                               mpz_class("1000000000000"))));

  EXPECT_EQ("one billion ",
            (toEnglishString<mpz_class, true, false>(mpz_class("1000000000"))));
  EXPECT_EQ("one billion ",
            (toEnglishString<mpz_class, true, true>(mpz_class("1000000000"))));
  EXPECT_EQ("onebillion", (toEnglishString<mpz_class, false, false>(
                              mpz_class("1000000000"))));
  EXPECT_EQ("onebillion",
            (toEnglishString<mpz_class, false, true>(mpz_class("1000000000"))));

  EXPECT_EQ("one million ",
            (toEnglishString<mpz_class, true, false>(mpz_class("1000000"))));
  EXPECT_EQ("one million ",
            (toEnglishString<mpz_class, true, true>(mpz_class("1000000"))));
  EXPECT_EQ("onemillion",
            (toEnglishString<mpz_class, false, false>(mpz_class("1000000"))));
  EXPECT_EQ("onemillion",
            (toEnglishString<mpz_class, false, true>(mpz_class("1000000"))));

  EXPECT_EQ("one thousand ",
            (toEnglishString<mpz_class, true, false>(mpz_class("1000"))));
  EXPECT_EQ("one thousand ",
            (toEnglishString<mpz_class, true, true>(mpz_class("1000"))));
  EXPECT_EQ("onethousand",
            (toEnglishString<mpz_class, false, false>(mpz_class("1000"))));
  EXPECT_EQ("onethousand",
            (toEnglishString<mpz_class, false, true>(mpz_class("1000"))));

  EXPECT_EQ("one", (toEnglishString<mpz_class, true, false>(mpz_class("1"))));
  EXPECT_EQ("one", (toEnglishString<mpz_class, true, true>(mpz_class("1"))));
  EXPECT_EQ("one", (toEnglishString<mpz_class, false, false>(mpz_class("1"))));
  EXPECT_EQ("one", (toEnglishString<mpz_class, false, true>(mpz_class("1"))));

  // Test things using integers
  EXPECT_EQ("one", toEnglishString(1));
  EXPECT_EQ("two", toEnglishString(2));
  EXPECT_EQ("three", toEnglishString(3));
  EXPECT_EQ("four", toEnglishString(4));
  EXPECT_EQ("five", toEnglishString(5));
  EXPECT_EQ("six", toEnglishString(6));
  EXPECT_EQ("seven", toEnglishString(7));
  EXPECT_EQ("eight", toEnglishString(8));
  EXPECT_EQ("nine", toEnglishString(9));
  EXPECT_EQ("ten", toEnglishString(10));
  EXPECT_EQ("eleven", toEnglishString(11));
  EXPECT_EQ("twelve", toEnglishString(12));
  EXPECT_EQ("thirteen", toEnglishString(13));
  EXPECT_EQ("fourteen", toEnglishString(14));
  EXPECT_EQ("fifteen", toEnglishString(15));
  EXPECT_EQ("sixteen", toEnglishString(16));
  EXPECT_EQ("seventeen", toEnglishString(17));
  EXPECT_EQ("eighteen", toEnglishString(18));
  EXPECT_EQ("nineteen", toEnglishString(19));
  EXPECT_EQ("twenty", toEnglishString(20));
  EXPECT_EQ("twenty-one", toEnglishString(21));
  EXPECT_EQ("twentyone", (toEnglishString<int, false>(21)));
  EXPECT_EQ("thirty", toEnglishString(30));
  EXPECT_EQ("thirty-one", toEnglishString(31));
  EXPECT_EQ("thirtyone", (toEnglishString<int, false>(31)));
  EXPECT_EQ("forty", toEnglishString(40));
  EXPECT_EQ("forty-one", toEnglishString(41));
  EXPECT_EQ("fortyone", (toEnglishString<int, false>(41)));
  EXPECT_EQ("fifty", toEnglishString(50));
  EXPECT_EQ("fifty-one", toEnglishString(51));
  EXPECT_EQ("fiftyone", (toEnglishString<int, false>(51)));
  EXPECT_EQ("sixty", toEnglishString(60));
  EXPECT_EQ("sixty-one", toEnglishString(61));
  EXPECT_EQ("sixtyone", (toEnglishString<int, false>(61)));
  EXPECT_EQ("seventy", toEnglishString(70));
  EXPECT_EQ("seventy-one", toEnglishString(71));
  EXPECT_EQ("seventyone", (toEnglishString<int, false>(71)));
  EXPECT_EQ("eighty", toEnglishString(80));
  EXPECT_EQ("eighty-one", toEnglishString(81));
  EXPECT_EQ("eightyone", (toEnglishString<int, false>(81)));
  EXPECT_EQ("ninety", toEnglishString(90));
  EXPECT_EQ("ninety-one", toEnglishString(91));
  EXPECT_EQ("ninetyone", (toEnglishString<int, false>(91)));
  EXPECT_EQ("one hundred ", toEnglishString(100));
  EXPECT_EQ("one hundred one", toEnglishString(101));
  EXPECT_EQ("one hundred and one", (toEnglishString<int, true, true>(101)));
  EXPECT_EQ("onehundredone", (toEnglishString<int, false>(101)));
  EXPECT_EQ("onehundredandone", (toEnglishString<int, false, true>(101)));

  EXPECT_EQ("one hundred twenty-three thousand four hundred fifty-six",
            toEnglishString(123456));
  EXPECT_EQ("one hundred twenty-three thousand four hundred and fifty-six",
            (toEnglishString<int, true, true>(123456)));
  EXPECT_EQ("onehundredtwentythreethousandfourhundredfiftysix",
            (toEnglishString<int, false>(123456)));
  EXPECT_EQ("onehundredtwentythreethousandfourhundredandfiftysix",
            (toEnglishString<int, false, true>(123456)));
}
