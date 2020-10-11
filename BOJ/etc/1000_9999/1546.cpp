#include <iostream>
using namespace std;

double nums[1001];

int main() {
	int N;
	double maxi = -1, sum = 0;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> nums[i];
		if (nums[i] > maxi)
			maxi = nums[i];
	}

	for (int i = 0; i < N; i++) {
		nums[i] = nums[i] / maxi * 100;
		sum += nums[i];
	}

	cout << (double)sum / N;
}
