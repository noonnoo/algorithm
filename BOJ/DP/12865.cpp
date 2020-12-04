#include <iostream>
using namespace std;

int DP[101][100001];
int weight[101];
int value[101];

int main() {
	int N, K, max = -1;
	cin >> N >> K;
	
	for (int i = 1; i <= N; i++) 
		cin >> weight[i] >> value[i];

	for (int i = 1; i <= N; i++) {
		int w = weight[i];
		int v = value[i];

		for (int j = 1; j <= K; j++) {
			if (j < w)
				DP[i][j] = DP[i - 1][j];
			else
				DP[i][j] = DP[i - 1][j] > DP[i - 1][j - w] + v ? DP[i - 1][j] : DP[i - 1][j - w] + v;
		}
		max = DP[i][K] > max ? DP[i][K] : max;
	}
	cout << max;
}
