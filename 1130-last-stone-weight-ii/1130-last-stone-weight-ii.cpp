class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int totalSum = 0;
        for (int stone : stones)
            totalSum += stone;

        int subsetSum = totalSum / 2;
        vector<bool> dp(subsetSum + 1, false);
        dp[0] = true;

        // Knapsack DP: Finding max subset sum <= totalSum/2
        for (int stone : stones) {
            for (int j = subsetSum; j >= stone; j--) {
                dp[j] = dp[j] || dp[j - stone];
            }
        }

        // Find the maximum possible subset sum (S1)
        for (int s1 = subsetSum; s1 >= 0; s1--) {
            if (dp[s1]) {
                return totalSum - 2 * s1; // Result = |(S - 2 * S1)|
            }
        }

        return 0;
    }
};