class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount + 1, 0);
        dp[0] = 1; // Base case: 1 way to make amount 0

        for (int coin : coins) {
            for (int i = coin; i <= amount; i++) {
                if (dp[i] <= INT_MAX - dp[i - coin]) { // Prevent overflow
                    dp[i] += dp[i - coin];
                } else {
                    dp[i] =
                        INT_MAX; // Cap the value at INT_MAX to prevent overflow
                }
            }
        }

        return dp[amount];
    }
};