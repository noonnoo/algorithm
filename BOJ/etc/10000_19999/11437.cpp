#include <iostream>
#include <vector>
using namespace std;

int N, M;
int depths[50001], parents[50001];
vector<int> vertex[50001];

int LCA(int v1, int v2) {		//부모 노드들이 같은 깊이가 될때까지 올라가기
	int d1 = depths[v1], d2 = depths[v2];

	while (d1 > d2) {
		v1 = parents[v1];
		d1--;
	}
	while (d1 < d2) {
		v2 = parents[v2];
		d2--;
	}
	while (v1 != v2) {			//깊이가 같아도 다른 경우 같아질 때까지 올라가기 (끝까지 올라가면 루트)
		v1 = parents[v1];
		v2 = parents[v2];
	}
	return v1;
}

void dfs(int curr, int depth, int parent) {		//트리 노드의 부모와 깊이 찾기
	depths[curr] = depth;
	parents[curr] = parent;

	for (auto v : vertex[curr]) {
		if (v != parent) {
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

	for (int i = 0; i < M; i++) {
		int v1, v2;
		cin >> v1 >> v2;

		cout << LCA(v1, v2) << "\n";
	}
}
