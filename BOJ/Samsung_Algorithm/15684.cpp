#include <iostream>
#include <vector>
using namespace std;

bool ladder[31][11];	//가로 점선, 세로선
int N, M, H;
int minimum;			//출력할 최솟값

bool move() {
	for (int i = 1; i <= N; i++) {		//세로선
		int curr = i;	
		for (int j = 1; j <= H; j++) {	//가로점선
			if (ladder[j][curr]) curr++;
			else if (ladder[j][curr - 1]) curr--;
		}
		if (curr != i) return false;
	}
	return true;
}

void solve(int a, int b, int depth) {	//a는 가로점선, b는 세로선
	if (depth > 3)						//깊이가 3 이상아면, 그러니까 새로 만든 사다리 수가 3개 이상이면 return
		return;
	if (move()) {						//사다리 게임을 해보고, 조건에 부합하면 return
		if (minimum > depth)
			minimum = depth;
		return;
	}

	for (int i = a; i <= H; i++) {
		for (int j = 1; j < N; j++) {
			if (ladder[i][j] || ladder[i][j - 1] || ladder[i][j + 1]) continue;		//좌우,현위치에 사다리가 있으면 pass
																					//index는 i와 j모두 최소가 1이고, ladder는 전역변수이기 때문에 쁠마 1씩 접근 가능하다
			ladder[i][j] = true;
			solve(i, j, depth + 1);
			ladder[i][j] = false;
		}
	}
}

int main() {
	cin >> N >> M >> H;		//세로선, 가로선 놓인 위치, 가로선 놓을 수 있는 위치
	minimum = 4;
	for (int i = 0; i < M; i++) {
		int a, b;			//a 점선, b번 세로선
		cin >> a >> b;
		ladder[a][b] = true;
	}

	solve(1, 1, 0);
	cout << (minimum < 4 ? minimum : -1);
}
