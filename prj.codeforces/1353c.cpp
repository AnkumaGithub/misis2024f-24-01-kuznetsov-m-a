#include <iostream>
#include <vector>
 
int main(){
    long long t, n, su;
    std::cin >> t;
    while (t > 0){
        t -= 1;
        su = 0;
        std::cin >> n;
        for (long long i = 0; i <= n / 2;++i){
            su += i*i;
        }
        std::cout << su * 8 << std::endl;
    }
