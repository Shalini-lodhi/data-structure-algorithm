class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        // Base cases
        for (int i = 0; i <= m; i++)
            dp[i][0] = i; // Deleting all characters
        for (int j = 0; j <= n; j++)
            dp[0][j] = j; // Inserting all characters

        // Fill the DP table
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1]; // No change needed
                } else {
                    dp[i][j] = 1 + min({
                                       dp[i - 1][j],    // Delete
                                       dp[i][j - 1],    // Insert
                                       dp[i - 1][j - 1] // Replace
                                   });
                }
            }
        }

        return dp[m][n];
    }
};