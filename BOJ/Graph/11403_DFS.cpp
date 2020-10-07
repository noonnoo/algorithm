#include <iostream>
using namespace std;

int N;					
int dir[101][101];					//input으로 받은 i에서 갈 수 있는 곳
int matrix[101][101];				//output이자 visited로 방문할 수 있는 곳 표시

void DFS(int i, int j) {			//i에서 j를 갈 수 있으면 호출됨
	matrix[i][j] = 1;

	for (int k = 1; k <= N; k++)
		if (!matrix[i][k] && dir[j][k])	//이전에 방문한 적 없고, 갈 수 있으면 진행
			DFS(i, k);
}

int main() {
	cin >> N;

	for (int i = 1; i <= N; i++)	//입력
		for (int j = 1; j <= N; j++) 
			cin >> dir[i][j];

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (dir[i][j])			//i에서 갈수 있는 모든 곳 진행
				DFS(i, j);
		}
	}

	for (int i = 1; i <= N; i++) {	//출력
		for (int j = 1; j <= N; j++)
			cout << matrix[i][j] << " ";
		cout << "\n";
	}
}
