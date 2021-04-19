#include <iostream>
#include <cstring>
using namespace std;

int N;
int nums[101];

long long DP[101][1000];

long long solve(int idx, int tmp) {
	if (tmp < 0 || tmp > 20) return 0;

	if (idx == N)
		if (tmp == nums[N])
			return 1;
		else
			return 0;

	long long &ret = DP[idx][tmp];
	if (ret != -1)
		return ret;

	ret = 0;
	ret += solve(idx + 1, tmp + nums[idx]);
	ret += solve(idx + 1, tmp - nums[idx]);

	return ret;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> N;

	for (int i = 0; i < N; cin >> nums[++i]);
	memset(DP, -1, sizeof(DP));

	cout << solve(2, nums[1]);
}
