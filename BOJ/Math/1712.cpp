#include <iostream>
using namespace std;

int main() {
	long long A, B, C;
	cin >> A >> B >> C;

	if (B >= C) {
		cout << -1 << "\n";
	}
	else {
		long long n = (long long)A / (C - B) + 1;
		cout << n;
	}
}
