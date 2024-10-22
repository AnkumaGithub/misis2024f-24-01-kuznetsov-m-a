#include <StructComplex.hpp>
#include <iostream>
#include <sstream>

// Struct initialization
//re & im initialization
double re = 0.0;
double im = 0.0;
//literals initialization
static const char LeftPart{'{'};
static const char Separator{','};
static const char RightPart{'}'};

bool Complex::operator==(const Complex& rhs) const noexcept {return (re == rhs.re) && (im == rhs.im);};
bool Complex::operator!=(const Complex& rhs) const noexcept {return (re != rhs.re) || (im != rhs.im);};

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

//Postfix operators definition
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
    return Complex(lhs.re - rhs, lhs.im);
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
    return Complex(lhs.re / rhs, lhs.im / rhs);
}

//Outstream definition
std::ostream& Complex::writeTo(std::ostream& out) const noexcept{
    out << LeftPart << re << Separator << im << RightPart;
    return out;
}

std::istream& Complex::readFrom(std::istream& in) noexcept {
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
};
 
bool test(std::string st){
    Complex z;
    std::istringstream istr(st);
    istr >> z;
    if (istr.good()){
        std::cout << "Success: " << st << "->" << z;
    }
    else{
        std::cout << "Unreadable! Please write like {8.7, 9.6}";
    }
    return istr.good();
}
int main(){
    Complex z, g, b1, b2, b3, b4;
    g = {700, -6};
    std::cout << "Cin and Cout test:" << std::endl;
    std::cin >> z;
    std::cout << z;

    std::cout << std::endl << "+ test:";
    std::cout << z + g << " " << 1 + g << " " << g + 1;
    std::cout << std::endl << "+= test:";
    b1 = z;
    b1 += g;
    std::cout << b1;

    std::cout << std::endl << "- test:";
    std::cout << z - g << " " << 1 - g << " " << g - 1;
    std::cout << std::endl << "-= test:";
    b2 = z;
    b2 -= g;
    std::cout << b2;

    std::cout << std::endl << "* test:";
    std::cout << z * g << 10 * g << g * 10; 
    std::cout << std::endl << "*= test:";
    b3 = z;
    b3 *= g;
    std::cout << b3;

    std::cout << std::endl << "/ test:";
    std::cout << z / g << 10 / g << g / 10;
    std::cout << std::endl << "/= test:";
    b4 = z;
    b4 /= g;
    std::cout << b4;

    std::cout << std::endl << "1 test: ";
    test("{8.7, 9.3}"); //normal (1)

    std::cout << std::endl << "2 test: ";
    test("{8.7 9.3}"); //without separator(2)

    std::cout << std::endl << "3 test: ";
    test("8.7, 9.3}"); //without left brace (3)

    std::cout << std::endl << "4 test: ";
    test("{8.7, 9.3"); //without right brace (4)

    std::cout << std::endl << "5 test: ";
    test("{8.7,9.3}"); //without spacing (5)

    std::cout << std::endl << "6 test: ";
    test("{8.7,  9.3}"); //with one more spacing (6)

    std::cout << std::endl << "7 test: ";
    test("{8.7, 9.}"); //without right part of double number (7)

    std::cout << std::endl << "8 test: ";
    test("{8.7, .3}"); //without left part of double nuber (8)

    std::cout << std::endl << "9 test: ";
    test("{8, 9.3}"); //int and double (9)

    std::cout << std::endl << "10 test: ";
    test("{8.7, 9}"); //double and int (10)

    std::cout << std::endl << "11 test: ";
    test("{8, 9}"); //int and int (11)

    std::cout << std::endl << "12 test: ";
    test("{8.7, }"); //without one number (12)

    std::cout << std::endl << "13 test: ";
    test("{ , }"); //without two numbers (13)

    std::cout << std::endl << "14 test: ";
    test("{ }"); //without numbers and separator (14)
}
