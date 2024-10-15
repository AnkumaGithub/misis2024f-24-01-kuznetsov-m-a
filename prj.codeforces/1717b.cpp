#include <iostream>
#include <vector>

int main(){
    int n, m, x, y, d, t;
    std::cin >> t;
    while(t > 0){
        int f = 1;
        t -= 1;
        std::cin >> n >> m >> x >> y >> d;
        if (x - d - 1 <= 0 && x + d >= n) {f = 0;}
        else if (y - d - 1 <= 0 && y + d >= m) {f = 0;}
        else if (y - d - 1 <= 0 && x - d - 1 <= 0) {f = 0;}
        else if (y + d >= m && x + d >= n) {f = 0;}
        if (f == 0){
            std::cout << "-1" << std::endl;
        }
        else{
            std::cout << (n + m - 2) << std::endl;
        }
    }
}
