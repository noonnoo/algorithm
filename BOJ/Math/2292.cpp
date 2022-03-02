#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;

	if (N == 1)
		cout << 1;
	else {
		int i = 0;
		while (true) {
			//2를 빼주 것은 1은 제외되기 때문에 하나 빼고, N이 6의 배수인 경우 나눈 값에서 1을 빼줘야하기 때문
			if (N - 2 < (i * (i - 1) / 2) * 6)	
				break;
			i++;
		}

		cout << i;
	}
}
