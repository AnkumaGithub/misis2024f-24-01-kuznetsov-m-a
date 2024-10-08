#include <iostream>

int main(){
    int t;char sym;
    std::cin >> t;
    while(t>0){
        int su = 0;
        t-=1;
        for (int i = 0;i < 100;++i){
            std::cin >> sym;
            if (sym == 'X'){
                if (i / 10 == 0 || i / 10 == 9 || i % 10 == 0 || i % 10 == 9){
                    su+=1;
                }
                else if ((i / 10 == 1 || i / 10 == 8) && i % 10 >0 && i % 10 < 9 || (i % 10 == 1 || i % 10 == 8) && i / 10 > 0 && i / 10 < 9){
                    su += 2;
                }
                else if ((i / 10 == 2 || i / 10 == 7) && i % 10 > 1 && i % 10 < 8 || (i % 10 == 2 || i % 10 == 7) && i / 10 > 1 && i / 10 < 8){
                    su += 3;
                }
                else if ((i / 10 == 3 || i / 10 == 6) && i % 10 > 2 && i % 10 < 7 || (i % 10 == 3 || i % 10 == 6) && i / 10 > 2 && i / 10 < 7){
                    su += 4;
                }
                else{
                    su += 5;
                }
            }

        }
        std::cout << su << std::endl;
    }
}
