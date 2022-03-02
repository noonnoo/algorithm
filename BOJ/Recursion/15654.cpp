#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int N, M;
vector<int> nums;

void swap(int& A, int& B) {
	int temp = A;
	A = B;
	B = temp;
}

void permutation(vector<int> result, vector<bool> v, int curr) {
	if (M == curr) {
		for (int i = 0; i < M; i++) 
			cout << result[i] << " ";
		cout << "\n";
		return;
	}

	for (int i = 0; i < N; i++) {
		if (!v[i]) {
			v[i] = true;
			result[curr] = nums[i];
			permutation(result, v, curr + 1);
			v[i] = false;
		}
	}
}

int main() {
	int tmp;
	cin >> N >> M;
	vector<int> result(N, 0);
	vector<bool> v(N, false);

	for (int i = 0; i < N; i++) {
		cin >> tmp;
		nums.push_back(tmp);
	}

	sort(nums.begin(), nums.end());
	permutation(nums, v, 0);
}
