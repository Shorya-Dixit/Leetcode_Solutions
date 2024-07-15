class Solution {
public:
    int f(vector<int>& piles,int beg,int end,vector<vector<int>>&dp){
        if(beg>end) return 0;
        if(dp[beg][end]!=-1) return dp[beg][end];
        int takeEnd=piles[end]+f(piles,beg,end-1,dp);
        int takeBeg=piles[beg]+f(piles,beg+1,end,dp);
        return dp[beg][end]=max(takeEnd,takeBeg);
    }
    bool stoneGame(vector<int>& piles) {
        int n=piles.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return f(piles,0,n-1,dp); 
    }
};