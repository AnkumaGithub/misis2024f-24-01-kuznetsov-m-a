#include <arrayt/arrayt.hpp>
#include <iostream>

int main(){
  ArrayT<int> a(10);
  int b = 10;
  a[0] = 10;
  a[1] = 7;
  a.Remove(0);
  a.Insert(0, 1);
  std::cout << a[1];
}