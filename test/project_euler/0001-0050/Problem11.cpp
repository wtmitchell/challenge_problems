#include <gtest/gtest.h>

#include "project_euler/Factory.h"
using project_euler::Factory::create;

#include "project_euler/0001-0050/Problem11.h"
using project_euler::Problem11;

TEST(Problem11, Basics) {
  Problem11 p;

  const std::array<std::array<unsigned, 4>, 4> horizontal = {
    { { { 0, 0, 0, 0 } },
      { { 0, 0, 0, 0 } },
      { { 0, 0, 0, 0 } },
      { { 1, 1, 1, 1 } } }
  };
  EXPECT_EQ(1, p.bruteForce(horizontal));

  const std::array<std::array<unsigned, 4>, 4> vertical = {
    { { { 0, 0, 0, 1 } },
      { { 0, 0, 0, 1 } },
      { { 0, 0, 0, 1 } },
      { { 0, 0, 0, 1 } } }
  };
  EXPECT_EQ(1, p.bruteForce(vertical));

  const std::array<std::array<unsigned, 4>, 4> down = {
    { { { 1, 0, 0, 0 } },
      { { 0, 1, 0, 0 } },
      { { 0, 0, 1, 0 } },
      { { 0, 0, 0, 1 } } }
  };
  EXPECT_EQ(1, p.bruteForce(down));

  const std::array<std::array<unsigned, 4>, 4> up = { { { { 0, 0, 0, 1 } },
                                                        { { 0, 0, 1, 0 } },
                                                        { { 0, 1, 0, 0 } },
                                                        { { 1, 0, 0, 0 } } } };
  EXPECT_EQ(1, p.bruteForce(up));
}

TEST(Problem11, ViaFactory) {
  auto p = create(11);

  p->solve();

  EXPECT_EQ("The greatest product in the grid is 70600674", p->answer());
}
