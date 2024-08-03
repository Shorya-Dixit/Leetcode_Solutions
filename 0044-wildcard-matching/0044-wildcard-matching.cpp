class Solution {
public:
    bool isAllStars(string &p, int i) {
        for (int k = 1; k <= i; k++) {
            if (p[k-1] != '*')
                return false;
        }
        return true;
    }
    bool isMatch(string s, string p) {
        int n = p.size();
        int m = s.size();

        // Create a DP table to memoize results
        vector<vector<bool>> dp(n + 1, vector<bool>(m+1, false));

        // Initialize the first row and column
        dp[0][0] = true;
        for (int j = 1; j <= m; j++) {
            dp[0][j] = false;
        }
        for (int i = 1; i <= n; i++) {
            dp[i][0] = isAllStars(p, i);
        }

        // Fill in the DP table
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (p[i - 1] == s[j - 1] || p[i - 1] == '?') {
                    dp[i][j] = dp[i - 1][j - 1];
                } 
                else {
                    if (p[i - 1] == '*') {
                        dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                    } 
                    else {
                        dp[i][j] = false;
                    }
                }
            }
        }
        return dp[n][m];
    }
};