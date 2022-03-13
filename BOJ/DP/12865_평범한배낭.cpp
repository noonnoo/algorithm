#include <iostream>
#include <algorithm>
using namespace std;

int DP[101][100001];
int W[101];
int V[101];

int main() {
	int N, K, result = -1;
	cin >> N >> K;
	
	for (int i = 1; i <= N; i++) 
		cin >> W[i] >> V[i];

	for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= K; j++) {
			if (j < W[i])
				DP[i][j] = DP[i - 1][j];
			else
				DP[i][j] = max(DP[i - 1][j], DP[i - 1][j - W[i]] + V[i]);
		}
		result = max(DP[i][K], result);
	}
	cout << result;
}