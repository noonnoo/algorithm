#include <iostream>
#include <vector>
#define MAX 2000001
using namespace std;

int N;
int ans = 0;
bool visited[MAX];

void combination(vector<int> &nums, int sum, int idx) {	 //수열의 모든 조합 만들면서 부분 수열의 합 부분을 true로 표시
	if (idx == N) {
		visited[sum] = true;		
		return;
	}

	combination(nums, sum + nums[idx], idx + 1);
	combination(nums, sum, idx + 1);
}

int main() {
	cin >> N;
	vector<int> nums(N);

	for (int i = 0; i < N; i++) {
		cin >> nums[i];
	}

	combination(nums, 0, 0);

	for (int i = 1; i < MAX; i++)		//처음부터 MAX까지 방문하지 않은 자연수 출력 후 종료
		if (!visited[i]) {
			cout << i;
			return 0;
		}
}
