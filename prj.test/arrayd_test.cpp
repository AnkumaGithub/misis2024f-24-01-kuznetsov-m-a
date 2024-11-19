#include <iostream>
#include <arrayd/arrayd.hpp>

int main() {
    Arrayd<int> A(10);
    A[2] = 1;
    int b = A[2];
    std::cout << "b = " << b << std::endl;
}