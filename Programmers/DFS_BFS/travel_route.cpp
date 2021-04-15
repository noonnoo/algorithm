#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<string> answer;

bool compare(vector<string> a, vector<string> b){
    return a[1] > b[1];
}

void DFS(int curr, vector<string> &route, const vector<vector<string>> &tickets, vector<bool> &used){    
    if(curr == tickets.size()) {
        answer = route;
        return;
    }
    
    for(int i= 0; i < tickets.size(); i++){
        if(tickets[i][0] == route[curr] && !used[i]){
            route.push_back(tickets[i][1]);
            used[i] = true;
            DFS(curr + 1, route, tickets, used);
            used[i] = false;
            route.pop_back();
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    sort(tickets.begin(), tickets.end(), compare);
    vector<bool> used(tickets.size(), false);
    vector<string> route = {"ICN"};
    
    DFS(0, route, tickets, used);
    
    return answer;
}
