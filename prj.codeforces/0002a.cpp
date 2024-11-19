#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
 
int main() {
	using std::vector;
	using std::string;
 
	int a, o, mx = -10000;
	string st, mxst;
	std::cin >> a;
	std::vector<string> B;
	std::vector<int> A;
	std::map<string, int> data;
	for (int i = 1; i <= a; i++) {
		std::cin >> st >> o;
 
		if (data.find(st) == data.end()) {
			data[st] = o;
		}
		else {
			int tr = data[st];
			data[st] = tr + o;
		}
		B.push_back(st);
		A.push_back(o);
	}
	for (auto j : data) {
		mx = std::max(mx, j.second);
	}
	std::map<string, int> D;
	for (int g = 0; g < a; g++) {
		if (data[B[g]] == mx) {
			D[B[g]] += A[g];
			if (D[B[g]] >= mx) {
				std::cout << B[g] << std::endl;
				break;
			}
		}
	}
}
