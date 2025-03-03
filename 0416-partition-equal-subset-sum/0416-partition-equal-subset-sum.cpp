class Solution {
public:
     bool canPartition(vector<int>& nums) {
        int totalSum = 0;
        for (int num : nums) totalSum += num;

        // If totalSum is odd, it cannot be partitioned into two equal subsets
        if (totalSum % 2 != 0) return false;

        int subsetSum = totalSum / 2;
        int n = nums.size();
        vector<bool> dp(subsetSum + 1, false);

        // Base case: There is always a way to make sum 0 (by picking nothing)
        dp[0] = true;

        // DP Tabulation (1D Knapsack)
        for (int num : nums) {
            for (int j = subsetSum; j >= num; j--) {
                dp[j] = dp[j] || dp[j - num];
            }
        }

        return dp[subsetSum];
    }
};