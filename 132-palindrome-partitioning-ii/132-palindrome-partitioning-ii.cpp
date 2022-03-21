class Solution {
public:
    int dp[2001][2001];
    bool isPalindrome(string &str, int i, int j){
        while(i<j){
            if(str[i++]!=str[j--]) return false;
        }
        return true;
    }
    int mcm(string &A, int i, int j){
        int ans=INT_MAX; int temp_ans;
        if(i>=j || isPalindrome(A, i, j)) return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int left, right;
            for(int k=i; k<=j-1; k++){
                if (isPalindrome(A, i, k))
 			    {
 				    ans = min(ans, 1 + mcm(A, k + 1, j));
 			    }
            }
            return dp[i][j]=ans;
    }
    int minCut(string str)
    {
        memset(dp, -1, sizeof(dp));
        return mcm(str, 0, str.size()-1);
    }
};