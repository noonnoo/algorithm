#include <iostream>
#include <vector>
using namespace std;

int n;
vector<vector<int>> rgb;
vector<vector<int>> dp;

int DP() {
	int ret = 1000 * 1000 + 1;
	for (int i = 1; i <= n; i++) {
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + rgb[i][0];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + rgb[i][1];
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + rgb[i][2];
	}

	for (int i = 0; i < 3; i++) 
		ret = min(ret, dp[n][i]);

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

	cout << DP() << endl;
}
