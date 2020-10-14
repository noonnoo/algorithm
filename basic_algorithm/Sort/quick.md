#  퀵 정렬

### 원리
정렬할 배열에서 기준원소(피봇, pivot)를 하나 고른다. 아무 원소나 임의로 골라도 되지만 코드에서는 맨 뒤의 원소를 기준원소로 삼으려고 한다.  
이 기준원소를 중심으로 더 작거나 같은 수는 왼쪽으로, 큰 수는 오른쪽으로 재배치한다.
![image](https://user-images.githubusercontent.com/33820372/95992932-74de1b00-0e69-11eb-9b2d-be8d32cd3107.png)  

기준원소가 분할된 양쪽 부분 사이에 자리하게 한다. 이렇게 분할된 왼쪽을 다시 quicksort로 정렬하고, 오른쪽도 마찬가지로 quicksort로 정렬한다.  
![image](https://user-images.githubusercontent.com/33820372/95992988-845d6400-0e69-11eb-9ef6-5b5c7e3e5801.png)  


### 분할 원리  
pivot을 기준으로 왼쪽은 작은 수들을, 오른쪽은 큰 원소들을 재배치하는 과정이다.  
처음부터 시작해서 작은 원소를 만나면 이를 큰 원소 중 가장 작은 인덱스 값을 가진 원소와 swap하면 된다.  
![image](https://user-images.githubusercontent.com/33820372/95993054-9939f780-0e69-11eb-966b-8854bad986a2.png)  

이렇게 swap하다 보면 위와 같이 파란쪽은 11보다 작은 숫자, 초록색쪽은 11보다 큰 숫자가 모이게 된다.  
여기서 11과 48을 swap하면 11을 기준으로 왼쪽과 오른쪽을 작은수와 큰 수로 나눌 수 있다.
![image](https://user-images.githubusercontent.com/33820372/95993092-a2c35f80-0e69-11eb-90d3-142b2a0e835f.png)  


### 시간복잡도
pivot인 숫자가 정렬된 상태에서 딱 중간에 있는 값이고 계속해서 지정된 피봇이 중간값이라면 분할은 모든 원소를 훑어 나가는 작업이기 때문에 O(N) 시간이 든다. 그리고 최선의 경우에서 반반씩 계속해서 분할하는 경우는 병합정렬과 마찬가지로 반씩 잘라서 내려가기 때문에 O(logN)의 시간이 들고 이를 합치면 최선의 경우에서 O(N*logN)의 시간복잡도를 가진다.  
최악의 경우는 pivot이 한쪽으로 치우친 경우이다. 분할은 마찬가지로 모든 원소를 훑어나가기 때문에 O(N)의 시간복잡도를 가진다. 그리고 피봇을 선정하면서 계속해서 피봇이 한쪽에 치우쳐 있으면 O(N-1)만큼을 살펴야 하는 것이 되므로 총 시간 복잡도는 O(N^2)으로 표현할 수 있다.

### 백준 관련 문제

[수 정렬하기1](https://www.acmicpc.net/problem/2750)  

#### c++ 코드
```cpp
#include <iostream>
using namespace std;

int nums[1000000];

int partition(int s, int e) {
	int pivot = nums[e];
	int i = s - 1;

	for (int j = s; j <= e; j++) {
		if (j == e || nums[j] <= pivot) 
			swap(nums[++i], nums[j]);
	}

	return i;
}

void quickSort(int s, int e) {
	if (s < e) {
		int m = partition(s, e);
		quickSort(s, m - 1);
		quickSort(m + 1, e);
	}
}

int main() {
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> nums[i];
	}

	quickSort(0, N - 1);

	for (int i = 0; i < N; i++) {
		cout << nums[i] << "\n";
	}
}
```  

### python 코드
```pyimport sys
import math
sys.setrecursionlimit(2000)

N = int(input())
nums = [int(input()) for n in range(N)]
tmp = list(nums)

def partition(s,e):
    pivot = nums[e]
    i = s - 1

    for j in range(s, e+1):
        if(j == e or nums[j] <= pivot):
            i += 1
            nums[i], nums[j] = nums[j], nums[i]

    return i

def quickSort(s,e):
    if(s < e):
        m = partition(s, e)
        quickSort(s, m-1)
        quickSort(m+1, e)

quickSort(0, N-1)

for i in range(N):
    print(nums[i])
```
