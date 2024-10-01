include <iostream>
#include <vector>
 
int main() {
	int num;
	std::cin >> num;
	int l1, l2, l3, l4, newnum = num + 1;
	std::vector <int> A(10);
	int nl1, nl2, nl3, nl4, f = newnum;
	while (f < 10000) {
		newnum = f;
		nl4 = newnum % 10;
		newnum = newnum / 10;
		nl3 = newnum % 10;
		newnum = newnum / 10;
		nl2 = newnum % 10;
		nl1 = newnum / 10;
		A[nl1] += 1;
		A[nl2] += 1;
		A[nl3] += 1;
		A[nl4] += 1;
		if (A[nl1] == 1 && A[nl2] == 1 && A[nl3] == 1 && A[nl4] == 1) {
			std::cout << f;
			break;
		}
		f += 1;
		A[nl1] = 0;
		A[nl2] = 0;
		A[nl3] = 0;
		A[nl4] = 0;
	}
}
