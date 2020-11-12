#include <iostream>
using namespace std;

void solve() {
	long long DP[102];

	int N;
	cin >> N;

	DP[0] = 0;
	DP[1] = 1;
	DP[2] = 1;
	DP[3] = 1;
	DP[4] = 2;

	for (int i = 5; i <= N; i++) {
		DP[i] = DP[i - 1] + DP[i - 5];
	}

	cout << DP[N] << "\n";
}


int main() {
	int T;
	cin >> T;

	for (int i = 0; i < T; i++)
		solve();
}
