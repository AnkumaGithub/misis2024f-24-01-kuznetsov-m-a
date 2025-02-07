#include <rational/rational.hpp>
#include <iostream>
#include <sstream>
#include <cstdint>

Rational::Rational(const int32_t lhs) : integ(lhs) {sokrin();}

Rational::Rational(const int32_t lhs, const int32_t rhs) : integ(lhs), nat(rhs)
{
    if (0 == nat) {
        throw std::invalid_argument("Zero denumenator in Rational ctor");
    }
    sokrin();
}

int32_t NOD(int32_t up, int32_t low)
{
    if (up == 0)
    {
        return low;
    }
    return NOD(low, up % low);
}

void Rational::sokrin()
{
    int32_t nod = NOD(abs(integ), abs(nat));
    integ = integ / nod;
    nat = nat / nod;
    if (integ < 0 && nat < 0)
    {
        integ *= -1;
        nat *= -1;
    }
    if (integ > 0 && nat < 0)
    {
        integ *= -1;
        nat *= -1;
    }
}

// bool operators
// ==
bool Rational::operator==(const Rational &rhs) const noexcept{
    return abs(double(integ) / double(nat) - double(rhs.integ) / double(rhs.nat)) < 2 * std::numeric_limits<double>::epsilon();
}
bool Rational::operator==(const int32_t &rhs) const noexcept{
    return abs(double(integ) / double(nat) - double(rhs)) < 2 * std::numeric_limits<double>::epsilon();
}

// !=
bool Rational::operator!=(const Rational &rhs) const noexcept{
    return !operator==(rhs);
}
bool Rational::operator!=(const int32_t &rhs) const noexcept{
    return !operator==(rhs);
}

Rational Rational::operator-() const noexcept
{
    return {-integ, nat};
}

// >=
bool Rational::operator>=(const Rational &rhs) const noexcept{
    Rational z = Rational(integ, nat) - Rational(rhs);
    z.sokrin();
    if (z.integ >= 0) {return true;}
    return false;
}
bool Rational::operator>=(const int32_t &rhs) const noexcept{
    Rational z = Rational(integ, nat) - Rational(rhs);
    z.sokrin();
    if (z.integ >= 0) {return true;}
    return false;
}

// <=
bool Rational::operator<=(const Rational &rhs) const noexcept{
    Rational z = Rational(integ, nat) - Rational(rhs);
    z.sokrin();
    if (z.integ <= 0) {return true;}
    return false;
}
bool Rational::operator<=(const int32_t &rhs) const noexcept{
    Rational z = Rational(integ, nat) - Rational(rhs);
    z.sokrin();
    if (z.integ <= 0) {return true;}
    return false;
}

// >
bool Rational::operator>(const Rational &rhs) const noexcept{
    Rational z = Rational(integ, nat) - Rational(rhs);
    z.sokrin();
    if (z.integ > 0) {return true;}
    return false;
}
bool Rational::operator>(const int32_t &rhs) const noexcept{
    Rational z = Rational(integ, nat) - Rational(rhs);
    z.sokrin();
    if (z.integ > 0) {return true;}
    return false;
}

// <
bool Rational::operator<(const Rational &rhs) const noexcept{
    Rational z = Rational(integ, nat) - Rational(rhs);
    z.sokrin();
    if (z.integ < 0) {return true;}
    return false;
}
bool Rational::operator<(const int32_t &rhs) const noexcept{
    Rational z = Rational(integ, nat) - Rational(rhs);
    z.sokrin();
    if (z.integ < 0) {return true;}
    return false;
}

// +=
Rational& Rational::operator+=(const Rational &rhs) noexcept{
    integ = integ * rhs.nat + rhs.integ * nat;
    nat = rhs.nat * nat;
    this->sokrin();
    return *this;
}
Rational& Rational::operator+=(const int32_t &rhs) noexcept{
    return operator+=(Rational(rhs));
}

// -=
Rational& Rational::operator-=(const Rational &rhs) noexcept{
    integ = integ * rhs.nat - rhs.integ * nat;
    nat = rhs.nat * nat;
    this->sokrin();
    return *this;
}
Rational& Rational::operator-=(const int32_t &rhs) noexcept{
    return operator-=(Rational(rhs));
}

// *=
Rational& Rational::operator*=(const Rational &rhs) noexcept{
    integ = integ * rhs.integ;
    nat = nat * rhs.nat;
    this->sokrin();
    return *this;
}
Rational& Rational::operator*=(const int32_t &rhs) noexcept{
    return operator*=(Rational(rhs));
}

// /=
Rational& Rational::operator/=(const Rational &rhs) noexcept{
    if (rhs.integ == 0){ throw std::invalid_argument("divide by zero"); }
    integ = integ * rhs.nat;
    nat = nat * rhs.integ;
    this->sokrin();
    return *this;
}
Rational& Rational::operator/=(const int32_t &rhs) noexcept{
    return operator/=(Rational(rhs));
}

// +
Rational operator+(const Rational &lhs, const Rational &rhs) noexcept{
    return Rational(lhs) += rhs;
}
Rational operator+(const Rational &lhs, const int32_t &rhs) noexcept{
    return Rational(lhs) += rhs;
}
Rational operator+(const int32_t &lhs, const Rational &rhs) noexcept{
    return Rational(lhs) += rhs;
}

// -
Rational operator-(const Rational &lhs, const Rational &rhs) noexcept{
    return Rational(lhs) -= rhs;
}
Rational operator-(const Rational &lhs, const int32_t &rhs) noexcept{
    return Rational(lhs) -= rhs;
}
Rational operator-(const int32_t &lhs, const Rational &rhs) noexcept{
    return Rational(lhs) -= rhs;
}

// *
Rational operator*(const Rational &lhs, const Rational &rhs) noexcept{
    return Rational(lhs) *= rhs;
}
Rational operator*(const Rational &lhs, const int32_t &rhs) noexcept{
    return Rational(lhs) *= rhs;
}
Rational operator*(const int32_t &lhs, const Rational &rhs) noexcept{
    return Rational(lhs) *= rhs;
}

// /
Rational operator/(const Rational &lhs, const Rational &rhs) noexcept{
    return Rational(lhs) /= rhs;
}
Rational operator/(const Rational &lhs, const int32_t &rhs) noexcept{
    return Rational(lhs) /= rhs;
}
Rational operator/(const int32_t &lhs, const Rational &rhs) noexcept{
    return Rational(lhs) /= rhs;
}

std::ostream& Rational::Writeto(std::ostream& out) const noexcept {
    if (integ == 0 || nat == 1)
    {
        out << integ << Separator << "1";
    }
    else
    {
        if (nat == -1)
        {
            out << -integ << Separator << "1";
        }
        else
        {
            out << integ << Separator << nat;
        }
    }
    return out;
}

std::istream& Rational::Readfrom(std::istream& in) noexcept {
    int32_t integin{0};
    int32_t natin{0};
    char Separatorin{'/'};

    in >> integin >> Separatorin >> natin;

    if (in.good() && natin != 0){
        if (Separatorin==Rational::Separator){
            integ = integin;
            nat = natin;
            this->sokrin();
        }
    }
    if (!in.good() && !in.eof() || natin == 0) {std::cerr << "Invalid input." << std::endl;}
    return in;
}
