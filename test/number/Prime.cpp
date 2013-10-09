#include <gtest/gtest.h>

#include <vector>
using std::vector;

#include "number/Prime.h"
using number::isPrime;
using number::primeDivisors;
using number::primesAtMost;

TEST(Prime, isPrime) {
  // Exhaustive first 20 numbers
  EXPECT_TRUE(isPrime(2));
  EXPECT_TRUE(isPrime(3));
  EXPECT_FALSE(isPrime(4));
  EXPECT_TRUE(isPrime(5));
  EXPECT_FALSE(isPrime(6));
  EXPECT_TRUE(isPrime(7));
  EXPECT_FALSE(isPrime(8));
  EXPECT_FALSE(isPrime(9));
  EXPECT_FALSE(isPrime(10));
  EXPECT_TRUE(isPrime(11));
  EXPECT_FALSE(isPrime(12));
  EXPECT_TRUE(isPrime(13));
  EXPECT_FALSE(isPrime(14));
  EXPECT_FALSE(isPrime(15));
  EXPECT_FALSE(isPrime(16));
  EXPECT_TRUE(isPrime(17));
  EXPECT_FALSE(isPrime(18));
  EXPECT_TRUE(isPrime(19));
  EXPECT_FALSE(isPrime(20));

  // Remaining primes up to 1000
  EXPECT_TRUE(isPrime(23));
  EXPECT_TRUE(isPrime(29));
  EXPECT_TRUE(isPrime(31));
  EXPECT_TRUE(isPrime(37));
  EXPECT_TRUE(isPrime(41));
  EXPECT_TRUE(isPrime(43));
  EXPECT_TRUE(isPrime(47));
  EXPECT_TRUE(isPrime(53));
  EXPECT_TRUE(isPrime(59));
  EXPECT_TRUE(isPrime(61));
  EXPECT_TRUE(isPrime(67));
  EXPECT_TRUE(isPrime(71));
  EXPECT_TRUE(isPrime(73));
  EXPECT_TRUE(isPrime(79));
  EXPECT_TRUE(isPrime(83));
  EXPECT_TRUE(isPrime(89));
  EXPECT_TRUE(isPrime(97));
  EXPECT_TRUE(isPrime(101));
  EXPECT_TRUE(isPrime(103));
  EXPECT_TRUE(isPrime(107));
  EXPECT_TRUE(isPrime(109));
  EXPECT_TRUE(isPrime(113));
  EXPECT_TRUE(isPrime(127));
  EXPECT_TRUE(isPrime(131));
  EXPECT_TRUE(isPrime(137));
  EXPECT_TRUE(isPrime(139));
  EXPECT_TRUE(isPrime(149));
  EXPECT_TRUE(isPrime(151));
  EXPECT_TRUE(isPrime(157));
  EXPECT_TRUE(isPrime(163));
  EXPECT_TRUE(isPrime(167));
  EXPECT_TRUE(isPrime(173));
  EXPECT_TRUE(isPrime(179));
  EXPECT_TRUE(isPrime(181));
  EXPECT_TRUE(isPrime(191));
  EXPECT_TRUE(isPrime(193));
  EXPECT_TRUE(isPrime(197));
  EXPECT_TRUE(isPrime(199));
  EXPECT_TRUE(isPrime(211));
  EXPECT_TRUE(isPrime(223));
  EXPECT_TRUE(isPrime(227));
  EXPECT_TRUE(isPrime(229));
  EXPECT_TRUE(isPrime(233));
  EXPECT_TRUE(isPrime(239));
  EXPECT_TRUE(isPrime(241));
  EXPECT_TRUE(isPrime(251));
  EXPECT_TRUE(isPrime(257));
  EXPECT_TRUE(isPrime(263));
  EXPECT_TRUE(isPrime(269));
  EXPECT_TRUE(isPrime(271));
  EXPECT_TRUE(isPrime(277));
  EXPECT_TRUE(isPrime(281));
  EXPECT_TRUE(isPrime(283));
  EXPECT_TRUE(isPrime(293));
  EXPECT_TRUE(isPrime(307));
  EXPECT_TRUE(isPrime(311));
  EXPECT_TRUE(isPrime(313));
  EXPECT_TRUE(isPrime(317));
  EXPECT_TRUE(isPrime(331));
  EXPECT_TRUE(isPrime(337));
  EXPECT_TRUE(isPrime(347));
  EXPECT_TRUE(isPrime(349));
  EXPECT_TRUE(isPrime(353));
  EXPECT_TRUE(isPrime(359));
  EXPECT_TRUE(isPrime(367));
  EXPECT_TRUE(isPrime(373));
  EXPECT_TRUE(isPrime(379));
  EXPECT_TRUE(isPrime(383));
  EXPECT_TRUE(isPrime(389));
  EXPECT_TRUE(isPrime(397));
  EXPECT_TRUE(isPrime(401));
  EXPECT_TRUE(isPrime(409));
  EXPECT_TRUE(isPrime(419));
  EXPECT_TRUE(isPrime(421));
  EXPECT_TRUE(isPrime(431));
  EXPECT_TRUE(isPrime(433));
  EXPECT_TRUE(isPrime(439));
  EXPECT_TRUE(isPrime(443));
  EXPECT_TRUE(isPrime(449));
  EXPECT_TRUE(isPrime(457));
  EXPECT_TRUE(isPrime(461));
  EXPECT_TRUE(isPrime(463));
  EXPECT_TRUE(isPrime(467));
  EXPECT_TRUE(isPrime(479));
  EXPECT_TRUE(isPrime(487));
  EXPECT_TRUE(isPrime(491));
  EXPECT_TRUE(isPrime(499));
  EXPECT_TRUE(isPrime(503));
  EXPECT_TRUE(isPrime(509));
  EXPECT_TRUE(isPrime(521));
  EXPECT_TRUE(isPrime(523));
  EXPECT_TRUE(isPrime(541));
  EXPECT_TRUE(isPrime(547));
  EXPECT_TRUE(isPrime(557));
  EXPECT_TRUE(isPrime(563));
  EXPECT_TRUE(isPrime(569));
  EXPECT_TRUE(isPrime(571));
  EXPECT_TRUE(isPrime(577));
  EXPECT_TRUE(isPrime(587));
  EXPECT_TRUE(isPrime(593));
  EXPECT_TRUE(isPrime(599));
  EXPECT_TRUE(isPrime(601));
  EXPECT_TRUE(isPrime(607));
  EXPECT_TRUE(isPrime(613));
  EXPECT_TRUE(isPrime(617));
  EXPECT_TRUE(isPrime(619));
  EXPECT_TRUE(isPrime(631));
  EXPECT_TRUE(isPrime(641));
  EXPECT_TRUE(isPrime(643));
  EXPECT_TRUE(isPrime(647));
  EXPECT_TRUE(isPrime(653));
  EXPECT_TRUE(isPrime(659));
  EXPECT_TRUE(isPrime(661));
  EXPECT_TRUE(isPrime(673));
  EXPECT_TRUE(isPrime(677));
  EXPECT_TRUE(isPrime(683));
  EXPECT_TRUE(isPrime(691));
  EXPECT_TRUE(isPrime(701));
  EXPECT_TRUE(isPrime(709));
  EXPECT_TRUE(isPrime(719));
  EXPECT_TRUE(isPrime(727));
  EXPECT_TRUE(isPrime(733));
  EXPECT_TRUE(isPrime(739));
  EXPECT_TRUE(isPrime(743));
  EXPECT_TRUE(isPrime(751));
  EXPECT_TRUE(isPrime(757));
  EXPECT_TRUE(isPrime(761));
  EXPECT_TRUE(isPrime(769));
  EXPECT_TRUE(isPrime(773));
  EXPECT_TRUE(isPrime(787));
  EXPECT_TRUE(isPrime(797));
  EXPECT_TRUE(isPrime(809));
  EXPECT_TRUE(isPrime(811));
  EXPECT_TRUE(isPrime(821));
  EXPECT_TRUE(isPrime(823));
  EXPECT_TRUE(isPrime(827));
  EXPECT_TRUE(isPrime(829));
  EXPECT_TRUE(isPrime(839));
  EXPECT_TRUE(isPrime(853));
  EXPECT_TRUE(isPrime(857));
  EXPECT_TRUE(isPrime(859));
  EXPECT_TRUE(isPrime(863));
  EXPECT_TRUE(isPrime(877));
  EXPECT_TRUE(isPrime(881));
  EXPECT_TRUE(isPrime(883));
  EXPECT_TRUE(isPrime(887));
  EXPECT_TRUE(isPrime(907));
  EXPECT_TRUE(isPrime(911));
  EXPECT_TRUE(isPrime(919));
  EXPECT_TRUE(isPrime(929));
  EXPECT_TRUE(isPrime(937));
  EXPECT_TRUE(isPrime(941));
  EXPECT_TRUE(isPrime(947));
  EXPECT_TRUE(isPrime(953));
  EXPECT_TRUE(isPrime(967));
  EXPECT_TRUE(isPrime(971));
  EXPECT_TRUE(isPrime(977));
  EXPECT_TRUE(isPrime(983));
  EXPECT_TRUE(isPrime(991));
  EXPECT_TRUE(isPrime(997));
}

TEST(Primes, isPrimeAugmented) {
  auto v = primesAtMost(1000u);

  for (unsigned i = 0; i < 10000; ++i) {
    if (isPrime(i))
      EXPECT_TRUE(isPrime(i, v));
    else
      EXPECT_FALSE(isPrime(i, v));
  }
}

TEST(Primes, primeDivisors) {
  vector<unsigned long long> knownFactors;

  knownFactors.push_back(2);

  EXPECT_EQ(knownFactors, primeDivisors(2ull));
  EXPECT_EQ(knownFactors, primeDivisors(4ull));
  EXPECT_EQ(knownFactors, primeDivisors(8ull));
  EXPECT_EQ(knownFactors, primeDivisors(16ull));
  EXPECT_EQ(knownFactors, primeDivisors(32ull));
  EXPECT_EQ(knownFactors, primeDivisors(64ull));
  EXPECT_EQ(knownFactors, primeDivisors(128ull));
  EXPECT_EQ(knownFactors, primeDivisors(256ull));
  EXPECT_EQ(knownFactors, primeDivisors(512ull));
  EXPECT_EQ(knownFactors, primeDivisors(1024ull));
  EXPECT_EQ(knownFactors, primeDivisors(2048ull));
  EXPECT_EQ(knownFactors, primeDivisors(4096ull));

  knownFactors.push_back(5);

  EXPECT_EQ(knownFactors, primeDivisors(2ull * 5ull));
  EXPECT_EQ(knownFactors, primeDivisors(4ull * 5ull));
  EXPECT_EQ(knownFactors, primeDivisors(4ull * 25ull));

  knownFactors.push_back(11);

  EXPECT_EQ(knownFactors, primeDivisors(2ull * 5ull * 11ull));
  EXPECT_EQ(knownFactors, primeDivisors(4ull * 5ull * 121ull));
  EXPECT_EQ(knownFactors, primeDivisors(4ull * 25ull * 121ull));
}

TEST(Primes, primesAtMost) {

  // Check through primes up to 10
  vector<unsigned int> knownPrimes;

  knownPrimes.push_back(2);
  knownPrimes.push_back(3);
  knownPrimes.push_back(5);
  knownPrimes.push_back(7);

  auto calculated = primesAtMost(7u);
  EXPECT_EQ(knownPrimes, calculated);

  // Check through primes up to 20
  knownPrimes.push_back(11);
  knownPrimes.push_back(13);
  knownPrimes.push_back(17);
  knownPrimes.push_back(19);

  calculated = primesAtMost(20u);
  EXPECT_EQ(knownPrimes, calculated);

  // Check through primes up to 100
  knownPrimes.push_back(23);
  knownPrimes.push_back(29);
  knownPrimes.push_back(31);
  knownPrimes.push_back(37);
  knownPrimes.push_back(41);
  knownPrimes.push_back(43);
  knownPrimes.push_back(47);
  knownPrimes.push_back(53);
  knownPrimes.push_back(59);
  knownPrimes.push_back(61);
  knownPrimes.push_back(67);
  knownPrimes.push_back(71);
  knownPrimes.push_back(73);
  knownPrimes.push_back(79);
  knownPrimes.push_back(83);
  knownPrimes.push_back(89);
  knownPrimes.push_back(97);

  calculated = primesAtMost(100u);
  EXPECT_EQ(knownPrimes, calculated);

  // Check through primes up to 500
  knownPrimes.push_back(101);
  knownPrimes.push_back(103);
  knownPrimes.push_back(107);
  knownPrimes.push_back(109);
  knownPrimes.push_back(113);
  knownPrimes.push_back(127);
  knownPrimes.push_back(131);
  knownPrimes.push_back(137);
  knownPrimes.push_back(139);
  knownPrimes.push_back(149);
  knownPrimes.push_back(151);
  knownPrimes.push_back(157);
  knownPrimes.push_back(163);
  knownPrimes.push_back(167);
  knownPrimes.push_back(173);
  knownPrimes.push_back(179);
  knownPrimes.push_back(181);
  knownPrimes.push_back(191);
  knownPrimes.push_back(193);
  knownPrimes.push_back(197);
  knownPrimes.push_back(199);
  knownPrimes.push_back(211);
  knownPrimes.push_back(223);
  knownPrimes.push_back(227);
  knownPrimes.push_back(229);
  knownPrimes.push_back(233);
  knownPrimes.push_back(239);
  knownPrimes.push_back(241);
  knownPrimes.push_back(251);
  knownPrimes.push_back(257);
  knownPrimes.push_back(263);
  knownPrimes.push_back(269);
  knownPrimes.push_back(271);
  knownPrimes.push_back(277);
  knownPrimes.push_back(281);
  knownPrimes.push_back(283);
  knownPrimes.push_back(293);
  knownPrimes.push_back(307);
  knownPrimes.push_back(311);
  knownPrimes.push_back(313);
  knownPrimes.push_back(317);
  knownPrimes.push_back(331);
  knownPrimes.push_back(337);
  knownPrimes.push_back(347);
  knownPrimes.push_back(349);
  knownPrimes.push_back(353);
  knownPrimes.push_back(359);
  knownPrimes.push_back(367);
  knownPrimes.push_back(373);
  knownPrimes.push_back(379);
  knownPrimes.push_back(383);
  knownPrimes.push_back(389);
  knownPrimes.push_back(397);
  knownPrimes.push_back(401);
  knownPrimes.push_back(409);
  knownPrimes.push_back(419);
  knownPrimes.push_back(421);
  knownPrimes.push_back(431);
  knownPrimes.push_back(433);
  knownPrimes.push_back(439);
  knownPrimes.push_back(443);
  knownPrimes.push_back(449);
  knownPrimes.push_back(457);
  knownPrimes.push_back(461);
  knownPrimes.push_back(463);
  knownPrimes.push_back(467);
  knownPrimes.push_back(479);
  knownPrimes.push_back(487);
  knownPrimes.push_back(491);
  knownPrimes.push_back(499);

  calculated = primesAtMost(500u);
  EXPECT_EQ(knownPrimes, calculated);

  // Check through primes up to 1000
  knownPrimes.push_back(503);
  knownPrimes.push_back(509);
  knownPrimes.push_back(521);
  knownPrimes.push_back(523);
  knownPrimes.push_back(541);
  knownPrimes.push_back(547);
  knownPrimes.push_back(557);
  knownPrimes.push_back(563);
  knownPrimes.push_back(569);
  knownPrimes.push_back(571);
  knownPrimes.push_back(577);
  knownPrimes.push_back(587);
  knownPrimes.push_back(593);
  knownPrimes.push_back(599);
  knownPrimes.push_back(601);
  knownPrimes.push_back(607);
  knownPrimes.push_back(613);
  knownPrimes.push_back(617);
  knownPrimes.push_back(619);
  knownPrimes.push_back(631);
  knownPrimes.push_back(641);
  knownPrimes.push_back(643);
  knownPrimes.push_back(647);
  knownPrimes.push_back(653);
  knownPrimes.push_back(659);
  knownPrimes.push_back(661);
  knownPrimes.push_back(673);
  knownPrimes.push_back(677);
  knownPrimes.push_back(683);
  knownPrimes.push_back(691);
  knownPrimes.push_back(701);
  knownPrimes.push_back(709);
  knownPrimes.push_back(719);
  knownPrimes.push_back(727);
  knownPrimes.push_back(733);
  knownPrimes.push_back(739);
  knownPrimes.push_back(743);
  knownPrimes.push_back(751);
  knownPrimes.push_back(757);
  knownPrimes.push_back(761);
  knownPrimes.push_back(769);
  knownPrimes.push_back(773);
  knownPrimes.push_back(787);
  knownPrimes.push_back(797);
  knownPrimes.push_back(809);
  knownPrimes.push_back(811);
  knownPrimes.push_back(821);
  knownPrimes.push_back(823);
  knownPrimes.push_back(827);
  knownPrimes.push_back(829);
  knownPrimes.push_back(839);
  knownPrimes.push_back(853);
  knownPrimes.push_back(857);
  knownPrimes.push_back(859);
  knownPrimes.push_back(863);
  knownPrimes.push_back(877);
  knownPrimes.push_back(881);
  knownPrimes.push_back(883);
  knownPrimes.push_back(887);
  knownPrimes.push_back(907);
  knownPrimes.push_back(911);
  knownPrimes.push_back(919);
  knownPrimes.push_back(929);
  knownPrimes.push_back(937);
  knownPrimes.push_back(941);
  knownPrimes.push_back(947);
  knownPrimes.push_back(953);
  knownPrimes.push_back(967);
  knownPrimes.push_back(971);
  knownPrimes.push_back(977);
  knownPrimes.push_back(983);
  knownPrimes.push_back(991);
  knownPrimes.push_back(997);

  calculated = primesAtMost(1000u);
  EXPECT_EQ(knownPrimes, calculated);
}
