# 선택 정렬

선택 정렬은 원리가 간단한 정렬 알고리즘 중 하나이다. 

### 원리
(오름차순 기준) 배열에 담긴 숫자를 처음부터 훑어나간다. 현재 숫자의 인덱스를 i라고 하면 i보다 큰 인덱스에 있는 숫자 중 가장 작은 수와 swap 한다.
가장 작은 수부터 앞으로 빼고 보는 간단한 논리의 정렬이다.


### 시간복잡도
첫번째 for loop가 n번 순회하고, 두번째 for루프는 n-i번 순회한다. 이 부분 배열의 크기는 n부터 1까지 감소하게 된다. n번동안 부분배열을 돌면서 비교하는 총 횟수는 n+(n-1)+(n-2)+...+2+1 이고 이는 n(n+1)/2가 된다.
즉 O(n^2)이 시간복잡도가 된다.


### 백준에관련 문제

[수 정렬하기1](https://www.acmicpc.net/problem/2750, "백준 수정렬하기1")

#### c++ 코드
```cpp
#include <iostream>
#include <vector>
using namespace std;

void selectionSort(vector<int> &nums) {
	for (int i = 0; i < nums.size() - 1; i++) {
		int smallest = nums[i], index = i;
		for (int j = i + 1; j < nums.size(); j++) {
			if (smallest > nums[j]) {
				smallest = nums[j];
				index = j;
			}
		}
		swap(nums[i], nums[index]);
	}
}

int main() {
	int N;
	cin >> N;
	vector<int> nums(N, 0);

	for(int i = 0; i < N; i++) {
		cin >> nums[i];
	}

	selectionSort(nums);

	for (int i = 0; i < N; i++) {
		cout << nums[i] << "\n";
	}	
}
```

#### python 코드
```python
def SelectionSort(nums):
    for i in range(len(nums) - 1):
        index = i
        for j in range(i, len(nums)):
            if nums[index] < nums[j]:          #내림차순 정렬
                index = j
        nums[i], nums[index] = nums[index], nums[i]

N = int(input())
nums = [int(input()) for n in range(N)]

SelectionSort(nums)

while(N):                                      #거꾸로 출력
    N -= 1
    print(nums[N])
```
