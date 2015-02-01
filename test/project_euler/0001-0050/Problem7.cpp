#include <gtest/gtest.h>

#include "project_euler/Factory.h"
using project_euler::Factory::create;

#include "project_euler/0001-0050/Problem7.h"
using project_euler::Problem7;

TEST(Problem7, Basics) {
  Problem7 p;

  EXPECT_EQ(p.bruteForce(100), p.bruteForce2(100));
  EXPECT_EQ(p.bruteForce(100), p.bruteForce3(100));
}

TEST(Problem7, bruteForce) {
  Problem7 p;

  EXPECT_EQ(13, p.bruteForce(6));
  EXPECT_EQ(29, p.bruteForce(10));
  EXPECT_EQ(541, p.bruteForce(100));
  EXPECT_EQ(7919, p.bruteForce(1000));
  EXPECT_EQ(104729, p.bruteForce(10000));
  EXPECT_EQ(104743, p.bruteForce(10001));
}

TEST(Problem7, bruteForce2) {
  Problem7 p;

  EXPECT_EQ(13, p.bruteForce2(6));
  EXPECT_EQ(29, p.bruteForce2(10));
  EXPECT_EQ(541, p.bruteForce2(100));
  EXPECT_EQ(7919, p.bruteForce2(1000));
  EXPECT_EQ(104729, p.bruteForce2(10000));
  EXPECT_EQ(104743, p.bruteForce2(10001));
}

TEST(Problem7, bruteForce3) {
  Problem7 p;

  EXPECT_EQ(13, p.bruteForce3(6));
  EXPECT_EQ(29, p.bruteForce3(10));
  EXPECT_EQ(541, p.bruteForce3(100));
  EXPECT_EQ(7919, p.bruteForce3(1000));
  EXPECT_EQ(104729, p.bruteForce3(10000));
  EXPECT_EQ(104743, p.bruteForce3(10001));
}

TEST(Problem7, bruteForce4) {
  Problem7 p;

  EXPECT_EQ(13, p.bruteForce4(6));
  EXPECT_EQ(29, p.bruteForce4(10));
  EXPECT_EQ(541, p.bruteForce4(100));
  EXPECT_EQ(7919, p.bruteForce4(1000));
  EXPECT_EQ(104729, p.bruteForce4(10000));
  EXPECT_EQ(104743, p.bruteForce4(10001));
}

TEST(Problem7, ViaFactory) {
  auto p = create(7);

  p->solve();

  EXPECT_EQ("The 10001st prime number is 104743", p->answer());
}
