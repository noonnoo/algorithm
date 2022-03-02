#include <iostream>
#include <cmath>
using namespace std;

int nums[8001];

void counting_sort(int N) {
	int min = 4001, max = -4001;
	int mode = -1, sum = 0;

	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		nums[temp + 4000]++;

		if (max < temp)							//범위 위한 최대 최소
			max = temp;	
		if (min > temp)
			min = temp;

		sum += temp;							//산술평균 위해 합

		if (mode < nums[temp + 4000])			//최빈값 구하기
			mode = nums[temp + 4000];
	}
	cout << round((double)sum / N) << endl;		//산술평균


	int count = 0, mode_index = -1, mode_count = 0;
	bool mid_printed = false;
	for (int i = 0; i < 8001; i++) {
		count += nums[i];
		if (!mid_printed && count >= (N / 2 + 1)) {
			cout << i - 4000 << endl;			//중앙값
			mid_printed = true;
		}

		if (mode == nums[i] && mode_count < 2) {//최빈값 중 겹치면 두번째 것 찾기
			mode_index = i;
			mode_count++;
		}
	}
	
	cout << mode_index - 4000 << endl			//최빈값
		 << max - min << endl;					//범위

}

int main() {
	long long N;
	cin >> N;

	counting_sort(N);
}
