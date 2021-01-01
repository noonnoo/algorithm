#include <iostream>
using namespace std;

const double pi = 3.14159265358979;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	double R;
	cin >> R;

	cout << fixed;
	cout.precision(6);
	
	double result1 = R * R * pi;
	double result2 = R * R * 2;
	cout << result1 << "\n"
		 << result2;
}
