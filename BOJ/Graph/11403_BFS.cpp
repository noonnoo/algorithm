#include <iostream>
#include <queue>
using namespace std;

int N;					
int dir[101][101];					//input으로 받은 i에서 갈 수 있는 곳
int matrix[101][101];				//output이자 visited로 방문할 수 있는 곳 표시

int main() {
	cin >> N;

	for (int i = 1; i <= N; i++)	//입력
		for (int j = 1; j <= N; j++) 
			cin >> dir[i][j];

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (dir[i][j]) {		//i에서 갈수 있는 모든 곳 진행
				queue<int> next;	//BFS 서치에서 다음 노드
				next.push(j);

				while (!next.empty()) {
					int curr = next.front();	//큐의 맨 앞 뽑기
					next.pop();
					matrix[i][curr] = 1;

					for (int k = 1; k <= N; k++) {	//현재노드에서 갈 수 있는 노드 i에서 갈 수 있다고 추가
						if (dir[curr][k] && !matrix[i][k]) {
							matrix[i][k] = 1;
							next.push(k);
						}
					}
				}
			}
		}
	}

	for (int i = 1; i <= N; i++) {	//출력
		for (int j = 1; j <= N; j++)
			cout << matrix[i][j] << " ";
		cout << "\n";
	}
}
