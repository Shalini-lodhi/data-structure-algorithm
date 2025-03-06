class Solution {
public:
    int n;
    int dp[50][50][50]; // Memoization array

    int cherryPickup(vector<vector<int>>& grid) {
        n = grid.size();
        memset(dp, -1, sizeof(dp)); // Initialize DP table

        int result = max(0, dfs(grid, 0, 0, 0));
        return result;
    }

    int dfs(vector<vector<int>>& grid, int r1, int c1, int r2) {
        int c2 = r1 + c1 - r2; // Deriving c2 based on r1, c1, r2

        // Boundary & obstacle check
        if (r1 >= n || c1 >= n || r2 >= n || c2 >= n || grid[r1][c1] == -1 ||
            grid[r2][c2] == -1)
            return INT_MIN;

        // If both reach the bottom-right cell
        if (r1 == n - 1 && c1 == n - 1)
            return grid[r1][c1];

        // If already computed, return cached result
        if (dp[r1][c1][r2] != -1)
            return dp[r1][c1][r2];

        // Collect cherries (avoid double counting if both at the same cell)
        int cherries = grid[r1][c1];
        if (r1 != r2)
            cherries += grid[r2][c2];

        // Move both persons in 4 different ways
        int maxCherries = max({
            dfs(grid, r1 + 1, c1, r2 + 1), // Both move down
            dfs(grid, r1 + 1, c1, r2),     // Person1 down, Person2 right
            dfs(grid, r1, c1 + 1, r2 + 1), // Person1 right, Person2 down
            dfs(grid, r1, c1 + 1, r2)      // Both move right
        });

        return dp[r1][c1][r2] = cherries + maxCherries;
    }
};