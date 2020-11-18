#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N;
bool visited[1000001];
int parent[1000001];

void BFS() {
    queue<pair<int, int>> Q;
    Q.push(make_pair(N, 0));

    while (!Q.empty()) {
        int curr = Q.front().first, depth = Q.front().second;
        Q.pop();

        if (curr == 1) {
            vector<int> nums;
            while (curr != N) {
                nums.push_back(curr);
                curr = parent[curr];
            }
            nums.push_back(N);

            cout << depth << "\n";
            for (int i = depth; i >= 0; i--)
                cout << nums[i] << " ";
            return;
        }

        int next = curr / 3;
        if (curr % 3 == 0 && !visited[next]) {
            visited[next] = true;
            parent[next] = curr;
            Q.push(make_pair(next, depth + 1));
        }

        next = curr / 2;
        if (curr % 2 == 0 && !visited[next]) {
            visited[next] = true;
            parent[next] = curr;
            Q.push(make_pair(next, depth + 1));
        }

        next = curr - 1;
        if (!visited[next]) {
            visited[next] = true;
            parent[next] = curr;
            Q.push(make_pair(next, depth + 1));
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> N;

    BFS();
}
