class Solution {
public:
    int numDecodings(string s) {
        if (s.empty() || s[0] == '0')
            return 0; // Invalid starting character

        int n = s.size();
        vector<int> dp(n + 1, 0);
        dp[0] = 1; // Base case: Empty string has one valid way
        dp[1] = (s[0] != '0') ? 1 : 0; // Single character string

        for (int i = 2; i <= n; i++) {
            // Single-digit decoding (1-9)
            if (s[i - 1] != '0') {
                dp[i] += dp[i - 1];
            }

            // Two-digit decoding (10-26)
            int twoDigit = stoi(s.substr(i - 2, 2));
            if (twoDigit >= 10 && twoDigit <= 26) {
                dp[i] += dp[i - 2];
            }
        }
        // for(int i = 0; i <= n; ++i){
        //     cout << i << ": " << s[i] << "->" << dp[i] << endl;
        // }

        return dp[n];
    }
};