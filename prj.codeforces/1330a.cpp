#include <iostream>
#include <vector>

int main(){
    int t, n, x, b, s = 0;
    std::cin >> t;
    while(t > 0){
        int v;
        std::vector <int> data(1000003);
        t-=1;
        std::cin >> n >> x;
        for (int j = 0;j < n;j++){
            std::cin >> b;
            data[b] = 1;
        }
        for (int i = 1;i < 1000003;i++){
            s += 1;
            if (x <= 0 and data[i] == 0){
                v = i - 1;
                break;
            }
            else{
                if (data[i] == 0){
                    x -= 1;
                }
            }
        }
        std::cout << v << std::endl;
    }
}
