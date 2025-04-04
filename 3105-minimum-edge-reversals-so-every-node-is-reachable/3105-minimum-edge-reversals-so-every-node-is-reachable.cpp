class Solution {
public:
    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        // Step 1: Construct adjacency list with direction tracking
        vector<vector<pair<int, int>>> graph(n);
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            graph[u].push_back({v, 0}); // u → v (0 means original direction)
            graph[v].push_back({u, 1}); // v → u (1 means needs reversal)
        }

        vector<int> reversals(n, 0); // Store min reversals for each node

        // Step 2: DFS to compute the minimum reversals from node 0
        function<void(int, int)> dfs1 = [&](int node, int parent) {
            for (auto& [neighbor, cost] : graph[node]) {
                if (neighbor != parent) {
                    reversals[0] +=
                        cost; // If cost = 1, we need to reverse this edge
                    dfs1(neighbor, node);
                }
            }
        };
        dfs1(0, -1);

        // Step 3: DFS to propagate the result to all other nodes
        function<void(int, int)> dfs2 = [&](int node, int parent) {
            for (auto& [neighbor, cost] : graph[node]) {
                if (neighbor != parent) {
                    // Calculate reversals for neighbor based on parent
                    reversals[neighbor] = reversals[node] - cost + (1 - cost);
                    dfs2(neighbor, node);
                }
            }
        };
        dfs2(0, -1);

        return reversals;
    }
};
