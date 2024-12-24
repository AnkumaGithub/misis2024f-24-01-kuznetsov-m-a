#include <stacka/stacka.hpp>
#include <iostream>

int main() {
  StackA A;
  A.Push(10);
  A.Size();
  std::cout << A.Top() << std::endl;
  A.Push(20);
  A.Size();
  A.Push(30);
  StackA B;
  //B.Push(10);
  B = A;
  //std::cout << B.Top() << " " << std::endl;
  A.Size();
  // После Pop() выводит 30, а должно 20
}