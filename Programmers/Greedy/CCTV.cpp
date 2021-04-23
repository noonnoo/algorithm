#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

struct compare{
	bool operator()(pair<int, int>a, pair<int, int>b){
		return a.second > b.second;
	}
};

int solution(vector<vector<int>> routes) {
    int answer = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
    
    for(int i = 0; i < routes.size(); i++){
        pq.push(make_pair(routes[i][0], routes[i][1]));
    }
    
    while(!pq.empty()){
        int cctv_loc = pq.top().second;
        pq.pop();
        answer++;
        
        while(true){
            if(pq.empty())
                break;
            else if(pq.top().first <= cctv_loc)
                pq.pop();
            else
                break;
        }
    }
    
    return answer;
}
