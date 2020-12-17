#include <iostream>
#include <vector>
using namespace std;

int n, result = 1000001;
vector<vector<int>> rgb;
vector<vector<int>> dp;

int DP(int color) {
	int ret = 1000 * 1000 + 1;
	for (int j = 0; j < 3; j++)
		dp[1][j] = j == color ? rgb[1][j] : 1000 * 1000 + 1;

	for (int i = 2; i <= n; i++) {
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + rgb[i][0];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + rgb[i][1];
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + rgb[i][2];
	}

	for (int i = 0; i < 3; i++) {
		if (i == color)
			continue;
		ret = min(ret, dp[n][i]);
	}
	return ret;
}

int main() {
	cin >> n;

	for (int i = 0; i <= n; i++) {
		vector<int> tmp(3, 0);
		dp.push_back(tmp);

		if (i == 0) 
			rgb.push_back(tmp);
		else {
			for (int j = 0; j < 3; j++) 
				cin >> tmp[j];
			rgb.push_back(tmp);
		}
	}

	for (int i = 0; i < 3; i++) {
		result = min(DP(i), result);
	}
	cout << result;
}
