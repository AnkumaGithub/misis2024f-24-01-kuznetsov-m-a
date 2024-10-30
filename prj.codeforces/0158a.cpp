#include <iostream>
#include <vector>

int main(){
    int n, k, x, kol = 0;
    std::cin >> n >> k;
    std::vector<int> A(n);
    for (int j = 0;j < n;++j){
        std::cin >> x;
        A[j] = x;
    }
    for (int i = 0;i < n;++i){
        if (A[i] >= A[k - 1] && A[i] > 0){
            kol += 1;
        }
    }
    std::cout << kol;
}