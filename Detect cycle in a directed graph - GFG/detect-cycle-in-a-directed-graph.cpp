// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        //find all inDegree of vertices
    vector<int> inDegree(V);
    for(int i=0;i<V;i++){
        for(auto j: adj[i]){
            inDegree[j]++;
        }
    }
    //pushinf all inDegree 0 to queue
    queue<int> q;
    for(int i=0;i<V;i++){
        if(inDegree[i]==0) q.push(i);
    }

    //do bfs    
    int cnt=0;

    while(!q.empty()){
        int front = q.front();
        q.pop();
        
        //increment cnt
        cnt++;
        
        //neighbour inDegree update
        for(auto neighbour: adj[front]){
            inDegree[neighbour]--;
            if(inDegree[neighbour]==0) q.push(neighbour);
        }
    }
		if(cnt == V) return false;
    return true;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
  // } Driver Code Ends