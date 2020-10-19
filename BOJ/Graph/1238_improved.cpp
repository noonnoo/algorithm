#include <iostream>
#include <queue>

#define INF 10000000
using namespace std;

vector<pair<int, int>> road[1001];
vector<pair<int, int>> r_road[1001];
vector<int> x_dist, x_dist_r;
int N, M, X;

void dijkstra(int s, bool r) {
	vector<int> dist(N + 1, INF);
	dist[s] = 0;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;	//최소힙, (시간, 다음 노드) 순서로 저장되어 있음
	heap.push(make_pair(0, s));	//s에서 s로 가는 가중치는 0

	while (!heap.empty()) {
		pair<int, int> curr = heap.top();
		heap.pop();

		if(r)
			for (auto next : road[curr.second]) {		//next.first: 현재에서 가려는 노드, next.second: 현재에서 first까지 가는데 걸리는 시간
				int next_t = curr.first + next.second;	//현재까지오는데 time + 다음번거 가는데 걸리는 time
				if (next_t < dist[next.first]) {
					dist[next.first] = next_t;
					heap.push(make_pair(next_t, next.first));
				}
			}
		else
			for (auto next : r_road[curr.second]) {		//next.first: 현재에서 가려는 노드, next.second: 현재에서 first까지 가는데 걸리는 시간
				int next_t = curr.first + next.second;	//현재까지오는데 time + 다음번거 가는데 걸리는 time
				if (next_t < dist[next.first]) {
					dist[next.first] = next_t;
					heap.push(make_pair(next_t, next.first));
				}
			}
	}

	if (r)
		x_dist = dist;
	else
		x_dist_r = dist;
}

int main() {
	int ct1, ct2, time, largest = 0;
	cin >> N >> M >> X;
	
	for (int i = 0; i < M; i++) {
		cin >> ct1 >> ct2 >> time;
		road[ct1].push_back(make_pair(ct2, time));
		r_road[ct2].push_back(make_pair(ct1, time));
	}

	dijkstra(X, true);
	dijkstra(X, false);

	for (int i = 1; i <= N; i++) {
		if (largest < x_dist[i] + x_dist_r[i])
			largest = x_dist[i] + x_dist_r[i];
	}

	cout << largest;
}
