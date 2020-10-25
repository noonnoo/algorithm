#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 100001
using namespace std;

int N, M;
int nums[MAX], target[MAX];

bool exist(int t) {
	int mini = 0, maxi = N;

	while (mini < maxi) {
		int mid = (mini + maxi) / 2;

		if (t > nums[mid])
			mini = mid + 1;
		else if (t < nums[mid])
			maxi = mid;
		else
			return true;
	}
	return false;
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> nums[i];

	cin >> M;
	for (int i = 0; i < M; i++)
		cin >> target[i];

	sort(nums, nums + N);

	for (int i = 0; i < M; i++) {
		cout << exist(target[i]) << "\n";
	}

}
