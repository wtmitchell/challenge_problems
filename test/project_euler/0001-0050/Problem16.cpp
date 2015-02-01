#include <gtest/gtest.h>

#include "project_euler/Factory.h"
using project_euler::Factory::create;

TEST(Problem16, ViaFactory) {
  auto p = create(16);

  p->solve();

  EXPECT_EQ("The sum of the digits of 2^1000 is 1366", p->answer());
}
