#include <iostream>
#include <cstring>
using namespace std;

int N, smallest = 101, largest = 0, result = 1;		//result가 안전영역의 수로 최소는 1이다.				
int map[100][100];									//땅의 높이

bool visited[100][100];								//강수량이 water일 때, 방문한 적 있는 노드
int dir[4][2] = { {-1,0}, {0,-1}, {0,1}, {1,0} };	//한 노드에서 갈 수 있는 네가지 방향

void DFS(int water, int r, int c) {
	visited[r][c] = 1;								//DFS에 들어오면 방문한 적 있다고 표시

	for (int i = 0; i < 4; i++) {
		int new_r = r + dir[i][0], new_c = c + dir[i][1];	//인접노드가 안전영역이면 확장
		if (new_r < 0 || new_r >= N || new_c < 0 || new_c >= N)
			continue;
		if (!visited[new_r][new_c] && map[new_r][new_c] > water)
			DFS(water, new_r, new_c);
	}
}

int getSafeArea(int water) {
	int safe_area = 0;
	for (int i = 0; i < N; i++)						//새로운 강수량일 때, 방문기록은 초기화
		memset(visited[i], false, sizeof(bool) * N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] > water && !visited[i][j]) {
				safe_area++;						//방문한적 없는, 강수량보다 높은 지대는 안전영역의 시작
				DFS(water, i, j);					//시작에서 더 나아갈 수 있는지 확인
			}
		}
	}
	return safe_area;
}

int main() {
	cin >> N;

	for (int i = 0; i < N; i++)			//입력
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (largest < map[i][j])				//땅의 높이중 최소최대를 구해서 강수량의 최소최대로 삼는다.
				largest = map[i][j];
			if (smallest > map[i][j])
				smallest = map[i][j];
		}

	for (int i = smallest; i <= largest; i++) {		//강수량 최소에서 최대까지 안전영역의 수의 최대를 구한다.
		int safe_area = getSafeArea(i);	
		if (safe_area > result)
			result = safe_area;
	}

	cout << result;						//출력
}
