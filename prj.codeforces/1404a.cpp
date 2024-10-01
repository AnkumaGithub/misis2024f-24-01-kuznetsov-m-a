#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <sstream> 
#include <cmath>
#include <algorithm>
#include <cstdlib>
 
int main() {
	int t, k, n;
	std::string s;
	std::cin >> t;
	while (t > 0) {
		int f = 0, total_o_count = 0, total_l_count = 0;
		t -= 1;
		std::cin >> n >> k >> s;
		for (int i = 0; i < k; i++) {
			int o_count = 0, l_count = 0;
			for (int j = i; j < n; j = j + k) {
				if (s[j] == '0') {
					o_count = 1;
				}
				if (s[j] == '1') {
					l_count = 1;
				}
			}
			if (o_count > 0 && l_count > 0) {
				f = 1;
				break;
			}
			else {
				total_o_count += o_count;
				total_l_count += l_count;
			}
		}
		if (f == 1) {
			std::cout << "NO" << std::endl;
		}
		else {
			if (total_o_count <= k / 2 && total_l_count <= k / 2) {
				std::cout << "YES" << std::endl;
			}
			else {
				std::cout << "NO" << std::endl;
			}
		}
	}
}
