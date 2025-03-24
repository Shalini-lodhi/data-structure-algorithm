class Solution {
public:
    int dfs(int node, int parent, unordered_map<int, vector<int>>& tree,
            vector<bool>& hasApple) {
        int time = 0;
        for (int child : tree[node]) {
            if (child == parent)
                continue; // Avoid revisiting the parent
            int childTime = dfs(child, node, tree, hasApple);
            if (childTime > 0 || hasApple[child]) {
                time += childTime + 2; // Add 2 for round trip
            }
        }
        return time;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        unordered_map<int, vector<int>> tree;

        // Build adjacency list
        for (auto& edge : edges) {
            tree[edge[0]].push_back(edge[1]);
            tree[edge[1]].push_back(edge[0]);
        }

        return dfs(0, -1, tree, hasApple);
    }
};