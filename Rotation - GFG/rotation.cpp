// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
// 	int findKRotation(int arr[], int n) {
// 	    int start=0, end=n-1; int mid;
	    
// 	    while(start<=end){
// 	        mid=start+(end-start)/2;
// 	        if(arr[mid]>arr[end]) start=mid+1;
// 	        else end=mid;
// 	    }
// 	    return mid;
// 	}
	int findKRotation(int a[], int n) {
	   int s=0, e=n-1,m;
	   while(s<=e){
	       m=s+(e-s)/2;
	       if(a[m]>=a[e]) s=m+1;
	       else e=m;
	   }
	   return m;
	}

};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findKRotation(a, n);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends