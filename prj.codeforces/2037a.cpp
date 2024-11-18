#include <iostream>
#include <vector>

int main(){
    int it = 0;
    std::cin >> it;
    while(it--)
    {
        int ln, num, itog = 0;
        std::cin >> ln;
        std::vector<long long> data(1000);
        for(int i = 0; i < ln; i++)
        {
            std::cin >> num;
            data[num] += 1;;
            if (data[num] % 2 == 0)
            {
                itog++;
            }
        }
        std::cout << itog << std::endl;
    }
}