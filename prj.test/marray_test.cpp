#include <iostream>
#include <marray/marray.hpp>

int main() {
    Marray<int> A(10);
    A[2] = 1;
    int b = A[2];
    std::cout << "b = " << b << std::endl;
}