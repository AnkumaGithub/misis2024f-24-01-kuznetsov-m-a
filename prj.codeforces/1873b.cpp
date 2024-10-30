#include <iostream>
#include <vector>

int main(){
    int t, n, x;
    std::cin >> t;
    while(t > 0){
        t -= 1;
        int mxp = 0, p = 1, pn, ocounter = 0;
        std::cin >> n;
        std::vector<int> data(n);
        for (int j = 0;j < n;++j){
            std::cin >> x;
            data[j] = x;
            p = p * x;
            ocounter += 1;
        }
        for (int i = 0;i < n;++i){
            pn = p / data[i] * (data[i] + 1);
            if (pn > mxp){
                mxp = pn;
            }
        }
        if (ocounter == 0){
            std::cout << mxp << std::endl;
        }
        else if (ocounter == 1){
            int totalp = 1;
            for (int i = 0;i < n;++i){
                if (data[i] != 0){
                    totalp *= data[i];
                }
            std::cout << totalp << std::endl;
            }
        }
        if (ocounter >= 2){
            std::cout << mxp << std::endl;
        }
    }
} 