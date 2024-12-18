#include <iostream>
#include <arrayd/arrayd.hpp>

int main() {
    ArrayD A(10);
    A[0] = 10;
    A[1] = 7;
    A[2] = 1;
    A[9] = 111;
    A[8] = 333;
    double b = A[2];
    std::cout << "b -> " << b << std::endl;
    A.Insert(2,3);
    std::cout << "A[3] -> " << A[3] << " " << A[2] << std::endl;
    A.Remove(0);
    std::cout << A[0];

    A.Insert(9,5);
    std::cout << A[9] << " " << A[10];
}