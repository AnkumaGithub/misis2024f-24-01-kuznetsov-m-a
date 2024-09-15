#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <algorithm>
 
int main() {
	int n;
	std::cin >> n;
	std::vector<int> A(n);
	std::vector<int> data(1001);
	std::vector<int> B;
	for (int i = 0; i < n; i++) {
		std::cin >> A[i];
		data[A[i]] = 1;
	}
	for (int j = n - 1; j >= 0; j--) {
		if (data[A[j]] == 1) {
			B.push_back(A[j]);
			data[A[j]] = 0;
		}
	}
	std::cout << B.size() << std::endl;
	for (int g = B.size() - 1; g >= 0; g--) {
		std::cout << B[g] << " ";
	}
}
