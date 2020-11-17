#include <iostream>
using namespace std;

int nums[100001];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	int N, S;
	cin >> N >> S;
	for (int i = 0; i < N; i++)
		cin >> nums[i];

	int s = 0, e = 0, ret = 100000001, sum = 0;

	while (true) {
		if (sum >= S) {
			sum -= nums[s++];
			ret = ret > e - s + 1 ? e - s + 1 : ret;
		}
		else if (e == N)
			break;
		else
			sum += nums[e++];
	}

	if (ret == 100000001)
		cout << 0;
	else
		cout << ret;
}
