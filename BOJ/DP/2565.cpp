DP를 구해서 답을 구했다.

#include <iostream>
#include <vector>
using namespace std;

int wires[501];			//인덱스는 A전봇대의 위치, 값은 A에서 연결된 B의 위치
int DP[501];			//A전봇대보다 작은 위치에서 교차하지 않고, 가질 수 있는 최대 전깃줄 수

int main() {
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int A, B;
		cin >> A >> B;

		wires[A] = B;
		DP[A] = 1;
	}

	for (int i = 1; i <= 500; i++) {
		if (wires[i] == 0)				//전깃줄이 아예 없는 경우
			continue;

		for (int j = i - 1; j >= 1; j--) {
			if (wires[j] == 0)			//전깃줄이 아예 없는 경우
				continue;

			if ((wires[i] - wires[j] >= 0) && (i - j >= 0)) {	//전깃줄이 교차하지 않는 경우
				DP[i] = DP[j] + 1 > DP[i] ? DP[j] + 1 : DP[i];	//DP로 최댓값 구하기
			}
		}
	}

	int max = -1;
	for (int i = 0; i < 501; i++) {
		max = DP[i] > max ? DP[i] : max;
	}
	
	cout << N - max;
}
