class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int left=0, right=arr.size()-1; int mid=-1;
        while(left<=right){
            mid=left+(right-left)/2;
            
            if(arr[mid]-(1+mid)<k) left=mid+1;
            else right=mid-1;
        }
        return left+k;
    }
};