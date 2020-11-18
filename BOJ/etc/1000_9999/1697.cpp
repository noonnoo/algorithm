#include <iostream>
#include <queue>
using namespace std;

int main() {
	int N, K;
	bool visited[100001] = { false, };
	int index = 0, count = 0;
	queue<pair<int, int>> Q;
	cin >> N >> K;

	Q.push(make_pair(N,index));

	while (!Q.empty()) {
		int position = Q.front().first;
		int second = Q.front().second;
		Q.pop();

		if (position == K) {
			cout << second;
			break;
		}

		if (position + 1 <= 100000 && visited[position + 1] == false) {
			visited[position + 1] = true;
			Q.push(make_pair(position + 1, second + 1));
		}
		if (position - 1 >= 0 && visited[position - 1] == false) {
			visited[position - 1] = true;
			Q.push(make_pair(position - 1, second + 1));
		}
		if (position * 2 <= 100000 && visited[position * 2] == false) {
			visited[position * 2] = true;
			Q.push(make_pair(position * 2, second + 1));
		}
	}

}
