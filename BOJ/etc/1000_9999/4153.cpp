#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	long long a, b, c;
	while (cin >> a >> b >> c) {
		if (a == 0 && b == 0 && c == 0)
			break;

		long long a2 = a * a, b2 = b * b, c2 = c * c;
		if (a2 + b2 == c2 || a2 + c2 == b2 || b2 + c2 == a2)
			cout << "right" << "\n";
		else
			cout << "wrong" << "\n";
 	}
}
