#include <gtest/gtest.h>

#include "problems/Factory.h"
using problems::Factory::create;

#include "problems/0001-0050/Problem15.h"
using problems::Problem15;

TEST(Problem15, ViaFactory) {
  auto p = create(15);

  p->solve();

  EXPECT_EQ("The number of paths through a 20x20 grid is 137846528820",
            p->answer());
}
