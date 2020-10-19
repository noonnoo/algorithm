#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int N, M;
bool visited[1001][1001][2];

int r[4] = { 0, 0, 1, -1 };
int c[4] = { 1, -1, 0, 0 };

int bfs(vector<string> map) {
	queue<vector<int>> q;
	visited[1][1][1] = true;
	vector<int> tmp(4, 1);	//r, c, count, block을 부수지 않았는지(1: 부수지 않음, 0: 부숨)
	q.push(tmp);

	while (!q.empty()) {
		vector<int> curr = q.front();
		q.pop();

		if (curr[0] == N && curr[1] == M) {
			return curr[2];
		}

		for (int i = 0; i < 4; i++) {
			int nr = curr[0] + r[i],
				nc = curr[1] + c[i];
			if (nr < 1 || nr > N || nc < 1 || nc > M)
				continue;

			tmp[0] = nr;
			tmp[1] = nc;
			tmp[2] = curr[2] + 1;
			tmp[3] = curr[3];

			if (map[nr][nc] == '1' && tmp[3] == 1) {
				visited[nr][nc][--tmp[3]] = true;
				q.push(tmp);
			}
			else if (map[nr][nc] == '0' && !visited[nr][nc][tmp[3]]) {
				visited[nr][nc][tmp[3]] = true;
				q.push(tmp);
			}
		}
	}
	return -1;
}

int main() {
	cin >> N >> M;
	string wall(M + 1, '1');
	vector<string> map(N + 1, wall);

	for (int i = 1; i <= N; i++) {
		cin >> map[i];
		map[i] = '1' + map[i] + '1';
	}

	cout << bfs(map);
}
