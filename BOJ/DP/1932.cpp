#include <iostream>
using namespace std;

int DP[125251];

int main() {
	int N;
	cin >> N;

	for (int i = 0; i < N * (N + 1) / 2; i++)
		cin >> DP[i];

	for (int i = N - 1; i >= 0; i--) {
		int init = i * (i - 1) / 2;
		for (int j = init; j < init + i; j++) {
			//i층의 j번째 숫자는 i+1층의 j번째 혹은 j+1번째 숫자 중 큰 수를 더하여 값을 갖는다.
			DP[j] += DP[j + i] > DP[j + i + 1] ? DP[j + i] : DP[j + i + 1];
		}
	}

	cout << DP[0] << "\n";
}
