#include <iostream>
using namespace std;

int fibonacci(int n, int i, int pre1, int pre2) {
	int curr = pre1 + pre2;

	if (n == i)
		return curr;
	else
		return fibonacci(n, ++i, curr, pre1);
}

int main() {
	int N;
	cin >> N;

	if (N == 0)
		cout << 0;
	else if (N == 1)
		cout << 1;
	else
		cout << fibonacci(N, 2, 1, 0);
}
