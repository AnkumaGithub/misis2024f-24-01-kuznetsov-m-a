#ifndef COMPLEX_HPP
#define COMPLEX_HPP

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

    Complex operator-() const noexcept;

    bool operator==(const Complex& rhs) const noexcept;
    bool operator!=(const Complex& rhs) const noexcept;

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
    std::ostream& writeTo(std::ostream& outstream) const noexcept;
    std::istream& readFrom(std::istream& instream) noexcept;
};

//Postfix operators definition
Complex operator+(const Complex& lhs, const Complex& rhs) noexcept;
Complex operator+(const Complex& lhs, const double rhs)noexcept;
Complex operator+(const double rhs, const Complex& lhs)noexcept;
 
Complex operator-(const Complex& lhs, const Complex& rhs)noexcept;
Complex operator-(const Complex& lhs, const double rhs)noexcept;
Complex operator-(const double rhs, const Complex& lhs)noexcept;
 
Complex operator*(const Complex& lhs, const Complex& rhs)noexcept;
Complex operator*(const Complex& lhs, const double rhs)noexcept;
Complex operator*(const double rhs, const Complex& lhs)noexcept;

Complex operator/(const Complex& lhs, const Complex& rhs);
Complex operator/(const Complex& lhs, const double rhs);
Complex operator/(const double rhs, const Complex& lhs);

inline std::ostream& operator<<(std::ostream& out,const Complex& rhs) noexcept {
    return rhs.writeTo(out);
}
//Istream definition
inline std::istream& operator>>(std::istream& in,Complex& rhs) noexcept {
    return rhs.readFrom(in);
}
 
#endif
