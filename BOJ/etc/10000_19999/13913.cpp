#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, K;
bool visited[100001] = { false, };
int parent[100001];

void BFS() {
    queue<pair<int, int>> Q;
    Q.push(make_pair(N, 0));

    while (!Q.empty()) {
        int pos = Q.front().first, sec = Q.front().second;
        Q.pop();

        if (pos == K) {
            vector<int> nums;
            while (pos != N) {
                nums.push_back(pos);
                pos = parent[pos];
            }
            nums.push_back(N);

            cout << sec << "\n";
            for (int i = sec; i >= 0; i--)
                cout << nums[i] << " ";
            return;
        }

        if (pos * 2 <= 100000 && visited[pos * 2] == false) {
            visited[pos * 2] = true;
            parent[pos * 2] = pos;
            Q.push(make_pair(pos * 2, sec + 1));
        }
        if (pos + 1 <= 100000 && visited[pos + 1] == false) {
            visited[pos + 1] = true;
            parent[pos + 1] = pos;
            Q.push(make_pair(pos + 1, sec + 1));
        }
        if (pos - 1 >= 0 && visited[pos - 1] == false) {
            visited[pos - 1] = true;
            parent[pos - 1] = pos;
            Q.push(make_pair(pos - 1, sec + 1));
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> N >> K;

    BFS();
}
