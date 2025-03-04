using namespace std;

class Solution {
public:
    int integerBreak(int n) {
        if (n == 2)
            return 1;
        if (n == 3)
            return 2;

        vector<int> dp(n + 1, 0);
        dp[2] = 1;
        dp[3] = 2;

        for (int i = 4; i <= n; i++) {
            for (int j = 1; j <= i / 2; j++) {
                dp[i] = max(dp[i], max(j * (i - j), j * dp[i - j]));
            }
        }
        for (int i = 0; i <= n; i++) {
            cout << i << "-> " << dp[i] << endl;
        }
        return dp[n];
    }
};