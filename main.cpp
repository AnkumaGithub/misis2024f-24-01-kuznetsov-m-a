#include <iostream>
#include <vector>

int main()
{
    int n, t;
    std::cin >> t;
    while (t--)
    {
        std::cin >> n;
        char x;
        int x1 = -1, y1, x2, y2;
        std::vector<std::vector<char>> data(n, std::vector<char>(n));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                std::cin >> x;
                if (x == '*')
                {
                    if (x1 == -1)
                    {
                        x1 = j;
                        y1 = i;
                    }
                    else
                    {
                        x2 = j;
                        y2 = i;
                    }
                }
                data[i][j] = x;
            }
        }
        data[x1][y2] = '*';
        data[x2][y1] = '*';
        std::cout << std::endl << n << std::endl;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                std::cout << data[i][j];
            }
            std::cout << std::endl;
        }
    }
}

