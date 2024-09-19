class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        if(piles.size()==1) return piles[0];
        vector<vector<int>>dp(piles.size()+1,vector<int>(piles.size()+1,0));
        vector<int>suffixSum(piles.size());
        suffixSum[piles.size()-1]=piles[piles.size()-1];
        for(int i=piles.size()-2;i>=0;i--) suffixSum[i]=piles[i]+suffixSum[i+1];
        for(int m=1;m<piles.size();m++){
            dp[piles.size()][m]=0;
        }
        for(int i=piles.size()-1;i>=0;i--){
            for(int m=piles.size()-1;m>=0;m--){
                int ans=0;
                if(i+2*m>=piles.size()) {dp[i][m]=suffixSum[i]; continue;}
                for(int x=1; x<=2*m ;x++){
                    dp[i][m]=max(dp[i][m],suffixSum[i]-dp[i+x][max(m,x)]);
                }
            }
        }
        return dp[0][1];
    }
};
