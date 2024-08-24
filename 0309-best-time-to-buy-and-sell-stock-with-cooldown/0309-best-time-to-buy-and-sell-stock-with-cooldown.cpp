class Solution {
public:
// slight modification in base case
    int trade(vector<int>& prices, int bought, int i, vector<vector<int>>&dp, int prevSold){
        if(i>=prices.size()) return 0;

        if(dp[i][bought]!=-1) return dp[i][bought];

        if(!bought) {
            int buy=trade(prices,1,i+1,dp,0)-prices[i];
            int notBuy=trade(prices,0,i+1,dp,0);
            return dp[i][bought]=max(buy,notBuy);
        }
        else {
            if(prevSold==1) trade(prices,1,i+1,dp,0);
            int sell=trade(prices,0,i+2,dp,1)+prices[i]; // if sold, leave the just next stock
            int notSell=trade(prices,1,i+1,dp,0);
            return dp[i][bought]=max(sell,notSell);
        }
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>>dp(prices.size(),vector<int>(2,-1));
        return trade(prices,0,0,dp,0);
    }
};
// check all previous submissions