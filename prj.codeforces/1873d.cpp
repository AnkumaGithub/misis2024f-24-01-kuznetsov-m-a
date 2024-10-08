#include <iostream>
#include <vector>
 
int main(){
    int t, n, k;
    std::string st;
    std::cin >> t;
    while(t > 0){
        int count = 0;
        std::cin >> n >> k >> st;
        t -= 1;
        for (int i = 0;i < n;++i){
            if (st[i] == 'B'){
                int k2 = k;
                count += 1;
                while (i < n && k2 > 0){
                    st[i] = 'W';
                    k2 -= 1;
                    i +=1 ;
                }
                i -= 1;
            }
        }
        std::cout << count << std::endl;
    }
}
