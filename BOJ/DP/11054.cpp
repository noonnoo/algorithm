#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int LIS[1001];
int LIS_r[1001];
int arr[1001];

int main() {
	int N, max = -1;
	cin >> N;

	for (int i = 1; i <= N; i++)
		cin >> arr[i];
	
	for (int i = 1; i <= N; i++) {
		LIS[i] = 1;

		for (int j = i - 1; j >= 1; j--)
			if (arr[i] > arr[j]) {
				LIS[i] = LIS[j] + 1 > LIS[i] ? LIS[j] + 1 : LIS[i];
			}

		int index_r = N - i + 1;
		LIS_r[index_r] = 1;
		for (int k = index_r; k <= N; k++)
			if (arr[index_r] > arr[k]) {
				LIS_r[index_r] = LIS_r[k] + 1 > LIS_r[index_r] ? LIS_r[k] + 1 : LIS_r[index_r];
			}
	}

	for(int i = 1 ; i <= N; i++)
		if (LIS[i] + LIS_r[i] > max)
			max = LIS[i] + LIS_r[i];

	cout << max - 1;
}
