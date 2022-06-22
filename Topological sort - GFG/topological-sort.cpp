// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
// 	void topoSort(int node, vector<bool>& visited, stack<int>& s, vector<int> adj[]){
//         visited[node]=true;
        
//         for(auto neighbour: adj[node]){
//             if(!visited[neighbour])
//                 topoSort(neighbour, visited, s, adj);
//         }
        
//         s.push(node);
// 	}
// 	vector<int> topoSort(int V, vector<int> adj[]) 
// 	{
// 	    stack<int> s;
// 	    vector<bool> visited(V);
// 	    for(int i=0; i<V; i++){
// 	        if(!visited[i]){
// 	            topoSort(i, visited, s, adj);
// 	        }
// 	    }
	    
// 	    vector<int> ans;
// 	    while(!s.empty()){
// 	        ans.push_back(s.top());
// 	        s.pop();
// 	    }
// 	    return ans;
// 	}
    vector<int> topoSort(int V, vector<int> adj[]) 
{    //find all inDegree of vertices
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
    
    vector<int> ans;
    while(!q.empty()){
        int front = q.front();
        q.pop();
        
        //ans store
        ans.push_back(front);
        
        //neighbour inDegree update
        for(auto neighbour: adj[front]){
            inDegree[neighbour]--;
            if(inDegree[neighbour]==0) q.push(neighbour);
        }
    }
    return ans;}
};

// { Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}  // } Driver Code Ends