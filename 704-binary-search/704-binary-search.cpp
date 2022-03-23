class Solution {
public:
    // int search(vector<int>& nums, int target) {
    //     int sz=sizeof(nums)/sizeof(nums[0]);
    //     if(sz==0 && nums[0]==target) return 0;
    //     int start=0, end=sz-1; int mid;
    //     while(start<=end){
    //         mid = start +(end-start)/2;
    //         if(nums[mid]==target) return mid;
    //         else if(target<nums[mid]) end=mid-1;
    //         else start=mid+1;
    //     }
    //     return -1;
    // }
    int search(vector<int>& arr,int k){
        int n=arr.size();
        int start=0, end=n-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(arr[mid]==k)return mid;
            else if(arr[mid]>k) end=mid-1;
            else start=mid+1;
        }
        return -1;
    }
};