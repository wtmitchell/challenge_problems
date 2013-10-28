#include <gtest/gtest.h>

#include "problems/Factory.h"
using problems::Factory::create;

#include "problems/0001-0050/Problem14.h"
using problems::Problem14;

TEST(Problem14, bruteForce) {
  Problem14 p;

  EXPECT_EQ(9ull, p.bruteForce(10ull));
  EXPECT_EQ(837799ull, p.bruteForce(1000000ull));
}

TEST(Problem14, faster) {
  Problem14 p;

  EXPECT_EQ(9ull, p.faster(10ull, 10));
  EXPECT_EQ(837799ull, p.faster(1000000ull, 500000));
}

TEST(Problem14, ViaFactory) {
  auto p = create(14);

  p->solve();

  EXPECT_EQ("The longest Collatz sequence starting at under one million starts "
            "at 837799 and has length 525",
            p->answer());
}
