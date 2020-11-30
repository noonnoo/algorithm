#include <iostream>
using namespace std;

int main() {
	int N, max = -1001;
	int pre = 0, curr;
	cin >> N;
	
	for (int i = 1; i <= N; i++) {
		cin >> curr;

		//이전 인덱스의 연속합에 현재 값을 더한 값과 현재값을 비교하여 큰 수를 저장
		curr = pre + curr > curr ? pre + curr : curr;
		max = curr > max ? curr : max;	//max 저장
		pre = curr;
	}
	 
	cout << max;
}
