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
	int t, a, b;
	std::string s;
	std::cin >> t;
	while (t > 0) {
		t -= 1;
		std::cin >> a >> b >> s;
		int o_count = a, l_count = b, f = 0;
		for (int i = 0; i < (a + b) / 2 + (a + b) % 2; i++) {
			if (s[i] != s[(a + b - 1) - i] && s[i] != '?' && s[(a + b - 1) - i] != '?') {
				f = 1;
				break;
			}
			if (s[i] != s[(a + b - 1) - i] && (s[i] == '?' || s[(a + b - 1) - i] == '?')) {
				if (s[i] == '?') {
					s[i] = s[(a + b - 1) - i];
				}
				else {
					s[(a + b - 1) - i] = s[i];
				}
			}
			if ((i == (a + b) / 2) && ((a + b) % 2 == 1)) {
				if (s[i] == '0') {
					o_count -= 1;
				}
				else {
					if (s[i] != '?') {
						l_count -= 1;
					}
				}
			}
			else {
				if (s[i] == '0') {
					o_count -= 2;
				}
				else {
					if (s[i] != '?') {
						l_count -= 2;
					}
				}
			}
		}
		if (f != 1) {
			for (int j = 0; j < (a + b) / 2 + (a + b) % 2; j++) {
				if (s[j] == '0' && s[(a + b - 1) - j] == '0') {
				}
				else {
					if (s[j] == '1' && s[(a + b - 1) - j] == '1') {
					}
					else {
						if ((j == (a + b) / 2) && ((a + b) % 2 == 1)) {
							if (l_count >= 1) {
								l_count -= 1;
								s[j] = '1';
							}
							else {
								if (o_count >= 1) {
									o_count -= 1;
									s[j] = '0';
								}
							}
						}
						else {
							if (l_count >= 2) {
								l_count -= 2;
								s[j] = '1';
								s[(a + b - 1) - j] = '1';
							}
							else {
								if (o_count >= 2) {
									o_count -= 2;
									s[j] = '0';
									s[(a + b - 1) - j] = '0';
								}
							}
						}
					}
				}
			}
			if (l_count == 0 && o_count == 0) {
				std::cout << s << std::endl;
			}
			else {
				std::cout << "-1" << std::endl;
			}
		}
		else {
			std::cout << "-1" << std::endl;
		}
	}
}
