class DSU {
public:
    vector<int> parent, size;

    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);
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
            if (size[rootX] < size[rootY])
                swap(rootX, rootY);
            parent[rootY] = rootX;
            size[rootX] += size[rootY];
        }
    }

    int getSize(int x) { return size[find(x)]; }
};

class Solution {
public:
    vector<int> hitBricks(vector<vector<int>>& grid,
                          vector<vector<int>>& hits) {
        int m = grid.size(), n = grid[0].size();
        int totalCells = m * n;

        // Step 1: Create a copy of the grid and remove bricks as per hits
        vector<vector<int>> gridCopy = grid;
        for (auto& hit : hits)
            gridCopy[hit[0]][hit[1]] = 0; // Temporarily remove bricks

        DSU dsu(totalCells + 1); // Extra node at index `totalCells` (roof node)
        auto getIndex = [&](int r, int c) { return r * n + c; };

        // Step 2: Connect all stable bricks (excluding hits)
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (gridCopy[r][c] == 1) {
                    int idx = getIndex(r, c);
                    if (r == 0)
                        dsu.unite(idx, totalCells); // Connect top row to roof

                    if (r > 0 && gridCopy[r - 1][c] == 1)
                        dsu.unite(idx, getIndex(r - 1, c));
                    if (c > 0 && gridCopy[r][c - 1] == 1)
                        dsu.unite(idx, getIndex(r, c - 1));
                }
            }
        }

        vector<int> result(hits.size());
        vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        // Step 3: Process hits in reverse (adding bricks back)
        for (int i = hits.size() - 1; i >= 0; i--) {
            int r = hits[i][0], c = hits[i][1];
            if (grid[r][c] == 0)
                continue; // If original grid had no brick, skip

            int prevStableSize =
                dsu.getSize(totalCells); // Stable component size before adding

            gridCopy[r][c] = 1; // Restore brick
            int idx = getIndex(r, c);

            // Connect new brick to its neighbors
            if (r == 0)
                dsu.unite(idx, totalCells); // Top row connects to the roof
            for (auto& dir : directions) {
                int nr = r + dir[0], nc = c + dir[1];
                if (nr >= 0 && nr < m && nc >= 0 && nc < n &&
                    gridCopy[nr][nc] == 1) {
                    dsu.unite(idx, getIndex(nr, nc));
                }
            }

            int newStableSize =
                dsu.getSize(totalCells); // Stable component size after adding
            result[i] = max(0, newStableSize - prevStableSize -
                                   1); // Count new falling bricks
        }

        return result;
    }
};