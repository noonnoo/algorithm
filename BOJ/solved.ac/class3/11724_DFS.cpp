#include <iostream>
using namespace std;

int N, M, cnt = 0;
bool nodes[1001][1001];
bool visited[1001];

void DFS(int s) {
    for (int i = 1; i <= N; i++)
        if (nodes[s][i] && !visited[i]) {
            visited[i] = true;
            DFS(i);
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
            DFS(i);
            cnt++;
        }
    }
    cout << cnt;
}
