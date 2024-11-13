#include <complex/complex.hpp>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

#include <iostream>

void test_bool(const double nat1, const double imag1, const double nat2, const double imag2)
{
  Complex a(nat1, imag1);
  Complex b(nat2, imag2);
  // ==
  if (nat1 == nat2 && imag1 == imag2)
  {
    if (a == b) { std::cout << "== is correct" << std::endl;}
    else { std::cout << "== not is correct" << std::endl;}
  }
  // !=
  else
  {
    if (a != b) { std::cout << "!= is correct" << std::endl;}
    else { std::cout << "!= not is correct" << std::endl;}
  }
}

void test_plus(const double nat1, const double imag1, const double nat2, const double imag2,
  const double nat3, const double imag3)
{
  Complex n1(nat1, imag1);
  Complex n2(nat2, imag2);
  Complex n3(nat3, imag3);
  CHECK((n1 + n2) == n3);
  if ((n1 + n2) == n3) {}
  else { std::cout << "+ not is correct" << std::endl;}
}

void test_minus(const double nat1, const double imag1, const double nat2, const double imag2,
  const double nat3, const double imag3)
{
  Complex n1(nat1, imag1);
  Complex n2(nat2, imag2);
  Complex n3(nat3, imag3);
  CHECK((n1 - n2) == n3);
  if ((n1 - n2) == n3) {}
  else { std::cout << "- not is correct" << std::endl;}
}

void test_mul(const double nat1, const double imag1, const double nat2, const double imag2,
  const double nat3, const double imag3)
{
  Complex n1(nat1, imag1);
  Complex n2(nat2, imag2);
  Complex n3(nat3, imag3);
  CHECK((n1 * n2) == n3);
  if ((n1 * n2) == n3) {}
  else { std::cout << "* not is correct" << std::endl;}
}

void test_div(const double nat1, const double imag1, const double nat2, const double imag2,
  const double nat3, const double imag3)
{
  Complex n1(nat1, imag1);
  Complex n2(nat2, imag2);
  Complex n3(nat3, imag3);
  CHECK((n1 / n2) == n3);
  if ((n1 / n2) == n3) {}
  else { std::cout << "/ not is correct" << std::endl;}
}

void test_eqplus(const double nat1, const double imag1, const double nat2, const double imag2,
  const double nat3, const double imag3)
{
  Complex n1(nat1, imag1);
  Complex n2(nat2, imag2);
  Complex n3(nat3, imag3);
  n1 += n2;
  CHECK(n1 == n3);
  if (n1 == n3) {}
  else { std::cout << "+= not is correct" << std::endl;}
}

void test_eqminus(const double nat1, const double imag1, const double nat2, const double imag2,
  const double nat3, const double imag3)
{
  Complex n1(nat1, imag1);
  Complex n2(nat2, imag2);
  Complex n3(nat3, imag3);
  n1 -= n2;
  CHECK(n1 == n3);
  if (n1 == n3) {}
  else { std::cout << "-= not is correct" << std::endl;}
}

void test_eqmul(const double nat1, const double imag1, const double nat2, const double imag2,
  const double nat3, const double imag3)
{
  Complex n1(nat1, imag1);
  Complex n2(nat2, imag2);
  Complex n3(nat3, imag3);
  n1 *= n2;
  CHECK(n1 == n3);
  if (n1 == n3) {}
  else { std::cout << "*= not is correct" << std::endl;}
}

void test_eqdiv(const double nat1, const double imag1, const double nat2, const double imag2,
  const double nat3, const double imag3)
{
  Complex n1(nat1, imag1);
  Complex n2(nat2, imag2);
  Complex n3(nat3, imag3);
  n1 /= n2;
  CHECK(n1 == n3);
  if (n1 == n3) {}
  else { std::cout << "/= not is correct" << std::endl;}
}

TEST_CASE("[complex] - ctor") {
  test_bool(1.0, 1.0, 1.0, 1.0);

  test_plus(1, 2, 3, 4, 4, 6);
  test_minus(1, 2, 3, 4, -2, -2);
  test_mul(4, 2, 6, 3, 18, 24);
  test_div(4, 6, 2, 3, 2, 0);

  test_eqplus(1, 2, 3, 4, 4, 6);
  test_eqminus(1, 2, 3, 4, -2, -2);
  test_eqmul(6, 7, 5, 5, -5, 65);
  test_eqdiv(10, 10, 2, 2, 5, 0);
}
