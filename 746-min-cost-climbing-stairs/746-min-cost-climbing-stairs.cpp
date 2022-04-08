class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int sz=cost.size();
        vector<int> dp(sz);
        int i;
        dp[0]=cost[0];
        dp[1] = cost[1];
        for(i=2; i<cost.size(); i++)
            dp[i] = cost[i] + min(dp[i-1], dp[i-2]);
        
        return min(dp[i-1], dp[i-2]);
    }
};