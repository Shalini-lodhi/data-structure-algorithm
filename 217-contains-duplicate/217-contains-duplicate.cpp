class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        bool ans=false;
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size()-1; i++){
            if(nums[i]==nums[i+1]) ans=true;
        }
        return ans;
    }
};