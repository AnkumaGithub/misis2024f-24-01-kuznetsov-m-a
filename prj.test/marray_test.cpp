#include <iostream>
#include <marray/marray.hpp>

int main() {
    Marray A(10);
    A[2] = 1;
    int b = A[2];
    std::cout << "b = " << b << std::endl;
}