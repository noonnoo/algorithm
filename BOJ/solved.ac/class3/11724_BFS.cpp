#include <iostream>
#include <queue>
using namespace std;

int N, M, cnt = 0;
bool nodes[1001][1001];
bool visited[1001];

void BFS(int s) {
    queue<int> q;
    q.push(s);

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        for (int i = 1; i <= N; i++) 
            if (nodes[curr][i] && !visited[i]) {
                q.push(i);
                visited[i] = true;
            }
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;

        nodes[u][v] = 1;
        nodes[v][u] = 1;
    }

    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
            BFS(i);
            cnt++;
        }
    }
    cout << cnt;
}
