#include <iostream>
#include <vector>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
      int n, high = 1, dcou = 0, flag = 0;
      std::cin >> n;
      std::vector<int> v(n);
      for (int i = 0; i < n; i++) {
        std::cin >> v[i];
      }
      if (v[0] == 1) { high += 1;}
      else{dcou += 1;}
      for (int i = 1; i < n; i++) {
        if (v[i - 1] == v[i] && v[i] == 1) {
          high += 5;
          dcou = 0;
        }
        else if (v[i] == 1){
          high += 1;
          dcou = 0;
        }
        if (v[i] == 0) {dcou += 1;}
        if (dcou == 2){
          std::cout << "-1" << std::endl;
          flag = 1;
          break;
        }
      }
      if (flag == 0) {
          std::cout << high << std::endl;
      }
    }
}