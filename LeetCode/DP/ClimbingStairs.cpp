/*
https://leetcode.com/problems/climbing-stairs/
*/
class Solution {
    int curr = 1, prev = 1;
public:
    int climbStairs(int n) {        
        for(int i = 2; i <= n; i++){
            int tmp = curr;
            curr += prev;
            prev = tmp;
        }
        return curr;
    }
};
