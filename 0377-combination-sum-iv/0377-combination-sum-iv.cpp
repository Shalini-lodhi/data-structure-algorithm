class Solution {
public:
    int combinationSum4(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, 0);
        dp[0] = 1; // Base case: 1 way to make amount 0

        for (int i = 1; i <= amount; i++) {
            for (int coin : coins) {
                if (i >= coin && dp[i] <= INT_MAX - dp[i - coin]) {
                    dp[i] += dp[i - coin];
                }
            }
        }
        for (int i = 0; i <= amount; i++) {
            cout << i << "-> " << dp[i] << endl;
        }

        return dp[amount];
    }
};