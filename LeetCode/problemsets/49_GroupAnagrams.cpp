#include <unordered_map>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<string, int> um;
        vector<vector<string>> ret;
        
        for(string str : strs){
            string tmp = str;
            sort(tmp.begin(), tmp.end());
            
            if(um.find(tmp) == um.end()){
                vector<string> str_vec = {str};
                
                um.insert(make_pair(tmp, um.size()));
                ret.push_back(str_vec);
            } else{
                int idx = um.find(tmp)->second;
                ret[idx].push_back(str);
            }
        }
        
        return ret;
    }
};
