class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<int> flattened(n * n + 1, -1);

        // Convert 2D board to 1D array
        bool leftToRight = true;
        int index = 1;
        for (int row = n - 1; row >= 0; row--) {
            if (leftToRight) {
                for (int col = 0; col < n; col++)
                    flattened[index++] = board[row][col];
            } else {
                for (int col = n - 1; col >= 0; col--)
                    flattened[index++] = board[row][col];
            }
            leftToRight = !leftToRight;
        }

        // BFS
        queue<pair<int, int>> q;
        unordered_set<int> visited;
        q.push({1, 0});
        visited.insert(1);

        while (!q.empty()) {
            auto [curr, moves] = q.front();
            q.pop();

            if (curr == n * n)
                return moves; // Reached last cell

            for (int i = 1; i <= 6; i++) {
                int next = curr + i;
                if (next > n * n)
                    break;

                int dest = (flattened[next] == -1) ? next : flattened[next];

                if (visited.find(dest) == visited.end()) {
                    q.push({dest, moves + 1});
                    visited.insert(dest);
                }
            }
        }

        return -1; // No way to reach the end
    }
};