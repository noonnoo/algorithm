#include <iostream>
using namespace std;

long long DP[201][201];
int N, K;

void solve() {
	for (int i = 0; i <= N; i++) 
		DP[i][0] = 1;
	
	for(int i = 0; i <= K; i++)
		DP[0][i] = 1;


	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= K; j++) {
			DP[i][j] = (DP[i - 1][j] + DP[i][j - 1]) % 1000000000;
		}
	}

	cout << DP[N][K - 1];
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> N >> K;
	solve();
}
