#include <iostream>
#include <queue>
using namespace std;

bool visited[100001];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int N, K, cnt = 0, min_s = 987654321;
    cin >> N >> K;

    queue<pair<int, int>> Q;
    Q.push(make_pair(N, 0));

    while (!Q.empty()) {
        int pos = Q.front().first, sec = Q.front().second;
        Q.pop();
        visited[pos] = true;

        if (pos == K) {
            if (min_s < sec) break;
            cnt++;
            min_s = sec;
            continue;
        }

        if (pos + 1 <= 100000 && visited[pos + 1] == false) {
            Q.push(make_pair(pos + 1, sec + 1));
        }
        if (pos - 1 >= 0 && visited[pos - 1] == false) {
            Q.push(make_pair(pos - 1, sec + 1));
        }
        if (pos * 2 <= 100000 && visited[pos * 2] == false) {
            Q.push(make_pair(pos * 2, sec + 1));
        }
    }

    cout << min_s << "\n" << cnt;
}
