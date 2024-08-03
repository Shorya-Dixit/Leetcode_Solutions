class Solution {
public:
    bool isAllStars(string &p, int i) {
        for (int k = 0; k <= i; k++) {
            if (p[k] != '*')
                return false;
        }
        return true;
    }
    bool wildcardMatchingUtil(string &p, string &s, int i, int j, vector<vector<int>> &dp) {
        // Base Cases
        if (i < 0 && j < 0)
            return true;
        if (i < 0 && j >= 0) 
            return false;
        if (j < 0 && i >= 0)
            return isAllStars(p, i);

        // If the result for this state has already been calculated, return it
        if (dp[i][j] != -1)
            return dp[i][j];

        // If the characters at the current positions match or p has a '?'
        if (p[i] == s[j] || p[i] == '?')
            return dp[i][j] = wildcardMatchingUtil(p, s, i - 1, j - 1, dp);
        else {
            if (p[i] == '*')
                // Two options: either '*' represents an empty string or it matches a character in s
                return dp[i][j] = wildcardMatchingUtil(p, s, i - 1, j, dp) || wildcardMatchingUtil(p, s, i, j - 1, dp);
            else
                return false;
        }
    }

    // Main function to check if p matches s using wildcard pattern matching
    bool isMatch(string &s, string &p) {
        int n = p.size();
        int m = s.size();

        // Create a DP table to memoize results
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return wildcardMatchingUtil(p, s, n - 1, m - 1, dp);
    }
};