#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

bool grid[101][101];		//(y,x)

void dragon_curve() {
	int x, y, d, g;
	cin >> x >> y >> d >> g;
	pair<int, int> dot = make_pair(x, y);		//마지막 페어(x,y)
	vector<pair<int, int>> dots;				//x, y

	dots.push_back(make_pair(x, y));
	grid[y][x] = true;

	if (d == 0)									//0세대 두번째 점 구하기
		dot.first++;
	else if (d == 1)
		dot.second--;
	else if (d == 2)
		dot.first--;
	else if (d == 3)
		dot.second++;
	dots.push_back(dot);
	grid[dot.second][dot.first] = true;

	
	for (int i = 0; i < g; i++) {
		for (int j = pow(2, i); j > 0; j--) {		//마지막 점부터 첫번째까지
			if (dots[j].first + 1 == dots[j - 1].first)		//x위치 +1
				dot.second++;
			else if (dots[j].first - 1 == dots[j - 1].first) 	//x위치 -1
				dot.second--;
			else if (dots[j].second + 1 == dots[j - 1].second) 		//y위치 +1
				dot.first--;
			else if (dots[j].second - 1 == dots[j - 1].second) 		//y위치 -1
				dot.first++;

			dots.push_back(dot);
			grid[dot.second][dot.first] = true;
		}
	}
}

int count_square() {		//네 꼭짓점이 모두 드래곤 커브의 꼭짓점인 정사각형 개수
	int count = 0;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (grid[i][j] && grid[i + 1][j] && grid[i][j + 1] && grid[i + 1][j + 1])
				count++;
		}
	}
	return count;
}

int main() {
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
		dragon_curve();

	cout << count_square();
}
