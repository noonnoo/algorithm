#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <cstring>
#define MAX 10001
using namespace std;

int V, E;
int id, parent[MAX], scc_count;

bool finished[MAX];
vector<int> graph[MAX];
vector<vector<int>> SCCs;	
stack<int> s;

int dfs(int curr) {
	parent[curr] = ++id;
	s.push(curr);

	int p = parent[curr];
	for (int next : graph[curr]) {
		if (parent[next] == 0) p = min(p, dfs(next));			//아직 방문하지 않았다면 --> dfs 시작
		else if (!finished[next]) p = min(p, parent[next]);		//아직 scc정해지지 않았다면 --> 자신과, 다음 노드 중 작은 부모값을 가짐
	}

	if (p == parent[curr]) {			//부모노드가 자기 자신인 경우
		vector<int> scc;
		while (true) {					//현재 노드가 나올때까지 stack pop
			int t = s.top();
			s.pop();
			scc.push_back(t);
			finished[t] = true;
			if (t == curr) break;
		}
		sort(scc.begin(), scc.end());
		SCCs.push_back(scc); 
		scc_count++;
	}
	return p;                        //이번 그래프에서 연결 된 노드 다보고 사이클 검사 끝냄
}

void solve() {
	for (int i = 1; i <= V; i++) {
		if (parent[i] == 0)			//이전에 가보지 않은 노드만 탐색
			dfs(i);
	}

	sort(SCCs.begin(), SCCs.end());	//sort 및 출력
	cout << scc_count << "\n";
	for (auto &scc : SCCs) {
		for (auto n : scc) 
			cout << n << " ";
		cout << "-1\n";
	}
}

int main() {
	cin >> V >> E;

	for (int i = 0; i < E; i++) {
		int v1, v2;
		cin >> v1 >> v2;
		graph[v1].push_back(v2);
	}

	solve();
}
