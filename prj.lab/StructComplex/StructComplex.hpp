#ifndef COMPLEX
#define COMPLEX

#include <iostream>
#include <iosfwd>
#include <sstream>
struct Complex {
    // Struct initialization
    Complex() = default;
    Complex(Complex&&) = default;
    explicit Complex(const double real) : re(real) {}
    Complex(const double real, const double imag) : re(real), im(imag) {}

    Complex& operator=(const Complex&) = default;

    Complex& operator=(Complex&&) = default;

    //! Деструктор.
    ~Complex() = default;

    [[nodiscard]] Complex operator-() const noexcept;

    [[nodiscard]] bool operator==(const Complex& rhs) const noexcept;
    [[nodiscard]] bool operator!=(const Complex& rhs) const noexcept;

    Complex& operator+=(const Complex& rhs) noexcept;
    Complex& operator+=(const double rhs) noexcept;

    Complex& operator-=(const Complex& rhs) noexcept;
    Complex& operator-=(const double rhs) noexcept;

    Complex& operator*=(const Complex& rhs) noexcept;
    Complex& operator*=(const double rhs) noexcept;

    Complex& operator/=(const Complex& rhs);
    Complex& operator/=(const double rhs);

    //re & im initialization
    double re = 0.0;
    double im = 0.0;
    //literals initialization
    static const char LeftPart{'{'};
    static const char Separator{','};
    static const char RightPart{'}'};
    //streams initialization
    [[nodiscard]] std::ostream& writeTo(std::ostream& outstream) const noexcept;
    [[nodiscard]] std::istream& readFrom(std::istream& instream) noexcept;
};

//Postfix operators definition
[[nodiscard]] Complex operator+(const Complex& lhs, const Complex& rhs) noexcept;
[[nodiscard]] Complex operator+(const Complex& lhs, const double rhs)noexcept;
[[nodiscard]] Complex operator+(const double rhs, const Complex& lhs)noexcept;
 
[[nodiscard]] Complex operator-(const Complex& lhs, const Complex& rhs)noexcept;
[[nodiscard]] Complex operator-(const Complex& lhs, const double rhs)noexcept;
[[nodiscard]] Complex operator-(const double rhs, const Complex& lhs)noexcept;
 
[[nodiscard]] Complex operator*(const Complex& lhs, const Complex& rhs)noexcept;
[[nodiscard]] Complex operator*(const Complex& lhs, const double rhs)noexcept;
[[nodiscard]] Complex operator*(const double rhs, const Complex& lhs)noexcept;

[[nodiscard]] Complex operator/(const Complex& lhs, const Complex& rhs)noexcept;
[[nodiscard]] Complex operator/(const Complex& lhs, const double rhs)noexcept;
[[nodiscard]] Complex operator/(const double rhs, const Complex& lhs)noexcept;

std::ostream& operator<<(std::ostream& out,const Complex& rhs) noexcept {
    return rhs.writeTo(out);
}
//Istream definition
std::istream& operator>>(std::istream& in,Complex& rhs) noexcept {
    return rhs.readFrom(in);
}
 
#endif
