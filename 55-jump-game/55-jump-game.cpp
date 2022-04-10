class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums[0]>=nums.size()-1) return true;
        
        for(int i=1; i<nums.size(); i++){
            if(i>nums[i-1]) return false;
            if(i+nums[i]>=nums.size()-1) return true;
            nums[i] = max(i+nums[i], nums[i-1]);
        }
        return true;
    }
};