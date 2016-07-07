#include <gtest/gtest.h>

#include "project_euler/0001-0050/Problem3.h"
using project_euler::Problem3;
#include "project_euler/Factory.h"
using project_euler::Factory::create;

TEST(Problem3, Basics) {
  Problem3 p;

  EXPECT_EQ(29, p.divisor_list(13195));
  EXPECT_EQ(6857, p.divisor_list(600851475143ull));
}

TEST(Problem3, ViaFactory) {
  auto p = create(3);

  p->solve();

  EXPECT_EQ("The largest prime factor of the number 600851475143 is 6857",
            p->answer());
}
