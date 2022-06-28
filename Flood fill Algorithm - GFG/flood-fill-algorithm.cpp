// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    void solve(vector<vector<int>>& image, int i, int j, int n, int m, int color, int newColor) {
       if(i<0 || i>=n || j<0 || j>=m || image[i][j] != color) return;
       
       image[i][j] = newColor;
       solve(image, i+1, j, n, m, color, newColor);
       solve(image, i-1, j, n, m, color, newColor);
       solve(image, i, j+1, n, m, color, newColor);
       solve(image, i, j-1, n, m, color, newColor);
       return;
   }
   vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
       int n = image.size();
       int m = image[0].size();
       int color = image[sr][sc];
       if(color == newColor) {
           return image;
       }
       solve(image, sr, sc, n, m, color, newColor);
       return image;
   }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}  // } Driver Code Ends