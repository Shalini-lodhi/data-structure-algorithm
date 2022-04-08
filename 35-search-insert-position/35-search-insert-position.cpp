class Solution {
public:
    int searchInsert(vector<int>& arr, int N) {
        int sz=arr.size();
        if(sz==0) return 0;
        int left=0, right=sz-1, mid=0, res;
        while(left<=right){
            mid=left+(right-left)/2;
            if(arr[mid]==N) return mid;
            else if(arr[mid]>N) right =mid-1; 
            else left=mid+1;
        }    
        return left;
    }
};