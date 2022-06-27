// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    bool isSafe(int newX, int newY, vector<vector<bool>>& vis, vector<vector<int>>& m, int n){
        if((newX>=0 && newY>=0)&&
            (newX<=n-1 && newY<=n-1)&&
                (vis[newX][newY]!=1)&&
                    (m[newX][newY]==1)){
                        return true;
                    }
                    return false;
    }
    void solution(int x, int y, vector<vector<int>>& m, int n, vector<string>& _paths, 
            vector<vector<bool>> &vis, string path){
                //base case
                if(x==n-1 && y==n-1){
                    _paths.push_back(path);
                    return;
                }
                vis[x][y]=1;
                //4 movements- D-L-R-U
                //Down
                if(isSafe(x+1, y, vis, m, n)){
                    solution(x+1, y, m, n, _paths, vis, path+'D');
                }
                //Left
                if(isSafe(x, y-1, vis, m, n)){
                    solution(x, y-1, m, n, _paths, vis, path+'L');
                }
                //Right
                if(isSafe(x, y+1, vis, m, n)){
                    solution(x, y+1, m, n, _paths, vis, path+'R');
                }
                //UP
                if(isSafe(x-1, y, vis, m, n)){
                    solution(x-1, y, m, n, _paths, vis, path+'U');
                }
                vis[x][y]=0;
                
            }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> possible_paths;
        vector<vector<bool>> visited(n, vector<bool>(n,0)); //visted vector for tracking path
        string path= "";
        
        if(m[0][0]==0){
            return possible_paths;
        }
        
        solution(0, 0, m, n, possible_paths, visited, path);
        return possible_paths;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends