#include <gtest/gtest.h>

#include "problems/Factory.h"
using problems::Factory::create;

TEST(Problem16, ViaFactory) {
  auto p = create(16);

  p->solve();

  EXPECT_EQ("The sum of the digits of 2^1000 is 1366", p->answer());
}
