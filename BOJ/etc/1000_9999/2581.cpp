#include <iostream>
using namespace std;

bool not_prime[10001];

int main() {
	int N, M, sum = 0, min = 10001;
	cin >> N >> M;

	not_prime[1] = true;
	for (int i = 2; i <= M; i++) {
		if (not_prime[i])
			continue;

		if (N <= i) {
			sum += i;
			if (min >= i)
				min = i;
		}

		for (int j = i * i; j <= M; j += i) {
			not_prime[j] = true;
		}
	}

	if (sum == 0)
		cout << -1;
	else
		cout << sum << "\n" << min << "\n";
}
