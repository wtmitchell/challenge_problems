#include <gtest/gtest.h>

#include "project_euler/Factory.h"
using project_euler::Factory::create;

#include "project_euler/0001-0050/Problem15.h"
using project_euler::Problem15;

TEST(Problem15, ViaFactory) {
  auto p = create(15);

  p->solve();

  EXPECT_EQ("The number of paths through a 20x20 grid is 137846528820",
            p->answer());
}
