#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int parent[101];

bool compare(vector<int> edge1, vector<int> edge2){
    return edge1[2] < edge2[2];
}

int getParent(int x) {	            //그래프의 부모 구하기
	if (parent[x] == x) return x;
	return parent[x] = getParent(parent[x]);
}

void unionParent(int a, int b) {	//그래프의 부모 병합
	a = getParent(a);
	b = getParent(b);

	//숫자가 작은 부모로 병합
	if (a < b) parent[b] = a;
	else parent[a] = b;
}

int find(int a, int b) {	        //서로 같은 부모면 0반환
	a = getParent(a);
	b = getParent(b);

	if (a == b) return 1;
	else return 0;
}


int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    sort(costs.begin(), costs.end(), compare);
    for(int i = 0; i < n; i++){
        parent[i] = i;
    }
    
    for(int i = 0; i < costs.size(); i++){
        if(!find(costs[i][0], costs[i][1])){
            unionParent(costs[i][0], costs[i][1]);
            answer += costs[i][2];
        }
    }
    
    return answer;
}
