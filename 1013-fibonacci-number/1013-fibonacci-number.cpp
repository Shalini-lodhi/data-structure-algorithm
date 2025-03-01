class Solution {
public:
    int fib(int n) {
        vector<int> dp(n + 2, 0);
        dp[0] = 0; // dp[0] = 0
        dp[1] = 1; // dp[1] = 1

        // n = 3
       for(int i = 2; i <= n; i++){ 
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        // dp[2] = dp[1] + dp[0] => dp[2] = 1
        // dp[3] = dp[2] + dp[1] => dp[3] = 2

        return dp[n]; 
        //[0->0, 1->1, 2->1, 3->2, 4->3]
    }
};