class Solution {
public:
    int f(vector<int>& coins, int amount,int i,vector<vector<int>>&dp){
        if(i<0){
            if(amount==0) return 1;
            else return 0;
        }
        if(dp[i][amount]!=-1) return dp[i][amount];
        int notTaken=f(coins,amount,i-1,dp);
        int Taken=0;
        if(amount>=coins[i]) Taken=f(coins,amount-coins[i],i,dp);
        return dp[i][amount]=(Taken+notTaken);
    }
    int change(int amount,vector<int>& coins) {
        if(amount==0) return 1;
        int i=coins.size()-1;
        vector<vector<int>>dp(i+2,vector<int>(amount+1,-1));
        return f(coins,amount,i,dp);
    }
};