#include <iostream>
#include <deque>
#include <vector>

using namespace std;

deque<char> gear[4];

void rotate(int num, int clockwise) {
	if (clockwise == -1) {				//반시계방향이면 맨앞에걸 뒤로 넣기
		gear[num].push_back(gear[num].front());
		gear[num].pop_front();
	}
	else {								//시계방향이면 맨뒤에걸 앞으로 넣기
		gear[num].push_front(gear[num].back());
		gear[num].pop_back();
	}
}

void solve(int num, int clockwise, bool flag) {
	int cw = clockwise;
	int pre_nine = gear[num].at(6), pre_three = gear[num].at(2);	//비교를 위해 회전 전 9시, 3시 기억
	rotate(num, cw);

	for (int i = num - 1; i >= 0; i--) {		//num이전의 기어 회전
		if (pre_nine != gear[i].at(2)) {
			pre_nine = gear[i].at(6);
			cw *= -1;
			rotate(i, cw);
		}
		else
			break;
	}

	cw = clockwise;
	for (int i = num + 1; i < 4; i++){			//num이후의 기어 회전
		if (pre_three != gear[i].at(6)) {
			pre_three = gear[i].at(2);
			cw *= -1;
			rotate(i, cw);
		}
		else
			break;
	}
}

int main() {
	int N, score = 0;
	int num, clockwise;

	for (int i = 0; i < 4; i++) {		//gear input 받기
		string temp;
		cin >> temp;
		for (int j = 0; j < 8; j++) {
			gear[i].push_back(temp[j]);
		}
	}

	cin >> N;
	for (int i = 0; i < N; i++) {		//input대로 회전시키기
		cin >> num >> clockwise;
		solve(num - 1, clockwise, true);
	}

	if (gear[0].front() == '1') score += 1;		//점수 따기
	if (gear[1].front() == '1') score += 2;
	if (gear[2].front() == '1') score += 4;
	if (gear[3].front() == '1') score += 8;

	cout << score;
}
