// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<vector<int>>ans;
   bool isSafe(vector<vector<int>>&a,int i,int j,int n){
    for(int row=0;row<i;row++){
     if(a[row][j]==1)
      return false;
    }
    int row=i,col=j;
    while(row>=0 && col>=0){
     if(a[row][col]==1)
      return false;
     row--;
     col--;
    }
    row=i;
    col=j;
    while(row>=0 && col<n){
     if(a[row][col]==1)
      return false;
     row--;
     col++;
    }
    return true;
   }
   bool solve(vector<vector<int>>&a,vector<int>temp,int i){
    if(i==a.size()){
        ans.push_back(temp);
    }
    for(int col=0;col<a.size();col++){
        if(isSafe(a,i,col,a.size())){
            a[i][col]=1;
            temp[i]=col+1;
            if(solve(a,temp,i+1))
                return true;
            a[i][col]=0;
            temp[i]=0;
        }
    }
    return false;
   }
   vector<vector<int>> nQueen(int n) {
       // code here
       vector<int>temp(n);
       vector<vector<int>>a(n,vector<int>(n,0));
       solve(a,temp,0);
       return ans;
   }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends