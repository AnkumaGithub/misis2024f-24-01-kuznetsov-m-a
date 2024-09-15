#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <algorithm>
 
int main() {
	int n, k = 0, ans = 0;
	std::string st;
	std::cin >> n >> st;
	if (st[0] == 'x') {
		k = 1;
	}
	for (int i = 0; i < n - 1; i++) {
		if (st[i + 1] == 'x') {
			k += 1;
		}
		else {
			if (k > 2) {
				ans += k - 2;
			}
			k = 0;
		}
	}
	if (k > 2) {
		ans += k - 2;
	}
	std::cout << ans;
}
