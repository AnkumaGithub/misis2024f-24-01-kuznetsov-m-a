#include <iostream>
#include <arrayd/arrayd.hpp>

int main() {
    ArrayD A(10);
    A[2] = 1;
    double b = A[2];
    std::cout << "b -> " << b << std::endl;
}