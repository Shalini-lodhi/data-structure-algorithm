// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
class Solution{
public:
    int *findTwoElement(int *arr, int n) {
       int *ans=new int[2];// code here
      sort(arr,arr+n);
      for(int i=0;i<n;i++)
      {
          if(arr[i]==arr[i+1])
          {
              ans[0]=arr[i];
             
          }
      }
      
      int sum1=0;
      int sum2=0;
      for(int i=1;i<=n;i++)
      {
          sum1+=i;
          sum2+=arr[i-1];
      }
      
      int x=sum2-sum1;
      ans[1]=abs(ans[0]-x);
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