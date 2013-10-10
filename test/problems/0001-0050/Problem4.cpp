#include <gtest/gtest.h>

#include "problems/Factory.h"
using problems::Factory::create;

TEST(Problem4, ViaFactory) {
  auto p = create(4);

  p->solve();

  EXPECT_EQ("The largest palindrome that is a product of two 3-digit numbers "
            "is 993 * 913 = 906609",
            p->answer());
}
