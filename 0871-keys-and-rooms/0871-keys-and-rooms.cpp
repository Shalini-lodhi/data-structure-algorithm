class Solution {
public:
    /*
    0 -> 1, 3
    1 -> 0, 1, 3
    2 -> 2
    3 -> 0
    */
    // DFS
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited) {
        visited[node] = true;
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, adj, visited);
            }
        }
    }
    // BFS
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
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visited(n, false);

        // Start DFS from room 0
        //dfs(0, rooms, visited);
        bfs(0, rooms, visited);

        /// Check if all rooms are visited
        for (bool v : visited) {
            if (!v)
                return false;
        }
        return true;
    }
};