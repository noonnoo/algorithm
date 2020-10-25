#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define MAX 2147483647
using namespace std;

bool visited[10001];
vector<pair<int, int>> dist[10001];		//i번째에서 갈 수 있는 곳: first, 가중치: second

struct cmp {
	bool operator()(pair<int, int> d1, pair<int, int> d2) {
		return d1.second > d2.second;
	}
};

int main() {
	int V, E, curr, s = 0, ans = 0;
	pair<int, int> mini;
	priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> q;

	cin >> V >> E;

	int v1, v2, w;
	for (int i = 0; i < E; i++) {
		cin >> v1 >> v2 >> w;
		dist[v1].push_back(make_pair(v2, w));	//v1에서 v2를 가는 경우, v2에서 v1을 가는 경우 모두 추가
		dist[v2].push_back(make_pair(v1, w));
	}

	curr = v1;									//시작 노드
	while (++s < V) {							//모든 노드를 다 돌아보는 동안
		visited[curr] = true;

		for (auto next : dist[curr]) {
			if (!visited[next.first]) {			//방문하지 않은 노드 중 가장 w이 작은 노드 S에 추가
				q.push(next);
			}
		}

		mini = q.top();
		while (visited[mini.first]) {
			q.pop();
			mini = q.top();
		}
		q.pop();
		ans += mini.second;
		curr = mini.first;
	}

	cout << ans;
}
