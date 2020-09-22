#include <iostream>
using namespace std;

void solve() {
	unsigned int x, y;
	long long count = -1;
	cin >> x >> y;
	
	unsigned int sub = y - x;
	
	int twice = 0;
	int index = -1, d = 1;
	while (count < sub) {
		count += d;

		if (twice == 2) {
			twice = 0;
			d++;
		}
		twice++;
		index++;
	}
	
	cout << index << "\n";
}

int main() {
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
		solve();
}
