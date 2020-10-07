#include <iostream>
#include <queue>
using namespace std;

int N;					
int graph[101][101];				//output이자 visited로 방문할 수 있는 곳 표시

int main() {
	cin >> N;

	for (int i = 1; i <= N; i++)	//입력
		for (int j = 1; j <= N; j++) {
			cin >> graph[i][j];
		}

	for (int k = 1; k <= N; k++)	//플로이드-워셜
		for (int i = 1; i <= N; i++) 
			for (int j = 1; j <= N; j++) 
				if (1 < graph[i][k] + graph[k][j])
					graph[i][j] = 1;

	for (int i = 1; i <= N; i++) {	//출력
		for (int j = 1; j <= N; j++) {
			cout << graph[i][j] << " ";
		}
		cout << "\n";
	}
}
