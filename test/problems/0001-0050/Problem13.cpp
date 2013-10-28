#include <gtest/gtest.h>

#include "problems/Factory.h"
using problems::Factory::create;

TEST(Problem13, ViaFactory) {
  auto p = create(13);

  p->solve();

  EXPECT_EQ("The first ten digits are 5537376230 of the total "
            "5537376230390876637302048746832985971773659831892672",
            p->answer());
}
