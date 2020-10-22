#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

long long init(vector<long long>& nums, vector<long long>& tree, int node, int start, int end) {
    if (start == end)       //노드가 리프노드인 경우 --> 배열의 수 자체를 가짐
        return tree[node] = nums[start];
    else                    //노드가 리프가 아닌 경우 --> 두 자식 노드의 합을 가짐
        return tree[node] = init(nums, tree, node * 2, start, (start + end) / 2) + init(nums, tree, node * 2 + 1, (start + end) / 2 + 1, end);
}

long long sum(vector<long long>& tree, int node, int start, int end, int left, int right) {
    if (left > end || right < start) {      //[left, right]가 [start, end]와 겹치지 않는 경우
        return 0;
    }
    if (left <= start && end <= right) {    //[left, right]가 [start, end]를 포함하는 경우
        return tree[node];
    }                                       //[left, right]가 [start, end]안에 포함되거나, 일부가 겹치는 경우
    return sum(tree, node * 2, start, (start + end) / 2, left, right) + sum(tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right);
}

void update(vector<long long>& tree, int node, int start, int end, int index, long long diff) {
    if (index < start || index > end) return;       //범위 내에 없으면 반환
    tree[node] = tree[node] + diff;                 //node에 변경된 차 만큼을 더해줌
    if (start != end) {                             //리프노드가 아니면 자식노드에 모두 diff만큼 더해주자
        update(tree, node * 2, start, (start + end) / 2, index, diff);
        update(tree, node * 2 + 1, (start + end) / 2 + 1, end, index, diff);
    }
}

int main() {
    int N, M, K;
    cin >> N >> M >> K;
    M += K;
    int H = (int)ceil(log2(N));
    int tree_size = 1 << (H + 1);       //트리 사이즈 = 2^(H+1)
    vector<long long> nums(N), tree(tree_size);

    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }
    init(nums, tree, 1, 0, N - 1);     //세그먼트 트리 만들기

    while (M--) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 1) {               //숫자 바꾸기        
            update(tree, 1, 0, N - 1, b - 1, c - nums[b - 1]);
            nums[b - 1] = c;
        }
        else {
            cout << sum(tree, 1, 0, N - 1, b - 1, c - 1) << "\n";
        }
    }
}
