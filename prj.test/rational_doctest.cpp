#include <rational/rational.hpp>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

#include <iostream>

void test_bool(const int32_t num1, const int32_t det1, const int32_t num2, const int32_t det2)
{
  Ration a(num1, det1);
  Ration b(num2, det2);
  // ==
  if (num1 == num2 && det1 == det2)
  {
    if (a == b) { std::cout << "== is correct" << std::endl;}
    else { std::cout << "== not is correct" << std::endl;}
  }
  // !=
  if (num1 != num2 || det1 != det2)
  {
    if (a != b) { std::cout << "!= is correct" << std::endl;}
    else { std::cout << "!= not is correct" << std::endl;}
  }
}

void test_plus(const int32_t num1, const int32_t det1, const int32_t num2, const int32_t det2,
  const int32_t num3, const int32_t det3)
{
  Ration n1(num1, det1);
  Ration n2(num2, det2);
  Ration n3(num3, det3);
  CHECK((n1 + n2) == n3);
  if ((n1 + n2) == n3) {}
  else { std::cout << "+ not is correct" << std::endl;}
}

void test_minus(const int32_t num1, const int32_t det1, const int32_t num2, const int32_t det2,
  const int32_t num3, const int32_t det3)
{
  Ration n1(num1, det1);
  Ration n2(num2, det2);
  Ration n3(num3, det3);
  CHECK((n1 - n2) == n3);
  if ((n1 - n2) == n3) {}
  else { std::cout << "- not is correct" << std::endl;}
}

void test_mul(const int32_t num1, const int32_t det1, const int32_t num2, const int32_t det2,
  const int32_t num3, const int32_t det3)
{
  Ration n1(num1, det1);
  Ration n2(num2, det2);
  Ration n3(num3, det3);
  CHECK((n1 * n2) == n3);
  if ((n1 * n2) == n3) {}
  else { std::cout << "* not is correct" << std::endl;}
}

void test_div(const int32_t num1, const int32_t det1, const int32_t num2, const int32_t det2,
  const int32_t num3, const int32_t det3)
{
  Ration n1(num1, det1);
  Ration n2(num2, det2);
  Ration n3(num3, det3);
  CHECK((n1 / n2) == n3);
  if ((n1 / n2) == n3) {}
  else { std::cout << "/ not is correct" << std::endl;}
}

void test_eqplus(const int32_t num1, const int32_t det1, const int32_t num2, const int32_t det2,
  const int32_t num3, const int32_t det3)
{
  Ration n1(num1, det1);
  Ration n2(num2, det2);
  Ration n3(num3, det3);
  n1 += n2;
  CHECK(n1 == n3);
  if (n1 == n3) {}
  else { std::cout << "+= not is correct" << std::endl;}
}

void test_eqminus(const int32_t num1, const int32_t det1, const int32_t num2, const int32_t det2,
  const int32_t num3, const int32_t det3)
{
  Ration n1(num1, det1);
  Ration n2(num2, det2);
  Ration n3(num3, det3);
  n1 -= n2;
  CHECK(n1 == n3);
  if (n1 == n3) {}
  else { std::cout << "-= not is correct" << std::endl;}
}

void test_eqmul(const int32_t num1, const int32_t det1, const int32_t num2, const int32_t det2,
  const int32_t num3, const int32_t det3)
{
  Ration n1(num1, det1);
  Ration n2(num2, det2);
  Ration n3(num3, det3);
  n1 *= n2;
  CHECK(n1 == n3);
  if (n1 == n3) {}
  else { std::cout << "*= not is correct" << std::endl;}
}

void test_eqdiv(const int32_t num1, const int32_t det1, const int32_t num2, const int32_t det2,
  const int32_t num3, const int32_t det3)
{
  Ration n1(num1, det1);
  Ration n2(num2, det2);
  Ration n3(num3, det3);
  n1 /= n2;
  CHECK(n1 == n3);
  if (n1 == n3) {}
  else { std::cout << "/= not is correct" << std::endl;}
}

TEST_CASE("[complex] - ctor") {
  test_bool(1.0, 1.0, 1.0, 1.0);

  test_plus(1, 2, 3, 4, 5, 4);
  test_minus(1, 2, 3, 4, -1, 4);
  test_mul(2, 3, 5, 6, 5, 9);
  test_div(2, 3, 5, 6, 4, 5);

  test_eqplus(1, 2, 3, 4, 5, 4);
  test_eqminus(1, 2, 3, 4, -1, 4);
  test_eqmul(2, 3, 5, 6, 5, 9);
  test_eqdiv(2, 3, 5, 6, 4, 5);

}