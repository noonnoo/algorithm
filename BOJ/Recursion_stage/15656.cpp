#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void pi(vector<int>& nums, string str, int M, int index) {
	if (index == M) {
		cout << str << "\n";
		return;
	}

	for (int i = 0; i < nums.size(); i++) {
		pi(nums, str + to_string(nums[i]) + " ", M, index + 1);
	}
}

int main() {
	int N, M, tmp;
	cin >> N >> M;
	vector<int> nums;

	for (int i = 0; i < N; i++) {
		cin >> tmp;
		nums.push_back(tmp);
	}

	sort(nums.begin(), nums.end());
	pi(nums, "", M, 0);
}
