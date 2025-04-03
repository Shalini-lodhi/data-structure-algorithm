class Solution {
public:
    void dfs(int node, unordered_map<int, vector<pair<int, int>>>& adjL, vector<bool>& visited, int& changes){
        visited[node] = true;
        for(auto [neighbor, isOutGoing] : adjL[node]){
            if(!visited[neighbor]){
                if(isOutGoing) changes++;
                dfs(neighbor, adjL, visited, changes);
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        //adj list
        unordered_map<int, vector<pair<int, int>>> adjL;

        //build the graph
        for(auto& connection : connections){
            adjL[connection[0]].push_back({connection[1], 1}); //outgoing edge
            adjL[connection[1]].push_back({connection[0], 0}); //incoming edge
        }
        //visited vector
        vector<bool> visited(n, false);
        int changes = 0;

        dfs(0, adjL, visited, changes);

        return changes;
    }
};