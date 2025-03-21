// Union-Find (Disjoint Set Union) Approach
class UnionFind {
public:
    vector<int> parent, size;
    int maxSize;

    UnionFind(int n) {
        parent.resize(n);
        size.resize(n, 1);
        maxSize = 0;
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]); // Path compression
        }
        return parent[x];
    }

    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            parent[rootY] = rootX;
            size[rootX] += size[rootY];
            maxSize = max(maxSize, size[rootX]);
        }
    }
};

class Solution {
public:
    vector<int> dirX = {0, 0, 1, -1};
    vector<int> dirY = {1, -1, 0, 0};
    // BFS
    int bfs(vector<vector<int>>& grid, int i, int j) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> q;
        q.push({i, j});
        grid[i][j] = 0; // Mark as visited
        int area = 1;

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            // Explore all 4 directions
            for (int d = 0; d < 4; d++) {
                int newX = x + dirX[d];
                int newY = y + dirY[d];

                if (newX >= 0 && newX < m && newY >= 0 && newY < n &&
                    grid[newX][newY] == 1) {
                    q.push({newX, newY});
                    grid[newX][newY] = 0; // Mark as visited
                    area++;
                }
            }
        }
        return area;
    }
    // DFS Approach
    int dfs(vector<vector<int>>& grid, int i, int j) {
        int m = grid.size(), n = grid[0].size();
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0)
            return 0;

        grid[i][j] = 0; // Mark as visited
        int area = 1;

        // Explore all 4 directions
        for (int d = 0; d < 4; d++) {
            area += dfs(grid, i + dirX[d], j + dirY[d]);
        }
        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int maxArea = 0;

        // #1. BFS
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    maxArea = max(maxArea, bfs(grid, i, j));
                }
            }
        }

        // #2. DFS Approach
        // for (int i = 0; i < m; i++) {
        //     for (int j = 0; j < n; j++) {
        //         if (grid[i][j] == 1) {
        //             maxArea = max(maxArea, dfs(grid, i, j));
        //         }
        //     }
        // }

        // UnionFind uf(m * n);
        // int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        // // Convert the 2D grid into a graph and apply union operations
        // for (int i = 0; i < m; i++) {
        //     for (int j = 0; j < n; j++) {
        //         if (grid[i][j] == 1) {
        //             int index = i * n + j;
        //             for (auto& d : dirs) {
        //                 int ni = i + d[0], nj = j + d[1];
        //                 if (ni >= 0 && ni < m && nj >= 0 && nj < n &&
        //                     grid[ni][nj] == 1) {
        //                     uf.unite(index, ni * n + nj);
        //                 }
        //             }
        //         }
        //     }
        // }
        // return uf.maxSize;
        return maxArea;
    }
};