#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <algorithm>
#include <cstdlib>
 
bool Tri(int x1, int y1, int x2, int y2, int x3, int y3) {
	int sx1, sx2, sx3, sy1, sy2, sy3;
	sx1 = x2 - x1;
	sy1 = y2 - y1;
	sx2 = x3 - x1;
	sy2 = y3 - y1;
	sx3 = x3 - x2;
	sy3 = y3 - y2;
	if (((x1 == x2) && (y1 == y2)) || ((x3 == x2) && (y3 == y2)) || ((x1 == x3) && (y1 == y3))) {
		return false;
	}
	if ((sx1 * sx2 + sy1 * sy2 == 0) || (sx1 * sx3 + sy1 * sy3 == 0) || (sx3 * sx2 + sy3 * sy2 == 0)) {
		return true;
	}
	return false;
}
int main() {
	int x1, x2, x3, y1, y2, y3, f = 0;
	std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	std::vector<int> A(6);
	A[0] = 1;
	if (Tri(x1, y1, x2, y2, x3, y3)) {
		std::cout << "RIGHT";
	}
	else {
		for (int i = 0; i < 6; i++) {
			if (Tri(x1 + A[0], y1 + A[1], x2 + A[2], y2 + A[3], x3 + A[4], y3 + A[5])) {
				std::cout << "ALMOST";
				f = 1;
				break;
			}
			if (i != 5) {
				A[i + 1] = A[i];
				A[i] = 0;
			}
		}
		A[5] = 0;
		A[0] = -1;
		if (f != 1) {
			for (int i = 0; i < 6; i++) {
				if (Tri(x1 + A[0], y1 + A[1], x2 + A[2], y2 + A[3], x3 + A[4], y3 + A[5])) {
					std::cout << "ALMOST";
					f = 1;
					break;
				}
				if (i != 5) {
					A[i + 1] = A[i];
					A[i] = 0;
				}
			}
		}
		if (f != 1) {
			std::cout << "NEITHER";
		}
	}
}
