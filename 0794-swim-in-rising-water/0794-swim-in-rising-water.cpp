class DSU {
public:
    vector<int> parent, rank;

    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]); // Path compression
        return parent[x];
    }

    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY])
                parent[rootY] = rootX;
            else if (rank[rootX] < rank[rootY])
                parent[rootX] = rootY;
            else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
};
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        DSU dsu(n * n);

        // Store cells with their elevation and sort by elevation
        vector<pair<int, int>> cells;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cells.push_back({grid[i][j], i * n + j});

        sort(cells.begin(), cells.end());

        vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<vector<bool>> flooded(n, vector<bool>(n, false));

        for (auto [t, pos] : cells) {
            int r = pos / n, c = pos % n;
            flooded[r][c] = true;

            for (auto d : directions) {
                int nr = r + d[0], nc = c + d[1];
                if (nr >= 0 && nr < n && nc >= 0 && nc < n && flooded[nr][nc]) {
                    dsu.unite(r * n + c, nr * n + nc);
                }
            }

            // Check if start and end are connected
            if (dsu.find(0) == dsu.find(n * n - 1))
                return t;
        }

        return -1;
    }
};