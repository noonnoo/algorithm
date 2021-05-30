#include <iostream>
#include <vector>
#include <queue>
#define MAX 10001
using namespace std;

int N;
vector<int> order[MAX];
int level[MAX], times[MAX], dp[MAX];

int getMin(){
	int result = 0;
	queue<int> q;
	for (int i = 1; i <= N; i++) {
		if (level[i] == 0) {		//진입차수가 0이면 q에 push
			q.push(i);
			dp[i] = times[i];
		}
	}

	while (!q.empty()) {
		int curr = q.front();
		q.pop();

		for (int i = 0; i < order[curr].size(); i++) {
			int posterior = order[curr][i];
			dp[posterior] = max(dp[curr] + times[posterior], dp[posterior]);
			
			if(--level[posterior] == 0)
				q.push(posterior);
		}
	}

	for (int i = 1; i <= N; i++) {
		result = max(result, dp[i]);
	}

	return result;
}

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;

	for (int i = 1; i <= N; i++) {
		int num, prior;
		cin >> times[i] >> num;

		for (int j = 0; j < num; j++) {
			cin >> prior;
			order[prior].push_back(i);
			level[i]++;
		}
	}

	cout << getMin();
}
