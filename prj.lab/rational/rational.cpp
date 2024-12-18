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
}

Rational sokrout(int32_t up, int32_t low)
{
    int32_t nod = NOD(abs(up), abs(low));
    return {up / nod, low / nod};
}

// bool operators
// ==
bool Rational::operator==(const Rational &rhs) const noexcept{
    return abs(double(integ) / double(nat) - double(rhs.integ) / double(rhs.nat)) <= 2 * std::numeric_limits<double>::epsilon();
}
bool Rational::operator==(const int32_t &rhs) const noexcept{
    return abs(double(integ) / double(nat) - double(rhs)) <= 2 * std::numeric_limits<double>::epsilon();
}

// !=
bool Rational::operator!=(const Rational &rhs) const noexcept{
    return abs(double(integ) / double(nat) - double(rhs.integ) / double(rhs.nat)) > 2 * std::numeric_limits<double>::epsilon();
}
bool Rational::operator!=(const int32_t &rhs) const noexcept{
    return abs(double(integ) / double(nat) - double(rhs)) > 2 * std::numeric_limits<double>::epsilon();
}

Rational Rational::operator-() const noexcept
{
    return {-integ, nat};
}

// >=
bool Rational::operator>=(const Rational &rhs) const noexcept{
    Rational z = Rational(integ, nat) - rhs;
    z.sokrin();
    if (z.integ >= 0) {return true;}
    else {return false;}
}
bool Rational::operator>=(const int32_t &rhs) const noexcept{
    Rational z = Rational(integ, nat) - Rational(rhs);
    z.sokrin();
    if (z.integ >= 0) {return true;}
    else {return false;}
}

// <=
bool Rational::operator<=(const Rational &rhs) const noexcept{
    Rational z = Rational(integ, nat) - rhs;
    z.sokrin();
    if (z.integ <= 0) {return true;}
    else {return false;}
}
bool Rational::operator<=(const int32_t &rhs) const noexcept{
    Rational z = Rational(integ, nat) - rhs;
    z.sokrin();
    if (z.integ <= 0) {return true;}
    else {return false;}
}

// >
bool Rational::operator>(const Rational &rhs) const noexcept{
    Rational z = Rational(integ, nat) - rhs;
    z.sokrin();
    if (z.integ > 0) {return true;}
    else {return false;}
}
bool Rational::operator>(const int32_t &rhs) const noexcept{
    Rational z = Rational(integ, nat) - rhs;
    z.sokrin();
    if (z.integ > 0) {return true;}
    else {return false;}
}

// <
bool Rational::operator<(const Rational &rhs) const noexcept{
    Rational z = Rational(integ, nat) - rhs;
    z.sokrin();
    if (z.integ < 0) {return true;}
    else {return false;}
}
bool Rational::operator<(const int32_t &rhs) const noexcept{
    Rational z = Rational(integ, nat) - rhs;
    z.sokrin();
    if (z.integ < 0) {return true;}
    else {return false;}
}

// += -= *= /= operators 
// +=
Rational& Rational::operator+=(const Rational &rhs) noexcept{
    integ = integ * rhs.nat + rhs.integ * nat;
    nat = rhs.nat * nat;
    this->sokrin();
    return *this;
}
Rational& Rational::operator+=(const int32_t &rhs) noexcept{
    integ += rhs * nat;
    this->sokrin();
    return *this;
}
Rational operator+=(const int32_t &lhs, const Rational &rhs) noexcept{
    Rational buf = rhs;
    std::cout << "!!!!";
    buf += lhs;
    return sokrout(buf.get_integ(), buf.get_nat());
}

// -=
Rational& Rational::operator-=(const Rational &rhs) noexcept{
    integ = integ * rhs.nat - rhs.integ * nat;
    nat = rhs.nat * nat;
    this->sokrin();
    return *this;
}
Rational& Rational::operator-=(const int32_t &rhs) noexcept{
    integ -= rhs * nat;
    this->sokrin();
    return *this;
}
Rational operator-=(const int32_t lhs, const Rational &rhs) noexcept{
    Rational buf = rhs, d{-1,1};
    std::cout << "!!!!";
    buf -= lhs;
    return sokrout(buf.get_integ(), buf.get_nat());
}

// *=
Rational& Rational::operator*=(const Rational &rhs) noexcept{
    integ = integ * rhs.integ;
    nat = nat * rhs.nat;
    this->sokrin();
    return *this;
}
Rational& Rational::operator*=(const int32_t &rhs) noexcept{
    integ = integ * rhs;
    this->sokrin();
    return *this;
}
Rational operator*=(const int32_t &lhs, const Rational &rhs) noexcept{
    Rational buf = rhs;
    std::cout << "!!!!";
    buf *= lhs;
    return sokrout(buf.get_integ(), buf.get_nat());
}

// /=
Rational& Rational::operator/=(const Rational &rhs) noexcept{
    integ = integ * rhs.nat;
    nat = nat * rhs.integ;
    this->sokrin();
    return *this;
}
Rational& Rational::operator/=(const int32_t &rhs) noexcept{
    nat = nat * rhs;
    this->sokrin();
    return *this;
}
Rational operator/=(const int32_t &lhs, const Rational &rhs) noexcept{
    Rational buf = rhs, d;
    buf /= lhs;
    return sokrout(buf.get_nat(), buf.get_integ());
}

//+ - * / operators
// +
Rational operator+(const Rational &lhs, const Rational &rhs) noexcept{
    Rational buf = lhs;
    buf += rhs;
    return sokrout(buf.get_integ(), buf.get_nat());
}
Rational operator+(const Rational &lhs, const int32_t &rhs) noexcept{
    Rational buf = lhs;
    buf += rhs;
    return sokrout(buf.get_integ(), buf.get_nat());
}
Rational operator+(const int32_t &lhs, const Rational &rhs) noexcept{
    Rational buf = rhs;
    buf += lhs;
    return sokrout(buf.get_integ(), buf.get_nat());
}

// -
Rational operator-(const Rational &lhs, const Rational &rhs) noexcept{
    Rational buf = lhs;
    buf -= rhs;
    return sokrout(buf.get_integ(), buf.get_nat());
}
Rational operator-(const Rational &lhs, const int32_t &rhs) noexcept{
    Rational buf = lhs;
    buf -= rhs;
    return sokrout(buf.get_integ(), buf.get_nat());
}
Rational operator-(const int32_t &lhs, const Rational &rhs) noexcept{
    Rational buf = rhs;
    buf -= lhs;
    return sokrout(-buf.get_integ(), buf.get_nat());
}

// *
Rational operator*(const Rational &lhs, const Rational &rhs) noexcept{
    Rational buf = lhs;
    buf *= rhs;
    return sokrout(buf.get_integ(), buf.get_nat());
}
Rational operator*(const Rational &lhs, const int32_t &rhs) noexcept{
    Rational buf = lhs;
    buf *= rhs;
    return sokrout(buf.get_integ(), buf.get_nat());
}
Rational operator*(const int32_t &lhs, const Rational &rhs) noexcept{
    Rational buf = rhs;
    buf *= lhs;
    return sokrout(buf.get_integ(), buf.get_nat());
}

// /
Rational operator/(const Rational &lhs, const Rational &rhs) noexcept{
    Rational buf = lhs;
    buf /= rhs;
    return sokrout(buf.get_integ(), buf.get_nat());
}
Rational operator/(const Rational &lhs, const int32_t &rhs) noexcept{
    Rational buf = lhs;
    buf /= rhs;
    return sokrout(buf.get_integ(), buf.get_nat());
}
Rational operator/(const int32_t &lhs, const Rational &rhs) noexcept{
    Rational buf = rhs;
    buf /= lhs;
    return sokrout(buf.get_nat(), buf.get_integ());
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
            out << -integ;
        }
        else
        {
            if ((nat < 0 && integ > 0) || (nat < 0 && integ < 0))
            {
                out << -integ << Separator << -nat;
            }
            if ((nat > 0 && integ < 0) || (nat > 0 && integ > 0))
            {
                out << integ << Separator << nat;
            }
        }
    }
    return out;
}

std::istream& Rational::Readfrom(std::istream& in) noexcept {
    int32_t integin{0};
    int32_t natin{0};
    char Separatorin{'/'};

    in >> integin >> Separatorin >> natin;

    if (in.good() || in.eof()){
        if (Separatorin==Rational::Separator){
            integ = integin;
            nat = natin;
        }
        else{
            std::cout << "ERROR! Please write like Z/N" << std::endl;
            std::cout << "Z - integer numbers" << std::endl;
            std::cout << "N - natural numbers" << std::endl;
        }
    }
    return in;
}
