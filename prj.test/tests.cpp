#include <StructComplex/StructComplex.hpp>
#include <iostream>
#include <sstream>

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