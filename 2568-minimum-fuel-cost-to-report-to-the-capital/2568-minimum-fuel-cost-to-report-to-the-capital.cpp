/*
              0
            / |  \
           1   4    5
          /    |
         3     6
        /
       2

Steps:
    C2 -> C3 => 1
    C3+C2 -> C1 -> C0  => 1 + 1
    C1 -> C0 => 1
    C5 -> C0 => 1
    C6 -> C4 => 1
    C4+C5 -> C0 => 1
    => 7

adj:
    0 -> 1, 4, 5
    1 -> 0, 3
    2 -> 3
    4 -> 0, 6
    5 -> 0
    6 -> 4

*/

class Solution {
public:
    long long minFuel = 0;

    int dfs(int node, int parent, vector<vector<int>>& adj, int seats) {
        int people = 1; 

        for (int neighbor : adj[node]) {
            if (neighbor == parent)
                continue; // Avoid backtracking
            people += dfs(neighbor, node, adj, seats);
        }

        if (node != 0) {
            minFuel += (people + seats - 1) / seats; 
        }

        return people;
    }

    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size() + 1;
        vector<vector<int>> adj(n);

        // bi-directional
        for (auto& road : roads) {
            adj[road[0]].push_back(road[1]);
            adj[road[1]].push_back(road[0]);
        }
        dfs(0, -1, adj, seats);
        return minFuel;
    }
};