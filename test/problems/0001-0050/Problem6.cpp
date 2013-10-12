#include <gtest/gtest.h>

#include "problems/Factory.h"
using problems::Factory::create;

#include "problems/0001-0050/Problem6.h"
using problems::Problem6;

TEST(Problem6, Basics) {
  Problem6 p;

  EXPECT_EQ(2640, p.bruteForce(10));
  EXPECT_EQ(2640, p.faster(10));

  EXPECT_EQ(25164150, p.bruteForce(100));
  EXPECT_EQ(25164150, p.faster(100));

  EXPECT_EQ(p.bruteForce(20), p.faster(20));
  EXPECT_EQ(p.bruteForce(40), p.faster(40));
  EXPECT_EQ(p.bruteForce(60), p.faster(60));
  EXPECT_EQ(p.bruteForce(80), p.faster(80));
}

TEST(Problem6, ViaFactory) {
  auto p = create(6);

  p->solve();

  EXPECT_EQ("The difference between the sum of squares and the square of the "
            "sum of the first 100 natural numbers is  25164150",
            p->answer());
}
