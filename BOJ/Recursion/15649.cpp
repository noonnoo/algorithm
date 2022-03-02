#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

void swap(int& A, int& B) {
	int temp = A;
	A = B;
	B = temp;
}

void permutation(vector<string> & results, vector<int> &nums,int depth, int curr) {
	if (depth == curr) {
		string str ="";
		for (int i = 0; i < depth; i++) {
			str += (nums[i] + '0');
			str += " ";
		}
		results.push_back(str);
		return;
	}

	for (int i = curr; i < nums.size(); i++) {
		swap(nums[curr], nums[i]);
		permutation(results, nums, depth, curr+1);
		swap(nums[curr], nums[i]);
	}
}

int main() {
	int N, M;
	cin >> N >> M;
	vector<int> nums;
	vector<string> results;

	for (int i = 0; i < N; i++) {
		nums.push_back(i + 1);
	}

	permutation(results, nums, M, 0);

	sort(results.begin(), results.end());
	for (int i = 0; i < results.size(); i++)
		cout << results[i] << "\n";
}
