#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <algorithm>
 
int main() {
	int qua, a, b, c;
	std::cin >> qua;
	for (int i = 0; i < qua; i++) {
		std::cin >> a >> b >> c;
		int f = 0, k = 0;
		while (f == 0 && a != b) {
			if (abs(a - b) <= c * 2) {
				k += 1;
				f = 1;
			}
			else {
				k += 1;
				if (a >= b) {
					a -= c;
					b += c;
				}
				else {
					b -= c;
					a += c;
				}
			}
		}
		std::cout << k << std::endl;
	}
}
