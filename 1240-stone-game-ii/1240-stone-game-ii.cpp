class Solution {
public:
    int game(vector<int>& piles, int m, vector<int>& suffixSum, int i, vector<vector<int>>&dp){
        if(i>=piles.size()) return 0;
        if(i+2*m>=piles.size()) return suffixSum[i];
        if(dp[i][m]!=-1) return dp[i][m];
        int ans=0;
        for(int x=1; x<=2*m ;x++){
            ans=max(ans,suffixSum[i]-game(piles,max(x,m),suffixSum,i+x,dp));
        }
        return dp[i][m]=ans;
    }
    int stoneGameII(vector<int>& piles) {
        vector<vector<int>>dp(piles.size(),vector<int>(piles.size(),-1));
        vector<int>suffixSum(piles.size());
        suffixSum[piles.size()-1]=piles[piles.size()-1];
        for(int i=piles.size()-2;i>=0;i--) suffixSum[i]=piles[i]+suffixSum[i+1];
        return game(piles,1,suffixSum,0,dp);
    }
};
