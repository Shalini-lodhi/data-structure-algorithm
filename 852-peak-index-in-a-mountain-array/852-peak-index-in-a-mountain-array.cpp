class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
       // int sz=arr.size();
       //  if(sz<3) return 0;
       // int s=0, e=sz-1; int m=0;
       //  while(s<=e){
       //      m=s+(e-s)/2;
       //      if(arr[m]>0 && arr[m]<sz-1){
       //          if(arr[m]>arr[m+1] && arr[m]>arr[m-1]) return m;
       //          else if(arr[m]<arr[m+1]) s=m+1;
       //          else e=m-1;
       //      }
       //      else if(m==0){
       //          if(arr[0]>arr[1]) return 0;
       //          else return 1;
       //      }
       //      else if(m==sz-1){
       //          if(arr[sz-1]>arr[sz-2]) return sz-1;
       //          else return sz-2;
       //      }
       //      }
       //  return 0;
        if(arr.size()==0){
            return 0;
        }
        int left=0, right=arr.size()-1, mid=0;
        while(left<right){
            mid=left+(right-left)/2;
            if(arr[mid]>=arr[mid+1]){
                right=mid;
            }
            else{
                left=mid+1;
            }
        }
            
        return left;
    }
};