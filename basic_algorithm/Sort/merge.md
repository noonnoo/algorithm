#  병합정렬

### 원리
입력된 숫자 배열을 반으로 나눈다. 반으로 나눈 전반부와 후반부로 생각하고, 이를 독립적으로 정렬시킨 후 둘을 병합해준다.  
![image](https://user-images.githubusercontent.com/33820372/95770842-fceee400-0cf4-11eb-8e9f-d48105ec2ceb.png)  

그림에서는 편의상 나눠진 배열 중 맨 앞부분의 코드만을 표시했지만, 배열이 반으로 나눠졌다가 합쳐지는 과정의 위와 같다.  
병합정렬에서 가장 중요한 부분은 역시 병합하는 과정이다. 아래 그림은 위 그림의 깊이1에서 깊이 0으로 돌아오는 과정을 상세히 표현한 것이다. 전반부 배열과 후반부 배열의 index를 따로 두고, 각각의 인덱스에 있는 값 중 더 작은 것을 tmp에 옮겨 담고 인덱스에 1씩 더해준다. 끝까지 옮겨 담기를 마쳤으면 남은 한쪽을 마저 tmp 배열에 옮겨주면 된다.  
tmp배열이 정렬된 배열이 된다.  
![image](https://user-images.githubusercontent.com/33820372/95770886-1132e100-0cf5-11eb-986e-cb7ddb7aadc9.png)



### 시간복잡도
merge sort는 쪼개진 배열이 정렬이 되어있든 아니든 모두 잘게 쪼개고 병합하는 과정을 거친다. 그래서 최악, 최선의 경우 모두 시간복잡도가 같다.
재귀적 호출로 n개의 문제를 두개의 n/2개의 문제로 쪼개서 처리하게 된다.  다시 두개의 n/2는 4개의 n/4개의 문제가 되고 이를 계속해서 쪼개는 과정을 다음과 같은 수식으로 표현할 수 있다.  
![image](https://user-images.githubusercontent.com/33820372/95770954-2dcf1900-0cf5-11eb-8b34-7105e369fcfc.png)  
n = k^2이라고 가정하자. 위 수식에서 cn은 병합하는데 걸리는 시간을 의미한다.
수식 점화식을 따라가다보면 최악의 경우에 O(nlogn)의 시간복잡도를 가짐을 알 수 있다.

### 백준 관련 문제

[수 정렬하기1](https://www.acmicpc.net/problem/2750)  
[수 정렬하기2](https://www.acmicpc.net/problem/2751)  

#### c++ 코드
```cpp
#include <iostream>
#include <vector>
using namespace std;

int nums[1000000];
int tmp[1000000];

void merge(int s, int m, int e) {
	int t = s;
	int i = s, j = m + 1;
	while (i <= m && j <= e) {
		if (nums[i] <= nums[j])
			tmp[t++] = nums[i++];
		else
			tmp[t++] = nums[j++];
	}

	while (i <= m) 
		tmp[t++] = nums[i++];

	while (j <= e) 			
		tmp[t++] = nums[j++];


	for (int k = s; k <= e; k++) {
		nums[k] = tmp[k];
	}
}

void mergeSort(int s, int e) {
	if (s >= e)
		return;

	int m = (s + e) / 2;
	mergeSort(s, m);
	mergeSort(m + 1, e);
	merge(s, m, e);
}

int main() {
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> nums[i];
		tmp[i] = nums[i];
	}

	mergeSort(0, N - 1);
	for (int i = 0; i < N; i++) {
		cout << nums[i] << "\n";
	}
}
```
