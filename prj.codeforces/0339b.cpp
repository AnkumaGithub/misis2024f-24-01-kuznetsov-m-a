#include <iostream>
#include <vector>
 
int main(){
    long long n, m, a;
    std::cin >> n >> m;
    std::vector <long long> data(m);
    for (long long i = 0;i < m;++i){
        std::cin >> a;
        data[i] = a;
    }
    long long ran = data[0] - 1;
    for (long long j = 0;j < m - 1;++j){
        if (data[j] <= data[j + 1]){
            ran += data[j + 1] - data[j];
        }
        else{
            ran += n - data[j] + data[j + 1];
        }
    }
    std::cout << ran;
}
