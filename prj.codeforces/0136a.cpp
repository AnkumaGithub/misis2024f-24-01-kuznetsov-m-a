#include <iostream>
#include <vector>

int main() {
  int n, x;
  std::cin >> n;
  std::vector<int> v(n);
  for (int i = 0; i < n; i++) {
    std::cin >> x;
    v[x - 1] = i + 1;
  }
  for (int i = 0; i < n; i++) {
    std::cout << v[i] << " ";
  }
}