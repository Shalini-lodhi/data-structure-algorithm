class Solution {
public:
    int dp[10001];
    int solve(vector<int>& nums, int curridx, int lidx)
    {
        if(curridx == lidx) return 0;
        if(curridx > lidx || nums[curridx] == 0) return 1e6;
        
        if(dp[curridx] < 1e6) return dp[curridx];
        
        for(int i=1;i<=nums[curridx];++i)
        {
            dp[curridx] = min(dp[curridx], solve(nums,curridx+i,lidx));
        }
        
        dp[curridx]+=1;
        return dp[curridx];
    }
    
    int jump(vector<int>& nums) {
        memset(dp,1e6,sizeof(dp));
        int ans = solve(nums,0,nums.size()-1);
        if(ans == 1e6) return 0;
        else return ans;
    }
};