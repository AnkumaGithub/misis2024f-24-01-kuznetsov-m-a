#include <iostream>
#include <vector>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
      int n, x, kol = 0, kolm = 0, mn = 1000000, flag = 0;
      std::cin >> n;
      std::vector<int> data(101);
      for (int i = 0; i < n; i++) {
        std::cin >> x;
        if (mn > x){ mn = x;}
        if (x != 0) {data[x] += 1;}
      }
      for (int i = 0; i < 101; i++) {
        if (data[i] > 1){
          kol += data[i];
        }
        else{
          kolm += data[i];
        }
      }
      if (kol != 0 || (kol == 0 && mn == 0)){
        kol += kolm;
      }
      if (kol == 0 && mn != 0){
        kol += kolm + 1;
      }
      std::cout << kol << std::endl;
    }
}