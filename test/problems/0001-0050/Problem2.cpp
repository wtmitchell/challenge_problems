#include <gtest/gtest.h>

#include "problems/0001-0050/Problem2.h"
using problems::Problem2;
#include "problems/Factory.h"
using problems::Factory::create;

TEST(Problem2, Basics) {
  Problem2 p;

  EXPECT_EQ(10, p.brute_force(10));
  EXPECT_EQ(10, p.faster(10));
  EXPECT_EQ(p.faster(10), p.brute_force(10));
  EXPECT_EQ(p.faster(100), p.brute_force(100));
  EXPECT_EQ(p.faster(1000), p.brute_force(1000));
  EXPECT_EQ(p.faster(10000), p.brute_force(10000));
  EXPECT_EQ(p.faster(100000), p.brute_force(100000));
  EXPECT_EQ(p.faster(1000000), p.brute_force(1000000));
  EXPECT_EQ(p.faster(4000000), p.brute_force(4000000));
}

TEST(Problem2, ViaFactory) {
  auto p = create(2);

  p->solve();

  EXPECT_EQ("The sum of all even valued Fibonacci numbers below 4 million is"
            " 4613732",
            p->answer());
}
