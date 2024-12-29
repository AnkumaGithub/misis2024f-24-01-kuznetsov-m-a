#include <complex/complex.hpp>
#include <iostream>
#include <sstream>
#include <cstdint>

// numbers definition
double re = 0.0;
double im = 0.0;

// bool operators definition
bool Complex::operator==(const Complex& rhs) const noexcept
{
    return abs(re - rhs.re) < 2 * std::numeric_limits<double>::epsilon()  &&
        abs(im - rhs.im) < 2 * std::numeric_limits<double>::epsilon();
};
bool Complex::operator!=(const Complex& rhs) const noexcept
{
    return !operator==(rhs);
};

// += -= *= /= operators definition
Complex Complex::operator-() const noexcept { return {-re, -im}; }

Complex& Complex::operator+=(const Complex& rhs) noexcept {
    re += rhs.re;
    im += rhs.im;
    return *this;
}
Complex& Complex::operator+=(const double rhs) noexcept {
    return operator+=(Complex(rhs));
}
 
Complex& Complex::operator-=(const Complex& rhs) noexcept {
    re -= rhs.re;
    im -= rhs.im;
    return *this;
}
Complex& Complex::operator-=(const double rhs) noexcept {
    return operator-=(Complex(rhs));
}
 
Complex& Complex::operator*=(const Complex& rhs) noexcept {
    const double zre = re;
    re = re * rhs.re - im * rhs.im;
    im = zre * rhs.im + rhs.re * im;
    return *this;
}
Complex& Complex::operator*=(const double rhs) noexcept {
    return operator*=(Complex(rhs));
}

Complex& Complex::operator/=(const Complex& rhs){
    const double s = pow(rhs.re, 2) + pow(rhs.im, 2);
    if (s == 0)
    {
        throw std::invalid_argument("devide by zero");
    }
    const double zre = re;
    re = (re * rhs.re + im * rhs.im) / (s);
    im =  (im * rhs.re - zre * rhs.im) / (s);
    return *this;
}
Complex& Complex::operator/=(const double rhs){
    return operator/=(Complex(rhs));
}

// + - * / operators definition
Complex operator+(const Complex& lhs, const Complex& rhs) noexcept {
    return Complex(lhs) += rhs;
}
Complex operator+(const Complex& lhs, const double rhs) noexcept {
    return Complex(lhs) += rhs;
}
Complex operator+(const double rhs, const Complex& lhs) noexcept {
    return Complex(lhs) += rhs;
}

Complex operator-(const Complex& lhs, const Complex& rhs) noexcept {
    return Complex(lhs) -= rhs;
}
Complex operator-(const Complex& lhs, const double rhs) noexcept {
    return Complex(lhs) -= rhs;
}
Complex operator-(const double rhs, const Complex& lhs) noexcept {
    return Complex(lhs) -= rhs;
}

Complex operator*(const Complex& lhs, const Complex& rhs) noexcept {
    return Complex(lhs) *= rhs;
}
Complex operator*(const Complex& lhs, const double rhs) noexcept {
    return Complex(lhs) *= rhs;
}
Complex operator*(const double rhs, const Complex& lhs) noexcept {
    return Complex(lhs) *= rhs;
}

Complex operator/(const Complex& lhs, const Complex& rhs){
    return Complex(lhs) /= rhs;
}
Complex operator/(const Complex& lhs, const double rhs){
    return Complex(lhs) /= rhs;
}
Complex operator/(const double rhs, const Complex& lhs){
    return Complex(lhs) /= rhs;
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
    if (!in.good() && !in.eof()) {std::cerr << "Invalid input." << std::endl;}
    return in;
}
