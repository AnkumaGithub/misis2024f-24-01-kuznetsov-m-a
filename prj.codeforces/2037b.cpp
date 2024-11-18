#include <iostream>
#include <vector>

int main(){
    int it = 0;
    std::cin >> it;
    while(it--)
    {
        int ln, num;
        std::cin >> ln;
        std::vector<int> data(200005);
        int sz = ln - 2;
        for(int i = 0; i < ln; i++)
        {
            std::cin >> num;
            data[num] += 1;;
        }
        for(int i = 1; i < ln; i++)
        {
            if (data[i] > 0 && sz % i == 0 && data[sz / i] > 0)
            {
                std::cout << i << " " << sz / i << std::endl;
                break;
            }
        }
    }
}