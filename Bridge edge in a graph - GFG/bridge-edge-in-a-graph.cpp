// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
    vector<pair<int,int>>v;
    void dfs(int node, int parent, vector<int> &vis, vector<int> &tin, vector<int> &low, int &timer, vector<int> adj[]) {
    vis[node] = 1; 
    tin[node] = low[node] = timer++; 
    for(auto it: adj[node]) {
        if(it == parent) continue;
        
        if(!vis[it]) {
            dfs(it, node, vis, tin, low, timer, adj); 
            low[node] = min(low[node], low[it]); 
            if(low[it] > tin[node]) {
                v.push_back({node,it});
            }
        } else {
            low[node] = min(low[node], tin[it]); 
        }
    }
}
    int isBridge(int V, vector<int> adj[], int c, int d) 
    {
        vector<int> tin(V, -1);
    	vector<int> low(V, -1); 
    	vector<int> vis(V, 0); 
    	int timer = 0; 
    	for(int i = 0;i<V;i++) {
    	    if(!vis[i]) {
    	        dfs(i, -1, vis, tin, low, timer, adj); 
	        }
    	}
    	for(int i=0;i<v.size();i++)
    	{
    	    auto kl=v[i];
    	    if((kl.first==c and kl.second==d )||(kl.first==d and kl.second==c ) )
    	    return true;
    	}
        return false;
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        int i=0;
        while (i++<E) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back (v);
            adj[v].push_back (u);
        }
        
        int c,d;
        cin>>c>>d;
        
        Solution obj;
    	cout << obj.isBridge(V, adj, c, d) << "\n";
    }

    return 0;
}

  // } Driver Code Ends