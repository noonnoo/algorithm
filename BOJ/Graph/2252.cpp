#include <iostream>
#include <vector>
#include <queue>
#define MAX 32001
using namespace std;

int N, M, degree[MAX];		//degree는 진입 차수
vector<int> order[MAX];		//order은 i번째 수가 j번째 수를 지난 후 나올 수 있다는 의미
int result[MAX];

void toppologySort() {		//위상 정렬
	queue<int> q;		

	for (int i = 1; i <= N; i++) 
		if (degree[i] == 0) q.push(i);		//진입차수가 0이면 q에 넣음

	for (int i = 0; i < N; i++) {
		if (q.empty())
			return;

		int x = q.front();					//q에서 나온 순서가 곧 순서
		q.pop();	
		result[i] = x;
		for (int j = 0; j < order[x].size(); j++) {		//q에서 갈 수 있는 수 중 차수가 0이되면 q에 넣기
			int y = order[x][j];
			if (--degree[y] == 0)
				q.push(y);
		}
	}

	for (int i = 0; i < N; i++) {
		cout << result[i] << " ";
	}
}

int main() {
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int X, Y;
		cin >> X >> Y;
		order[X].push_back(Y);
		degree[Y]++;
	}

	toppologySort();
}
