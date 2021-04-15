#include <iostream>
using namespace std;

int N, M;
int MAP[501][501];
int DP[501][501];

int dr[4] = { -1, 0, 0, 1 };
int dc[4] = { 0, -1, 1, 0 };

int DFS(int r, int c) {
	if (r == N - 1 && c == M - 1)
		return 1;

	if (DP[r][c] == -1) {				//방문한적 없는 길만 탐색
		DP[r][c] = 0;
		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];
			if (nr >= 0 && nc >= 0 && nr < N && nc < M && MAP[r][c] > MAP[nr][nc])
				DP[r][c] += DFS(nr, nc);
		}
	}

	return DP[r][c];
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> MAP[i][j];
			DP[i][j] = -1;		//-1은 가본적 없는 길
		}
	}

	cout << DFS(0, 0);
}
