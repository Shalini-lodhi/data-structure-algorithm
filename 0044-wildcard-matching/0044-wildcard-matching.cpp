class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));

        // Base case: empty pattern matches empty string
        dp[0][0] = true;

        // Handling '*' in pattern when s is empty
        for (int j = 1; j <= n; j++) {
            if (p[j - 1] == '*') {
                dp[0][j] = dp[0][j - 1]; // '*' can match an empty sequence
            }
        }

        // Fill the DP table
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (p[j - 1] == s[i - 1] || p[j - 1] == '?') {
                    dp[i][j] = dp[i - 1][j - 1]; // Match single character
                } else if (p[j - 1] == '*') {
                    dp[i][j] =
                        dp[i][j - 1] ||
                        dp[i - 1][j]; // '*' matches zero or more characters
                }
            }
        }

        return dp[m][n];
    }
};