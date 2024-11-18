#include <iostream>

int main() {
    int n1, n2, n3, n4, t;
    std::cin >> t;
    while (t--) {
        std::cin >> n1 >> n2 >> n3 >> n4;
        if (n1 == 0 && n2 == 0 && n3 == 0 && n4 == 0) {
            std::cout << "0" << std::endl;
        }
        else{
            if (n1 == 1 && n2 == 1 && n3 == 1 && n4 == 1){
                std::cout << "2" << std::endl;
            }
            else{
                std::cout << "1" << std::endl;
            }
        }
    }
}