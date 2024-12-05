#include <iostream>
#include <stackl/stackl.hpp>

int main() {
    StackL A;
    std::uint8_t a = 10, b = 20;
    std::cout << "c1";
    //A.Push(2);
    std::cout << "c3";
    A.Pop();
    A.Push(b);
    A.Push(a);
    std::cout << " -> " << unsigned(A.Top()) << std::endl;
}