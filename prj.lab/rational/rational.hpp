#ifndef RATION
#define RATION
#include <iosfwd>
#include <sstream>
#include <iostream>

struct Ration {
    int integ = 0;
    int nat = 0;

    Ration() = default;
    Ration(Ration&&) = default;
    explicit Ration(const int lhs) : integ(lhs) {}
    Ration(const int lhs, const int rhs) : integ(lhs), nat(rhs) {}

    Ration& operator=(const Ration&) = default;
    Ration& operator=(Ration&&) = default;

    bool operator==(const Ration &rhs) const noexcept;
    bool operator==(const int &rhs) const noexcept;

    bool operator!=(const Ration &rhs) const noexcept;
    bool operator!=(const int &rhs) const noexcept;

    bool operator>=(const Ration &rhs) const noexcept;
    bool operator>=(const int &rhs) const noexcept;

    bool operator<=(const Ration &rhs) const noexcept;
    bool operator<=(const int &rhs) const noexcept;

    bool operator>(const Ration &rhs) const noexcept;
    bool operator>(const int &rhs) const noexcept;

    bool operator<(const Ration &rhs) const noexcept;
    bool operator<(const int &rhs) const noexcept;

    Ration& operator+=(const Ration &rhs) noexcept;
    Ration& operator+=(const int &rhs) noexcept;

    Ration& operator-=(const Ration &rhs) noexcept;
    Ration& operator-=(const int &rhs) noexcept;

    Ration& operator*=(const Ration &rhs) noexcept;
    Ration& operator*=(const int &rhs) noexcept;

    Ration& operator/=(const Ration &rhs) noexcept;
    Ration& operator/=(const int &rhs) noexcept;

    std::ostream& writeto(std::ostream& outs) const noexcept;
    std::istream& readfrom(std::istream& ins) noexcept;

    static const char LeftPart{'{'};
    static const char Separator{'/'};
    static const char RightPart{'}'};
};

Ration operator+=(const int &lhs, const Ration &rhs) noexcept;
Ration operator-=(const int &lhs, const Ration &rhs) noexcept;
Ration operator*=(const int &lhs, const Ration &rhs) noexcept;
Ration operator/=(const int &lhs, const Ration &rhs) noexcept;

Ration operator+(const Ration &lhs, const Ration &rhs) noexcept;
Ration operator+(const Ration &lhs, const int &rhs) noexcept;
Ration operator+(const int &lhs, const Ration &rhs) noexcept;

Ration operator-(const Ration &lhs, const Ration &rhs) noexcept;
Ration operator-(const Ration &lhs, const int &rhs) noexcept;
Ration operator-(const int &lhs, const Ration &rhs) noexcept;

Ration operator*(const Ration &lhs, const Ration &rhs) noexcept;
Ration operator*(const Ration &lhs, const int &rhs) noexcept;
Ration operator*(const int &lhs, const Ration &rhs) noexcept;

Ration operator/(const Ration &lhs, const Ration &rhs) noexcept;
Ration operator/(const Ration &lhs, const int &rhs) noexcept;
Ration operator/(const int &lhs, const Ration &rhs) noexcept;

inline std::ostream& operator<<(std::ostream& out,const Ration& rhs) noexcept {
    return rhs.writeto(out);
}
inline std::istream& operator>>(std::istream& in,Ration& rhs) noexcept {
    return rhs.readfrom(in);
}

#endif


