struct State {
    int node, mask, steps;
};
class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        if (n == 1)
            return 0; // Edge case: single node graph

        queue<State> q;
        vector<vector<bool>> visited(n, vector<bool>(1 << n, false));

        // Start BFS from all nodes
        for (int i = 0; i < n; i++) {
            q.push({i, 1 << i, 0});
            visited[i][1 << i] = true;
        }

        while (!q.empty()) {
            State curr = q.front();
            q.pop();

            // If all nodes visited, return answer
            if (curr.mask == (1 << n) - 1)
                return curr.steps;

            // Explore neighbors
            for (int neighbor : graph[curr.node]) {
                int nextMask = curr.mask | (1 << neighbor);
                if (!visited[neighbor][nextMask]) {
                    visited[neighbor][nextMask] = true;
                    q.push({neighbor, nextMask, curr.steps + 1});
                }
            }
        }
        return -1; // Should never reach here
    }
};