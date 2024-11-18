#include <iostream>
#include <vector>

int main() {
  int t;
  std::cin >> t;
  while (t--){
    int n, x1, y1, x2, y2, flag = 0, x3, y3, x4, y4;
    std::cin >> n;
    std::vector<std::vector<char>> data(n, std::vector<char>(n));
    for (int i = 0;i < n;i++){
      for (int j = 0;j < n;j++){
        std::cin >> data[i][j];
        if (data[i][j] == '*' && flag == 1){
          x2 = i;
          y2 = j;
        }
        if (data[i][j] == '*' && flag == 0){
          x1 = i;
          y1 = j;
          flag = 1;
        }
      }
    }
    if (x1 == y2 && y1 == x2 || x1 == y1 && y2 == x2 || x1 != x2 && y1 != y2){
      data[x1][y2] = '*';
      data[x2][y1] = '*';
      flag = 1;
    }
    else{
      if (x1 == x2){
        if (x1 == 0){
          data[1][y1] = '*';
          data[1][y2] = '*';
        }
        else{
          data[x1 - 1][y1] = '*';
          data[x1 - 1][y2] = '*';
        }
      }
      if (y1 == y2){
        if (y1 == 0){
          data[x1][1] = '*';
          data[x2][1] = '*';
        }
        else{
          data[x1][y1 - 1] = '*';
          data[x2][y1 - 1] = '*';
        }
      }
    }
    for (int i = 0;i < n;i++){
      for (int j = 0;j < n;j++){
        std::cout << data[i][j];
      }
      std::cout << std::endl;
    }
  }
}