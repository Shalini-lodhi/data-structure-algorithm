// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    // bool isCycleDetected(int V, vector<int> adj[], unordered_map<int, bool>& visited, 
    //     unordered_map<int, int>& parent){
    //     parent[V]=-1;
    //     visited[V]=true;
    //     queue<int> q;
    //     q.push(V);
        
    //     while(!q.empty()){
    //         int front=q.front();
    //         q.pop();
            
    //         for(auto neighbors: adj[front]){
    //             if(visited[neighbors]==true && neighbors!=parent[front]) return true;
                
    //             else if(!visited[neighbors]){
    //                 q.push(neighbors);
    //                 visited[neighbors]=true;
    //                 parent[neighbors]=front;
    //             }
    //         }
    //     }
    //     return false;
    // }
    bool DFS(int src, int parent, vector<int> adj[], vector<bool> &visited) {
        visited[src] = true;
        
        for(int &u : adj[src]) {
            if(visited[u] == false) {
                if(DFS(u, src, adj, visited))
                    return true;
            }
            else if(u != parent)
                return true;
        }
        
        return false;
    }
    
    bool checkDFS(vector<int> adj[], int V) {
        vector<bool> visited(V, false);
        
        for(int i = 0; i < V; ++i) {
            if(visited[i] == false) {
                if(DFS(i, -1, adj, visited))
                    return true;
            }
        }
        
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        return checkDFS(adj, V); 
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}  // } Driver Code Ends