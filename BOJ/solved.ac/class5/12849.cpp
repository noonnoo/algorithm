#include <iostream>
#include <vector>
using namespace std;

vector<int> graph[8];
int dp[100001][8];

void make_graph() {
	graph[0] = { 1,2 };
	graph[1] = { 0,2,3 };
	graph[2] = { 0,1,3,4 };
	graph[3] = { 1,2,4,5 };
	graph[4] = { 2,3,5,7 };
	graph[5] = { 3,4,6 };
	graph[6] = { 5,7 };
	graph[7] = { 4,6 };
}

void solve() {
	int n;
	cin >> n;

	dp[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 8; j++) {
			if (dp[i - 1][j]) {
				for (int k = 0; k < graph[j].size(); k++) {
					dp[i][graph[j][k]] += dp[i - 1][j];
					dp[i][graph[j][k]] %= 1000000007;
				}
			}
		}
	}
	
	cout << dp[n][0];
}

int main() {
	make_graph();
	solve();
}
