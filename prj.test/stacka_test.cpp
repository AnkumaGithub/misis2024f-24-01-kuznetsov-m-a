#include <stacka/stacka.hpp>
#include <iostream>

int main() {
  StackA A;
  A.Push(10);
  std::cout << A.Top() << std::endl;
  A.Push(20);
  A.Push(30);
  A.Pop();
  std::cout << A.Top() << std::endl;
  // После Pop() выводит 30, а должно 20
}