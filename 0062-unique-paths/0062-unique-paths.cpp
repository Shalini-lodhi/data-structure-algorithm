class Solution {
public:
    vector<vector<int>> dp;
    void print(vector<vector<int>>& dp) {
        for (int i = 0; i < dp.size(); i++) {
            for (int j = 0; j < dp[0].size(); j++) {
                cout << dp[i][j] << ", ";
            }
            cout << endl;
        }
    }
    int pathFinder(int i, int j, vector<vector<int>>& dp) {
        if (i == 0 || j == 0)
            return 1;
        if (i < 0 || j < 0)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        dp[i][j] = pathFinder(i - 1, j, dp) + pathFinder(i, j - 1, dp);

        return dp[i][j];
    }
    int uniquePaths(int m, int n) {
        dp = vector<vector<int>>(m, vector<int>(n, -1));
        int result = pathFinder(m - 1, n - 1, dp);
        print(dp);
        return result;
    }
};