#include <iostream>
#include <cstring>
#include <string>
#include <queue>
using namespace std;

string map[51];
int N, M;
int ans = 0;

bool visited[51][51];
int dr[4] = { -1, 0, 0, 1 };
int dc[4] = { 0, -1, 1, 0 };

int BFS(int start_r, int start_c) {
	int max_depth = 0;

	memset(visited, false, sizeof(visited));
	queue<pair<pair<int, int>, int>> q;
	visited[start_r][start_c] = true;
	q.push(make_pair(make_pair(start_r, start_c), 0));

	while (!q.empty()) {
		int r = q.front().first.first;
		int c = q.front().first.second;
		int depth = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];
			if (nr < 0 || nc < 0 || nr >= N || nc >= M || visited[nr][nc] || map[nr][nc] == 'W')
				continue;

			visited[nr][nc] = true;
			q.push(make_pair(make_pair(nr, nc), depth + 1));
		}
		max_depth = max(depth, max_depth);
	}
	return max_depth;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> map[i];
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 'L') {
				int ret = BFS(i, j);
				ans = max(ret, ans);
			}
		}
	}

	cout << ans;
}
