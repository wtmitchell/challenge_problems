#include <gtest/gtest.h>

#include "problems/Factory.h"
using problems::Factory::create;

#include "problems/0001-0050/Problem12.h"
using problems::Problem12;

TEST(Problem12, Basics) {
  Problem12 p;

  EXPECT_EQ(28, p.bruteForce(5));
  EXPECT_EQ(28, p.faster(5));
  EXPECT_EQ(76576500, p.bruteForce(500));
  EXPECT_EQ(76576500, p.faster(500));

}

TEST(Problem12, ViaFactory) {
  auto p = create(12);

  p->solve();

  EXPECT_EQ("The 12375th triangular number is the first triangular number with "
            "over 500 divisors. It is 76576500",
            p->answer());
}
