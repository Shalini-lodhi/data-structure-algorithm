class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int sz=nums.size();
        if(nums[0]==0 && sz==1) return -1;
        if(nums[0]>=sz) return sz;
        int l=0, r=sz-1;
        
        while(l<=r){
            int mid=r+(l-r)/2;
            
            if(nums[mid]>=(sz-mid) & nums[mid-1]<(sz-mid)) return sz-mid;
            else if(nums[mid]>=(sz-mid)) r=mid-1;
            else l=mid + 1;
        }
        return -1;
    }
};