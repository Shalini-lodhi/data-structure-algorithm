class Solution {
public:
    /*
    - no two adjacent houses can be broken
    - Linear DP -> depnds on the past elements
    - nums = [1,2,3,1]
    - [[0|1],[1|2],[2|3],[3|1]]
    - #1 -> dp[i] = max((dp[i]+dp[i-2]), dp[i-1]) -> [0-2-4] || [1-3-5]
    - #2 -> if nums.size() == 1 -> nums[0]
    - #3 -> if nums.size() == 2 -> max(nums[0], nums[1])

    */

    int rob(vector<int>& nums) {
        if(nums.size()==1)return nums[0];
        vector<int>dp(nums.size());
        
        dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);
        
        for(int i=2;i<nums.size();i++){
            dp[i]=max(dp[i-1],dp[i-2]+nums[i]);
        }
        return dp[nums.size()-1];
    }
};