#include <iostream>
#include <vector>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int a = 0, b = 0, flag = 0;
        std::string s;
        std::cin >> s;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'a') {
                a+=1;
                if (b != 1){}
                else { flag = 1; break;}
                b = 0;
            }
            else {
                b += 1;
                if (a != 1){}
                else { flag = 1; break;}
                a = 0;
            }
        }
        if (b != 1){}
        else { flag = 1;}
        if (a != 1){}
        else { flag = 1;}
        if (flag == 0) { std::cout << "YES" << std::endl; }
        else { std::cout << "NO" << std::endl; }
    }
}