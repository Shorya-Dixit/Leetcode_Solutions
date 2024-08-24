class Solution {
public:
    int trade(vector<int>& prices, int bought, int i, vector<vector<vector<int>>>&dp, int trans){
        if(trans==0) return 0;
        if(i==prices.size()-1 && bought==1) return prices[i];
        else if(i==prices.size()-1 && bought==0) return 0;

        if(dp[i][bought][trans]!=-1) return dp[i][bought][trans];

        if(!bought) {
            int buy=trade(prices,1,i+1,dp,trans)-prices[i];
            int notBuy=trade(prices,0,i+1,dp,trans);
            return dp[i][bought][trans]=max(buy,notBuy);
        }
        else {
            int sell=trade(prices,0,i+1,dp,trans-1)+prices[i];
            int notSell=trade(prices,1,i+1,dp,trans);
            return dp[i][bought][trans]=max(sell,notSell);
        }
    }
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<vector<int>>>dp(prices.size(),vector<vector<int>>(2,vector<int>(k+1,-1)));
        return trade(prices,0,0,dp,k);
    }
};