class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();

        vector<vector<long long>> dp(
            m + 1,
            vector<long long>(n + 1, 0)
        );

        // Empty string t can be formed in exactly 1 way
        for (int i = 0; i <= m; i++) {
            dp[i][0] = 1;
        }

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {

                // Skip s[i-1]
                dp[i][j] = dp[i - 1][j];

                // Use s[i-1] if characters match
                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] += dp[i - 1][j - 1];

                    // Prevent overflow
                    dp[i][j] = min(dp[i][j], (long long)INT_MAX);
                }
            }
        }

        return (int)dp[m][n];
    }
};