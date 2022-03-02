#include <iostream>
using namespace std;

int main() {
	int X;
	cin >> X;

	int n = 0, a = 0;
	while (true) {
		n++;
		if (X <= n * (n + 1) / 2)
			break;
	}

	a = n - (n * (n + 1) / 2 - X);
	int m = n + 1 - a;
	if (n % 2 == 0)
		cout << a << "/" << m;
	else
		cout << m << "/" << a;
}
