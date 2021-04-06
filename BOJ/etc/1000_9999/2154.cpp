#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
	int n;
	cin >> n;

	string str = "";
	string num = to_string(n);

	for (int i = 1; i <= n; i++) {
		str += to_string(i);
	}

	cout << str.find(num) + 1;
}
