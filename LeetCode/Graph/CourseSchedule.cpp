class Solution {
public:
    vector<int> next[100001];
    int depth[100001];
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        memset(depth, 0, sizeof(depth));

        for(int i = 0; i < prerequisites.size(); i++){
            depth[prerequisites[i][0]]++;
            next[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        
        if(prerequisites.size() == 0)
            return true;
        
        return checkGraph(numCourses);
    }
    
    bool checkGraph(int num){
        queue<int> q;
        int numCourses = num;
        
        for(int i = 0 ; i < numCourses; i++){
            if(!depth[i]){
                q.push(i);
                num--;
            }
        }
        
        if(q.empty())
            return false;
        
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            
            for(int i = 0; i < next[cur].size(); i++){
                if(--depth[next[cur][i]] == 0){
                    q.push(next[cur][i]);
                    num--;
                }
            }
        }
        
        if(num)
            return false;
        
        return true;
    }
};
