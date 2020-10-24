#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<int> graph[20001];
int dist[20001];
bool visited[20001];

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    int maxi = 0;            //depth 중 최댓값
    queue<pair<int, int>> q; //vertex, depth
    
    for(int i= 0; i < edge.size(); i++){        //양방향 그래프 생성
        graph[edge[i][0]].push_back(edge[i][1]);
        graph[edge[i][1]].push_back(edge[i][0]);
    }        
    
    q.push(make_pair(1,0));                     //BFS의 시작 - 1
    visited[1] = true;
    while(!q.empty()){                          //BFS
        pair<int, int> curr = q.front();
        if(dist[curr.first] == 0 || dist[curr.first] > curr.second)     
            dist[curr.first] = curr.second;     //각 vertex까지 깊이가 최소 값이면 갱신
        if(dist[curr.first] > maxi)
            maxi = dist[curr.first];            //depth 중 최댓값 찾기
        q.pop();
        
        for(int i= 0; i < graph[curr.first].size(); i++){       //갈 수 있는 노드 중 방문하지 않은 노드 방문
            int next = graph[curr.first][i];
            if(!visited[next]){
                visited[next] = true;
                q.push(make_pair(next, curr.second + 1));
            }
        }
    }
    
    for(int i = 2; i <= n; i++){
        if(dist[i] == maxi){
            answer++;
        }
    }    
    
    return answer;
}
