#include <rational/rational.hpp>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

#include <iostream>

void test_rav(const int32_t num1, const int32_t det1, const int32_t num2, const int32_t det2)
{
  Rational a(num1, det1);
  Rational b(num2, det2);
  CHECK(a == b);
}

void test_nerav(const int32_t num1, const int32_t det1, const int32_t num2, const int32_t det2)
{
  Rational a(num1, det1);
  Rational b(num2, det2);
  CHECK(a != b);
}

void test_bol(const int32_t num1, const int32_t det1, const int32_t num2, const int32_t det2)
{
  Rational a(num1, det1);
  Rational b(num2, det2);
  CHECK(a > b);
}

void test_bolrav(const int32_t num1, const int32_t det1, const int32_t num2, const int32_t det2)
{
  Rational a(num1, det1);
  Rational b(num2, det2);
  CHECK(a >= b);
}

void test_men(const int32_t num1, const int32_t det1, const int32_t num2, const int32_t det2)
{
  Rational a(num1, det1);
  Rational b(num2, det2);
  CHECK(a < b);
}

void test_menrav(const int32_t num1, const int32_t det1, const int32_t num2, const int32_t det2)
{
  Rational a(num1, det1);
  Rational b(num2, det2);
  CHECK(a <= b);
}

void test_plus(const int32_t num1, const int32_t det1, const int32_t num2, const int32_t det2,
  const int32_t num3, const int32_t det3)
{
  Rational n1(num1, det1);
  Rational n2(num2, det2);
  Rational n3(num3, det3);
  CHECK((n1 + n2) == n3);
  if ((n1 + n2) == n3) {}
  else { std::cout << "+ not is correct" << std::endl;}
}

void test_minus(const int32_t num1, const int32_t det1, const int32_t num2, const int32_t det2,
  const int32_t num3, const int32_t det3)
{
  Rational n1(num1, det1);
  Rational n2(num2, det2);
  Rational n3(num3, det3);
  CHECK((n1 - n2) == n3);
  if ((n1 - n2) == n3) {}
  else { std::cout << "- not is correct" << std::endl;}
}

void test_mul(const int32_t num1, const int32_t det1, const int32_t num2, const int32_t det2,
  const int32_t num3, const int32_t det3)
{
  Rational n1(num1, det1);
  Rational n2(num2, det2);
  Rational n3(num3, det3);
  CHECK((n1 * n2) == n3);
  if ((n1 * n2) == n3) {}
  else { std::cout << "* not is correct" << std::endl;}
}

void test_div(const int32_t num1, const int32_t det1, const int32_t num2, const int32_t det2,
  const int32_t num3, const int32_t det3)
{
  Rational n1(num1, det1);
  Rational n2(num2, det2);
  Rational n3(num3, det3);
  CHECK((n1 / n2) == n3);
  if ((n1 / n2) == n3) {}
  else { std::cout << "/ not is correct" << std::endl;}
}

void test_eqplus(const int32_t num1, const int32_t det1, const int32_t num2, const int32_t det2,
  const int32_t num3, const int32_t det3)
{
  Rational n1(num1, det1);
  Rational n2(num2, det2);
  Rational n3(num3, det3);
  n1 += n2;
  CHECK(n1 == n3);
  if (n1 == n3) {}
  else { std::cout << "+= not is correct" << std::endl;}
}

void test_eqminus(const int32_t num1, const int32_t det1, const int32_t num2, const int32_t det2,
  const int32_t num3, const int32_t det3)
{
  Rational n1(num1, det1);
  Rational n2(num2, det2);
  Rational n3(num3, det3);
  n1 -= n2;
  CHECK(n1 == n3);
  if (n1 == n3) {}
  else { std::cout << "-= not is correct" << std::endl;}
}

void test_eqmul(const int32_t num1, const int32_t det1, const int32_t num2, const int32_t det2,
  const int32_t num3, const int32_t det3)
{
  Rational n1(num1, det1);
  Rational n2(num2, det2);
  Rational n3(num3, det3);
  n1 *= n2;
  CHECK(n1 == n3);
  if (n1 == n3) {}
  else { std::cout << "*= not is correct" << std::endl;}
}

void test_eqdiv(const int32_t num1, const int32_t det1, const int32_t num2, const int32_t det2,
  const int32_t num3, const int32_t det3)
{
  Rational n1(num1, det1);
  Rational n2(num2, det2);
  Rational n3(num3, det3);
  n1 /= n2;
  CHECK(n1 == n3);
  if (n1 == n3) {}
  else { std::cout << "/= not is correct" << std::endl;}
}

TEST_CASE("[complex] - ctor") {
  Rational n1(1, 1), n2(1, 2), n3(1, -1);
  CHECK(n1 == n3);
  CHECK(n1 > n3);
  CHECK(n1 < n3);
  CHECK(n1 >= n3);
  CHECK(n1 != n3);
  CHECK(n1 <= n3);
  test_rav(1, 2, 1.0, 2.0);
  test_bol(1, 2, 0, 2.0);
  test_bolrav(1, 2, 0, 2.0);
  test_men(-1, 2, 1, 2.0);
  test_menrav(-1, 2, 1, 2.0);
  test_rav(-10, 2, -10.0, 2.0);

  test_plus(1, 2, 3, 4, 5, 4);
  test_plus(-1, 4, 3, 4, 1, 2);
  test_plus(1, 4, 3, 4, 1, 1);

  test_minus(1, 2, 3, 4, -1, 4);
  test_minus(1, 4, 3, 4, -2, 4);
  test_minus(1, 2, 1, 2, 0, 1.0);

  test_mul(2, 3, 5, 6, 5, 9);
  test_div(2, 3, 5, 6, 4, 5);

  test_eqplus(1, 2, 3, 4, 5, 4);
  test_eqminus(1, 2, 3, 4, -1, 4);
  test_eqmul(2, 3, 5, 6, 5, 9);
  test_eqdiv(2, 3, 5, 6, 4, 5);

}