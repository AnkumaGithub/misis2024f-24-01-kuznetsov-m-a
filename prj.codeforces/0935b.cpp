#include <iostream>

int main(){
    int n, x = 0, y = 0, mon = 0;
    std::string st;
    std::cin >> n >> st;
    if (st[0] == 'U'){
        y += 1;
    }
    else{
        x += 1;
    }
    for (int i = 1;i < n;++i){
        // check
        if (x == y){
            // -> * ->
            if (st[i] == 'R'){
                if (st[i - 1] == 'R'){
                    mon += 1;
                }
            }
            // up
            if (st[i] == 'U'){
                if (st[i - 1] == 'U'){
                    mon += 1;
                }
            }
        }
        if (st[i] == 'U'){
            y += 1;
        }
        else{
            x += 1;
        }
    }
    std::cout << mon;
}