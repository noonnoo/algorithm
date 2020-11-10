#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;

	int pre1 = 1, pre2 = 0, curr = 2;

	for (int i = 1; i <= N; i++) {
		curr = (pre1 % 15746 + pre2 % 15746) % 15746;
		pre2 = pre1;
		pre1 = curr;
	}

	cout << curr;
}
