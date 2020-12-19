#include <iostream>
#include <string>
#include <vector>
using namespace std;

int N;

void press(vector<vector<int>> &room, int r, int c, int &cnt) {
	int dr[] = { 0, -1, 0, 0, 1 };
	int dc[] = { 0, 0, -1, 1, 0 };

	for (int i = 0; i < 5; i++) {
		int nr = r + dr[i];
		int nc = c + dc[i];

		if (nr < 0 || nc < 0 || nr > N - 1 || nc > N -1)continue;

		if (room[nr][nc] == 1) room[nr][nc] = 0;
		else room[nr][nc] = 1;
	}
	cnt++;
}


int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> N;

	vector<vector<int>> room(N, vector<int>(N, 0));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> room[i][j];
	
	int ans = N * N + 1;
	for (int bulb = 0; bulb < (1 << N); bulb++) {
		int cnt = 0;
		vector<vector<int>> changed = room;

		//bulb에서 i번째 비트가 켜져있으면 첫행의 i열을 누른다.
		for (int i = 0; i < N; i++)
			if (bulb & (1 << i))
				press(changed, 0, i, cnt);

		//1행부터 이전 행의 스위치가 켜져있으면 누른다.
		for (int i = 1; i < N; i++)
			for (int j = 0; j < N; j++) {
				if (changed[i - 1][j] == 0) continue;
				press(changed, i, j, cnt);
			}
		
		//마지막 행이 모두 꺼져있는지 확인하고 꺼져있다면 ans 업데이트
		bool flag = true;
		for (int i = 0; i < N; i++)
			if (changed[N - 1][i] == 1) {
				flag = false;
				break;
			}

		if (flag) ans = min(ans, cnt);
	}
	cout << (ans == N * N + 1 ? -1 : ans);
}
