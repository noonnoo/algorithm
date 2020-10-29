#include <iostream>
#include <string>
using namespace std;

int GCD(int n, int m) {
	int tmp;
	while (m) {
		tmp = n % m;
		n = m;
		m = tmp;
	}
	return n;
}

int main() {
	int n, m;
	cin >> n >> m;

	int gcd = GCD(n, m);
	cout << gcd << "\n"
		<< n * m / gcd;
}
