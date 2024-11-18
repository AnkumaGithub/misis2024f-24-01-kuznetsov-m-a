#include <iostream>
#include <vector>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
      int n, m, xmin = 1000000, ymin = 1000000;
      std::cin >> n >> m;
      std::vector<std::vector<char>> data(n, std::vector<char>(m));
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          std::cin >> data[i][j];
          if (data[i][j] == 'R') {
            if (xmin > j){
              xmin = j;
            }
            if (ymin > i) {
              ymin = i;
            }
          }
        }
      }
      int flag = 0;
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          if (data[i][j] == 'R') {
            if (j <= xmin && i <= ymin){
              flag = 1;
            }
          }
        }
      }
      if (flag == 1){
        std::cout << "YES" << std::endl;
      }
      else{
        std::cout << "NO" << std::endl;
      }
    }
}