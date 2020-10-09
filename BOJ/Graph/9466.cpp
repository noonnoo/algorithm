#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 100001;
int N, gnum = 0;			//N는 input, gnum은 그래프 개수
int like[MAX], visited[MAX];
bool finished[MAX];			//visited는 해당 노드를 방문했는가, finished는 사이클을 검토하는 것이 끝났는가
int scc[MAX];				//그래프가 가질 수 있는 강한 연결 요소의 개수

void getGraph(int curr) {                           
	int next = like[curr];

	if (visited[next]) {                            //다음 노드가 이미 방문한 노드인 경우
		visited[curr] = visited[next];
		if (!finished[next]) {                      //사이클이 있다면(다음 노드가 사이클 검사가 끝나지 않았다면)
			for (int i = next; i != curr; i = like[i])		//현재부터 다시 현재가 될 때까지 사이클 돌기
				scc[visited[curr]]++;
			scc[visited[curr]]++;                         
		}
	}
	else {
		visited[curr] = gnum;
		getGraph(next);                           //다음 노드로 넘어가기
	}
	finished[curr] = true;                        //이번 그래프에서 연결 된 노드 다보고 사이클 검사 끝냄
}

void solve() {
	memset(visited, 0, sizeof(int) * MAX);
	memset(scc, 0, sizeof(int) * MAX);
	memset(finished, 0, sizeof(bool) * MAX);
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> like[i];
	}

	for (int i = 1; i <= N; i++) {
		if (!visited[i]) {
			if (!visited[like[i]]) gnum++;
			getGraph(i);					//scc구하기
		}
	}

	while (gnum) {
		N -= scc[gnum--];                   //전체 개수에서 scc 개수만큼 빼기
	}

	cout << N << "\n";
}

int main() {
	int T;
	cin >> T;

	while (T--) {
		solve();
	}
}
