#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <math.h>
 
int main() {
	using std::vector;
	using std::string;
 
	int a;
	string st;
	std::cin >> a;
	std::map<std::string, int> A;
	for (int i = 0; i < a; i++) {
		std::cin >> st;
		auto fl = A.find(st);
			if (fl == A.end()) {
				std::cout << "OK" << std::endl;
				A[st] = 1;
			} else {
				std::cout << st << A[st] << std::endl;
					int tr;
					tr = A[st];
					tr += 1;
					A[st] = tr;
			}
	}
}
