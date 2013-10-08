#include <gtest/gtest.h>

#include "problems/0001-0050/Problem1.h"
using problems::Problem1;
#include "problems/Factory.h"
using problems::Factory::create;

TEST(Problem1, Basics) {
  Problem1 p;

  EXPECT_EQ(23, p.brute_force(10));
  EXPECT_EQ(233168, p.brute_force(1000));
  EXPECT_EQ(23, p.faster(10));
  EXPECT_EQ(233168, p.faster(1000));
  EXPECT_EQ(p.brute_force(1000), p.faster(1000));
  EXPECT_EQ(p.brute_force(100), p.faster(100));
  EXPECT_EQ(p.brute_force(10), p.faster(10));
}

TEST(Problem1, ViaFactory) {
  auto p = create(1);

  p->solve();

  EXPECT_EQ("The sum of all multiples of 3 or 5 below 1000 is 233168",
	    p->answer());
}
