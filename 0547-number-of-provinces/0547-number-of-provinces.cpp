class Solution {
public:
    /*
    isConnected = adjMatrix
    */
    // 1. dfs
    void dfs(int city, vector<vector<int>>& isConnected,
             vector<bool>& visited) {
        visited[city] = true;

        // Explore all connected cities recursively
        for (int i = 0; i < isConnected.size(); i++) {
            if (isConnected[city][i] == 1 && !visited[i]) {
                dfs(i, isConnected, visited);
            }
        }
    }
    // 2. bfs
    void bfs(int city, vector<vector<int>>& isConnected,
             vector<bool>& visited) {
        queue<int> q;
        q.push(city);
        visited[city] = true;

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            // explore all connected cities
            for (int i = 0; i < isConnected.size(); ++i) {
                if (isConnected[curr][i] == 1 && !visited[i]) {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
    }

    // Union-Find (Disjoint Set Union) Approach
    int find(int x, vector<int>& parent) {
        if (parent[x] != x) {
            parent[x] = find(parent[x], parent); // Path compression
        }
        return parent[x];
    }

    void unionFind(int x, int y, vector<int>& parent, vector<int>& rank) {
        int rootX = find(x, parent);
        int rootY = find(y, parent);

        if (rootX != rootY) {
            // Union by rank
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }

    int unionFindApproach(vector<vector<int>>& isConnected, int n) {
        vector<int> parent(n);
        vector<int> rank(n, 0);

        // Initially, each city is its own parent
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        // Perform union operation for connected cities
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (isConnected[i][j] == 1) {
                    unionFind(i, j, parent, rank);
                }
            }
        }

        // Count number of provinces by checking the unique roots
        int provinceCount = 0;
        for (int i = 0; i < n; i++) {
            if (parent[i] == i) {
                provinceCount++;
            }
        }

        return provinceCount;
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n, false); // mark the visited provinse
        int provinceCount = 0;

        // #1. BFS
        // for (int i = 0; i < n; ++i) {
        //     if (!visited[i]) {
        //         bfs(i, isConnected, visited);
        //         provinceCount++;
        //     }
        // }

        // #2. DFS
        // for (int i = 0; i < n; ++i) {
        //     if (!visited[i]) {
        //         dfs(i, isConnected, visited);
        //         provinceCount++;
        //     }
        // }

        // #3. Union Find Algo
        provinceCount = unionFindApproach(isConnected, n);

        return provinceCount;
    }
};