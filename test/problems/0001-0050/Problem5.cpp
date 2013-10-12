#include <gtest/gtest.h>

#include "problems/Factory.h"
using problems::Factory::create;

TEST(Problem5, ViaFactory) {
  auto p = create(5);

  p->solve();

  EXPECT_EQ("The smallest positive number that is evenly divisible by all of "
            "the numbers from 1 to 20 is 232792560",
            p->answer());
}
