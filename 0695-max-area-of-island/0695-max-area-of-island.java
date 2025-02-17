import java.util.*;

class UnionFind {
    private int[] parent;
    private int[] size; // Size of each set
    private int maxSize; // Maximum island size

    public UnionFind(int n) {
        parent = new int[n];
        size = new int[n];
        Arrays.fill(size, 1); // Each node initially has size 1

        for (int i = 0; i < n; i++) {
            parent[i] = i; // Initially, each node is its own parent
        }
        maxSize = 0;
    }

    public int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]); // Path compression
        }
        return parent[x];
    }

    public void union(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) {
            if (size[rootX] > size[rootY]) {
                parent[rootY] = rootX;
                size[rootX] += size[rootY];
                maxSize = Math.max(maxSize, size[rootX]);
            } else {
                parent[rootX] = rootY;
                size[rootY] += size[rootX];
                maxSize = Math.max(maxSize, size[rootY]);
            }
        }
    }

    public void updateMaxSize(int index) {
        maxSize = Math.max(maxSize, size[find(index)]);
    }

    public int getMaxSize() {
        return maxSize;
    }
}

class Solution {
    public int maxAreaOfIsland(int[][] grid) {
        int rows = grid.length, cols = grid[0].length;
        UnionFind uf = new UnionFind(rows * cols);

        int[][] directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}}; // Down, Up, Right, Left
        boolean hasIsland = false;

        // Step 1: Process grid and track islands
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1) {
                    hasIsland = true;
                    int index = i * cols + j; // Convert 2D index to 1D
                    uf.updateMaxSize(index); // Update size for isolated 1s

                    for (int[] dir : directions) {
                        int newRow = i + dir[0];
                        int newCol = j + dir[1];

                        if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols && grid[newRow][newCol] == 1) {
                            int newIndex = newRow * cols + newCol;
                            uf.union(index, newIndex);
                        }
                    }
                }
            }
        }

        return hasIsland ? uf.getMaxSize() : 0;
    }
}
