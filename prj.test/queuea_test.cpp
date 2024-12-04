#include <iostream>
#include <queuea/queuea.hpp>

int main() {
    QueueA A;
    std::uint8_t a = 10, b = 20;
    std::cout << "c1";
    std::cout << A.get_size();
    std::cout << "c2";
    A.Push(a);
    A.Push(b);
    std::cout << A.get_size();
    //A.Push(2);
    std::cout << "c3";
    std::cout << " -> " << unsigned(A.Top()) << std::endl;
}