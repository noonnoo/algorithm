# 버블 정렬

버블 정렬도 선택정렬과 마찬가지로 간단한 정렬 알고리즘 중 하나이다.


### 원리
버블 정렬도 선택정렬과 마찬가지로 제일 큰/작은 원소를 끝자리로 옮기는 작업을 반복한다. 
숫자가 있는 배열의 처음부터 for문을 돌면서 i번째 숫자와 i+1번째 숫자를 비교하고 i번째 수가 더 큰 경우 둘을 swap한다.  왼쪽부터 이웃한 수를 비교하면서 순서가 제대로 되어 있지 않으면 하나하나 바꾸어 나가는 정렬이다.
맨 끝부터 큰수를 채워나가는 형식이다.


### 시간복잡도
선택정렬과 마찬가지로 첫번째 for문은 n번을 돌아간다. 두번째 for문은 n-i번을 순환한다. 그러니까 선택정렬과 같이 O(n^2)의 시간복잡도를 가진다. 
그런데 버블정렬이 선택정렬보다 효율이 조금 떨어진다. 선택정렬은 두번째 for문을 돌면서 비교한 값 중 하나만을 swap하면 되지만 버블 정렬은 매번 비교하고 순서가 제대로 되어 있지 않으면 매번 swap하는 과정을 거쳐야 하기 때문이다.

-----

### 백준 관련 문제

[수 정렬하기1](https://www.acmicpc.net/problem/2750, "백준 수정렬하기1")

#### c++ 코드
```cpp
#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(vector<int> &nums) {
	for (int i = 0; i < nums.size() - 1; i++) {
		for (int j = i + 1; j < nums.size(); j++) {
			if (nums[i] > nums[j])        //i번째 수보다 작은 수를 앞으로 뺌
				swap(nums[i], nums[j]);
		}
	}
}

int main() {
	int N;
	cin >> N;
	vector<int> nums(N, 0);

	for(int i = 0; i < N; i++) {
		cin >> nums[i];
	}

	bubbleSort(nums);

	for (int i = 0; i < N; i++) {
		cout << nums[i] << "\n";
	}	
}
```

#### python 코드
```python
#python 코드
def bubbleSort(nums):
    for i in range(len(nums) - 1):
        for j in range(i, len(nums)):
            if nums[i] < nums[j]:          #내림차순 정렬
                nums[i], nums[j] = nums[j], nums[i]

N = int(input())
nums = [int(input()) for n in range(N)]

bubbleSort(nums)

while(N):                                  #거꾸로 출력
    N -= 1
    print(nums[N])
```

-----

### 개선된 버블정렬
버블정렬은 이미 정렬되어 있거나 중간에 정렬이 완료되더라도 의미없는 수행을 반복한다. 
이를 개선하기 위한 장치가 있다. 두번째 for문을 돌면서 수들간의 swap이 한차례도 없다면 이미 정렬이 완료된 상태로 생각하고 수행을 끝낸다. 
```cpp
void bubbleSort(vector<int>& nums) {
	for (int i = 0; i < nums.size(); i++) {
		bool sorted = true;
		for (int j = i + 1; j < nums.size(); j++) {
			if (nums[i] > nums[j]) {        //i번째 수보다 작은 수를 앞으로 뺌
				swap(nums[i], nums[j]);
				sorted = false;
			}
		}
		if (sorted) break;
	}
}
```

### 개선된 버블정렬 관련 백준 
[버블정렬](https://www.acmicpc.net/problem/1838, "버블정렬")

이 문제는 개선된 버블 정렬이 어느 시점에서 끝내고 break되는 지를 출력하는 문제이다.
진짜로 버블 정렬을 사용하면 N의 개수가 50만개이 때문에 시간초과가 난다. 

문제에서의 버블정렬은 두번째 for문을 한번 끝내고 나면, 큰 수가 마지막으로 가게된다. 두번째 for문이 몇번 돌고 끝나는가가 이 문제에서의 관건이다. 앞에 있던 큰 수가 뒤로 가는 것은 for문이 수행하는 과정에서 일어나는 것이고, 뒤에 있던 작은 수가 언제 앞으로 오는 것이 의미가 있다. 

뒤에 있던 작은 수는 두번째 for문을 한번 돌 때마다 한칸씩 앞으로 이동할 수 있다. 뒤에 있던 작은 수가 3칸을 이동했다면 두번째 for문이 최소한 3번 돌았다는 이야기가 된다.

그래서 원래 숫자들의 위치와 정렬이 완료된 숫자들의 위치의 차가 가장 큰 것이 이 문제에서 요구하는 답이 된다.

#### c++ 코드
```cpp
#include <iostream>
#include <algorithm>
using namespace std;

pair<int, int> nums[500000];

int main() {
	int N, ans = 0;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> nums[i].first;
		nums[i].second = i;
	}

	sort(nums, nums + N);

	for (int i = 0; i < N; i++) {
		ans = max(ans, nums[i].second - i);
	}

	cout << ans;
}
```
