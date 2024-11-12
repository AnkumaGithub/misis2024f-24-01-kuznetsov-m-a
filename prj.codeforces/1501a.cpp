#include <iostream>
#include <vector>

int main() {
  int n, it;
  std::cin >> it;
  while (it--) {
    int time = 0;
    std::cin >> n;
    std::vector <int> a(n + 1);
    std::vector <int> b(n + 1);
    std::vector <int> t(n + 1);
    for (int i = 0; i < n; i++) {
      std::cin >> a[i];
      std::cin >> b[i];
    }
    for (int i = 1; i <= n; i++) {
      std::cin >> t[i];
    }
    for (int i = 1; i <= n; i++) {
      time += a[i] - b[i - 1] + t[i];
      if (i != n) {
        time += (b[i] - a[i] + 1) / 2;
        if (time < b[i]){
          time += b[i] - time;
        }
      }
    }
    std::cout << time + a[n - 1] << std::endl;
  }
}