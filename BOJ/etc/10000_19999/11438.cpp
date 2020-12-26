#include <iostream>
#include <vector>
using namespace std;

int N, M;
int depths[100001], ancestors[100001][18];
vector<int> vertex[100001];

int LCA(int v1, int v2) {		//부모 노드들이 같은 깊이가 될때까지 올라가기
	int d1 = depths[v1], d2 = depths[v2];

	if (d1 != d2) {
		for (int i = 17; i >= 0; i--) {
			if (d1 - d2 >= (1 << i)) {
				v1 = ancestors[v1][i];
				d1 -= (1 << i);
			}
			else if(d2 - d1 >= (1 << i)) {
				v2 = ancestors[v2][i];
				d2 -= (1 << i);
			}
		}
	}

	if (v1 != v2) {
		for (int i = 17; i >= 0; i--) {
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

void dfs(int curr, int depth, int parent) {		//트리 노드의 부모와 깊이 찾기
	depths[curr] = depth;

	for (auto v : vertex[curr]) {
		if (v != parent) {
			ancestors[v][0] = curr;
			dfs(v, depth + 1, curr);
		}
	}
}

void input() {		//인풋 부분
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		int v1, v2;
		cin >> v1 >> v2;
		vertex[v1].push_back(v2);
		vertex[v2].push_back(v1);
	}

	cin >> M;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	input();
	dfs(1, 1, 0);

	for (int k = 1; k < 18; k++) 
		for (int v = 1; v <= N; v++) 
			ancestors[v][k] = ancestors[ancestors[v][k - 1]][k - 1];

	for (int i = 0; i < M; i++) {
		int v1, v2;
		cin >> v1 >> v2;

		cout << LCA(v1, v2) << "\n";
	}
}
