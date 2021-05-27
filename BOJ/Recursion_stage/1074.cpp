#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int solve(int N, int r, int c) {
	int two_pow = pow(2, N - 1);
	int k = 0, result = 0;

	if (N < 1)
		return 0;

	if (two_pow > r) {
		if (two_pow > c) {
			k = 0;
		}
		else {
			k = 1;
			c -= two_pow;
		}
	}
	else {
		if (two_pow > c) {
			k = 2;
			r -= two_pow;
		}
		else {
			k = 3;
			r -= two_pow;
			c -= two_pow;
		}
	}

	result = k * pow(4, N - 1);
	return result + solve(N - 1, r, c);
}

int main() {
	int N, r, c;
	cin >> N >> r >> c;

	cout << solve(N, r, c);
}
