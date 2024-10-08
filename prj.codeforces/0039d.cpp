#include <iostream>
#include <vector>
 
int main(){
    int x1,x2, y1, y2, z1, z2;
    std::cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
    if(x1 != x2 && y1 != y2 && z1 != z2){
        std::cout << "NO";
    }
    else{
        std::cout << "YES";
    }
}
