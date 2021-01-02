#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, K, M;
vector<vector<int>> vertex;
bool visited[101001];
int depth[101001];

int BFS() {
	queue<int> q;
	q.push(1);
	visited[1] = true;
	while (!q.empty()) {
		int curr = q.front();
		q.pop();

		if (curr == N) break;
		for (auto next : vertex[curr]) {	//curr에서 갈 수 있는 곳을 탐색
			if (!visited[next]) {
				visited[next] = true;
				depth[next] = depth[curr] + 1;
				q.push(next);
			}
		}
	}

	if (N != 1 && depth[N] == 0)		//N이 1인경우 depth는 오르지 않음
		return -1;
	return depth[N] / 2 + 1;			//하이퍼튜브에서 움직임이 1이기 때문에 이를 제외
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> N >> K >> M;
	vertex.resize(N + M + 1);

	for (int i = N + 1; i < N + M + 1; i++) {		//i번째는 튜브
		for (int j = 0; j < K; j++) {
			int tmp;								//tmp는 역
			cin >> tmp;
			vertex[i].push_back(tmp);				//튜브에서 갈 수 있는 곳
			vertex[tmp].push_back(i);				//정점에서 갈 수 있는 곳
		}
	}

	cout << BFS();
}
