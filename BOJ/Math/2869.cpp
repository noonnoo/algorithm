#include <iostream>
#include <cmath>
using namespace std;

int main() {
	double A, B, V;
	int n;
	cin >> A >> B >> V;

	if (V == A)
		cout << 1;
	else {
		n = (long)ceil((V - B) / (A - B));
		cout << n;
	}
}
