#include <iostream>

int main() {
  int n, k, x, mx = 0;
  std::cin >> n >> k;
  for (int i = 0; i < n; i++) {
    std::cin >> x;
    if (k == (x * (k / x))){
      if (x > mx){
        mx = x;
      }
    }
  }
  std::cout << k / mx << std::endl;
}