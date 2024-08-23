class Solution {
public:
    int trade(vector<int>& prices, int bought, int i, vector<vector<int>>&dp){
        if(i==prices.size()-1 && bought==1) return prices[i];
        else if(i==prices.size()-1 && bought==0) return 0;

        if(dp[i][bought]!=-1) return dp[i][bought];

        if(!bought) {
            int buy=trade(prices,1,i+1,dp)-prices[i];
            int notBuy=trade(prices,0,i+1,dp);
            return dp[i][bought]=max(buy,notBuy);
        }
        else {
            int sell=trade(prices,0,i+1,dp)+prices[i];
            int notSell=trade(prices,1,i+1,dp);
            return dp[i][bought]=max(sell,notSell);
        }
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>>dp(prices.size(),vector<int>(2,-1));
        return trade(prices,0,0,dp);
    }
};