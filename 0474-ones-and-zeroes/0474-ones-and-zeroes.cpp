class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (string s : strs) {
            int zeros = count(s.begin(), s.end(), '0');
            int ones = count(s.begin(), s.end(), '1');

            // Reverse iteration to prevent multiple usage
            for (int i = m; i >= zeros; --i) {
                for (int j = n; j >= ones; --j) {
                    dp[i][j] = max(dp[i][j], 1 + dp[i - zeros][j - ones]);
                }
            }
        }
        for (int i = 0; i <= m ; i++) {
                for (int j = 0; j <= n; j++) {
                    cout<<dp[i][j]<< " | ";
                }
                cout<<endl;
            }
        return dp[m][n];
    }
};