class Solution {
public:
    int findMin(vector<int>& nums) {
         if(nums.size()==1) return nums[0];
        int l=0,r=nums.size()-1,n=r;
        if(nums[r]>nums[0]) return nums[0];
        while(l<=r){
            // int m=(l+r)/2;
            int m=l+(r-l)/2;
            if(nums[m]>nums[m+1]) return nums[m+1];
            if(nums[m]<nums[m-1]) return nums[m];
            if(nums[m]>nums[0]) l=m+1;
            else r=m-1;
        }
        return -1;
    }
};