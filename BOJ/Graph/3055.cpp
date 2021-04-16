#include <iostream>
#include <string>
#include <queue>
using namespace std;

int map[51][51];
int R, C;
pair<int, int> hedgehog;

bool visited[51][51];
int dr[4] = { -1, 0, 0, 1 };
int dc[4] = { 0, -1, 1, 0 };

int BFS() {
	queue<pair<pair<int, int>, int>> q;
	q.push(make_pair(hedgehog, 0));
	visited[hedgehog.first][hedgehog.second] = true;

	while (!q.empty()) {
		int r = q.front().first.first;
		int c = q.front().first.second;
		int time = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];

			if (nr < 0 || nc < 0 || nr >= R || nc >= C || visited[nr][nc])
				continue;

			visited[nr][nc] = true;
			if (map[nr][nc] > time + 1 || map[nr][nc] == -1)
				q.push(make_pair(make_pair(nr, nc), time + 1));
			else if (map[nr][nc] == -3)
				return time + 1;
		}
	}

	return -1;
}

void predictWater(queue<pair<int, int>> &water) {
	while (!water.empty()) {
		int r = water.front().first;
		int c = water.front().second;
		water.pop();

		if (map[r][c] >= 0) {
			for (int d = 0; d < 4; d++) {
				int nr = r + dr[d];
				int nc = c + dc[d];

				if (nr < 0 || nc < 0 || nr >= R || nc >= C || map[nr][nc] != -1)
					continue;

				map[nr][nc] = map[r][c] + 1;
				water.push(make_pair(nr, nc));
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> R >> C;

	queue<pair<int, int>> water;
	string tmp;

	for (int i = 0; i < R; i++) {
		cin >> tmp;
		for (int j = 0; j < C; j++) {
			if (tmp[j] == '*') {
				water.push(make_pair(i, j));
				map[i][j] = 0;
			}
			else if (tmp[j] == '.') 
				map[i][j] = -1;
			else if (tmp[j] == 'S') {
				hedgehog = make_pair(i, j);
				map[i][j] = -2;
			}
			else if (tmp[j] == 'D')
				map[i][j] = -3;						
			else
				map[i][j] = -4;
		}
	}

	predictWater(water);
	int result = BFS();
	if (result == -1)
		cout << "KAKTUS";
	else
		cout << result;
}
