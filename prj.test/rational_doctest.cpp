#include <rational/rational.hpp>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

TEST_CASE("[complex] - ctor") {
  CHECK(Ration() == Ration(0.0, 0.0));
  CHECK(Ration(2.0) == Ration(2.0, 0.0));
  CHECK(Ration(1.0, 3.0) - Ration(2.0, 3.0) == Ration(1.0, 0.0));
}
