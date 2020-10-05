#include <iostream>
#include <vector>
using namespace std;

//U,D,F,B,L,R 순서
vector<vector<char>> cube;

int rotates[6][4] = { {2,5,3,4}, {2,4,3,5},		//i번째 면을 반시계방향으로 돌릴때 돌아가는 면
					  {1,5,0,4}, {1,4,0,5},
					  {1,2,0,3}, {1,3,0,2} };

int indexes[6][4][3] = { { {0,1,2}, {0,1,2}, {8,7,6}, {0,1,2} },	//돌아가는 면의 돌아가는 칸
						 { {8,7,6}, {8,7,6}, {0,1,2}, {8,7,6} },
						 { {0,1,2}, {6,3,0}, {8,7,6}, {2,5,8} },
						 { {8,7,6}, {6,3,0}, {0,1,2}, {2,5,8} },
						 { {0,3,6}, {0,3,6}, {0,3,6}, {0,3,6} },
						 { {2,5,8}, {2,5,8}, {2,5,8}, {2,5,8} } };
int index[8] = { 0,1,2,5,8,7,6,3 };							//돌아가는 면에서 칸들의 인덱스

void rotate(int r, char clockwise) {						//방향에 따라 면 돌리기
	vector<vector<char>> copied = cube;

	for (int i = 0; i < 4; i++) {							//1.돌아가는 면의 주위 면들희 회전
		int pre = 0, curr = 0;
		if (clockwise == '-') {
			pre = i == 0 ? 3 : i - 1;
			curr = i;
		}
		else {
			pre = i == 3 ? 0 : i + 1;
			curr = i;
		}

		for (int j = 0; j < 3; j++) { 						//이전 면의 정해진 인덱스를 copy해오기
			cube[rotates[r][curr]][indexes[r][curr][j]] = copied[rotates[r][pre]][indexes[r][pre][j]];
		}
	}

	if (clockwise == '-') {									//2.돌아가는 면에서 칸의 회전
		for (int i = 0; i < 8; i++) {
			cube[r][index[i]] = copied[r][index[i + 2 <= 7 ? i + 2 : i + 2 - 8]];
		}
	} else {
		for (int i = 7; i >= 0; i--)
			cube[r][index[i]] = copied[r][index[i - 2 >= 0 ? i - 2 : i - 2 + 8]];
	}
}

void solve() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		string temp;
		cin >> temp;

		int p = 0;
		if(temp[0] == 'U')
			p = 0;
		else if (temp[0] == 'D')
			p = 1;
		else if (temp[0] == 'F')
			p = 2;
		else if (temp[0] == 'B')
			p = 3;
		else if (temp[0] == 'L')
			p = 4;
		else if (temp[0] == 'R')
			p = 5;

		rotate(p, temp[1]);			//해당 면을 기준으로 시계, 혹은 반시계 회전
	}
}

void print() {
	for (int i = 0; i < 9; i++) {
		cout << cube[0][i];
		if (i % 3 == 2)
			cout << "\n";
	}
}

int main() {
	int N;
	cin >> N;
	vector<vector<char>> origin = { {'w','w','w','w','w','w','w','w','w'},	//큐브 원형
								  {'y','y','y','y','y','y','y','y','y'},	//UDFBLR 순서
								  {'r','r','r','r','r','r','r','r','r'},
								  {'o','o','o','o','o','o','o','o','o'},
								  {'g','g','g','g','g','g','g','g','g'},
								  {'b','b','b','b','b','b','b','b','b'} };

	for (int i = 0; i < N; i++) {
		cube = origin;
		solve();
		print();
	}
}
