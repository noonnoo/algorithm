# 삽입정렬

### 원리
i번째까진는 정렬된 배열이 있고, 여기에 num이라는 숫자를 삽입하려고 한다. 
num이 들어가야하는 위치를 찾아서 그 자리에 해당 숫자를 삽입하면 된다.
![image](https://user-images.githubusercontent.com/33820372/95770376-47239580-0cf4-11eb-8e2c-fee0b2d1ea51.png)

### 시간복잡도
삽입정렬도 구현이 간단한 정렬 중 하나이지만, 배열이 길어지면 효율이 떨어진다. 또한 중간에 숫자를 삽입하는 것은 링크드 리스트가 아니라면 그 이후 항목들이 하나씩 밀어내야 하기 때문에 효율이 떨어진다.
배열이 정렬되어 있지 않은 최악의 경우라면 시간 복잡도는 O(N^2)이 되겠지만, 배열이 이미 정렬되어 있는 최선의 경우에 시간복잡도는 O(N)으로 빠르다.


### 백준 관련 문제

[수 정렬하기1](https://www.acmicpc.net/problem/2750)

#### c++ 코드
```cpp
#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<int> &nums) {
	for (int i = 1; i < nums.size(); i++) {
		int num = nums[i];
		int j;
		for (j = i - 1; j >= 0 && nums[j] > num; j--) {    //num보다 큰 숫자들은 뒤로 밀림
			nums[j + 1] = nums[j];
		}
		nums[j + 1] = num;
	}
}

int main() {
	int N;
	cin >> N;
	vector<int> nums(N, 0);

	for (int i = 0; i < N; i++) {
		cin >> nums[i];
	}

	insertionSort(nums);

	for (int i = 0; i < N; i++) {
		cout << nums[i] << "\n";
	}
}
```

#### python 코드
```python
def insertionSort(nums):
    for i in range(1, len(nums)):
        num = nums[i]
        j = i-1
        while(j >= 0 and nums[j] > num):         #num보다 큰 숫자들은 뒤로 밀림
            nums[j+1] = nums[j]
            j -= 1
        nums[j+1] = num

N = int(input())
nums = [int(input()) for n in range(N)]

insertionSort(nums)

for i in range(N):                                 #출력
    print(nums[i])
```
