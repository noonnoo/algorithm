#include <iostream>
#include <string>
using namespace std;

bool not_prime[1001];

int main() {
	int n, ans = 0;
	cin >> n;

	not_prime[1] = true;
	for (int i = 2; i <= 1001; i++) {
		if (not_prime[i])
			continue;

		for (int j = i * i; j <= 1001; j += i) {
			not_prime[j] = true;
		}
	}

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		if (!not_prime[num])
			ans++;
	}
	cout << ans;
}
