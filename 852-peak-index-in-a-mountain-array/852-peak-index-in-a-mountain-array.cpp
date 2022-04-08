class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int sz=arr.size();
        if(sz==0){
            return 0;
        }
        int left=0, right=sz-1, mid=0;
        while(left<right){
            mid=left+(right-left)/2;
            if(arr[mid]>=arr[mid+1]) right=mid;
            else left=mid+1;
        }    
        return left;
    }
};