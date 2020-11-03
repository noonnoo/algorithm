#include <iostream>
using namespace std;

int R, C, maxi = -1;
bool alphabet[26];
char map[21][21];
int r[4] = { -1, 0, 0, 1 }, c[4] = { 0, -1, 1, 0 };

void DFS(int cr, int cc, int cnt) {    //현재 위치와 현재까지 count
	for (int i = 0; i < 4; i++) {
		int nr = cr + r[i];            //다음 위치
		int nc = cc + c[i];

		if (nr < 0 || nr >= R || nc < 0 || nc >= C)
			continue;

		if (alphabet[map[nr][nc] - 65]) {
			if (cnt > maxi)
				maxi = cnt; 
			continue;
		}
		else {
			alphabet[map[nr][nc] - 65] = true;
			DFS(nr, nc, cnt + 1);
			alphabet[map[nr][nc] - 65] = false;
		}
	}
}

int main() {
	cin >> R >> C;

	char tmp[21];
	for (int i = 0; i < R; i++) {
		cin >> tmp;
		for (int j = 0; j < C; j++) {
			map[i][j] = tmp[j];
		}
	}

	alphabet[map[0][0] - 65] = true;
	maxi = 1;
	DFS(0, 0, 1);
	cout << maxi;
}
