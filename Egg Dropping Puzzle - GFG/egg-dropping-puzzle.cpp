// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int dp[101][10002];
    int solve(int e, int f) {
        if(f==0 || f==1) return f;
        if(e==1) return f;
        
        if(dp[e][f]!=-1) return dp[e][f];
        int nm=INT_MAX;
        int high, low, temp;
        for(int k=1; k<=f; k++){
            if(dp[e-1][k-1]!=-1) low=dp[e-1][k-1];
            else{
                low=solve(e-1, k-1);
                dp[e-1][k-1]=low;
            }
            if(dp[e][f-k]!=-1) high=dp[e][f-k];
            else{
                high=solve(e, f-k);
                dp[e][f-k]=high;
            }
            
            temp=1+max(high, low);
            nm=min(nm, temp);
        }
        return dp[e][f]=nm;
    }
    int eggDrop(int e, int f){
        memset(dp, -1, sizeof(dp));
        return solve(e, f);
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}
  // } Driver Code Ends