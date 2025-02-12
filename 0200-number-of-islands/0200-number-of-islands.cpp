class Solution {
public:
    void dfs(vector<vector<char>>& grid, int r, int c) {
        int m = grid.size(), n = grid[0].size();
        if (r < 0 || c < 0 || r >= m || c >= n || grid[r][c] == '0')
            return;

        grid[r][c] = '0'; // Mark as visited

        // Explore all 4 directions
        dfs(grid, r + 1, c);
        dfs(grid, r - 1, c);
        dfs(grid, r, c + 1);
        dfs(grid, r, c - 1);
    }

    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        int m = grid.size(), n = grid[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') { // Found new island
                    count++;
                    dfs(grid, i, j);
                }
            }
        }
        return count;
    }
};