class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,0));
        dp[n-1][0]=0;
        dp[n-1][1]=prices[n-1];
        for(int i=n-2;i>=0;i--){
            dp[i][0]=max(dp[i+1][1]-prices[i],dp[i+1][0]);
            dp[i][1]=max(dp[i+1][0]+prices[i],dp[i+1][1]);
        }
        return dp[0][0];
    }
};
// dp[n-1][0] means the change in profit if we start from n-1 and haven't bought the stock before.
// dp[n-1][1] means the change in profit if we start from n-1 and have bought the stock before and now must sell it.