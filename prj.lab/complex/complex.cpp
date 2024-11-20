#include <complex/complex.hpp>
#include <iostream>
#include <sstream>
#include <cstdint>

// numbers definition
double re = 0.0;
double im = 0.0;

// bool operators definition
bool Complex::operator==(const Complex& rhs) const noexcept {return (re == rhs.re) && (im == rhs.im);};
bool Complex::operator!=(const Complex& rhs) const noexcept {return (re != rhs.re) || (im != rhs.im);};

// += -= *= /= operators definition
Complex Complex::operator-() const noexcept { return Complex(-re, -im); }

Complex& Complex::operator+=(const Complex& rhs) noexcept {
    re += rhs.re;
    im += rhs.im;
    return *this;
}
Complex& Complex::operator+=(const double rhs) noexcept {
    re += rhs;
    return *this;
}
 
Complex& Complex::operator-=(const Complex& rhs) noexcept {
    re -= rhs.re;
    im -= rhs.im;
    return *this;
}
Complex& Complex::operator-=(const double rhs) noexcept {
    re -= rhs;
    return *this;
}
 
Complex& Complex::operator*=(const Complex& rhs) noexcept {
    double zre = re;
    re = re * rhs.re - im * rhs.im;
    im = zre * rhs.im + rhs.re * im;
    return *this;
}
Complex& Complex::operator*=(const double rhs) noexcept {
    re *= rhs;
    return *this;
}

Complex& Complex::operator/=(const Complex& rhs){
    double zre = re;
    re = (re * rhs.re + im * rhs.im) / (rhs.re * rhs.re + rhs.im * rhs.im);
    im =  (im * rhs.re - zre * rhs.im) / (rhs.re * rhs.re + rhs.im * rhs.im);
    return *this;
}
Complex& Complex::operator/=(const double rhs){
    re /= rhs;
    return *this;
}

// + - * / operators definition
Complex operator+(const Complex& lhs, const Complex& rhs) noexcept {
    return Complex(lhs.re + rhs.re, lhs.im + rhs.im);
}
Complex operator+(const Complex& lhs, const double rhs) noexcept {
    return Complex(lhs.re + rhs, lhs.im);
}
Complex operator+(const double rhs, const Complex& lhs) noexcept {
    return Complex(lhs.re + rhs, lhs.im);
}

Complex operator-(const Complex& lhs, const Complex& rhs) noexcept {
    return Complex(lhs.re - rhs.re, lhs.im - rhs.im);
}
Complex operator-(const Complex& lhs, const double rhs) noexcept {
    return Complex(lhs.re - rhs, lhs.im);
}
Complex operator-(const double rhs, const Complex& lhs) noexcept {
    return Complex(rhs - lhs.re, -lhs.im);
}

Complex operator*(const Complex& lhs, const Complex& rhs) noexcept {
    return Complex(lhs.re * rhs.re - lhs.im * rhs.im, lhs.re * rhs.im + rhs.re * lhs.im);
}
Complex operator*(const Complex& lhs, const double rhs) noexcept {
    return Complex(lhs.re * rhs, lhs.im * rhs);
}
Complex operator*(const double rhs, const Complex& lhs) noexcept {
    return Complex(lhs.re * rhs, lhs.im * rhs);
}

Complex operator/(const Complex& lhs, const Complex& rhs){
    return Complex((lhs.re * rhs.re + lhs.im * rhs.im) / (rhs.re * rhs.re + rhs.im * rhs.im),
    (lhs.im * rhs.re - lhs.re * rhs.im) / (rhs.re * rhs.re + rhs.im * rhs.im));
}
Complex operator/(const Complex& lhs, const double rhs){
    return Complex(lhs.re / rhs, lhs.im / rhs);
}
Complex operator/(const double rhs, const Complex& lhs){
    return Complex(rhs / lhs.re, rhs / lhs.im);
}

// streams sdefinition
std::ostream& Complex::WriteTo(std::ostream& out) const noexcept{
    out << LeftPart << re << Separator << im << RightPart;
    return out;
}

std::istream& Complex::ReadFrom(std::istream& in) noexcept {
    char LeftPartIn(0);
    double realIn(0.0);
    char SeparatorIn(0);
    double imagIn(0.0);
    char RightPartIn(0);
    in >> LeftPartIn >> realIn >> SeparatorIn >> imagIn >> RightPartIn;
    if(in.good()){
        if (LeftPartIn == Complex::LeftPart && SeparatorIn == Complex::Separator && RightPartIn == Complex::RightPart){
            Complex::re = realIn;
            Complex::im = imagIn;
        }
        else{
            in.setstate(std::ios_base::failbit);
        }
    }
    return in;
}
