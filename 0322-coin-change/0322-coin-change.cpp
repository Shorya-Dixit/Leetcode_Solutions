class Solution {
public:
    int f(vector<int>& coins, int amount,int i,vector<vector<int>>&dp){
        if(i<0){
            if(amount==0) return 0;
            else return 1e5;
        }
        if(dp[i][amount]!=-1) return dp[i][amount];
        int notTaken=0+f(coins,amount,i-1,dp);
        int Taken=INT_MAX;
        if(amount>=coins[i]) Taken=1+f(coins,amount-coins[i],i,dp);
        return dp[i][amount]=min(Taken,notTaken);
    }
    int coinChange(vector<int>& coins, int amount) {
        if(amount==0) return 0;
        int i=coins.size()-1;
        vector<vector<int>>dp(i+2,vector<int>(amount+1,-1));
        if(f(coins,amount,i,dp)>1e4 ) return -1;
        else return f(coins,amount,i,dp);
    }
};