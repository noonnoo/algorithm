#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int N, answer = 0;
int MAP[21][21];

int dr[4] = { -1, 0, 0, 1 };
int dc[4] = { 0, -1, 1, 0 };

vector<vector<int>> fish;
int shark_size = 2, eaten_fish = 0;
pair<int, int> shark = make_pair(-1, -1);

bool compare(vector<int> fish1, vector<int> fish2) {
	if (fish1[2] != fish2[2])
		return fish1[2] < fish2[2];
	if (fish1[0] != fish2[0])
		return fish1[0] < fish2[0];
	return fish1[1] < fish2[1];
}

void getEdibleFish() {
	fish.clear();
	bool visited[21][21];
	queue<pair<pair<int, int>, int>> q;

	memset(visited, false, sizeof(visited));
	q.push(make_pair(shark, 0));

	visited[shark.first][shark.second] = true;
	while (!q.empty()) {
		int r = q.front().first.first;
		int c = q.front().first.second;
		int dist = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];
			if (nr >= 0 && nc >= 0 && nr < N && nc < N && !visited[nr][nc] && MAP[nr][nc] <= shark_size) {
				if (MAP[nr][nc] > 0 && MAP[nr][nc] < shark_size) {
					vector<int> edible = { nr, nc, dist + 1 };
					fish.push_back(edible);
				}
				visited[nr][nc] = true;
				q.push(make_pair(make_pair(nr, nc), dist + 1));
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> MAP[i][j];
			
			if (MAP[i][j] == 9) {
				shark.first = i;
				shark.second = j;
				MAP[i][j] = 0;
			}
		}
	}

	while (true) {
		getEdibleFish();

		if (fish.empty())
			break;
		sort(fish.begin(), fish.end(), compare);
		answer += fish[0][2];
		MAP[fish[0][0]][fish[0][1]] = 0;
		shark.first = fish[0][0];
		shark.second = fish[0][1];

		eaten_fish++;
		if (shark_size == eaten_fish) {
			shark_size++;
			eaten_fish = 0;
		}
	}

	cout << answer;
}
