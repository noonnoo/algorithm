#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ret;
        bool inserted = false;
        int start = newInterval[0];
        
        for(int i = 0; i < intervals.size(); i++)
            if(start < intervals[i][0]){
                intervals.insert(intervals.begin() + i, newInterval);
                inserted = true;
                break;
            }               
        if(!inserted)
            intervals.push_back(newInterval);

        ret.push_back(intervals[0]);
        merge(ret, intervals);
        return ret;
    }
    
    void merge(vector<vector<int>>& merged, const vector<vector<int>>& intervals){
        int idx = 0;
        
        for(int i = 1; i < intervals.size(); i++){
            int curr_s = intervals[i][0], curr_e = intervals[i][1];
            //cout << curr_s << " " << curr_e << " " << idx << "\n";
            if(curr_s <= merged[idx][1]){
                if(curr_s <= merged[idx][0]) {
                    if(curr_e < merged[idx][0] - 1){
                        merged.push_back(merged[idx++]);
                        merged[idx - 1][1] = curr_e;
                        merged[idx - 1][0] = min(merged[idx][0], curr_s);
                    } else {
                        merged[idx][0] = min(merged[idx][0], curr_s);
                    }
                }
                merged[idx][1] = max(merged[idx][1], curr_e);
            } else{
                merged.push_back({curr_s, curr_e});
                idx++;
            }
        }
    }
};
