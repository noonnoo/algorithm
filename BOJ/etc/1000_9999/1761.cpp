#include <iostream>
#include <map>
using namespace std;

int N, M;
int depths[40001], ancestors[40001][17], dist[40001];
map<int, int> vertex[40001];

int LCA(int v1, int v2) {		//부모 노드들이 같은 깊이가 될때까지 올라가기
	int d1 = depths[v1], d2 = depths[v2];

	if (d1 != d2) {
		for (int i = 17; i >= 0; i--) {
			if (d1 - d2 >= (1 << i)) {
				v1 = ancestors[v1][i];
				d1 -= (1 << i);
			}
			else if (d2 - d1 >= (1 << i)) {
				v2 = ancestors[v2][i];
				d2 -= (1 << i);
			}
		}
	}

	if (v1 != v2) {
		for (int i = 16; i >= 0; i--) {
			if (ancestors[v1][i] != ancestors[v2][i]) {
				v1 = ancestors[v1][i];
				v2 = ancestors[v2][i];
			}
		}
		return ancestors[v1][0];
	}
	else {
		return v1;
	}
}

void dfs(int curr, int depth, int d, int parent) {		//트리 노드의 부모와 깊이 찾기 (루트에서 노드까지 거리 찾기)
	depths[curr] = depth;

	for (auto v : vertex[curr]) {
		if (v.first != parent) {
			ancestors[v.first][0] = curr;
			dist[v.first] += vertex[v.first].find(curr)->second + dist[curr];
			dfs(v.first, depth + 1, dist[curr], curr);
		}
	}
}

void input() {		//인풋 부분
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		int v1, v2, d;
		cin >> v1 >> v2 >> d;
		vertex[v1].insert({ v2, d });
		vertex[v2].insert({ v1, d });
	}

	cin >> M;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	input();
	dfs(1, 1, 0, 0);

	for (int k = 1; k < 17; k++)
		for (int v = 1; v <= N; v++)
			ancestors[v][k] = ancestors[ancestors[v][k - 1]][k - 1];

	for (int i = 0; i < M; i++) {
		int v1, v2, lca;
		cin >> v1 >> v2;

		lca = LCA(v1, v2);
		cout << dist[v1] + dist[v2] - 2 * dist[lca] << "\n";	//노드1에서 노드2까지 거리 찾기
	}
}
