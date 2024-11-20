#ifndef RATION
#define RATION
#include <iosfwd>
#include <sstream>
#include <iostream>
#include <cstdint>

class Rational {
private:
    int32_t integ = 0;
    int32_t nat = 1;

    inline void sokrin();

public:
    Rational() = default;
    Rational(const Rational&) = default;
    Rational(Rational&&) = default;
    explicit Rational(const int32_t lhs) : integ(lhs) {}
    Rational(const int32_t lhs, const int32_t rhs) : integ(lhs), nat(rhs) {}

    ~Rational() = default;

    Rational& operator=(const Rational&) = default;
    Rational& operator=(Rational&&) = default;

    Rational operator-() const noexcept;

    [[nodiscard]] int32_t get_integ() const noexcept {return integ;}
    [[nodiscard]] int32_t get_nat() const noexcept {return nat;}

    bool operator==(const Rational &rhs) const noexcept;
    bool operator==(const int32_t &rhs) const noexcept;

    bool operator!=(const Rational &rhs) const noexcept;
    bool operator!=(const int32_t &rhs) const noexcept;

    bool operator>=(const Rational &rhs) const noexcept;
    bool operator>=(const int32_t &rhs) const noexcept;

    bool operator<=(const Rational &rhs) const noexcept;
    bool operator<=(const int32_t &rhs) const noexcept;

    bool operator>(const Rational &rhs) const noexcept;
    bool operator>(const int32_t &rhs) const noexcept;

    bool operator<(const Rational &rhs) const noexcept;
    bool operator<(const int32_t &rhs) const noexcept;

    Rational& operator+=(const Rational &rhs) noexcept;
    Rational& operator+=(const int32_t &rhs) noexcept;

    Rational& operator-=(const Rational &rhs) noexcept;
    Rational& operator-=(const int32_t &rhs) noexcept;

    Rational& operator*=(const Rational &rhs) noexcept;
    Rational& operator*=(const int32_t &rhs) noexcept;

    Rational& operator/=(const Rational &rhs) noexcept;
    Rational& operator/=(const int32_t &rhs) noexcept;

    std::ostream& Writeto(std::ostream& outs) const noexcept;
    std::istream& Readfrom(std::istream& ins) noexcept;

    static const char Separator{'/'};
};

int32_t NOD(int32_t up, int32_t low);

Rational sokrout(int32_t up, int32_t low);

Rational operator+=(const int32_t &lhs, const Rational &rhs) noexcept;
Rational operator-=(const int32_t &lhs, const Rational &rhs) noexcept;
Rational operator*=(const int32_t &lhs, const Rational &rhs) noexcept;
Rational operator/=(const int32_t &lhs, const Rational &rhs) noexcept;

Rational operator+(const Rational &lhs, const Rational &rhs) noexcept;
Rational operator+(const Rational &lhs, const int32_t &rhs) noexcept;
Rational operator+(const int32_t &lhs, const Rational &rhs) noexcept;

Rational operator-(const Rational &lhs, const Rational &rhs) noexcept;
Rational operator-(const Rational &lhs, const int32_t &rhs) noexcept;
Rational operator-(const int32_t &lhs, const Rational &rhs) noexcept;

Rational operator*(const Rational &lhs, const Rational &rhs) noexcept;
Rational operator*(const Rational &lhs, const int32_t &rhs) noexcept;
Rational operator*(const int32_t &lhs, const Rational &rhs) noexcept;

Rational operator/(const Rational &lhs, const Rational &rhs) noexcept;
Rational operator/(const Rational &lhs, const int32_t &rhs) noexcept;
Rational operator/(const int32_t &lhs, const Rational &rhs) noexcept;

inline std::ostream& operator<<(std::ostream& out,const Rational& rhs) noexcept {
    return rhs.Writeto(out);
}
inline std::istream& operator>>(std::istream& in,Rational& rhs) noexcept {
    return rhs.Readfrom(in);
}

#endif


