#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, L;
vector<int> vertex[200001];
bool visited[200001];
int depth[200001];

int BFS() {
	int start, end;
	cin >> start >> end;

	queue<int> q;
	q.push(start);
	visited[start] = true;
	while (!q.empty()) {
		int curr = q.front();
		q.pop();

		if (curr == end) break;
		for (auto next : vertex[curr]) {	//curr에서 갈 수 있는 곳을 탐색
			if (!visited[next]) {
				visited[next] = true;
				depth[next] = depth[curr] + 1;
				q.push(next);
			}
		}
	}
		
	if (start == end)						//end가 start와 같은 경우는 환승 1
		return 0;
	else if(depth[end] == 0)				//이외의 경우 depth가 0이면 불가능
		return -1;
	return depth[end] / 2 - 1;				//노선도 정점이기 때문에 이를 제외( /2-1 )
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> N >> L;

	for (int i = N + 1; i < N + L + 1; i++) {		//i번째는 노선
		int tmp = 0;								//tmp는 역
		while (tmp != -1) {
			cin >> tmp;
			if (tmp == -1)
				break;
			vertex[i].push_back(tmp);				//노선에서 갈 수 있는 곳
			vertex[tmp].push_back(i);				//역에서 갈 수 있는 곳
		}
	}

	cout << BFS();
}
