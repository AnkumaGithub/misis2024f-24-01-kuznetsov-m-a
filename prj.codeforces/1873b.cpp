#include <iostream>
#include <vector>

int main(){
    int t, n, x;
    std::cin >> t;
    while(t > 0){
        t -= 1;
        int mxp = 0, p = 1, pn;
        std::cin >> n;
        std::vector<int> data(n);
        for (int j = 0;j < n;++j){
            std::cin >> x;
            data[j] = x;
            p = p * x;
        }
        for (int i = 0;i < n;++i){
            pn = p / data[i] * (data[i] + 1);
            if (pn > mxp){
                mxp = pn;
            }
        }
        std :: cout << mxp << std::endl;
    }
}