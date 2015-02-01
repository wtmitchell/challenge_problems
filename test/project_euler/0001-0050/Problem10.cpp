#include <gtest/gtest.h>

#include "project_euler/Factory.h"
using project_euler::Factory::create;

#include "project_euler/0001-0050/Problem10.h"
using project_euler::Problem10;

TEST(Problem10, Basics) {
  Problem10 p;

  EXPECT_EQ(17, p.sieveOfEratosthenes(10));
  EXPECT_EQ(1060, p.sieveOfEratosthenes(100));
  EXPECT_EQ(76127, p.sieveOfEratosthenes(1000));
  EXPECT_EQ(5736396, p.sieveOfEratosthenes(10000));
}

TEST(Problem10, ViaFactory) {
  auto p = create(10);

  p->solve();

  EXPECT_EQ("The sum of all primes below 2 million is 142913828922",
            p->answer());
}
