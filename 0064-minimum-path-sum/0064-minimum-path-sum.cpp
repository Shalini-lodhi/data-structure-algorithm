class Solution {
public:
    vector<vector<int>> dp; // Memoization table

    int findMinPath(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || j < 0)
            return INT_MAX; // Out of bounds case
        if (i == 0 && j == 0)
            return grid[0][0]; // Base case: start position

        if (dp[i][j] != -1)
            return dp[i][j]; // Return cached result

        // Minimum path sum from either top or left cell
        return dp[i][j] = grid[i][j] + min(findMinPath(grid, i - 1, j),
                                           findMinPath(grid, i, j - 1));
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        dp = vector<vector<int>>(
            m, vector<int>(n, -1)); // Initialize memoization table
        return findMinPath(grid, m - 1, n - 1);
    }
};