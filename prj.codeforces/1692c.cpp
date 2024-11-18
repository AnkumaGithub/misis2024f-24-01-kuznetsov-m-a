#include <iostream>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
      char lit;
      int xkon, ykon, pbuf = 0, flag = 0;
      for (int i = 0;i < 8;i++){
        int buf = 0, x, y;
        for (int j = 0;j < 8;j++){
          std::cin >> lit;
          if (lit == '#'){
            buf += 1;
            x = j + 1;
            y = i + 1;
          }
        }
        if (buf == 1 && pbuf == 2 && flag == 0){
          xkon = x;
          ykon = y;
          flag = 1;
        }
        pbuf = buf;
      }
      std::cout << ykon << " " << xkon << std::endl;

    }
}