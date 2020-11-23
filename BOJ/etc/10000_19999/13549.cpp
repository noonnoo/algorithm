#include <iostream>
#include <queue>
#include <vector>
#include <functional>
using namespace std;

bool visited[100001] = { false, };

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	int N, K;
	cin >> N >> K;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
	Q.push(make_pair(0, N));

	while (!Q.empty()) {
		int sec = Q.top().first, pos = Q.top().second;
		Q.pop();

		if (pos == K) {
			cout << sec;
			break;
		}

		if (pos * 2 <= 100000 && !visited[pos * 2]) {
			visited[pos * 2] = true;
			Q.push(make_pair(sec, pos * 2));
		}
		if (pos + 1 <= 100000 && !visited[pos + 1]) {
			visited[pos + 1] = true;
			Q.push(make_pair(sec + 1, pos + 1));
		}
		if (pos - 1 >= 0 && !visited[pos - 1]) {
			visited[pos - 1] = true;
			Q.push(make_pair(sec + 1, pos - 1));
		}
	}
}
