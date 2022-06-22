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
    // bool isCycle(int V, vector<int> adj[]) {
    //     unordered_map<int, bool> visited;
    //     unordered_map<int, int> parent;
    //     for(int i=0;i<V;i++){
    //         if(!visited[i]){
    //             bool ans=isCycleDetected(V, adj, visited, parent);
    //             if(ans==1){
    //                 return true;
    //             }
    //         }
    //     }
    //     return false;
    // }
      bool isCycleBFS(vector<int>adj[],unordered_map<int,bool>&visited,
                   int node,unordered_map<int,int>&parent){
       
       queue<int>q;
       q.push(node);
       visited[node]=true;
       parent[node]=-1;
       
       while(!q.empty()){
           int t=q.front();
           q.pop();
           for(auto i : adj[t]){
               if(visited[i]==true && i != parent[t]){
                   return true;
               }
               else if(!visited[i]){
                   q.push(i);
                   visited[i]=true;
                   parent[i]=t;
                   
               }
           }
       }
       
       return false;
                       
    }
 
 
 
 
   // Function to detect cycle in an undirected graph.
   bool isCycle(int V, vector<int> adj[]) {
       
       unordered_map<int,bool>visited;
       unordered_map<int,int>parent;
       for(int i=0;i<V;i++){
           if(!visited[i]){
               bool ans=isCycleBFS(adj,visited,i,parent);
               if(ans==1){
                   return true;
               }
           }
       }
       return false;
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