#include <iostream>
#include <string>
using namespace std;

bool not_prime[1001];

int main() {
	int n, k, cnt = 0;
	cin >> n >> k;

	not_prime[1] = true;
	for (int i = 2; i <= n; i++) {
		if (not_prime[i])
			continue;

		for (int j = i; j <= n; j += i) {
			if (not_prime[j])
				continue;
			not_prime[j] = true;
			if (++cnt == k) {
				cout << j;
				return 0;
			}
		}
	}
}
