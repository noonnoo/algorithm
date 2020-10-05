#include <iostream>
#include <math.h>
#include <cstring>
#include <queue>
using namespace std;

int land[52][52];		//국가별 인구수
int N, R, L;			

bool is_moved() {		//인구이동이 있었는지 확인하는 BFS함수
	bool ret = false;
	bool visited[52][52];	//해당국가를 방문한 적 있는지 표시
	for (int i = 0; i < N + 2; i++)
		memset(visited[i], false, sizeof(bool) * (N + 2));

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (visited[i][j]) {
				ret = true;
				continue;
			} 
			if (!(abs(land[i][j] - land[i][j + 1]) >= L && abs(land[i][j] - land[i][j + 1]) <= R)		//상하좌우 국경을 개방할 수 없으면 통과
				&& !(abs(land[i][j] - land[i][j - 1]) >= L && abs(land[i][j] - land[i][j - 1]) <= R)
				&& !(abs(land[i][j] - land[i + 1][j]) >= L && abs(land[i][j] - land[i + 1][j]) <= R)
				&& !(abs(land[i][j] - land[i - 1][j]) >= L && abs(land[i][j] - land[i - 1][j]) <= R))
				continue;

			queue<pair<int, int>> Q;
			vector<pair<int, int>> unions;
			int population = 0, num = 0;
			Q.push(make_pair(i, j));
			unions.push_back(make_pair(i, j));
			visited[i][j] = true;

			while (!Q.empty()) {
				pair<int, int> curr = Q.front();
				int r = curr.first, c = curr.second;
				population += land[curr.first][curr.second];
				num++;
				Q.pop();

				if (!visited[r][c + 1]						//오른쪽 국가와 개방 가능여부
					&& abs(land[r][c] - land[r][c + 1]) >= L && abs(land[r][c] - land[r][c + 1]) <= R) {
					Q.push(make_pair(r, c + 1));
					unions.push_back(make_pair(r, c + 1));
					visited[r][c + 1] = true;
				}
				if (!visited[r][c - 1]						//왼쪽 국가와 개방 가능여부
					&& abs(land[r][c] - land[r][c - 1]) >= L && abs(land[r][c] - land[r][c - 1]) <= R) {
					Q.push(make_pair(r, c - 1));
					unions.push_back(make_pair(r, c - 1));
					visited[r][c - 1] = true;
				}
				if (!visited[r + 1][c]						//아래 국가와 개방 가능여부
					&& abs(land[r][c] - land[r + 1][c]) >= L && abs(land[r][c] - land[r + 1][c]) <= R) {
					Q.push(make_pair(r + 1, c));
					unions.push_back(make_pair(r + 1, c));
					visited[r + 1][c] = true;
				}
				if (!visited[r - 1][c]						//위 국가와 개방 가능여부
					&& abs(land[r][c] - land[r - 1][c]) >= L && abs(land[r][c] - land[r - 1][c]) <= R) {
					Q.push(make_pair(r - 1, c));
					unions.push_back(make_pair(r - 1, c));
					visited[r - 1][c] = true;
				}
			}

			int mean = population / num;
			for (int u = 0; u < unions.size(); u++)
				land[unions[u].first][unions[u].second] = mean;
		}
	}
	return ret;
}

int main() {
	cin >> N >> L >> R;
	int count = 0;

	for (int i = 0; i <= N + 1; i++)
		for (int j = 0; j <= N + 1; j++) {
			if (i == 0 || j == 0 || i == N + 1 || j == N + 1)
				land[i][j] = 201;
			else
				cin >> land[i][j];
		}


	while (is_moved())
		count++;

	cout << count;
}
