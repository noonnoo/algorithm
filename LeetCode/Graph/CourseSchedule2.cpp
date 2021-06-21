#include <vector>
#include <cstring>
#include <queue>
#include <iostream>

class Solution {
public:
    vector<int> next[100001];
    vector<int> result;
    int depth[100001];
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        memset(depth, 0, sizeof(depth));

        for(int i = 0; i < prerequisites.size(); i++){
            depth[prerequisites[i][0]]++;
            next[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        
        if(prerequisites.size() == 0){
            for(int i = 0; i < numCourses; i++)
                result.push_back(i);
            return result;
        }
        
        if(!topologySort(numCourses))
            return {};
        return result;
    }
    
    bool topologySort(int numCourses){
        queue<int> q;
        
        for(int i = 0 ; i < numCourses; i++){
            if(!depth[i]){
                q.push(i);
            }
        }
        
        for(int i = 0; i < numCourses; i++){
            if(q.empty())
                return false;
            
            int cur = q.front();
            q.pop();            
            result.push_back(cur);
            
            for(int j = 0; j < next[cur].size(); j++){
                if(--depth[next[cur][j]] == 0){
                    q.push(next[cur][j]);
                }
            }
        }
        return true;
    }
};
