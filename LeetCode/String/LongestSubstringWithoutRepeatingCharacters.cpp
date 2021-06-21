class Solution {
    int longest = 0;
    map<char, int> m;
public:
    int lengthOfLongestSubstring(string s) {        
        int n = s.size(), idx = 0;
        
        for(int i = 0; i < n; i++){
            if(m.find(s[i]) != m.end()) {  //현재 문자가 이전에 있었으면
                idx = max(idx, m.find(s[i])->second);
                m.find(s[i])->second = i + 1;
            } else{
                m.insert({s[i], i + 1});
            }
            longest = max(i - idx + 1, longest);
        }
        
        return longest;
    }
};
