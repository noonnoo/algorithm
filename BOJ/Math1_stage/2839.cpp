#include <iostream>
using namespace std;

int main() {
	int N, result = -1;
	cin >> N;

	if (N % 5 == 0) {
		cout << N / 5;
	}
	else if ((N % 5) % 3 == 0) {
		result = (N / 5) + ((N % 5) / 3);
		cout << result;
	}
	else {
		for (int i = 0; i <= (N / 5); i++) {
			int num = N - 5 * i;
			if (num % 3 == 0 && (result == -1 || result > i + (num / 3)))
				result = i + (num / 3);
		}
		cout << result;
	}
}
