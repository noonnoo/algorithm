#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int N, K, W;
int time[1001];				//i번째 빌딩을 짓는데 걸리는 시간
int dp[1001];				//i번째 빌딩을 짓는데 걸리는 총 시간, dp에 이전에 구한 값들을 저장 후 활용
bool order[1001][1001];		//Y번째 선행 조건 X가 있으면 order[Y][X] = true

int DFS(int curr) {			//curr가 진입차수가 아니면 curr까지 오기까지의 시간 중 가장 큰 시간 을 return한다.
	if (dp[curr] != -1)		//이전에 방문했던 곳이라면 이전에 얻은 값 return
		return dp[curr];

	int ans = 0;
	for (int i = 1; i <= N; i++) {	//curr로 오기 위해 거쳐야할 곳들의 값을 미리 거쳐옴
		if (!order[curr][i]) continue;

		int temp = DFS(i);
		if (temp > ans)
			ans = temp;
	}

	dp[curr] = ans + time[curr];	//현재 건물을 짓는데 걸리는 시간 + 현재까지 오기위해 걸린 시간
	return dp[curr];				//return
}

void solve() {
	cin >> N >> K;					//초기화 및 입력 과정
	memset(dp, -1, sizeof(dp));
	memset(order, false, sizeof(order));

	for (int i = 1; i <= N; i++) {		
		cin >> time[i];
	}

	for (int i = 0; i < K; i++) {
		int X, Y;
		cin >> X >> Y;
		order[Y][X] = true;
	}
	cin >> W;	

	cout << DFS(W) << "\n";			//dfs 호출, 답 출력
}

int main() {
	int T;
	cin >> T;

	while (T--)
		solve();
}
