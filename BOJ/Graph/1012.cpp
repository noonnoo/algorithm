#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int r[4] = { 0, -1, 1, 0 };
int c[4] = { -1, 0, 0, 1 };

int M, N, K;
int land[51][51];
bool visited[51][51];
pair<int, int> cabbages[2501];

void DFS(int X, int Y) {
	if (visited[X][Y]) {
		return;
	}

	visited[X][Y] = true;

	for (int i = 0; i < 4; i++) {
		int nr = X + r[i], nc = Y + c[i];
		if (land[nr][nc] == 1)
			DFS(nr, nc);
	}
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	int T;
	cin >> T;

	while (T--) {
		fill(&land[0][0], &land[50][51], 0);
		fill(&visited[0][0], &visited[50][51], false);
		cin >> M >> N >> K;

		int X, Y;
		for (int i = 0; i < K; i++) {
			cin >> X >> Y;
			land[X][Y] = 1;
			cabbages[i] = make_pair(X, Y);
		}

		int answer = 0;
		for (int i = 0; i < K; i++) {
			if (!visited[cabbages[i].first][cabbages[i].second]) {
				DFS(cabbages[i].first, cabbages[i].second);
				answer++;
			}
		}

		cout << answer << "\n";
	}
}
