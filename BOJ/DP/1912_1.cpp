#include <iostream>
using namespace std;

int DP[100001];		//각 인덱스당 연속합을 저장하는 배열

int main() {
	int N, max = -1001;
	cin >> N;
	
	for (int i = 1; i <= N; i++) {
		cin >> DP[i];

		//이전 인덱스의 연속합에 현재 값을 더한 값과 현재값을 비교하여 큰 수를 저장
		DP[i] = DP[i - 1] + DP[i] > DP[i] ? DP[i - 1] + DP[i] : DP[i];
		max = DP[i] > max ? DP[i] : max;	//max 저장
	}
	cout << max;
}
