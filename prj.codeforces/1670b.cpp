#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
#include <cstdlib>
 
int main() {
	int t, n, k;
	std::string s;
	char buk;
	std::cin >> t;
	while (t > 0) {
		int count = 1, mxcount = 0, is_special = 0;
		t -= 1;
		std::cin >> n;
		std::cin >> s;
		std::cin >> k;
		std::vector <int> A(1000);
		int v = 0;
		while (k > 0) {
			k -= 1;
			std::cin >> buk;
			int c = buk;
			A[c] = 1;
			v += 1;
		}
		for (int i = 0; i < n - 1; i++) {
			int c = s[i + 1];
			if (A[c] == 1) {
				is_special = 1;
			}
			if (is_special == 0) {
				count += 1;
			}
			else {
				is_special = 0;
				if (mxcount < count) {
					mxcount = count;
				}
				count = 1;
			}
		}
		std::cout << mxcount << std::endl;
	}
}
