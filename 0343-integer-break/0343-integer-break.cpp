class Solution {
public:
    int integerBreak(int n) {
        if(n==3) return 2;
        if(n==2) return 1;
        vector<int>dp(n+1,-1);
        dp[2]=2;
        dp[3]=3;
        for(int i=4;i<=n;i++){
            dp[i]=max(dp[i-2]*2,dp[i-3]*3);
        }
        return dp[n];
    }
};
// here dp[x] show the maximum possible product using factors of x
