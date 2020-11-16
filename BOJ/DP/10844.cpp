#include <iostream>
#include <cmath>
using namespace std;

int dp[100][10];

int main() {
	int N;
	cin >> N;

	for (int i = 1; i < 10; i++) 
		dp[1][i] = 1;

	for (int i = 2; i <= N; i++) {
		for (int j = 0; j < 10; j++) {
			if (j > 0)
				dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % 1000000000;
			if (j < 9)
				dp[i][j] = (dp[i][j] + dp[i - 1][j + 1]) % 1000000000;
		}
	}

	long long sum = 0;
	for (int i = 0; i < 10; i++)
		sum = (sum + dp[N][i]) % 1000000000;

	
	cout << sum << "\n";
}
