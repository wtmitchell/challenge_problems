#include <gtest/gtest.h>

#include <vector>
using std::vector;

#include "number/Palindrome.h"
using number::isPalindrome;

TEST(Palindrom, isPalindrome) {
  // Palindromes up to 500 from OEIS  A002113
  // With non-palindromes thrown in for up to 20
  EXPECT_TRUE(isPalindrome(0));
  EXPECT_TRUE(isPalindrome(1));
  EXPECT_TRUE(isPalindrome(2));
  EXPECT_TRUE(isPalindrome(3));
  EXPECT_TRUE(isPalindrome(4));
  EXPECT_TRUE(isPalindrome(5));
  EXPECT_TRUE(isPalindrome(6));
  EXPECT_TRUE(isPalindrome(7));
  EXPECT_TRUE(isPalindrome(8));
  EXPECT_TRUE(isPalindrome(9));
  EXPECT_FALSE(isPalindrome(10));
  EXPECT_TRUE(isPalindrome(11));
  EXPECT_FALSE(isPalindrome(12));
  EXPECT_FALSE(isPalindrome(13));
  EXPECT_FALSE(isPalindrome(14));
  EXPECT_FALSE(isPalindrome(15));
  EXPECT_FALSE(isPalindrome(16));
  EXPECT_FALSE(isPalindrome(17));
  EXPECT_FALSE(isPalindrome(18));
  EXPECT_FALSE(isPalindrome(19));
  EXPECT_FALSE(isPalindrome(20));
  EXPECT_TRUE(isPalindrome(22));
  EXPECT_TRUE(isPalindrome(33));
  EXPECT_TRUE(isPalindrome(44));
  EXPECT_TRUE(isPalindrome(55));
  EXPECT_TRUE(isPalindrome(66));
  EXPECT_TRUE(isPalindrome(77));
  EXPECT_TRUE(isPalindrome(88));
  EXPECT_TRUE(isPalindrome(99));
  EXPECT_TRUE(isPalindrome(101));
  EXPECT_TRUE(isPalindrome(111));
  EXPECT_TRUE(isPalindrome(121));
  EXPECT_TRUE(isPalindrome(131));
  EXPECT_TRUE(isPalindrome(141));
  EXPECT_TRUE(isPalindrome(151));
  EXPECT_TRUE(isPalindrome(161));
  EXPECT_TRUE(isPalindrome(171));
  EXPECT_TRUE(isPalindrome(181));
  EXPECT_TRUE(isPalindrome(191));
  EXPECT_TRUE(isPalindrome(202));
  EXPECT_TRUE(isPalindrome(212));
  EXPECT_TRUE(isPalindrome(222));
  EXPECT_TRUE(isPalindrome(232));
  EXPECT_TRUE(isPalindrome(242));
  EXPECT_TRUE(isPalindrome(252));
  EXPECT_TRUE(isPalindrome(262));
  EXPECT_TRUE(isPalindrome(272));
  EXPECT_TRUE(isPalindrome(282));
  EXPECT_TRUE(isPalindrome(292));
  EXPECT_TRUE(isPalindrome(303));
  EXPECT_TRUE(isPalindrome(313));
  EXPECT_TRUE(isPalindrome(323));
  EXPECT_TRUE(isPalindrome(333));
  EXPECT_TRUE(isPalindrome(343));
  EXPECT_TRUE(isPalindrome(353));
  EXPECT_TRUE(isPalindrome(363));
  EXPECT_TRUE(isPalindrome(373));
  EXPECT_TRUE(isPalindrome(383));
  EXPECT_TRUE(isPalindrome(393));
  EXPECT_TRUE(isPalindrome(404));
  EXPECT_TRUE(isPalindrome(414));
  EXPECT_TRUE(isPalindrome(424));
  EXPECT_TRUE(isPalindrome(434));
  EXPECT_TRUE(isPalindrome(444));
  EXPECT_TRUE(isPalindrome(454));
  EXPECT_TRUE(isPalindrome(464));
  EXPECT_TRUE(isPalindrome(474));
  EXPECT_TRUE(isPalindrome(484));
  EXPECT_TRUE(isPalindrome(494));
  EXPECT_TRUE(isPalindrome(505));
  EXPECT_TRUE(isPalindrome(515));

  // Some hex palindromes
  EXPECT_TRUE(isPalindrome(0xABA, 16));
  EXPECT_TRUE(isPalindrome(0xDAEAD, 16));
  EXPECT_TRUE(isPalindrome(0xB545B, 16));
}
