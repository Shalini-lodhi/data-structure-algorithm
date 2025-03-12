class UnionFind {
public:
    vector<int> parent, rank;

    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 1);
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
    bool validPath(int n, vector<vector<int>>& edges, int source,
                   int destination) {
        // vector<vector<int>> adj(n);
        // for (auto& edge : edges) {
        //     adj[edge[0]].push_back(edge[1]);
        //     adj[edge[1]].push_back(edge[0]); // Since the graph is undirected
        // }

        // vector<bool> visited(n, false);
        // dfs(source, adj, visited);
        // bfs(source, adj, visited);

        // return visited[destination];
        UnionFind uf(n);
        for (auto& edge : edges) {
            uf.unite(edge[0], edge[1]);
        }
        return uf.find(source) == uf.find(destination);
    }

    // 1. BFS
    void bfs(int source, vector<vector<int>>& adj, vector<bool>& visited) {
        queue<int> q;
        q.push(source);
        visited[source] = true;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int neighbor : adj[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
    }

    // 2. DFS
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited) {
        visited[node] = true;
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, adj, visited);
            }
        }
    }

    // 3. Union Find
};