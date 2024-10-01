#include <iostream>
int main() {
    int m, mxs;
    std::cin >> m;
    mxs = m / 5;
    if (m % 5 != 0) {
        mxs += 1;
        
        
    }
    std::cout << mxs;
    
    
}
