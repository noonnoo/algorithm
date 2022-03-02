#include <iostream>
using namespace std;

void fibonacci(long long n) {
	int mod = 1000000;
	int p = mod / 10 * 15;
	int *fibo = new int[p];
	fibo[0] = 0;
	fibo[1] = 1;

	for (int i = 2; i < p; i++) {
		fibo[i] = (fibo[i - 1] + fibo[i - 2]) % mod;
	}

	cout << fibo[n % p] << "\n";
	delete[] fibo;
}

int main() {
	long long N;
	cin >> N;

	fibonacci(N);
}
