#include <iostream>
#include <vector>

int main() {
  int t;
  std::cin >> t;
  //------------
  while (t--) {
    int n, x1 = -1, x2 = -1;
    std::cin >> n;
    std::vector<int> data(n);
    for (int i = 0; i < n; i++) {
      std::cin >> data[i];
    }
    for (int i = n - 1; i > 0; i--) {
      if (data[i - 1] == 0){
        x2 = i;
        break;
      }
    }
    for (int i = 0; i < n - 1; i++) {
      if (data[i + 1] == 0){
        x1 = i;
        break;
      }
    }
    std::cout << x2 - x1 << std::endl;
  }
}