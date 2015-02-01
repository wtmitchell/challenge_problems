#include <gtest/gtest.h>

#include "project_euler/Factory.h"
using project_euler::Factory::create;

#include "project_euler/0001-0050/Problem17.h"
using project_euler::Problem17;

TEST(Problem17, bruteForce) {
  Problem17 p;

  EXPECT_EQ(19, p.bruteForce(5));
  EXPECT_EQ(21124, p.bruteForce(1000));
}

TEST(Problem17, bruteForce2) {
  Problem17 p;

  EXPECT_EQ(21124, p.bruteForce2());
}

TEST(Problem17, bruteForce3) {
  Problem17 p;

  EXPECT_EQ(21124, p.bruteForce3());
}

TEST(Problem17, ViaFactory) {
  auto p = create(17);

  p->solve();

  EXPECT_EQ("The number of letters used to write 1 to 1000 with British usage "
            "is 21124",
            p->answer());
}
