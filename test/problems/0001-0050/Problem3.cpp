#include <gtest/gtest.h>

#include "problems/0001-0050/Problem3.h"
using problems::Problem3;
#include "problems/Factory.h"
using problems::Factory::create;

TEST(Problem3, Basics) {
  Problem3 p;

  EXPECT_EQ(29, p.faster(13195));
  EXPECT_EQ(6857, p.faster(600851475143ull));
}

TEST(Problem3, ViaFactory) {
  auto p = create(3);

  p->solve();

  EXPECT_EQ("The largest prime factor of the number 600851475143 is 6857",
            p->answer());
}
