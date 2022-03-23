class Solution {
public:
    int findKRotation(vector<int>& n, int k) {
	   int s=0, e=n.size()-1,m;
	   while(s<=e){
	       m=s+(e-s)/2;
	       if(n[m]>=n[e]) s=m+1;
	       else e=m;
	   }
	   return m;
	}
    int binarySearch(vector<int>& n, int k,int s,int e) {
	   while(s<=e){
	       int m=s+(e-s)/2;
           if(n[m]==k) return m;
	       if(n[m]>k) e=m-1;
	       else s=m+1;;
	   }
	   return -1;
	}
    
    int search(vector<int>& n, int k) {
        int mx=findKRotation(n,k);
        if(binarySearch(n,k, 0, mx-1)!=-1)
            return binarySearch(n,k, 0, mx-1);
        else if(binarySearch(n, k, mx, n.size()-1)!=-1)
            return binarySearch(n, k, mx, n.size()-1);
        
        return -1;
    }
};