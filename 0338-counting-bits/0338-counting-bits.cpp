class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> dp(num + 1, 0);

        for (int i = 1; i <= num; i++) {
            /*
            dp[i >> 1] : shifts the bit to the right (divide by 2)
            i & 1 : checks if i is odd (adds 1 if it is). 
            */
            dp[i] = dp[i >> 1] + (i & 1); // Using bit manipulation
        }

        return dp;
    }
};