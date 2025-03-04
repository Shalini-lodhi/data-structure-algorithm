class Solution {
public:
    int integerBreak(int n) {
        // vector<int> dp(n + 1, 0);
        // dp[0] = 0; dp[1] = 1;

        // for(int i = 2; i <= n ; ++i){
        //     for(int j = i; j <)
        // }

        // return dp[n];
        if (n == 2)
            return 1;
        if (n == 3)
            return 2;

        int product = 1;

        // Break as many 3s as possible
        while (n > 4) {
            product *= 3;
            n -= 3;
        }

        // Multiply the last remaining number (either 2 or 4)
        product *= n;

        return product;
    }
};