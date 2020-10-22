#  세그먼트 트리

세그먼트 트리에 대해 공부하면서 이해한 내용과 코드를 정리해보았습니다.
내용과 그림은 [백준 세그먼트 트리 블로그](https://www.acmicpc.net/blog/view/9)에서 참고했습니다.

### 세그먼트 트리
세그먼트 트리는 구간합을 구하거나, 배열의 i번째 숫자를 업데이트할 때 시간 효율성을 뛰어나게 하기 위한 알고리즘이다.  
원래라면 트리 구간합을 구하는 시간복잡도는최대 O(NM), O(M)이 되는데, 세그먼트 트리를 활용하면 둘다 O(NlogN)으로 줄어들 수 있다.  

세그먼트 트리에는 리프노드와 리프노드가 아닌 노드가 있다.  
* 리프노드: 배열의 수 자체
* 다른노드: 왼쪽 자식(2*i)과 오른쪽 자식(2*i + 1)의 합을 저장하는 노드  

아래 그림은 N=10일 때 세그먼트 트리가 저장하는 내용  
![image](https://user-images.githubusercontent.com/33820372/96912948-025ee200-14de-11eb-90f0-1c12f1304b14.png)

### 세그먼트 트리 만들기
원래 숫자들의 배열을 a라고 하고 배열의 크기를 N이라고 하자.
세그먼트 트리는 바이너리 트리이기 때문에 높이가 H=ceil(logN)이 된다.(N이 2의 제곱수가 아닐 때)   
그래서 세그먼트 트리를 만드는데 필요한 배열의 크기는 2(H+1)-1개가 된다.

트리와 배열 a, 현재 노드를 말하는 node, node가 담당할 구간합 범위 start와 end가 주어지면 트리를 만들 수 있다.  
```cpp
// a: 배열 a
// tree: 세그먼트 트리
// node: 세그먼트 트리 노드 번호
// node가 담당하는 합의 범위가 start ~ end
long long init(vector<long long>& a, vector<long long>& tree, int node, int start, int end) {
    if (start == end)       //노드가 리프노드인 경우 --> 배열의 수 자체를 가짐
        return tree[node] = a[start];
    else                    //노드가 리프가 아닌 경우 --> 두 자식 노드의 합을 가짐
        return tree[node] = init(a, tree, node * 2, start, (start + end) / 2) + init(a, tree, node * 2 + 1, (start + end) / 2 + 1, end);
}
```

### 세그먼트 트리에서 합 구하기
세그먼트 트리에서 left, right사이 값의 합을 구하고 싶다고 하자.  
node가 주어지고 해당 노드가 담당하는 구간 start와 end와 left,right 구간이 어떤 관계인지에 따라 반환하는 값이 달라진다.  

* [start, end]와 [left, right]가 겹치지 않는경우 --> 아무일도 없어야 하니 0을 반환
* [left, right]가 [start, end]를 포함하는 경우 --> start,end의 구간 합을 반환 (원하는 범위 내에 노드가 속하기 때문에)
* [left, right]가 [start, end]안에 포함되거나, 일부가 겹치는 경우 --> 현재 노드의 자식 노드를 탐색, 자식노드가 원하는 범위 내에 있으면 구해온 값들을 합쳐서 반환

```cpp
long long sum(vector<long long>& tree, int node, int start, int end, int left, int right) {
    if (left > end || right < start) {      //[left, right]가 [start, end]와 겹치지 않는 경우
        return 0;
    }
    if (left <= start && end <= right) {    //[left, right]가 [start, end]를 포함하는 경우
        return tree[node];
    }                                       //[left, right]가 [start, end]안에 포함되거나, 일부가 겹치는 경우
    return sum(tree, node * 2, start, (start + end) / 2, left, right) + sum(tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right);
}
```

### 세그먼트 트리 업데이트 하기
맨 처음 세그먼트 트리의 5를 변경하기 위해서는 아래 그림처럼 그 부모를 포함한 모든 조상노드를 업데이트 해줘야 한다.  
![image](https://user-images.githubusercontent.com/33820372/96914461-fffd8780-14df-11eb-8d6a-4a6f34c41f78.png)

바꾸고 싶은 수가 얼만큼 변경되었는지를 diff = a[index]-val 이라고 하자.
바꾸고 싶은 수가 있는 모든 조상노드에 diff만큼을 더해주면 될 것이다.

```cpp
void update(vector<long long>& tree, int node, int start, int end, int index, long long diff) {
    if (index < start || index > end) return;       //범위 내에 없으면 반환
    tree[node] = tree[node] + diff;                 //node에 변경된 차 만큼을 더해줌
    if (start != end) {                             //리프노드가 아니면 자식노드에 모두 diff만큼 더해주자
        update(tree, node * 2, start, (start + end) / 2, index, diff);
        update(tree, node * 2 + 1, (start + end) / 2 + 1, end, index, diff);
    }
}
```


### 세그먼트 트리 활용 기본 문제
[백준 구간합 구하기](https://www.acmicpc.net/problem/2042) 문제.  
[블로그](]https://blog.naver.com/kdy246/222123828378)에 코드와 간략한 생각을 정리했다.
