#include <iostream>
#include <string>
using namespace std;

void digit_sort(int N) {
	int digit[10] = { 0, };
	string num = to_string(N);

	for (int i = 0; i < num.size(); i++) {
		digit[num[i] - '0']++;
	}

	for (int i = 9; i >= 0; i--)
		for (int j = 0; j < digit[i]; j++)
			cout << i;
}

int main() {
	long long N;
	cin >> N;

	digit_sort(N);
}
