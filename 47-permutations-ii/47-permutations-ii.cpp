class Solution {
public:
    // void solve(vector<int>& nums, vector<vector<int>>& ans, int index){
    //     if(index == nums.size()){
    //         ans.push_back(nums);
    //         // return;
    //     }
    //     for(int j=index; j<nums.size(); j++){
    //         if (j != index && nums[index] == nums[j]) continue;
    //         swap(nums[index], nums[j]); 
    //         solve(nums, ans, index+1); 
    //     }
    // }
    // vector<vector<int>> permuteUnique(vector<int>& nums) {
    //     sort(nums.begin(), nums.end());
    //     vector<vector<int>>ans;
    //     // int index=0;
    //     solve(nums,ans,0);
    //     return ans;
    // }
    vector<vector<int>>ans;
    void helper(vector<int> nums,int idx)
    {
        if(idx==nums.size())
        {
            ans.push_back(nums);
        }
        for(int i=idx;i<nums.size();i++)
        {
            if(i!=idx && nums[i]==nums[idx])    continue;
            swap(nums[i],nums[idx]);
            helper(nums,idx+1);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        helper(nums, 0);
        return ans;
    }
    
};