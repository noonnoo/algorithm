#include <iostream>
#include <string>
#include <vector>
using namespace std;

void press(vector<string> &room, int r, int c, int &cnt) {
	int dr[] = { 0, -1, 0, 0, 1 };
	int dc[] = { 0, 0, -1, 1, 0 };

	for (int i = 0; i < 5; i++) {
		int nr = r + dr[i];
		int nc = c + dc[i];

		if (nr < 0 || nc < 0 || nr > 9 || nc > 9)continue;

		if (room[nr][nc] == '#') room[nr][nc] = 'O';
		else room[nr][nc] = '#';
	}
	cnt++;
}


int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	vector<string> room(10, "");	
	for (int i = 0; i < 10; i++) 
		cin >> room[i];
	
	int ans = 101;
	for (int bulb = 0; bulb < (1 << 10); bulb++) {
		int cnt = 0;
		vector<string> changed = room;

		//bulb에서 i번째 비트가 켜져있으면 첫행의 i열을 누른다.
		for (int i = 0; i < 10; i++) 
			if (bulb & (1 << i))
				press(changed, 0, i, cnt);

		//1행부터 이전 행의 스위치가 켜져있으면 누른다.
		for (int i = 1; i < 10; i++) 
			for (int j = 0; j < 10; j++) {
				if (changed[i - 1][j] == '#') continue;
				press(changed, i, j, cnt);
			}
		
		//마지막 행이 모두 꺼져있는지 확인하고 꺼져있다면 ans 업데이트
		bool flag = true;
		for (int i = 0; i < 10; i++) 
			if (changed[9][i] == 'O') {
				flag = false;
				break;
			}

		if (flag) ans = min(ans, cnt);
	}
	cout << (ans == 101 ? -1 : ans);
}
