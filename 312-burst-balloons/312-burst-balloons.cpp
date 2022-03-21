class Solution {
public:
    int dp[302][302];
    int mcm(vector<int>& A, int i, int j){
        int ans=INT_MIN;int temp_ans;
        if(i+1==j) return 0;
        if(dp[i][j] != -1)return dp[i][j];
        
        for(int k=i+1; k<j; k++){
            temp_ans=mcm(A, i, k)+mcm(A, k, j)+ (A[i]*A[k]*A[j]);
            ans=max(ans, temp_ans);
        }
        return dp[i][j]=ans;
    }
    int maxCoins(vector<int>& values) {
        memset(dp, -1, sizeof(dp));
        values.insert(values.begin(),1);
        values.push_back(1);
        return mcm(values, 0, values.size()-1);
    }
};