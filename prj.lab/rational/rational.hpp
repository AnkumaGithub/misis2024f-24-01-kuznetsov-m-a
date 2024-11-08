#ifndef RATION
#define RATION
#include <iosfwd>
#include <sstream>
#include <iostream>

struct Ration {
    int32_t integ = 0;
    int32_t nat = 1;

    Ration() = default;
    Ration(Ration&&) = default;
    explicit Ration(const int32_t lhs) : integ(lhs) {}
    Ration(const int32_t lhs, const int32_t rhs) : integ(lhs), nat(rhs) {}

    Ration& operator=(const Ration&) = default;
    Ration& operator=(Ration&&) = default;

    bool operator==(const Ration &rhs) const noexcept;
    bool operator==(const int32_t &rhs) const noexcept;

    bool operator!=(const Ration &rhs) const noexcept;
    bool operator!=(const int32_t &rhs) const noexcept;

    bool operator>=(const Ration &rhs) const noexcept;
    bool operator>=(const int32_t &rhs) const noexcept;

    bool operator<=(const Ration &rhs) const noexcept;
    bool operator<=(const int32_t &rhs) const noexcept;

    bool operator>(const Ration &rhs) const noexcept;
    bool operator>(const int32_t &rhs) const noexcept;

    bool operator<(const Ration &rhs) const noexcept;
    bool operator<(const int32_t &rhs) const noexcept;

    Ration& operator+=(const Ration &rhs) noexcept;
    Ration& operator+=(const int32_t &rhs) noexcept;

    Ration& operator-=(const Ration &rhs) noexcept;
    Ration& operator-=(const int32_t &rhs) noexcept;

    Ration& operator*=(const Ration &rhs) noexcept;
    Ration& operator*=(const int32_t &rhs) noexcept;

    Ration& operator/=(const Ration &rhs) noexcept;
    Ration& operator/=(const int32_t &rhs) noexcept;

    std::ostream& writeto(std::ostream& outs) const noexcept;
    std::istream& readfrom(std::istream& ins) noexcept;

    static const char Separator{'/'};
};

Ration operator+=(const int32_t &lhs, const Ration &rhs) noexcept;
Ration operator-=(const int32_t &lhs, const Ration &rhs) noexcept;
Ration operator*=(const int32_t &lhs, const Ration &rhs) noexcept;
Ration operator/=(const int32_t &lhs, const Ration &rhs) noexcept;

Ration operator+(const Ration &lhs, const Ration &rhs) noexcept;
Ration operator+(const Ration &lhs, const int32_t &rhs) noexcept;
Ration operator+(const int32_t &lhs, const Ration &rhs) noexcept;

Ration operator-(const Ration &lhs, const Ration &rhs) noexcept;
Ration operator-(const Ration &lhs, const int32_t &rhs) noexcept;
Ration operator-(const int32_t &lhs, const Ration &rhs) noexcept;

Ration operator*(const Ration &lhs, const Ration &rhs) noexcept;
Ration operator*(const Ration &lhs, const int32_t &rhs) noexcept;
Ration operator*(const int32_t &lhs, const Ration &rhs) noexcept;

Ration operator/(const Ration &lhs, const Ration &rhs) noexcept;
Ration operator/(const Ration &lhs, const int32_t &rhs) noexcept;
Ration operator/(const int32_t &lhs, const Ration &rhs) noexcept;

int64_t NOD(int32_t up, int32_t low);

inline std::ostream& operator<<(std::ostream& out,const Ration& rhs) noexcept {
    return rhs.writeto(out);
}
inline std::istream& operator>>(std::istream& in,Ration& rhs) noexcept {
    return rhs.readfrom(in);
}

#endif


