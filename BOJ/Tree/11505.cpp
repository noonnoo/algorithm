#include <iostream>
#include <cmath>
#define MAX 1000001
#define MOD 1000000007
using namespace std;
typedef long long ull;

ull nums[MAX];
ull tree[1048577 * 2];

ull init(int node, int start, int end) {
    if (start == end)       //노드가 리프노드인 경우 --> 배열의 수 자체를 가짐
        return tree[node] = nums[start];
    else                    //노드가 리프가 아닌 경우 --> 두 자식 노드의 곱을 가짐
        return tree[node] = ((init(node * 2, start, (start + end) / 2) % MOD) * (init(node * 2 + 1, (start + end) / 2 + 1, end) % MOD) % MOD);
}

ull product(int node, int start, int end, int left, int right) {
    if (left > end || right < start) {      //[left, right]가 [start, end]와 겹치지 않는 경우
        return 1;
    }
    if (left <= start && end <= right) {    //[left, right]가 [start, end]를 포함하는 경우
        return tree[node];
    }                                       //[left, right]가 [start, end]안에 포함되거나, 일부가 겹치는 경우
    return ((product(node * 2, start, (start + end) / 2, left, right) % MOD) * (product(node * 2 + 1, (start + end) / 2 + 1, end, left, right) % MOD) % MOD);
}

ull update(int node, int start, int end, int index, ull new_val) {
    if (index < start || index > end) return tree[node];       //범위 내에 없으면 반환
    if (start == end)
        return tree[node] = new_val;
    return tree[node] = ((update(node * 2, start, (start + end) / 2, index, new_val) % MOD) * (update(node * 2 + 1, (start + end) / 2 + 1, end, index, new_val) % MOD) % MOD);
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int N, M, K;
    cin >> N >> M >> K;
    M += K;

    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }
    init(1, 0, N - 1);                  //세그먼트 트리 만들기

    while (M--) {
        ull a, b, c;
        cin >> a >> b >> c;
        if (a == 1) {                   //숫자 바꾸기        
            update(1, 0, N - 1, b - 1, c);
            nums[b - 1] = c;
        }
        else {                          //구간 곱 출력하기
            cout << product(1, 0, N - 1, b - 1, c - 1) << "\n";
        }
    }
}
