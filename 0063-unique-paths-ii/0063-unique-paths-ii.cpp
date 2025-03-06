class Solution {
public:
    vector<vector<int>> dp; // Memoization table

    int findPaths(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || j < 0 || grid[i][j] == 1)
            return 0; // Out of bounds or obstacle
        if (i == 0 && j == 0)
            return 1; // Base case: Reached start

        if (dp[i][j] != -1)
            return dp[i][j]; // Return cached result

        // Recursively find paths from top and left
        return dp[i][j] = findPaths(grid, i - 1, j) + findPaths(grid, i, j - 1);
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        if (obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1)
            return 0; // No path possible

        dp = vector<vector<int>>(
            m, vector<int>(n, -1)); // Initialize memoization table
        return findPaths(obstacleGrid, m - 1, n - 1);
    }
};