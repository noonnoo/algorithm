#include <iostream>
#include <vector>
#include <string>
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
	int N, M;
	cin >> N >> M;
	vector<int> nums;

	for (int i = 0; i < N; i++) {
		nums.push_back(i + 1);
	}

	pi(nums, "", M, 0);
}
