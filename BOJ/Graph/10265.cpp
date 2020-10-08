#include <iostream>
using namespace std;

const int MAX = 1001;
short N, K, gnum = 0, ret = 0;         //N,K는 input, gnum은 그래프 개수, ret는 결과값
short like[MAX];                       //같이 가고 싶은 친구 번호

short visited[MAX];
bool finished[MAX];      //visited는 해당 노드를 방문했는가, finished는 사이클을 검토하는 것이 끝났는가
short gmax[MAX], gmin[MAX];              //graph가 가질 수 있는 최대(더해질 수 있는 수), 최소(사이클에 있는 컴포넌트 수) 값
short dp[MAX];

void getGraph(int curr) {                           //그래프가 가질 수 있는 최대(강한 연결 포함 모두), 최소(강한 연결만) 요소 개수
	int next = like[curr];

	if (visited[next]) {                            //다음 노드가 이미 방문한 노드인 경우
		visited[curr] = visited[next];
		if(next != curr) gmax[visited[curr]]++;
		if (!finished[next]) {                      //사이클이 있다면(다음 노드가 사이클 검사가 끝나지 않았다면)
			for (int i = next; i != curr; i = like[i])      //현재부터 다시 현재가 될 때까지 사이클 돌기
				gmin[visited[curr]]++;
			gmin[visited[curr]]++;                           //최솟값: 사이클 안의 컴포넌트 수
		}
	}
	else {
		visited[curr] = gnum;
		gmax[gnum]++;
		getGraph(next);                           //다음 노드로 넘어가기
	}
	finished[curr] = true;                        //이번 그래프에서 연결 된 노드 다보고 사이클 검사 끝냄
}

int main() {
	cin >> N >> K;

	for (int i = 1; i <= N; i++) {
		cin >> like[i];
	}

	for (int i = 1; i <= N; i++) {
		if (!visited[i]) {
			if (!visited[like[i]]) gnum++;
			getGraph(i);
		}
	}

	dp[0] = 1;
	for (int i = 1; i <= gnum; i++)
		for (int j = K; j >= 0; j--)
			for (int p = gmin[i]; p <= gmax[i]; p++)
				if (j - p >= 0) dp[j] |= dp[j - p];

	for (int i = K; i >= 0; i--) 
		if (dp[i]) {
			cout << i;
			break;
		}

	return 0;
}
