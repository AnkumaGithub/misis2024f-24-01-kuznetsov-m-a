#include "rational.hpp"
#include <iostream>
#include <sstream>


int32_t NOD(int32_t up, int32_t low)
{
    if (up == 0)
    {
        return low;
    }
    return NOD(low, up % low);
}

void Ration::sokrin()
{
    int32_t nod = NOD(abs(integ), abs(nat));
    integ = integ / nod;
    nat = nat / nod;
}

Ration sokrout(int32_t up, int32_t low)
{
    int32_t nod = NOD(abs(up), abs(low));
    return {up / nod, low / nod};
}

// bool operators
// ==
bool Ration::operator==(const Ration &rhs) const noexcept{
    return integ == rhs.integ && nat == rhs.nat;
}
bool Ration::operator==(const int32_t &rhs) const noexcept{
    return integ == rhs && nat == 1;
}

// !=
bool Ration::operator!=(const Ration &rhs) const noexcept{
    return integ != rhs.integ || nat != rhs.nat;
}
bool Ration::operator!=(const int32_t &rhs) const noexcept{
    return integ != rhs || nat != 1;
}

Ration Ration::operator-() const noexcept
{
    return {-integ, nat};
}

// >=
bool Ration::operator>=(const Ration &rhs) const noexcept{
    Ration z = Ration(integ, nat) - rhs;
    z.sokrin();
    if (z.integ >= 0) {return true;}
    else {return false;}
}
bool Ration::operator>=(const int32_t &rhs) const noexcept{
    Ration z = Ration(integ, nat) - Ration(rhs);
    z.sokrin();
    if (z.integ >= 0) {return true;}
    else {return false;}
}

// <=
bool Ration::operator<=(const Ration &rhs) const noexcept{
    Ration z = Ration(integ, nat) - rhs;
    z.sokrin();
    if (z.integ <= 0) {return true;}
    else {return false;}
}
bool Ration::operator<=(const int32_t &rhs) const noexcept{
    Ration z = Ration(integ, nat) - rhs;
    z.sokrin();
    if (z.integ <= 0) {return true;}
    else {return false;}
}

// >
bool Ration::operator>(const Ration &rhs) const noexcept{
    Ration z = Ration(integ, nat) - rhs;
    z.sokrin();
    if (z.integ > 0) {return true;}
    else {return false;}
}
bool Ration::operator>(const int32_t &rhs) const noexcept{
    Ration z = Ration(integ, nat) - rhs;
    z.sokrin();
    if (z.integ > 0) {return true;}
    else {return false;}
}

// <
bool Ration::operator<(const Ration &rhs) const noexcept{
    Ration z = Ration(integ, nat) - rhs;
    z.sokrin();
    if (z.integ < 0) {return true;}
    else {return false;}
}
bool Ration::operator<(const int32_t &rhs) const noexcept{
    Ration z = Ration(integ, nat) - rhs;
    z.sokrin();
    if (z.integ < 0) {return true;}
    else {return false;}
}

// += -= *= /= operators 
// +=
Ration& Ration::operator+=(const Ration &rhs) noexcept{
    integ = integ * rhs.nat + rhs.integ * nat;
    nat = rhs.nat * nat;
    this->sokrin();
    return *this;
}
Ration& Ration::operator+=(const int32_t &rhs) noexcept{
    integ += rhs * nat;
    this->sokrin();
    return *this;
}
Ration operator+=(const int32_t &lhs, const Ration &rhs) noexcept{
    Ration buf = rhs;
    buf += lhs;
    return sokrout(buf.get_integ(), buf.get_nat());
}

// -=
Ration& Ration::operator-=(const Ration &rhs) noexcept{
    integ = integ * rhs.nat - rhs.integ * nat;
    nat = rhs.nat * nat;
    this->sokrin();
    return *this;
}
Ration& Ration::operator-=(const int32_t &rhs) noexcept{
    integ -= rhs * nat;
    this->sokrin();
    return *this;
}
Ration operator-=(const int32_t lhs, const Ration &rhs) noexcept{
    Ration buf = rhs;
    buf -= lhs;
    return sokrout(buf.get_integ(), buf.get_nat());
}

// *=
Ration& Ration::operator*=(const Ration &rhs) noexcept{
    integ = integ * rhs.integ;
    nat = nat * rhs.nat;
    this->sokrin();
    return *this;
}
Ration& Ration::operator*=(const int32_t &rhs) noexcept{
    integ = integ * rhs;
    this->sokrin();
    return *this;
}
Ration operator*=(const int32_t &lhs, const Ration &rhs) noexcept{
    Ration buf = rhs;
    buf *= lhs;
    return sokrout(buf.get_integ(), buf.get_nat());
}

// /=
Ration& Ration::operator/=(const Ration &rhs) noexcept{
    integ = integ * rhs.nat;
    nat = nat * rhs.integ;
    this->sokrin();
    return *this;
}
Ration& Ration::operator/=(const int32_t &rhs) noexcept{
    nat = nat * rhs;
    this->sokrin();
    return *this;
}
Ration operator/=(const int32_t &lhs, const Ration &rhs) noexcept{
    Ration buf = rhs;
    buf /= lhs;
    return sokrout(buf.get_integ(), buf.get_nat());
}

//+ - * / operators
// +
Ration operator+(const Ration &lhs, const Ration &rhs) noexcept{
    Ration buf = lhs;
    buf += rhs;
    return sokrout(buf.get_integ(), buf.get_nat());
}
Ration operator+(const Ration &lhs, const int32_t &rhs) noexcept{
    Ration buf = lhs;
    buf += rhs;
    return sokrout(buf.get_integ(), buf.get_nat());
}
Ration operator+(const int32_t &lhs, const Ration &rhs) noexcept{
    Ration buf = rhs;
    buf += lhs;
    return sokrout(buf.get_integ(), buf.get_nat());
}

// -
Ration operator-(const Ration &lhs, const Ration &rhs) noexcept{
    Ration buf = lhs;
    buf -= rhs;
    return sokrout(buf.get_integ(), buf.get_nat());
}
Ration operator-(const Ration &lhs, const int32_t &rhs) noexcept{
    Ration buf = lhs;
    buf -= rhs;
    return sokrout(buf.get_integ(), buf.get_nat());
}
Ration operator-(const int32_t &lhs, const Ration &rhs) noexcept{
    Ration buf = rhs;
    buf -= lhs;
    return sokrout(buf.get_integ(), buf.get_nat());
}

// *
Ration operator*(const Ration &lhs, const Ration &rhs) noexcept{
    Ration buf = lhs;
    buf *= rhs;
    return sokrout(buf.get_integ(), buf.get_nat());
}
Ration operator*(const Ration &lhs, const int32_t &rhs) noexcept{
    Ration buf = lhs;
    buf *= rhs;
    return sokrout(buf.get_integ(), buf.get_nat());
}
Ration operator*(const int32_t &lhs, const Ration &rhs) noexcept{
    Ration buf = rhs;
    buf *= lhs;
    return sokrout(buf.get_integ(), buf.get_nat());
}

// /
Ration operator/(const Ration &lhs, const Ration &rhs) noexcept{
    Ration buf = lhs;
    buf /= rhs;
    return sokrout(buf.get_integ(), buf.get_nat());
}
Ration operator/(const Ration &lhs, const int32_t &rhs) noexcept{
    Ration buf = lhs;
    buf /= rhs;
    return sokrout(buf.get_integ(), buf.get_nat());
}
Ration operator/(const int32_t &lhs, const Ration &rhs) noexcept{
    Ration buf = rhs;
    buf /= lhs;
    return sokrout(buf.get_integ(), buf.get_nat());
}

std::ostream& operator<<(std::ostream out, const Ration rhs) noexcept{
    return rhs.writeto(out);
}
std::istream& operator>>(std::istream in,Ration rhs) noexcept{
    return rhs.readfrom(in);
}

std::ostream& Ration::writeto(std::ostream& out) const noexcept {
    if (integ == 0 or nat == 1)
    {
        out << integ;
    }
    else
    {
        if (nat == -1)
        {
            out << -integ;
        }
        else
        {
            if ((nat < 0 and integ > 0) or (nat < 0 and integ < 0))
            {
                out << -integ << Separator << -nat;
            }
            if ((nat > 0 and integ < 0) or (nat > 0 and integ > 0))
            {
                out << integ << Separator << nat;
            }
        }
    }
    return out;
}


std::istream& Ration::readfrom(std::istream& in) noexcept {
    int32_t integin{0};
    int32_t natin{0};
    char LeftPartin{'{'};
    char Separatorin{'/'};
    char RightPartin{'}'};

    in >> integin >> Separatorin >> natin;

    if (in.good()){
        if (Separatorin==Ration::Separator){
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