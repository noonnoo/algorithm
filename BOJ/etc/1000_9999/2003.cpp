#include <iostream>
using namespace std;

int nums[10000];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> nums[i];

	int s = 0, e = 0, ret = 0, sum = 0;

	while (true) {
		if (sum >= M)
			sum -= nums[s++];
		else if (e == N)
			break;
		else
			sum += nums[e++];
		if (sum == M)
			ret++;
	}

	cout << ret;
}
