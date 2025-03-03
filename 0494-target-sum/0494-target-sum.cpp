class Solution {
public:
    int countSubsets(vector<int>& nums, int sum) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));

        // Base case: There is one way to make sum 0 (by picking nothing)
        for (int i = 0; i <= n; i++)
            dp[i][0] = 1;

        // DP Table filling
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= sum; j++) {
                if (nums[i - 1] <= j)
                    dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i - 1]];
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[n][sum];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        // Total sum of nums
        int totalSum = 0;
        for (int num : nums)
            totalSum += num;
        // Edge case: If target is out of bounds, return 0
        if (totalSum < abs(target))
            return 0;
        if ((totalSum + target) % 2 != 0)
            return 0;

        int subsetSum = (totalSum + target) / 2;

        return countSubsets(nums, subsetSum);
    }
};