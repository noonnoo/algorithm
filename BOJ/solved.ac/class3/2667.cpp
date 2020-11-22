#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int n;
string map[26];
bool visited[26][26];
int pr[4] = { -1,0,0,1 }, pc[4] = { 0,-1,1,0 };

void solve() {
	vector<int> group;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visited[i][j] || map[i][j] == '0') continue;

			int count = 0;
			queue<pair<int, int>> q;
			q.push({ i,j });
			visited[i][j] = true;

			while (!q.empty()) {
				int r = q.front().first, c = q.front().second;
				q.pop();
				count++;

				for (int k = 0; k < 4; k++) {
					int nr = r + pr[k], nc = c + pc[k];
					if (nr < 0 || nr >= n || nc < 0 || nc >= n || visited[nr][nc] || map[nr][nc] == '0')
						continue;

					q.push({ nr, nc });
					visited[nr][nc] = true;
				}
			}
			group.push_back(count);
		}
	}

	sort(group.begin(), group.end());
	cout << group.size();
	for (int i = 0; i < group.size(); i++) {
		cout << "\n" << group[i];
	}
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) 
		cin >> map[i];

	solve();
}
