#include "rational.hpp"
#include <iostream>
#include <sstream>

// bool operators
// ==
bool Ration::operator==(const Ration &rhs) const noexcept{
    return integ == rhs.integ && nat == rhs.nat;
}
bool Ration::operator==(const int32_t &rhs) const noexcept{
    return integ == rhs && nat == rhs;
}

// !=
bool Ration::operator!=(const Ration &rhs) const noexcept{
    return integ != rhs.integ || nat != rhs.nat;
}
bool Ration::operator!=(const int32_t &rhs) const noexcept{
    return integ != rhs || nat != rhs;
}

// >=
bool Ration::operator>=(const Ration &rhs) const noexcept{
    return double(integ / nat) >= double(rhs.integ / rhs.nat);
}
bool Ration::operator>=(const int32_t &rhs) const noexcept{
    return double(integ / nat) >= rhs;
}

// <=
bool Ration::operator<=(const Ration &rhs) const noexcept{
    return double(integ / nat) <= double(rhs.integ / rhs.nat);
}
bool Ration::operator<=(const int32_t &rhs) const noexcept{
    return double(integ / nat) <= rhs;
}

// >
bool Ration::operator>(const Ration &rhs) const noexcept{
    return double(integ / nat) > double(rhs.integ / rhs.nat);
}
bool Ration::operator>(const int32_t &rhs) const noexcept{
    return double(integ / nat) > rhs;
}

// <
bool Ration::operator<(const Ration &rhs) const noexcept{
    return double(integ / nat) < double(rhs.integ / rhs.nat);
}
bool Ration::operator<(const int32_t &rhs) const noexcept{
    return double(integ / nat) < rhs;
}

// += -= *= /= operators 
// +=
Ration& Ration::operator+=(const Ration &rhs) noexcept{
    integ = rhs.integ * nat + integ * rhs.nat;
    nat = rhs.nat * nat;
    return *this;
}
Ration& Ration::operator+=(const int32_t &rhs) noexcept{
    integ += rhs * nat;
    return *this;
}
Ration operator+=(const int32_t &lhs, const Ration &rhs) noexcept{
    return Ration(lhs * rhs.nat + rhs.integ, rhs.nat);
}

// -=
Ration& Ration::operator-=(const Ration &rhs) noexcept{
    integ = rhs.integ * nat + integ * rhs.nat;
    nat = rhs.nat * nat;
    return *this;
}
Ration& Ration::operator-=(const int32_t &rhs) noexcept{
    integ -= rhs * nat;
    return *this;
}
Ration operator-=(const int32_t lhs, const Ration &rhs) noexcept{
    return Ration(lhs * rhs.nat - rhs.integ, rhs.nat);
}

// *=
Ration& Ration::operator*=(const Ration &rhs) noexcept{
    integ = integ * rhs.integ;
    nat = nat * rhs.nat;
    return *this;
}
Ration& Ration::operator*=(const int32_t &rhs) noexcept{
    integ = integ * rhs;
    return *this;
}
Ration operator*=(const int32_t &lhs, const Ration &rhs) noexcept{
    return Ration(lhs * rhs.integ, rhs.nat);
}

// /=
Ration& Ration::operator/=(const Ration &rhs) noexcept{
    integ = integ * rhs.nat;
    nat = nat * rhs.integ;
    return *this;
}
Ration& Ration::operator/=(const int32_t &rhs) noexcept{
    nat = nat * rhs;
    return *this;
}
Ration operator/=(const int32_t &lhs, const Ration &rhs) noexcept{
    return Ration(lhs * rhs.nat, rhs.integ);
}

//+ - * / operators
// +
Ration operator+(const Ration &lhs, const Ration &rhs) noexcept{
    return Ration(lhs.integ * rhs.nat + rhs.integ * lhs.nat
    , lhs.nat * rhs.nat);
}
Ration operator+(const Ration &lhs, const int32_t &rhs) noexcept{
    return Ration(lhs.integ + lhs.nat * rhs
    , lhs.nat);
}
Ration operator+(const int32_t &lhs, const Ration &rhs) noexcept{
    return Ration(rhs.integ + lhs * rhs.nat
    , rhs.nat);
}

// -
Ration operator-(const Ration &lhs, const Ration &rhs) noexcept{
    return Ration(lhs.integ * rhs.nat - rhs.integ * lhs.nat
    , lhs.nat * rhs.nat);
}
Ration operator-(const Ration &lhs, const int32_t &rhs) noexcept{
    return Ration(lhs.integ - lhs.nat * rhs
    , lhs.nat);
}
Ration operator-(const int32_t &lhs, const Ration &rhs) noexcept{
    return Ration(rhs.integ - lhs * rhs.nat
    , rhs.nat);
}

// *
Ration operator*(const Ration &lhs, const Ration &rhs) noexcept{
    return Ration(lhs.integ * rhs.integ
    , lhs.nat * rhs.nat);
}
Ration operator*(const Ration &lhs, const int32_t &rhs) noexcept{
    return Ration(lhs.integ * rhs
    , lhs.nat);
}
Ration operator*(const int32_t &lhs, const Ration &rhs) noexcept{
    return Ration(lhs * rhs.integ
    , rhs.nat);
}

// /
Ration operator/(const Ration &lhs, const Ration &rhs) noexcept{
    return Ration(lhs.integ * rhs.nat
    , lhs.nat * rhs.integ);
}
Ration operator/(const Ration &lhs, const int32_t &rhs) noexcept{
    return Ration(lhs.integ
    , lhs.nat * rhs);
}
Ration operator/(const int32_t &lhs, const Ration &rhs) noexcept{
    return Ration(lhs * rhs.nat
    , rhs.integ);
}

int64_t NOD(int32_t up, int32_t low) {
    while (up && low)
        if (up > low) up %= low;
        else low %= up;
    return up + low;
}

std::ostream& operator<<(std::ostream out, const Ration rhs) noexcept{
    return rhs.writeto(out);
}
std::istream& operator>>(std::istream in,Ration rhs) noexcept{
    return rhs.readfrom(in);
}

std::ostream& Ration::writeto(std::ostream& out) const noexcept {
    int32_t nod = NOD(integ, nat);
    out << integ / nod << Separator << nat / nod;
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
            std::cout << "ERROR! Please write like {Z/N}" << std::endl;
            std::cout << "Z - integer numbers" << std::endl;
            std::cout << "N - natural numbers" << std::endl;
        }
    }
    return in;
}