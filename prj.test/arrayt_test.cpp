#include <arrayt/arrayt.hpp>
#include <iostream>

int main(){
  ArrayT<int> a;
  int b = 10;
  a.Insert(0, b);
  std::cout << a[0] << " " << a.MaxSize();
}