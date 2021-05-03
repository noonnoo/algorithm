/*
https://leetcode.com/explore/challenge/card/may-leetcoding-challenge-2021/598/week-1-may-1st-may-7th/3730/
*/

class Solution {
    vector<int> running_sum;
public:
    vector<int> runningSum(vector<int>& nums) {
        int sum_temp = nums[0];
        running_sum.push_back(sum_temp);
        
        for(int i = 1; i < nums.size(); i++){
            sum_temp += nums[i];
            running_sum.push_back(sum_temp);
        }
        
        return this->running_sum;
    }
};
