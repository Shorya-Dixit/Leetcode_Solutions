class Solution {
public:
// slight modification in base case
    int trade(vector<int>& prices, int bought, int i, vector<vector<int>>&dp, int fee){
        if(i>=prices.size()) return 0;

        if(dp[i][bought]!=-1) return dp[i][bought];

        if(!bought) {
            int buy=trade(prices,1,i+1,dp,fee)-prices[i]-fee;
            int notBuy=trade(prices,0,i+1,dp,fee);
            return dp[i][bought]=max(buy,notBuy);
        }
        else {
            int sell=trade(prices,0,i+1,dp,fee)+prices[i];
            int notSell=trade(prices,1,i+1,dp,fee);
            return dp[i][bought]=max(sell,notSell);
        }
    }
    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>>dp(prices.size(),vector<int>(2,-1));
        return trade(prices,0,0,dp,fee);
    }
};