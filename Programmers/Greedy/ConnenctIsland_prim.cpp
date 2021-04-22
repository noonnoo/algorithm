#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int answer = 0;

bool visited[101];
vector<pair<int, int>> edge_cost[101];  //i번째에서 갈 수 있는 노드 (비용, 노드)

void prim(){
    priority_queue<pair<int, int>> pq;
    
    for(int i = 0; i < edge_cost[0].size(); i++){
        pq.push(edge_cost[0][i]);
    }
    
    visited[0] = true;
    while(!pq.empty()){
        int dist = pq.top().first;
        int curr = pq.top().second;
        pq.pop();
        
        if(!visited[curr]){
            visited[curr] = true;
            answer += -dist;
            
            for(int i = 0; i < edge_cost[curr].size(); i++){
                if(!visited[edge_cost[curr][i].second])
                    pq.push(edge_cost[curr][i]);
            }
        }
    }
}

int solution(int n, vector<vector<int>> costs) {    
    //edge에서 연결된 부분 표시
    for(int i = 0; i <costs.size(); i++){
        edge_cost[costs[i][0]].push_back(make_pair(-costs[i][2], costs[i][1]));
        edge_cost[costs[i][1]].push_back(make_pair(-costs[i][2], costs[i][0]));
    }
    
    prim();
    
    return answer;
}
