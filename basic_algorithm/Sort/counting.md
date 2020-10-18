#  계수 정렬

### 원리
계수정렬은 정렬하고자 하는 원소들의 값이 특정 숫자 N을 넘지 않는 경우에 사용할 수 있다.  
계수정렬은 먼저 input(A[1....k])으로 들어온 원소들을 모두 훑어본 후, 1부터 k까지의 자연수가 각각 몇번 나오는지를 세어본다.  

이렇게 숫자를 센 배열을 활용해서 다시 1부터 k까지 해당 자연수가 몇번 나왔는지를 출력하거나 결과 배열에 넣어주면 정렬된 결과값을 받아볼 수 있다.  

![image](https://user-images.githubusercontent.com/33820372/96370742-de2b9a00-1199-11eb-9e46-ced457302c72.png)  
처음에 크기를 N으로 하는 counting배열을 모두 0으로 초기화한다.  

![image](https://user-images.githubusercontent.com/33820372/96370752-e71c6b80-1199-11eb-957a-594f7c65e257.png)  
그리고 input으로 들어온 배열 A에 있는 숫자들을 counting 배열의 index로 하여 counting배열에서 해당 자연수의 수를 세어준다.  

![image](https://user-images.githubusercontent.com/33820372/96370788-fe5b5900-1199-11eb-9308-8c45a6c84fad.png)  
counting 배열의 처음부터 N까지 각 인덱스의 숫자가 0이 될때까지 index에 있는 숫자를 1씩 줄여가면서 index숫자를 빼내면 정렬이 완료된다.  

### 시간복잡도
counting할 수 있는 최대 수를 N이라 하고, input으로 주어진 배열의 크기를 k라고 하자.
처음 k개의 숫자들을 모두 세는 과정이 O(k)의 복잡도를 가진다. 그리고 모두 counting 된 숫자들을 세는 과정에서 O(N)의 복잡도를 가진다.  
그러니까 계수정렬은 O(N*k)의 시간복잡도를 갖는다고 할 수 있다.  
어떤 책에서는 k가 O(N)을 초과하지 않으면 k는 무시할 수 있는 정도로 보고, O(N)의 시간복잡도를 가진다고 얘기한다. 반대로 k가 O(N)을 초과하면 O(k)의 복잡도를 가진다고 말하고 있다.  

### 백준 관련 문제

[수 정렬하기1](https://www.acmicpc.net/problem/2750)  
백준 2750번 문제는 계수정렬로 풀 수 없다. 절댓값이 1000이하이기 때문에 input중에서 음수가 포함되어있기 때문이다.

#### 양수만 정렬할 수 있는 c++ 코드
```cpp
#include <iostream>
using namespace std;

int counting[1001];

int main() {
	int N, num;
	cin >> N;

	for (int i = 0; i < N; i++) {	//input 과정 and counting
		cin >> num;
		counting[num]++;
	}

	for (int i = 1; i < 1001; i++) {	//counting을 빼내고 출력
		while(counting[i]--)
			cout << i << "\n";
	}
}
```  

백준 2750같이 음수가 포함된 경우를 풀기 위해서는 index값을 모두 0보다 큰 자연수로 조정해줄 필요가 있다.  
나는 위의 코드에서 counting의 index부분에 1000을 더함으로써 index값을 양의 정수와 0으로 조정해줘서 배열의 인덱스 범위안에 들어오게 했다.  

#### 음수까지 정렬할 수 있는 c++ 코드
```cpp
#include <iostream>
using namespace std;

int counting[2001];

int main() {
	int N, num;
	cin >> N;

	for (int i = 0; i < N; i++) {	//input 과정 and counting
		cin >> num;
		counting[num + 1000]++;     //counting의 인덱스에서 개수를 셀 때, 1000을 더해줌
	}

	for (int i = 0; i < 2001; i++) {	//counting을 빼내고 출력
		while(counting[i]--)
			cout << i - 1000 << "\n";   //출력할 때는 1000을 빼서 출력
	}
}
```  

#### 음수까지 정렬할 수 있는 python 코드
```py
#python 코드
N = int(input())
nums = [int(input()) for n in range(N)]
counting = [0 for n in range(2001)]

for num in nums:
    counting[num + 1000] += 1

for idx in range(2001):
    while(counting[idx]):
        print(idx - 1000)
        counting[idx] -= 1
```
