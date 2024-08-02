class Solution {
public:
    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();
        vector<vector<double>>dp(n+1,vector<double>(m+1,0));
        for(int i=0;i<=n;i++){
            dp[i][0]=1;    // only 1 way that a subsequence of s[0 to i] is eq. to NULL string
        }
        for(int j=1;j<=m;j++){
            dp[0][j]=0;    // no way that a subsequence of NULL string is eq. to t[0 to j].
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1]) dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
                else dp[i][j]=dp[i-1][j];
            }
        }
        return (int)dp[n][m];
    }
};
// here dp[i][j] represents the no. of distinct subsequences of s[0 to i] which equals t[0 to j]. 
// we have done index by 1 towards right for tabulation as dp of negative is not possible and 
// we need to accomodate i<0 and j<0 in our dp table.