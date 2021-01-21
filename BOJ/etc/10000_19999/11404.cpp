#include <iostream>
#include <algorithm>
using namespace std;

const int INF = 10000000;
int n, m;
long long cost[101][101];

void floyd() {		//플로이드-워셜
	for (int k = 1; k <= n; k++)	
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++) {
				if (cost[i][j] > cost[i][k] + cost[k][j])
					cost[i][j] = cost[i][k] + cost[k][j];
			}
}

void output() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (cost[i][j] >= INF)
				cout << 0 << " ";
			else
				cout << cost[i][j] << " ";
		}
		cout << "\n";
	}
}

int main() {
	cin >> n >> m;
	fill(cost[0], cost[101], INF);

	for (int i = 0; i < m; i++) {
		int A, B, C;
		cin >> A >> B >> C;
		cost[A][B] = min(cost[A][B],(long long)C);
	}

	for (int i = 1; i <= n; i++) {
		cost[i][i] = 0;
	}

	floyd();
	output();
}
