#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int N, M, answer = 0;
int MAP[51][51];
int safe_dist[51][51];

int dr[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dc[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };

void BFS(pair<int, int> shark) {
	bool visited[51][51];
	queue<pair<pair<int, int>, int>> q;

	memset(visited, false, sizeof(visited));
	q.push(make_pair(shark, 0));
	visited[shark.first][shark.second] = true;

	while (!q.empty()) {
		int r = q.front().first.first;
		int c = q.front().first.second;
		int dist = q.front().second;
		q.pop();

		for (int i = 0; i < 8; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];
			if (nr < 0 || nc < 0 || nr >= N || nc >= M || visited[nr][nc] || MAP[nr][nc] == 1)
				continue;

			visited[nr][nc] = true;
			if(safe_dist[nr][nc] > dist + 1)
				safe_dist[nr][nc] = dist + 1;

			q.push(make_pair(make_pair(nr, nc), dist + 1));
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	vector<pair<int, int>> sharks;
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> MAP[i][j];
			if (MAP[i][j] == 1)
				sharks.push_back(make_pair(i, j));
			safe_dist[i][j] = 987654321;
		}
	}
	
	for (int i = 0; i < sharks.size(); i++) {
		BFS(sharks[i]);
		safe_dist[sharks[i].first][sharks[i].second] = 0;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (safe_dist[i][j] > answer)
				answer = safe_dist[i][j];
		}
	}

	cout << answer;
}
