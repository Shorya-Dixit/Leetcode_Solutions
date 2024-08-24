class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int trans=2;
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        for(int i=0;i<n;i++){
            dp[i][0][0]=0;
            dp[i][1][0]=0;
        }
        for(int t=1;t<=trans;t++){
            dp[n-1][0][t]=0;
            dp[n-1][1][t]=prices[n-1];
        }
        for(int i=n-2;i>=0;i--){
            for(int t=1;t<=trans;t++){
                dp[i][0][t]=max(dp[i+1][1][t]-prices[i],dp[i+1][0][t]);
                dp[i][1][t]=max(dp[i+1][0][t-1]+prices[i],dp[i+1][1][t]);
            }
        }
        return dp[0][0][trans];
    }
};
// dp[n-1][0][t] means the change in profit if we start from n-1 and haven't bought the stock before.
// dp[n-1][1][t] means the change in profit if we start from n-1 and have bought the stock before and now must sell it.
// above values are for t transactions left.