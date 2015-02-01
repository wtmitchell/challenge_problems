#include <gtest/gtest.h>

#include "project_euler/Factory.h"
using project_euler::Factory::create;

TEST(Problem8, ViaFactory) {
  auto p = create(8);

  p->solve();

  EXPECT_EQ("The greatest product is 40824", p->answer());
}
