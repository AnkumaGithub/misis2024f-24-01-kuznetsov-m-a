#include <complex/complex.hpp>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

TEST_CASE("[complex] - ctor") {
  CHECK(Complex() == Complex(0.0, 0.0));
  CHECK(Complex(2.0) == Complex(2.0, 0.0));
  CHECK(Complex(1.0, 3.0) - Complex(2.0, 3.0) == Complex(1.0, 0.0));
}
