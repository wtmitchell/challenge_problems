#include <gtest/gtest.h>

#include "problems/Factory.h"
using problems::Factory::create;

#include "problems/0001-0050/Problem12.h"
using problems::Problem12;

TEST(Problem12, bruteForce) {
  Problem12 p;

  EXPECT_EQ(28, p.bruteForce(5));
  EXPECT_EQ(76576500, p.bruteForce(500));
}

TEST(Problem12, faster) {
  Problem12 p;

  EXPECT_EQ(28, p.faster(5));
  EXPECT_EQ(73920, p.faster(100));
  EXPECT_EQ(76576500, p.faster(500));
  EXPECT_EQ(842161320, p.faster(1000));
  EXPECT_EQ(7589181600, p.faster(1500));
}

TEST(Problem12, faster2) {
  Problem12 p;

  EXPECT_EQ(28, p.faster2(5));
  EXPECT_EQ(73920, p.faster2(100));
  EXPECT_EQ(76576500, p.faster2(500));
  EXPECT_EQ(842161320, p.faster2(1000));
  EXPECT_EQ(7589181600, p.faster2(1500));
}

TEST(Problem12, ViaFactory) {
  auto p = create(12);

  p->solve();

  EXPECT_EQ("The 12375th triangular number is the first triangular number with "
            "over 500 divisors. It is 76576500",
            p->answer());
}
