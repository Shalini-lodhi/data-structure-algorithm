class Solution {
public:
    /*
        coins = [1, 2, 5]
        amount = 11
    */
    int coinChange(vector<int>& coins, int amount) {
        // Initialize DP array with large values
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0; // Base case

        // Compute the minimum number of coins for each amount
        for (int coin : coins) {
            for (int i = coin; i <= amount; i++) {
                if (dp[i - coin] != INT_MAX) { // If i-coin can be formed
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }

        return (dp[amount] == INT_MAX) ? -1 : dp[amount];
    }
};