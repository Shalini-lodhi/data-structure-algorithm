// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        int *ans= new int[2];
       sort(arr, arr+n);
       for(int i = 0; i<n-1; i++){
           if(arr[i+1]-arr[i] == 0){
               ans[0]=arr[i];
           }
           else if(arr[i+1] - arr[i] == 2){
               ans[1]=arr[i]+1;
           }
       }
       if(arr[n-1] == n && ans[1]==0){
           ans[1]=n-1;
       }else if(arr[n-1] == n-1 && ans[1]==0){
           ans[1]=n;
       }
       if(arr[0] != 1){
           ans[1]=1;
       }
       return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}  // } Driver Code Ends