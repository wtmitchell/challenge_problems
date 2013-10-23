#include <gtest/gtest.h>

#include "problems/Factory.h"
using problems::Factory::create;

#include "problems/0001-0050/Problem9.h"
using problems::Problem9;

TEST(Problem9, Basics) {
  Problem9 p;

  // (3, 4, 5)
  EXPECT_EQ(p.bruteForce(12), p.faster(12));
  EXPECT_EQ(60, p.faster(12));

  // (20, 99, 101)
  EXPECT_EQ(p.bruteForce(220), p.faster(220));
  EXPECT_EQ(199980, p.faster(220));

  //(23,264,265)
  EXPECT_EQ(p.bruteForce(552), p.faster(552));
  EXPECT_EQ(1609080, p.faster(552));

  EXPECT_EQ(p.bruteForce(1000), p.faster(1000));
  EXPECT_EQ(31875000, p.faster(1000));
  EXPECT_EQ(p.bruteForce(2000), p.faster(2000));
}

TEST(Problem9, ViaFactory) {
  auto p = create(9);

  p->solve();

  EXPECT_EQ("The product is 31875000 from the triple (200, 375, 425)", p->answer());
}
