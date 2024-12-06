#include <iostream>
#include <queuea/queuea.hpp>

int main() {
    QueueA A;
    std::uint8_t a = 10, b = 20, c = 30, d = 40, e = 50;
    A.Push(a);
    std::cout << "a -> " << A.get_size() << std::endl;
    A.Push(b);
    std::cout << "ab -> " << A.get_size() << std::endl;
    A.Push(c);
    std::cout << "abc -> " << A.get_size() << std::endl;
    A.Push(d);
    std::cout << "abcd -> " << A.get_size() << std::endl;
    A.show_queue();
    std::cout << " -> " << A.get_size() << " " <<  unsigned(A.Top()) << " " << A.get_size() << std::endl;
    std::cout << " -> " << A.get_size() << " " <<  unsigned(A.Top()) << " " << A.get_size() << std::endl;
    std::cout << " -> " << A.get_size() << " " <<  unsigned(A.Top()) << " " << A.get_size() << std::endl;
    std::cout << " -> " << A.get_size() << " " <<  unsigned(A.Top()) << " " << A.get_size() << std::endl;
}