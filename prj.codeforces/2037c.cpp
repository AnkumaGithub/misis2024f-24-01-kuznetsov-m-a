#include <iostream>
#include <vector>

int main() {
    int t, n;
    std::cin >> t;
    while(t--) {
        std::cin >> n;
        if(n <= 4) {
            std::cout << -1 << std::endl;
        }
        else
        {
            std::vector<int> even, odd;
            for(int i = 2; i <= n; i += 2)
            {
                if (i != 4)
                {
                    even.push_back(i);
                }
            }
            even.push_back(4);
            even.push_back(5);
            for(int i = 1; i <= n; i += 2)
            {
                if (i != 5)
                {
                    odd.push_back(i);
                }
            }
            for(int i = 0; i < even.size(); i++)
            {
                std::cout << even[i] << " ";
            }
            for(int i = 0; i < odd.size(); i++)
            {
                std::cout << odd[i] << " ";
            }
        }
    }
}